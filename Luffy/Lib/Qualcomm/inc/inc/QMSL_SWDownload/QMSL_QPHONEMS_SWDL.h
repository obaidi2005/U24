/******************************************************************************/
/**
Program: QMSL

   $Id: //depot/HTE/QDART/QMSL6/inc/QMSL_SWDownload/QMSL_QPHONEMS_SWDL.h#9 $

\code

   - Defines the "C" interface for all Factory Library functions.

   - Table of contents (text search can be done for the following sections)

         - General Information
         - Related Documents
         - Version History
         - Callback function definitions

         - Connection/Disconnection Functions
         - Text LoggingQ
         - Diagnostic subsystem
         - LTE Diag
         - HDR Diag
         - GSM Diag
         - Streaming Download Diag
         - Diagnostic commands
         - Phone async Logging
         - Phone sync (command) Logging
         - Keypad Diag
         - Handset Diag
         - MediaFLO Diag
         - CGPS Diag
         - ISDB-T Diag
         - MBP Diag

         - Commands for multiple FTM modes
         - Dual RX Chain FTM RF Commands
         - FTM CDMA RF Calibration API V2
         - GSM FTM
         - GSM Polar Tx Cal FTM
         - GSM Linear Tx FTM
         - PMIC FTM
         - cdma2000 FTM
         - cdma2000 FTM non-signaling
         - EVDO Non-signaling FTM
         - Camera FTM
         - FTM Log

         - WCDMA BER FTM
         - HSDPA BER FTM

         - GSM BER FTM
         - EGPRS BER FTM
         - UMTS SINGLE ENDED BER FTM
         - GSDI Diag
         - AGPS FTM
         - Common RF FTM
         - LTE Non-signaling FTM
         - MediaFLO FTM
         - MediaFLO FTM UBM
         - MediaFLO NS FTM
         - DVB-H Diag Commands
         - WLAN FTM
         - QFUSE FTM
         - GPS FTM


         - Software Download
         - EFS Functions

         - Calibration Data Manager
         - NVTool

         - FTM Sequencer
         - Band Class Helper
         - WP7 PVK

   ------------------------------------------------------


   ----------------------
   General Information
   ----------------------

   - All data types used in this interface are ANSI C compatible.

   - All returns that indicate "true if succeed, false if fail" are defined
      as:  1 = true = Success , 0 = false = failure

      Functions that are not entirely upper case do not correspond directly to
      an FTM or diagnostic command.

      For example, QLIB_ConnectServer() is not mapped directly to a diagnostic
      command.


   - Variable Names
      Variable names are prefixed in lower case to indicate the data type.
      The following are defined:

         p = Pointer
         i = Integer type, either char, short, or long
         d = Double or floating point
         e = Enumeration (possibly stored as a short, but representing
                          a fixed list of possibilities)
         b = unsigned char, 0=false, 1=true

   ----------------------
   Related Documents
   ----------------------

   - The function name convention used in this document is as follows:

      QLIB_ indicates that this function corresponds to library function
      in the QLib project.

      From there, all diagnostic and FTM functions are named exactly as
      the command identifiers are defined in the QLib_Defines.h.

   - For a list of all document numbers referred to by QMSL, please see following section in the QDART Help file:
      1) QDART -> QDART Related Documents
   or  2) QDART -> QMSL -> Getting Started -> References.


\endcode


   -----------------------
   Version History
   -----------------------

 \b QUALCOMM  \b PROPRIETARY

   This document contains propriety information, and except with written
   permission of Qualcomm Technologies INC, such information shall not be
   published, or disclosed to others, or used for any purpose, and the
   document shall not be duplicated in whole or in part.


	Copyright (c) 2004-2012 QUALCOMM Technologies Incorporated.
   All Rights Reserved.
   Qualcomm Confidential and Proprietary

\version
Version information is stored in the file "QMSL_Release_Notes.txt"

\note
Compiler:  Microsoft Visual C++ v6.0 SP4
*******************************************************************************/

#if !defined(_QLIB_QPHONES_SWDL_H)
#define _QLIB_QPHONES_SWDL_H

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



   /**
      Call back for general SW Download event( replaces the other non-EFS call backs)

      Optional for NV backup/restore and normal download.  Must be used for boot loader and
      multimage download
   */
   //typedef unsigned char( *generalSWDownloadCB )
   //(
   //   unsigned char* pEventStructure	// type union generalSwDownloadEvent_union, as defined in SoftwareDownload.h
   //   // Not declared explicitly here because general users do not need to
   //   // include the SWDownload.h file.
   //);

   /******************************************************************************
                  Streaming Download Diag
   *******************************************************************************/

   /******************************************************************************/
   /**
   Streaming Download ICD, 3.2.1 19 Hello packet, A specialized version of this
   command, to be used as a method to PING a phone in download mode.

   Call DOWNLOAD_Hello with default parameters.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_Ping( HANDLE hResourceContext );

      /******************************************************************************/
   /**
   Streaming Download ICD, 3.2.1 19 Hello packet

   This function sends the "hello" packet to the phone, and returns the response
   message, in its entirety, by copying the response packet to a user defined
   buffer.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iVersionNumber = Host shall set this field to indicate the maximum version
                           of this protocol that the host supports. The value for this
                     field is 0x03.

   \param iCompatibleVersion = Host shall set this field to indicate the lowest version
                               of the protocol that it supports. The value for this field
                        is 0x02.

   \param iFeatureBits = Host shall set these bits to indicate the negotiated set
                         of features requested to be used.

   \param pResponseBuffer = The entire response packet, as defined by section 3.2.2 of
                            the streaming download ICD.

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning The function must run in QPHONEMS mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_Hello
   (
      HANDLE hResourceContext,
      unsigned char iVersionNumber,
      unsigned char iCompatibleVersion,
      unsigned char iFeatureBits,
      unsigned char* pResponseBuffer
   );


   /******************************************************************************/
   /**
   Streaming Download ICD, x.x.x QFprom Write

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRowAddress = Row Address

   \param iAddressType = 0 = Corrected Reads
                         1 = Raw Reads

   \param iMSBBytes = Most Significant Bytes.

   \param iLSBBytes = Least Significant Bytes

   \param iErrorCode = 0 if the operation is successful
                  otherwise, return the error code from error response message (0xD) defined in Streaming Download Protocol ICD

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning
   /******************************************************************************/
   /**
   Streaming Download ICD, x.x.x QFprom Write

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRowAddress = Row Address

   \param iAddressType = 0 = Corrected Reads
                         1 = Raw Reads

   \param iMSBBytes = Most Significant Bytes.

   \param iLSBBytes = Least Significant Bytes

   \param iErrorCode = 0 if the operation is successful
                  otherwise, return the error code from error response message (0xD) defined in Streaming Download Protocol ICD

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning The function must run in QPHONEMS mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_QFprom_Write
   (
      HANDLE hResourceContext,
      unsigned long iRowAddress,
      unsigned long iMSBBytes,
      unsigned long iLSBBytes,
      unsigned long *iErrorCode
   );
   /******************************************************************************/
   /**
   Streaming Download ICD, QEprom Read

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()

   \param iRowAddress = Row Address

   \param iAddressType = 0 = Corrected Reads
                         1 = Raw Reads

   \param iMSBBytes = Most Significant Bytes.

   \param iLSBBytes = Least Significant Bytes

   \param iErrorCode = 0 if the operation is successful
                  otherwise, return the error code from error response message (0xD) defined in Streaming Download Protocol ICD
                  iMSBBytes, and iLSBBytes will be returned as 0

   \return true if response packet was successfully returned, false if fail for any reason.

   \warning The function must run in QPHONEMS mode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DOWNLOAD_QFprom_Read
   (
      HANDLE hResourceContext,
      unsigned long iRowAddress,
      unsigned long iAddressType,
      unsigned long *iMSBBytes,
      unsigned long *iLSBBytes,
      unsigned long *iErrorCode
   );

   /******************************************************************************/
   /**
   Upload software image for NOR targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   NOR includes QSC1215...

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path
   \param sMBNFileName = MODEM file, usually "all.mbn"
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE
   \param bDownloadReset      = 0 == false (essentially skip reset after download)
                                1 == true 
                           If the flag is TRUE, phone will reset after downloaded
                           The flag must be set to FALSE
   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             QSC1215 = 5000;

   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                           QSC1215 = 5000;
                           
   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning Note, sDSP1, sMBR, sADSP files are not supported yet

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadNORImage(		
 	 HANDLE hResourceContext,
	 char* sARMPRG_FileName,
	 char* sMBNFileName,
	 unsigned char bSkipGoToDownload,
	 unsigned char bDownloadReset,
	 unsigned long iSleepTimeToDOWNLOADmode,
	 unsigned long iSleepTimeToGOcommand,
	 unsigned long* iErrorCode
	 );


   /******************************************************************************/
   /**
   Upload software image with CDT information from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path
   \param sRawProgramFileName = RawProgram xml file path, usually "rawprogram_unsparse.xml"
   \param sPatchFileName = Patch xml file path, usually "patch0.xml"
   \param sEmmcUserPartitionImage = User Partition image file
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   
   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                            
   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                           
   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning Note, sDSP1, sMBR, sADSP files are not supported yet

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcUserParitionImageWithCDT(		
 	 HANDLE hResourceContext,
	 char* sARMPRG_FileName,
	 char* sRawProgramFileName,
	 char* sPatchFileName,
	 char* sEmmcUserPartitionImage,
	 unsigned char bUseTrustedMode,
	 unsigned long iSleepTimeToDOWNLOADmode,
	 unsigned long iSleepTimeToGOcommand,
	 unsigned long* iErrorCode
	 );


   /******************************************************************************/
   /**
   Upload software image for Secure Boot 1.0 targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Secure Boot 1.0 target includes MSM7x01, MSM7x25, MSM7x27

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path
   \param sPartitionFileName = Partition File Path, usually "partition.mbn"
   \param sPriBootLoader_FileName= Primary Boot Loader File Path, usually, "pbl.mbn"
   \param sQCSecBootLoader_FileName= Qualcomm Secondary Boot Loader, usually "qcsbl.mbn"
   \param sQCSecBootLoaderHeader_FileName= Qualcomm Secondary Boot Loader Header, usually qcsblhd_cfgdata.mbn"
   \param sOEMSecBootLoader_FileName= OEM Secondary Boot Loader, usually "oemsbl.mbn"
   \param sOEMSecBootLoaderHeader_FileName= OEM Secondary Boot Loader Header, usually "oemsblhd.mbn"
   \param sModemFile_FileName= AMSS modem file, usually amss.mbn"
   \param sModemFileHeader_FileName= AMSS modem file header, usually "amsshd.mbn"
   \param sAppsFile_FileName=  AMSS application file, usually "apps.mbn"
   \param sAppsFileHeader_FileName= AMSS application file header, "appshd.mbn";
   \param sAppsBootLoaderFile_FileName= AMSS application boot loader file, usually "appsboot.mbn";
   \param sAppsBootLoaderFileHeader_FileName= AMSS application boot loader header file, usually "appsboothd.mbn";
   \param sWinMobile_FileName= Winmobile file, usually "flash.bin"
   \param sDSP1_FileName= DSP1 file, usually "dsp1.mbn"
   \param sMBR_FileName= MBR file, usually "mbr.mbn"
   \param sADSP_FileName= ADSP file, usually "adsp.mbn"
   \param sCefsModem_FileName = CEFS MODEM file, usually "cefs_modem.mbn"
   \param bOverridePrtnTable = TRUE(1)  to overwrite the stored partition table in the phone
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MSM7x25 = 5000;
                             MSM7x25 = 5000;

   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                           MSM7x25 = 5000;
                           MSM7x25 = 5000;

   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning Note, sDSP1, sMBR, sADSP files are not supported yet

   *******************************************************************************/




   QLIB_API unsigned char QLIB_QPHONEMS_UploadSB1MultiImage
   (   HANDLE hResourceContext,
       char* sARMPRG_FileName,
       char* sPartitionFileName,
       char* sPriBootLoader_FileName,
       char* sQCSecBootLoader_FileName,
       char* sQCSecBootLoaderHeader_FileName,
       char* sOEMSecBootLoader_FileName,
       char* sOEMSecBootLoaderHeader_FileName,
       char* sModemFile_FileName,
       char* sModemFileHeader_FileName,
       char* sAppsFile_FileName,
       char* sAppsFileHeader_FileName,
       char* sAppsBootLoaderFile_FileName,
       char* sAppsBootLoaderFileHeader_FileName,
       char* sWinMobile_FileName,
       char* sDSP1_FileName,
       char* sMBR_FileName,
       char* sADSP_FileName,
       char* sCefsModem_FileName,
       unsigned char bOverridePrtnTable,
       unsigned char bUseTrustedMode,
       unsigned char bSkipGoToDownload,
       unsigned long iSleepTimeToDOWNLOADmode,
       unsigned long iSleepTimeToGOcommand,
       unsigned long *iErrorCode
   );

   QLIB_API unsigned char QLIB_QPHONEMS_SetupStrmDlRetries
   (	
		HANDLE hResourceContext, 
		unsigned long iSleepTimeToRetryHello,
		unsigned long iMaxTriesToHello,
		unsigned long iSleepTimeToRetryNop,
		unsigned long iMaxTriesToNop
	);
   /******************************************************************************/
   /**
   This method is design to work with the fastboot command.
   In Multi unit download enviornment, a fastboot command need to be directed towards specific
   device. This method sets a command that identifies the device as a unqiue

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param serialNumber = serialnumber is the token that is going to get set for fastboot to be used.

   /warning: token can not exceed more than 16 characters.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SetFactoryToken(HANDLE hResourceContext, char *serialNumber);


   

   /******************************************************************************/
   /**
   Upload software image for Secure Boot 3.0 targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Secure Boot 3.0 targets includes 9x15

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files using the user partition method. 

   The function will return once RESET command is issued after MBN download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path name. For example, "NPRG9x15.hex"(regular ARMPRG) or "ENPRG9x15.hex" (emergency downloader)
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param pPartitonList = contains a pointer to a structure providing information about the .mbn files that are going to be programmed into the device. 
						   At the moment, limit is set to 10 files on the partition name / parition files. Please use the SWDL_UserPartitionList structre. 
						   sPartitionName will contain the partition name. Note: Use the "0:SBL1" as the first partition name. the partition string must be null terminated!
						   sPartitionMBNPath will contain the mbn file path. 
			struct
			{
				 char sPartitionName[10];                      // PartitionName For example, 0:SBL1     
				 char sPartitionMBNPath[256];                // Path to the mbn files
			}SWDL_UserPartitionEntry;

			struct
			{
				 SWDL_UserPartitionEntry oPartitionList[10];
				 int  iNumOfPartitionEntry;
			}SWDL_UserPartitionList;

   \param bOverridePrtnTable = TRUE(1)  to overwrite the stored partition table in the phone
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MDM9k = 5000;
                             SCMM (MDM6k, QSC6x95) = 5000;
                             LCU (QSC6240/70) = 5000


   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                             MDM9k = 3000;
                             SCMM (MDM6k, QSC6x95) = 3000;
                             LCU (QSC6240/70) = 5000

    \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h   

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DownloadUserPartitions
   (
		HANDLE hResourceContext,
		char* sARMPRG_FileName,
		char* sPartitionFileName,
		void* pPartitonList,
		unsigned char bOverridePrtnTable,
		unsigned char bUseTrustedMode,
		unsigned char bSkipGoToDownload,		
		unsigned long iSleepTimeToDOWNLOADmode,
		unsigned long iSleepTimeToGOcommand,
		unsigned long *iErrorCode
   );

   /******************************************************************************/
   /**
   Upload software image for Secure Boot 2.0 targets from the PC to the phone.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Secure Boot 2.0 target includes QSC6240/6270, QSC6x95, QSD8x50, MDM9k

   Software Download is a 3 step process

   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download MBN files

   The function will return once RESET command is issued after MBN download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   For the file type that is NOT uploaded, user should pass NULL as argument.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path name. For example, "NPRG6695.hex"(regular ARMPRG) or "ENPRG6695.hex" (emergency downloader)
   \param sPartitionFileName = partition path and file name, usually "partition.mbn"
   \param sDeviceBootLoader_FileName = Device Boot Loader Name, usually "dbl.mbn"
   \param sQFailSafeBootLoader_FileName = Fail safe boot loader name, usually "fsbl.mbn"
   \param sOSBootLoader_FileName = OS boot loader name, usually "osbl.mbn"
   \param sModem_FileName = AMSS File, usually "amss.mbn"
   \param sApps_FileName = AMSS boot loader, usually "apps.mbn"
   \param sAppsBootLoader_FileName = AMSS boot loader, usually "appsboot.mbn"
   \param sWinbMobile_FileName = Win Image Name, usually "flash.bin"
   \param sDSP1_FileName = DSP1 file name, usually "dsp1.mbn"
   \param sDSP2_FileName = DSP2 file name, usually "dsp2.mbn"
   \param sMBR_FileName = MBR file name, usually "mbr.bin"
   \param sADSP_FileName = MBR file name, usually "adsp_q5.mbn"
   \param sTrustZone = Trust Zone name, usually "tzos.mbn"
   \param sROFS1 = ROFS1 file, usually "file.rofs1"
   \param sROFS2 = ROFS2 file, usually "file.rofs2"
   \param sROFS3 = ROFS3 file, usually "file.rofs3"
   \param sCefsModem_FileName = CEFS MODEM file, usually "cefs_modem.mbn"
   \param bOverridePrtnTable = TRUE(1)  to overwrite the stored partition table in the phone
   \param bUseTrustedMode = TRUE(1) to use trusted mode and the AMSS has a built-in PBL.
                                 If FALSE, then PBL must be provided.
                          The flag must be set to TRUE.
   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MDM9k = 5000;
                             SCMM (MDM6k, QSC6x95) = 5000;
                             LCU (QSC6240/70) = 5000


   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                             MDM9k = 3000;
                             SCMM (MDM6k, QSC6x95) = 3000;
                             LCU (QSC6240/70) = 5000

    \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   \warning sMBR_FileName, sADSP_FileName, sTrustZone, sORFS1, sORFS2 and sORFS3 partition files are not yet supported.

   *******************************************************************************/

   QLIB_API unsigned char QLIB_QPHONEMS_UploadSB2MultiImage
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName,
      char* sPartitionFileName,
      char* sDeviceBootLoader_FileName,
      char* sQFailSafeBOotLoader_FileName,
      char* sOSBootLoader_FileName,
      char* sModem_FileName,
      char* sApps_FileName,
      char* sAppsBootLoader_FileName,
      char* sWinMobile_FileName,
      char* sDSP1FileName,
      char* sDSP2FileName,
      char* sMBR_FileName,
      char* sADSP_FileName,
      char* sTrustZone,
      char* sROFS1,
      char* sROFS2,
      char* sROFS3,
      char* sCefsModem_FileName,
      unsigned char bOverridePrtnTable,
      unsigned char bUseTrustedMode,
      unsigned char bSkipGoToDownload,
      unsigned long iSleepTimeToDOWNLOADmode,
      unsigned long iSleepTimeToGOcommand,
      unsigned long *iErrorCode
   );
   /******************************************************************************/
   /**

   Callback function for QMSL client to collect status during software download

   Note: This method will not work with QPST. It requires Qlib connection.

   *******************************************************************************/
   QLIB_API void QLIB_QPHONEMS_UploadSBMultiImage_ConfigureCallBack( HANDLE hResourceContext, swdlQPHONEMSCB pSWDLCallBack);


   /******************************************************************************/
   /**
   Switch to download mode.

   Note: This method will not work with QPST. It requires Qlib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SwitchToDownloadMode(HANDLE hResourceContext, unsigned long iSleepTimeToDownloadMode, unsigned long *iErrorCode);

   /******************************************************************************/
   /**
   Switch to download mode, but does not send the NOP command to ensure that
   Device infact has switched over. The reason for that is that sometimes in download mode
   device changes its port.
   This method simply switches the device into download mode allowing user to make a decision on how to proceed next.

   Note: This method will not work with QPST. It requires Qlib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_SwitchToDownloadMode_OptionalValidation(HANDLE hResourceContext, unsigned long iSleepTimeToDownloadMode, bool checkForNOP, unsigned long *iErrorCode);

   /******************************************************************************/
   /**
   This function reboots the phone based on the DMSS Download Protocol

   Ref Doc (80-39912-1)
   Note: This method will not work with QPST. It requires a QLib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoad_Reset(HANDLE hResourceContext, int timeoutSeconds);

   /******************************************************************************/
   /**
   This function gets the version of the phone based on the DMSS Download Protocol

   Ref Doc (80-39912-1)
   Note: This method will not work with QPST. It requires a QLib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoadVersionReq(HANDLE hResourceContext, int timeoutSeconds);

   /******************************************************************************/
   /**
   This function is used to erase the specified sectors from the unit in the DMSS Download Protocol
   
   Note: This method will not work with QPST. It requires a QLib connection.  Only applicable to QRD target as of Nov 2012.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoad_EraseEMMC(HANDLE hResourceContext, int timeoutSeconds, int Sector, int NoOfSectors);

   /******************************************************************************/
   /**
   Send NOP command to ensure that device is in fact in download mode.

   Note: This method will not work with QPST. It requires Qlib connection.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_DLoad_SendNop(HANDLE hResourceContext, int timeout);

   /******************************************************************************/
   /**
   Uploads the EMMC user partition image file.
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)

   Only supporting 7627A at the moment.



   Step 0: Change mobile from DIAG to DOWNLOAD mode (mobile will re-enumerate)
   Step 1: Download Flash Programmer (Nxxxx.hex) into mobile and issue GO command to start the programmer (mobile will re-enuermate)
   Step 2: Download EMMC user partition image file

   The function will return once RESET command is issued after MBN download

   This function will not backup/restore NV/EFS items from the mobile.  User
   must call other QMSL APIs if backup/restore is required.

   Note: This method will not work with QPST. It requires QPHONEMS connection.

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param sARMPRG_FileName = ARMPRG file path name. For example, "NPRG6695.hex"(regular ARMPRG) or "ENPRG6695.hex" (emergency downloader)
   \param sEmmcUserPartitionImage = EMMC user partition image file

   \param bSkipGoToDownload      = 0 == false
                                   1 == true (essentially skip Step 0)
                           If the phone is already in download mode, user can set bSkipToToDownload to true
                           The flag must be set to FALSE

   \param iSleepTimeToDOWNLOADmode = Sleep time (in ms) for QMSL to wait between step 0 and 1 due to mobile re-enumeration
                             This value is target dependent.  The value provided below is for reference.
                             User can optimize the value based on their platform

                             MDM9k = 5000;
                             SCMM (MDM6k, QSC6x95) = 5000;
                             LCU (QSC6240/70) = 5000


   \param iSleepTimeToGOcommand = Sleep time (in ms) for QMSL to wait between step 1 and 2 due to mobile re-enumeration
                           This value is target dependent.  The value provided below is for reference.
                           User can optimize the value based on their platform

                             MDM9k = 3000;
                             SCMM (MDM6k, QSC6x95) = 3000;
                             LCU (QSC6240/70) = 5000

    \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h

   *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_UploadEmmcUserParitionImage
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName,
      char* sEmmcUserPartitionImage,
      unsigned char bUseTrustedMode,
      unsigned char bSkipGoToDownload,
      unsigned long iSleepTimeToDOWNLOADmode,
      unsigned long iSleepTimeToGOcommand,
      unsigned long *iErrorCode
   );

   /******************************************************************************/
   /**
    Uploads the Flash programmer image file using Sahara Protocol from the host to the device.
   
   Ref Sahara Protocol Doc (80-N1008-1)
   
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer_Sahara method.
   \param sARMPRG_FileName = ARMPRG file path name. For example for 9x25 MTP, "NPRG9x25.mbn"(regular ARMPRG) or "ENPRG9x25.mbn" (emergency downloader)

     *******************************************************************************/
   QLIB_API unsigned char QLIB_QPHONEMS_Sahara_FlashProgrammer
   (
      HANDLE hResourceContext,
      char* sARMPRG_FileName
   );

   /******************************************************************************/
   /**

   Switch the device in Diagnostic mode to Download/Sahara Mode.
   
   Ref Sahara Protocol Doc (80-N1008-1)
   
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer method.
   
   \param iErrorCode = See QMSL_DownloadAgent_Error_Enum in QLib_Defines.h
   
   *******************************************************************************/
  QLIB_API unsigned char QLIB_QPHONEMS_SwitchToDownload_Sahara(HANDLE hResourceContext, unsigned long *iErrorCode);

  /******************************************************************************/
  /**
	Receive the Hello packet after Dload command (will be used for upgrade mechanism), and provide the version number.
	Respond the hello packet as ImageTransfer mode.
 
   Ref Sahara Protocol Doc (80-N1008-1)
   
   The function runs in QPHONEMS mode (aka NO QPSTServer.exe is required)
   
   \param hResourceContext = Resource context that was returned from the call to QLIB_QPHONEMS_ConnectServer method.
   
   \param version = Sahara Protocol version supported and currently used by the device

   \param timeout = Indicates the timeout value for the host to wait for the device to send a Sahara hello packet
   
  *******************************************************************************/

  QLIB_API unsigned char QLIB_QPHONEMS_Sahara_SetImageTransferMode(HANDLE hResourceContext, unsigned long* version, unsigned long timeout);

  /******************************************************************************/
   /**
   	Callback function for the Sahara protocol methods for logging purposes.

   	\param hResourceContext	Resource context that was returned from the call to QLIB_ConnectServer()

	\param pSWDL_QPHONEMS_CB, callback function to display debug messages for Sahara Protocol methods.

  	*******************************************************************************/

  QLIB_API void QLIB_QPHONEMS_SaharaConfigureCallback(HANDLE hResourceContext, swdlQPHONEMSCB pSWDL_QPHONEMS_CB);

   /******************************************************************************/
   /**
   	Read NV and PRL values from mobile.  The method reads all the NV and PRL from the mobile and does not
	require a NV Definition XML file. The method resembles QPST NV backup operation EXCEPT EFS ITEMS.

   	\param hResourceContext	Resource context that was returned from the call to QLIB_ConnectServer()

	\param sQCN_Path - Path of the QCN file. The file, if exists, will be overwritten.

   	\param iResultCode, the result code, See QMSL_Backup_ResultCode_Enum

   	\return true if result code is 0

	\warning 7/1/2012: This method does not backup NV item stored as EFS item file or regular file. It has only been proved to backup NV items
	frin 7x27 target

	The method will be updated to backup EFS NV item in future QMSL release.

	*******************************************************************************/
   QLIB_API unsigned char QLIB_BackupNVFromMobileToQCN(HANDLE hResourceContext, const char *sQCN_Path, int* iResultCode);

#ifdef __cplusplus
}	// extern "C"
#endif

#endif	