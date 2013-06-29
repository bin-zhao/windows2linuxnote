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

SwordObject::SwordObject()
{
	m_ObjectType = _TYPED_OBJECT_SWORDOBJECT_;
	m_ObjectSubType = 0;
}

SwordObject::~SwordObject()
{

}

void SwordObject::Init()
{
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar,true);
	switch(m_dir)
	{
	case DIR_UP:
		PlayEffect("sword_up",m_pAvatar);
		break;
	case DIR_DOWN:
		PlayEffect("sword_down",m_pAvatar);
		break;
	case DIR_LEFT:
		PlayEffect("sword_left",m_pAvatar);
		break;
	case DIR_RIGHT:
		PlayEffect("sword_right",m_pAvatar);
		break;
	}	
}

void SwordObject::Tick()
{
	IObject::Tick();
}

void SwordObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		SCENEMANAGER->GetSceneBackgroundLayer()->removeChild(m_pAvatar,true);
		m_pAvatar = NULL;
	}
}


void SwordObject::PushCommand(int commandId, void* pPtr)
{

}

void SwordObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	SetIsValid(false);
}

void SwordObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void SwordObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}

void SwordObject::create(cocos2d::CCPoint pt,DIRECTION dir)
{
	SwordObject* pSwordEffect = new SwordObject;
	pSwordEffect->setDir(dir);
	pSwordEffect->Init();
	switch(dir)
	{
	case DIR_DOWN:
		pSwordEffect->SetXPos(pt.x);
		pSwordEffect->SetYPos(pt.y - 50);
		break;
	case DIR_UP:
		pSwordEffect->SetXPos(pt.x);
		pSwordEffect->SetYPos(pt.y + 20);
		break;
	case DIR_LEFT:
		pSwordEffect->SetXPos(pt.x - 20);
		pSwordEffect->SetYPos(pt.y);
		break;
	case DIR_RIGHT:
		pSwordEffect->SetXPos(pt.x+20);
		pSwordEffect->SetYPos(pt.y);
		break;
	}
	OBJECTMANAGER->InsertObject(pSwordEffect);
}