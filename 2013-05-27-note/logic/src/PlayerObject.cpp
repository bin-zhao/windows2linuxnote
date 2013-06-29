#include "../include/PlayerObject.h"
#include "../include/SwordObject.h"
#include "../include/InputCommand.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/VariableSystem.h"
#include "../include/SoundSystem.h"
#include "../include/Common.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/PlayerDataManager.h"
#include "../include/LocalPlayerDataManager.h"
#include <cocos2d.h>

PlayerObject::PlayerObject()
{
	m_ObjectType = _TYPED_OBJECT_PLAYEROBJECT_;
	m_ObjectSubType = 0;
	bIsLeader = false;                  /* 是否是队长 */ 
	bIsTeam = false;                    /* 是否在队伍中,默认False */
	m_bDead = false;                    /* 是否死亡 */
	m_Speed = 0;                        /* 速度 */
	m_AttackDst = 0;					/* 攻击距离 */
	m_AttackAngle = 0;					/* 攻击角度0～180 */
	m_Dir = DIR_UP;                     /* 方向 */
	m_AttackAbility = 0;	            /* 攻击力 */
	m_PreDir = DIR_OTHER;               /* 前一时刻方向 */
	m_pPlayerHPBar = NULL;              /* 血量条 */
	m_PlayerHP = 0;                     /* 英雄当前血量 */
	m_PlayerMaxHP = 0;                  /* 英雄总血量 */
	m_pPlayerAvatar = NULL;             /* 英雄avatar */
	m_PreShootTime = 0;                 /* 前一次攻击时间 */
	m_PlayerGreenDiamonNumber =0;       /* 玩家吃到绿钻个数 */
	m_PlayerBlueDiamonNumber = 0;       /* 玩家吃到蓝钻个数 */
	m_PlayerRedDiamonNumber = 0;        /* 玩家吃到红钻个数 */
	m_KillMonsterNumber = 0;            /* 玩家杀敌数目 */
}

PlayerObject::~PlayerObject()
{

}

void PlayerObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void PlayerObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}




void PlayerObject::Init()
{
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	if(GetObjectSubType()<_SUBTYPE_MONSTER_01)
	{
		//如果是队长
		if(bIsLeader == true)
		{
			SCENEMANAGER->GetScenePlayerLayer()->addChild(m_pAvatar);
		}
		else
		{
			//如果被队伍撞到
			if(bIsTeam)
			{
				SCENEMANAGER->GetScenePlayerLayer()->addChild(m_pAvatar);
			}
			else//如果既不是队长又不是被英雄撞到
			{
				SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar);
			}
		}
	}
	else
	{
		SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar);
	}

	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	m_PlayerHP = pPlayerData->m_MaxHp;
	m_PlayerMaxHP = pPlayerData->m_MaxHp;
	m_Speed = pPlayerData->m_Speed;
	m_AttackDst = pPlayerData->m_AttackDistence;
	m_AttackAngle = pPlayerData->m_AttackAngle;
	m_AttackAbility = pPlayerData->m_AttackAbility;

	m_pPlayerAvatar = cocos2d::CCSprite::create();
	m_pPlayerAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	m_pAvatar->addChild(m_pPlayerAvatar);

	m_pPlayerHPBar = new cocos2d::CCProgressBar;
	m_pPlayerHPBar->autorelease();
	m_pPlayerHPBar->init();

	cocos2d::CCTexture2D *pTexture = cocos2d::CCTextureCache::sharedTextureCache()->addImage("resource/image/loadingbar2.png");
	if(pTexture!=NULL)
	{
		cocos2d::CCRect rect = cocos2d::CCRectZero;
		rect.size = pTexture->getContentSize();
		m_pPlayerHPBar->setTexture(pTexture);
		m_pPlayerHPBar->setTextureRect(rect);
	}
	m_pPlayerHPBar->setProgressInnerFileName("resource/image/loadingbar.png");
	m_pPlayerHPBar->setProgressXInnerOffset(2);
	m_pPlayerHPBar->setProgressYInnerOffset(0);
	m_pPlayerHPBar->setPercent((float)m_PlayerHP);
	//int x = GetXPos();
	//int y = GetYPos();
	//int h = getPlayerObjectHeight();
	//m_pPlayerHPBar->setPosition(ccp(GetXPos(),GetYPos()+getPlayerObjectHeight()));
	m_pPlayerHPBar->setPosition(ccp(GetXPos()+pPlayerData->m_Width/2.0f-25,GetYPos()+pPlayerData->m_Height/2.0f));
	m_pAvatar->addChild(m_pPlayerHPBar);
	m_pPlayerHPBar->setVisible(true);

	switch(m_Dir)
	{
	case DIR_UP:
		PlayEffect(getRunUpAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_DOWN:
		PlayEffect(getDownActionAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_LEFT:
		PlayEffect(getLeftActionAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_RIGHT:
		PlayEffect(getRightActionAnimationName(),m_pPlayerAvatar);
		break;
	}
}

void PlayerObject::Tick()
{
	IObject::Tick();

	UpdateBuffAvatar();
}

void PlayerObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		if(m_pPlayerHPBar!=NULL)
		{
			m_pAvatar->removeChild(m_pPlayerHPBar,true);
			m_pPlayerHPBar = NULL;
		}
		if(m_pPlayerAvatar!=NULL)
		{
			m_pAvatar->removeChild(m_pPlayerAvatar,true);
			m_pPlayerAvatar = NULL;
		}
		if(!bIsTeam&&!bIsLeader)
		{
			SCENEMANAGER->GetSceneBackgroundLayer()->removeChild(m_pAvatar,true);
		}
		else
		{
			SCENEMANAGER->GetScenePlayerLayer()->removeChild(m_pAvatar,true);
		}
		m_pAvatar = NULL;
	}
}


void PlayerObject::PushCommand(int commandId, void* pPtr)
{

	if(_TYPED_INPUT_COMMAND_HEROTOMONSTER_ == commandId)//如果为英雄攻击怪物(类似于刀光),指针为英雄
	{
		PlayerObject *player = (PlayerObject*)pPtr;
		//pPtr为掉血的数值
		m_PlayerHP -= player->m_AttackAbility;
		m_pPlayerHPBar->setPercent(m_PlayerHP);
	}
	else if(_TYPED_INPUT_COMMAND_HEROWEAPONTOMONSTER_ == commandId)//指针为武器对象
	{
		WeaponObject *weapon = (WeaponObject*)pPtr;
		//pPtr为掉血的数值
		m_PlayerHP -= weapon->getAttackDamage();
		m_pPlayerHPBar->setPercent(m_PlayerHP);
	}
	else if(_TYPED_INPUT_COMMAND_MONSTERTOHERO == commandId)//指针为怪物指针
	{
		PlayerObject *player = (PlayerObject*)pPtr;
		//pPtr为掉血的数值
		m_PlayerHP -= player->m_AttackAbility;
		m_pPlayerHPBar->setPercent(m_PlayerHP);
	}
	else if(_TYPED_INPUT_COMMAND_MONSTERWEAPONTOHERO_ == commandId)//指针为怪物武器指针
	{
		OnPlayerCollisionCommandHandler(pPtr);
	}
	
}

void PlayerObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	switch(m_Dir)
	{
	case DIR_UP:
		PlayEffect(getRunUpAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_DOWN:
		PlayEffect(getDownActionAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_LEFT:
		PlayEffect(getLeftActionAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_RIGHT:
		PlayEffect(getRightActionAnimationName(),m_pPlayerAvatar);
		break;
	}
}

bool PlayerObject::Attack(cocos2d::CCPoint targetPos)
{
	int interval = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_AttackInterVal * NinjiaTribeApp::get_instance2()->GetFPS();
	//cocos2d::CCPoint atBkPos = SCENEMANAGER->playerLayerPos2bkLayerPos(GetXPos(),GetYPos());
	//判断是否到达攻击间隔
	if(m_PreShootTime == 0|| (m_LogicTickCounter - m_PreShootTime) > interval)
	{
		m_PreShootTime = m_LogicTickCounter;

		//player层转换到背景层
		cocos2d::CCPoint bkPos;
		if(GetObjectSubType()<_SUBTYPE_MONSTER_01)
		{
			bkPos.x = GetXPos() - SCENEMANAGER->GetSceneBackgroundLayer()->getPositionX();
			bkPos.y = GetYPos() - SCENEMANAGER->GetSceneBackgroundLayer()->getPositionY();
		}
		else
		{
			bkPos.x = GetXPos();
			bkPos.y = GetYPos();
		}

		//背景层创建武器对象
		switch(m_ObjectSubType)
		{
		case _SUBTYPE_HERO_HERO1:
			SwordObject::create(bkPos,m_Dir);
			CCLOG("subtype:%d create weapon object",m_ObjectSubType);
			break;
		case _SUBTYPE_HERO_HERO2:
			SCENEMANAGER->createWeapon(WeaponObject::_SUBTYPE_WEAPON_ARROW,bkPos,targetPos);
			CCLOG("subtype:%d create weapon object",m_ObjectSubType);
			break;
		case _SUBTYPE_HERO_HERO3:
			SCENEMANAGER->createWeapon(WeaponObject::_SUBTYPE_WEAPON_FIRE,bkPos,targetPos);
			CCLOG("subtype:%d create weapon object",m_ObjectSubType);
			break;
		case _SUBTYPE_MONSTER_01:
			SCENEMANAGER->createWeapon(WeaponObject::_SUBTYPE_WEAPON_NET,bkPos,targetPos);
			break;
		case _SUBTYPE_MONSTER_BOWARROW:
			SCENEMANAGER->createWeapon(WeaponObject::_SUBTYPE_WEAPON_VENOM,bkPos,targetPos);
			break;
		case _SUBTYPE_MONSTER_03:
			SCENEMANAGER->createWeapon(WeaponObject::_SUBTYPE_WEAPON_BOWAEEOW,bkPos,targetPos);
			break;
		}		
		return true;
	}
	else
	{
		return false;
	}
}

//判断targetPos是否在英雄攻击范围之内
bool PlayerObject::isInAttackScope(cocos2d::CCPoint targetPos)
{

	cocos2d::CCPoint bkPos;
	if(GetObjectSubType()<16)
	{
		//player层转换到背景层
		bkPos.x = GetXPos() - SCENEMANAGER->GetSceneBackgroundLayer()->getPositionX();
		bkPos.y = GetYPos() - SCENEMANAGER->GetSceneBackgroundLayer()->getPositionY();

	}
	else
	{
		bkPos.x = GetXPos();
		bkPos.y = GetYPos();
		//targetPos.x -=SCENEMANAGER->GetSceneBackgroundLayer()->getPositionX();
		//targetPos.y -=SCENEMANAGER->GetSceneBackgroundLayer()->getPositionY();
	}

	//计算目标与英雄之间的距离
	float dst_x = ::fabs(bkPos.x - targetPos.x);
	float dst_y = ::fabs(bkPos.y - targetPos.y);
	float dst   = ::sqrt(dst_x*dst_x + dst_y*dst_y);
	//如果距离不够,直接返回false
	if(dst > m_AttackDst)
		return false;
	//计算角度
	float angle = 0;
	switch(m_Dir)
	{
	case DIR_UP:
		if(targetPos.y<bkPos.y) //角度大于90度
		{
			return false;
		}
		angle = ::atan2(dst_x,dst_y) * 180 / 3.1415926f;
		angle *= 2;
		if(angle > m_AttackAngle)
		{
			return false;
		}
		break;
	case DIR_DOWN:
		if(targetPos.y>bkPos.y) //角度大于90度
		{
			return false;
		}
		angle = ::atan2(dst_x,dst_y) * 180 / 3.1415926f;
		angle *= 2;
		if(angle > m_AttackAngle)
		{
			return false;
		}
		break;
	case DIR_LEFT:
		if(targetPos.x>bkPos.x) //角度大于90度
		{
			return false;
		}
		angle = ::atan2(dst_y,dst_x) * 180 / 3.1415926f;
		angle *= 2;
		if(angle > m_AttackAngle)
		{
			return false;
		}
		break;
	case DIR_RIGHT:
		if(targetPos.x<bkPos.x) //角度大于90度
		{
			return false;
		}
		angle = ::atan2(dst_y,dst_x) * 180 / 3.1415926f;
		angle *= 2;
		if(angle > m_AttackAngle)
		{
			return false;
		}
		break;
	}
	return true;
}

void PlayerObject::PlayDeadSound()
{

}

void PlayerObject::PlayDeadEffect()
{

}
float PlayerObject::GetAvatarWidth()
{
	return PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_Width;
}

float PlayerObject::GetAvatarHeight()
{
	return PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_Height;
}

float PlayerObject::GetAvatarCollisionWidth()
{
	return PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_CollisionWidth;
}

float PlayerObject::GetAvatarCollisionHeight()
{
	return PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_CollisionHeight;
}

std::string PlayerObject::getRunUpAnimationName()
{
	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	assert(pPlayerData != NULL);

	return pPlayerData->m_RunUpActionName;
}

std::string PlayerObject::getDownActionAnimationName()
{
	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	assert(pPlayerData != NULL);

	return pPlayerData->m_RunDownActionName;
}

std::string PlayerObject::getLeftActionAnimationName()
{
	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	assert(pPlayerData != NULL);

	return pPlayerData->m_RunLeftActionName;
}

std::string PlayerObject::getRightActionAnimationName()
{
	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	assert(pPlayerData != NULL);

	return pPlayerData->m_RunRightActionName;
}

float PlayerObject::getPlayerObjectWidht()
{
	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	assert(pPlayerData != NULL);

	return pPlayerData->m_Width;
}

float PlayerObject::getPlayerObjectHeight()
{
	PlayerData* pPlayerData = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType());
	assert(pPlayerData != NULL);

	return pPlayerData->m_Height;
}

void PlayerObject::turnDir()
{
	if(m_PreDir == m_Dir)
		return;
	switch(m_PreDir)
	{
	case DIR_UP:
		StopEffect(getRunUpAnimationName());
		break;
	case DIR_DOWN:
		StopEffect(getDownActionAnimationName());
		break;
	case DIR_LEFT:
		StopEffect(getLeftActionAnimationName());
		break;
	case DIR_RIGHT:
		StopEffect(getRightActionAnimationName());
		break;
	}
	m_PreDir = m_Dir;

	switch(m_Dir)
	{
	case DIR_UP:
		PlayEffect(getRunUpAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_DOWN:
		PlayEffect(getDownActionAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_LEFT:
		PlayEffect(getLeftActionAnimationName(),m_pPlayerAvatar);
		break;
	case DIR_RIGHT:
		PlayEffect(getRightActionAnimationName(),m_pPlayerAvatar);
		break;
	}

}

PlayerObject* PlayerObject::create(int subType,cocos2d::CCPoint pt,bool IsLeader,bool bIsTeam,DIRECTION dir)
{
	PlayerObject* pPlayer = new PlayerObject;
	pPlayer->SetObjectSubType(subType);
	pPlayer->bIsLeader = IsLeader;
	pPlayer->bIsTeam = bIsTeam;
	pPlayer->m_Dir = dir;
	pPlayer->Init();
	pPlayer->SetXPos(pt.x);
	pPlayer->SetYPos(pt.y);
	OBJECTMANAGER->InsertObject(pPlayer);
	return pPlayer;
}

PlayerObject* PlayerObject::create(int subType)
{
	PlayerObject* pPlayer = new PlayerObject;
	pPlayer->SetObjectSubType(subType);
	pPlayer->bIsLeader = false;
	pPlayer->bIsTeam = true;
	pPlayer->m_Dir = DIR_DOWN;
	pPlayer->Init();
	pPlayer->SetXPos(0);
	pPlayer->SetYPos(0);
	OBJECTMANAGER->InsertObject(pPlayer);
	return pPlayer;
}

void PlayerObject::OnPlayerCollisionCommandHandler(void* ptr)
{
	WeaponObject* weapon = (WeaponObject*)ptr;
	int type = weapon->GetObjectSubType();
	switch(type)
	{
	case WeaponObject::_SUBTYPE_WEAPON_NET:
		//英雄减速
		//PlayBuffEffect(_SUBTYPE_BUFF_SLOW);
		//m_Speed -=2;
		SCENEMANAGER->allHerosSlowDown();
		break;
	default:
		//pPtr为掉血的数值
		m_PlayerHP -= weapon->getAttackDamage();
		m_pPlayerHPBar->setPercent(m_PlayerHP);
		break;
	}
}

bool PlayerObject::IsInBuff(int buffType)
{
	std::map<int, _PLAYER_BUFF_INFO_>::iterator iter = m_PlayerBuffList.find(buffType);
	if (iter == m_PlayerBuffList.end())
		return false;

	if (!iter->second.mIsPlaying)
		return false;

	return true;
}

void PlayerObject::PlayBuffEffect(int buffType)
{
	//查找是否存在指定的buff
	std::map<int, _PLAYER_BUFF_INFO_>::iterator iter = m_PlayerBuffList.find(buffType);
	if (iter != m_PlayerBuffList.end())
	{
		//存在则更新相关数值
		iter->second.mIsPlaying        = true;
		iter->second.mBuffLastTime     = int(2*NinjiaTribeApp::get_instance2()->GetFPS());//2s,以后改为读表
		iter->second.mBuffStartTime    = m_LogicTickCounter;
		iter->second.mBufferActionName = "cobweb.png";//pStatusItem->mStatusActionName;
		if (iter->second.mBufferActionName.size() > 0)
		{
			iter->second.mBuffAvatar->setVisible(true);
			// 开始播放动作
			// PlayEffect(iter->second.mBufferActionName, iter->second.mBuffAvatar);
			m_Speed = 4;
		}
		return;
	}

	_PLAYER_BUFF_INFO_ info;
	info.mBuffType      = buffType;
	info.mIsPlaying     = true;
	info.mBuffLastTime  = int(2*NinjiaTribeApp::get_instance2()->GetFPS());//int(pStatusItem->mStatusLastTime*VIP3DApp::get_instance2()->GetFPS());
	info.mBuffStartTime = m_LogicTickCounter;
	info.mBufferActionName = "cobweb.png";//pStatusItem->mStatusActionName;
	if (info.mBufferActionName.size() > 0)
	{
		//info.mBuffAvatar = cocos2d::CCSprite::create();
		info.mBuffAvatar = cocos2d::CCSprite::createWithSpriteFrameName(info.mBufferActionName.c_str());
		info.mBuffAvatar->setAnchorPoint(cocos2d::CCPoint(0.5f, 0.5f));
		//设置坐标便宜
		info.mBuffAvatar->setPosition(cocos2d::CCPoint(0, -20));//(cocos2d::CCPoint(pStatusItem->mXMove, pStatusItem->mYMove));
		//设置X缩放
		//info.mBuffAvatar->setScaleX(pStatusItem->mXScale);
		//设置Y缩放
		//info.mBuffAvatar->setScaleY(pStatusItem->mYScale);
		m_pAvatar->addChild(info.mBuffAvatar);
		//PlayEffect(info.mBufferActionName, info.mBuffAvatar);//PlayEffect(pStatusItem->mStatusActionName, info.mBuffAvatar);
	}
	m_PlayerBuffList.insert(std::map<int, _PLAYER_BUFF_INFO_>::value_type(buffType, info));
}

void PlayerObject::StopBuffEffect(int buffType)
{
	std::map<int, _PLAYER_BUFF_INFO_>::iterator iter = m_PlayerBuffList.find(buffType);
	if (iter == m_PlayerBuffList.end())
		return;

	iter->second.mIsPlaying = false;
	if (iter->second.mBuffAvatar != NULL)
	{
		iter->second.mBuffAvatar->setVisible(false);
		//StopEffect(iter->second.mBufferActionName);
	}
}

void PlayerObject::UpdateBuffAvatar()
{
	std::map<int, _PLAYER_BUFF_INFO_>::iterator iter   = m_PlayerBuffList.begin();
	std::map<int, _PLAYER_BUFF_INFO_>::iterator iter_e = m_PlayerBuffList.end();
	for ( ; iter!=iter_e; )
	{
		std::map<int, _PLAYER_BUFF_INFO_>::iterator temp = iter;
		++iter;

		_PLAYER_BUFF_INFO_& info = temp->second;
		if (info.mIsPlaying)
		{
			if (m_LogicTickCounter >= (info.mBuffStartTime+info.mBuffLastTime))
			{
				info.mIsPlaying = false;
				if (info.mBuffAvatar != NULL)
				{
					info.mBuffAvatar->setVisible(false);
					//由于我的图片仅仅是frame,所以设置为不可见就OK
					//StopEffect(temp->second.mBufferActionName);
					if(temp->first == _SUBTYPE_BUFF_SLOW)
					{
						m_Speed = 8;
					}
				}
			}
		}
	}
}