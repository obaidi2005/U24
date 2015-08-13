#ifndef _COMM_ERRORDEFINE_H
#define _COMM_ERRORDEFINE_H

#define CommErr_PASS                                         "PASS"
//**Software Version
#define CommErr_Get_Software_Version_Fail                    "Get_Software_Version_Fail"
#define CommErr_Check_Software_Version_Fail                  "Check_Software_Version_Fail"
#define CommErr_Check_BIST_Version_Fail                      "Check_BIST_Version_Fail"
//Hardware Version                       
#define CommErr_Get_Hardware_Version_Fail                    "Get_Hardware_Version_Fail"
#define CommErr_Check_Hardware_Version_Fail                  "Check_Hardware_Version_Fail"
#define CommErr_Get_Mechaical_Version_Fail                   "Get_Mechaical_Version_Fail" 
#define CommErr_Check_Mechaical_Version_Fail                 "Check_Mechaical_Version_Fail"
//HW ID                                  
#define CommErr_Get_HW_ID_Fail                               "Get_HW_ID_Fail"            
#define CommErr_Check_HW_ID_Fail                             "Check_HW_ID_Fail"
#define CommErr_Check_HW_ID_Rule_Fail                        "Check_HW_ID_Rule_Fail"
//**Read and Write FA                    
#define CommErr_Factory_Area_Not_Active                      "Factory_Area_Not_Active"
#define CommErr_Read_Factory_Area_Fail                       "Read_Factory_Area_Fail"    
#define CommErr_Write_Factory_Area_Fail                      "Write_Factory_Area_Fail"
#define CommErr_Read_MobileID_Fail                           "Read_MobileID_Fail"    
#define CommErr_Write_MobileID_Fail                          "Write_MobileID_Fail"
#define CommErr_Check_MobileID_Fail                          "Check_MobileID_Fail"
#define CommErr_Check_Picasso_Rule_Fail                      "Check_Picasso_Rule_Fail"
#define CommErr_Read_Picasso_Fail                            "Read_Picasso_Fail"    
#define CommErr_Write_Picasso_Fail                           "Write_Picasso_Fail"
#define CommErr_Check_Picasso_Fail                           "Check_Picasso_Fail"
#define CommErr_Picasso_NOT_IN_SMT                           "Picasso_NOT_in_SMT"
#define CommErr_Picasso_Duplicated                           "Picasso_Duplicated"
#define CommErr_Picasso_USED_Already                         "Picasso_USED_Already"
//**OTP                                  
#define CommErr_Query_OTP_Status_Fail                        "Query_OTP_Status_Fail"
#define CommErr_Freeze_OTP_Fail                              "Freeze_OTP_Fail"
#define CommErr_OTP_Damaged_Or_Warning                       "OTP_Damaged_Or_Warning"
//**SPC                                  
#define CommErr_Read_SPC_Code_Fail                           "Read_SPC_Code_Fail"
#define CommErr_Write_SPC_Code_Fail                          "Write_SPC_Code_Fail"
#define CommErr_SPC_Code_Error                               "SPC_Code_Error"
#define CommErr_SPC_Unlock_Fail                              "SPC_Unlock_Fail"
#define CommErr_SPC_lock_Fail                                "SPC_lock_Fail"
#define CommErr_Query_SPC_lock_Status_Fail                   "Query_SPC_lock_Status_Fail"
#define CommErr_Compare_SPC_Code_Fail                        "Compare_SPC_Code_Fail"
//**Sim data                             
#define CommErr_Encode_Sim_Data_Fail                         "Encode_Sim_Data_Fail"
#define CommErr_Write_Sim_Data_Fail                          "Write_Sim_Data_Fail"        
#define CommErr_Check_Sim_Data_Fail                          "Check_Sim_Data_Fail"        
#define CommErr_Write_Public_key_Fail                        "Write_Public_key_Fail"      
#define CommErr_Read_Public_key_Fail                         "Read_Public_key_Fail"       
#define CommErr_Compare_Public_key_Fail                      "Compare_Public_key_Fail" 
#define CommErr_SimLock_GetControlKey_Fail                   "SimLock_GetControlKey_Fail"          
#define CommErr_Unlock_PhoneCode_Fail                        "Unlock_PhoneCode_Fail"         
#define CommErr_Read_Sim_Data_Fail                           "Read_Sim_Data_Fail"         
#define CommErr_Activate_SimLock_Fail                        "Activate_SimLock_Fail"         
#define CommErr_Deactivate_SimLock_Fail                      "Deactivate_SimLock_Fail"         
//**PVK                                  
#define CommErr_Write_PVK_File_Fail                          "Write_PVK_File_Fail"        
#define CommErr_Load_PVK_File_Fail                           "Load_PVK_File_Fail"         
#define CommErr_Check_PVK_Status_Fail                        "Check_PVK_Status_Fail"      
#define CommErr_Decrypt_PVK_Fail                             "Decrypt_PVK_Fail"           
#define CommErr_No_PVK_File_Found                            "No_PVK_File_Found"          
//**phone                                
#define CommErr_No_Phone_Connected                           "No_Phone_Connected"         
#define CommErr_Connect_Phone_Fail_After_Sim_Data            "Connect_Phone_Fail_After_Sim_Data"       
#define CommErr_Connect_Phone_Fail_After_PVK_Reset           "Connect_Phone_Fail_After_PVK_Reset"      
#define CommErr_Close_Phone_Connection_Fail                  "Close_Phone_Connection_Fail"
#define CommErr_Reset_Phone_Fail                             "Reset_Phone_Fail"           
#define CommErr_Get_ADB_Fail                                 "Get_ADB_Fail"
#define CommErr_Set_Phone_To_Ftd_Mode_Fail                   "Set_Phone_To_Ftd_Mode_Fail" 
#define CommErr_Set_Phone_To_Online_Mode_Fail                "Set_Phone_To_Online_Mode_Fail"           
#define CommErr_Phone_Not_FTD                                "Phone_Not_In_FTM_Mode"  
#define CommErr_Phone_Restart_Fail                           "Phone_Restart_Fail"        
#define CommErr_Phone_Modem_Not_Ready_Fail                   "Phone_Modem_Not_Ready_Fail"
#define CommErr_Set_Phone_To_FTM_Mode_Fail                   "Set_Phone_To_FTM_Mode_Fail"
//**File
#define CommErr_Pull_File_From_Device_Fail                   "Pull_File_From_Device_Fail"
#define CommErr_Push_File_To_Device_Fail                     "Push_File_To_Device_Fail"
#define CommErr_Parse_File_Fail                              "Parse_File_Fail"
//**NV & EFS                                  
#define CommErr_Backup_NV_Fail                               "Backup_NV_Fail"             
#define CommErr_Restore_NV_Fail                              "Restore_NV_Fail"            
#define CommErr_Check_NV_Backup_Fail                         "Check_NV_Backup_Fail"
#define CommErr_Read_NV_Fail	                             "Read_NV_Fail"
#define CommErr_Write_NV_Fail	                             "Write_NV_Fail"             
#define CommErr_EFS_Sync_Fail                                "EFS_Sync_Fail"
//**Factroy Reset                        
#define CommErr_Master_Clear_Fail                            "Master_Clear_Fail"          
//**Qfuse                                
#define CommErr_Write_Qfuse_Fail                             "Write_Qfuse_Fail"           
#define CommErr_Read_Qfuse_Fail                              "Read_Qfuse_Fail"            
#define CommErr_Check_Qfuse_Fail                             "Check_Qfuse_Fail"           
//**others                               
#define CommErr_Load_DLL_Fail                                "Load_DLL_Fail"              
//**XML related                          
#define CommErr_XML_Testitem_Load_Fail                       "XML_Testitem_Load"          
#define CommErr_XML_Cableloss_Load_Fail                      "XML_Cableloss_Load"         
#define CommErr_XML_Deviceitem_Load_Fail                     "XML_Deviceitem_Load"       
#define CommErr_XML_Testitem_Parameter_Missed                "XML_Testitem_Parameter"     
#define CommErr_XML_Cableloss_Parameter_Missed               "XML_Cableloss_Parameter"    
#define CommErr_XML_Deviceitem_Parameter_Missed              "XML_Deviceitem_Parameter"   
//**PPID                                 
#define CommErr_Check_PPID_Length_Fail                       "PPID_Length_fail"           
#define CommErr_Check_PPID_Rule_Fail                         "PPID_rule_fail"             
#define CommErr_Write_PPID_Fail                              "PPID_write_fail"            
#define CommErr_Read_PPID_Fail                               "PPID_read_fail"             
#define CommErr_Check_PPID_Fail                              "PPID_check_fail"            
//**FSN                                  
#define CommErr_FSN_Length_Fail                              "FSN_Siez_fail"              
#define CommErr_Compare_MSN_Fail                             "Compare_FSN_Fail"           
#define CommErr_Read_FSN_Fail                                "Read_FSN_Fail"              
#define CommErr_Write_FSN_Fail                               "Write_FSN_Fail"             
#define CommErr_No_FSN_Record_in_DB                          "NO_FSN_Record_IN_DB"        
//**BT Address                           
#define CommErr_Read_BT_Address_Fail                         "Read_BT_Address_Fail"       
#define CommErr_Write_BT_Address_Fail                        "Write_BT_Address_Fail"      
#define CommErr_Compare_BT_Address_Fail                      "Compare_BT_Address_Fail"    
#define CommErr_Check_BT_Address_Length_Fail                 "Check_BT_Address_Length_Fail"            
//**WLAN Address                         
#define CommErr_Check_WLAN_Address_Length_Fail               "Check_WLAN_Address_Length_Fail"          
#define CommErr_Read_WLAN_Address_Fail                       "Read_WLAN_Address_Fail"     
#define CommErr_Write_WLAN_Address_Fail                      "Write_WLAN_Address_Fail"    
#define CommErr_Compare_WLAN_Address_Fail                    "Compare_WLAN_Address_Fail"  
//**IMEI                                 
#define CommErr_Check_IMEI_Rule_Fail                         "Check_IMEI_Rule_Fail"       
#define CommErr_Check_IMEI_Fail_In_Rework                    "Check_IMEI_Fail_In_Rework"  
#define CommErr_IMEI_Default_In_Phone_Error                  "IMEI_Default_In_Phone_Error"
#define CommErr_No_IMEI_In_Phone_When_rework                 "No_IMEI_In_Phone_When_rework"           
#define CommErr_IMEI_Status_In_P_S_Error                     "IMEI_Status_In_P_S_Error"   
#define CommErr_IMEI_Status_Error                            "IMEI_Status_Error"          
#define CommErr_Check_IMEI_Sequence_Fail                     "Check_IMEI_Sequence_Fail"   
#define CommErr_Read_IMEI_Fail                               "Read_IMEI_Fail"            
#define CommErr_Write_IMEI_Fail                              "Write_IMEI_Fail"            
#define CommErr_Check_IMEI_Fail                              "Compare_IMEI_Fail"          
//**SSSO2                                
#define CommErr_Initial_SSSO2_Fail                           "Initial_PICS_SSS02_fail"    
#define CommErr_Query_BT_WLAN_MSN_From_SSS_Fail              "Query_BT_WLAN_MSN_From_SSS_Fail"         
#define CommErr_Query_IMEI_Status_From_PICS_Fail             "Query_IMEI_Status_From_PICS_Fail"        
#define CommErr_Query_SPC_Code_From_PICS_Fail                "Query_SPC_Code_From_PICS_Fail"           
#define CommErr_Query_FSN_From_PICS_Fail                     "Query_FSN_From_PICS_Fail" 
#define CommErr_Create_FSN_From_PICS_Fail                    "Created_FSN_From_PICS_Fail" 
#define CommErr_Query_Unlock_key_From_PICS_Fail              "Query_Unlock_key_From_PICS_Fail"         
#define CommErr_Query_Sim_Data_From_PICS_Fail                "Query_Sim_Data_From_PICS_Fail"           
#define CommErr_Get_Sim_Data_Size_From_PICS_Fail             "Get_Sim_Data_Size_From_PICS_Fail"        
#define CommErr_Update_IMEI_Status_To_PICS_Fail              "Update_IMEI_Status_To_PICS_Fail"         
#define CommErr_Check_IMEI_PN_MAL_In_PICS_Fail               "Check_IMEI_PN_MAL_In_PICS_Fail"          
#define CommErr_Create_IMEI_Table_In_PICS_Fail               "Create_IMEI_Table_In_PICS_Fail"          
//**Serial Number                        
#define CommErr_Read_Serial_Number_Fail                      "Read_Serial_Number_Fail"    
#define CommErr_Write_Serial_Number_Fail                     "Write_Serial_Number_Fail"   
#define CommErr_Compare_Serial_Number_Fail                   "Compare_Serial_Number_Fail" 
//**NAL                                  
#define CommErr_Check_NAL_Rule_Fail                          "Check_NAL_Rule_Fail"        
#define CommErr_NAL_NOT_IN_DB                                "NAL_NOT_IN_DB"              
#define CommErr_NAL_Duplicated                               "NAL_DUPLICATED"             
#define CommErr_NAL_USED_Already                             "NAL_USED_ALREADY"           
//**DRM                                  
#define CommErr_Create_DRM_Fail                              "Create_DRM_Fail"            
#define CommErr_DRM_Backup_Fail                              "DRM_Backup_Fail"            
//**Device Control                       
#define CommErr_PowerSupply_Control_Fail                     "PowerSupply_Control_Fail"   
#define CommErr_RelayBoard_Control_Fail                      "RelayBoard_Control_Fail"    
#define CommErr_Jig_Move_Fail                                "Jig_Move_Fail"   
#define CommErr_Detect_CMU_Fail	                             "Detect_CMU_Fail"
//**RF relative
#define CommErr_Get_Channel_Type_Fail                           "Get_Channel_Type_Fail"
#define CommErr_No_Band_Define_Fail                             "No_Band_Define_Fail"
#define CommErr_LimFreq_Extra_RelativePDM_List_Count_Fail       "LimFreq_Extra_RelativePDM_List_Count_Fail"
#endif //_COMM_ERRORDEFINE_H