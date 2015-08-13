#include "stdafx.h"
#include "TestItemHandler_Standard.h"

using namespace ECIErrorCode::TestItemHdr;

CTestItemHdrStd::CTestItemHdrStd(CEnhanceController* pNextCEC) :	CEnhanceController(pNextCEC), 
																												m_bForcePass(false)
{
}

CTestItemHdrStd::~CTestItemHdrStd()
{
}

size_t CTestItemHdrStd::Enhance_OnAPPLaunch()
{
	size_t ret = NOERROR;

	ret = CEnhanceController::Enhance_OnAPPLaunch();
	if(NOERROR != ret)
		return ret;

	ret = this->CheckTestItemXMLExist();
	if(NOERROR != ret)
		return ret;

	ret = LoadTestProcessor();
	if(NOERROR != ret)
		return ret;

	ret = this->GetTestItem();
	if(NOERROR != ret)
		return ret;

	ret = this->SetToolTestItem();
	if(NOERROR != ret)
		return ret;

	this->SetOtherParameter();

	return ret;
}

size_t CTestItemHdrStd::Enhance_OnRunInit(int i_slot)
{
	size_t ret = NOERROR;

	ret = CEnhanceController::Enhance_OnRunInit(i_slot);
	if(NOERROR != ret)
		return ret;

	if(!this->m_pITI->OnRunInit() || !this->RunTestItem(0, _T("PRERUN")))
	{
		return TOOL_ONRUNINIT_FAIL;
	}

	return ret;
}

size_t CTestItemHdrStd::Enhance_RunTest(int i_slot)
{
	size_t ret = NOERROR;

	ret = CEnhanceController::Enhance_RunTest(i_slot);
	if(NOERROR != ret)
		return ret;

	//Don't care the return value here, if the test item fail, it notify
	if(!this->RunTestItem(0, _T("NORMAL")))
		return TOOL_ONRUN_FAIL;

	return ret; 
}

size_t CTestItemHdrStd::Enhance_OnRunFinish(int i_slot)
{
	size_t ret = NOERROR;

	ret = CEnhanceController::Enhance_OnRunFinish(i_slot);
	if(NOERROR != ret)
		return ret;

	if(!this->RunTestItem(0, _T("POSTRUN")) || !this->m_pITI->OnRunFinish())
	{
		return TOOL_ONRUNFINISH_FAIL;
	}

	return ret;
}

size_t CTestItemHdrStd::Enhance_OnAPPEnd()
{
	size_t ret = NOERROR;

	ret = CEnhanceController::Enhance_OnAPPEnd();
	if(NOERROR != ret)
		return ret;

	m_vTestItemList.clear();
	m_vTestItemTypeList.clear();

	return ret;
}

size_t CTestItemHdrStd::CheckTestItemXMLExist()
{
	CString cstrTestItemPath =	this->m_Parametermap[ParameterKeyWord::WORKINGDIR] + 
												_T("Qisda\\") + 
												this->m_Parametermap[ParameterKeyWord::MODELNAME] + 
												_T("_") + 
												this->m_Parametermap[ParameterKeyWord::STATIONNAME] + 
												_T("_TestItem.xml");
	size_t ret = NOERROR;

	if (::_taccess(cstrTestItemPath, 0) == 0)
	{
		if (m_TestItemXML.Load(cstrTestItemPath) != ERROR_SUCCESS)
		{
			ret = LOAD_TESTITEM_FAIL;
		}
	}
	else
	{
		ret = LOAD_TESTITEM_FAIL;
	}

	return ret;
}

size_t CTestItemHdrStd::LoadTestProcessor()
{
	XMLNode ForcePassNode = m_TestItemXML.SearchNode(_T("//Configuration//TestProcessor//ForceToPass"));

	if (ForcePassNode != NULL)
	{
		CString cstrForcePass = m_TestItemXML.GetNodeText(ForcePassNode);
		if (! cstrForcePass.IsEmpty())
		{
			this->m_bForcePass = cstrForcePass.CompareNoCase(_T("TRUE")) == 0;
		}
	}

	XMLNode Name = m_TestItemXML.SearchNode(_T("//Configuration//TestProcessor//Name"));

	if (Name != NULL)
	{
		this->m_strProcessorName = m_TestItemXML.GetNodeText(Name);
	}

	return NOERROR;
}

size_t CTestItemHdrStd::GetTestItem()
{
	m_vTestItemList.clear();
	m_vTestItemTypeList.clear();

	XMLNodeList TestItemNodeList = NULL;
	TestItemNodeList = m_TestItemXML.GetChildNodes(_T("//Configuration//TestItemList"));

	if (TestItemNodeList == NULL)
	{
		return LOAD_TESTITEM_FAIL;
	}

	for (UINT i = 0; i < m_TestItemXML.GetNodeListSize(TestItemNodeList); ++i)
	{
		XMLNode testItemNode = m_TestItemXML.GetNodeListItem(TestItemNodeList, i);

		CString cstrEnabled = m_TestItemXML.GetNodeAttrValue(testItemNode, _T("Enabled"));
		if (cstrEnabled.CompareNoCase(_T("TRUE")) != 0)
			continue;

		CString cstrTestItemName = m_TestItemXML.GetNodeAttrValue(testItemNode, _T("Name"));
		if (cstrTestItemName.IsEmpty() != true)
		{
			m_vTestItemList.push_back(cstrTestItemName);
		}

		CString cstrTestItemType = m_TestItemXML.GetNodeAttrValue(testItemNode, _T("Type"));
		if (!cstrTestItemType.IsEmpty())
		{
			m_vTestItemTypeList.push_back(cstrTestItemType);
		}

		else
			m_vTestItemTypeList.push_back(_T("NORMAL"));
	}

	return NOERROR;
}

size_t CTestItemHdrStd::SetToolTestItem()
{
	size_t ret = NOERROR;

	for(size_t i = 0;i < this->m_vTestItemList.size();i++)
	{
		if(!this->m_pITI->SetTestItem(this->m_vTestItemList[i].GetString()))
		{
			ret = TOOL_SET_TESTITEM_FAIL;
			break;
		}
	}

	return ret;
}

size_t CTestItemHdrStd::SetOtherParameter()
{
	this->m_pITI->SetParameterValue(ParameterKeyWord::FORCEPASS, this->m_bForcePass ? _T("TRUE") : _T("FALSE"));
	this->m_pITI->SetParameterValue(ParameterKeyWord::RFPROCESSORNAME, this->m_strProcessorName.GetString());

	return NOERROR;
}

void CTestItemHdrStd::RunMustTestItem(size_t StartItem)
{
	for(size_t MustItem = StartItem; MustItem < this->m_vTestItemList.size(); MustItem++)
	{
		CStringA strTestingItem(this->m_vTestItemList[MustItem]);
		this->SendMsg(ECIMsg::TestingItem, (LPARAM)strTestingItem.GetString());

		if (m_vTestItemTypeList[MustItem] == _T("MUST"))
		{
			this->m_pITI->RunTestItem(MustItem);
		}
	}
}

bool CTestItemHdrStd::RunTestItem(size_t StartItem, CString strRunType)
{
	bool bRet = true;
	bool bRunMust = strRunType == _T("NORMAL");

	for(size_t Item = StartItem; Item < this->m_vTestItemList.size(); Item++)
	{
		/*	Run test item if the type match strRunType. If strRunType is NORMAL,
			MUST items need to consider as NORMAL item if no fail	*/
		if (m_vTestItemTypeList[Item] == strRunType ||
			(bRunMust && m_vTestItemTypeList[Item] == _T("MUST")))
		{
			CStringA strTestingItem(this->m_vTestItemList[Item]);
			this->SendMsg(ECIMsg::TestingItem, (LPARAM)strTestingItem.GetString());

			bool bRes = this->m_pITI->RunTestItem(Item);

			if(! bRes)
			{
				bRet = false;

				//If no force to pass, run MUST item if fail, otherwise run next item
				if(! this->m_bForcePass)
				{
					//Run must items if fail
					this->RunMustTestItem(Item + 1);
					break;
				}
			}
		}
	}

	return bRet;
}