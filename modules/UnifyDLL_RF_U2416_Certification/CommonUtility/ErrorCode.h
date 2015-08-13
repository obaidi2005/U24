#ifndef _ERROR_CODE_H_
#define _ERROR_CODE_H_

//////////////////////////////////////////////////////////////////////////
//   Error Code Index:
//      1-Category: QLib Phone Command Phone Error Code
//      2-Category: QLib Phone GSM/EDGE Command Error Code
//      3-Category: QLib Phone WCDMA Command Error Code
//      4-Category: GSM Calibration Device Error Code
//      5-Category: GSM/EDGE Test Device Error Code
//      6-Category: WCDMA Calibration Device Error Code
//      7-Category: WCDMA Test Device Error Code
//      8-Category: GPIB Device Setup Error Code
//      9-Category: Others
//
//   Change Log:
//      2011/07/14, v1.01: Depend on Qisda_ManufactureTools_ErrorCode_V1.01.xls
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
//   1-Category: QLib Phone Command Phone Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_QLIB_PHONE_CONNECT				        	"RF1001"
#define		ERR_QLIB_SET_FTM				            	"RF1002"
#define		ERR_QLIB_SET_ONLINE				            	"RF1003"
#define		ERR_QLIB_MODE_ID				            	"RF1004"
#define		ERR_QLIB_SET_PHONE_BAND				        	"RF1005"
#define		ERR_QLIB_WRITE_RFNV_INBATCHMODE					"RF1006"
#define		ERR_QLIB_FLUSH_RFNV_INBATCHQUEUE				"RF1007"
#define		ERR_QLIB_FTM_LOAD_RF_DATA				    	"RF1008"
#define		ERR_QLIB_COMMAND_CODE				        	"RF1009"
#define		ERR_QLIB_FUNCTION_FAILED				    	"RF1010"
#define		ERR_QLIB_SET_RF_CHANNEL				        	"RF1011"
#define		ERR_PHONE_MODE_NOTFOUND				        	"RF1012"
#define		ERR_QLIB_WRONG_VALUE				        	"RF1013"
#define		ERR_QLIB_SET_LPM				            	"RF1014"
#define		ERR_QLIB_CHECK_ANSWERCALL				    	"RF1015"
#define		ERR_QLIB_STARTMOC				            	"RF1016"
#define		ERR_QLIB_GSM_TX_DA_CAL							"RF1020"
#define		ERR_QLIB_GSM_TX_LINEAR_PREDIST_CAL				"RF1021"
#define		ERR_QLIB_XO_DC_CAL								"RF1022"
#define		ERR_QLIB_XO_FT_COLLECT_SAMPLE					"RF1023"
#define		ERR_QLIB_XO_FT_CURVE_CAL						"RF1024"
#define		ERR_QLIB_SET_SECONDARY_CHAIN					"RF1024"
#define		ERR_QLIB_TURN_ON_OFF_TX							"RF1025"
#define		ERR_QLIB_SET_OFFLINE							"RF1026"
#define		ERR_QLIB_GET_ENH_THERM							"RF1027"



//////////////////////////////////////////////////////////////////////////
//   2-Category: QLib Phone GSM/EDGE Command Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_GSM_TX_BER_STARTPSESSION					"RF2001"
#define		ERR_EGPRS_BER_ASSIGN_BCCH						"RF2002"
#define		ERR_EGPRS_BER_CONFIGURE_DL_TBF					"RF2003"
#define		ERR_EGPRS_BER_CONFIGURE_UL_TBF					"RF2004"
#define		ERR_EGPRS_BER_ESTABLISH_SRB_LOOPBACK			"RF2005"
#define		ERR_EGPRS_BER_RELEASE_ALL_TBF					"RF2006"
#define		ERR_GSM_SET_TX_ONOFF							"RF2007"
#define		ERR_GSM_BER_ASSIGN_BCCH							"RF2008"
#define		ERR_GSM_BER_HANDOVER							"RF2009"
#define		ERR_GSM_BER_CLEARSTATUS							"RF2010"
#define		ERR_GSM_CONFIG_LOOKBACKTYPE						"RF2011"
#define		ERR_GSM_SET_RF_CHANNEL							"RF2012"
#define		ERR_GSM_SET_TX_PDM								"RF2013"
#define		ERR_GSM_SET_DAC_INPUT							"RF2014"
#define		ERR_GSM_CS_TX_SWEEP								"RF2015"
#define		ERR_GSM_KVCO_TX									"RF2016"
#define		ERR_GSM_RX_GAINRANGE_CAL						"RF2017"
#define		ERR_GSM_TX_SWEEP_CAL_ONOFF						"RF2018"
#define		ERR_GSM_SET_PA_RANGE							"RF2020"
#define		ERR_GSM_SET_AMAM_SWEEP							"RF2021"
#define		ERR_GSM_READ_NV									"RF2022"


//////////////////////////////////////////////////////////////////////////
//   3-Category: QLib Phone WCDMA Command Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_QLib_WCDMA_SET_PA_RANGE						"RF3001"
#define		ERR_QLib_WCDMA_SET_SWEEP_STEP_SIZE				"RF3002"
#define		ERR_QLib_WCDMA_SET_CONFIGURE_TX_SWEEP			"RF3003"
#define		ERR_QLib_WCDMA_TX_SWEEP_CAL_ONOFF				"RF3004"
#define		ERR_QLib_WCDMA_GET_ALL_HDET_FROM_SWEEP			"RF3005"
#define		ERR_QLib_WCDMA_GENERATE_TX_LIN_TABLE			"RF3006"
#define		ERR_QLib_WCDMA_SET_TX_ONOFF						"RF3007"
#define		ERR_QLib_WCDMA_SET_LNA_RANGE					"RF3008"
#define		ERR_QLib_WCDMA_SET_RF_CHANNEL					"RF3009"
#define		ERR_QLib_WCDMA_GET_IM2Value						"RF3010"
#define		ERR_QLib_WCDMA_PhoneIsConnected					"RF3011"
#define		ERR_QLib_WCDMA_SetCommandCode					"RF3012"
#define		ERR_QLib_WCDMA_TX_RX_FREQ_CAL_SWEEP				"RF3013"
#define		ERR_QLib_WCDMA_DoDCCal							"RF3014"
#define		ERR_WCDMA_BER_RMC_DCH_TFCS_CONFIG_REQ			"RF3015"
#define		ERR_WCDMA_BER_START_SESSION						"RF3016"
#define		ERR_WCDMA_BER_ACQUIRE_PILOT						"RF3017"
#define		ERR_WCDMA_BER_HAND_OVER							"RF3018"
#define		ERR_WCDMA_BER_STOP_SESSION						"RF3019"
#define		ERR_QLib_WCDMA_SET_PDM							"RF3020"
#define		ERR_WCDMA_WRITE_NV_TX							"RF3021"
#define		ERR_WCDMA_WRITE_NV_RX							"RF3022"
#define		ERR_WCDMA_WRITE_NV_IM2							"RF3023"
#define		ERR_WCDMA_WRITE_NV_DIVERSITY_RX					"RF3024"
#define		ERR_WCDMA_WRITE_NV_DIVERSITY_IM2				"RF3025"
#define		ERR_WCDMA_SET_CW_WAVEFORM						"RF3026"
#define		ERR_WCDMA_SET_CALIBRATION_STATE					"RF3027"
#define		ERR_WCDMA_GET_HDET_BY_INDEX						"RF3028"
#define		ERR_WCDMA_SET_SECONDARY_CHAIN					"RF3029"

//APT
#define		ERR_PHONE_SET_TX_ENH_CAL_ACTION					"RF3030"
#define		ERR_WCDMA_SET_SMPS_BIAS_VAL						"RF3031"	
#define		ERR_WCDMA_SET_SMPS_BIAS_OVERRIDE				"RF3032"
#define		ERR_WCDMA_LOAD_TX_LINEARIZER_CAL_DATA			"RF3033"
#define		ERR_WCDMA_FTM_LOAD_TX_FREQCOMP_CAL_DATA			"RF3034"


//////////////////////////////////////////////////////////////////////////
//   4-Category: GSM Calibration Device Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_DEVICE_GSMCAL_SET_BAND						"RF4001"
#define		ERR_DEVICE_GSMCAL_TABLE_OFF						"RF4002"
#define		ERR_DEVICE_GSMCAL_IQ_INIT_SET					"RF4003"
#define		ERR_DEVICE_GSMCAL_SET_TXFREQ					"RF4004"
#define		ERR_DEVICE_GSMCAL_SET_IPUT_CABLELOSS			"RF4005"
#define		ERR_DEVICE_GSMCAL_SET_MAX_POWER					"RF4006"
#define		ERR_DEVICE_GSMCAL_SET_TRIG_SOURCE				"RF4007"
#define		ERR_DEVICE_GSMCAL_SET_LEAVE_NORM				"RF4008"
#define		ERR_DEVICE_GSMCAL_SET_TXSWEEP					"RF4009"
#define		ERR_DEVICE_GSMCAL_SET_TXIQSL_INIT				"RF4010"
#define		ERR_DEVICE_GSMCAL_FETCH_TXSWEEP_ALL				"RF4011"
#define		ERR_DEVICE_GSMCAL_SET_GSM_INIT					"RF4012"
#define		ERR_DEVICE_GSMCAL_SET_RXCHAN					"RF4013"
#define		ERR_DEVICE_GSMCAL_SET_TXCHAN					"RF4014"
#define		ERR_DEVICE_GSMCAL_FETCH_MODGMSK					"RF4015"
#define		ERR_DEVICE_GSMCAL_SET_OUTPUT_CABLELOSS			"RF4016"
#define		ERR_DEVICE_GSMCAL_SET_RXPOWER					"RF4017"
#define		ERR_DEVICE_GSMCAL_SET_ORFSF_TRIG				"RF4018"
#define		ERR_DEVICE_GSMCAL_SET_ORFSF_SUFFIX				"RF4019"
#define		ERR_DEVICE_GSMCAL_FETCH_ORFSF					"RF4020"
#define		ERR_DEVICE_GSMCAL_SET_TXPOLAR_INIT				"RF4021"
#define		ERR_DEVICE_GSMCAL_SET_AN_BW			            "RF4022"
#define		ERR_DEVICE_GSMCAL_SET_TRIG_GAP		            "RF4023"
#define		ERR_DEVICE_GSMCAL_SET_IQR			            "RF4024"
#define		ERR_DEVICE_GSMCAL_SET_IQR_INIT		            "RF4025"
#define		ERR_DEVICE_GSMCAL_FETCH_IQR						"RF4026"
#define		ERR_DEVICE_GSMCAL_SET_MAP			            "RF4027"
#define		ERR_DEVICE_GSMCAL_SET_CORRECTION	            "RF4028"
#define		ERR_DEVICE_GSMCAL_SET_TXIQSL_ABORT	            "RF4029"
#define		ERR_DEVICE_GSMCAL_SET_LEVEL			            "RF4030"
#define		ERR_DEVICE_GSMCAL_SET_RX_MOD			        "RF4031"
#define		ERR_DEVICE_GSMCAL_SET_RFG_ABORT		            "RF4032"
#define		ERR_DEVICE_GSMCAL_SET_RFG_LSM_ON		        "RF4033"
#define		ERR_DEVICE_GSMCAL_SET_RFG_DEF			        "RF4034"
#define		ERR_DEVICE_GSMCAL_SET_NPOW				        "RF4035"
#define		ERR_DEVICE_GSMCAL_SET_RXFREQ	                "RF4036"


//////////////////////////////////////////////////////////////////////////
//   5-Category: GSM/EDGE Test Device Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_DEVICE_GSMTEST_SET_BAND						"RF5001"
#define		ERR_DEVICE_GSMTEST_SET_TX_INPUTLEVEL_AUTO		"RF5002"
#define		ERR_DEVICE_GSMTEST_SET_RXQUAL_LEVEL				"RF5003"
#define		ERR_DEVICE_GSMTEST_SET_BSSIGNAL_BITSTREAM		"RF5004"
#define		ERR_DEVICE_GSMTEST_SET_CHANGE_MODE				"RF5005"
#define		ERR_DEVICE_GSMTEST_SET_BSSIGNAL_CHAN			"RF5006"
#define		ERR_DEVICE_GSMTEST_FETCH_SPECTRUM_SWIT_FDOMAIN	"RF5007"
#define		ERR_DEVICE_GSMTEST_FETCH_SPECTRUM_MOD_FDOMAIN	"RF5008"
#define		ERR_DEVICE_GSMTEST_FETCH_RXQUAL_BER				"RF5009"
#define		ERR_DEVICE_GSMTEST_SET_TO_TEST_MODE				"RF5010"
#define		ERR_DEVICE_GSMTEST_SET_BSSIGNAL_LEVEL			"RF5011"
#define		ERR_DEVICE_GSMTEST_SET_CONFIG_INIT				"RF5012"
#define		ERR_DEVICE_GSMTEST_QUERY_SIGNAL_STATE			"RF5013"
#define		ERR_DEVICE_GSMTEST_SET_SIGNAL_ON				"RF5014"
#define		ERR_DEVICE_GSMTEST_SET_SIGNAL_MTC				"RF5015"
#define		ERR_DEVICE_GSMTEST_SET_PROC_BSSIGNAL_LEVEL		"RF5016"
#define		ERR_DEVICE_GSMTEST_SET_RFGEN_FREQ				"RF5017"
#define		ERR_DEVICE_GSMTEST_HANDOVER_TARGET				"RF5018"
#define		ERR_DEVICE_GSMTEST_SET_PROC_CHAN				"RF5019"
#define		ERR_DEVICE_GSMTEST_SET_PROC_SLOT_PCL			"RF5020"
#define		ERR_DEVICE_GSMETEST_FETCH_MODGPSK				"RF5021"
#define		ERR_DEVICE_GSMTEST_FETCH_NPOW					"RF5022"
#define		ERR_DEVICE_GSMTEST_SET_SPECTRUM_INIT			"RF5023"
#define		ERR_DEVICE_GSMTEST_SET_RXQUAL_BER				"RF5024"
#define		ERR_DEVICE_GSMTEST_FETCH_BURST					"RF5025"
#define		ERR_FETCHRXQUALITYBER_TIME_OUT					"RF5026"
#define		ERR_DEVICE_GSMTEST_SET_NSUP						"RF5027"
#define		ERR_DEVICE_GSMTEST_ENDCALL						"RF5028"

#define		ERR_DEVICE_EDGETEST_SET_PROC					"RF5101"
#define		ERR_DEVICE_EDGETEST_CONFIGE_CHANNEL				"RF5102"
#define		ERR_DEVICE_EDGETEST_SET_INIT					"RF5103"
#define		ERR_DEVICE_EDGETEST_QUERY_SIGNAL_STATE			"RF5104"
#define		ERR_DEVICE_EDGETEST_SET_SIGNAL_ON				"RF5105"
#define		ERR_DEVICE_EDGETEST_SET_CRES					"RF5106"
#define		ERR_DEVICE_EDGETEST_HANDOVER_TARGET				"RF5107"
#define		ERR_DEVICE_EDGETEST_RXQUAL_BDBL					"RF5108"
#define		ERR_DEVICE_EDGETEST_SPECTRUM_INIT				"RF5109"
#define		ERR_DEVICE_EDGETEST_FETCH_MODEPSK				"RF5110"
#define		ERR_DEVICE_EDGETEST_SET_EDGE_CHAN				"RF5111"
#define		ERR_DEVICE_EDGETEST_FETCH_POWER					"RF5112"
#define		ERR_DEVICE_EDGETEST_ENDCALL						"RF5113"
#define		ERR_DEVICE_EDGETEST_SET_GAMMA					"RF5114"


//////////////////////////////////////////////////////////////////////////
//   6-Category: WCDMA Calibration Device Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_DEVICE_WCDMACAL_SetToWCDMAMode				"RF6001"
#define		ERR_DEVICE_WCDMACAL_SetFrequency				"RF6002"
#define		ERR_DEVICE_WCDMACAL_SET_MAX_INPUT_POWER			"RF6003"
#define		ERR_DEVICE_WCDMACAL_POWER_VS_SLOT_INIT			"RF6004"
#define		ERR_DEVICE_WCDMACAL_READ_POWER					"RF6005"
#define		ERR_DEVICE_WCDMACAL_POWER_VS_SLOT_MODE			"RF6006"
#define		ERR_DEVICE_WCDMACAL_POWER_VS_SLOT_CONFIG		"RF6007"
#define		ERR_DEVICE_WCDMACAL_POWER_VS_SLOT_REPETITION	"RF6008"
#define		ERR_DEVICE_WCDMACAL_FETCH_POWER_VS_SLOT_MEARSURMENT		"RF6009"
#define		ERR_DEVICE_WCDMACAL_SET_INPUT_POWER_LEVEL				"RF6010"
#define		ERR_DEVICE_WCDMACAL_SET_OUPUT_POWER_LEVEL				"RF6011"
#define		ERR_DEVICE_WCDMACAL_SetLevelIm2					"RF6012"
#define		ERR_DEVICE_WCDMACAL_TURN_ON_OFF_RF_GENERATOR	"RF6013"
#define		ERR_DEVICE_WCDMACAL_SET_SMART_ALIGNMENT_CONF	"RF6014"
#define		ERR_DEVICE_WCDMACAL_FETCH_SMART_ALIGNMENT				"RF6015"
#define		ERR_DEVICE_WCDMACAL_ReturnToInit				"RF6016"
#define		ERR_DEVICE_WCDMACAL_AbortSALignment				"RF6017"
#define		ERR_DEVICE_WCDMACAL_SET_SMART_ALIGMENT_POWER_SEGMENTS	"RF6018"
#define		ERR_DEVICE_WCDMACAL_SET_SMART_ALIGMENT_FREQUNCIES		"RF6019"
#define		ERR_DEVICE_WCDMACAL_SET_ANALYZER_FRQUENCY		"RF6020"
#define		ERR_DEVICE_WCDMACAL_SET_GENERATOR_FRQUENCY		"RF6021"
#define		ERR_DEVICE_WCDMACAL_INITIATE_SMART_ALIGNMENT	"RF6022"
#define		ERR_DEVICE_WCDMACAL_IM2_I_DAC					"RF6023"
#define		ERR_DEVICE_WCDMACAL_IM2_Q_DAC					"RF6024"
#define		ERR_DEVICE_WCDMACAL_IM2_GM_DAC					"RF6025"
#define		ERR_DEVICE_WCDMACAL_THERM_CAL					"RF6026"
#define		ERR_DEVICE_WCDMACAL_LINEAR_CAL					"RF6027"
#define		ERR_DEVICE_WCDMACAL_FREQ_COMP_CAL				"RF6028"


//////////////////////////////////////////////////////////////////////////
//   7-Category: WCDMA Test Device Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_DEVICE_WCDMATEST_SET_BAND					"RF7001"
#define		ERR_DEVICE_WCDMATEST_SET_RFGEN_FREQ				"RF7002"
#define		ERR_DEVICE_WCDMATEST_SET_INIT					"RF7003"
#define		ERR_DEVICE_WCDMATEST_SET_CABLELOSS				"RF7004"
#define		ERR_DEVICE_WCDMATEST_SET_RFGEN_INIT				"RF7005"
#define		ERR_DEVICE_WCDMATEST_SET_INPUT_LEVEL_MANUAL		"RF7006"
#define		ERR_DEVICE_WCDMATEST_SET_RFGEN_SETUP			"RF7007"
#define		ERR_DEVICE_WCDMATEST_SET_RFGEN_OPOW				"RF7008"
#define		ERR_DEVICE_WCDMATEST_SET_RFGEN_TPC				"RF7009"
#define		ERR_DEVICE_WCDMATEST_SET_RFGEN_BEGIN			"RF7010"
#define		ERR_DEVICE_WCDMATEST_CONFIG_FE					"RF7011"
#define		ERR_DEVICE_WCDMATEST_FETCH_FE					"RF7012"
#define		ERR_DEVICE_WCDMATEST_CONFIG_MAXPOW				"RF7013"
#define		ERR_DEVICE_WCDMATEST_FETCH_MAXPOW				"RF7014"
#define		ERR_DEVICE_WCDMATEST_CONFIG_ACLR				"RF7015"
#define		ERR_DEVICE_WCDMATEST_FETCH_ACLR					"RF7016"
#define		ERR_DEVICE_WCDMATEST_CONFIG_OBW					"RF7017"
#define		ERR_DEVICE_WCDMATEST_FETCH_OBW					"RF7018"
#define		ERR_DEVICE_WCDMATEST_CONFIG_SEM					"RF7019"
#define		ERR_DEVICE_WCDMATEST_FETCH_SEM					"RF7020"
#define		ERR_DEVICE_WCDMATEST_CONFIG_BER					"RF7021"
#define		ERR_DEVICE_WCDMATEST_FETCH_BER					"RF7022"
#define		ERR_DEVICE_WCDMATEST_CONFIG_ILPC				"RF7023"
#define		ERR_DEVICE_WCDMATEST_FETCH_ILPC					"RF7024"
#define		ERR_DEVICE_WCDMATEST_TPC_TYPE					"RF7025"
#define		ERR_ALLOCATE_MEMORY_NOT_ENOUGH					"RF7026"
#define		ERR_FETCHNPOWERREZ_TIME_OUT						"RF7027"
#define		ERR_FETCHSPECTMFILTER_TIME_OUT					"RF7028"
#define		ERR_SAMPLEDPCH_TIME_OUT							"RF7029"
#define		ERR_DEVICE_WCDMATEST_REF_CHANNEL_TYPE			"RF7030"
#define		ERR_DEVICE_WCDMATEST_SET_SCRAMBLING_CODE		"RF7031"
#define		ERR_DEVICE_WCDMATEST_SET_CHANNEL_CODE			"RF7032"
#define		ERR_DEVICE_WCDMATEST_SET_PHYSICAL_CHANNEL_POWER	"RF7033"
#define		ERR_DEVICE_WCDMATEST_ILPC_NOT_REACH_MAX_MIN_POWER	"RF7034"
#define		ERR_DEVICE_WCDMATEST_CONFIG_MINPOW				"RF7035"
#define		ERR_DEVICE_WCDMATEST_FETCH_MINPOW				"RF7036"


//////////////////////////////////////////////////////////////////////////
//   8-Category: GPIB Device Setup Error Code
//////////////////////////////////////////////////////////////////////////
#define		ERR_GPIB_WRITE									"RF8001"
#define		ERR_GPIB_READ									"RF8002"
#define		ERR_DEVICE_GSM_TEST_INIT						"RF8003"
#define		ERR_DEVICE_GSM_CAL_INIT							"RF8004"
#define		ERR_DEVICE_WCDMA_INIT							"RF8005"
#define		ERR_DEVICE_FM_INIT								"RF8006"
#define		ERR_DEVICE_PS_INIT								"RF8007"
#define		ERR_DEVICE_SET_OUTINPUT							"RF8008"
#define		ERR_DEVICE_DO_GPIB_SELECT						"RF8009"
#define		ERR_DEVICE_SET_OUTPUT_PORT						"RF8010"
#define		ERR_DEVICE_SET_CABLE_LOSS						"RF8011"
#define		ERR_DEVICE_SET_TABLE_ENABLE_OFF					"RF8012"
#define		ERR_DEVICE_FETCH_NAN							"RF8013"
#define		ERR_DEVICE_PS_GET_CURR							"RF8014"
#define		ERR_DEVICE_NOTFOUND								"RF8015"
#define		ERR_GPIB_POW_QUERY								"RF8016"
#define		ERR_GPIB_QUERY									"RF8017"
#define		ERR_GPIB_FINDLSTN								"RF8018"
#define		ERR_GPIB_SEDIFC									"RF8019"
#define		ERR_GPIB_SENDLIST								"RF8020"
#define		ERR_POWER_SUPPLY_WRONG_OUTPUT					"RF8021"
#define		ERR_SYS_SETTING									"RF8022"
#define		ERR_DEVICE_RESET								"RF8023"
#define     ERR_DEVICE_RF_SETFRQ                            "RF8024"
#define     ERR_DEVICE_RF_SETPOWER                          "RF8025"
#define     ERR_DEVICE_RF_INIT                              "RF8026"

#define		ERR_DEVICE_RF_SET_ANALYZER_FREQ					"RF8027"
#define		ERR_DEVICE_TURN_ON_OFF_RF_AUX_GENERATOR			"RF8029"
#define		ERR_DEVICE_TURN_ON_OFF_LOW_SPUR_MODE			"RF8030"
#define		ERR_DEVICE_SET_MODULATION_MODE					"RF8031"
#define		ERR_DEVICE_TURN_ON_OFF_RF_GENERATOR				"RF8032"
#define		ERR_DEVICE_RF_SET_GENERATOR_FREQ				"RF8033"
#define		ERR_DEVICE_RF_SET_GENERATOR_POWER				"RF8034"
#define		ERR_DEVICE_RF_SET_MAX_INPUT_POWER				"RF8035"
#define		ERR_DEVICE_RF_SET_TRIGGER_SOURCE_TYPE			"RF8036"
#define		ERR_DEVICE_RF_SET_IFPOWER_CONFIG				"RF8037"
#define		ERR_DEVICE_RF_SET_TRIGGER_DELAY					"RF8038"
#define		ERR_DEVICE_RF_SET_AM_MODULATION_RATION			"RF8039"
#define		ERR_DEVICE_RF_SET_AM_MODULATION_FREQUENCE		"RF8040"


//////////////////////////////////////////////////////////////////////////
//   9-Category: Others
//////////////////////////////////////////////////////////////////////////
#define		ERR_GSMTEST_INIT								"RF9001"
#define		ERR_GSMTEST_STARTCALL							"RF9002"
#define		ERR_GSMTEST_END									"RF9003"
#define		ERR_GSMTEST_FREQUENCY							"RF9004"
#define		ERR_GSMTEST_PEAKPHASE							"RF9005"
#define		ERR_GSMTEST_MAXRMSPHASE							"RF9006"
#define		ERR_GSMTEST_AVGRMSPHASE							"RF9007"
#define		ERR_GSMTEST_BER_SPECTRUM_SWIT					"RF9008"
#define		ERR_GSMTEST_BER_SPECTRUM_MOD					"RF9009"
#define		ERR_GSMTEST_BURSTPOWER							"RF9010"
#define		ERR_GSMTEST_BER									"RF9011"
#define		ERR_GSMTEST_MAXPOWRWIRELESS						"RF9012"
#define		ERR_GSMTEST_TXCURRENT							"RF9013"
#define		ERR_GSMTEST_RXLEV								"RF9014"
#define		ERR_GSMTEST_BURST								"RF9015"
#define		ERR_GSMTEST_DACPOWERWIRELESS					"RF9016"
#define     ERR_GSMTEST_HANDOVER                            "RF9017"
#define     ERR_GSMTEST_MEASURELOOP                         "RF9018"
#define		ERR_GSMTEST_TXPOWER								"RF9019"
#define		ERR_GSMTEST_PVT									"RF9020"
#define		ERR_GSMTEST_SPECTRUM_SWITCH						"RF9021"
#define		ERR_GSMTEST_SPECTRUM_MOD						"RF9022"
#define		ERR_GSMTEST_SENSITIVITY							"RF9023"

#define		ERR_GSMCAL_INIT									"RF9100"
#define		ERR_GSMCAL_END									"RF9101"
#define		ERR_GSMCAL_PADAC_VCOERR							"RF9102"
#define		ERR_GSMCAL_CS_1800								"RF9103"
#define		ERR_GSMCAL_CS_1900								"RF9104"
#define		ERR_GSMCAL_KVCO_850								"RF9105"
#define		ERR_GSMCAL_KVCO_900								"RF9106"
#define		ERR_GSMCAL_KVCO_1800							"RF9107"
#define		ERR_GSMCAL_KVCO_1900							"RF9108"
#define		ERR_GSMCAL_PADAC_850							"RF9109"
#define		ERR_GSMCAL_PADAC_900							"RF9110"
#define		ERR_GSMCAL_PADAC_1800							"RF9111"
#define		ERR_GSMCAL_PADAC_1900							"RF9112"
#define		ERR_RFCAL_EXCEED_NV_MARGIN						"RF9113"
#define		ERR_GSMCAL_RXCOMP_850							"RF9114"
#define		ERR_GSMCAL_RXCOMP_900							"RF9115"
#define		ERR_GSMCAL_RXCOMP_1800							"RF9116"
#define		ERR_GSMCAL_RXCOMP_1900							"RF9117"
#define		ERR_TIMING_DELAY_SEARCH							"RF9118"
#define		ERR_GSMCAL_TIMEDELAY_850						"RF9119"
#define		ERR_GSMCAL_TIMEDELAY_900						"RF9120"
#define		ERR_GSMCAL_TIMEDELAY_1800						"RF9121"
#define		ERR_GSMCAL_TIMEDELAY_1900						"RF9122"
#define		ERR_GSM_POLAR									"RF9123"

#define		ERR_3GCAL_SEARCH_POWER							"RF9200"
#define		ERR_WCDMA_CAL_SEARCH_PDM						"RF9201"
#define		ERR_3GCAL_LIM_FREQ_EXTRA_POLATION_RELATIVE_PDM_LIST_COUNT	"RF9202"
#define		ERR_3GCAL_HDET_POWER_VS_PDM_SEARCH				"RF9203"
#define		ERR_3GCAL_WCDMA_DVGAOFFSET_OVER_LMT				"RF9204"
#define		ERR_3GCAL_WRITE_NV								"RF9205"
#define		ERR_WCDMACAL_END								"RF9206"
#define		ERR_WCDMA_GET_DVGA_OFFSET						"RF9207"
#define		ERR_WCDMA_COVERAGE_TABLE_OVERFLOW				"RF9208"
#define		ERR_WCDMA_NO_POWER_LESS_MORE_THAN_COVERAGE_TABLE "RF9209"
#define		ERR_WCDMA_POWER_NOT_IN_RANGE					"RF9210"
#define		ERR_WCDMA_NO_POWER_LESS_THAN_HDET_SATURATION_POINT	"RF9211"
#define		ERR_WCDMA_TX_RX_FREQ_CAL_CHANNEL_NUM_OVERFLOW	"RF9212"
#define		ERR_WCDMA_SEARCH_POWER_FOR_TARGET_POWER			"RF9213"
#define		ERR_WCDMA_TX_RX_FREQ_CAL_POWER_SEGMENT_OVERFLOW "RF9214"
#define		ERR_WCDMA_PA_RANGE_NUM_NOT_MATCH				"RF9215"
#define		ERR_WCDMA_DVGA_OUT_OF_SPEC						"RF9216"

#define		ERR_EDGETEST_INIT								"RF9301"
#define		ERR_EDGETEST_STARTCALL							"RF9302"
#define		ERR_EDGETEST_END								"RF9303"
#define		ERR_EDGETEST_BER								"RF9304"
#define		ERR_EDGETEST_FREQUENCY							"RF9305"
#define		ERR_EDGETEST_PEAKPHASE							"RF9306"
#define		ERR_EDGETEST_MAXRMSPHASE						"RF9307"
#define		ERR_EDGETEST_AVGRMSPHASE						"RF9308"
#define		ERR_EDGETEST_BER_SPECTRUM_SWIT					"RF9309"
#define		ERR_EDGETEST_BER_SPECTRUM_MOD					"RF9310"
#define		ERR_EDGETEST_EVMRMS								"RF9311"
#define		ERR_EDGETEST_BURSTPOWER							"RF9312"
#define     ERR_EDGETEST_HANDOVER                           "RF9313"
#define     ERR_EDGETEST_MEASURELOOP                        "RF9314"
#define     ERR_GPRSTEST_INIT                               "RF9315"
#define     ERR_GPRSTEST_STARTCALL                          "RF9316"
#define     ERR_GPRSTEST_HANDOVER                           "RF9317"
#define     ERR_GPRSTEST_MEASURELOOP                        "RF9318"
#define     ERR_GPRSTEST_END                                "RF9319"
#define		ERR_EDGETEST_TXPOWER							"RF9320"
#define		ERR_EDGETEST_PVT								"RF9321"
#define		ERR_EDGETEST_EVM95								"RF9322"
#define		ERR_EDGETEST_SPECTRUM_MOD						"RF9323"
#define		ERR_EDGETEST_SPECTRUM_SWITCH					"RF9324"

#define		ERR_WCDMATEST_INIT								"RF9400"
#define		ERR_WCDMATEST_STARTCALL							"RF9401"
#define		ERR_WCDMATEST_END								"RF9402"
#define		ERR_WCDMATEST_FREQUENCY							"RF9403"
#define		ERR_WCDMATEST_MAXPOW							"RF9404"
#define		ERR_WCDMATEST_ACLR								"RF9405"
#define		ERR_WCDMATEST_SEM								"RF9406"
#define		ERR_WCDMATEST_OBW								"RF9407"
#define		ERR_WCDMATEST_ILPCE								"RF9416"
#define		ERR_WCDMATEST_ILPCF								"RF9409"
#define		ERR_WCDMATEST_BER								"RF9410"
#define		ERR_WCDMATEST_RXLEV								"RF9411"
#define		ERR_WCDMATEST_TXCURR							"RF9412"
#define		ERR_WCDMATEST_STANDBYCURR						"RF9413"
#define		ERR_WCDMATEST_MINPOWER							"RF9414"
#define		ERR_WCDMATEST_EVM								"RF9415"
#define		ERR_WCDMATEST_TRANS								"RF9499"
#define		ERR_WCDMATEST_HANDOVER							"RF9417"
#define		ERR_WCDMATEST_MEASURELOOP						"RF9418"

#define     ERR_HSDPATEST_INIT                               "RF9500"
#define     ERR_HSDPATEST_STARTCALL                          "RF9501"
#define     ERR_HSDPATEST_HANDOVER                           "RF9502"
#define     ERR_HSDPATEST_MEASURELOOP                        "RF9503"
#define     ERR_HSDPATEST_END                                "RF9504"
#define     ERR_HSUPATEST_INIT                               "RF9505"
#define     ERR_HSUPATEST_STARTCALL                          "RF9506"
#define     ERR_HSUPATEST_HANDOVER                           "RF9507"
#define     ERR_HSUPATEST_MEASURELOOP                        "RF9508"
#define     ERR_HSUPATEST_END                                "RF9509"

#define		ERR_FACINFO_FLASHID_NULL						"RF9701"
#define		ERR_FACINFO_PCBID_NULL 							"RF9702"
#define		ERR_FACINFO_PICASSONUM_NULL						"RF9703"
#define		ERR_FACINFO_MISMATCH_FLASHID					"RF9704"
#define		ERR_FACINFO_MISMATCH_PCBID						"RF9705"
#define		ERR_FACINFO_MISMATCH_PICASSONUM					"RF9706"
#define		ERR_FACINFO_CHECK_2G							"RF9707"
#define		ERR_FACINFO_CHECK_3G							"RF9708"
#define		ERR_FACINFO_CHECK_CIT							"RF9709"

#define		ERR_LEAKAGE_CURRENT								"RF9996"
#define		ERR_COINCELL_VOL								"RF9997"
#define		ERR_BACKUP_PART									"RF9998"
#define		ERR_CHECK_HWID									"RF9999"
#define		ERR_PHONE_CONNECT								"RF9900"
#define		ERR_READ_PICASSO								"RF9901"
#define		ERR_WRITE_PICASSO								"RF9902"
#define		ERR_PICASSO_NOT_EQUAL							"RF9903"
#define		ERR_WRITE_VERSION								"RF9904"
#define		ERR_READ_VERSION								"RF9905"
#define		ERR_CHECK_VERSION								"RF9906"
#define		ERR_SET_RTC										"RF9907"
#define		ERR_WRITE_QFUSE									"RF9908"
#define		ERR_CHECK_QFUSE									"RF9909"
#define		ERR_WRITE_PROCESSID								"RF9910"
#define		ERR_READ_PROCESSID								"RF9911"
#define		ERR_CHECK_PROCESSID								"RF9912"
#define		ERR_USB_CHARGE_SWITCH							"RF9913"
#define		ERR_CHANGE_MODE									"RF9914"
#define		ERR_BB_TEST										"RF9915"
#define		ERR_FM_RSSI_OUT_OF_RANGE						"RF9916"
#define		ERR_GPS_CNO_OUT_OF_RANGE						"RF9917"
#define		ERR_WRITE_MOBILEID								"RF9918"
#define		ERR_Read_MOBILEID								"RF9919"
#define		ERR_WLAN_TEST									"RF9920"
#define     ERR_XOCAL_INIT                                  "RF9921"


#define		ERR_3GCAL_TX_COMP_VS_FREQ_NV_OVER_LIMIT			"RF9921"
#define		ERR_3GCAL_LNA_RANGE_OFFSET_NV_OVER_LIMIT		"RF9922"
#define		ERR_3GCAL_VGA_LNA_OFFSET_VS_FREQ_NV_OVER_LIMIT	"RF9923"
#define		ERR_3GCAL_HDET_VS_AGC_NV_OVER_LIMIT				"RF9924"
#define		ERR_READ_NV										"RF9925"
#define		ERR_WRONG_TOOL_CONFIGURE						"RF9926"
#define		ERR_MOBILE_ON_CURRENT							"RF9927"
#define		ERR_MODEM_VERSION_NOT_MATCH						"RF9928"
#define		ERR_SW_VERSION_NOT_MATCH						"RF9929"
#define		ERR_MOBILE_FTM_NV_INCORRECT						"RF9930"

#define		ERR_COMMON_LOAD_DLL_FAIL						"RF9940"
#define		ERR_COMMON_PICASSO								"RF9941"


//////////////////////////////////////////////////////////////////////////
//  ErrorCode for Device and xml by Jackiesen.wan 2012/02/03
//////////////////////////////////////////////////////////////////////////
#define		ERR_DETECT_CMU							"RF0001"
#define		ERR_LOAD_LOSS_XML						"RF0002"
#define		ERR_LOAD_TESTITEM_XML					"RF0003"
#define		ERR_LOAD_DEVICE_XML						"RF0004"




//////////////////////////////////////////////////////////////////////////
//   Wireless error codes
//////////////////////////////////////////////////////////////////////////

#define ERR_WIRELESS_WIFI_TX_POWER_FAIL						"FT5302"
#define ERR_WIRELESS_BT_TX_POWER_FAIL						"FT5252"

#define ERR_WIRELESS_GPS_CN0_FAIL							"FT5453"

#define ERR_WIRELESS_GSM_TX_POWER_FAIL						"FT5850"
#define ERR_WIRELESS_WCDMA_TX_POWER_FAIL					"FT5878"


//////////////////////////////////////////////////////////////////////////
//   Baseband error codes
//////////////////////////////////////////////////////////////////////////

#define ERR_LEAKAGE_CURRENT_FAIL							"FT5618"


#endif // End of #ifndef _ERROR_CODE_H_
