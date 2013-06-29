#include "../include/SysLangDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include "../include/VariableSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>


SysLangItemData::SysLangItemData()
{
	mLangTextCN = "";
}

SysLangItemData::~SysLangItemData()
{

}

bool SysLangItemData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	// 解析字符串
	Parser parser(pBuffer, iLen, '\t');

	int id = 0;
	if (!parser.parser_int_value(id))
		return false;

	if (!parser.parser_int_value(mLangId))
		return false;

	char buffer1[1024] = "";
	if (!parser.parser_string_value(buffer1, sizeof(buffer1)))
		return false;

	mLangTextCN = buffer1;

	return true;
}

template<> SysLangDataManager* cobra_win::Singleton2<SysLangDataManager>::m_pMySelf = NULL;

SysLangDataManager::SysLangDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_SysLangList.clear();
}

SysLangDataManager::~SysLangDataManager()
{

}

std::string SysLangDataManager::GetSysLangById(int langId)
{
	std::map<int, SysLangItemData*>::iterator iter = m_SysLangList.find(langId);
	if (iter == m_SysLangList.end())
		return "";

	int langType = SysLangDataManager::_TYPED_SYSLANG_CN_;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_ACCOUNT_, "SYS", "SysLangType", langType);
	if (langType == _TYPED_SYSLANG_CN_)
	{
		return iter->second->mLangTextCN;
	}

	return "";
}

std::string SysLangDataManager::GetSysLangById(int langId, int langType)
{
	std::map<int, SysLangItemData*>::iterator iter = m_SysLangList.find(langId);
	if (iter == m_SysLangList.end())
		return "";

	if (langType == _TYPED_SYSLANG_CN_)
	{
		return iter->second->mLangTextCN;
	}

	return "";
}

std::string SysLangDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/syslang.txt";

	return "syslang";
}

unsigned  int SysLangDataManager::GetSize()
{
	return m_SysLangList.size()*sizeof(SysLangItemData);
}

bool  SysLangDataManager::Init()
{
	do 
	{
		if (m_bLoadFromDB)
		{
			if (!LoadFromDB())
				break;
		}
		else
		{
			if (!LoadFromFile())
				break;
		}

		return true;
	} 
	while(false);

	return false;
}

void  SysLangDataManager::Tick()
{

}

void  SysLangDataManager::Destroy()
{
	std::map<int, SysLangItemData*>::iterator iter   = m_SysLangList.begin();
	std::map<int, SysLangItemData*>::iterator iter_e = m_SysLangList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	m_SysLangList.clear();
}

bool  SysLangDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	SysLangItemData* pSysLangItem = (SysLangItemData*)pData;
	assert(pSysLangItem != NULL);

	return true;
}

bool  SysLangDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  SysLangDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	SysLangItemData* pItemData = new SysLangItemData;
	if (!pItemData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pItemData))
		return false;

	m_SysLangList.insert(std::map<int, SysLangItemData*>::value_type(pItemData->mLangId, pItemData));
	return true;
}
