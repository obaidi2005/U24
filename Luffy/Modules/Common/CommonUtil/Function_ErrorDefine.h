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
#define FunErr_BT_EM_Test_Fail         			 "BT_EM_Test_Fail"
#define FunErr_BT_MODULATION_CHARACTERISTIC_FAIL "BT_MODULATION_CHARACTERISTIC_FAIL"
#define FunErr_BT_ICFT_FAIL                      "BT_ICFT_FAIL"
#define FunErr_BT_CARRIER_DRIFT_FAIL             "BT_CARRIER_DRIFT_FAIL"
#define FunErr_BT_EDR_FREQ_STAB_MOD_ACC_FAIL     "BT_EDR_FREQ_STAB_MOD_ACC_FAIL"
#define FunErr_BT_EDR_DIFF_PHASE_ENCODING_FAIL   "BT_EDR_DIFF_PHASE_ENCODING_FAIL"
#define FunErr_BT_SINGLESLOT_SENSITIVITY_FAIL    "BT_SINGLESLOT_SENSITIVITY_FAIL"
#define FunErr_BT_MULTISLOT_SENSITIVITY_FAIL     "BT_MULTISLOT_SENSITIVITY_FAIL"
#define FunErr_BT_MAX_USABLE_SIGNAL_LEVEL_FAIL   "BT_MAX_USABLE_SIGNAL_LEVEL_FAIL"
#define FunErr_BT_EDR_SENSITIVITY_FAIL           "BT_EDR_SENSITIVITY_FAIL"
#define FunErr_BT_EDR_BER_FLOOR_FAIL             "BT_EDR_BER_FLOOR_FAIL"
#define FunErr_BT_EDR_MAX_INPUT_LEVEL_FAIL       "BT_EDR_MAX_INPUT_LEVEL_FAIL"
#define FunErr_BT_POWER_CONTROL_FAIL             "BT_POWER_CONTROL_FAIL"
#define FunErr_BT_EDR_RELATIVE_POWER_FAIL        "BT_EDR_RELATIVE_POWER_FAIL"
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
#define FunErr_WLAN_EM_Test_Fail         		   "WLAN_EM_Test_Fail"
#define FunErr_WLAN_EVM_FAIL					   "WLAN_EVM_FAIL"
#define FunErr_WLAN_CARRIER_SUPPRESION_FAIL		   "WLAN_CARRIER_SUPPRESION_FAIL"
#define FunErr_WLAN_FREQ_ERROR_FAIL                "WLAN_FREQ_ERROR_FAIL"
#define FunErr_WLAN_DEMOD_FAIL                     "WLAN_DEMOD_FAIL"
#define FunErr_WLAN_POWER_RAMP_FAIL                "WLAN_POWER_RAMP_FAIL"
#define FunErr_WLAN_SPECTRAL_MASK_FAIL             "WLAN_SPECTRAL_MASK_FAIL"
#define FunErr_WLAN_SPECTRAL_FLATNESS_FAIL         "WLAN_SPECTRAL_FLATNESS_FAIL"
#define FunErr_WLAN_RX_MINSENS_FAIL                "WLAN_RX_MINSENS_FAIL"
//**GPS
#define FunErr_GPS_Test_Init_Device_Fail          "GPS_Test_Init_Device_Fail"
#define FunErr_GPS_Test_Set_Command_Fail          "GPS_Test_Set_Command_Fail"
#define FunErr_GPS_Test_CN0_OutRange              "GPS_Test_CN0_OutRange"
//**WirelessGSM	
#define FunErr_WirelessGSM_Test_Set_Command_Fail	"WirelessGSM_Test_Set_Command"
#define FunErr_WirelessGSM_Test_Init_Device_Fail	"WirelessGSM_Test_Init_Device"
#define FunErr_WirelessGSM_Test_OutPower_OutRange	"WirelessGSM_Test_OutPower"
#define FunErr_WirelessGSM_Online_Call_Fail         "WirelessGSM_Online_Call"
#define FunErr_WirelessGSM_Online_BER_OutRange	    "WirelessGSM_Online_BER"
#define FunErr_WirelessGSM_Online_RSSI_OutRange	    "WirelessGSM_Online_RSSI"
#define FunErr_WirelessGSM_Online_EndCall_Fail	    "WirelessGSM_Online_EndCall"
#define FunErr_WirelessGSM_Online_Handover_Fail     "WirelessGSM_Online_Handover"
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
//**WirelessWCDMA	
#define FunErr_WirelessWCDMA_Test_Set_Command_Fail	  "WirelessWCDMA_Test_Set_Command"
#define FunErr_WirelessWCDMA_Test_Init_Device_Fail	  "WirelessWCDMA_Test_Init_Device"
#define FunErr_WirelessWCDMA_Test_OutPower_OutRange	  "WirelessWCDMA_Test_OutPower"
#define FunErr_WirelessWCDMA_Online_Call_Fail	      "WirelessWCDMA_Online_Call"
#define FunErr_WirelessWCDMA_Online_BER_OutRange	  "WirelessWCDMA_Online_BER"
#define FunErr_WirelessWCDMA_Online_RSCP_OutRange	  "WirelessWCDMA_Online_RSCP"
#define FunErr_WirelessWCDMA_Online_EndCall_Fail	  "WirelessWCDMA_Online_EndCall"
#define FunErr_WirelessWCDMA_Online_Handover_Fail	  "WirelessWCDMA_Online_Handover"
#define FunErr_WirelessWCDMA_Get_PhoneMode_Fail       "WirelessWCDMA_Get_PhoneMode_Fail"
#define FunErr_WirelessWCDMA_Fetch_Max_Power_Fail     "WirelessWCDMA_Fetch_Max_Power_Fail"
#define FunErr_WirelessWCDMA_Set_Band_CH_Fail         "WirelessWCDMA_Set_Band_CH_Fail"
#define FunErr_WirelessWCDMA_Set_PhoneMode_Fail       "WirelessWCDMA_Set_PhoneMode_Fail"
#define FunErr_WirelessWCDMA_Set_PhoneBand_Fail       "WirelessWCDMA_Set_PhoneBand_Fail"
#define FunErr_WirelessWCDMA_Set_PhoneCH_Fail         "WirelessWCDMA_Set_PhoneCH_Fail"
#define FunErr_WirelessWCDMA_Set_PA_Range_Fail        "WirelessWCDMA_Set_PA_Range_Fail"
#define FunErr_WirelessWCDMA_Set_WAVE_Fail            "WirelessWCDMA_Set_WAVE_Fail"
#define FunErr_WirelessWCDMA_Set_TX_PDM_Fail          "WirelessWCDMA_Set_TX_PDM_Fail"
#define FunErr_WirelessWCDMA_Get_TX_PDM_Fail          "WirelessWCDMA_Get_TX_PDM_Fail"
#define FunErr_WirelessWCDMA_Set_TX_ONOFF_Fail        "WirelessWCDMA_Set_TX_ONOFF_Fail"
//**WirelessCDMA200
#define FunErr_WirelessCDMA2000_Get_PhoneMode_Fail       "WirelessCDMA2000_Get_PhoneMode_Fail"
#define FunErr_WirelessCDMA2000_Fetch_Max_Power_Fail     "WirelessCDMA2000_Fetch_Max_Power_Fail"
#define FunErr_WirelessCDMA2000_Set_Band_CH_Fail         "WirelessCDMA2000_Set_Band_CH_Fail"
#define FunErr_WirelessCDMA2000_Set_TX_ONOFF_Fail        "WirelessCDMA2000_Set_TX_ONOFF_Fail"
#define FunErr_WirelessCDMA2000_Get_PDM_NV_Fail          "WirelessCDMA2000_Get_PDM_NV_Fail"
#define FunErr_WirelessCDMA2000_Test_Init_Device_Fail	 "WirelessCDMA2000_Test_Init_Device_Fail"
#define FunErr_WireleseCDMA2000_Test_OutPower_OutRange	 "WirelessCDMA2000_Test_OutPower"
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
#define FunErr_Rear_Camera_Test_Macro_Capture_Fail           "Rear_Camera_Test_Macro_Capture_Fail"
#define FunErr_Rear_Camera_Test_Shutdown_Fail                "Rear_Camera_Test_Shutdown_Fail"
#define FunErr_Front_Camera_Color_Shading_Fail               "Front_Camera_Color_Shading_Fail"
#define FunErr_Rear_Camera_Color_Shading_Fail                "Rear_Camera_Color_Shading_Fail"
#define FunErr_Camera_SendKeyEvent_Fail				         "Camera_SendKeyEvent_Fail"
#define FunErr_Camera_Test_Fail                              "Camera_Test_Fail"
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
#define FunErr_Touch_Enable_Fail								"Touch_Enable_Fail"
#define FunErr_Touch_Disable_Fail								"Touch_Disable_Fail"
#define FunErr_Touch_Slider_Test_Fail         	 		        "Touch_Slider_Test_Fail"
#define FunErr_Touch_Keypad_Test_Fail         			        "Touch_Keypad_Test_Fail"
//**SD Card
#define FunErr_Detect_SD_Fail           "Detect_SD_Fail"
#define FunErr_SD_Mount_Fail            "SD_Mount_Fail"
#define FunErr_Select_SD_Fail           "Select_SD_Fail"
#define FunErr_SD_UnMount_Fail          "SD_UnMount_Fail"
#define FunErr_Get_SD_Size_Fail         "Get_SD_Size_fail"
//**LED
#define FunErr_LED_Test_Fail                     "LED_Test_Fail"
#define FunErr_CapKey_LED_Test_Fail              "CapKey_LED_Test_Fail"
#define FunErr_Flash_LED_Test_Fail               "Flash_LED_Test_Fail"
#define FunErr_Green_Power_LED_Test_Fail         "Green_Power_LED_Test_Fail"
#define FunErr_Red_Power_LED_Test_Fail           "Red_Power_LED_Test_Fail"
#define FunErr_Flash_LED_ID_Fail                 "Flash_LED_ID_Fail"            
//**SIM card
#define FunErr_Detect_SIM_Card_Fail              "Detect_SIM_Card_Fail"
//**L-Sensor
#define FunErr_LSensor_Check_ID_Fail                      "LSensor_Check_ID_Fail"
#define FunErr_LSensor_Range_Check_Fail                   "LSensor_Range_Check_Fail"
#define FunErr_LSensor_Data_Equaul_With_Two_Situation     "LSensor_Data_Equaul_With_Two_Situation"
#define FunErr_LSensor_Calibration_Fail                   "LSensor_Calibration_Fail"
#define FunErr_LSensor_Verification_Fail                  "LSensor_Verification_Fail"
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
//**Speaker
#define FunErr_Speaker_Amp_Test_Fail              "Speaker_Amp_Test_Fail"
#define FunErr_Speaker_L_Test_Fail                "Speaker_L_Test_Fail"
#define FunErr_Speaker_R_Test_Fail                "Speaker_R_Test_Fail"
#define FunErr_Switch_Speaker_Fail                "Switch_Speaker_Fail"
#define FunErr_Speaker_Play_Fail                  "Speaker_Play_Fail"
#define FunErr_Speaker_Play_Stop_Fail             "Speaker_Play_Stop_Fail"
#define FunErr_Speaker_Loud_Test_Fail             "Speaker_Loud_Test_Fail"
//**Receiver
#define FunErr_Switch_Receiver_Fail                "Switch_Receiver_Fail"
#define FunErr_Receiver_Play_Fail                  "Receiver_Play_Fail"
#define FunErr_Receiver_Play_Stop_Fail             "Receiver_Play_Stop_Fail"
#define FunErr_Receiver_Test_Fail                  "Receiver_Test_Fail"
//**Mic
#define FunErr_Mic_Record_Wav_Fail                  "Mic_Record_Wav_Fail"
#define FunErr_Switch_Mic_Fail                      "Switch_Mic_Fail"
#define FunErr_Mic_Record_Chip_ID_Fail              "Mic_Record_Chip_ID_Fail"
#define FunErr_Mic2_Stop_Record_Fail                "Mic2_Stop_Record_Fail"
#define FunErr_Mic_Stop_Record_Fail                 "Mic_Stop_Record_Fail"
#define FunErr_Mic2_Record_Wav_Fail                 "Mic2_Record_Wav_Fail"
#define FunErr_Switch_Mic2_Fail                     "Switch_Mic2_Fail"
#define FunErr_Mic_Test_Fail                   "Mic_Test_Fail"
#define FunErr_Mic2_Test_Fail                  "Mic2_Test_Fail"
#define FunErr_Loopback_Mic_To_Speaker_Fail    "Loopback_Mic_To_Speaker_Fail"
//**Headset
#define FunErr_Detect_Headset_Fail                  "Detect_Headset_Fail"
#define FunErr_No_Headset_But_Detect_It             "No_Headset_But_Detect_It"
#define FunErr_Headset_Send_Key_Fail                "Headset_Send_Key_Fail"
#define FunErr_Headset_Mic_Fail                     "Headset_Mic_Fail"
#define FunErr_Headset_Play_Fail_or_Mic_exception   "Headset_Play_Fail_or_Mic_exception"
#define FunErr_Headset_L_Test_Fail                  "Headset_L_Test_Fail"
#define FunErr_Headset_R_Test_Fail                  "Headset_R_Test_Fail"
#define FunErr_Switch_Headset_Fail                          "Switch_Headset_Fail"
#define FunErr_Headset_Switch_Mic_Fail                     "Headset_Switch_Mic_Fail"
#define FunErr_Headset_Switch_Speaker_Fail                     "Headset_Switch_Speaker_Fail"
#define FunErr_Headset_Mic_Stop_Record_Fail                     "Headset_Mic_Stop_Record_Fail"
#define FunErr_Headset_Speaker_Play_Stop_Fail                  "Headset_Speaker_Play_Stop_Fail"
#define FunErr_Headset_Speaker_Test_Fail             "Headset_Speaker_Test_Fail"
#define FunErr_Headset_Test_Fail                     "Headset_Test_Fail"
#define FunErr_Loopback_Headmic_To_Headset_Fail      "Loopback_Headmic_To_Headset_Fail"
//**Current
#define FunErr_USB_Charging_Current_Test_Fail        "USB_Charging_Current_Test_Fail"
#define FunErr_HC_Charging_Current_Test_Fail         "HC_Charging_Current_Test_Fail"
#define FunErr_LCD_Off_Current_Test_Fail             "LCD_Off_Current_Test_Fail"
#define FunErr_Sleep_Current_Test_Fail               "Sleep_Current_Test_Fail"
#define FunErr_Boot_Current_Test_Fail                "Boot_Current_Test_Fail"
#define FunErr_Leakage_Current_Test_Fail             "Leakage_Current_Test_Fail"
//**Audio
#define FunErr_Audio_Test_Fail                 "Audio_Test_Fail"
#define FunErr_Collect_Audio_Fail              "Collect_Audio_Fail"
#define FunErr_Analyse_Collected_Audio_Fail    "Analyse_Collected_Audio_Fail"
#define FunErr_Audio_PC_Play_Wav_Fail          "Audio_Test_PC_Play_Wav_Fail"
#define FunErr_Audio_Push_Wav_Fail             "Audio_Test_Push_Wav_Fail"
#define FunErr_Audio_ID_Fail                   "Audio_ID_Fail"            
#define FunErr_Audio_Speaker_Analyse_Collected_Fail                    "Audio_Speaker_Analyse_Collected_Fail"
#define FunErr_Audio_Receiver_Analyse_Collected_Fail                   "Audio_Receiver_Analyse_Collected_Fail"
#define FunErr_Audio_Hankset_L_Analyse_Collected_Fail                  "Audio_Hankset_L_Analyse_Collected_Fail"
#define FunErr_Audio_Hankset_R_Analyse_Collected_Fail                  "Audio_Hankset_R_Analyse_Collected_Fail"
//**LCD
#define FunErr_LCD_Backlight_Test_Fail           "LCD_Backlight_Test_Fail"
#define FunErr_LCD_Display_Fail                  "LCD_Display_Fail"
#define FunErr_Set_Backlight_Fail				 "Set_LCD_Backlight_Fail"
//**Gauge
#define FunErr_Guage_IC_Check_Fail               "Guage_IC_Check_Fail"
#define FunErr_Guage_IC_DFI_Calibration_Fail     "Guage_IC_DFI_Calibration_Fail"
#define FunErr_Check_DFI_Enable_Status_Fail      "Check_DFI_Enable_Status_Fail"
#define FunErr_Enable_Gauge_DFI_IT_Fail          "Enable_Gauge_DFI_IT_Fail"
#define FunErr_Guage_ID_Fail                     "Guage_ID_Fail"            
#define FunErr_DFI_Version_Check_Fail            "DFI_Version_Check_Fail"
//**NFC
#define FunErr_NFC_Test_Fail                  "NFC_Test_Fail"
#define FunErr_Check_NFC_Upgrade_Fail         "Check_NFC_Upgrade_Fail"
//VIBRATOR
#define FunErr_Vibrator_Test_Fail             "Vibrator_Test_Fail"
//Memory
#define FunErr_Check_eMMC_Fail                "Check_eMMC_Fail"
#define FunErr_DDR_ReadWrite_Data_Fail        "DDR_ReadWrite_Data_Fail"            
#define FunErr_DDR_Size_Fail                  "DDR_Size_Fail"  
//**Ecompass
#define FunErr_ECompassr_Test_Fail            "ECompassr_Test_Fail"
#define FunErr_ECompassr_ID_Fail              "ECompassr_ID_Fail"            
//**SBL
#define FunErr_SBL_Booting_Fail               "SBL_Booting_Fail"            
//**PMIC
#define FunErr_PMIC_ID_Fail                   "PMIC_ID_Fail"            
//**Gyro
#define FunErr_Gyro_ID_Fail                   "Gyro_ID_Fail"            
//**CPU
#define FunErr_Check_CPU_Version_Fail         "Check_CPU_Version_Fail"            
//**RF_chip
#define FunErr_RFChip_ID_Fail                 "RFChip_ID_Fail"            
//**RTC
#define FunErr_RTC_Set_Fail                                 "RTC_Set_Fail"                
#define FunErr_RTC_Test_Fail                                "RTC_Test_Fail"
//**Capkey
#define FunErr_Capkey_ID_Fail                               "Capkey_ID_Fail"
#define FunErr_Capkey_Sensitivity_Check_Fail                "Capkey_Sensitivity_Check_Fail"
//**Keypad
#define FunErr_Keypad_Test_Fail                             "Keypad_Test_Fail"
#define FunErr_Sidekey_Test_Fail                            "SideKey_Test_Fail"
//**HDMI
#define FunErr_HDMI_Test_Fail                               "HDMI_Test_Fail"
//**MHL				
#define FunErr_MHL_ID_Check_Fail                            "MHL ID Check Fail"
//**Codec				
#define FunErr_Codec_ID_Check_Fail                          "Codec ID Check Fail"

#endif //_FUNCTION_ERRORDEFINE_H