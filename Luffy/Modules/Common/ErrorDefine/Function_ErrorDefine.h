#ifndef _FUNCTION_ERRORDEFINE_H
#define _FUNCTION_ERRORDEFINE_H

//**Battery & Coin Cell
#define FunErr_Check_Battery_ID_Fail               "Check_Battery_ID_Fail"
#define FunErr_Check_Battery_Temperature_Fail      "Check_Battery_Temperatur_Fail"
#define FunErr_Check_Battery_Voltage_Fail          "Check_Battery_Voltage_Fail"
#define FunErr_Detect_Battery_Cover_Fail           "Detect_Battery_Cover_Fail"
#define FunErr_Check_Coin_Cell_Voltage_Fail        "Check_Coin_Cell_Voltage_Fail"
#define FunErr_Charge_ID_Fail                      "Charge_ID_Fail"
#define FunErr_Check_Battery_Impedance_Fail        "Check_Battery_Impedance_Fail"
#define FunErr_Check_Battery_Current_Fail          "Check_Battery_Current_Fail"
#define FunErr_Battery_Voltage_Too_Low             "Battery_Voltage_Too_Low"
#define FunErr_Check_Battery_Capacity_Fail         "Check_Battery_Capacity_Fail"
//**charging
#define FunErr_Switch_To_USB_Charging_Fail       "Switch_To_USB_Charging_Fail"
#define FunErr_USB_Charge_Fail                   "USB_Charge_Fail"
#define FunErr_Stop_Coin_Cell_Charge_Fail        "Stop_Coin_Cell_Charge_Fail"
#define FunErr_Start_Coin_Cell_Charge_Fail       "Start_Coin_Cell_Charge_Fail"
#define FunErr_Stop_USB_Charging_Fail            "Stopo_USB_Charging_Fail"
//**BT
#define FunErr_BT_Test_Init_Device_Fail          "BT_Test_Init_Device_Fail"
#define FunErr_BT_Test_Set_Command_Fail          "BT_Test_Set_Command_Fail"
#define FunErr_BT_Module_ON_Fail                 "BT_Module_ON_Fail"
#define FunErr_BT_Module_OFF_Fail                "BT_Module_OFF_Fail"
#define FunErr_BT_Power_ON_Fail                  "BT_Power_ON_Fail"
#define FunErr_BT_Power_OFF_Fail                 "BT_Power_OFF_Fail"
#define FunErr_BT_Test_OutPower_OutRange         "BT_Test_OutPower_OutRange"
#define FunErr_BT_ID_Fail                        "BT_ID_Fail"
#define FunErr_BT_Hardware_Selftest_Fail         "BT_Hardware_Selftest_Fail"
#define FunErr_BT_EM_Test_Fail                   "BT_EM_Test_Fail"
#define FunErr_BT_Modulation_Characteristic_Fail "BT_Modulation_Characteristic_Fail"
#define FunErr_BT_ICFT_Fail                      "BT_ICFT_Fail"
#define FunErr_BT_Carrier_Drift_Fail             "BT_Carrier_Drift_Fail"
#define FunErr_BT_EDR_Freq_Stab_Mod_ACC_Fail     "BT_EDR_Freq_Stab_Mod_ACC_Fail"
#define FunErr_BT_EDR_Diff_Phase_Encoding_Fail   "BT_EDR_Diff_Phase_Encoding_Fail"
#define FunErr_BT_Singleslot_Sensitivity_Fail    "BT_Singleslot_Sensitivity_Fail"
#define FunErr_BT_Multislot_Sensitivity_Fail     "BT_Multislot_Sensitivity_Fail"
#define FunErr_BT_Max_Usable_Signal_Level_Fail   "BT_MAX_USABLE_SIGNAL_LEVEL_Fail"
#define FunErr_BT_EDR_Sensitivity_Fail           "BT_EDR_Sensitivity_Fail"
#define FunErr_BT_EDR_BER_Floor_Fail             "BT_EDR_BER_Floor_Fail"
#define FunErr_BT_EDR_Max_Input_Level_Fail       "BT_EDR_Max_Input_Level_Fail"
#define FunErr_BT_Power_Control_Fail             "BT_Power_Control_Fail"
#define FunErr_BT_EDR_Relative_Power_Fail        "BT_EDR_Relative_Power_Fail"
#define FunErr_BT_SCO_Path_Fail                  "BT_SCO_Path_Fail"
#define FunErr_BT_Play_To_A2DP_Fail              "BT_Play_To_A2DP_Fail"
//**FM
#define FunErr_FM_Test_Init_Device_Fail          "FM_Test_Init_Device_Fail"
#define FunErr_FM_Test_Set_Command_Fail          "FM_Test_Set_Command_Fail"
#define FunErr_FM_Test_Fail                      "FM_Test_Fail"
#define FunErr_FM_ID_Fail                        "FM_ID_Fail"
//**WLAN
#define FunErr_WLAN_Test_Init_Device_Fail          "WLAN_Test_Init_Device_Fail"
#define FunErr_WLAN_Test_Set_Command_Fail          "WLAN_Test_Set_Command_Fail"
#define FunErr_WLAN_Module_ON_Fail                 "WLAN_Module_ON_Fail"
#define FunErr_WLAN_Module_OFF_Fail                "WLAN_Module_OFF_Fail"
#define FunErr_WLAN_Power_ON_Fail                  "WLAN_Power_ON_Fail"
#define FunErr_WLAN_Power_OFF_Fail                 "WLAN_Power_OFF_Fail"
#define FunErr_WLAN_Test_OutPower_OutRange         "WLAN_Test_OutPower_OutRange"
#define FunErr_WLAN_ID_Fail                        "WLAN_ID_Fail"
#define FunErr_WLAN_Hardware_Selftest_Fail         "WLAN_Hardware_Selftest_Fail"
#define FunErr_WLAN_Fetch_OutPower_Fail            "WLAN_Fetch_OutPower_Fail"
#define FunErr_WLAN_Connect_Fail                   "WLAN_Connect_Fail"
#define FunErr_WLAN_EM_Test_Fail                   "WLAN_EM_Test_Fail"
#define FunErr_WLAN_EVM_Fail                       "WLAN_EVM_Fail"
#define FunErr_WLAN_Carrier_Suppresion_Fail        "WLAN_Carrier_Suppresion_Fail"
#define FunErr_WLAN_Freq_Error_Fail                "WLAN_Freq_Error_Fail"
#define FunErr_WLAN_Demod_Fail                     "WLAN_Demod_Fail"
#define FunErr_WLAN_Power_Ramp_Fail                "WLAN_Power_Ramp_Fail"
#define FunErr_WLAN_Spectral_Mask_Fail             "WLAN_Spectral_Mask_Fail"
#define FunErr_WLAN_Spectral_Flatness_Fail         "WLAN_Spectral_Flatness_Fail"
#define FunErr_WLAN_RX_Minsens_Fail                "WLAN_RX_Minsens_Fail"
#define FunErr_WLAN_Load_Bin_Fail                  "WLAN_Load_Bin_Fail"
#define FunErr_WLAN_Save_Bin_Fail                  "WLAN_Save_Bin_Fail"
//**GPS
#define FunErr_GPS_Test_Init_Device_Fail           "GPS_Test_Init_Device_Fail"
#define FunErr_GPS_Test_Set_Command_Fail           "GPS_Test_Set_Command_Fail"
#define FunErr_GPS_Test_CN0_OutRange               "GPS_Test_CN0_OutRange"
#define FunErr_GPS_Test_Fail                       "GPS_Test_Fail"
//**WirelessGSM
#define FunErr_WirelessGSM_Test_Set_Command_Fail         "WirelessGSM_Test_Set_Command"
#define FunErr_WirelessGSM_Test_Init_Device_Fail         "WirelessGSM_Test_Init_Device"
#define FunErr_WirelessGSM_Test_OutPower_OutRange        "WirelessGSM_Test_OutPower"
#define FunErr_WirelessGSM_Online_Call_Fail              "WirelessGSM_Online_Call"
#define FunErr_WirelessGSM_Online_BER_OutRange           "WirelessGSM_Online_BER"
#define FunErr_WirelessGSM_Online_RSSI_OutRange          "WirelessGSM_Online_RSSI"
#define FunErr_WirelessGSM_Online_EndCall_Fail           "WirelessGSM_Online_EndCall"
#define FunErr_WirelessGSM_Online_Handover_Fail          "WirelessGSM_Online_Handover"
#define FunErr_WirelessGSM_Get_PhoneMode_Fail            "WirelessGSM_Get_PhoneMode_Fail"
#define FunErr_WirelessGSM_Set_Band_CH_Fail              "WirelessGSM_Set_Band_CH_Fail"
#define FunErr_WirelessGSM_Set_PhoneMode_Fail            "WirelessGSM_Set_PhoneMode_Fail"
#define FunErr_WirelessGSM_Set_PhoneBand_Fail            "WirelessGSM_Set_PhoneBand_Fail"
#define FunErr_WirelessGSM_Set_PhoneCH_Fail              "WirelessGSM_Set_PhoneCH_Fail"
#define FunErr_WirelessGSM_Set_PA_Range_Fail             "WirelessGSM_Set_PA_Range_Fail"
#define FunErr_WirelessGSM_Set_WAVE_Fail                 "WirelessGSM_Set_WAVE_Fail"
#define FunErr_WirelessGSM_Set_TX_PDM_Fail               "WirelessGSM_Set_TX_PDM_Fail"
#define FunErr_WirelessGSM_Set_TX_ONOFF_Fail             "WirelessGSM_Set_TX_ONOFF_Fail"
#define FunErr_WirelessGSM_Fetch_Max_Power_Fail          "WirelessGSM_Fetch_Max_Power_Fail"
#define FunErr_WirelessGSM_Set_RGI_Fail                  "WirelessGSM_Set_RGI_Fail"
#define FunErr_WirelessGSM_Get_RGI_Fail                  "WirelessGSM_Get_RGI_Fail"
#define FunErr_WirelessGSM_Online_Sync_Fail              "WirelessGSM_Online_Sync_Fail"
//**WirelessWCDMA
#define FunErr_WirelessWCDMA_Test_Set_Command_Fail       "WirelessWCDMA_Test_Set_Command"
#define FunErr_WirelessWCDMA_Test_Init_Device_Fail       "WirelessWCDMA_Test_Init_Device"
#define FunErr_WirelessWCDMA_Test_OutPower_OutRange      "WirelessWCDMA_Test_OutPower"
#define FunErr_WirelessWCDMA_Online_Call_Fail            "WirelessWCDMA_Online_Call"
#define FunErr_WirelessWCDMA_Online_BER_OutRange         "WirelessWCDMA_Online_BER"
#define FunErr_WirelessWCDMA_Online_RSCP_OutRange        "WirelessWCDMA_Online_RSCP"
#define FunErr_WirelessWCDMA_Online_EndCall_Fail         "WirelessWCDMA_Online_EndCall"
#define FunErr_WirelessWCDMA_Online_Handover_Fail        "WirelessWCDMA_Online_Handover"
#define FunErr_WirelessWCDMA_Get_PhoneMode_Fail          "WirelessWCDMA_Get_PhoneMode_Fail"
#define FunErr_WirelessWCDMA_Fetch_Max_Power_Fail        "WirelessWCDMA_Fetch_Max_Power_Fail"
#define FunErr_WirelessWCDMA_Set_Band_CH_Fail            "WirelessWCDMA_Set_Band_CH_Fail"
#define FunErr_WirelessWCDMA_Set_PhoneMode_Fail          "WirelessWCDMA_Set_PhoneMode_Fail"
#define FunErr_WirelessWCDMA_Set_PhoneBand_Fail          "WirelessWCDMA_Set_PhoneBand_Fail"
#define FunErr_WirelessWCDMA_Set_PhoneCH_Fail            "WirelessWCDMA_Set_PhoneCH_Fail"
#define FunErr_WirelessWCDMA_Set_PA_Range_Fail           "WirelessWCDMA_Set_PA_Range_Fail"
#define FunErr_WirelessWCDMA_Set_WAVE_Fail               "WirelessWCDMA_Set_WAVE_Fail"
#define FunErr_WirelessWCDMA_Set_TX_PDM_Fail             "WirelessWCDMA_Set_TX_PDM_Fail"
#define FunErr_WirelessWCDMA_Get_TX_PDM_Fail             "WirelessWCDMA_Get_TX_PDM_Fail"
#define FunErr_WirelessWCDMA_Set_TX_ONOFF_Fail           "WirelessWCDMA_Set_TX_ONOFF_Fail"
#define FunErr_WirelessWCDMA_Online_Sync_Fail            "WirelessWCDMA_Online_Sync_Fail"
//**WirelessCDMA200
#define FunErr_WirelessCDMA2000_Get_PhoneMode_Fail       "WirelessCDMA2000_Get_PhoneMode_Fail"
#define FunErr_WirelessCDMA2000_Fetch_Max_Power_Fail     "WirelessCDMA2000_Fetch_Max_Power_Fail"
#define FunErr_WirelessCDMA2000_Set_Band_CH_Fail         "WirelessCDMA2000_Set_Band_CH_Fail"
#define FunErr_WirelessCDMA2000_Set_TX_ONOFF_Fail        "WirelessCDMA2000_Set_TX_ONOFF_Fail"
#define FunErr_WirelessCDMA2000_Get_PDM_NV_Fail          "WirelessCDMA2000_Get_PDM_NV_Fail"
#define FunErr_WirelessCDMA2000_Test_Init_Device_Fail    "WirelessCDMA2000_Test_Init_Device_Fail"
#define FunErr_WireleseCDMA2000_Test_OutPower_OutRange   "WirelessCDMA2000_Test_OutPower"
//WirelessLTE
#define	FunErr_WirelessLTE_TX_Power_Fail	         "WirelessLTE_Tx_Power_Fail"
#define	FunErr_WirelessLTE_Diversity_RxRSSI_Fail	 "WirelessLTE_Diversity_RxRSSI_Fail"
#define FunErr_WirelessLTE_Test_Set_Command_Fail         "WirelessLTE_Test_Set_Command"
#define FunErr_WirelessLTE_Test_Init_Device_Fail         "WirelessLTE_Test_Init_Device"
#define FunErr_WirelessLTE_RX_Power_Fail                 "WirelessLTE_Rx_Power_Fail"
//**Camera
#define FunErr_Front_Camera_Test_Macro_Capture_Fail   "Front_Camera_Test_Macro_Capture_Fail"
#define FunErr_Front_Camera_Test_Capture_Fail         "Front_Camera_Test_Capture_Fail"
#define FunErr_Front_Camera_Test_Shutdown_Fail        "Front_Camera_Test_Shutdown_Fail"
#define FunErr_Front_Camera_Test_Read_ID_Fail         "Front_Camera_Test_Read_ID_Fail"
#define FunErr_Front_Camera_Test_Shading_Fail         "Front_Camera_Test_Shading_Fail"
#define FunErr_Front_Camera_Test_Blemish_Fail         "Front_Camera_Test_Blemish_Fail"
#define FunErr_Front_Camera_Test_MTF_Fail             "Front_Camera_Test_MTF_Fail"
#define FunErr_Front_Camera_Test_Tile_Fail            "Front_Camera_Test_Tile_Fail"
#define FunErr_Front_Camera_Test_Rotation_Fail        "Front_Camera_Test_Rotation_Fail"
#define FunErr_Front_Camera_Test_Color_Fail           "Front_Camera_Test_Color_Fail"
#define FunErr_Rear_Camera_Test_Capture_Fail          "Rear_Camera_Test_Capture_Fail" 
#define FunErr_Rear_Camera_Test_Read_ID_Fail          "Rear_Camera_Test_Read_ID_Fail"
#define FunErr_Rear_Camera_Test_Shading_Fail          "Rear_Camera_Test_Shading_Fail"
#define FunErr_Rear_Camera_Test_Blemish_Fail          "Rear_Camera_Test_Blemish_Fail"
#define FunErr_Rear_Camera_Test_MTF_Fail              "Rear_Camera_Test_MTF_Fail"
#define FunErr_Rear_Camera_Test_Tile_Fail             "Rear_Camera_Test_Tile_Fail"
#define FunErr_Rear_Camera_Test_Rotation_Fail         "Rear_Camera_Test_Rotation_Fail"
#define FunErr_Rear_Camera_Test_Color_Fail            "Rear_Camera_Test_Color_Fail"
#define FunErr_Camera_Reset_PictureIndex_Fail         "Reset_PictureIndex_Fail"
#define FunErr_Rear_Camera_Test_Macro_Capture_Fail    "Rear_Camera_Test_Macro_Capture_Fail"
#define FunErr_Rear_Camera_Test_Shutdown_Fail         "Rear_Camera_Test_Shutdown_Fail"
#define FunErr_Front_Camera_Color_Shading_Fail        "Front_Camera_Color_Shading_Fail"
#define FunErr_Rear_Camera_Color_Shading_Fail         "Rear_Camera_Color_Shading_Fail"
#define FunErr_Camera_SendKeyEvent_Fail               "Camera_SendKeyEvent_Fail"
#define FunErr_Camera_Test_Fail                       "Camera_Test_Fail"
#define FunErr_Camera_Launch_APP_Fail                 "Camera_Launch_APP_Fail"
#define FunErr_Rear_Camera_Test_Macro_MTF_Fail        "Rear_Camera_Test_Macro_MTF_Fail"
#define FunErr_Rear_Camera_Test_OTP_AWB_Fail          "Rear_Camera_Test_Read_OTP_AWB_Fail"
#define FunErr_Rear_Camera_Test_OTP_AFMacro_Fail      "Rear_Camera_Test_Read_OTP_AFMacro_Fail"
#define FunErr_Rear_Camera_Test_OTP_AFInfinity_Fail   "Rear_Camera_Test_Read_OTP_AFInfinity_Fail"
#define FunErr_Camera_Flashlight_Disable_Fail         "Camera_Flashlight_Disable_Fail"
#define FunErr_Camera_Flashlight_Enable_Fail          "Camera_Flashlight_Enable_Fail"
#define FunErr_Camera_OIS_Enable_Fail                 "Camera_OIS_Enable_Fail"
#define FunErr_Camera_OIS_Disable_Fail                "Camera_OIS_Disable_Fail"
#define FunErr_Rear_Camera_Test_Flash_Fail            "Rear_Camera_Test_Flash_Fail"
#define FunErr_Rear_Camera_Test_OIS_Fail              "Rear_Camera_Test_OIS_Fail"
#define FunErr_Switch_Camera_Fail                     "Switch_Camera_Fail"
#define FunErr_Camera_Scan_Barcode_Fail               "Camera_Scan_Barcode_Fail"
#define FunErr_Camera_AutoFocus_Fail                  "Camera_AutoFocus_Fail"
//**Touch
#define FunErr_Touch_ID_Test_Fail                               "Touch_ID_Test_Fail"
#define FunErr_Touch_Calibration_Fail                           "Touch_Calibration_Fail"
#define FunErr_Touch_Test_IDAC_Fail                             "Touch_Test_IDAC_Fail"
#define FunErr_Touch_Test_Delta_Fail                            "Touch_Test_Delta_Fail"
#define FunErr_Touch_Test_Baseline_Fail                         "Touch_Test_Baseline_Fail"
#define FunErr_Touch_Test_Finger_ID_Out_Of_Setting              "Touch_Test_Finger_ID_Out_Of_Setting"
#define FunErr_Touch_Test_Point_Out_Of_Setting                  "Touch_Test_Point_Out_Of_Setting"
#define FunErr_Touch_Test_Event_Type_M_Occur_Without_T_Before   "Touch_Test_Event_Type_M_Occur_Without_T_Before"
#define FunErr_Touch_Test_Event_Type_R_Occur_Without_T_Before   "Touch_Test_Event_Type_R_Occur_Without_T_Before"
#define FunErr_Touch_Test_Undefined_Event_Type                  "Touch_Test_Undefined_Event_Type"
#define FunErr_Touch_Test_No_Mapped_Line                        "Touch_Test_No_Mapped_Line"
#define FunErr_Touch_Test_Broken_Line                           "Touch_Test_Broken_Line"
#define FunErr_Touch_Download_Firmware_Fail                     "Touch_Download_Firmware_Fail"
#define FunErr_Touch_General_Fail                               "Touch_General_Fail"
#define FunErr_Touch_Check_Range_Fail                           "Touch_Check_Range_Fail"
#define FunErr_Touch_Auto_Check_Fail                            "Touch_Auto_Check_Fail"
#define FunErr_Touch_Pin_Fail                                   "Touch_Pin_Fail"
#define FunErr_Touch_Panel_Fail                                 "Touch_Panel_Fail"
#define FunErr_Touch_Capkey_Fail                                "Touch_Capkey_Fail"
#define FunErr_Touch_Enable_Fail                                "Touch_Enable_Fail"
#define FunErr_Touch_Disable_Fail                               "Touch_Disable_Fail"
#define FunErr_Touch_Slider_Test_Fail                           "Touch_Slider_Test_Fail"
#define FunErr_Touch_Keypad_Test_Fail                           "Touch_Keypad_Test_Fail"
#define FunErr_Touch_Self_Test_Fail                             "Touch_Self_Test_Fail"
#define FunErr_Touch_Write_Flag_Fail                            "Touch_Write_Flag_Fail"
#define FunErr_Get_Touch_FW_Fail                                "Get_Touch_FW_Fail"
#define FunErr_Check_Touch_FW_Fail                              "Check_Touch_FW_Fail"
//**SD Card
#define FunErr_Detect_SD_Fail                      "Detect_SD_Fail"
#define FunErr_SD_Mount_Fail                       "SD_Mount_Fail"
#define FunErr_Select_SD_Fail                      "Select_SD_Fail"
#define FunErr_SD_UnMount_Fail                     "SD_UnMount_Fail"
#define FunErr_Get_SD_Size_Fail                    "Get_SD_Size_Fail"
#define FunErr_SD_Operate_Fail                     "SD_Operate_Fail"
#define FunErr_SD_ReadWrite_Data_Fail              "SD_ReadWrite_Data_Fail"
#define FunErr_SD_Write_Protect_Test_Fail          "SD_Write_Protect_Test_Fail"
//**LED
#define FunErr_LED_Test_Fail                     "LED_Test_Fail"
#define FunErr_CapKey_LED_Test_Fail              "CapKey_LED_Test_Fail"
#define FunErr_Flash_LED_Test_Fail               "Flash_LED_Test_Fail"
#define FunErr_Green_Power_LED_Test_Fail         "Green_Power_LED_Test_Fail"
#define FunErr_Red_Power_LED_Test_Fail           "Red_Power_LED_Test_Fail"
#define FunErr_Flash_LED_ID_Fail                 "Flash_LED_ID_Fail"
#define FunErr_Blue_Power_LED_Test_Fail          "Blue_Power_LED_Test_Fail"
#define	FunErr_Flash_RGB_LED_ID_Fail                 "Flash_RGB_LED_ID_Test_Fail"
//**SIM card
#define FunErr_Detect_SIM_Card_Fail              "Detect_SIM_Card_Fail"
//**L-Sensor
#define FunErr_LSensor_Check_ID_Fail                      "LSensor_Check_ID_Fail"
#define FunErr_LSensor_Range_Check_Fail                   "LSensor_Range_Check_Fail"
#define FunErr_LSensor_Data_Equaul_With_Two_Situation     "LSensor_Data_Equaul_With_Two_Situation"
#define FunErr_LSensor_Calibration_Fail                   "LSensor_Calibration_Fail"
#define FunErr_LSensor_Verification_Fail                  "LSensor_Verification_Fail"
#define FunErr_LSensor_LuxCheck_Fail                      "LSensor_LuxCheck_Fail"
//**P-Sensor
#define FunErr_PSensor_Check_ID_Fail                      "PSensor_Check_ID_Fail"
#define FunErr_PSensor_Range_Check_Fail                   "PSensor_Range_Check_Fail"
#define FunErr_PSensor_Data_Equaul_With_Two_Situation     "PSensor_Data_Equaul_With_Two_Situation"
#define FunErr_PSensor_Calibration_Fail                   "PSensor_Calibration_Fail"
#define FunErr_PSensor_Verification_Fail                  "PSensor_Verification_Fail"
#define FunErr_PSensor_Proximity_Test_Fail                "PSensor_Proximity_Test_Fail"
//**G-Sensor
#define FunErr_GSensor_Calibration_Fail                  "GSensor_Calibration_Fail"
#define FunErr_GSensor_Test_Fail                         "GSensor_Test_Fail"
#define FunErr_GSensor_ID_Fail                           "GSensor_ID_Fail"
#define FunErr_GSensor_SelfTest_Fail                     "GSensor_SelfTest_Fail"
//**Speaker
#define FunErr_Speaker_Amp_Test_Fail               "Speaker_Amp_Test_Fail"
#define FunErr_Speaker_L_Test_Fail                 "Speaker_L_Test_Fail"
#define FunErr_Speaker_R_Test_Fail                 "Speaker_R_Test_Fail"
#define FunErr_Switch_Speaker_Fail                 "Switch_Speaker_Fail"
#define FunErr_Speaker_Play_Fail                   "Speaker_Play_Fail"
#define FunErr_Speaker_Play_Stop_Fail              "Speaker_Play_Stop_Fail"
#define FunErr_Speaker_Loud_Test_Fail              "Speaker_Loud_Test_Fail"
#define FunErr_Analyse_Speaker_Frequence_Fail      "Analyse_Speaker_Frequence_Fail"
#define FunErr_Analyse_Speaker_VPP_Fail            "Analyse_Speaker_VPP_Fail"
#define FunErr_Speaker2_Play_Fail                  "Speaker2_Play_Fail"
#define FunErr_Speaker1_Test_Fail                  "Speaker1_Test_Fail"
#define FunErr_Speaker2_Test_Fail                  "Speaker2_Test_Fail"
//**Receiver
#define FunErr_Switch_Receiver_Fail                "Switch_Receiver_Fail"
#define FunErr_Receiver_Play_Fail                  "Receiver_Play_Fail"
#define FunErr_Receiver_Play_Stop_Fail             "Receiver_Play_Stop_Fail"
#define FunErr_Receiver_Test_Fail                  "Receiver_Test_Fail"
#define FunErr_Analyse_Receiver_Frequence_Fail     "Analyse_Receiver_Frequence_Fail"
#define FunErr_Analyse_Receiver_VPP_Fail           "Analyse_Receiver_VPP_Fail"
//**Mic
#define FunErr_Mic_Record_Wav_Fail                "Mic_Record_Wav_Fail"
#define FunErr_Switch_Mic_Fail                    "Switch_Mic_Fail"
#define FunErr_Mic_Record_Chip_ID_Fail            "Mic_Record_Chip_ID_Fail"
#define FunErr_Mic2_Stop_Record_Fail              "Mic2_Stop_Record_Fail"
#define FunErr_Mic_Stop_Record_Fail               "Mic_Stop_Record_Fail"
#define FunErr_Mic2_Record_Wav_Fail               "Mic2_Record_Wav_Fail"
#define FunErr_Switch_Mic2_Fail                   "Switch_Mic2_Fail"
#define FunErr_Mic_Test_Fail                      "Mic_Test_Fail"
#define FunErr_Mic2_Test_Fail                     "Mic2_Test_Fail"
#define FunErr_Loopback_Mic_To_Speaker_Fail       "Loopback_Mic_To_Speaker_Fail"
#define FunErr_Loopback_Mic_To_Headset_Fail       "Loopback_Mic_To_Headset_Fail"
#define FunErr_Loopback_Mic2_To_Headset_Fail      "Loopback_Mic2_To_Headset_Fail"
#define FunErr_Mic_Bias_Fail                      "Mic_Bias_Fail"
#define FunErr_Mic2_Bias_Fail                     "Mic2_Bias_Fail"
#define FunErr_Loopback_Mic2_To_Receiver_Fail     "Loopback_Mic2_To_Receiver_Fail"
#define FunErr_Mic3_Test_Fail                     "Mic3_Test_Fail"       
#define FunErr_Mic4_Test_Fail                     "Mic4_Test_Fail"
#define FunErr_Mic3_Stop_Record_Fail              "Mic3_Stop_Record_Fail"
#define FunErr_Mic4_Stop_Record_Fail              "Mic4_Stop_Record_Fail"
#define FunErr_Loopback_Mic3_To_Headset_Fail      "Loopback_Mic3_To_Headset_Fail"
#define FunErr_Loopback_Mic4_To_Headset_Fail      "Loopback_Mic4_To_Headset_Fail"
#define FunErr_Loopback_Mic2_To_Speaker_Fail      "Loopback_Mic2_To_Speaker_Fail"

//**Headset
#define FunErr_Detect_Headset_Fail                  "Detect_Headset_Fail"
#define FunErr_No_Headset_But_Detect_It             "No_Headset_But_Detect_It"
#define FunErr_Headset_Send_Key_Fail                "Headset_Send_Key_Fail"
#define FunErr_Headset_Mic_Fail                     "Headset_Mic_Fail"
#define FunErr_Headset_Play_Fail_or_Mic_exception   "Headset_Play_Fail_or_Mic_exception"
#define FunErr_Headset_L_Test_Fail                  "Headset_L_Test_Fail"
#define FunErr_Headset_R_Test_Fail                  "Headset_R_Test_Fail"
#define FunErr_Switch_Headset_Fail                  "Switch_Headset_Fail"
#define FunErr_Headset_Switch_Mic_Fail              "Headset_Switch_Mic_Fail"
#define FunErr_Headset_Switch_Speaker_Fail          "Headset_Switch_Speaker_Fail"
#define FunErr_Headset_Mic_Stop_Record_Fail         "Headset_Mic_Stop_Record_Fail"
#define FunErr_Headset_Speaker_Play_Stop_Fail       "Headset_Speaker_Play_Stop_Fail"
#define FunErr_Headset_Speaker_Test_Fail            "Headset_Speaker_Test_Fail"
#define FunErr_Headset_Test_Fail                    "Headset_Test_Fail"
#define FunErr_Loopback_Headmic_To_Headset_Fail     "Loopback_Headmic_To_Headset_Fail"
#define FunErr_Analyse_Headset_Frequence_Fail       "Analyse_Headset_Frequence_Fail"
#define FunErr_Analyse_Headset_VPP_Fail             "Analyse_Headset_VPP_Fail"
#define FunErr_Headset_Timeout_Fail                 "Headset_Timeout_Fail"
#define FunErr_Headset_Calibration_Fail             "Headset_Calibration_Fail"
#define FunErr_Headset_Info_Fail                    "Read_Headset_Info_Fail"
#define FunErr_Loopback_Headmic_To_Receiver_Fail    "Loopback_Headmic_To_Receiver_Fail"
#define FunErr_Headset_Play_Fail                    "Headset_Play_Fail"
//**Current
#define FunErr_USB_Charging_Current_Test_Fail        "USB_Charging_Current_Test_Fail"
#define FunErr_HC_Charging_Current_Test_Fail         "HC_Charging_Current_Test_Fail"
#define FunErr_LCD_Off_Current_Test_Fail             "LCD_Off_Current_Test_Fail"
#define FunErr_Sleep_Current_Test_Fail               "Sleep_Current_Test_Fail"
#define FunErr_Boot_Current_Test_Fail                "Boot_Current_Test_Fail"
#define FunErr_Leakage_Current_Test_Fail             "Leakage_Current_Test_Fail"
//**Audio
#define FunErr_Audio_Test_Fail                              "Audio_Test_Fail"
#define FunErr_Collect_Audio_Fail                           "Collect_Audio_Fail"
#define FunErr_Analyse_Collected_Audio_Fail                 "Analyse_Collected_Audio_Fail"
#define FunErr_Audio_PC_Play_Wav_Fail                       "Audio_Test_PC_Play_Wav_Fail"
#define FunErr_Audio_Push_Wav_Fail                          "Audio_Test_Push_Wav_Fail"
#define FunErr_Audio_ID_Fail                                "Audio_ID_Fail"
#define FunErr_Audio_Mic_Speaker_Analyse_Collected_Fail                 "Audio_Mic_Speaker_Analyse_Collected_Fail"
#define FunErr_Audio_Mic_Receiver_Analyse_Collected_Fail                "Audio_Mic_Receiver_Analyse_Collected_Fail"
#define FunErr_Audio_Hankset_Mic_L_Speaker_Analyse_Collected_Fail       "Audio_Hankset_Mic_L_Speaker_Analyse_Collected_Fail"
#define FunErr_Audio_Hankset_Mic_R_Speaker_Analyse_Collected_Fail       "Audio_Hankset_Mic_R_Speaker_Analyse_Collected_Fail"
#define FunErr_Audio_Mic2_Speaker_Analyse_Collected_Fail                "Audio_Mic2_Speaker_Analyse_Collected_Fail"
//**LCD
#define FunErr_LCD_Backlight_Test_Fail           "LCD_Backlight_Test_Fail"
#define FunErr_LCD_Display_Fail                  "LCD_Display_Fail"
#define FunErr_Set_Backlight_Fail                "Set_LCD_Backlight_Fail"
//**Gauge
#define FunErr_Guage_IC_Check_Fail               "Guage_IC_Check_Fail"
#define FunErr_Guage_IC_DFI_Calibration_Fail     "Guage_IC_DFI_Calibration_Fail"
#define FunErr_Check_DFI_Enable_Status_Fail      "Check_DFI_Enable_Status_Fail"
#define FunErr_Enable_Gauge_DFI_IT_Fail          "Enable_Gauge_DFI_IT_Fail"
#define FunErr_Guage_ID_Fail                     "Guage_ID_Fail"            
#define FunErr_DFI_Version_Check_Fail            "DFI_Version_Check_Fail"
//**NFC
#define FunErr_NFC_Test_Fail                     "NFC_Test_Fail"
#define FunErr_Check_NFC_Upgrade_Fail            "Check_NFC_Upgrade_Fail"
#define FunErr_NFC_Card_Mode_Fail                "NFC_Card_Mode_Fail"
#define FunErr_NFC_Read_Mode_Fail                "NFC_Read_Mode_Fail"
#define FunErr_NFC_Read_Mode_Type1_Fail          "NFC_Read_Mode_Type1_Fail"
#define FunErr_NFC_Read_Mode_Type2_Fail          "NFC_Read_Mode_Type2_Fail"
#define FunErr_NFC_Read_Mode_Type4_Fail          "NFC_Read_Mode_Type4_Fail"
#define FunErr_NFC_Card_Mode_0cm_PowerOn_Fail    "NFC_Card_Mode_0cm_PowerOn_Fail"
#define FunErr_NFC_Card_Mode_0cm_PowerOff_Fail   "NFC_Card_Mode_0cm_PowerOff_Fail"
#define FunErr_NFC_Card_Mode_4cm_PowerOn_Fail    "NFC_Card_Mode_4cm_PowerOn_Fail"
#define FunErr_NFC_Card_Mode_4cm_PowerOff_Fail   "NFC_Card_Mode_4cm_PowerOff_Fail"
#define FunErr_NFC_Chip_ID_Fail                  "NFC_Chip_ID_Fail"
#define FunErr_NFC_FW_Version_Fail               "NFC_FW_Version_Fail"
#define FunErr_NFC_Antenna_Selftest_Fail         "NFC_Antenna_Selftest_Fail"
#define FunErr_NFC_SWP_Selftest_Fail             "NFC_SWP_Selftest_Fail"
#define FunErr_NFC_Card_Mode_2cm_PowerOff_Fail   "NFC_Card_Mode_2cm_PowerOff_Fail"
//VIBRATOR
#define FunErr_Vibrator_Test_Fail                "Vibrator_Test_Fail"
//Memory
#define FunErr_Check_eMMC_Fail                   "Check_eMMC_Fail"
#define FunErr_DDR_ReadWrite_Data_Fail           "DDR_ReadWrite_Data_Fail"
#define FunErr_DDR_Size_Fail                     "DDR_Size_Fail"
#define FunErr_Flash_ReadWrite_Data_Fail         "Flash_ReadWrite_Data_Fail"
//**Ecompass
#define FunErr_ECompassr_Test_Fail               "ECompassr_Test_Fail"
#define FunErr_ECompassr_ID_Fail                 "ECompassr_ID_Fail"
#define FunErr_ECompass_SelfTest_Fail            "ECompass_SelfTest_Fail"
//**SBL
#define FunErr_SBL_Booting_Fail                  "SBL_Booting_Fail"
//**PMIC
#define FunErr_PMIC_ID_Fail                      "PMIC_ID_Fail"
//**Gyro
#define FunErr_Gyro_ID_Fail                      "Gyro_ID_Fail"
#define FunErr_Gyro_Sensor_Test_Fail             "Gyro_Sensor_Test_Fail"
#define FunErr_Gyro_Sensor_SelfTest_Fail         "Gyro_Sensor_SelfTest_Fail"
//**CPU
#define FunErr_Check_CPU_Version_Fail            "Check_CPU_Version_Fail"
//**RF_chip
#define FunErr_RFChip_ID_Fail                    "RFChip_ID_Fail"
//**RTC
#define FunErr_RTC_Set_Fail                      "RTC_Set_Fail"
#define FunErr_RTC_Test_Fail                     "RTC_Test_Fail"
//**Capkey
#define FunErr_Capkey_ID_Fail                    "Capkey_ID_Fail"
#define FunErr_Capkey_Sensitivity_Check_Fail     "Capkey_Sensitivity_Check_Fail"
//**Keypad
#define FunErr_Keypad_Test_Fail                  "Keypad_Test_Fail"
#define FunErr_Sidekey_Test_Fail                 "SideKey_Test_Fail"
#define FunErr_VolumeUpKey_Test_Fail             "VolumeUpKey_Test_Fail"
#define FunErr_VolumeDownKey_Test_Fail           "VolumeDownKey_Test_Fail"
#define FunErr_PowerKey_Test_Fail                "PowerKey_Test_Fail"
//**HDMI
#define FunErr_HDMI_Test_Fail                    "HDMI_Test_Fail"
//**MHL
#define FunErr_MHL_ID_Check_Fail                 "MHL_ID_Check_Fail"
//**Codec
#define FunErr_Codec_ID_Check_Fail               "Codec_ID_Check_Fail"
//**Run in
#define FunErr_Run_In_Fail                       "Run_In_Fail"
//**Browser_Test error
#define	FunErr_Browser_Test_Fail                 "Browser_Test_Fail"
//**LCM Control Panel
#define	FunErr_Check_LCM_Control_Panel_Fail      "Check_LCM_Control_Panel_Fail"
//**GPIO_Test error
#define	FunErr_GPIO_Test_Fail                    "GPIO_Test_Fail"
//**Ethernet_Test error
#define	FunErr_Ethernet_Loopback_Test_Fail       "Ethernet_Loopback_Test_Fail"
#define	FunErr_Ethernet_Connection_Test_Fail     "Ethernet_Connection_Test_Fail"
//**UART_Test_Fail
#define	FunErr_UART_Test_Fail                    "UART_Test_Fail"
//**USB_Test error
#define	FunErr_USB_HOST_Test_Fail                "USB_HOST_Test_Fail"

#endif //_FUNCTION_ERRORDEFINE_H