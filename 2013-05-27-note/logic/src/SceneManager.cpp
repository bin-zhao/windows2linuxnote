#include "../include/SceneManager.h"
#include "../include/VariableSystem.h"
#include "../include/TimeSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ArenaProcedure.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/ObjectManager.h"
#include "../include/EffectObject.h"
#include "../include/Common.h"
#include "../include/InputCommand.h"
#include "../include/SoundSystem.h"
#include "../include/LocalPlayerDataManager.h"
#include "../include/AnimationFileDataManager.h"
#include "../include/PlayerDataManager.h"
#include "../include/WindowManager.h"
#include "../include/IWindow.h"
#include "../include/EngineSystem.h"
#include "../include/PlayerObject.h"
#include "../include/PlayerObject.h"
#include "../include/MarsObject.h"
#include "../include/SmogObject.h"
#include "../include/SwordObject.h"
#include "../include/DiamondObject.h"
#include "../include/WeaponObject.h"
#include <include/UIWindowManager.h>
#include <include/common/Random.h>
#include <include/common/String.h>
#include <include/tinyxml.h>
#include <cocos2d.h>
#include <vector>
#include <string>
using  namespace  uiloader;
using  namespace  cobra_win;


template<> SceneManager* cobra_win::Singleton2<SceneManager>::m_pMySelf = NULL;

SceneManager::SceneManager()
{
	m_LogicTickCounter = 0;

	m_bShakeScene = false;
	m_ShakeSceneBeginTime = 0;

	m_bInverseScene = false;
	m_InverseSceneBeginTime = 0;

	m_TickSpeedFactor = 1.0f;
	m_bTickPaused     = false;
	m_bGameOver       = false;
}

SceneManager::~SceneManager()
{

}

void SceneManager::SetTickSpeedFactor(float speed)
{
	m_TickSpeedFactor = speed;
}

float SceneManager::GetTickSpeedFactor()
{
	return m_TickSpeedFactor;
}

void SceneManager::SetTickPaused(bool bPause)
{
	m_bTickPaused = bPause;
}

bool SceneManager::GetTickPaused()
{
	return m_bTickPaused;
}

cocos2d::CCNode* SceneManager::GetSceneRootLayer()
{
	return (cocos2d::CCNode*)UIWindowManager::get_instance()->GetUIWindow("arena/root");
}

cocos2d::CCNode* SceneManager::GetSceneBackgroundLayer()
{
	return (cocos2d::CCNode*)UIWindowManager::get_instance()->GetUIWindow("arena/backgroundlayer");
}

cocos2d::CCNode* SceneManager::GetScenePlayerLayer()
{
	return (cocos2d::CCNode*)UIWindowManager::get_instance()->GetUIWindow("arena/playerlayer");
}

cocos2d::CCNode* SceneManager::GetSceneEffectLayer()
{
	return (cocos2d::CCNode*)UIWindowManager::get_instance()->GetUIWindow("arena/effectlayer");
}

cocos2d::CCNode* SceneManager::GetSceneInverseLayer()
{
	return (cocos2d::CCNode*)UIWindowManager::get_instance()->GetUIWindow("arena/inverselayer");
}

cocos2d::CCNode* SceneManager::GetSceneLobbyPlayerLayer()
{
	return (cocos2d::CCNode*)UIWindowManager::get_instance()->GetUIWindow("lobby/playerlayer");
}

void SceneManager::InverseScene()
{
	if (m_bInverseScene)
		return;

	m_bInverseScene = true;
	m_InverseSceneBeginTime = TimeSystem::GetCurrentMicroSecond();
	cocos2d::CCLayerColor* pLayer = (cocos2d::CCLayerColor*)GetSceneInverseLayer();
	m_LastInverseBlendFunc = pLayer->getBlendFunc();

	GLenum src;
	GLenum dst;
	if (m_LastInverseBlendFunc.dst == GL_ZERO)
	{
		src = CC_BLEND_SRC;  
		dst = CC_BLEND_DST;
	}
	else
	{
		src = GL_ONE_MINUS_DST_COLOR;  
		dst = GL_ZERO;  
	}

	cocos2d::ccBlendFunc bf = {src, dst};  
	pLayer->setBlendFunc(bf);  
}

void SceneManager::ShakeScene()
{
	if (m_bShakeScene)
		return;

	m_bShakeScene = true;
	m_ShakeSceneBeginTime = TimeSystem::GetCurrentMicroSecond();
}

cocos2d::CCAnimation* SceneManager::GetAnimtionByName(std::string name)
{
	cocos2d::CCAnimation* pAnimation = cocos2d::CCAnimationCache::sharedAnimationCache()->animationByName(name.c_str());
	if (pAnimation == NULL)
	{
		AnimationFileData* pData = AnimationFileDataManager::get_instance2()->GetAnimationByName(name);

		cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(pData->mAnimationFileName);
		cocos2d::CCArray* pArray = new cocos2d::CCArray;

		for (int i=0; i<pData->mAnimationFrameCount; i++)
		{
			char buffer[128] = "";
			sprintf(buffer, "%s_%02d.png", pData->mAnimationPrefix, i+1);
			cocos2d::CCSpriteFrame* spriteFrame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(buffer);
			pArray->addObject(spriteFrame);
		}
		pAnimation = cocos2d::CCAnimation::createWithSpriteFrames(pArray, pData->mAnimationIntervalTime);
		cocos2d::CCAnimationCache::sharedAnimationCache()->addAnimation(pAnimation, pData->mAnimationName);

		pArray->removeAllObjects();
		delete pArray;
	}

	return pAnimation;
}

bool SceneManager::Init()
{
	do 
	{
		// 创建并初始化场景对象管理器
		new ObjectManager;
		if (!OBJECTMANAGER->Init())
			break;
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_ARENAWINDOW_);

		// 获取玩家的选择的英雄
		int playerSelecter = 0;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_MEM_,"PLAYERINDEX","INDEX",playerSelecter);

		// 创建英雄
		PlayerObject* tmpPlayer = PlayerObject::create(playerSelecter,ccp(320,480),true,true,DIR_UP);
		insertIntoHeroList(tmpPlayer);

		// 英雄随机掉落 
		initDropHeroIndexVector();
		findAndRemove(playerSelecter);
		

		//int subTypeBuf[]={18,18,18};
		//m_ppMonsterList.push_back(createMonsterTeam(sizeof(subTypeBuf)/sizeof(int),subTypeBuf,ccp(0,0),DIR_LEFT));

		//int subTypeBuf2[]={18,18};
		//m_ppMonsterList.push_back(createMonsterTeam(sizeof(subTypeBuf2)/sizeof(int),subTypeBuf2,ccp(0,0),DIR_UP));

		//int subTypeBuf3[]={PlayerObject::_SUBTYPE_MONSTER_BOWARROW};
		//m_ppMonsterList.push_back(createMonsterTeam(sizeof(subTypeBuf3)/sizeof(int),subTypeBuf3,ccp(0,0),DIR_UP));
		LOGGERSYSTEM->LogInfo("Init SceneManager Success\n");
		return true;
	} 
	while (false);
	LOGGERSYSTEM->LogInfo("Init SceneManager Failed\n");
	return false;
}

void SceneManager::Tick()
{
	// 所有场景对象逻辑帧更新
	OBJECTMANAGER->Tick();
	// 是否暂停中
	if (m_bTickPaused)
		return;
	m_LogicTickCounter++;
	// 场景震屏更新
	UpdateSceneShake();
	
	// 场景反色效果更新
	UpdateSceneInverse();
	
	// 更新背景图片
	if(!m_bGameOver)
	UpdateBackgroundLayer();

	// 更新队形
	UpdateHeroTeamShape();
	// 更新所有怪物队形
	updateAppMonsterTeamShape();
	// 更新英雄攻击
    updateHeroAttack();
	// 更新怪物攻击
	updateAllMonstersAttack();
	// 更新怪物死亡
	updateMonsterKilled();
	// 更新武器死亡
	updateAllWeaponKilled();
	// 更新英雄死亡
	updateHeroKilled();
	// 更新英雄和宝石的碰撞
	updateCollisionGem2Heros();
	// 更新英雄队伍和孤立英雄的碰撞
	updateCollisionAloneHero2HeroTeam();
	// 英雄队伍与边界
	updateCollisionHero2Bound();
	// 武器和怪物碰撞检测
	updateCollisionWeapon2Monster();
	// 武器和英雄碰撞检测
	updateCollisionWeapon2Heros();
	// 英雄和怪物之间碰撞检测
	updateCollisionHero2Monster();
	//
	FlushMonsters();
}

void SceneManager::Destroy()
{
	// 销毁所有竞技场对象
	if (OBJECTMANAGER != NULL)
	{
		OBJECTMANAGER->Destroy();
		delete OBJECTMANAGER;
	}

	//m_ppMonsterList.

	LOGGERSYSTEM->LogInfo("Destroy SceneManager Success\n");
}

void SceneManager::UpdateSceneShake()
{
	if (m_bShakeScene)
	{
		long long time = TimeSystem::GetCurrentMicroSecond()-m_ShakeSceneBeginTime;
		if (float(time)/float(1000000.0f) >= 0.2f)
		{
			m_bShakeScene = false;
			m_ShakeSceneBeginTime = 0;

			GetSceneRootLayer()->setPositionX(0.0f);
			GetSceneRootLayer()->setPositionY(0.0f);
		}
		else
		{
			int xPos = Random::rand()%6-3;
			int yPos = Random::rand()%14-7;
			GetSceneRootLayer()->setPositionX(float(xPos));
			GetSceneRootLayer()->setPositionY(float(yPos));
		}
	}
}

void SceneManager::UpdateSceneInverse()
{
	if (m_bInverseScene)
	{
		long long time = TimeSystem::GetCurrentMicroSecond()-m_InverseSceneBeginTime;
		if (float(time)/float(1000000.0f) >= 0.4f)
		{
			m_bInverseScene = false;
			m_InverseSceneBeginTime = 0;
			((cocos2d::CCLayerColor*)GetSceneInverseLayer())->setBlendFunc(m_LastInverseBlendFunc);
		}
	}
}

void SceneManager::createPlayerObject(int subType,cocos2d::CCPoint pt,bool IsLeader,bool bIsTeam,DIRECTION dir)
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
}

void SceneManager::createMonsterObject(int subType,cocos2d::CCPoint pt,bool IsLeader,bool bIsTeam,DIRECTION dir)
{
	PlayerObject* pMonster = new PlayerObject;
	pMonster->SetObjectSubType(subType);
	pMonster->bIsLeader = IsLeader;
	pMonster->bIsTeam = bIsTeam;
	pMonster->m_Dir = dir;
	pMonster->Init();
	pMonster->SetXPos(pt.x);
	pMonster->SetYPos(pt.y);
	OBJECTMANAGER->InsertObject(pMonster);
}

void SceneManager::UpdateBackgroundLayer()
{
	//如果英雄队伍为空,则不逻动背景图片
	if(m_pHerosList.empty())
		return;

	//获得队伍的首领
	PlayerObject* pLeader = m_pHerosList.front();
	//更新背景层
	switch(pLeader->m_Dir)
	{
	case DIR_UP:
		SCENEMANAGER->GetSceneBackgroundLayer()->setPositionY( SCENEMANAGER->GetSceneBackgroundLayer()->getPositionY() - pLeader->m_Speed);
		break;
	case DIR_DOWN:
		SCENEMANAGER->GetSceneBackgroundLayer()->setPositionY( SCENEMANAGER->GetSceneBackgroundLayer()->getPositionY() + pLeader->m_Speed);
		break;
	case DIR_LEFT:
		SCENEMANAGER->GetSceneBackgroundLayer()->setPositionX( SCENEMANAGER->GetSceneBackgroundLayer()->getPositionX() + pLeader->m_Speed);
		break;
	case DIR_RIGHT:
		SCENEMANAGER->GetSceneBackgroundLayer()->setPositionX( SCENEMANAGER->GetSceneBackgroundLayer()->getPositionX() - pLeader->m_Speed);
		break;
	}
}




void SceneManager::UpdateHeroTeamShape()
{
	static float len = 0;

	//static int tickerCounter = 0;
	//如果英雄队伍为空,则不逻动背景图片
	if(m_pHerosList.empty())
		return;
	//获取队伍每个人坐标和方向
	std::list<PlayerObject*>::iterator	iter	=	m_pHerosList.begin();
	std::list<PlayerObject*>::iterator	iter_e	=	m_pHerosList.end();
	DIRECTION	leaderdir	=	(*iter)->m_Dir;
	float speed = (*iter)->m_Speed;
	//除了第一个都要做偏移
	iter++;	//跳过第一个
	//根据leader方向更新位置（逆向）
	switch(leaderdir)
	{
	case DIR_UP:
		for(;iter != iter_e; ++iter)
		{
			(*iter)->SetYPos((*iter)->GetYPos() - speed);
		}
		break;
	case DIR_RIGHT:
		for(;iter != iter_e; ++iter)
		{
			(*iter)->SetXPos((*iter)->GetXPos() - speed);
		}
		break;
	case DIR_DOWN:
		for(;iter != iter_e; ++iter)
		{
			(*iter)->SetYPos((*iter)->GetYPos() + speed);
		}
		break;
	case DIR_LEFT:
		for(;iter != iter_e; ++iter)
		{
			(*iter)->SetXPos((*iter)->GetXPos() + speed);
		}
		break;
	}

	//根据自身方向更新位置（顺向）
	iter	=	m_pHerosList.begin();
	iter_e	=	m_pHerosList.end();
	iter++;	//跳过第一个
	for(;iter != iter_e; ++iter)
	{
		switch((*iter)->m_Dir)
		{
		case DIR_UP:
			(*iter)->SetYPos((*iter)->GetYPos() + speed);
			break;
		case DIR_RIGHT:
			(*iter)->SetXPos((*iter)->GetXPos() + speed);
			break;
		case DIR_DOWN:
			(*iter)->SetYPos((*iter)->GetYPos() - speed);
			break;
		case DIR_LEFT:
			(*iter)->SetXPos((*iter)->GetXPos() - speed);
			break;
		}
	}

	//tickerCounter ++;
	len += speed;
	std::vector<int>	posvector;
	//方向改变
	float playerHeight = m_pHerosList.front()->getPlayerObjectHeight();
	//if(tickerCounter == (int)(playerHeight/speed))
	if(len >= playerHeight)
	{
		len = 0;
		//tickerCounter = 0;
		//遍历方向并存储
		iter	=	m_pHerosList.begin();
		iter_e	=	m_pHerosList.end();
		for(;iter != iter_e; ++iter)
		{
			posvector.push_back((*iter)->m_Dir);
		}
		//方向移动（倒序）
		for(int index = posvector.size() - 1; index > 0; index--)
		{
			posvector.at(index) = posvector.at(index - 1);
		}
		//头结点改变方向
		if(!NinjiaTribeApp::get_instance2()->m_pArenaProcedure->dirQueue.empty())
		{
			posvector.at(0) = NinjiaTribeApp::get_instance2()->m_pArenaProcedure->dirQueue.front();
			NinjiaTribeApp::get_instance2()->m_pArenaProcedure->dirQueue.pop();
		}
		//方向赋值
		iter	=	m_pHerosList.begin();
		iter_e	=	m_pHerosList.end();
		for(int i = 0; iter != iter_e; ++iter, i++)
		{
			//判断方向是否改变（用于防止一直调用TurnDir导致动画不播放）
			if((*iter)->m_Dir != DIRECTION(posvector.at(i)))
			{
				(*iter)->m_Dir = DIRECTION(posvector.at(i));
				(*iter)->turnDir();
			}
		}
	}
}

void SceneManager::insertIntoHeroList(PlayerObject *pPlayerObject)
{
	assert(pPlayerObject);
	if(m_pHerosList.empty())
	{
		m_pHerosList.push_back(pPlayerObject);
		return;
	}

	//获取队尾的位置和方向
	PlayerObject *tailPlayer = m_pHerosList.back();
	float tailPlayerPosX = tailPlayer->GetXPos();
	float tailPlayerPosY = tailPlayer->GetYPos();
	float tailPlayerHeight = tailPlayer->getPlayerObjectHeight();
	pPlayerObject->m_Dir = tailPlayer->m_Dir;
	switch(tailPlayer->m_Dir)
	{
	case DIR_UP:
		pPlayerObject->SetXPos(tailPlayerPosX);
		pPlayerObject->SetYPos(tailPlayerPosY - tailPlayerHeight);
		break;
	case DIR_LEFT:
		pPlayerObject->SetYPos(tailPlayerPosY);
		pPlayerObject->SetXPos(tailPlayerPosX + tailPlayerHeight);
		break;
	case DIR_RIGHT:
		pPlayerObject->SetYPos(tailPlayerPosY);
		pPlayerObject->SetXPos(tailPlayerPosX - tailPlayerHeight);
		break;
	case DIR_DOWN:
		pPlayerObject->SetXPos(tailPlayerPosX);
		pPlayerObject->SetYPos(tailPlayerPosY + tailPlayerHeight);
		break;
	}
	pPlayerObject->turnDir();
	m_pHerosList.push_back(pPlayerObject);
}


void SceneManager::insertIntoMonsterList(std::list<PlayerObject*> &pMonsterList,PlayerObject* pMonsterObject)
{
	assert(pMonsterObject);
	if(pMonsterList.empty())
	{
		pMonsterList.push_back(pMonsterObject);
		return;
	}

	//获取队尾的位置和方向
	PlayerObject *tailMonster = pMonsterList.back();
	float tailMonsterPosX = tailMonster->GetXPos();
	float tailMonsterPosY = tailMonster->GetYPos();
	float tailMonsterHeight = tailMonster->getPlayerObjectHeight();
	pMonsterObject->m_Dir = tailMonster->m_Dir;
	switch(tailMonster->m_Dir)
	{
	case DIR_UP:
		pMonsterObject->SetXPos(tailMonsterPosX);
		pMonsterObject->SetYPos(tailMonsterPosY - tailMonsterHeight);
		break;
	case DIR_LEFT:
		pMonsterObject->SetYPos(tailMonsterPosY);
		pMonsterObject->SetXPos(tailMonsterPosX + tailMonsterHeight);
		break;
	case DIR_RIGHT:
		pMonsterObject->SetYPos(tailMonsterPosY);
		pMonsterObject->SetXPos(tailMonsterPosX - tailMonsterHeight);
		break;
	case DIR_DOWN:
		pMonsterObject->SetXPos(tailMonsterPosX);
		pMonsterObject->SetYPos(tailMonsterPosY + tailMonsterHeight);
		break;
	}
	pMonsterList.push_back(pMonsterObject);
}

SceneManager::MonsterListAndTicker SceneManager::createMonsterTeam(int num,int *pPlayerTypeBuf,cocos2d::CCPoint ptPos,DIRECTION dir)
{
	SceneManager::MonsterListAndTicker tmpMonsterListAndTicker;
	tmpMonsterListAndTicker.frametickCounter = 0;

	for(int i=0;i<num;i++)
	{
		PlayerObject* t = PlayerObject::create(pPlayerTypeBuf[i],ptPos,false,false,dir);
		if(0 == i)
			tmpMonsterListAndTicker.changeDirTickCounter = (int)(t->getPlayerObjectHeight()/t->m_Speed);
		insertIntoMonsterList(tmpMonsterListAndTicker.pMonsterList,t);
	}
	return tmpMonsterListAndTicker;
}

cocos2d::CCPoint SceneManager::playerLayerPos2bkLayerPos(cocos2d::CCPoint playerLayerPos)
{
	return ccp(playerLayerPos.x - GetSceneBackgroundLayer()->getPositionX(),playerLayerPos.y - GetSceneBackgroundLayer()->getPositionY());
}

cocos2d::CCPoint SceneManager::playerLayerPos2bkLayerPos(float playerLayerPosx,float playerLayerPosy)
{
	return ccp(playerLayerPosx - GetSceneBackgroundLayer()->getPositionX(),playerLayerPosy - GetSceneBackgroundLayer()->getPositionY());
}

cocos2d::CCPoint SceneManager::bkLayerPos2playerLayerPos(cocos2d::CCPoint bkLayerPos)
{
	return ccp(bkLayerPos.x + GetSceneBackgroundLayer()->getPositionX(),bkLayerPos.y + GetSceneBackgroundLayer()->getPositionY());
}

cocos2d::CCPoint SceneManager::bkLayerPos2playerLayerPos(float bkLayerPosx,float bkLayerPosy)
{
	return ccp(bkLayerPosx + GetSceneBackgroundLayer()->getPositionX(),bkLayerPosy + GetSceneBackgroundLayer()->getPositionY());
}

void SceneManager::UpdateMonsterTeamShape(MonsterListAndTicker &MonsterListAndTicker)
{
	static int counter = 0;

	//获取相关引用,方便操作
	std::list<PlayerObject*> &pMonsterList = MonsterListAndTicker.pMonsterList;
	int &frametickCounter = MonsterListAndTicker.frametickCounter;
	int &changeDirTickCounter = MonsterListAndTicker.changeDirTickCounter;
	//帧计数+1
	frametickCounter++;
	//获取队伍每个人的坐标和方向
	std::list<PlayerObject*>::iterator	iter	=	pMonsterList.begin();
	std::list<PlayerObject*>::iterator	iter_e	=	pMonsterList.end();

	if((*iter)->GetObjectSubType() == PlayerObject::_SUBTYPE_MONSTER_BOWARROW)//如果为弓箭手则直接改变方向
	{
		(*iter)->m_Dir = changeMonsterTeamDirction((*iter)->getPos(),(*iter)->m_Dir);
	}
	else
	{
		//按着自己的方向顺序移动
		float x = 0;
		float y = 0;
		float speed = 0;
		DIRECTION dir = DIR_OTHER;
		for(;iter != iter_e; iter++)
		{
			x = (*iter)->GetXPos();
			y = (*iter)->GetYPos();
			speed = (*iter)->m_Speed;
			dir = (*iter)->m_Dir;

			switch(dir)
			{
			case DIR_UP:
				(*iter)->SetYPos( y + speed);
				break;
			case DIR_RIGHT:
				(*iter)->SetXPos( x + speed);
				break;
			case DIR_DOWN:
				(*iter)->SetYPos( y - speed);
				break;
			case DIR_LEFT:
				(*iter)->SetXPos( x - speed);
				break;
			}
		}

		std::vector<DIRECTION>	posvector;
		if(frametickCounter == changeDirTickCounter)
		{

			frametickCounter = 0;
			//遍历方向并存储
			iter	=	pMonsterList.begin();
			iter_e	=	pMonsterList.end();
			for(;iter != iter_e; ++iter)
			{
				posvector.push_back( (*iter)->m_Dir );
			}
			//方向移动（倒序）
			for(int index = posvector.size()- 1; index > 0; index--)
			{
				posvector.at(index) = posvector.at(index-1);
			}

			//头节点改变方向
			iter 	= pMonsterList.begin();
			posvector.at(0) = changeMonsterTeamDirction(ccp((*iter)->GetXPos(),(*iter)->GetYPos()),posvector.at(0));


			//方向赋值
			iter 	= pMonsterList.begin();
			iter_e	=	pMonsterList.end();
			for( int i=0; iter != iter_e; ++iter, i++)
			{
				//判断方向改变（用于防止一直调用TurnDir导致动画不播放）
				if( (*iter)->m_Dir != posvector.at(i))
				{
					(*iter)->m_Dir = posvector.at(i);
					(*iter)->turnDir();
				}
			}
		}
	}	
}





void SceneManager::FlushMonsters()//以后可能大幅度改动
{
	static long long   m_PreFlushMonsterTime=0; 

	cocos2d::CCPoint	pt[4] = { ccp(200, 200), ccp(-150, 300), ccp(200, 500), ccp(-20, 940), };
	DIRECTION direction[]={DIR_UP,DIR_LEFT,DIR_DOWN,DIR_RIGHT,};
	m_PreFlushMonsterTime++;
	if(m_PreFlushMonsterTime > 150 )
	{
		m_PreFlushMonsterTime = 0;
		srand((unsigned)time(NULL));
		int	team 					= 	rand()%2;		//队伍or单个
		int	dir						=	rand()%4;		//方向
		cocos2d::CCPoint	born 	= 	pt[rand()%4];	//出生地
		if(team)
		{
			int subTypeBuf[]={18,16,18};
			m_ppMonsterList.push_back(createMonsterTeam(sizeof(subTypeBuf)/sizeof(int),subTypeBuf,born,direction[dir]));
		}
		else
		{
			int active	=	rand()%2;	//蜘蛛or人
			if(active)
			{
				int subTypeBuf[]={18};
				m_ppMonsterList.push_back(createMonsterTeam(sizeof(subTypeBuf)/sizeof(int),subTypeBuf,born,direction[dir]));
			}
			else//人
			{
				int subTypeBuf[]={17};
				m_ppMonsterList.push_back(createMonsterTeam(sizeof(subTypeBuf)/sizeof(int),subTypeBuf,born,direction[dir]));
			}
			
		}
	}
}

void SceneManager::updateAppMonsterTeamShape()
{
	std::list<SceneManager::MonsterListAndTicker>::iterator iter =	m_ppMonsterList.begin();
	std::list<SceneManager::MonsterListAndTicker>::iterator iter_e = m_ppMonsterList.end();
	for(;iter!=iter_e;iter++)
	{
		// 更新怪物队形
		UpdateMonsterTeamShape(*iter);
	}
}

void SceneManager::updateHeroAttack()
{
	//如果英雄队伍已经死亡,则直接跳过
	if(m_pHerosList.empty())
		return;

	std::list<PlayerObject*>::iterator iter = m_pHerosList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_pHerosList.end();

	//获取所有怪物坐标
	std::vector<SceneManager::PersonPointerAndPos> allMonstersVector;
	//引用传递
	getAllMonsterPosandPointer(allMonstersVector);


	//遍历队伍中每个英雄
	for(;iter != iter_e;)
	{
		std::list<PlayerObject*>::iterator temp = iter;
		++iter;
		PlayerObject* player = *temp;
		//将英雄的PlayerLayer坐标转换为BkLayer坐标
		//cocos2d::CCPoint heroBkPos = playerLayerPos2bkLayerPos(ccp(player->GetXPos(),player->GetYPos()));
		//判断攻击范围内是否有怪物,有则创建武器对象
		for(unsigned int i=0;i<allMonstersVector.size();i++)
		{
			if(player->isInAttackScope(allMonstersVector.at(i).pos))
			{
				//创建攻击对象
				if(player->Attack(allMonstersVector.at(i).pos))
				{
					//给怪物发送伤害消息
					for(unsigned int j=0;j<allMonstersVector.size();j++)
					{
						if(player->isInAttackScope(allMonstersVector.at(j).pos))
						{
							allMonstersVector.at(j).pPerson->PushCommand(_TYPED_INPUT_COMMAND_HEROTOMONSTER_,player);//此处传递的是英雄的指针				
						}
					}
				}				
				break;
			}
		}		
	}
}



void SceneManager::getAllMonsterPos(std::vector<cocos2d::CCPoint> &posVector)
{
	std::list<SceneManager::MonsterListAndTicker>::iterator iter =	m_ppMonsterList.begin();
	std::list<SceneManager::MonsterListAndTicker>::iterator iter_e = m_ppMonsterList.end();
	for(;iter!=iter_e;iter++)
	{
		// 获取队伍中怪物坐标
		getMonsterTeamPos(*iter,posVector);
	}
}

void SceneManager::getMonsterTeamPos(MonsterListAndTicker &MonsterListAndTicker,std::vector<cocos2d::CCPoint> &posVector)
{
	//获取相关引用,方便操作
	std::list<PlayerObject*> &pMonsterList = MonsterListAndTicker.pMonsterList;
	//获取队伍每个人的坐标
	std::list<PlayerObject*>::iterator	iter	=	pMonsterList.begin();
	std::list<PlayerObject*>::iterator	iter_e	=	pMonsterList.end();
	for(;iter != iter_e; iter++)
	{
		posVector.push_back(ccp((*iter)->GetXPos(),(*iter)->GetYPos()));
	}
}



void SceneManager::getAllMonsterPosandPointer(std::vector<SceneManager::PersonPointerAndPos> &MonsterVector)
{
	std::list<SceneManager::MonsterListAndTicker>::iterator iter =	m_ppMonsterList.begin();
	std::list<SceneManager::MonsterListAndTicker>::iterator iter_e = m_ppMonsterList.end();
	for(;iter!=iter_e;iter++)
	{
		// 获取队伍中怪物坐标
		getMonsterTeamPosandPointer(*iter,MonsterVector);
	}
}

void SceneManager::getMonsterTeamPosandPointer(MonsterListAndTicker &MonsterListAndTicker,std::vector<SceneManager::PersonPointerAndPos> &MonsterVector)
{
	//获取相关引用,方便操作
	std::list<PlayerObject*> &pMonsterList = MonsterListAndTicker.pMonsterList;
	//获取队伍每个人的坐标和指针,方便发送被攻击消息
	std::list<PlayerObject*>::iterator	iter	=	pMonsterList.begin();
	std::list<PlayerObject*>::iterator	iter_e	=	pMonsterList.end();

	SceneManager::PersonPointerAndPos tmp;
	for(;iter != iter_e; iter++)
	{
		tmp.pos = ccp((*iter)->GetXPos(),(*iter)->GetYPos());
		tmp.pPerson = (*iter);
		MonsterVector.push_back(tmp);
	}
}

//除掉死亡的怪物
void SceneManager::updateMonsterKilled()
{
	std::list<SceneManager::MonsterListAndTicker>::iterator iter =	m_ppMonsterList.begin();
	std::list<SceneManager::MonsterListAndTicker>::iterator iter_e = m_ppMonsterList.end();
	for(;iter!=iter_e;)
	{
		std::list<SceneManager::MonsterListAndTicker>::iterator tmp = iter;
		iter++;

		//获取相关引用,方便操作
		std::list<PlayerObject*> &pMonsterList = (*tmp).pMonsterList;
		//获取队伍每个人的坐标和指针,方便发送被攻击消息
		std::list<PlayerObject*>::iterator	iter_monster	=	pMonsterList.begin();
		std::list<PlayerObject*>::iterator	iter_monster_e	=	pMonsterList.end();


		//如果是怪物队伍的首领死掉
		if((*iter_monster)->getPlayerHP() <= 0)
		{
			//获取整个队伍的对象setisvalid(false)
			//iter_monsterTeam	=	pMonsterList.begin();
			//iter_monsterTeam_e	=	pMonsterList.end();
			for(;iter_monster!=iter_monster_e;iter_monster++)
			{
				SmogObject::create(ccp((*iter_monster)->GetXPos(),(*iter_monster)->GetYPos()),SmogObject::_SUBTYPE_DROP_GEMS);
				(*iter_monster)->SetIsValid(false);
			}
			m_ppMonsterList.erase(tmp);
		}
		else
		{
			//遍历整个队伍的对象
			for(;iter_monster!=iter_monster_e;)
			{
				std::list<PlayerObject*>::iterator tmpMonster_iter = iter_monster;
				iter_monster++;
				if((*tmpMonster_iter)->getPlayerHP() <= 0)
				{
					cocos2d::CCPoint prept = ccp((*tmpMonster_iter)->GetXPos(),(*tmpMonster_iter)->GetYPos());
					cocos2d::CCPoint curpt;
					SmogObject::create(ccp((*tmpMonster_iter)->GetXPos(),(*tmpMonster_iter)->GetYPos()),SmogObject::_SUBTYPE_DROP_HERO);
					//后面对象的在场景中的位置需要更新
					std::list<PlayerObject*>::iterator tmpMonster_iter2 = iter_monster;
					for(;tmpMonster_iter2!=iter_monster_e;tmpMonster_iter2++)
					{
						curpt.x = (*tmpMonster_iter2)->GetXPos();
						curpt.y = (*tmpMonster_iter2)->GetYPos();
						(*tmpMonster_iter2)->SetXPos(prept.x);
						(*tmpMonster_iter2)->SetYPos(prept.y);
						prept = curpt;						
					}
					//让怪物对象从objectmanager释放
					(*tmpMonster_iter)->SetIsValid(false);
					//队伍节点释放
					pMonsterList.erase(tmpMonster_iter);
				}
			}
		}
	}
}

void SceneManager::createGemObject(int subType,cocos2d::CCPoint pt)
{
	m_pGemsList.push_back(DiamondObject::create(subType,pt));
}

void SceneManager::createAloneHero(int subType,cocos2d::CCPoint pt)
{
	m_AloneHeroList.push_back(PlayerObject::create(subType,pt,false,false,DIR_DOWN));
}

void SceneManager::updateCollisionAloneHero2HeroTeam()
{
	//如果英雄队伍已经死亡,则直接跳过
	if(m_pHerosList.empty())
		return;
	//获取队伍首领
	PlayerObject *leader = m_pHerosList.front();
	int subPlayerType = inAloneHeroScope(SceneManager::playerLayerPos2bkLayerPos(ccp(leader->GetXPos(),leader->GetYPos())));
	if(PlayerObject::_SUBTYPE_HERO_UNKOWN != subPlayerType)
	{
		insertIntoHeroList(PlayerObject::create(subPlayerType));
	}
}

//************************************
// Method:    inAloneHeroScope
// FullName:  SceneManager::inAloneHeroScope
// Access:    public 
// Returns:   返回英雄类型(注意)
// Qualifier:
// Parameter: cocos2d::CCPoint atBkLayerpt
//************************************
int SceneManager::inAloneHeroScope(cocos2d::CCPoint atBkLayerpt)
{
	int ret = PlayerObject::_SUBTYPE_HERO_UNKOWN;
	std::list<PlayerObject*>::iterator iter = m_AloneHeroList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_AloneHeroList.end();

	for(;iter!=iter_e;)
	{
		std::list<PlayerObject*>::iterator tmpiter = iter;
		iter++;
		float dx = atBkLayerpt.x - (*tmpiter)->GetXPos();
		float dy = atBkLayerpt.y - (*tmpiter)->GetYPos();
		float len = ::sqrt(dx*dx + dy*dy);
		if(len < 70)
		{
			ret = (*tmpiter)->GetObjectSubType();
			(*tmpiter)->SetIsValid(false);
			m_AloneHeroList.erase(tmpiter);
			break;
		}
	}
	return ret;
}

void SceneManager::updateCollisionGem2Heros()
{
	//如果英雄队伍已经死亡,则直接跳过
	if(m_pHerosList.empty())
		return;
	//获取队伍首领
	PlayerObject *leader = m_pHerosList.front();
	inGemsScope(SceneManager::playerLayerPos2bkLayerPos(ccp(leader->GetXPos(),leader->GetYPos())));
}

void SceneManager::inGemsScope(cocos2d::CCPoint atBkLayerpt)
{
	std::list<DiamondObject*>::iterator iter = m_pGemsList.begin();
	std::list<DiamondObject*>::iterator iter_e = m_pGemsList.end();

	for(;iter!=iter_e;)
	{
		std::list<DiamondObject*>::iterator tmpiter = iter;
		iter++;
		float dx = atBkLayerpt.x - (*tmpiter)->GetXPos();
		float dy = atBkLayerpt.y - (*tmpiter)->GetYPos();
		float len = ::sqrt(dx*dx + dy*dy);
		if(len < 70)
		{
			(*tmpiter)->SetIsValid(false);
			m_pGemsList.erase(tmpiter);
		}
	}
}

DIRECTION SceneManager::changeMonsterTeamDirction(cocos2d::CCPoint leaderPtAtBkLayer,DIRECTION dir)
{
	int rd = rand()%10;
	DIRECTION tmpdir = dir;
	if(rd < 3)//30%的概率改变方向
	{
		do 
		{
			tmpdir = getrandDirectTion(tmpdir);
		}
		while (targetPosHaveMonster(getDstPos(leaderPtAtBkLayer,tmpdir))||targettPosIsBound(getDstPos(leaderPtAtBkLayer,tmpdir)));
	}
	else//70%的概率方向不变
	{
		//判断朝着原始方向走是否会遇到边界
		while (targetPosHaveMonster(getDstPos(leaderPtAtBkLayer,tmpdir))||targettPosIsBound(getDstPos(leaderPtAtBkLayer,tmpdir)))
		{
			tmpdir = getrandDirectTion(tmpdir);
		}
	}
	return tmpdir;
}

cocos2d::CCPoint SceneManager::getDstPos(const cocos2d::CCPoint leaderPtAtBkLayer,DIRECTION dir)
{
	cocos2d::CCPoint dstPos;
	//MonsterData* pMonsterData = MonsterDataManager::get_instance2()->GetMonsterById(1);

	PlayerData* pMonsterData=PlayerDataManager::get_instance2()->GetPlayerById(16);
	assert(pMonsterData != NULL);
	float height = pMonsterData->m_Height;
	switch(dir)
	{
	case DIR_UP:
		dstPos = ccp(leaderPtAtBkLayer.x,leaderPtAtBkLayer.y+height);
		break;
	case DIR_DOWN:
		dstPos = ccp(leaderPtAtBkLayer.x,leaderPtAtBkLayer.y-height);
		break;
	case DIR_LEFT:
		dstPos = ccp(leaderPtAtBkLayer.x-height,leaderPtAtBkLayer.y);
		break;
	case DIR_RIGHT:
		dstPos = ccp(leaderPtAtBkLayer.x+height,leaderPtAtBkLayer.y);
		break;
	}
	return dstPos;
}

bool SceneManager::targetPosHaveMonster(cocos2d::CCPoint pos)
{
	std::vector<cocos2d::CCPoint> posVector;
	getAllMonsterPos(posVector);
	for(unsigned int i=0;i<posVector.size();i++)
	{
		if(posVector.at(i).equals(pos))
		{
			return true;
		}
	}
	return false;
}

bool SceneManager::targettPosIsBound(cocos2d::CCPoint pos)
{
	if(pos.x < LEFTBOUND)
	{
		return true;
	}
	else if(pos.x > RIGHTBOUND)
	{
		return true;
	}
	else if(pos.y > UPBOUND)
	{
		return true;
	}
	else if(pos.y < DOWNBOUND)
	{
		return true;
	}
	return false;
}

//************************************
// Method:    getrandDirectTion
// FullName:  getrandDirectTion
// Access:    public 
// Returns:   DIRECTION
// Qualifier:
// Parameter: DIRECTION orgdir
//            传入原始方向,过滤掉回头走的方向
//************************************
DIRECTION SceneManager::getrandDirectTion(DIRECTION orgdir)
{
	DIRECTION dir[]=
	{DIR_UP,
	DIR_LEFT,
	DIR_DOWN,
	DIR_RIGHT,
	};
	//让队伍的头不能后退
	DIRECTION tmpdir = DIR_OTHER;
	switch(orgdir)
	{
	case DIR_UP:
		do
		{
			tmpdir	=	dir[rand()%4];
		}
		while( tmpdir == DIR_DOWN );
		break;
	case DIR_DOWN:
		do
		{
			tmpdir	=	dir[rand()%4];
		}
		while( tmpdir == DIR_UP );
		break;
	case DIR_LEFT:
		do
		{
			tmpdir	=	dir[rand()%4];
		}
		while( tmpdir == DIR_RIGHT );
		break;
	case DIR_RIGHT:
		do
		{
			tmpdir	=	dir[rand()%4];
		}
		while( tmpdir == DIR_LEFT );
		break;
	}
	return tmpdir;
}

void SceneManager::updateCollisionHero2Bound()
{
	if(m_pHerosList.empty())
		return;
	cocos2d::CCPoint playerLayerPos = ccp(m_pHerosList.front()->GetXPos(),m_pHerosList.front()->GetYPos());
	cocos2d::CCPoint bkLayerPos = playerLayerPos2bkLayerPos(playerLayerPos);
	if(targettPosIsBound(bkLayerPos))
	{
		gameOver();
	}
}

void SceneManager::createWeapon(int subType,cocos2d::CCPoint birthPt,cocos2d::CCPoint dstPt)
{
	WeaponObject *tmp = WeaponObject::create(subType,birthPt,dstPt);
	if(tmp->getIsGood())//如果属于我方则
	{
		m_pWeaponObjectGoodList.push_back(tmp);
	}
	else
	{
		m_pWeaponObjectBadList.push_back(tmp);
	}
}

void SceneManager::updateCollisionWeapon2Monster()
{
	//如果英雄武器对象容器为空
	if(m_pWeaponObjectGoodList.empty())
		return;
	std::list<WeaponObject*>::iterator iter = m_pWeaponObjectGoodList.begin();
	std::list<WeaponObject*>::iterator iter_e = m_pWeaponObjectGoodList.end();
	
	//获取所有怪物坐标
	std::vector<SceneManager::PersonPointerAndPos> allMonstersVector;
	//引用传递
	getAllMonsterPosandPointer(allMonstersVector);
	
	//遍历所有武器对象
	for(;iter!=iter_e;)
	{
		std::list<WeaponObject*>::iterator temp = iter;
		++iter;
		WeaponObject* weapon = *temp;
		//判断武器当前是否有怪物,有则给怪物发送伤害消息
		for(unsigned int i=0;i<allMonstersVector.size();i++)
		{
			cocos2d::CCPoint monsterPos = allMonstersVector.at(i).pos;
			if(weapon->isInAttackScope(monsterPos))//在武器的碰撞检测范围内
			{
				//判断武器是否有溅射能力
				if(weapon->getIsHasSpreadAbility())
				{
					//给武器发送播放爆炸动画消息
					weapon->PushCommand(_TYPED_INPUT_COMMAND_WEAPON_PLAYEFFECT_,NULL);
					//给所有在范围的怪物发送掉血消息
					//给怪物发送伤害消息
					for(unsigned int j=0;j<allMonstersVector.size();j++)
					{
						if(weapon->isInEffectAttackScope(allMonstersVector.at(j).pos))
						{
							allMonstersVector.at(j).pPerson->PushCommand(_TYPED_INPUT_COMMAND_HEROWEAPONTOMONSTER_,(void*)weapon);//此处传递英雄武器对象				
						}
					}
					m_pWeaponObjectGoodList.erase(temp);
					//注意:有溅射能力的武器将在播放完动画后从objectmanager里面释放出来
					//      这里只需要释放结点
				}
				else//如果没有则直接给怪物发送伤害消息
				{
					allMonstersVector.at(i).pPerson->PushCommand(_TYPED_INPUT_COMMAND_HEROWEAPONTOMONSTER_,(void*)weapon);////此处传递英雄武器对象		
					//将武器对象setisvalid(false)
					weapon->SetIsValid(false);
					//将节点从武器容器中删除
					m_pWeaponObjectGoodList.erase(temp);
				}	
				//因为已经检测到碰撞,所以跳出循环检测
				break;
			}			
		}
	}
}


void SceneManager::updateAllMonstersAttack()
{
	//如果怪物已经死亡,则直接跳过
	if(m_ppMonsterList.empty())
		return;

	std::list<SceneManager::MonsterListAndTicker>::iterator iter =	m_ppMonsterList.begin();
	std::list<SceneManager::MonsterListAndTicker>::iterator iter_e = m_ppMonsterList.end();
	for(;iter!=iter_e;iter++)
	{
		// 更新怪物队伍中的攻击
		UpdateMonsterTeamAttack(*iter);
	}
}

//创建英雄队伍的攻击
void SceneManager::UpdateMonsterTeamAttack(MonsterListAndTicker &MonsterListAndTicker)
{
	//获取相关引用,方便操作
	std::list<PlayerObject*> &pMonsterList = MonsterListAndTicker.pMonsterList;
	//
	std::list<PlayerObject*>::iterator iter = pMonsterList.begin();
	std::list<PlayerObject*>::iterator iter_e = pMonsterList.end();

	//获取所有英雄坐标
	std::vector<SceneManager::PersonPointerAndPos> allHerosVector;

	//引用传递
	getAllHeroPosandPointer(allHerosVector);

	//遍历队伍中每个怪物
	for(;iter != iter_e;)
	{
		std::list<PlayerObject*>::iterator temp = iter;
		++iter;
		PlayerObject* monster = *temp;
		//将英雄的PlayerLayer坐标转换为BkLayer坐标
		//cocos2d::CCPoint heroBkPos = playerLayerPos2bkLayerPos(ccp(player->GetXPos(),player->GetYPos()));
		//判断攻击范围内是否有怪物,有则创建武器对象
		for(unsigned int i=0;i<allHerosVector.size();i++)
		{
			cocos2d::CCPoint heroPos = allHerosVector.at(i).pos;
			cocos2d::CCPoint heroPosatBk = playerLayerPos2bkLayerPos(heroPos);

			if(monster->isInAttackScope(heroPosatBk))//如果在怪物的攻击范围之内
			{
				//创建攻击对象
				if(monster->Attack(heroPosatBk))
				{
					//给怪物发送伤害消息
					for(unsigned int j=0;j<allHerosVector.size();j++)
					{
						if(monster->isInAttackScope(heroPosatBk))
						{
							allHerosVector.at(j).pPerson->PushCommand(_TYPED_INPUT_COMMAND_MONSTERTOHERO,(void*)monster);//此处传递怪物对象指针				
						}
					}
				}				
				break;
			}
		}		
	}
}

void SceneManager::getAllHeroPosandPointer(std::vector<SceneManager::PersonPointerAndPos> &allHerosVector)
{
	//如果英雄队伍为空则直接返回
	if(m_pHerosList.empty())
		return;
	std::list<PlayerObject*>::iterator iter = m_pHerosList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_pHerosList.end();
	SceneManager::PersonPointerAndPos tmp;
	for(;iter!=iter_e;iter++)
	{
		tmp.pos=(*iter)->getPos();
		tmp.pPerson = (*iter);
		allHerosVector.push_back(tmp);
	}
}

//怪物武器和英雄的碰撞
void SceneManager::updateCollisionWeapon2Heros()
{
	//如果怪物武器对象容器为空
	if(m_pWeaponObjectBadList.empty())
		return;
	std::list<WeaponObject*>::iterator iter = m_pWeaponObjectBadList.begin();
	std::list<WeaponObject*>::iterator iter_e = m_pWeaponObjectBadList.end();

	//获取所有怪物坐标
	std::vector<SceneManager::PersonPointerAndPos> allHerossVector;
	//引用传递
	getAllHeroPosandPointer(allHerossVector);

	//遍历所有怪物武器对象
	for(;iter!=iter_e;)
	{
		std::list<WeaponObject*>::iterator temp = iter;
		++iter;
		WeaponObject* weapon = *temp;
		//判断武器当前是否有怪物,有则给怪物发送伤害消息
		for(unsigned int i=0;i<allHerossVector.size();i++)
		{
			cocos2d::CCPoint heroPos = allHerossVector.at(i).pos;
			cocos2d::CCPoint heroPosAtbk = playerLayerPos2bkLayerPos(heroPos);
			if(weapon->isInAttackScope(heroPosAtbk))//在武器的碰撞检测范围内
			{
				//判断武器是否有溅射能力
				if(weapon->getIsHasSpreadAbility()||(weapon->getLiveTicker()>weapon->getDeadTicker()))
				{
					//给武器发送播放爆炸动画消息
					weapon->PushCommand(_TYPED_INPUT_COMMAND_WEAPON_PLAYEFFECT_,NULL);
					//给所有在范围的怪物发送掉血消息
					//给怪物发送伤害消息
					float atkDamage = weapon->getAttackDamage();
					for(unsigned int j=0;j<allHerossVector.size();j++)
					{
						if(weapon->isInEffectAttackScope(heroPosAtbk))
						{
							allHerossVector.at(j).pPerson->PushCommand(_TYPED_INPUT_COMMAND_MONSTERWEAPONTOHERO_,(void*)weapon);//此处传递怪物武器指针				
						}
					}
					m_pWeaponObjectBadList.erase(temp);
					//注意:有溅射能力的武器将在播放完动画后从objectmanager里面释放出来
					//      这里只需要释放结点
				}
				else//如果没有则直接给怪物发送伤害消息
				{
					float atkDamage = weapon->getAttackDamage();
					allHerossVector.at(i).pPerson->PushCommand(_TYPED_INPUT_COMMAND_MONSTERWEAPONTOHERO_,(void*)weapon);//此处传递怪物武器指针
					//将武器对象setisvalid(false)
					weapon->SetIsValid(false);
					//将节点从武器容器中删除
					m_pWeaponObjectBadList.erase(temp);
				}	
				//因为已经检测到碰撞,所以跳出循环检测
				break;
			}			
		}
	}
}
//武器死亡更新
void SceneManager::updateAllWeaponKilled()
{
	//把死亡的武器从容器中去掉
	std::list<WeaponObject*>::iterator iter = m_pWeaponObjectGoodList.begin();
	std::list<WeaponObject*>::iterator iter_e = m_pWeaponObjectGoodList.end();
	for(;iter!=iter_e;)
	{
		std::list<WeaponObject*>::iterator tmp = iter;
		iter++;
		if((*tmp)->getLiveTicker()>(*tmp)->getDeadTicker())
		{
			if(!(*tmp)->getIsHasSpreadAbility())
			{
				(*tmp)->SetIsValid(false);
				m_pWeaponObjectGoodList.erase(tmp);
			}
		}
	}
	//把死亡的武器从容器中去掉
	iter = m_pWeaponObjectBadList.begin();
	iter_e = m_pWeaponObjectBadList.end();
	for(;iter!=iter_e;)
	{
		std::list<WeaponObject*>::iterator tmp = iter;
		iter++;
		if((*tmp)->getLiveTicker()>(*tmp)->getDeadTicker())
		{
			if(!(*tmp)->getIsHasSpreadAbility())
			{
				(*tmp)->SetIsValid(false);
				m_pWeaponObjectBadList.erase(tmp);
			}
		}
	}
}

//所有英雄减速
void SceneManager::allHerosSlowDown()
{
	std::list<PlayerObject*>::iterator iter = m_pHerosList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_pHerosList.end();
	for(;iter!=iter_e;iter++)
	{
		(*iter)->PlayBuffEffect(PlayerObject::_SUBTYPE_BUFF_SLOW);
	}
}

void SceneManager::gameOver()
{
	std::list<PlayerObject*>::iterator iter = m_pHerosList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_pHerosList.end();
	for(;iter!=iter_e;)
	{
		std::list<PlayerObject*>::iterator iter_tmp = iter;
		iter++;
		(*iter_tmp)->SetIsValid(false);
		SmogObject::create(playerLayerPos2bkLayerPos((*iter_tmp)->getPos()),SmogObject::_SUBTYPE_DROP_NOTHING);
		m_pHerosList.erase(iter_tmp);
	}
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_GAMEOVERWINDOW_);
	setGameOver(true);
}

void SceneManager::updateCollisionHero2Monster()
{
	if(m_pHerosList.empty())
		return;
	if(m_ppMonsterList.empty())
		return;
	std::vector<cocos2d::CCPoint> monstersPos;
	getAllMonsterPos(monstersPos);
	std::list<PlayerObject*>::iterator iter = m_pHerosList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_pHerosList.end();
	for(;iter!=iter_e;)
	{
		std::list<PlayerObject*>::iterator iter_tmp = iter;
		iter++;

		for(int i=0;i<monstersPos.size();i++)
		{
			cocos2d::CCPoint heroAtBkPos = playerLayerPos2bkLayerPos((*iter_tmp)->getPos());
			float dx = heroAtBkPos.x - monstersPos.at(i).x;
			float dy = heroAtBkPos.y - monstersPos.at(i).y;
			float len = ::sqrt(dx*dx+dy*dy);
			if(len<50)
			{
				//是否为首领
				if(iter_tmp == m_pHerosList.begin())
				{
					gameOver();
					break;
				}
				else
				{					
					SmogObject::create(playerLayerPos2bkLayerPos((*iter_tmp)->getPos()),SmogObject::_SUBTYPE_DROP_NOTHING);
					(*iter_tmp)->SetIsValid(false);
					m_pHerosList.erase(iter_tmp);
				}				
			}
		}

		if(getGameOver())
		{
			//如果游戏结束则直接跳出
			break;
		}
	}
}

void SceneManager::updateHeroKilled()
{
	std::list<PlayerObject*>::iterator iter = m_pHerosList.begin();
	std::list<PlayerObject*>::iterator iter_e = m_pHerosList.end();
	for(;iter!=iter_e;)
	{
		std::list<PlayerObject*>::iterator iter_tmp = iter;
		iter++;

		if((*iter_tmp)->getPlayerHP()<=0)
		{
			if(iter_tmp == m_pHerosList.begin())
			{
				gameOver();
				break;
			}
			else
			{
				cocos2d::CCPoint prept = ccp((*iter_tmp)->GetXPos(),(*iter_tmp)->GetYPos());
				cocos2d::CCPoint curpt;
				SmogObject::create(playerLayerPos2bkLayerPos((*iter_tmp)->GetXPos(),(*iter_tmp)->GetYPos()),SmogObject::_SUBTYPE_DROP_NOTHING);
				//后面对象的在场景中的位置需要更新
				std::list<PlayerObject*>::iterator iter_tmp2 = iter_tmp;
				for(;iter_tmp2!=iter_e;iter_tmp2++)
				{
					curpt.x = (*iter_tmp2)->GetXPos();
					curpt.y = (*iter_tmp2)->GetYPos();
					(*iter_tmp2)->SetXPos(prept.x);
					(*iter_tmp2)->SetYPos(prept.y);
					prept = curpt;						
				}
				//队伍位置更新
				(*iter_tmp)->SetIsValid(false);
				m_pHerosList.erase(iter_tmp);
			}			
		}
	}
}



bool SceneManager::findAndRemove(int n)
{
	std::vector<int>::iterator iter = m_heroIndexSave.begin();
	std::vector<int>::iterator iter_e = m_heroIndexSave.end();
	for(;iter!=iter_e;)
	{
		std::vector<int>::iterator tmp = iter;
		iter++;
		if((*tmp) == n)
		{
			m_heroIndexSave.erase(tmp);
			return true;
		}
	}

	return false;
}

void SceneManager::initDropHeroIndexVector()
{
	for(int i=0;i<3;i++)
	{
		m_heroIndexSave.push_back(i+1);//存1,2,3
	}
}

int SceneManager::reserveHeros()
{
	return m_heroIndexSave.size();
}

int SceneManager::getHeroIndexVal(int index)
{
	return  m_heroIndexSave[index];
}