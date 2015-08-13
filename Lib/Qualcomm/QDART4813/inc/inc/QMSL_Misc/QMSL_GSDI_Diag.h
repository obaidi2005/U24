#if !defined(_QMSL_GSDI_DIAG_H)
#define _QMSL_GSDI_DIAG_H

#if !defined(_WINDOWS_)
#include "windows.h"
#endif

/**
	Establish whether the library is being compiled into a DLL (exporting),
	or being included from a client (importing)

	When the DLL is built, then QLIB_EXPORTS should be defined
*/
#ifdef QLIB_API
#undef QLIB_API
#endif

#ifdef QLIB_EXPORTS
#define QLIB_API __declspec(dllexport)
#else
#define QLIB_API __declspec(dllimport)
#endif

#if defined(QLIB_STATIC)
#undef QLIB_API
#define QLIB_API
//#define QLIB_API __cdecl
#endif


#ifdef __cplusplus
extern "C" {
#endif

	//MMGSDI
	
	QLIB_API unsigned char QLIB_MMGSDI_CLIENT_ID_AND_EVT_REG_CMD(HANDLE hResourceContext, unsigned long *status, unsigned long *client_id_low, unsigned long *client_id_high);
	QLIB_API unsigned char QLIB_MMGSDI_SESSION_OPEN_CMD(HANDLE hResourceContext, unsigned long *status, unsigned long client_id_low, unsigned long client_id_high, unsigned long *session_id_high, unsigned long *session_id_low);
	QLIB_API unsigned char QLIB_MMGSDI_SESSION_PERSO_GET_KEY_CMD(HANDLE hResourceContext, unsigned long session_id_low, unsigned long session_id_high, unsigned long feature_type, unsigned long key_type, unsigned long *key_data_len, unsigned char *key_data,unsigned long *status);
	QLIB_API unsigned char QLIB_MMGSDI_SESSION_PERSO_ACTIVATE_CMD(HANDLE hResourceContext, unsigned long session_id_low, unsigned long session_id_high, unsigned long feature_type, unsigned long data_length, unsigned char *data, unsigned long  *perso_action, unsigned long *perso_feature, unsigned long  *num_retries_left, unsigned long  *status);
	QLIB_API unsigned char QLIB_MMGSDI_SESSION_PERSO_SET_DATA_CMD(HANDLE hResourceContext, unsigned long session_id_low, unsigned long session_id_high, unsigned long feature_type, unsigned long data_length, unsigned char *data, unsigned long *status, unsigned long  *ret_session_id_high, unsigned long  *ret_session_id_low);


	QLIB_API unsigned char QLIB_MMGSDI_CLIENT_ID_AND_EVT_DEREG_CMD(HANDLE hResourceContext, unsigned long client_id_low, unsigned long  client_id_high,unsigned long  *status); 
	QLIB_API unsigned char QLIB_MMGSDI_SESSION_PERSO_DEACTIVATE_CMD(HANDLE hResourceContext, unsigned long  session_id_low, unsigned long  session_id_high, unsigned long  feature_type, unsigned long  data_length, unsigned char *data, unsigned long *perso_action, unsigned long  *perso_feature, unsigned long  *num_retries, unsigned long  *status); 
	QLIB_API unsigned char QLIB_MMGSDI_SESSION_CLOSE_CMD(HANDLE hResourceContext, unsigned long  session_id_low, unsigned long  session_id_high, unsigned long  *ret_session_id_high, unsigned long  *ret_session_id_low, unsigned long  *app_type, unsigned long  *aid_len, unsigned char *aid, unsigned long  *status);

   /******************************************************************************

   GSDI Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   GDSI ICD, 4.16  DELAYED RESPONSE: GSDIDIAG_ROOT_KEY_WRITE_CMD

   This function is used to write the root key to the FLASH.

   This function handles the delayed response message and the return values are
   taken from delayed asynchronous message, not the first response message.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = Input, SLOT_ID - Slot number for the SIM for which this information
                    needs retrieved. Values applicable to dual slot targets are:
      \code
            0x01 - SLOT 1
            0x02 - SLOT 2
      \endcode
      For single slot targets, slot number should be None.

   \param iSIM_AppIdLen = Input, Length of the Application ID from which to retrieve information;
                         set to Length = 0 when not used. Be sure to set this to 0 when not
                          used. Optional and applicable only to USIM. For a USIM, this implies
                    that the USIM ADF is to be selected by default as necessary.
                    Note: When using GSM cards and RUIM cards, set this to 0.

   \param piSIM_AppId = Input, Optional and applicable only to USIM.
                  USIM application identifier (APP ID); should only be used when the
                  Card is a UICC with application directory files (ADFs)
                  The APP IDs are retrieved from the USIM file EF-DIR.
                  Set bytes [1 to 16] to 0x00 for GSM cards and RUIM cards.

                  If this is not used, then set value to NULL, otherwise, must be 16 bytes long.


   \param iRootKeyLen = Input, # of bytes used by the root key,
   \param piRootKeyData = Input, storage area of the root key, must be a valid pointer to
                          "iRootKeyLen" number of bytes.

   \param piCommandStatus = Output, Command status is set to GSDI_SUCCESS if APS_AS_TRANSPORT is
                           set to 1.Otherwise it is set to the status returned by GSDI

                     This value is not valid if the function returns a false.


   \param piStatus = Output, status code returned by the delayed response GSDI.
                     These are the codes returned in the CDM_STATUS fields of Events.

                     This value is not valid if the function returns a false.
   \code
         0	- COMMAND COMPLETED SUCCESSFULLY
         1	- GENERAL ERROR:  No other information specified
         2	- ACCESS DENIED:  Security Procedures performed thus far don't satisfy restrictions
         3	- NOT FOUND:  SIM Elementary File or Directory File was not found.
         4	- INCOMPATIBLE PIN STATUS:  Trying to perform a PIN Action for a PIN that is not in the correct state.
            For example, trying to Disable an already Disabled PIN.
         5	- INCORRECT CODE:  The Code provided is incorrect for the PIN ID used.
         6	- CODE BLOCKED:  The Number of retries has been exceeded and the PIN is now blocked.
         7	- INCREASE IMPOSSIBLE:  The INCREASE Command has failed due to a Bad Value
         8	- INCORRECT PARAMETERS:  The SIM detected an incorrect parameter for the action performed.
         9	- NOT SUPPORTED:  Not allowed by GSDI due to Service Table Values
         10	- NOT INIT:  Cache has not been INIT
         11	- SUCCESS BUT ILLEGAL SIM:  The SIM has been marked as an illegal SIM for the network,
            but the actions are succeeding on the SIM.
         12	- RESERVED
         13	- RESERVED
         14	- SIM TECHNICAL PROBLEMS:  The SIM malfunctioned.
         15	- NO EF SELECTED:  Attempted to read a file without fist selecting it.
         16	- EF INCONSISTENT:  Trying to Read a Record when the file is a Binary or similar type error.
         17	- RESERVED
         18	- UNKNOWN INST CLASS:  Trying to send a UICC Command to a GSM/RUIM Card or vice versa.
         19	- RESERVED
         20	- RESERVED
         21	- INCORRECT LENGTH:  A Bad length was provided in the command.
         22	- DRIVERS TIMED OUT:  The Drivers communicating with the Card Timed Out.
         23	- CODE PERM BLOCKED:  The Unblock Code has been blocked.  Need Administrative assistance to unblock it.
         24	- RESERVED
         25	- RESERVED
         26	- RESERVED
   \endcode


   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_ROOT_KEY_WRITE_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char * piSIM_AppId,
      unsigned long iRootKeyLen,
      unsigned char * piRootKeyData,
      unsigned long* piCommandStatus,
      unsigned long* piStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 4.17  DELAYED RESPONSE: GSDIDIAG_ROOT_KEY_READ_CMD

   This function is used to read the root key from the FLASH.

   This function handles the delayed response message and the return values are
   taken from delayed asynchronous message, not the first response message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>

   \param piRootKeyLen = Output, # of bytes used by the root key,
   \param piRootKeyData = Output, storage area of the root key, must be a valid pointer to
                          at least 260 bytes.

   \param piCommandStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_ROOT_KEY_READ_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId, unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long* piRootKeyLen,
      unsigned char* piRootKeyData,
      unsigned long* piCommandStatus,
      unsigned long* piStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 1.2.17  DELAYED RESPONSE: GSDIDIAG_SECURE_DEVICE_INFO_CMD

   This function is used to save IMEI, Serial Number to the Flash and perform
   the activation procedure.

   This function handles the delayed response message and the return values are
   taken from delayed asynchronous message, not the first response message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>

   \param piCommandStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SECURE_DEVICE_INFO_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long* piCommandStatus,
      unsigned long* piStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 4.15  DELAYED RESPONSE: GSDIDIAG_SIM_SECURE_STORE_CMD

   This function is used to store encrypted SIM lock data.

   This function handles the delayed response message and the return values are
   taken from delayed asynchronous message, not the first response message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_SecureDataLen = input, size of sim secure buffer.  At most 1360 bytes
   \param piSIM_SecureData = input, buffer of SIM secure data, must be a minimum of
                             "iSIM_SecureDataLen" bytes, at most 1360 bytes

   \param piCommandStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SIM_SECURE_STORE_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long iSIM_SecureDataLen,
      unsigned char* piSIM_SecureData,
      unsigned long* piCommandStatus,
      unsigned long* piStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 4.18.2 GSDIDIAG_SECURE_READ_CMD response

   This function is used to read the encrypted SIM lock data.

   This function handles the delayed response message and the return values are
   taken from delayed asynchronous message, not the first response message.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>

   \param piSIM_SecureDataLen = output, return value of the number of bytes in the SIM secure data
   \param piSIM_SecureData = output, buffer to store the contents of the SIM secure data, at most 1360 bytes.

   \param piCommandStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \return true if successful, false if fail.

   \warning
   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SIM_SECURE_READ_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char * piSIM_AppId,
      unsigned long*piSIM_SecureDataLen,
      unsigned char * piSIM_SecureData,
      unsigned long* piCommandStatus,
      unsigned long* piStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 4.25  DELAYED RESPONSE: GSDIDIAG_ACTIVATE_ONCHIP_SIM_CMD

   ICD description:
   This function is used to activate Virtual SIM.

   This function handles the delayed response message and the return values are
   taken from delayed asynchronous message, not the first response message.


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>

   \param piCommandStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piStatus = Output, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \return true if successful, false if fail.

   \warning The SPC code must be sent to the phone first, using QLIB_DIAG_SPC_F()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_ACTIVATE_ONCHIP_SIM_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long* piCommandStatus,
      unsigned long* piStatus
   );

   /******************************************************************************/
   /**
   MMGDSI ICD, TBD Section,  DELAYED RESPONSE: MMGSDIDIAG_ACTIVATE_ONCHIP_SIM_CMD

   ICD description:
   This function is used to activate Virtual SIM.  There is a difference between the
   "GSDIDIAG" and "MMGSDIDIAG" commands.  The MMGSDI command also allows specifying
   the IMSI, Access Class, Admin data, LOCI, FPLMN, SST, and Phase.

   This function sends a fixed configuration on the data.  This is done because
   the ICD definition was not completed at the time of the function writing and
   it is a standard configuration, which can be used to make a call on most call processing
   equipment

   Then send the Activate ONCHIP SIM Data.
   \code
      send_data 0x80 0x21 0x48 0x00 0x01 0x00 0x00 0x00 0x83 0x00 0x00 0x00 0x01 0x10 0x00 0x00 0x00 0x00 0x00
                0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0xbc 0xda 0xcd 0xab 0xcd 0xab 0xba 0xdc
            0x30 0x00 0x00 0x00 0x00 0x2D 0x00 0x02 0x09 0x08 0x09 0x10 0x10 0x10 0x32 0x54 0x76 0x98 0x07
            0x02 0xFB 0xF8 0x0A 0x04 0x81 0x00 0x01 0x02 0x03 0x0B 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0x00
            0x00 0xFF 0x01 0x08 0x03 0xFF 0xFF 0xFF 0x06 0x04 0xFF 0xFF 0xFF 0xFF 0x09 0x01 0x03
      About the data:

      0x30 0x00 0x00 0x00           : Total length of the Activate ONCHIP SIM Payload data
      0x2D 0x00                     : Total Length of the TLV Data
      0x02 0x09 0x08 0x09 0x10 0x10 0x10 0x32 0x54 0x76 0x98               :  IMSI:  0x001 01 0123456789
      0x07 0x02 0xFB 0xF8           :  Access Class:
      0x0A 0x04 0x81 0x00 01 02     :  Administrative Data:
      0x03 0x0B 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0xFF 0x0x00 0x0x00 0xFF 0x01 :  LOCI
      0x08 0x03 0xFF 0xFF 0xFF      :  FPLMN
      0x06 0x04 0xFF 0xFF 0xFF 0xFF :  SST
      0x09 0x01 0x03                :  Phase

   \endcode


   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \return true if successful, false if fail.

   \warning The SPC code must be sent to the phone first, using QLIB_DIAG_SPC_F()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_MMGSDIDIAG_ACTIVATE_ONCHIP_SIM_CMD_FixedConfig
   (
      HANDLE hResourceContext
   );

   /*
      GSDI commands with Event response.

      This group of commands has response packets which are in the form of "event"
      responses, rather than "delayed" responses.  The difference has to do with the
      type of packet that contains the response information.

      For this group, the process of getting response data is different from
      the delayed response types.  In addition to calling the GSDI request command,
      the function QLIB_GSDIDIAG_GetEventResponse() must be called to get the request
      response information.

      An example of this can be seen in QLibDemo.cpp, in the function Test_Security(),
      which calls QLIB_GSDIDIAG_GET_FEATURE_INDICATION_CMD()

      If the request command is not directly available in QMSL, it is possible to send
      the request directly using QLIB_GSDIDIAG_SendRequestWithEventResponse().  Then
      any command can be requested and the response can be captured with
      QLIB_GSDIDIAG_GetEventResponse().
   */
   /******************************************************************************/
   /**

   Function to send any user defined "event response GSDI function"
   This funtion will enable the event capturing and prepare the proper header
   for the request packet:
      CMD_CODE
      SUBSYS_CODE
      SUBSYS_CMD_CODE
      SIM_SLOT_NUMBER

   The user must supply the remaining request parameters in the data buffer, pUserRequestData

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSUBSYS_CMD_CODE = GSDI command number, to be used for the field, SUBSYS_CMD_CODE, refer to
                             enumeration, GSDI_DIAG_CMD_Enum.
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param pUserRequestData = all data after the SIM_SLOT_NUMBER field, NULL if there are no parameters
   \param iUserRequestDataSize = number of bytes to be sent in pUserRequestData, 0 if there are no parameters
   \param piTransactionID = Output, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if a valid event was found, matching the transaction ID and the event
         which were specified in iTransactionID and iEventID.


   \warning Before this function, one of the specific GSDI requests should be made
         (e.g. GSDIDIAG_VERIFY_PIN_CMD), or the generic event-based GSDI request
         should be made QLIB_GSDIDIAG_SendRequestWithEventResponse()



   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SendUserDefineEventResponseCommand(
      HANDLE hResourceContext,
      unsigned short iSUBSYS_CMD_CODE,
      unsigned char iSlotId,
      void* pUserRequestData,
      unsigned short iUserRequestDataSize,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   Function used to get the event response for all GSDI functions which result
   in event responses.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iTransactionID = Input, the transaction ID returned by the request
   \param iEventID = Input, the event ID to wait for, e.g. EVENT_GSDI_GET_FEATURE_IND. For
                     a wildcard event type, use QMSL_EVENT_ID_WILDCARD and any event will be
                 returned
   \param pEvent = a pointer to an event structure, QMSL_Event_Element_Struct.

               They "payload" field of this structure maps to a GSDIDIAG_EventHeader structure.


   \return true if a valid event was found, matching the transaction ID and the event
         which were specified in iTransactionID and iEventID.


   \warning Before this function, one of the specific GSDI requests should be made
         (e.g. GSDIDIAG_VERIFY_PIN_CMD), or the generic event-based GSDI request
         should be made QLIB_GSDIDIAG_SendRequestWithEventResponse()



   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GetEventResponse(
      HANDLE hResourceContext,
      unsigned short iTransactionID,
      unsigned short iEventID,
      void* pEvent
   );

   /******************************************************************************/
   /**
   GDSI ICD, 2.6 GSDIDIAG_VERIFY_PIN_CMD

   ICD description:
      This command is used to verify the requested PIN. Currently used to verify PIN1/CHV1 or
      PIN2/CHV2. When the proper ID is supplied, it can be used to verify other PINs.
      This command will not need to Read/Write to EFS. Upon completion of this command, the result
      in EVENT_GSDI_SIM_VERIFY_PIN will send a status as well as the number of retries
      remaining.

   Related script command:  SIMVerifyPin

     The QMSL function will currently >>not<< process the event that results from this
     function call.  Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PIN_ID = input,
     \code
       - 0x00 = PIN1 (SIM/RUIM) PIN1 Application 1 (USIM)
       - 0x01 = PIN2 (SIM/RUIM) PIN1 Application 2 (USIM)
       - 0x02 = PIN1 Application 3 (USIM)
       - 0x03 = PIN1 Application 4 (USIM)
       - 0x04 = PIN1 Application 5 (USIM)
       - 0x05 = PIN1 Application 6 (USIM)
       - 0x06 = PIN1 Application 7 (USIM)
       - 0x07 = PIN1 Application 8 (USIM)
       - 0x0A = ADM1
       - 0x0B = ADM2
       - 0x0C = ADM3
       - 0x0D = ADM4
       - 0x0E = ADM5
       - 0x11 = UNIVERSAL PIN
       - 0x81 = PIN2 Application 1 (USIM)
       - 0x82 = PIN2 Application 2 (USIM)
       - 0x83 = PIN2 Application 3 (USIM)
       - 0x84 = PIN2 Application 4 (USIM)
       - 0x85 = PIN2 Application 5 (USIM)
       - 0x86 = PIN2 Application 6 (USIM)
       - 0x87 = PIN2 Application 7 (USIM)
       - 0x88 = PIN2 Application 8 (USIM)
       - 0x8A = ADM6
       - 0x8B = ADM7
       - 0x8C = ADM8
       - 0x8D = ADM9
       - 0x8E = ADM10-
    \endcode
    \param sSIM_PIN = input, NULL terminated string containing pin
   \param piTransactionID = Output, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_VERIFY_PIN_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned char iSIM_PIN_ID,
      char* sSIM_PIN,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 2.3 GSDIDIAG_SIM_READ_CMD

   ICD description:
      This is used to retrieve information from a Cyclic/Binary/Record Elementary Files from SIM.
      The data retrieved will be in a raw and unparsed format. It is up to the user to parse the data per
      the following specification. All fields are mandatory unless they specifically indicate that they
      are optional.
      The command is processed and put onto the GSDI Task Command Queue. If the queuing of the
      command is successful, a response with a valid Transaction ID is provided. Check the Command
      Status and verify that it is non-zero before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client that the contents of the request can now be accessed from the filename provided in the
      request.
      Disclaimer: The client must maintain the EFS filenames and ensure that the same filenames are
      not used without first retrieving the data.

   Related script command:  READ_BINARY

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_ElementaryFile = input, see enumeration defintion, GSDI_DIAG_SIM_ElementaryFile_Enum
   \param iSIM_SimpleReq = input, Represents if write parameters are user specified values, or
                     the phone calculates appropriate values; also represents if the
                     user has to deal with chunking:
     \code
        0 = GSDIDIAG_SIM_SIMPLE_REQ_ONE_STEP, User specified values for SIM_INDEX_MODE, SIM_
            OFFSET, SIM_REC_NUM, SIM_DATA_LEN: user has to
            deal with chunking: for record based files, user has to
            specify SIM_REC_NUM
        1 = GSDIDIAG_SIM_SIMPLE_REQ_ALL_STEPS, Phone uses appropriate values; also returns the
            complete data in a file; user is transparent to chunking
     \endcode
   \param iSIM_IndexMode = input, See GSDI_DIAG_IndexModes_Enum
   \param iSIM_Offset = Input, Range = 0 to 256, Set to 0 when an offset is not to be specified
   \param iSIM_RecNum = Input, Range = 0 to 500.  Set to 0 when a Record Number is not required;
                     this will be the case when the file is either Cyclical or Binary/Transparent
   \param iSIM_DataLen = Input, Number of bytes to write
   \param sEFS_Filename = Input, Range = Variable; must be Null Terminated. File on EFS that the read data is to be stored in

   \param piTransactionID = Output, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SIM_READ_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long iSIM_Elementary_File,
      unsigned char iSIM_SimpleReq,
      unsigned char iSIM_IndexMode,
      unsigned short iSIM_Offset,
      unsigned short iSIM_RecNum,
      unsigned short iSIM_DataLen,
      char* sEFS_Filename,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 2.3.4 GSDIDIAG_SIM_WRITE_CMD

   ICD description:
   This command is used to store information on a Binary/Record Elementary Files in the
   SIM/USIM/RUIM. It is important that all relevant CHV/PIN(s) are considered and that all PIN
   Verification Procedures are performed prior to attempting a write. Otherwise, the write request
   will fail.
   The Command will result in a write to the EFS filename provided. The interface will then
   retrieve this information and write it to the SIM. EVENT_GSDI_SIM_WRITE is generated as a
   result of completion of this command.

   Related script command:  WRITE_BINARY

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_ElementaryFile = input, see enumeration defintion, GSDI_DIAG_SIM_ElementaryFile_Enum
   \param iSIM_SimpleReq = input, Represents if write parameters are user specified values, or
                     the phone calculates appropriate values; also represents if the
                     user has to deal with chunking:
     \code
        0 = User specified values for SIM_INDEX_MODE, SIM_
            OFFSET, SIM_REC_NUM, SIM_DATA_LEN: user has to
            deal with chunking: for record based files, user has to
            specify SIM_REC_NUM
        1 = Phone uses appropriate values; also returns the
            complete data in a file; user is transparent to chunking
     \endcode
   \param iSIM_IndexMode = input, See GSDI_DIAG_IndexModes_Enum
   \param iSIM_Offset = Input, Range = 0 to 256, Set to 0 when an offset is not to be specified
   \param iSIM_RecNum = Input, Range = 0 to 500.  Set to 0 when a Record Number is not required;
                     this will be the case when the file is either Cyclical or Binary/Transparent
   \param iSIM_DataLen = Input, Number of bytes to write
   \param sEFS_Filename = Input, Range = Variable; must be Null Terminated. File on EFS that the data is taken from.
   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SIM_WRITE_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long iSIM_Elementary_File,
      unsigned char iSIM_SimpleReq,
      unsigned char iSIM_IndexMode,
      unsigned short iSIM_Offset,
      unsigned short iSIM_RecNum,
      unsigned short iSIM_DataLen,
      char* sEFS_Filename,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 2.4 GSDIDIAG_GET_FILE_ATTRIBUTES_CMD

   ICD description:
      This command, when called, will get an immediate response based on whether the command was
      successfully queued. The Command contents are as follows:

   Related script command:  GET_FILE_ATTR

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_AppIdLen = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param piSIM_AppId = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_ElementaryFile = input, see enumeration defintion, GSDI_DIAG_SIM_ElementaryFile_Enum

   \param sEFS_Filename = Input, Range = Variable; must be Null Terminated. File on EFS that the read data is to be stored in

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GET_FILE_ATTRIBUTES_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_AppIdLen,
      unsigned char* piSIM_AppId,
      unsigned long iSIM_Elementary_File,
      char* sEFS_Filename,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 2.10 QLIB_GSDIDIAG_GET_AVAILABLE_APPS

   ICD description:
      This command is used to get applications available on a SIM card.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param piNumSlots = number of slots reported
   \param pbSlot1Inserted = true if slot 1 has a card
   \param piSlot1Apps = bit mask of applications enabled on the slot 1 card,
                  GSDI_DIAG_SIM_AppsList defines the bit mask values
   \param pbSlot2Inserted = true if slot 2 has a card
   \param piSlot2Apps = bit mask of applications enabled on the slot 2 card
                  GSDI_DIAG_SIM_AppsList defines the bit mask values

   \return true if successful, false if fail.

   \warning The Slot 2 report has not been verified yet.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GET_AVAILABLE_APPS
   (
      HANDLE hResourceContext,
      unsigned char* piNumSlots,
      unsigned char* piSlot1Inserted,
      unsigned char* piSlot1Apps,
      unsigned char* pbSlot2Inserted,
      unsigned char* piSlot2Apps
   );

   /******************************************************************************/
   /**

   GDSI ICD, 3.9 GSDIDIAG_ACTIVATE_FEATURE_INDICATOR_CMD

   ICD description:
      This command is used to activate the personalization feature indicator in SIM Lock feature. All
      fields are mandatory unless they specifically indicate that they are optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMActivateFeature

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param sSIM_PersoKey = input, Personalization Key Value; Input is in string format, NULL terminated

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_ACTIVATE_FEATURE_INDICATOR_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      char* sSIM_PersoKey,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 3.10 GSDIDIAG_DEACTIVATE_FEATURE_INDICATOR_CMD

   ICD description:
      This request message is used to deactivate the personalization feature indicator in SIM Lock
      feature. All fields are mandatory unless they specifically indicate that they are optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMDeactivateFeature

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param sSIM_PersoKey = input, Personalization Key Value; Input is in string format, NULL terminated

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_DEACTIVATE_FEATURE_INDICATOR_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      char* sSIM_PersoKey,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 3.11 GSDIDIAG_GET_FEATURE_INDICATION_CMD

   ICD Description:
      This request message is used to get the various personalization feature indication with respect to
      SIM Lock feature. All fields are mandatory unless they specifically indicate that they are
      optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMGetFeatureIndicators

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GET_FEATURE_INDICATION_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 3.12 GSDIDIAG_SET_FEATURE_INDICATOR_DATA_CMD

   ICD Description:
      This request message is used to set the data for the corresponding personalization feature
      indicator that the mobile is required to compare to the SIM with. All fields are mandatory unless
      they specifically indicate that they are optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successfully, a response with a valid Transaction ID is provided.
      Check the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMSetFeatureData

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param piSIM_PersoData = input, byte buffer
   \code
      Personalization Data Value. Input is in HEX
      representation + string format
      Formats of the data are:
      - Network personalization (multiple of 3 bytes)
       As defined in IMSI, e.g.:
         - 44097(2 digits MNC) . >= 44F079
         - 440973 (3 digits MNC) >= 443079

      Network Subset personalization (multiple of 4 bytes)
      As defined in Network personalization + 6 and 7 bits in
      IMSI, e.g.;
          - 4409712 (2 digits MNC) >= 44F07921
          - 44097312 (3 digits MNC) >= 44307921

      Service Provider personalization (multiple of 5 bytes)
      MCC + MNC + bcd format of service provider code, e.g.:
        - MCC + MNC=44097, SP=6 >= 44F07960
        - MCC + MNC=440973, SP=12 >= 44307921

      Corporate personalization (multiple of 6 bytes)
      Network personalization + Service provider
      personalization representation + Corporate code in
      BCD format, e.g.:
        - MCC + MNC = 44097, SP = 13, CP = 17, >= 44F0793171
        - SIM/USIM personalization

      When multiple data entries are made for each
      personalization level data, each entry should follow the
      format indicated above and there should be no space in
      between entries

   \endcode
   \param iSIM_PersoDataSize = size of piSIM_PersonData, in bytes
   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_SET_FEATURE_INDICATOR_DATA_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      unsigned char* piSIM_PersoData,
      unsigned short iSIM_PersoDataSize,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 3.12 GSDIDIAG_GET_FEATURE_INDICATOR_DATA_CMD

   ICD Description:
      This is used to get the data for the corresponding personalization feature indicator data set
      in the module.  All fields are mandatory unless they specifically indicate that it is an optional field.
      The Command is processed and put onto the GSDI Task Command Queue.  So long as the Queuing of the
      command is successfully, a response with a valid Transaction ID is provided.  Please check the Command
      Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify the client.

   Related script command:  SIMSetFeatureData

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param sEFS_Filename = File at which the return PersoData will be stored at
   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GET_FEATURE_INDICATOR_DATA_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      char* sEFS_Filename,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**

   GDSI ICD, 3.13 GSDIDIAG_GET_FEATURE_INDICATOR_KEY_CMD

   ICD Description:
      This request message is used to get the various personalization feature control key value with
      respect to SIM Lock feature. All fields are mandatory unless they specifically indicate that they
      are optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMGetFeatureKey

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param sEFS_Filename = File at which the return IMEI + key data will be stored at
   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.	\return true if successful, false if fail.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GET_FEATURE_INDICATOR_KEY_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      char* sEFS_Filename,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 3.14 GSDIDIAG_UNBLOCK_FEATURE_INDICATOR_CMD

   ICD Description:
      This request message is used to unblock a blocked personalization feature indicator in SIM Lock
      feature. All fields are mandatory unless specifically indicate that they are an optional field.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command: SIMUnblockFeature

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param sSIM_PersoKey = input, Personalization Key Value; Input is in string format, NULL terminated

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_UNBLOCK_FEATURE_INDICATOR_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      char* sSIM_PersoKey,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 3.15 GSDIDIAG_GET_PERM_FEATURE_INDICATION_CMD

   ICD Description:
      This request message is used to get the various permanent personalization feature indication with
      respect to SIM Lock feature. All fields are mandatory unless they specifically indicate that they
      are optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMGetPermanentFeatureIndicators

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_GET_PERM_FEATURE_INDICATION_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

   /******************************************************************************/
   /**
   GDSI ICD, 3.16 GSDIDIAG_PERM_DISABLE_FEATURE_INDICATOR_CMD

   ICD Description:
      This request message is used to permanently disable a personalization feature indicator in SIM
      Lock feature. All fields are mandatory unless they specifically indicate that they are optional.
      The command is processed and put onto the GSDI Task Command Queue. So long as the
      queuing of the command is successful, a response with a valid Transaction ID is provided. Check
      the Command Status and verify it is successful before accepting the Transaction ID.
      At the completion of the Command Processing in the GSDI Task, an event is generated to notify
      the client.

   Related script command:  SIMDisableFeaturePermanently

     The QMSL function will currently >>not<< process the event that results from this
     function call. Use QLIB_GSDIDIAG_GetEventResponse() to get the response data, see
     QLibDemo.cpp ->Test_Security() for an example of this.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iSlotID = input, <See description of GSDIDIAG_ROOT_KEY_WRITE_CMD>
   \param iSIM_PersoFeature = input, see description of GSDI_DIAG_PersoFeature_Enum
   \param sSIM_PersoKey = input, Personalization Key Value; Input is in string format, NULL terminated

   \param piTransactionID = Ouptut, returned in order to identify the related event
   \param piCommandStatus = Output, result of CMD_STATUS field, if not GSDI_SUCCESS then the function returns a false.

   \return true if successful, false if fail.

   \warning Will activate event messages and clear the current event queue

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GSDIDIAG_PERM_DISABLE_FEATURE_INDICATOR_CMD
   (
      HANDLE hResourceContext,
      unsigned char iSlotId,
      unsigned char iSIM_PersoFeature,
      char* sSIM_PersoKey,
      unsigned short* piTransactionID,
      unsigned long* piCommandStatus
   );

	#ifdef __cplusplus
}	// extern "C"
#endif

#endif	// defined(_QLIB_GSDI_DIAG_H)
