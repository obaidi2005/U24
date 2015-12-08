#ifndef _RF_ERRORDEFINE_H
#define _RF_ERRORDEFINE_H

//////////////////////////////////////////////////////////////////////////
//   QLib Phone Command Phone Error Code
//////////////////////////////////////////////////////////////////////////

#define ERR_QLIB_PHONE_CONNECT                          "Qlib_Connect_Phone_Fail"//QLIB_ConnectServerWithWait
#define ERR_QLIB_SET_FTM                                "Qlib_Set_FTM_Fail"//QLIB_DIAG_CONTROL_F
#define ERR_QLIB_SET_ONLINE                             "Qlib_Set_Online_Fail"//QLIB_DIAG_CONTROL_F
#define ERR_QLIB_SET_OFFLINE                            "Qlib_Phone_Offline_Fail"//QLIB_DIAG_CONTROL_F
#define ERR_QLIB_IsPhoneConnected                       "Qlib_IsPhoneConnected_Fail"
#define ERR_QLIB_SET_PHONE_BAND                         "Qlib_Set_Phone_Band_Fail"//QLIB_FTM_SET_MODE
#define ERR_QLIB_DIAG_NV_WRITE_F                        "Qlib_Diag_NV_Write_F_Fail"
#define ERR_QLIB_DIAG_NV_WRITE_FlushBatchQueue          "Qlib_Diag_NV_Write_FlushBatchQueue_Fail"
#define ERR_QLIB_FTM_LOAD_RF_NV                         "Qlib_FTM_Load_RF_NV_Fail"
#define ERR_QLIB_FTM_SET_COMMAND_CODE                   "Qlib_FTM_Set_Command_Code_Fail"
#define ERR_QLIB_FTM_SET_CHAN                           "Qlib_FTM_Set_Channel_Fail"
#define ERR_QLIB_FTM_SET_SECONDARY_CHAIN                "Qlib_FTM_Set_Secondary_Chain_Fail"
#define ERR_QLIB_FTM_SET_TX_ONOFF                       "Qlib_FTM_Set_Tx_OnOff_Fail"//QLIB_FTM_SET_TX_ON/OFF
#define ERR_QLIB_RFCAL_NV_Manager_WriteToPhone          "Qlib_RFCal_NV_Manager_WriteToPhone_Fail"
#define ERR_QLIB_FTM_SET_PDM                            "Qlib_FTM_Set_PDM_Fail"
#define ERR_QLIB_FTM_SET_MODE_ID                        "Qlib_FTM_Set_Mode_Id_Fail"
#define ERR_QLIB_ConfigureTimeOut                       "Qlib_ConfigureTimeOut_Fail"
#define ERR_QLIB_FTM_GET_ENH_THERM                      "Qlib_FTM_Get_ENH_Therm_Fail"
#define ERR_QLIB_FTM_DO_ENH_XO_DC_CAL                   "Qlib_FTM_Do_ENH_XO_DC_Cal_Fail"
#define ERR_QLIB_FTM_DO_ENH_XO_DC_CAL_V2                "Qlib_FTM_Do_ENH_XO_DC_Cal_V2_Fail"
#define ERR_QLIB_FTM_DO_ENH_XO_FT_COLLECT_SAMPLE        "Qlib_FTM_Do_ENH_XO_FT_Collect_Sample_Fail"
#define ERR_QLIB_FTM_DO_ENH_XO_FT_COLLECT_SAMPLE_V2     "Qlib_FTM_Do_ENH_XO_FT_Collect_Sample_V2_Fail"
#define ERR_QLIB_FTM_DO_ENH_XO_FT_CURVE_CAL             "Qlib_FTM_Do_ENH_XO_FT_Curve_Cal_Fail"
#define ERR_QLIB_FTM_DO_ENH_XO_FT_CURVE_CAL_V2          "Qlib_FTM_Do_ENH_XO_FT_Curve_Cal_V2_Fail"
#define ERR_QLIB_GetPhoneOperatingMode                  "Qlib_GetPhoneOperatingMode_Fail"
#define ERR_QLIB_FTM_SET_RF_POWER_MODE                  "Qlib_FTM_Set_RF_Power_Mode_Fail"
#define ERR_QLIB_ConnectServer                          "Qlib_ConnectServer_Fail"
#define ERR_QLIB_DisconnectServer                       "Qlib_DisconnectServer_Fail"
#define ERR_QLIB_DIAG_NV_READ_F                         "Qlib_Diag_NV_Read_F_Fail"
#define ERR_QLIB_FTM_DO_SELF_CAL                        "Qlib_FTM_Do_Self_Cal_Fail"
#define ERR_QLIB_FTM_CFG_AND_EXEC_CAL_SWEEP             "Qlib_FTM_CFG_And_Exec_Cal_Sweep_Fail"
#define ERR_QLIB_FTM_GET_CAL_SWEEP_RESULTS              "Qlib_FTM_Get_Cal_Sweep_Results"
#define ERR_QLIB_SET_TX_BANDWIDTH                       "QLib_Set_Tx_Bandwidth_Fail"
#define ERR_QLIB_SET_RX_BANDWIDTH                       "QLib_Set_Rx_Bandwidth_Fail"
#define ERR_QLIB_SET_TX_MODULATION                      "QLib_Set_Tx_Modulation_Fail"
#define ERR_QLIB_SET_TX_WAVEFORM                        "Qlib_Set_Tx_Waveform_Fail"
#define ERR_QLIB_FTM_SET_TX_POWER_DBM                   "QLib_Set_Tx_Power_DBM_Fail"
#define ERR_QLIB_FTM_SET_TX_GAIN_INDEX                  "Qlib_FTM_Set_TX_Gain_Index_Fail"
#define ERR_QLIB_FTM_GET_RX_LEVEL_DBM                   "Qlib_FTM_Get_Rx_Level_DBM_Fail"
#define ERR_QLIB_FTM_XO_CALIBRATION                     "Qlib_FTM_XO_Calibration_Fail"
#define ERR_QLIB_FTM_DO_RSB_TXLO_CAL                    "Qlib_RSB_TXLO_Calibration_Fail"
#define ERR_QLIB_FTM_RFFE_READWRITE_CMD                 "Qlib_Read_RFFE_Device_Info_Fail"
#define ERR_QLIB_FTM_RF_MODE_EXIT                       "Qlib_FTM_RF_Mode_Exit_Fail"
//////////////////////////////////////////////////////////////////////////
//   QLib Phone GSM/EDGE Command Error Code
//////////////////////////////////////////////////////////////////////////

#define ERR_QLIB_FTM_EGPRS_BER_AssignBCCH                "Qlib_FTM_EGPRS_BER_AssignBCCH_Fail"
#define ERR_QLIB_FTM_EGPRS_BER_Configure_DL_TBF          "Qlib_FTM_EGPRS_BER_Configure_DL_TBF_Fail"
#define ERR_QLIB_FTM_EGPRS_BER_Configure_UL_TBF          "Qlib_FTM_EGPRS_BER_Configure_UL_TBF_Fail"
#define ERR_QLIB_FTM_EGPRS_BER_Establish_SRB_LOOPBACK    "Qlib_FTM_EGPRS_BER_Establish_SRB_LOOPBACK_Fail"
#define ERR_QLIB_FTM_EGPRS_BER_Release_All_TBF           "Qlib_FTM_EGPRS_BER_Release_All_TBF_Fail"
#define ERR_QLIB_FTM_GSM_BER_StartSession                "Qlib_FTM_GSM_BER_StartSession_Fail"
#define ERR_QLIB_FTM_GSM_BER_AssignBCCH                  "Qlib_FTM_GSM_BER_AssignBCCH_Fail"
#define ERR_QLIB_FTM_GSM_BER_Handover                    "Qlib_FTM_GSM_BER_HandOver_Fail"
#define ERR_QLIB_FTM_GSM_BER_ClearStatus                 "Qlib_FTM_GSM_BER_ClearStatus_Fail"
#define ERR_QLIB_FTM_GSM_ConfigLoopbackType              "Qlib_FTM_GSM_ConfigLoopbackType_Fail"
#define ERR_QLIB_FTM_RX_GAIN_RANGE_CAL                   "Qlib_FTM_Rx_Gain_Range_Cal_Fail"
#define ERR_QLIB_FTM_DA_CAL                              "Qlib_FTM_DA_Cal_Fail"
#define ERR_QLIB_FTM_SET_PA_DAC_INPUT                    "Qlib_FTM_Set_PA_DAC_Input_Fail"
#define ERR_QLIB_FTM_GSM_DO_TX_KV_CAL                    "Qlib_FTM_GSM_Do_Tx_Kv_Cal_Fail"
#define ERR_QLIB_FTM_TX_CFG2_AMAM_SWEEP                  "Qlib_FTM_Tx_CFG2_AMAM_Sweep_Fail"
#define ERR_QLIB_FTM_SET_TRANSMIT_BURST                  "Qlib_FTM_Set_Transmit_Burst_Fail"
#define ERR_QLIB_FTM_SET_TX_FRAME_MATRIX                 "Qlib_FTM_Set_Tx_Frame_Matrix_Fail"
#define ERR_QLIB_FTM_SET_PATH_DELAY                      "Qlib_FTM_Set_Path_Delay_Fail"
#define ERR_QLIB_FTM_GSM_BER_GetRxMetrics                "Qlib_FTM_GSM_BER_GetRxMetrics_Fail"
#define ERR_QLIB_FTM_SET_RX_BURST                        "Qlib_FTM_Set_Rx_Burst_Fail"
#define ERR_QLIB_FTM_SET_GSM_LINEAR_PA_RANGE             "Qlib_FTM_Set_GSM_Linear_PA_Range_Fail"
#define ERR_QLIB_RFCAL_GSM_CAL_ARFCN                     "Qlib_RFCal_GSM_Cal_Arfcn_Fail"
#define ERR_QLIB_RFCAL_GSM_Tx_Linear_Process_Swapped_PreDist_Cal_Results    "Qlib_RFCal_GSM_Tx_Linear_Process_Swapped_PreDist_Cal_Results_Fail"
#define ERR_QLIB_RFCAL_GSM_Rx_Gain_Range_Results         "Qlib_RFCAL_GSM_Rx_Gain_Range_Results_Fail"
#define ERR_QLIB_FTM_GSM_API_ReadEnvGainNV               "Qlib_FTM_GSM_API_ReadEnvGainNV_Fail"
#define ERR_QLIB_RFCal_GSM_Tx_DA_Cal_IQ_Predist_Cal_Generate_NV   "Qlib_RFCal_GSM_Tx_DA_Cal_IQ_Predist_Cal_Generate_NV_Fail"
#define ERR_QLIB_FTM_TX_CS_SWEEP                         "Qlib_FTM_Tx_CS_Sweep_Fail"
#define ERR_QLIB_FTM_GSM_POLAR_TX_SWEEP_CAL              "Qlib_FTM_GSM_Polar_Tx_Sweep_Cal_Fail"
#define ERR_QLIB_GSM_RX_CALIBRATION_GENERATE_NV          "Qlib_GSM_Rx_Calibration_Generate_NV_Fail"
#define ERR_QLIB_GSM_RX_LEVEL                            "Qlib_GSM_Rx_Level_Fail"
//////////////////////////////////////////////////////////////////////////
//   QLib Phone WCDMA/CDMA Command Error Code
//////////////////////////////////////////////////////////////////////////
//Qlib WCDMA
#define ERR_QLIB_FTM_GET_HDET_FROM_TX_SWEEP_CAL          "Qlib_FTM_Get_Hdet_From_Tx_Sweep_Cal_Fail"
#define ERR_QLIB_FTM_SET_TX_SWEEP_STEP_SIZE              "Qlib_FTM_Set_Tx_Sweep_Step_Size_Fail"
#define ERR_QLIB_FTM_CONFIGURE_TX_SWEEP_CAL              "Qlib_FTM_Configure_Tx_Sweep_Cal_Fail"
#define ERR_QLIB_FTM_TX_SWEEP_CAL                        "Qlib_FTM_Tx_Sweep_Cal_Fail"
#define ERR_QLIB_FTM_TX_RX_FREQ_CAL_SWEEP                "Qlib_FTM_Tx_Rx_Freq_Cal_Sweep_Fail"
#define ERR_QLIB_FTM_SET_LNA_RANGE                       "Qlib_FTM_Set_LNA_Range_Fail"
#define ERR_QLIB_FTM_CDMA_CW_WAVEFORM                    "Qlib_FTM_CDMA_CW_Waveform_Fail"
#define ERR_QLIB_FTM_SET_PA_RANGE                        "Qlib_FTM_Set_PA_Range_Fail"
#define ERR_QLIB_FTM_GET_CDMA_IM2                        "Qlib_FTM_Get_CDMA_Im2_Fail"
#define ERR_QLIB_FTM_WCDMA_BER_StopSession               "Qlib_FTM_WCDMA_BER_StopSession_Fail"
#define ERR_QLIB_FTM_DO_DC_CAL                           "Qlib_FTM_Do_DC_Cal_Fail"
#define ERR_QLIB_FTM_WCDMA_BER_RMC_DCH_TFCS_CONFIG_REQ   "Qlib_FTM_WCDMA_BER_RMC_Dch_Tfcs_Config_Req_Fail"
#define ERR_QLIB_FTM_WCDMA_BER_StartSession              "Qlib_FTM_WCDMA_BER_StartSession_Fail"
#define ERR_QLIB_FTM_WCDMA_BER_AcquirePilot              "Qlib_FTM_WCDMA_BER_AcquirePilot_Fail"
#define ERR_QLIB_FTM_WCDMA_BER_Handover                  "Qlib_FTM_WCDMA_BER_HandOver_Fail"
#define ERR_QLIB_FTM_GET_DVGA_OFFSET                     "Qlib_FTM_Get_DVGA_Offset_Fail"
#define ERR_QLIB_FTM_SET_CALIBRATION_STATE               "Qlib_FTM_Set_Calibration_State_Fail"
#define ERR_QLIB_FTM_SET_SMPS_PA_BIAS_VAL                "Qlib_FTM_Set_Smps_PA_Bias_Val_Fail"
#define ERR_QLIB_FTM_SET_SMPS_PA_BIAS_OVERRIDE           "Qlib_FTM_Set_Smps_PA_Bias_Override_Fail"
#define ERR_QLIB_FTM_LOAD_TX_LINEARIZER_CAL_DATA         "Qlib_FTM_Load_Tx_Linearizer_Cal_Data_Fail"
#define ERR_QLIB_FTM_LOAD_TX_FREQCOMP_CAL_DATA           "Qlib_FTM_Load_Tx_Freqcomp_Cal_Data_Fail"
#define ERR_QLIB_FTM_SET_TX_ENH_CAL_ACTION               "Qlib_FTM_Set_Tx_ENH_Cal_Action_Fail"
#define ERR_QLIB_FTM_WCDMA_AGC_Start_Log                 "Qlib_FTM_WCDMA_AGC_Start_Log_Fail"
#define ERR_QLIB_FTM_WCDMA_AGC_WaitForNextLog            "Qlib_FTM_WCDMA_AGC_WaitForNextLog_Fail"
#define ERR_QLIB_FTM_WCDMA_AGC_Stop_Log                  "Qlib_FTM_WCDMA_AGC_Stop_Log"
#define ERR_QLIB_RFCAL_WCDMA_MultiCarrier_RxCal_Results  "Qlib_RFCal_WCDMA_MultiCarrier_RxCal_Results_Fail"
#define ERR_QLIB_RFCAL_Complete_TxRxCal                  "Qlib_RFCal_Complete_TxRxCal_Fail"
//Qlib CDMA
#define ERR_QLIB_FTM_CDMA_API2_CALIBRATE_DVGA            "Qlib_FTM_CDMA_Api2_Calibrate_DVGA_Fail"
#define ERR_QLIB_FTM_CDMA_API2_CALIBRATE_INTELLICEIVER   "Qlib_FTM_CDMA_Api2_Calibrate_Intelliceiver_Fail"
#define ERR_QLIB_RFCAL_Rx_Intelliceiver_Cal_Results      "Qlib_RFCAL_Rx_Intelliceiver_Cal_Results_Fail"
#define ERR_QLIB_FTM_CDMA2000_CMD_RELEASE                "Qlib_FTM_CDMA2000_Cmd_Release_Fail"
#define ERR_QLIB_FTM_CDMA2000_NS_Start                   "Qlib_FTM_CDMA2000_NS_Start_Fail"
#define ERR_QLIB_FTM_CDMA2000_FTM_FWD_HHO_SC             "Qlib_FTM_CDMA2000_FTM_FWD_HHO_SC_Fail"
#define ERR_QLIB_FTM_CDMA2000_NS_Get_FCH_SER_FER         "Qlib_FTM_CDMA2000_NS_Get_FCH_SER_FER_Fail"
#define ERR_QLIB_FTM_CDMA2000_NS_SetSER_RCandRS          "Qlib_FTM_CDMA2000_NS_SetSER_RCandRS_Fail"
#define ERR_QLIB_DIAG_READ_ESN_F                         "Qlib_Diag_Read_ESN_F_Fail"
#define ERR_QLIB_RFCAL_CDMA_Tx_LinVsFreq_Results         "Qlib_RFCal_CDMA_Tx_LinVsFreq_Results_Fail"
#define ERR_QLIB_RFCAL_CDMA_Tx_LimVsFreq_Results         "Qlib_RFCal_CDMA_Tx_LimVsFreq_Results_Fail"
#define ERR_QLIB_RFCAL_CDMA_RxCal_Results                "Qlib_RFCal_CDMA_Rxcal_Results_Fail"
#define ERR_QLIB_RFCAL_CDMA_TxLinCal_BetaScaling_Results "Qlib_RFCal_CDMA_TxLinCal_BetaScaling_Results_Fail"
#define ERR_QLIB_FTM_CDMA2000_NS_Stop                    "Qlib_FTM_CDMA2000_NS_Stop_Fail"
#define ERR_QLIB_FTM_CDMA2000_NS_ClearStatus             "Qlib_FTM_CDMA2000_NS_ClearStatus_Fail"
#define ERR_QLIB_FTM_CDMA2000_DEMOD_SYNC                 "Qlib_FTM_CDMA2000_Demod_Sync_Fail"
#define ERR_QLIB_FTM_CDMA2000_DEMOD_FCH                  "Qlib_FTM_CDMA2000_Demod_Fch_Fail"
#define ERR_QLIB_FTM_CDMA2000_PILOT_ACQ                  "Qlib_FTM_CDMA2000_Pilot_ACQ_Fail"
#define ERR_QLIB_FTM_EVDO_CMD_RELEASE                    "Qlib_FTM_EVDO_CMD_Release_Fail"
#define ERR_QLIB_FTM_EVDO_SYS_TIME_ACQ                   "Qlib_FTM_EVDO_SYS_TIME_ACQ_Fail"
#define ERR_QLIB_FTM_EVDO_MOD_ACC                        "Qlib_FTM_EVDO_MOD_ACC_Fail"
#define ERR_QLIB_FTM_EVDO_MOD_REVERSE_TRA                "Qlib_FTM_QLIB_FTM_EVDO_MOD_REVERSE_TRA_Fail"
//////////////////////////////////////////////////////////////////////////
//   Device Error Code
//////////////////////////////////////////////////////////////////////////

#define ERR_DEVICE_GSM_Calibration                      "Device_GSM_Calibration_Fail"
#define ERR_DEVICE_GSM_Test                             "Device_GSM_Test_Fail"
#define ERR_DEVICE_EDGE_Test                            "Device_EDGE_Test_Fail"
#define ERR_DEVICE_WCDMA_Calibration                    "Device_WCDMA_Calibration_Fail"
#define ERR_DEVICE_WCDMA_Test                           "Device_WCDMA_Test_Fail"
#define ERR_DEVICE_CDMA_Calibration                     "Device_CDMA_Calibration_Fail"
#define ERR_DEVICE_CDMA_Test                            "Device_CDMA_Test_Fail"
#define ERR_DEVICE_LTE_Calibration                      "Device_LTE_Calibration_Fail"
#define ERR_DEVICE_LTE_Test                             "Device_LTE_Test_Fail"
#define ERR_DEVICE_EVDO_Test                            "Device_EVDO_Test_Fail"

//////////////////////////////////////////////////////////////////////////
//   Cal spec
//////////////////////////////////////////////////////////////////////////

//GSM Cal
#define ERR_GSMCAL_KVCO_Value                           "GSMCal_KVCO_Value_Fail"
#define ERR_GSMCAL_PA_Linear_Trigger_Power              "GSMCal_PA_Linear_Trigger_Power_Fail"
#define ERR_GSMCal_TimingDelay_Search                   "GSMCal_TimingDelay_Search_Fail"
#define ERR_GSMCal_RxFreqCompensation_RSSI              "GSMCal_RxFreqCompensation_RSSI_Fail"
#define ERR_GSMCAL_PA_DAC_Search                        "GSMCal_PA_DAC_Search_Fail"
#define ERR_GSMCAL_Polar_Trigger_Power                  "GSMCal_Polar_Trigger_Power_Fail"

#define ERR_GSMCAL_PreDistortion_Dynamic_Range_Max_Power      "GSMCAL_PreDistortion_Dynamic_Range_Max_Power_Fail"
#define ERR_GSMCAL_PreDistortion_Meas_Delay                   "GSMCAL_PreDistortion_Meas_Delay_Fail"
#define ERR_GSMCAL_PreDistortion_EDGE_Duration                "GSMCAL_PreDistortion_EDGE_Duration_Fail"
//CDMA Cal
#define ERR_CDMACAL_Rx_Intelliceiver                    "CDMACal_Rx_Intelliceiver_Fail"
#define ERR_CDMACAL_TxLinMaster_Initial_Power           "CDMACal_TxLinMaster_Initial_Power_Fail"
#define ERR_CDMACAL_TxRxAlign_DVGA                      "CDMACal_TxRxAlign_DVGA_Fail"
#define ERR_CDMACAL_TxRxAlign_LNA                       "CDMACal_TxRxAlign_LNA_Fail"
#define ERR_CDMACAL_XOCoarse_Status                     "CDMACAL_XOCoarse_Status_Fail"
#define ERR_CDMACAL_XOCoarse_Temperature                "CDMACAL_XOCoarse_Temperature_Fail"
#define ERR_CDMACAL_TxRxAlign_LIM                       "CDMACal_TxRxAlign_LIM_Fail"
#define ERR_CDMACAL_TxRxAlign_LIM                       "CDMACal_TxRxAlign_LIM_Fail"
//WCDMA Cal
#define ERR_WCDMACAL_TxLinMaster_Initial_Power          "WCDMACal_TxLinMaster_Initial_Power_Fail"
#define ERR_WCDMACAL_TxRxAlign_HDET_Power_VS_PDM_Search "WCDMACal_TxRxAlign_HDET_Power_VS_PDM_Search_Fail" 
#define ERR_WCDMACAL_TxRxAlign_DVGA                     "WCDMACal_TxRxAlign_DVGA_Fail"
#define ERR_WCDMACAL_TxRxAlign_LNA                      "WCDMACal_TxRxAlign_LNA_Fail"
#define ERR_WCDMACAL_TxRxAlign_LimFreq_Extra_RelativePDM_List_Count   "WCDMACAL_TxRxAlign_LimFreq_Extra_RelativePDM_List_Count_Fail"
#define ERR_WCDMACAL_XOCoarse_Status                    "WCDMACAL_XOCoarse_Status_Fail"
#define ERR_WCDMACAL_XOCoarse_Temperature               "WCDMACAL_XOCoarse_Temperature_Fail"

//////////////////////////////////////////////////////////////////////////
//   Test spec
//////////////////////////////////////////////////////////////////////////

//GSM TEST SPEC
#define ERR_GSMTEST_MAX_POWER                           "GSMTest_Max_Power_Fail"
#define ERR_GSMTEST_PVT                                 "GSMTest_PVT_Fail"
#define ERR_GSMTEST_PEAK_PHASE                          "GSMTest_Peak_Phase_Fail"
#define ERR_GSMTEST_AVG_RMS_PHASE                       "GSMTest_Avg_RMS_Phase_Fail"
#define ERR_GSMTEST_FREQUENCY                           "GSMTest_Frequency_Fail"
#define ERR_GSMTEST_SPECTRUM_SWIT                       "GSMTest_Spectrum_Swit_Fail"
#define ERR_GSMTEST_SPECTRUM_MOD                        "GSMTest_Spectrum_Mod_Fail"
#define ERR_GSMTEST_RX_LEV                              "GSMTest_Rx_Lev_Fail"
#define ERR_GSMTEST_TX_CURR                             "GSMTest_Tx_Curr_Fail"
#define ERR_GSMTEST_BER                                 "GSMTest_BER_Fail"
//EDGE TEST SPEC
#define ERR_EDGETEST_MAX_POWER                          "EDGETest_Max_Power_Fail"
#define ERR_EDGETEST_EVM_RMS                            "EDGETest_EVM_RMS_Fail"
#define ERR_EDGETEST_EVM_95                             "EDGETest_EVM_95_Fail"
#define ERR_EDGETEST_FREQUENCY                          "EDGETest_Frequency_Fail"
#define ERR_EDGETEST_SPECTRUM_SWIT                      "EDGETest_Spectrum_Swit_Fail"
#define ERR_EDGETEST_SPECTRUM_MOD                       "EDGETest_Spectrum_Mod_Fail"
#define ERR_EDGETEST_PVT                                "EDGETest_PVT_Fail"
#define ERR_EDGETEST_Peak_EVM                           "EDGETest_Peak_EVM_Fail"
//CDMA TEST SPEC
#define ERR_CDMATEST_WAVEFORM_QUALITY                   "CDMATest_Waveform_Quality_Fail"
#define ERR_CDMATEST_FREQUENCY                          "CDMATest_Frequency_Fail"
#define ERR_CDMATEST_TIME_ERROR                         "CDMATest_Time_Error_Fail"
#define ERR_CDMATEST_CARRIERFTH                         "CDMATest_CarrierFTH_Fail"
#define ERR_CDMATEST_PHASE                              "CDMATest_Phase_Fail"
#define ERR_CDMATEST_MAGNITUDE                          "CDMATest_Magnitude_Fail"
#define ERR_CDMATEST_EVM                                "CDMATest_EVM_Fail"
#define ERR_CDMATEST_TX_CURR                            "CDMATest_Tx_Curr_Fail"
#define ERR_CDMATEST_RCLPC                              "CDMATest_RCLPC_Fail"
#define ERR_CDMATEST_CDPOWER                            "CDMATest_CDPower_Fail"
#define ERR_CDMATEST_TIME_TOLERANCE                     "CDMATest_Time_Tolerance_Fail"
#define ERR_CDMATEST_PHASE_TOLERANCE                    "CDMATest_Phase_Tolerance_Fail"
#define ERR_CDMATEST_MIN_POWER                          "CDMATest_Min_Power_Fail"
#define ERR_CDMATEST_MAX_POWER                          "CDMATest_Max_Power_Fail"
#define ERR_CDMATEST_RX_SENSITIVITY                     "CDMATest_Rx_Sensitivity_Fail"
#define ERR_CDMATEST_RX_DYNAMIC_RANGE                   "CDMATest_Rx_Dynamic_Range_Fail"
#define ERR_CDMATEST_CSE                                "CDMATest_CSE_Fail"
//WCDMA TEST SPEC
#define ERR_WCDMATEST_MAX_POWER                         "WCDMATest_Max_Power_Fail"
#define ERR_WCDMATEST_MINPOWER                          "WCDMATest_Min_Power_Fail"
#define ERR_WCDMATEST_EVM_RMS                           "WCDMATest_EVM_RMS_Fail"
#define ERR_WCDMATEST_FREQUENCY                         "WCDMATest_Frequency_Fail"
#define ERR_WCDMATEST_TRANS_TIME                        "WCDMATest_Trans_Time_Fail"
#define ERR_WCDMATEST_SPECTRUM_EMASK                    "WCDMATest_Spectrum_EMask_Fail"
#define ERR_WCDMATEST_OBW                               "WCDMATest_OBW_Fail"
#define ERR_WCDMATEST_BER                               "WCDMATest_BER_Fail"
#define ERR_WCDMATEST_RXLEV                             "WCDMATest_RxLev_Fail"
#define ERR_WCDMATEST_ILPCE                             "WCDMATest_ILPCE_Fail"
#define ERR_WCDMATEST_ILPCF                             "WCDMATest_ILPCF_Fail"
#define ERR_WCDMATEST_ACLR                              "WCDMATest_ACLR_Fail"
#define ERR_WCDMATEST_TX_CURR                           "WCDMATest_Tx_Curr_Fail"

//EVDO Test Spec
#define ERR_EVDOTEST_WAVEFORM_QUALITY                   "EVDOTest_Waveform_Quality_Fail"
#define ERR_EVDOTEST_FREQUENCY                          "EVDOTest_Frequency_Fail"
#define ERR_EVDOTEST_TIME_ERROR                         "EVDOTest_Time_Error_Fail"
#define ERR_EVDOTEST_CARRIERFTH                         "EVDOTest_CarrierFTH_Fail"
#define ERR_EVDOTEST_PHASE                              "EVDOTest_Phase_Fail"
#define ERR_EVDOTEST_MAGNITUDE                          "EVDOTest_Magnitude_Fail"
#define ERR_EVDOTEST_EVM                                "EVDOTest_EVM_Fail"
#define ERR_EVDOTEST_TX_CURR                            "EVDOTest_Tx_Curr_Fail"
#define ERR_EVDOTEST_RCLPC                              "EVDOTest_RCLPC_Fail"
#define ERR_EVDOTEST_CDPOWER                            "EVDOTest_CDPower_Fail"
#define ERR_EVDOTEST_TIME_TOLERANCE                     "EVDOTest_Time_Tolerance_Fail"
#define ERR_EVDOTEST_PHASE_TOLERANCE                    "EVDOTest_Phase_Tolerance_Fail"
#define ERR_EVDOTEST_MIN_POWER                          "EVDOTest_Min_Power_Fail"
#define ERR_EVDOTEST_MAX_POWER                          "EVDOTest_Max_Power_Fail"
#define ERR_EVDOTEST_RX_SENSITIVITY                     "EVDOTest_Rx_Sensitivity_Fail"
#define ERR_EVDOTEST_RX_DYNAMIC_RANGE                   "EVDOTest_Rx_Dynamic_Range_Fail"
#define ERR_EVDOTEST_CSE                                "EVDOTest_CSE_Fail"

//LTE Cal
#define ERR_LTECAL_TxLinMaster_Initial_Power                        "LTECal_TxLinMaster_Initial_Power_Fail"
#define ERR_LTECAL_TxRxAlign_HDET_Power_VS_PDM_Search               "LTECal_TxRxAlign_HDET_Power_VS_PDM_Search_Fail" 
#define ERR_LTECAL_TxRxAlign_DVGA                                   "LTECal_TxRxAlign_DVGA_Fail"
#define ERR_LTECAL_TxRxAlign_LNA                                    "LTECal_TxRxAlign_LNA_Fail"
#define ERR_LTECAL_TxRxAlign_LimFreq_Extra_RelativePDM_List_Count   "LTECAL_TxRxAlign_LimFreq_Extra_RelativePDM_List_Count_Fail"
//LTE DRX CAL
#define ERR_LTECAL_DRX_TxRxAlign_HDET_Power_VS_PDM_Search           "LTECal_DRX_TxRxAlign_HDET_Power_VS_PDM_Search_Fail" 
#define ERR_LTECAL_DRX_TxRxAlign_DVGA                               "LTECal_DRX_TxRxAlign_DVGA_Fail"
#define ERR_LTECAL_DRX_TxRxAlign_LNA                                "LTECal_DRX_TxRxAlign_LNA_Fail"
//LTE TEST SPEC
#define ERR_LTETEST_MAX_POWER                                      "LTETest_Max_Power_Fail"
#define ERR_LTETEST_MIN_POWER                                      "LTETest_Min_Power_Fail"
#define ERR_LTETEST_EVM                                            "LTETest_EVM_Fail"
#define ERR_LTETEST_FREQ_ERR                                       "LTETest_FreqErr_Fail"
#define ERR_LTETEST_SEM                                            "LTETest_SEM_Fail"
#define ERR_LTETEST_IQ_OFFSET                                      "LTETest_IQoffset_Fail"
#define ERR_LTETEST_OBW                                            "LTETest_OBW_Fail"
#define ERR_LTETEST_BER                                            "LTETest_BER_Fail"
#define ERR_LTETEST_RXSENS                                         "LTETest_RxSens_Fail"
#define ERR_LTETEST_ACLR                                           "LTETest_ACLR_Fail"
#define ERR_LTETEST_MAX_INPUT                                      "LTETest_MaxInput_Fail"
#define ERR_LTETEST_IEM                                            "LTETest_IEM_Fail"
#define ERR_LTETEST_ESFL                                           "LTETest_ESFL_Fail"
#define ERR_LTETEST_TRANS_POWER                                    "LTETest_Trans_Power_Fail"
#define ERR_LTETEST_MIN_RXSENS                                     "LTETest_Min_RxSens_Fail"
//LTE DRX TEST SPEC
#define ERR_LTETEST_DRX_BER                                        "LTETest_DRX_BER_Fail"
#define ERR_LTETEST_DRX_SENS                                       "LTETest_DRX_Sens_Fail"
#define ERR_LTETEST_DRX_MAX_INPUT                                  "LTETest_DRX_MaxInput_Fail"
#define ERR_LTETEST_DRX_MIN_RXSENS                                 "LTETest_DRX_Min_RxSens_Fail"
//power supply
#define ERR_DEVICE_PS_INIT                              "Device_PS_Init_Fail"
#define ERR_DEVICE_PS_GET_CURR                          "Device_PS_Get_Curr_Fail"
#define ERR_DEVICE_PS_SET_VOL                           "Device_PS_Set_Vol_Fail"
#define ERR_DEVICE_PS_SET_CURR_LIMIT                    "Device_PS_Set_Curr_Limit_Fail"
#define ERR_DEVICE_PS_SET_ONOFF                         "Device_PS_Set_OnOff_Fail"

#endif //_RF_ERRORDEFINE_H
