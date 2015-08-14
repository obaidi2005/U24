/******************************************************************************/
/**
Program: QLib_CGPS_GNSS

$Id: //depot/HTE/QDART/QMSL6/inc/QMSL_CGPS_GNSS/QMSL_CGPS_GNSS.h#10 $

\brief QLib library routines for the CGPS and GNSS 

\b QUALCOMM  \b PROPRIETARY

This document contains propriety information, and except with written
permission of Qualcomm Technologies INC, such information shall not be
published, or disclosed to others, or used for any purpose, and the
document shall not be duplicated in whole or in part.

Copyright 2013 - Qualcomm Technologies, Inc. 
*******************************************************************************/
#if !defined(_QMSL_CGPS_GNSS_H)
#define _QMSL_CGPS_GNSS_H

#if !defined(_WINDOWS_)
#include "windows.h"
#endif

#include "QMSL_CGPS_GNSS_SOC.h"

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
   /******************************************************************************
                     CGPS DIAG
   *******************************************************************************/

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to enter "Standalone RF verification" mode.


   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlag = input
   \code
        0 = GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE = Enter SA-RF Verif Mode,
      1 = GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE  = Exit SA-RF Verif Mode
         Refer to the enumeration below for bit mask definitions:

            typedef enum
            {
               GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE         = 0x00, // Enter Standalone RF verification mode
               GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE          = 0x01  // Exit Standalone RF verification mode
            } gps_sa_rf_verif_mode_switch_enum_type;
   \endcode

   \param piStatus = output, 0=Command Accepted, 1=Command Rejected

   \return true if successful, false if fail.

   \warning This version of the function does not wait for the associated event.
            Use QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait() to wait for the event.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH(
      HANDLE hResourceContext,
      unsigned char iFlag,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to enter "Standalone RF verification" mode
   and waits for the associated event, EVENT_GPS_LM_ENTER_SA_RF_VERIF #1247

   The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
   timeout type of QMSL_Timeout_CGPS_Event.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlag = input
   \code
        0 = GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE = Enter SA-RF Verif Mode,
      1 = GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE  = Exit SA-RF Verif Mode
         Refer to the enumeration below for bit mask definitions:

            typedef enum
            {
               GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE         = 0x00, // Enter Standalone RF verification mode
               GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE          = 0x01  // Exit Standalone RF verification mode
            } gps_sa_rf_verif_mode_switch_enum_type;
   \endcode
   \param piStatus = output, 0=Command Accepted, 1=Command Rejected

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(
      HANDLE hResourceContext,
      unsigned char iFlag,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to perform one dwell on one channel.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlags            = input, Enables different functionalities
                       Refer to these enumerations for bit mask definitions:
      \code
            typedef enum
            {
               GPS_PRESCRIBED_DWELL_NO_RESULTS            = 0x00, // Do not send dwell results
               GPS_PRESCRIBED_DWELL_SEND_RESULTS          = 0x01  // Send dwell results
            } gps_prescribed_dwell_results_enum_type;   //Bit 0

            typedef enum
            {
               GPS_PRESCRIBED_DWELL_CHIPX1                = 0x00, // Chipx1
               GPS_PRESCRIBED_DWELL_CHIPX2                = 0x02  // Chipx2
            } gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

            typedef enum
         {
                GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS     = 0x00, // Do not report incoherent sums
                GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS  = 0x04  // Report incoherent sums
            } gps_prescribed_dwell_incoher_sums_enum_type; //Bit 2

            typedef enum
            {
                GPS_PRESCRIBED_DWELL_NO_COHER_SUMS       = 0x00, // Do not report coherent sums
                GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS    = 0x08  // Report coherent sums
            } gps_prescribed_dwell_coher_sums_enum_type; //Bit 3

            typedef enum
         {
                GPS_PRESCRIBED_DWELL_START_NOW           = 0x00, // Start now
                GPS_PRESCRIBED_DWELL_USE_TOA              = 0x0A  // Use TOA
            } gps_prescribed_dwell_start_time_enum_type; //Bit[5:4]

            typedef enum
            {
                GPS_PRESCRIBED_DWELL_USE_RF              = 0x00, // Use RF
                GPS_PRESCRIBED_DWELL_USE_TS               = 0x40  // Use TS
            } gps_prescribed_dwell_source_enum_type; //Bit 6

            typedef enum
            {
                GPS_PRESCRIBED_DWELL_NO_INIT             = 0x00, // Do not initialize TS and BC at starte of dwell
                GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC       = 0x80  // Initialize TS and BC at start of dwell
            } gps_prescribed_dwell_source_init_type; //Bit 7
      \endcode
   \param iTOA              = input, Time of Applicability. GPS_RTC time at which dwell must start.
   \param iSV               = input, Satellite PRN [0..32]. If zero, correlation is codeless.
   \param iSearchMode       = input, Pre-Detection Mode.
   \param iPOST_DET_N       = input, Number of Post-Detection.
   \param iTASK_MASK1       = input, Bit31:Bit0 - Task32:Task1. A set bit implies that that task must be selected.
   \param iTASK_MASK2       = input, Bit7:Bit0 - Task40:Task33. A set bit implies that that task must be selected.
   \param iDOPP_FREQ        = input, Signed (1000/65536 Hz/Bit). Range: -32768000 to +32768000 Hz.
   \param iDOPP_FREQ_RATE   = input, Signed (1000/65536 Hz/sec/Bit). Range: -32768000 to +32768000 Hz/sec.
   \param iSUB_MS           = input, Unsigned (1/256 Chips/Bit). Range: 0 to 1023 chips.
   \param iCNO_Threshold    = input, Used for declaring dwell as a detection. Dwell result DM packet.
                       will be send only if CNo exceeds this threshold. Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.
   \param iJammerThreshold  = input, Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.

   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning This version of the function does not wait for the response event. To wait for
            the event use QLIB_DIAG_GPS_PRESCRIBED_DWELL_WithWait

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL(
      HANDLE hResourceContext,
      unsigned short iFlags,
      unsigned long iTOA,
      unsigned char iSV,
      unsigned char iSearchMode,
      unsigned short iPOST_DET_N,
      unsigned long iTASK_MASK1,
      unsigned char iTASK_MASK2,
      unsigned long iDOPP_FREQ,
      unsigned long iDOPP_FREQ_RATE,
      unsigned long iSUB_MS,
      unsigned short iCNO_Threshold,
      unsigned short iJammerThreshold,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to perform one dwell on one channel, then
   wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

   The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
   timeout type of QMSL_Timeout_CGPS_Event.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlags            = input, Enables different functionalities
                       Refer to these enumerations for bit mask definitions:
      \code
            typedef enum
            {
               GPS_PRESCRIBED_DWELL_NO_RESULTS            = 0x00, // Do not send dwell results
               GPS_PRESCRIBED_DWELL_SEND_RESULTS          = 0x01  // Send dwell results
            } gps_prescribed_dwell_results_enum_type;   //Bit 0

            typedef enum
            {
               GPS_PRESCRIBED_DWELL_CHIPX1                = 0x00, // Chipx1
               GPS_PRESCRIBED_DWELL_CHIPX2                = 0x02  // Chipx2
            } gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

            typedef enum
         {
                GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS     = 0x00, // Do not report incoherent sums
                GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS  = 0x04  // Report incoherent sums
            } gps_prescribed_dwell_incoher_sums_enum_type; //Bit 2

            typedef enum
            {
                GPS_PRESCRIBED_DWELL_NO_COHER_SUMS       = 0x00, // Do not report coherent sums
                GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS    = 0x08  // Report coherent sums
            } gps_prescribed_dwell_coher_sums_enum_type; //Bit 3

            typedef enum
         {
                GPS_PRESCRIBED_DWELL_START_NOW           = 0x00, // Start now
                GPS_PRESCRIBED_DWELL_USE_TOA              = 0x0A  // Use TOA
            } gps_prescribed_dwell_start_time_enum_type; //Bit[5:4]

            typedef enum
            {
                GPS_PRESCRIBED_DWELL_USE_RF              = 0x00, // Use RF
                GPS_PRESCRIBED_DWELL_USE_TS               = 0x40  // Use TS
            } gps_prescribed_dwell_source_enum_type; //Bit 6

            typedef enum
            {
                GPS_PRESCRIBED_DWELL_NO_INIT             = 0x00, // Do not initialize TS and BC at starte of dwell
                GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC       = 0x80  // Initialize TS and BC at start of dwell
            } gps_prescribed_dwell_source_init_type; //Bit 7
      \endcode
   \param iTOA              = input, Time of Applicability. GPS_RTC time at which dwell must start.
   \param iSV               = input, Satellite PRN [0..32]. If zero, correlation is codeless.
   \param iSearchMode       = input, Pre-Detection Mode.
   \param iPOST_DET_N       = input, Number of Post-Detection.
   \param iTASK_MASK1       = input, Bit31:Bit0 - Task32:Task1. A set bit implies that that task must be selected.
   \param iTASK_MASK2       = input, Bit7:Bit0 - Task40:Task33. A set bit implies that that task must be selected.
   \param iDOPP_FREQ        = input, Signed (1000/65536 Hz/Bit). Range: -32768000 to +32768000 Hz.
   \param iDOPP_FREQ_RATE   = input, Signed (1000/65536 Hz/sec/Bit). Range: -32768000 to +32768000 Hz/sec.
   \param iSUB_MS           = input, Unsigned (1/256 Chips/Bit). Range: 0 to 1023 chips.
   \param iCNO_Threshold    = input, Used for declaring dwell as a detection. Dwell result DM packet.
                       will be send only if CNo exceeds this threshold. Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.
   \param iJammerThreshold  = input, Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.

   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL_WithWait(
      HANDLE hResourceContext,
      unsigned short iFlags,
      unsigned long iTOA,
      unsigned char iSV,
      unsigned char iSearchMode,
      unsigned short iPOST_DET_N,
      unsigned long iTASK_MASK1,
      unsigned char iTASK_MASK2,
      unsigned long iDOPP_FREQ,
      unsigned long iDOPP_FREQ_RATE,
      unsigned long iSUB_MS,
      unsigned short iCNO_Threshold,
      unsigned short iJammerThreshold,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to perform one dwell on one channel.
   It first enables the log code mask _EVENT_GPS_LM_PD_COMPLETE, enables event control,
   clears event queue/log queue, and existing status for CGPS_Dwell_Complete, then starts a prescribed dwell.

   Use QLIB_DIAG_GPS_PRESCRIBED_DWELL_CHECK_STATUS  to check completion.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlags          = input, Enables different functionalities
                     Refer to these enumerations for bit mask definitions:
     \code
        typedef enum
        {
          GPS_PRESCRIBED_DWELL_NO_RESULTS           = 0x00, // Do not send dwell results
          GPS_PRESCRIBED_DWELL_SEND_RESULTS         = 0x01  // Send dwell results
        } gps_prescribed_dwell_results_enum_type;   //Bit 0

        typedef enum
        {
          GPS_PRESCRIBED_DWELL_CHIPX1               = 0x00, // Chipx1
          GPS_PRESCRIBED_DWELL_CHIPX2               = 0x02  // Chipx2
        } gps_prescribed_dwell_chip_rate_enum_type; //Bit 1

        typedef enum
        {
           GPS_PRESCRIBED_DWELL_NO_INCOHER_SUMS    = 0x00, // Do not report incoherent sums
           GPS_PRESCRIBED_DWELL_REPORT_INCOHER_SUMS = 0x04  // Report incoherent sums
        } gps_prescribed_dwell_incoher_sums_enum_type; //Bit 2

        typedef enum
        {
           GPS_PRESCRIBED_DWELL_NO_COHER_SUMS      = 0x00, // Do not report coherent sums
           GPS_PRESCRIBED_DWELL_REPORT_COHER_SUMS   = 0x08  // Report coherent sums
        } gps_prescribed_dwell_coher_sums_enum_type; //Bit 3

        typedef enum
        {
           GPS_PRESCRIBED_DWELL_START_NOW          = 0x00, // Start now
           GPS_PRESCRIBED_DWELL_USE_TOA             = 0x0A  // Use TOA
        } gps_prescribed_dwell_start_time_enum_type; //Bit[5:4]

        typedef enum
        {
           GPS_PRESCRIBED_DWELL_USE_RF             = 0x00, // Use RF
           GPS_PRESCRIBED_DWELL_USE_TS              = 0x40  // Use TS
        } gps_prescribed_dwell_source_enum_type; //Bit 6

        typedef enum
        {
           GPS_PRESCRIBED_DWELL_NO_INIT            = 0x00, // Do not initialize TS and BC at starte of dwell
           GPS_PRESCRIBED_DWELL_INIT_TS_AND_BC      = 0x80  // Initialize TS and BC at start of dwell
        } gps_prescribed_dwell_source_init_type; //Bit 7
     \endcode
   \param iTOA            = input, Time of Applicability. GPS_RTC time at which dwell must start.
   \param iSV             = input, Satellite PRN [0..32]. If zero, correlation is codeless.
   \param iSearchMode     = input, Pre-Detection Mode.
   \param iPOST_DET_N     = input, Number of Post-Detection.
   \param iTASK_MASK1     = input, Bit31:Bit0 - Task32:Task1. A set bit implies that that task must be selected.
   \param iTASK_MASK2     = input, Bit7:Bit0 - Task40:Task33. A set bit implies that that task must be selected.
   \param iDOPP_FREQ      = input, Signed (1000/65536 Hz/Bit). Range: -32768000 to +32768000 Hz.
   \param iDOPP_FREQ_RATE  = input, Signed (1000/65536 Hz/sec/Bit). Range: -32768000 to +32768000 Hz/sec.
   \param iSUB_MS         = input, Unsigned (1/256 Chips/Bit). Range: 0 to 1023 chips.
   \param iCNO_Threshold   = input, Used for declaring dwell as a detection. Dwell result DM packet.
                     will be send only if CNo exceeds this threshold. Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.
   \param iJammerThreshold = input, Unsigned (0.1 dB/bit). Range: 0 to 6553.5dB.

   \param piStatus        = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL_START(
      HANDLE hResourceContext,
      unsigned short iFlags,
      unsigned long iTOA,
      unsigned char iSV,
      unsigned char iSearchMode,
      unsigned short iPOST_DET_N,
      unsigned long iTASK_MASK1,
      unsigned char iTASK_MASK2,
      unsigned long iDOPP_FREQ,
      unsigned long iDOPP_FREQ_RATE,
      unsigned long iSUB_MS,
      unsigned short iCNO_Threshold,
      unsigned short iJammerThreshold,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
      This function checks to see if an CGPS_Dwell_Complete event has been received.

      \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
      \param iOverrideTimeout_ms        = new timeout value to override the one configured using ConfigureTimeout().
                              if iOverrideTimeout_ms < 0 or unspecified, use general timeout from ConfigureTimeout.
                              if iOverrideTimeout_ms ==0, return immediately.
                              if iOverrideTimeout_ms>0, it will override the one from ConfigureTimeout().

      \return true if successful, false if fail.

      ******************************************************************************/


   QLIB_API unsigned char QLIB_DIAG_GPS_PRESCRIBED_DWELL_CHECK_STATUS(
      HANDLE hResourceContext,
      long iOverrideTimeout_ms
   );



   /******************************************************************************/
   /**
   This function instructs the CGPS engine to start an IQ collect at a given point along
   the GPS and AFLT signal paths, and performs FFT if requested. Raw IQ values and/or
   FFT powers are output in MGP DM log packets.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param pGPS_StartIQ_TestParams       = structure of type gps_start_iq_test_struct_type, which contains
                                all input parameters.

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning This funciton does not collect the results using in the log message.  To do
            so, use QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_START_IQ_TEST(
      HANDLE hResourceContext,
      void* pGPS_StartIQ_TestParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to start an IQ collect at a given point along
   the GPS and AFLT signal paths, and performs FFT if requested. Raw IQ values and/or
   FFT powers are output in MGP DM log packets.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param pGPS_StartIQ_TestParams       = structure of type gps_start_iq_test_struct_type, which contains
                                all input parameters.

   \param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_START_IQ_TEST_CollectResults(
      HANDLE hResourceContext,
      void* pGPS_StartIQ_TestParams,
      char* sIQ_FileName,
      char* sFFT_FileName,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function instructs the CGPS engine to start a 60 second IQ test.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param pGPS_StartIQ_TestParams       = structure of type gps_start_iq_test_struct_type, which contains
                                all input parameters.

   \param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   ******************************************************************************/

   QLIB_API unsigned char QLIB_DIAG_GPS_START_IQ_TEST_60sec(
      HANDLE hResourceContext,
      void* pGPS_StartIQ_TestParams,
      char* sIQ_FileName,
      char* sFFT_FileName,
      unsigned char* piStatus
   );



   /******************************************************************************/
   /**

   This function checks to see if an CGPS_IQ_Test_Complete event has been received.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().

   \return true if successful, false if fail.

   ******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_Check_IQ_TEST_Status( HANDLE hResourceContext );

   /******************************************************************************/
   /**

   This function closes IQ test related files if they have been opened.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().

   ******************************************************************************/
   QLIB_API void QLIB_DIAG_GPS_Close_IQ_TEST_Files( HANDLE hResourceContext );


   /******************************************************************************/
   /**
      Returns the IQ data for the last IQ Capture. This is the data reported by the mobile,
      via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \param pI_Samples = INPUT, pointer to buffer to store I samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pQ_Samples = INPUT, pointer to buffer to store Q samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pNumSamples = OUTPUT, returns the number of samples that were written into the pI_Samples and pQ_Samples arrays.

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of IQ samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_GetIQ_Data(
      HANDLE hResourceContext,
      char* pI_Samples,
      char* pQ_Samples,
      unsigned long* pNumSamples
   );


   /******************************************************************************/
   /**
      Returns the processed IQ data for the last IQ Capture. The processing includes adding 0.5
      to the I and Q samples and replacing each 2046th and each 20487h sample with 0.

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \param hResourceContext = INPUT, pointer to buffer to store processed I samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pQ_ProcessedSamples = INPUT, pointer to buffer to store processed Q samples, the size of the array should be size CGPS_MAX_IQ_SAMPLES_PER_CAPTURE
      \param pNumProcessedSamples = OUTPUT, returns the number of processed samples that were written into the pI_ProcessedSamples and pQ_ProcessedSamples arrays.

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of IQ samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_GetProcessedIQ_Data(
      HANDLE hResourceContext,
      double* pI_ProcessedSamples,
      double* pQ_ProcessedSamples,
      unsigned long* pNumProcessedSamples
   );


   /******************************************************************************/
   /**
      Returns the FFT Measured data from the last IQ Capture.  Measured means that this is
      the data reported by the mobile, via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \param pFFT_Samples = INPUT, pointer to buffer to store FFT samples, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
      \param pNumSamples = OUTPUT, returns the number of samples that were written into the pFFT_Samples array

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of FFT samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_GetFFT_MeasuredData(
      HANDLE hResourceContext,
      unsigned short* pFFT_Samples,
      unsigned long* pNumSamples
   );

   /******************************************************************************/
   /**
      Calculate FFT based on the IQ data.

      Call QLIB_CGPS_GetFFT_CalculatedData to get the results

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() must be called first.

      \return Returns true if successful, false if fail or number of FFT samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_CalculateFFT_Data( HANDLE hResourceContext );


   /******************************************************************************/
   /**
      Returns the FFT Calculated data from the last IQ Capture.  Measured means that this is
      the data reported by the mobile, via the IQ Data Log, ( CGPS_IQ_DATA_LOG, 0x138A)

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
      \param pFFT_Amplitude = OUTPUT, pointer to buffer to store FFT samples, the size of the array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
      \param pFFT_Frequency = OUTPUT, frequency associated with each element in the pFFT_Amplitude array should be size CGPS_MAX_FFT_SAMPLES_PER_CAPTURE
      \param iNumSamples = OUTPUT, returns the number of samples that were written into the pFFT_Samples array

      \warning QLIB_DIAG_GPS_START_IQ_TEST_CollectResults() and QLIB_CGPS_CalculateFFT_Data() must be called first.

      \return Returns true if successful, false if fail or number of FFT samples = 0

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_GetFFT_CalculatedData(
      HANDLE hResourceContext,
      double* pFFT_Amplitude,
      double* pFFT_Frequency,
      unsigned long* iNumSamples
   );

   /******************************************************************************/
   /**
         Clear the IQ data for the last IQ Capture to release memory.

         \param hResourceContext = Resource context that was returned from the call to ConnectServer().
         \warning QLIB_CGPS_GetIQ_Data
               /QLIB_CGPS_GetProcessedIQ_Data
               /QLIB_CGPS_GetFFT_MeasuredData
               QLIB_CGPS_CalculateFFT_Data cannot be called after this function as the memory is cleared.

         \return Returns true if successful, false if fail or number of IQ samples = 0

      *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_ClearIQ_Data(
      HANDLE hResourceContext   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to track the specified SV or all the SVs depending on the input command. The test can be stopped
   using appropriate command parameters (see below).

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param iSV                           = input.    Satellite PRN [0:32]. If zero (GPS_SV_TRACK_ALL), operation is track all SVs.
   \param iCommand                      = input.    defined by gps_sv_track_command_enum_type:
      \code
           GPS_SV_TRACK_START_CLEAR_ALL = 0
           GPS_SV_TRACK_START_NO_CLEAR  = 1
           GPS_SV_TRACK_STOP_CLEAR_ALL  = 2
           GPS_SV_TRACK_STOP_NO_CLEAR   = 3
           GPS_SV_TRACK_START_CLEAR_ALL_NO_BITEDGE_DETECTION = 5
           GPS_SV_TRACK_START_NO_CLEAR_NO_BITEDGE_DETECTION = 6

        \endcode

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_SV_TRACK(
      HANDLE hResourceContext,
      unsigned char iSV,
      unsigned char iCommand,
      unsigned char* piStatus
   );



   /******************************************************************************/
   /**

   This function instructs the CGPS GEN8 engine to track GNSS SV's as specified
   by SvTrackParams input parameters. The test can also be stopped using appropriate
      command parameters.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param SvTrackParams = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to CGPS_Gen8_SvTrack_Struct_type in QLib_Defines.h
      \endcode

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_SV_TRACK(
      HANDLE hResourceContext,
      void *SvTrackParams,
      unsigned char* piStatus
   );


   /******************************************************************************/
   /*

   This function instructs the CGPS GEN8 engine to track GNSS SV's as specified
   by SvTrackParams input parameters. The test can also be stopped using appropriate
      command parameters.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param SvTrackParams     = input. A structure containing Multi-Channel Tracking Test parameters.  Please refer to CGPS_Gen8_SvTrack_Struct_type in QLib_Defines.h
      \endcode

   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8B_SV_TRACK(
      HANDLE hResourceContext,
      void *SvTrackParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function sends the CGPS GEN8 engine HW Configure command to the phone.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param HwConfigParams    = input. A structure containing HW Configure command parameters.  Please refer to CGPS_Gen8_HwConfig_Struct_type in QLib_Defins.h
      \endcode

   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_HW_CONFIG(
      HANDLE hResourceContext,
      void* HwConfigParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function sends the CGPS GEN8 engine PRx RF Mode DM command to the phone.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param PRx_Mode  = input. A CGPS_Gen8_Rx_RfMode_Struct_type structure containing PRx RF Mode command parameters.  Please refer to
   CGPS_Gen8_Rx_RfMode_Struct_type in QLib_Defines.h

   \endcode

      \return true if successful, false if fail.

      \warning

      *******************************************************************************/

   QLIB_API unsigned char QLIB_GPS_GEN8_PRx_Mode_Config (
      HANDLE hResourceContext,
      void *PRx_Mode
   );

   /******************************************************************************/
   /**

   This function sends the CGPS GEN8 engine RF Linearity Config DM command to the phone.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param DRx_On_Off_Config = input. A CGPS_Gen8_Rf_Linearity_Config_Struct_type structure containing RF Linearity Config command parameters .
   \endcode

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GPS_GEN8_RF_Linearity_Config(
      HANDLE hResourceContext,
      void *RF_Linearity_Config
   );

   /******************************************************************************/
   /*

   This function sends the CGPS GEN8 engine GPS Engine Query RF Dev Capability DM Command Config DM command to the phone.

   This command will check the status field and return false if the command was rejected.
   \param EngineRev = output, GNSS Engine Revision.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_GPS_GEN8_Get_GNSS_Engine_Revision( HANDLE hResourceContext,  long& EngineRevision );


   /******************************************************************************/
   /**

   This function Initilizes a specific GPS PDAPI client.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_INITIALIZE(
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function registers or deregisters GPS PD related callbacks and events.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_REGISTER_PD(
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function activates a specific PDAPI client, so that it will be notified of Session Manager
   events for which it is registered.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_ACTIVATE (
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function deactivates a particular PDAPI client, so that it will not be notified of
   Session Manager events for which it is registered.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_DEACTIVATE (
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function releases a specific PDAPI client when it no longer needs the Session Manager.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_RELEASE(
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function requests the target to start a CGPS session with the specified parameters.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_START(
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function requests the target to end an ongoing CGPS session with the specified parameters.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_END(
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**

   This function requests the target to set configuration parameters in either the NV or
   Session Manager.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param FixCollectionParams   = input. A structure containing GPS PD Configuration parameters .

   \param iStatus           = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_PDAPI_SET_PARAM(
      HANDLE hResourceContext,
      void* FixCollectionParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS GEN 8 engine to start an IQ collect, performs FFT
   if requested. Raw IQ values and/or FFT powers are output in MGP DM log packets.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param pGPS_StartIQ_TestParams       = structure of type CGPS_Gen8_StartIqTest_struct_type, which contains
                                all input parameters.

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning This funciton does not collect the results using in the log message.  To do
            so, use QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_START_IQ_TEST(
      HANDLE hResourceContext,
      void* pGPS_StartIQ_TestParams,
      unsigned char* piStatus);

   /******************************************************************************/
   /**
   This function instructs the CGPS Gen 8 engine to start an IQ collect and performs
   FFT if requested. Raw IQ values and/or FFT powers are output in MGP DM log packets.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param pGPS_StartIQ_TestParams       = structure of type CGPS_Gen8_StartIqTest_struct_type, which contains
                                all input parameters.   Supportted collect modes include:

                                 1  WBIQ LBW-GPS (2.046 MHz sample rate)
                                 3  WBIQ GLO     (1.022 MHz sample rate)
                                 4  FBIQ HBW-GPS (20.46 MHz sample rate)

   \param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_START_IQ_TEST_CollectResults(
      HANDLE hResourceContext,
      void* pGPS_StartIQ_TestParams,
      char* sIQ_FileName,
      char* sFFT_FileName,
      unsigned char* piStatus);


   /******************************************************************************/
   /**
   This function queries RF Blanking Status.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext     = Resource context that was returned from the call to ConnectServer().
   \param BlankingStatus       = Structure of type GNSS_BlankingStatus_Response_type to recive the blanking status. 


   \param piStatus             = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   *******************************************************************************/
    QLIB_API unsigned char QLIB_DIAG_GNSS_QueryBlankingStatus( HANDLE hResourceContext, 
                                                               unsigned char& Enabled,
                                                               unsigned long& Rx1Counter,
                                                               unsigned long& Rx2Counter );


   /******************************************************************************/
   /**

   This function instructs the CGPS engine to start a 60 second IQ test.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext              = Resource context that was returned from the call to ConnectServer().
   \param pGPS_StartIQ_TestParams       = structure of type CGPS_Gen8_StartIqTest_struct_type, which contains
                                all input parameters.

   \param sIQ_FileName                  = File name to store IQ data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param sFFT_FileName             = File name to store FFT data.  File format is compatible with Qualcomm CGPS MatLab files.
                                If NULL or empty string, then no data will be stored to file.

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   ******************************************************************************/

   QLIB_API unsigned char QLIB_DIAG_GPS_Gen8_START_IQ_TEST_60sec(
      HANDLE hResourceContext,
      void* pGPS_StartIQ_TestParams,
      char* sIQ_FileName,
      char* sFFT_FileName,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to perform one dwell on one channel.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param PrescribedDwellParams= Pointer to a structure containing the Prescribed Dwell command paramters.
   Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h


   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning This version of the function does not wait for the response event. To wait for
            the event use QLIB_DIAG_GPS_PRESCRIBED_DWELL_WithWait

   *******************************************************************************/

   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_PRESCRIBED_DWELL(
      HANDLE hResourceContext,
      void * PrescribedDwellParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to perform one dwell on one channel, then
   wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

   The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
   timeout type of QMSL_Timeout_CGPS_Event.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param PrescribedDwellParams = input, A structure containing the prescrbed dwell
                                 command parameters.  Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h

   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8_PRESCRIBED_DWELL_WithWait(
      HANDLE hResourceContext,
      void * PrescribedDwellParams,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
   This function instructs the CGPS engine to perform one dwell on one channel, then
   wait for the corresponding event, EVENT_GPS_LM_PD_COMPLETE, #1250.

   The timeout value for waiting for the event can be set using QLIB_ConfigureTimeOut() and the
   timeout type of QMSL_Timeout_CGPS_Event.

   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param PrescribedDwellParams = input, A structure containing the prescrbed dwell
                                 command parameters.  Please refer to CGPS_Gen8_PrescribedDwell_struct_type in QLib_Defines.h

   \param piStatus          = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning The asynchronous message queue will be cleared in the course of executing this function
   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_GEN8B_PRESCRIBED_DWELL_WithWait(
      HANDLE hResourceContext,
      void * PrescribedDwellParams,
      unsigned char* piStatus
   );


   /******************************************************************************/
   /**
      Clear the status of the entire CGPS status object
      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().

      \return Returns true if successful, false if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_ClearStatus( HANDLE hResourceContext );

   /******************************************************************************/
   /**
      Clear a specific status element of the CGPS status

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
      \param eStat = the type of status to clear, type is QMSL_CGPS_Event_Enum from QLibDefines.h
      \return Returns true if successful, false if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_ClearStatus_Specific( HANDLE hResourceContext, unsigned long eStat );

   /******************************************************************************/
   /**
      Copy the status into the user supplied GSM BER Status structure

      \param hResourceContext   = Resource context that was returned from the call to ConnectServer().
      \param pCGPS_Status is a structure of type "CGPS_Status_Struct*"

      \return Returns true if successful, false if fail

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_GetStatus( HANDLE hResourceContext, void* pCGPS_Status );

   /******************************************************************************/
   /**
   Starts the async messages (logs and events) associated with CGPS.  These logs are:
   \code
         CGPS_IQ_DATA_LOG = 0x138A
       CGPS_RF_STATUS_REPORT_LOG 0x1372

   \endcode

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param bEnableEvents = true to enable CGPS events, false to disable.  The events that will be enabled are:
   \code
       _EVENT_GPS_PD_COMM_FAILURE      = 1241,
       _EVENT_GPS_PD_COMM_DONE         = 1242,
       _EVENT_GPS_PD_EVENT_END         = 1243,
       _EVENT_GPS_PA_EVENT_CALLBACK    = 1244,
       _EVENT_GPS_PD_CMD_ERR_CALLBACK  = 1245,
       _EVENT_GPS_PA_CMD_ERR_CALLBACK  = 1246,
       _EVENT_GPS_LM_ENTER_SA_RF_VERIF = 1247,
       -EVENT_GPS_LM_EXIT_SA_RF_VERIF  = 1248,
       _EVENT_GPS_LM_ERROR_SA_RF_VERIF = 1249,
       _EVENT_GPS_LM_PD_COMPLETE       = 1250,
       _EVENT_GPS_LM_IQ_TEST_COMPLETE  = 1251,
       _EVENT_GNSS_PRESC_DWELL_COMPLETE = 1717

   \endcode

   \param piStatus                      = output, 0=Command Accepted, 1=Command Rejected.

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_StartCGPS_AsyncMessages(
      HANDLE hResourceContext,
      unsigned char bEnableEvents
   );

   /******************************************************************************/
   /**
   Performs a CW SNR measurment by using other CGPS functions:
      - Optionally activates/deactivates CGPS test mode using QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait()
      - Captures Wideband IQ data using QLIB_DIAG_GPS_START_IQ_TEST()
      - Calculates FFT using QLIB_CGPS_CalculateFFT_Data()
      - Gets the FFT results using QLIB_CGPS_GetFFT_CalculatedData()
      - Peforms a peak search and C/N calculation using the FFT data

   This function is designed to be used for factory testing, for quick verification of the GPS path.
   It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

   The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
   -120dBm and -100dBm.  -110dBm is suggested.

   For troubleshooting, it is possible to enable a text file to log the IQ data in a format that a Matlab script
   will be able to parse.  To use the Matlab script:
   \code
      cgps_IqTest_IqFileProc( 6.0, 100, -120, 'c:\CGPS_SNR_IQ_Capture.txt' )

      For this case,
      RF_NoiseFigure = 6.0dB
      SigFreqKhz = 100kHz
      SigLevelDbm = -120.0dBm
      FileName = �c:\CGPS_SNR_IQ_Capture.txt

   \endcode

   The SNR calculation is exactly as found the CGPS Matlab script named, ""

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
   \param iAutoSetGPS_VerificationMode = input, true to set the GPS Verification mode ON before the capture and OFF after the capture
                                 if true, the CGPS timeout will automatically be set to 15 seconds using the function QLIB_ConfigureTimeOut()
   \param sIQ_FileName = input, file name to store a text file which can be used by the MatLab script, cgps_IqTest_FftFileProc.m
                     if NULL, then no file will be created.
   \param iNumberOfIntegrations = number of integrations (separate embedded IQ captures) to use.  The higher the number of integrations,
                                  the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                           The maximum number of integrations is 10.
   \param pdSNR = output, pointer to storage for the output results


   \return true if successful, false if fail.

   \warning if iAutoSetGPS_VerificationMode==1 then this function will increase the CGPS timeout to 15 seconds:
   \code
       QLIB_ConfigureTimeOut(g_hResourceContext, QMSL_Timeout_CGPS_Event, 15000 )
   \endcode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_CGPS_SNR(
      HANDLE hResourceContext,
      unsigned short iCaptureSize_kSamples,
      unsigned char  iAutoSetGPS_VerificationMode,
      unsigned short iNumberOfIntegrations,
      char* sIQ_FileName,
      double* pdSNR
   );
   /******************************************************************************/
   /**
   Commands the mobile to start a WB I/Q capature and returns C/N calculated by mobile

      - Optionally activates/deactivates CGPS test mode using QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait()
      - Captures Wideband IQ data using QLIB_DIAG_GPS_START_IQ_TEST()
       - Returns the C/N and frequency bin calculated by embedded side

    Note: Please note that C/N or SNR returned is expected to be different from the one returned by QLIB_DIAG_CGPS_SNR.
   It is because the two functions use different alogorithm to compute SNR.

   This function is designed to be used for factory testing, for quick verification of the GPS path.
   It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

   The function requires that embedded side to be able to return C/N via LOG_CGPS_WB_FFT_STATS_C (0x1487).

   The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
   -120dBm and -100dBm.  -110dBm is suggested.

   For more information, please refer to 80-VR679-1 (C/N0 Measurement Method for GPS Testing on Production Line)

   For troubleshooting, it is possible to enable a text file to log the IQ data in a format that a Matlab script
   will be able to parse.  To use the Matlab script:
   \code
      cgps_IqTest_IqFileProc( 6.0, 100, -120, 'c:\CGPS_SNR_IQ_Capture.txt' )

      For this case,
      RF_NoiseFigure = 6.0dB
      SigFreqKhz = 100kHz
      SigLevelDbm = -120.0dBm
      FileName = �c:\CGPS_SNR_IQ_Capture.txt

   \endcode

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
   \param iAutoSetGPS_VerificationMode = input, true to set the GPS Verification mode ON before the capture and OFF after the capture
                                 if true, the CGPS timeout will automatically be set to 15 seconds using the function QLIB_ConfigureTimeOut()
   \param sIQ_FileName = input, file name to store a text file which can be used by the MatLab script, cgps_IqTest_FftFileProc.m
                     if NULL, then no file will be created.
   \param iNumberOfIntegrations = number of integrations (separate embedded IQ captures) to use.  The higher the number of integrations,
                                  the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                           The maximum number of integrations is 10.
   \param pdCNoDBHz = output, pointer to Signal strength calculated in dBHz as part of WBIQ test
   \param piFreqInHz = output, pointer to Frequency in Hz calculated as part of WBIQ test

   \return true if successful, false if fail.

   \warning if iAutoSetGPS_VerificationMode==1 then this function will increase the CGPS timeout to 15 seconds:
   \code
       QLIB_ConfigureTimeOut(g_hResourceContext, QMSL_Timeout_CGPS_Event, 15000 )
   \endcode

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_CGPS_GET_EMBEDDED_CALCULATED_CTON(
      HANDLE hResourceContext,
      unsigned short iCaptureSize_kSamples,
      unsigned char  iAutoSetGPS_VerificationMode,
      unsigned short iNumberOfIntegrations,
      char* sIQ_FileName,
      double* pdCNoDBHz,
      int*    piFreqInHz
   );

   /******************************************************************************/
   /**
    Requests the phone to return the GPS C/No(dB) and frequency offset(Hz) calculated by embedded side.
    For more information, please refer to "DM Command to get C/No for testing GEN8 GPS at Production Line", 80-VU919-1 A.

    This function is designed to be used for factory testing, for quick verification of the GPS path.
    It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

    The function requires that embedded side to be able to return C/No via LOG_CGPS_WB_FFT_STATS_C (0x1487).
    QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE) must be called first, with the RF signal disabled.

    The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
    -120dBm and -100dBm.  -110dBm is suggested.

   To configure the timeout, use QLIB_ConfigureTimeOut(QMSL_Timeout_CGPS_Event, timeout) to configure.

    \param hResourceContext = Resource context that was returned from the call to ConnectServer().
    \param iCollectMode          = input, defines the collect point of I/Q samples, see the definition of gps_start_iq_test_collect_mode_gen8.
    \param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
    \param iNumberOfIntegrations = number of integrations (separate embedded I/Q captures) to use.  The higher the number of integrations,
                                    the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                                   The maximum number of integrations is 10.
    \param pdCNoDBHz = output, pointer to C/No calculated in dB.
    \param piFreqInHz = output, pointer to Frequency offset in Hz.

    \return true if successful, false if fail.
    *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GEN8_GET_EMBEDDED_CALCULATED_CTON(
      HANDLE hResourceContext,
      unsigned char iCollectMode,
      unsigned short iCaptureSize_kSamples,
      unsigned char iNumberOfIntegrations,
      double* pdCNoDBHz,
      int* piFreqInHz
   );


   /******************************************************************************/
   /*
    Requests the phone to return the GPS C/No(dB) and frequency offset(Hz) calculated by embedded side.
    For more information, please refer to "DM Command to get C/No for testing GEN8 GPS at Production Line", 80-VU919-1 A.

    This function is designed to be used for factory testing, for quick verification of the GPS path.
    It replaces functionality that is not longer available in QLIB_FTM_GET_CTON()

    The function requires that embedded side to be able to return C/No via LOG_CGPS_WB_FFT_STATS_C (0x1487).
    QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait(GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE) must be called first, with the RF signal disabled.

    The input signal needs to be a CW that is offset from the center frequency by at least 100kHz and is between
    -120dBm and -100dBm.  -110dBm is suggested.

   To configure the timeout, use QLIB_ConfigureTimeOut(QMSL_Timeout_CGPS_Event, timeout) to configure.

    \param hResourceContext = Resource context that was returned from the call to ConnectServer().
    \param iCollectMode          = input, defines the collect point of I/Q samples, see the definition of gps_start_iq_test_collect_mode_gen8.
    \param iCaptureSize_kSamples = input, capture size in kilo samples. 1 to 32, in powers of 2 (1,2,4,8, etc.)
    \param iNumberOfIntegrations = number of integrations (separate embedded I/Q captures) to use.  The higher the number of integrations,
                                    the more the noise will be reduced by the averaging affect.  The minimum number of integrations is 1.
                           The maximum number of integrations is 10.
   \param GLO_FrequencyID       = The GLONASS SV Frequency ID in the range -7 to +6.
   \param GLO_FrequencyID       = The GLONASS Hardware Channel to be used, in the range 1 to 12.
    \param pdCNoDBHz = output, pointer to C/No calculated in dB.
    \param piFreqInHz = output, pointer to Frequency offset in Hz.

    \return true if successful, false if fail.
    *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GNSS_GET_EMBEDDED_CALCULATED_CTON(
      HANDLE hResourceContext,
      unsigned char iCollectMode,
      unsigned short iCaptureSize_kSamples,
      unsigned char iNumberOfIntegrations,
      char GLO_FrequencyID,
      unsigned char GLO_HW_Channel,
      double* pdCNoDBHz,
      int* piFreqInHz
   );

   /******************************************************************************/
   /**
   Execute binary form of the MATLAB script that is used for CGPS IQ processing.

   The MATLAB script name is: CGPS_IqTest_IqFileProc.m
   The compiled binary form of the MATLAB script is: CGPS_IqTest_IqFileProc.exe
   The "Component Technology File" is: CGPS_IqTest_IqFileProc.ctf

   Both the .EXE and .CTF must be in the same folder as the QMSL client executable file or
   those two files must be in the system path.

   The purpose of this function is to simplify the process for a C program to call the .EXE file.
   It is always possible to bypass this function and call the .EXE directly in your C program.

   This process will run in a blocking fashion, meaning that the function will not return until
   all of the MATLAB processing has been completed.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param dRF_NoiseFigure_dB = input, expected noise figure, dB
   \param dSigFreq_kHz = input, CW offset from center frequency, kHz
   \param dSigLevel_dBm = input, CW power level at the mobile input, dBm
   \param sIQ_FileName = input, file name of text file that holds IQ data/.
                     This is the same file passed as the sIQ_FileName paremter to
                     QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()
   \param sOutputFolder = folder where MATLAB output files should be stored
   \param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
                  If set to TRUE then the MATLAB graph windows will not be shown.
   \param sStandardOutputFile = file name to store standard output into. If NULL then standard output will not be stored
   \param bWaitForCompletion = wait for the child process to complete before returning from this function
   \param iPhoneState = call state. 0 = OoS, 1 = WCDMA in-service OR GSM Idle, 2 = GSM Traffic, 3 = 1x
   \param sStdFolder = path name to store standard output into for Matlab. If NULL then standard output will not be stored


   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_MATLAB_IQ_FILE_PROC(
      HANDLE hResourceContext,
      double dRF_NoiseFigure_dB,
      double dSigFreq_kHz,
      double dSigLevel_dBm,
      char* sIQ_FileName,
      char* sOutputFolder,
      unsigned char bAutoClose,
      char* sStandardOutputFile,
      unsigned char bWaitForCompletion,
      unsigned char iPhoneState,
      const char* sStdFolder
   );

   /******************************************************************************/
   /**
   Execute binary form of the MATLAB script that is used for CGPS IQ processing.

   The MATLAB binary is invoved using a COM object which requires a QMSL DLL to be
   registered using regsvr32

   File: QMSL_MATLAB_Interface.DLL
   uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
   interface name = QMSL_MATLAB Interface


   The MATLAB script name is: CGPS_IqTest_IqFileProc.m
   The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
   The "Component Technology File" is: QMSL_Matlab_Generic.ctf

   Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
   those two files must be in the system path.

   This process will run in a blocking fashion, meaning that the function will not return until
   all of the MATLAB processing has been completed.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
   \param dRF_NoiseFigure_dB = input, expected noise figure, dB
   \param dSigFreq_kHz = input, CW offset from center frequency, kHz
   \param dSigLevel_dBm = input, CW power level at the mobile input, dBm
   \param sIQ_FileName = input, file name of text file that holds IQ data/.
                     This is the same file passed as the sIQ_FileName paremter to
                     QLIB_DIAG_GPS_START_IQ_TEST_CollectResults()
   \param sOutputFolder = folder where MATLAB output files should be stored
   \param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
                  WARNING: if autoclose is set to false, it is possible to receive MATLAB exception
                  after the file processing is completed. The only supported setting is for bAutoClose = true
                  If set to TRUE then the MATLAB graph windows will not be shown.

   \param iPhoneState = call state. 0 = OoS, 1 = WCDMA in-service OR GSM Idle, 2 = GSM Traffic, 3 = 1x
   \param sStdFolder = path name to store standard output into for COM interface and Matlab. If NULL then standard output will not be stored


   \return true if successful, false if fail.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_CGPS_MATLAB_IQ_FILE_PROC_COM(
      HANDLE hResourceContext,
      double dRF_NoiseFigure_dB,
      double dSigFreq_kHz,
      double dSigLevel_dBm,
      char* sIQ_FileName,
      char* sOutputFolder,
      unsigned char bAutoClose,
      unsigned char iPhoneState,
      const char* sStdFolder
   );

   /******************************************************************************/
   /**
   Execute binary form of the MATLAB script that is used for GNSS Gen8 (Callisto) IQ processing.

   The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
   The compiled binary form of the MATLAB script is: gnss_IqTest_IqFileProc.dll
   The "Component Technology File" is: gnss_IqTest_IqFileProc.ctf
   The MATLAB binary is invoked using a COM object which requires a QMSL DLL to be
   registered using regsvr32

   File: QMSL_MATLAB_Interface.DLL
   uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
   interface name = QMSL_MATLAB Interface

   The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
   The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
   The "Component Technology File" is: QMSL_Matlab_Generic.ctf

   Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
   those two files must be in the system path.

   This process will run in a blocking fashion, meaning that the function will not return until
   all of the MATLAB processing has been completed.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
    \param iPhoneState = phone state.
        iPhoneState = 100*gnssSig + 10*nwType + nwCond
        gnssSig:(1) GPS / (2) GLO
        nwType: (1) 1X / (2) WCDMA / (3) GSM / (4) Unconnected
        nwCond: (1) OoS/UnConnected
                (2) Idle
                (3) Traffic
        Note: Multimode OoS should be tested with nwType = 2 or 3.
   \param dSigFreq_kHz = input, CW offset from center frequency, kHz
   \param dSigLevel_dBm = input, CW power level at the mobile input, dBm
   \param sIQ_FileName = input, file name of a .bin file that holds IQ data/.
   \param sOutputFolder = folder where MATLAB output files should be stored
   \param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
                  WARNING: if autoclose is set to false, it is possible to receive MATLAB exception
                  after the file processing is completed. The only supported setting is for bAutoClose = true
                  If set to TRUE then the MATLAB graph windows will not be shown.
   \param sStdFolder = path name to store standard output into for COM interface and Matlab. If NULL then standard output will not be stored
   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_MATLAB_IQ_FILE_PROC_COM(
      HANDLE hResourceContext,
      unsigned long iPhoneState,
      double dSigFreq_kHz,
      double dSigLevel_dBm,
      char* sIQ_FileName,
      char* sOutputFolder,
      unsigned char bAutoClose,
      const char* sStdFolder
   );
   /******************************************************************************/
   /**
   Execute binary form of the MATLAB script that is used for GNSS Gen8 (Callisto) IQ processing.

   The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
   The compiled binary form of the MATLAB script is: gnss_IqTest_IqFileProc.dll
   The "Component Technology File" is: gnss_IqTest_IqFileProc.ctf
   The MATLAB binary is invoked using a COM object which requires a QMSL DLL to be
   registered using regsvr32

   File: QMSL_MATLAB_Interface.DLL
   uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
   interface name = QMSL_MATLAB Interface

   The MATLAB script names are: gnss_IqTest_IqFileProc.m, gnss_IqTest_JammerProc.m
   The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
   The "Component Technology File" is: QMSL_Matlab_Generic.ctf

   Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
   those two files must be in the system path.

   This process will run in a blocking fashion, meaning that the function will not return until
   all of the MATLAB processing has been completed.

   \param hResourceContext  = Resource context that was returned from the call to ConnectServer().
    \param iPhoneState = phone state.
        iPhoneState = 100*gnssSig + 10*nwType + nwCond
        gnssSig:(1) GPS / (2) GLO
        nwType: (1) 1X / (2) WCDMA / (3) GSM / (4) Unconnected
        nwCond: (1) OoS/UnConnected
                (2) Idle
                (3) Traffic
        Note: Multimode OoS should be tested with nwType = 2 or 3.
   \param dSigFreq_kHz = input, CW offset from center frequency, kHz
   \param dSigLevel_dBm = input, CW power level at the mobile input, dBm
   \param sIQ_FileName = input, file name of a .bin file that holds IQ data/.
   \param sOutputFolder = folder where MATLAB output files should be stored
   \param bAutoClose = TRUE to close the MATLAB graph windows, FALSE to keep them open
                  WARNING: if autoclose is set to false, it is possible to receive MATLAB exception
                  after the file processing is completed. The only supported setting is for bAutoClose = true
                  If set to TRUE then the MATLAB graph windows will not be shown.
   \param sStdFolder = path name to store standard output into for COM interface and Matlab. If NULL then standard output will not be stored
   \param sEngine = GNSS Engine - "Gen 8" or "Gen8A"
   \param sAgcType = AGC Type - "HW" or "SW"
   \return true if successful, false if fail.
   *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_8A_MATLAB_IQ_FILE_PROC_COM(
      HANDLE hResourceContext,
      unsigned long iPhoneState,
      double dSigFreq_kHz,
      double dSigLevel_dBm,
      char* sIQ_FileName,
      char* sOutputFolder,
      unsigned char bAutoClose,
      const char* sStdFolder,
      const char* Engine,
      const char* AgcType
   );

   /******************************************************************************/
   /**
   Execute binary form of the MATLAB script that is used to plot a figure.

   The MATLAB binary is invoved using a COM object which requires a QMSL DLL to be
   registered using regsvr32

   File: QMSL_MATLAB_Interface.DLL
   uuid = 7EEA2D69-0CAE-40B8-B3A1-9D31F65FE46B
   interface name = QMSL_MATLAB Interface

   The MATLAB script name is: qmsl_matlab_plot.m, print_to_error.m, and remove_special_string.m
   The compiled binary form of the MATLAB script is: QMSL_Matlab_Generic.dll
   The "Component Technology File" is: QMSL_Matlab_Generic.ctf
   Both the .DLL and .CTF must be in the same folder as the QMSL client executable file or
   those two files must be in the system path.

   This process will run in a blocking fashion, meaning that the function will not return until
   all of the MATLAB processing has been completed.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer().
   \param sFileName = input, name of file containing the data to plot. must follow the required format. see below note.
   \param sOutputPath = path (inc. file name) where MATLAB output files should be stored
   \param sStdFolder = path name to store standard output into. If NULL then standard output will not be stored
   \param bBackGround = TRUE, the MATLAB graph windows will not be shown.
   \return true if successful, false if fail.

   \IMPORTANT: Input file must follow format below:
   line 1: figure title = string.
   line 2: figure x-label = string.
   line 3: figure y-label = string.
   line 4: figure legend = string. If you have multiple lines to plot   in same figure,
             use legend to give each line a name. Use";" to delim them.
   line 5: user defined text to display to figure.
   line 6: figure style, default is "plot" options include "plot" and "bar" (must be lower case)
   line 7 - 10: reserved. user data file should fill with emtpy lines for future backward compatibility.
   begin of data: use a line starting with ***
   data format per line:x(1) [] y(1)\n. Note [] represents for space. you must make
   sure there are no extra spaces except the one separate x and y coordinates.
   If you have multiple lines to plot in figure, please use another *** to start another data
   section, immediately in the line following last data section.

   An Example of input file:
      line1: BP amplitude vs time.                                          //title.
      line2: Time in seconds                                                //x-label and unit
      line3: BP Amp [dB]                                                //y-label and unit
      line4: BP Amp I data;BP Amp Q data                                    //legend: totally two lines.
      line5: Technology=CDMA, band=CDMA 800,channel=18                  //user defined text, optional
      line6: plot                                                       //optional, use lower case "plot" or "bar" (without quote)
      line 7- 10: empty.                                                    //reserved
      line11: ***                                                       //indicator of starting of data section
      line12: 0.000 53.000
      line13: 2.094 58.500
      ......
             4.187 58.000
      line#: ***                                                        //inication of another data section begin
            10.469 58.500
            12.562 59.500

   *******************************************************************************/

   QLIB_API unsigned char QLIB_MATLAB_GENERIC_PLOT_COM(
      HANDLE hResourceContext,
      char* sFileName,
      char* sOutputPath,
      char* sStdFolder,
      unsigned char bBackGround
   );

   /******************************************************************************/
   /**
   Factory Test Mode, GNSS FTM RF Mode ID 34, Subcommand 253 - External LNA

   FTM ICD DCN: TBD

   Enable/disable external LNA

   \param hResourceContext = Resource context that was returned from the call to QLIB_ConnectServer()
   \param iEnable = 0= diable, 1 = enable

   \return true if successful, false if fail.

   \warning

   *******************************************************************************/

   QLIB_API unsigned char QLIB_FTM_GNSS_EXTERNAL_LNA(HANDLE hResourceContext, unsigned char iEnable);


  /******************************************************************************/

   /**
   This function instructs the CGPS engine to enter "Standalone RF verification" mode.


   This command will check the status field and return false if the command was rejected.

   \param hResourceContext = Resource context that was returned from the call to ConnectServer()
   \param iFlag = input
   \code
        0 = GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE = Enter SA-RF Verif Mode,
      1 = GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE  = Exit SA-RF Verif Mode
         Refer to the enumeration below for bit mask definitions:

            typedef enum
            {
               GPS_SA_RF_VERIF_MODE_SWITCH_ENTER_MODE         = 0x00, // Enter Standalone RF verification mode
               GPS_SA_RF_VERIF_MODE_SWITCH_EXIT_MODE          = 0x01  // Exit Standalone RF verification mode
            } gps_sa_rf_verif_mode_switch_enum_type;
   \endcode

   \param piStatus = output, 0=Command Accepted, 1=Command Rejected

   \return true if successful, false if fail.

   \warning This version of the function does not wait for the associated event.
            Use QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH_WithWait() to wait for the event.

   *******************************************************************************/
   QLIB_API unsigned char QLIB_DIAG_GPS_SA_RF_VERIF_MODE_SWITCH(
      HANDLE hResourceContext,
      unsigned char iFlag,
      unsigned char* piStatus
   );

   /******************************************************************************/
   /**
    This function configures the onboard Spectrum Analysis 
     
    \param SCAN_MODE              = 0 - Single Shot, 1 - Continuos
    \param SCAN_START_STOP        = 1 - start scan, 0 - stop scan, 2 - stop and restart scan 
    \param GPS_SCAN_TYPES_ENABLED = Bit Mask for GPS Scan types: 
                                    Bit 0 = Fast Scan, Bit 1 = Deep Scan 
    \param GLO_SCAN_TYPES_ENABLED = Bit Mask for GLONASS Scan Types: 
                                    Bit 0 = Fast Scan, Bit 1 = Deep Scan
    \param PROBE_POINT_FOR_SCAN   = Bit Mask for probe point to be used in collecting 
                                    spectrum analysis samples:
                                    Bit 0-3 to 1 for Probe points P1-P4
    \param TRACKING_MODE_CONTROL  = 0 - Disable tracking mode for jammers 
                                    1 - Enable tracking mode for jammers
    \param RESET_NOTCH_FILTERS    = Option to reset all the Notch filters currently
                                    assigned. When issued with a start option, this
                                    resets notch filters prior to Start. When issued
                                    with a stop option, this resets notch filters
                                    after stopping the scan.
                                    1 - Reset notch filters
                                    0 - Do not reset notch filters

    \return true if successful, false if fail.


    *******************************************************************************/
   QLIB_API unsigned char QLIB_GNSS_SpecAn_Control( HANDLE hResourceContext, 
                                               unsigned char SCAN_MODE,
                                               unsigned char SCAN_START_STOP,        
                                               unsigned char GPS_SCAN_TYPES_ENABLED, 
                                               unsigned char GLO_SCAN_TYPES_ENABLED, 
                                               unsigned char PROBE_POINT_FOR_SCAN,   
                                               unsigned char TRACKING_MODE_CONTROL,  
                                               unsigned char RESET_NOTCH_FILTERS   
                                              );

    #ifdef __cplusplus
}   // extern "C"
#endif

#endif  // defined(_QMSL_CGPS_GNSS_H)
