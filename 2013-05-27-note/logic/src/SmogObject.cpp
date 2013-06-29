#include "../include/SmogObject.h"
#include "../include/InputCommand.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/VariableSystem.h"
#include "../include/SoundSystem.h"
#include "../include/Common.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/PlayerDataManager.h"
#include "../include/LocalPlayerDataManager.h"

SmogObject::SmogObject()
{
	m_ObjectType = _TYPED_OBJECT_SMOGOBJECT_;
	m_ObjectSubType = 0;
}

SmogObject::~SmogObject()
{

}

void SmogObject::Init()
{
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar,true);
	PlayEffect("smogeffect",m_pAvatar);
}

void SmogObject::Tick()
{
	IObject::Tick();
}

void SmogObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		SCENEMANAGER->GetSceneBackgroundLayer()->removeChild(m_pAvatar,true);
		m_pAvatar = NULL;
	}
}


void SmogObject::PushCommand(int commandId, void* pPtr)
{

}

void SmogObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	if(_SUBTYPE_DROP_HERO == m_ObjectSubType)
	{
		//SCENEMANAGER->createAloneHero(2,ccp(GetXPos(),GetYPos()));
		if(SCENEMANAGER->reserveHeros())
		{
			int dropHeros = rand()%10;
			if(dropHeros<8)//80的概率掉落英雄
			{
				int rd = rand()%SCENEMANAGER->reserveHeros();
				SCENEMANAGER->createAloneHero(SCENEMANAGER->getHeroIndexVal(rd),ccp(GetXPos(),GetYPos()));
				SCENEMANAGER->findAndRemove(SCENEMANAGER->getHeroIndexVal(rd));
			}
		}
	}
	else if(_SUBTYPE_DROP_GEMS== m_ObjectSubType)
	{
		//随机是否真的掉落宝石
		int dropGem = rand()%10;
		if(dropGem<2)//20%的概率掉落宝石
		{
			SCENEMANAGER->createGemObject(DiamondObject::_SUBTYPE_GREEN_GEM,ccp(GetXPos(),GetYPos()));
		}
		else//80%的概率不掉落
		{

		}
		//for test
		//SCENEMANAGER->createGemObject(DiamondObject::_SUBTYPE_GREEN_GEM,ccp(GetXPos(),GetYPos()));
	}
	else if(_SUBTYPE_DROP_NOTHING)
	{

	}
	SetIsValid(false);
}

void SmogObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void SmogObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}

void SmogObject::create(cocos2d::CCPoint pt,int subType)
{
	SmogObject* pSmogEffect = new SmogObject;
	pSmogEffect->Init();
	pSmogEffect->SetObjectSubType(subType);
	pSmogEffect->SetXPos(pt.x);
	pSmogEffect->SetYPos(pt.y);
	OBJECTMANAGER->InsertObject(pSmogEffect);
}
