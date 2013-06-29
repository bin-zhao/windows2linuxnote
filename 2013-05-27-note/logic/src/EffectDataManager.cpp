#include "../include/EffectDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>


EffectItemData::EffectItemData()
{
	mEffectType = 0;
	mEffectFadeout = false;
	memset(mEffectIdleAvatarName, 0, sizeof(mEffectIdleAvatarName));
	memset(mEffectSoundName, 0, sizeof(mEffectSoundName));
}

EffectItemData::~EffectItemData()
{

}

bool EffectItemData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	// 解析字符串
	Parser parser(pBuffer, iLen, '\t');

	int id = 0;
	if (!parser.parser_int_value(id))
		return false;

	if (!parser.parser_int_value(mEffectType))
		return false;

	if (!parser.parser_string_value(mEffectIdleAvatarName, sizeof(mEffectIdleAvatarName)))
		return false;

	if (!parser.parser_bool_value(mEffectFadeout))
		return false;

	parser.parser_string_value(mEffectSoundName, sizeof(mEffectSoundName));

	return true;
}

template<> EffectDataManager* cobra_win::Singleton2<EffectDataManager>::m_pMySelf = NULL;

EffectDataManager::EffectDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_EffectList.clear();
}	

EffectDataManager::~EffectDataManager()
{

}

EffectItemData* EffectDataManager::GetEffectByType(int type)
{
	std::map<int, EffectItemData*>::iterator iter = m_EffectList.find(type);
	if (iter == m_EffectList.end())
		return NULL;

	return iter->second;
}

std::string EffectDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/effect.txt";

	return "effect";
}

unsigned  int EffectDataManager::GetSize()
{
	return m_EffectList.size()*sizeof(EffectItemData);
}

bool  EffectDataManager::Init()
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

void  EffectDataManager::Tick()
{

}

void  EffectDataManager::Destroy()
{
	std::map<int, EffectItemData*>::iterator iter   = m_EffectList.begin();
	std::map<int, EffectItemData*>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	return m_EffectList.clear();
}

bool  EffectDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	EffectItemData* pButtonItem = (EffectItemData*)pData;
	assert(pButtonItem != NULL);

	return true;
}

bool  EffectDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  EffectDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	EffectItemData* pItemData = new EffectItemData;
	if (!pItemData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pItemData))
		return false;

	m_EffectList.insert(std::map<int, EffectItemData*>::value_type(pItemData->mEffectType, pItemData));
	return true;
}
