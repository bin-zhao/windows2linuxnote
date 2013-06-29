#include "../include/WeaponDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>

WeaponData::WeaponData()
{
	m_WeaponId=0;				 // 怪物武器Id
    m_attackScope=0;			 // 武器碰撞检测范围
    m_Speed=0;                   // 武器移动速度
    m_AttackDamage=0;           // 武器攻击力
    m_bHasSpreedAbility=0;           // 是否具备溅射能力
    m_AddAttackRadius=0;         // 溅射半径
}

WeaponData::~WeaponData()
{

}

bool WeaponData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	//解析字符串
	Parser parser(pBuffer,iLen,'\t');
	int id = 0;
	if(!parser.parser_int_value(id))
		return false;
	if(!parser.parser_int_value(m_WeaponId))
		return false;
	if(!parser.parser_float_value(m_attackScope))
		return false;
	if(!parser.parser_float_value(m_Speed))
		return false;
	if(!parser.parser_float_value(m_AttackDamage))
		return false;
	if(!parser.parser_bool_value(m_bHasSpreedAbility))
		return false;
	if(!parser.parser_float_value(m_AddAttackRadius))
		return false;
	if(!parser.parser_string_value(m_AvatarResourceName,sizeof(m_AvatarResourceName)))
		return false;
	if(!parser.parser_string_value(m_EffectName,sizeof(m_EffectName)))
		return false;
	if(!parser.parser_bool_value(m_isGood))
		return false;
	return true;
}

template<> WeaponDataManager* cobra_win::Singleton2<WeaponDataManager>::m_pMySelf = NULL;

WeaponDataManager::WeaponDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{

}

WeaponDataManager::~WeaponDataManager()
{

}

WeaponData* WeaponDataManager::GetWeaponById(int WeaponId)
{
	std::map<int, WeaponData*>::iterator iter = m_WeaponList.find(WeaponId);
	if (iter == m_WeaponList.end())
		return NULL;

	return iter->second;
}

std::string WeaponDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/weapon.txt";

	return "weapon";
}

unsigned  int WeaponDataManager::GetSize()
{
	return m_WeaponList.size()*sizeof(WeaponData);
}

bool  WeaponDataManager::Init()
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

void  WeaponDataManager::Tick()
{

}

void  WeaponDataManager::Destroy()
{
	std::map<int, WeaponData*>::iterator iter   = m_WeaponList.begin();
	std::map<int, WeaponData*>::iterator iter_e = m_WeaponList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	m_WeaponList.clear();
}

bool  WeaponDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	WeaponData* pWeaponData = (WeaponData*)pData;
	assert(pWeaponData != NULL);

	return true;
}

bool  WeaponDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  WeaponDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	WeaponData* pWeaponData = new WeaponData;
	if (!pWeaponData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pWeaponData))
		return false;

	m_WeaponList.insert(std::map<int, WeaponData*>::value_type(pWeaponData->m_WeaponId, pWeaponData));
	return true;
}

