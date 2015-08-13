/*
 * Copyright (C) 2006 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** \file
  This file consists of implementation of rotines that are exported
  from this DLL.
*/

#include "stdafx.h"
#include "adb_api.h"
#include "adb_object_handle.h"
#include "adb_interface_enum.h"
#include "adb_interface.h"
#include "adb_endpoint_object.h"
#include "adb_io_completion.h"
#include "adb_helper_routines.h"

ADBAPIHANDLE AdbEnumInterfaces(GUID class_id,
                               bool exclude_not_present,
                               bool exclude_removed,
                               bool active_only) {
  AdbInterfaceEnumObject* enum_obj = NULL;
  ADBAPIHANDLE ret = NULL;

  try {
    // Instantiate and initialize enum object
    enum_obj = new AdbInterfaceEnumObject();

    if (enum_obj->InitializeEnum(class_id,
                                 exclude_not_present,
                                 exclude_removed,
                                 active_only)) {
      // After successful initialization we can create handle.
      ret = enum_obj->CreateHandle();
    }
  } catch (...) {
    SetLastError(ERROR_OUTOFMEMORY);
  }

  if (NULL != enum_obj)
    enum_obj->Release();

  return ret;
}

bool AdbNextInterface(ADBAPIHANDLE adb_handle,
                      AdbInterfaceInfo* info,
                      unsigned long* size) {
  if (NULL == size) {
    SetLastError(ERROR_INVALID_PARAMETER);
    return false;
  }

  // Lookup AdbInterfaceEnumObject object for the handle
  AdbInterfaceEnumObject* adb_ienum_object =
    LookupObject<AdbInterfaceEnumObject>(adb_handle);
  if (NULL == adb_ienum_object)
    return false;

  // Everything is verified. Pass it down to the object
  bool ret = adb_ienum_object->Next(info, size);

  adb_ienum_object->Release();

  return ret;
}

bool AdbResetInterfaceEnum(ADBAPIHANDLE adb_handle) {
  // Lookup AdbInterfaceEnumObject object for the handle
  AdbInterfaceEnumObject* adb_ienum_object =
    LookupObject<AdbInterfaceEnumObject>(adb_handle);
  if (NULL == adb_ienum_object)
    return false;

  // Everything is verified. Pass it down to the object
  bool ret = adb_ienum_object->Reset();

  adb_ienum_object->Release();

  return ret;
}

ADBWIN_API ADBAPIHANDLE AdbCreateInterfaceByName(
    const wchar_t* interface_name) {
  AdbInterfaceObject* obj = NULL;
  ADBAPIHANDLE ret = NULL;

  try {
    // Instantiate object
    obj = new AdbInterfaceObject(interface_name);

    // Create handle for it
    ret = obj->CreateHandle();
  } catch (...) {
    SetLastError(ERROR_OUTOFMEMORY);
  }

  if (NULL != obj)
    obj->Release();

  return ret;
}

ADBAPIHANDLE AdbCreateInterface(GUID class_id,
                                unsigned short vendor_id,
                                unsigned short product_id,
                                unsigned char interface_id) {
  // Enumerate all active interfaces for the given class
  AdbEnumInterfaceArray interfaces;

  if (!EnumerateDeviceInterfaces(class_id,
                                 DIGCF_DEVICEINTERFACE | DIGCF_PRESENT,
                                 true,
                                 true,
                                 &interfaces)) {
    return NULL;
  }

  if (interfaces.empty()) {
    SetLastError(ERROR_DEVICE_NOT_AVAILABLE);
    return NULL;
  }

  // Now iterate over active interfaces looking for the name match.
  // The name is formatted as such:
  // "\\\\?\\usb#vid_xxxx&pid_xxxx&mi_xx#123456789abcdef#{XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}"
  // where
  //    vid_xxxx is for the vendor id (xxxx are hex for the given vendor id),
  //    pid_xxxx is for the product id (xxxx are hex for the given product id)
  //    mi_xx is for the interface id  (xx are hex for the given interface id)
  // EnumerateDeviceInterfaces will guarantee that returned interface names
  // will have our class id at the end of the name (those last XXXes in the
  // format). So, we only need to match the beginning of the name
  wchar_t match_name[64] = {0};
  if(vendor_id > 0 && product_id > 0 && vendor_id != 0x413C/*GOOGLE*/)
  {
	  if (0xFF == interface_id) 
	  {
		  // No interface id for the name.
		  swprintf(match_name, L"\\\\?\\usb#vid_%04x&pid_%04x#",vendor_id, product_id);
	  } 
	  else 
	  {
		  // With interface id for the name.
		  swprintf(match_name, L"\\\\?\\usb#vid_%04x&pid_%04x&mi_%02x#",vendor_id, product_id, interface_id);
	  }
  }
  size_t match_len = wcslen(match_name);

  for (AdbEnumInterfaceArray::iterator it = interfaces.begin();
       it != interfaces.end(); it++) {
    const AdbInstanceEnumEntry& next_interface = *it;
    if (0 == wcsnicmp(match_name,
                      next_interface.device_name().c_str(),
                      match_len)) {
      // Found requested interface among active interfaces.
      return AdbCreateInterfaceByName(next_interface.device_name().c_str());
    }
  }

  SetLastError(ERROR_DEVICE_NOT_AVAILABLE);
  return NULL;
}

ADBAPIHANDLE MultiAdbCreateInterface(GUID class_id,
									 unsigned short vendor_id,
									 unsigned short product_id,
									 unsigned char interface_id,
									 const char* szComport) 
{
	// Enumerate all active interfaces for the given class
	AdbEnumInterfaceArray interfaces;

	wchar_t match_name[128] = {0};

	if (!EnumerateDeviceInterfaces(class_id,
		DIGCF_DEVICEINTERFACE | DIGCF_PRESENT,
		true,
		true,
		&interfaces)) {
			return NULL;
	}
	else
	{

		char *pdest = NULL;

		for(AdbEnumInterfaceArray::iterator it = interfaces.begin();it != interfaces.end(); it++)
		{
			std::wstring m_strDeviceName = it->device_name();

			wchar_t* wsztemp = (wchar_t*)m_strDeviceName.c_str();

			char sztemp[512] = {0};

			wcstombs(sztemp,wsztemp,m_strDeviceName.length());

			pdest=strstr(sztemp,szComport);

			if(pdest!=NULL) {
				swprintf(match_name, L"%s", wsztemp);
				break;
			}
		}	  

		if(pdest == NULL)
			return NULL;
	}

	if (interfaces.empty()) {
		SetLastError(ERROR_DEVICE_NOT_AVAILABLE);
		return NULL;
	}

	size_t match_len = wcslen(match_name);

	for (AdbEnumInterfaceArray::iterator it = interfaces.begin(); it != interfaces.end(); it++) {
		const AdbInstanceEnumEntry& next_interface = *it;
		if (0 == wcsnicmp(match_name, next_interface.device_name().c_str(), match_len)) {
			return AdbCreateInterfaceByName(next_interface.device_name().c_str());
		}
	}

	// Now iterate over active interfaces looking for the name match.
	// The name is formatted as such:
	// "\\\\?\\usb#vid_xxxx&pid_xxxx&mi_xx#123456789abcdef#{XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX}"
	// where
	//    vid_xxxx is for the vendor id (xxxx are hex for the given vendor id),
	//    pid_xxxx is for the product id (xxxx are hex for the given product id)
	//    mi_xx is for the interface id  (xx are hex for the given interface id)
	// EnumerateDeviceInterfaces will guarantee that returned interface names
	// will have our class id at the end of the name (those last XXXes in the
	// format). So, we only need to match the beginning of the name


	//wchar_t match_name[64] = {0};

	//if(vendor_id > 0 && product_id > 0 && vendor_id != 0x413C/*GOOGLE*/)
	//{
	//	if (0xFF == interface_id) 
	//	{
	//		// No interface id for the name.
	//		swprintf(match_name, L"\\\\?\\usb#vid_%04x&pid_%04x#",vendor_id, product_id);
	//	} 
	//	else 
	//	{
	//		// With interface id for the name.
	//		swprintf(match_name, L"\\\\?\\usb#vid_%04x&pid_%04x&mi_%02x#",vendor_id, product_id, interface_id);
	//	}
	//}
	//size_t match_len = wcslen(match_name);

	//for (AdbEnumInterfaceArray::iterator it = interfaces.begin();
	//	it != interfaces.end(); it++) {
	//		const AdbInstanceEnumEntry& next_interface = *it;
	//		if (0 == wcsnicmp(match_name,
	//			next_interface.device_name().c_str(),
	//			match_len)) {
	//				// Found requested interface among active interfaces.
	//				return AdbCreateInterfaceByName(next_interface.device_name().c_str());
	//		}
	//}

	SetLastError(ERROR_DEVICE_NOT_AVAILABLE);
	return NULL;
}

bool AdbGetInterfaceName(ADBAPIHANDLE adb_interface,
                         void* buffer,
                         unsigned long* buffer_char_size,
                         bool ansi) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch call to the found object
    bool ret = adb_object->GetInterfaceName(buffer, buffer_char_size, ansi);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetSerialNumber(ADBAPIHANDLE adb_interface,
                        void* buffer,
                        unsigned long* buffer_char_size,
                        bool ansi) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch call to the found object
    bool ret = adb_object->GetSerialNumber(buffer, buffer_char_size, ansi);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetUsbDeviceDescriptor(ADBAPIHANDLE adb_interface,
                               USB_DEVICE_DESCRIPTOR* desc) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch close to the found object
    bool ret = adb_object->GetUsbDeviceDescriptor(desc);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetUsbConfigurationDescriptor(ADBAPIHANDLE adb_interface,
                                      USB_CONFIGURATION_DESCRIPTOR* desc) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch close to the found object
    bool ret = adb_object->GetUsbConfigurationDescriptor(desc);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetUsbInterfaceDescriptor(ADBAPIHANDLE adb_interface,
                                  USB_INTERFACE_DESCRIPTOR* desc) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch close to the found object
    bool ret = adb_object->GetUsbInterfaceDescriptor(desc);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetEndpointInformation(ADBAPIHANDLE adb_interface,
                               UCHAR endpoint_index,
                               AdbEndpointInformation* info) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch close to the found object
    bool ret = adb_object->GetEndpointInformation(endpoint_index, info);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetDefaultBulkReadEndpointInformation(ADBAPIHANDLE adb_interface,
                                              AdbEndpointInformation* info) {
  return AdbGetEndpointInformation(adb_interface,
                                   ADB_QUERY_BULK_READ_ENDPOINT_INDEX,
                                   info);
}

bool AdbGetDefaultBulkWriteEndpointInformation(ADBAPIHANDLE adb_interface,
                                               AdbEndpointInformation* info) {
  return AdbGetEndpointInformation(adb_interface,
                                   ADB_QUERY_BULK_WRITE_ENDPOINT_INDEX,
                                   info);
}

ADBAPIHANDLE AdbOpenEndpoint(ADBAPIHANDLE adb_interface,
                             unsigned char endpoint_index,
                             AdbOpenAccessType access_type,
                             AdbOpenSharingMode sharing_mode) {
  // Lookup interface object for the handle
  AdbInterfaceObject* adb_object =
    LookupObject<AdbInterfaceObject>(adb_interface);

  if (NULL != adb_object) {
    // Dispatch close to the found object
    ADBAPIHANDLE ret =
      adb_object->OpenEndpoint(endpoint_index, access_type, sharing_mode);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return NULL;
  }
}

ADBAPIHANDLE AdbOpenDefaultBulkReadEndpoint(ADBAPIHANDLE adb_interface,
                                            AdbOpenAccessType access_type,
                                            AdbOpenSharingMode sharing_mode) {
  return AdbOpenEndpoint(adb_interface,
                         ADB_QUERY_BULK_READ_ENDPOINT_INDEX,
                         access_type,
                         sharing_mode);
}

ADBAPIHANDLE AdbOpenDefaultBulkWriteEndpoint(ADBAPIHANDLE adb_interface,
                                             AdbOpenAccessType access_type,
                                             AdbOpenSharingMode sharing_mode) {
  return AdbOpenEndpoint(adb_interface,
                         ADB_QUERY_BULK_WRITE_ENDPOINT_INDEX,
                         access_type,
                         sharing_mode);
}

ADBAPIHANDLE AdbGetEndpointInterface(ADBAPIHANDLE adb_endpoint) {
  // Lookup endpoint object for the handle
  AdbEndpointObject* adb_object =
    LookupObject<AdbEndpointObject>(adb_endpoint);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    ADBAPIHANDLE ret = adb_object->GetParentInterfaceHandle();
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return NULL;
  }
}

bool AdbQueryInformationEndpoint(ADBAPIHANDLE adb_endpoint,
                                 AdbEndpointInformation* info) {
  // Lookup endpoint object for the handle
  AdbEndpointObject* adb_object =
    LookupObject<AdbEndpointObject>(adb_endpoint);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    bool ret = adb_object->GetEndpointInformation(info);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

ADBAPIHANDLE AdbReadEndpointAsync(ADBAPIHANDLE adb_endpoint,
                                  void* buffer,
                                  unsigned long bytes_to_read,
                                  unsigned long* bytes_read,
                                  unsigned long time_out,
                                  HANDLE event_handle) {
  // Lookup endpoint object for the handle
  AdbEndpointObject* adb_object =
    LookupObject<AdbEndpointObject>(adb_endpoint);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    ADBAPIHANDLE ret = adb_object->AsyncRead(buffer,
                                             bytes_to_read,
                                             bytes_read,
                                             event_handle,
                                             time_out);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return NULL;
  }
}

ADBAPIHANDLE AdbWriteEndpointAsync(ADBAPIHANDLE adb_endpoint,
                                   void* buffer,
                                   unsigned long bytes_to_write,
                                   unsigned long* bytes_written,
                                   unsigned long time_out,
                                   HANDLE event_handle) {
  // Lookup endpoint object for the handle
  AdbEndpointObject* adb_object =
    LookupObject<AdbEndpointObject>(adb_endpoint);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    ADBAPIHANDLE ret = adb_object->AsyncWrite(buffer,
                                              bytes_to_write,
                                              bytes_written,
                                              event_handle,
                                              time_out);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbReadEndpointSync(ADBAPIHANDLE adb_endpoint,
                         void* buffer,
                         unsigned long bytes_to_read,
                         unsigned long* bytes_read,
                         unsigned long time_out) {
  // Lookup endpoint object for the handle
  AdbEndpointObject* adb_object =
    LookupObject<AdbEndpointObject>(adb_endpoint);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    bool ret =
      adb_object->SyncRead(buffer, bytes_to_read, bytes_read, time_out);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return NULL;
  }
}

bool AdbWriteEndpointSync(ADBAPIHANDLE adb_endpoint,
                          void* buffer,
                          unsigned long bytes_to_write,
                          unsigned long* bytes_written,
                          unsigned long time_out) {
  // Lookup endpoint object for the handle
  AdbEndpointObject* adb_object =
    LookupObject<AdbEndpointObject>(adb_endpoint);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    bool ret =
      adb_object->SyncWrite(buffer, bytes_to_write, bytes_written, time_out);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbGetOvelappedIoResult(ADBAPIHANDLE adb_io_completion,
                             LPOVERLAPPED overlapped,
                             unsigned long* bytes_transferred,
                             bool wait) {
  // Lookup endpoint object for the handle
  AdbIOCompletion* adb_object =
    LookupObject<AdbIOCompletion>(adb_io_completion);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    bool ret =
      adb_object->GetOvelappedIoResult(overlapped, bytes_transferred, wait);
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}

bool AdbHasOvelappedIoComplated(ADBAPIHANDLE adb_io_completion) {
  // Lookup endpoint object for the handle
  AdbIOCompletion* adb_object =
    LookupObject<AdbIOCompletion>(adb_io_completion);

  if (NULL != adb_object) {
    // Dispatch the call to the found object
    bool ret =
      adb_object->IsCompleted();
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return true;
  }
}

bool AdbCloseHandle(ADBAPIHANDLE adb_handle) {
  // Lookup object for the handle
  AdbObjectHandle* adb_object = AdbObjectHandle::Lookup(adb_handle);

  if (NULL != adb_object) {
    // Dispatch close to the found object
    bool ret = adb_object->CloseHandle();
    adb_object->Release();
    return ret;
  } else {
    SetLastError(ERROR_INVALID_HANDLE);
    return false;
  }
}
