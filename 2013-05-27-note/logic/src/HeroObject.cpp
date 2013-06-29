#include "../include/HeroObject.h"
#include "../include/InputCommand.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/VariableSystem.h"
#include "../include/SoundSystem.h"
#include "../include/Common.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/PlayerDataManager.h"
#include "../include/LocalPlayerDataManager.h"

HeroObject::HeroObject():m_strName("")
{
	m_ObjectType = _TYPED_OBJECT_HEROOBJECT_;
	m_ObjectSubType = 0;
    m_blRun = false;					//是否奔跑
	m_killNum = 0;					    //杀敌数名
    //m_pHeroAvatar = NULL;				//英雄Avatar
	m_isActive = false;					//是否被激活
}

HeroObject::~HeroObject()
{

}

void HeroObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void HeroObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}




void HeroObject::Init()
{
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(cocos2d::CCPoint(0.5f,0.5f));
	SCENEMANAGER->GetSceneLobbyPlayerLayer()->addChild(m_pAvatar);
	char *t = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_LobbyDownActionNmae;
	PlayEffect(t,m_pAvatar);
	StopEffect(PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_LobbyDownActionNmae);
	m_strName = PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_PlayerName;
	
}

void HeroObject::Tick()
{
	IObject::Tick();
}

void HeroObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		SCENEMANAGER->GetSceneLobbyPlayerLayer()->removeChild(m_pAvatar,true);
		m_pAvatar = NULL;
	}
}


void HeroObject::PushCommand(int commandId, void* pPtr)
{

}

void HeroObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	if(m_blRun)
	{
		PlayEffect(animationName,pNode);
	}
}


void HeroObject::setScale(float x)
{
	m_pAvatar->setScale(x);
}

void HeroObject::playAnimation()
{
	m_blRun = true;
	PlayEffect(PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_LobbyDownActionNmae,m_pAvatar);
}

void HeroObject::stopAnimation()
{
	m_blRun = false;
	StopEffect(PlayerDataManager::get_instance2()->GetPlayerById(GetObjectSubType())->m_LobbyDownActionNmae);
}

std::string HeroObject::getHeroName()
{
	return m_strName;
}

void HeroObject::setKillNum(long killNum)
{
	m_killNum = killNum;
}

long HeroObject::getKillNum()
{
	return m_killNum;
}

HeroObject* HeroObject::create(int subType,cocos2d::CCPoint pt)
{
	HeroObject* t = new HeroObject;
	t->m_ObjectSubType = subType;
	//LocalData从0开始
	int LocalIndex = subType -1;
	t->m_isActive = LocalPlayerDataManager::get_instance2()->GetLocalHeroStateByPos(LocalIndex)->m_isActive;
	t->m_killNum = LocalPlayerDataManager::get_instance2()->GetLocalHeroStateByPos(LocalIndex)->m_KillNum;
	t->Init();
	t->SetXPos(pt.x);
	t->SetYPos(pt.y);
	return t;
}

