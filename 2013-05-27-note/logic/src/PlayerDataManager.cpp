#include "../include/PlayerDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>

PlayerData::PlayerData()
{
	m_PlayerId = 0;								 // 英雄Id
	memset(m_PlayerName,0,sizeof(m_PlayerName)); // 英雄名字
	m_WeaponType = 0;							 // 武器类型，0近程，1远程
	m_WeaponId = 0;        // 武器ID
	m_AttackAngle = 0;     // 攻击角度0～180
	m_AttackDistence = 0;  // 攻击距离
	m_AttackAbility = 0;   // 攻击力
	m_DefenceAbility = 0;  // 防御能力
	m_MaxHp = 0;           // 初始血量
	m_Speed = 0;           // 初始速度
	m_Width = 0;           // 英雄宽度
	m_Height = 0;          // 英雄高度
	m_CollisionWidth = 0;  // 碰撞检测宽度
	m_CollisionHeight = 0; // 碰撞检测高度
	m_AttackInterVal = 0;  // 攻击间隔时间
	memset(m_RunUpActionName,0,sizeof(m_RunUpActionName)); // 向上运动动画
	memset(m_RunDownActionName,0,sizeof(m_RunDownActionName)); // 向下运动动画 
	memset(m_RunLeftActionName,0,sizeof(m_RunLeftActionName)); // 向左运动动画
	memset(m_RunRightActionName,0,sizeof(m_RunRightActionName)); // 向右运动动画
	memset(m_AttackSoundName,0,sizeof(m_AttackSoundName)); // 攻击音效
	memset(m_DeadSoundName,0,sizeof(m_DeadSoundName)); // 死亡音效
}

PlayerData::~PlayerData()
{

}

bool PlayerData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	//解析字符串
	Parser parser(pBuffer,iLen,'\t');
	int id = 0;
	if(!parser.parser_int_value(id))
		return false;
	if(!parser.parser_int_value(m_PlayerId))
		return false;
	if(!parser.parser_string_value(m_PlayerName,sizeof(m_PlayerName)))
		return false;
	if(!parser.parser_int_value(m_WeaponType))
		return false;
	if(!parser.parser_int_value(m_WeaponId))
		return false;
	if(!parser.parser_int_value(m_AttackAngle))
		return false;
	if(!parser.parser_int_value(m_AttackDistence))
		return false;
	if(!parser.parser_float_value(m_AttackAbility))
		return false;
	if(!parser.parser_int_value(m_DefenceAbility))
		return false;
	if(!parser.parser_float_value(m_MaxHp))
		return false;
	if(!parser.parser_float_value(m_Speed))
		return false;
	if(!parser.parser_float_value(m_Width))
		return false;
	if(!parser.parser_float_value(m_Height))
		return false;
	if(!parser.parser_float_value(m_CollisionWidth))
		return false;
	if(!parser.parser_float_value(m_CollisionHeight))
		return false;
	if(!parser.parser_int_value(m_AttackInterVal))
		return false;
	if(!parser.parser_string_value(m_RunUpActionName,sizeof(m_RunUpActionName)))
		return false;
	if(!parser.parser_string_value(m_RunDownActionName,sizeof(m_RunDownActionName)))
		return false;
	if(!parser.parser_string_value(m_RunLeftActionName,sizeof(m_RunLeftActionName)))
		return false;
	if(!parser.parser_string_value(m_RunRightActionName,sizeof(m_RunRightActionName)))
		return false;
	if(!parser.parser_string_value(m_LobbyDownActionNmae,sizeof(m_LobbyDownActionNmae)))
		return false;
	if(!parser.parser_string_value(m_BuffRightActionNmae,sizeof(m_BuffRightActionNmae)))
		return false;
	if(!parser.parser_string_value(m_AttackSoundName,sizeof(m_AttackSoundName)))
		return false;
	if(!parser.parser_string_value(m_DeadSoundName,sizeof(m_DeadSoundName)))
		return false;
	return true;
}

template<> PlayerDataManager* cobra_win::Singleton2<PlayerDataManager>::m_pMySelf = NULL;

PlayerDataManager::PlayerDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{

}

PlayerDataManager::~PlayerDataManager()
{

}

PlayerData* PlayerDataManager::GetPlayerById(int playerId)
{
	std::map<int, PlayerData*>::iterator iter = m_PlayerList.find(playerId);
	if (iter == m_PlayerList.end())
		return NULL;

	return iter->second;
}

std::string PlayerDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/player.txt";

	return "player";
}

unsigned  int PlayerDataManager::GetSize()
{
	return m_PlayerList.size()*sizeof(PlayerData);
}

bool  PlayerDataManager::Init()
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

void  PlayerDataManager::Tick()
{

}

void  PlayerDataManager::Destroy()
{
	std::map<int, PlayerData*>::iterator iter   = m_PlayerList.begin();
	std::map<int, PlayerData*>::iterator iter_e = m_PlayerList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	m_PlayerList.clear();
}

bool  PlayerDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	PlayerData* pPlayerData = (PlayerData*)pData;
	assert(pPlayerData != NULL);

	return true;
}

bool  PlayerDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  PlayerDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	PlayerData* pPlayerData = new PlayerData;
	if (!pPlayerData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pPlayerData))
		return false;

	m_PlayerList.insert(std::map<int, PlayerData*>::value_type(pPlayerData->m_PlayerId, pPlayerData));
	return true;
}

