#include "../include/DiamondObject.h"
#include "../include/InputCommand.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/VariableSystem.h"
#include "../include/SoundSystem.h"
#include "../include/Common.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/PlayerDataManager.h"
#include "../include/LocalPlayerDataManager.h"

DiamondObject::DiamondObject()
{
	m_ObjectType = _TYPED_OBJECT_DIAMONDOBJECT_;
	m_ObjectSubType = 0;
}

DiamondObject::~DiamondObject()
{

}

void DiamondObject::Init()
{
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar,true);
    if(m_ObjectSubType == 0)
	PlayEffect("greengem",m_pAvatar);
    else if(m_ObjectSubType == 1)
	PlayEffect("redgem",m_pAvatar);
}

void DiamondObject::Tick()
{
	IObject::Tick();
}

void DiamondObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		SCENEMANAGER->GetSceneBackgroundLayer()->removeChild(m_pAvatar,true);
		m_pAvatar = NULL;
	}
}


void DiamondObject::PushCommand(int commandId, void* pPtr)
{

}

void DiamondObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
    if(m_ObjectSubType == _SUBTYPE_GREEN_GEM)
	{
		PlayEffect("greengem",m_pAvatar);
	}
    else if(m_ObjectSubType == _SUBTYPE_RED_GEM)
	{
		PlayEffect("greengem",m_pAvatar);
	}
}

void DiamondObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void DiamondObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}

DiamondObject* DiamondObject::create(int subType,cocos2d::CCPoint pt)
{
	DiamondObject* pDiamondEffect = new DiamondObject;
	pDiamondEffect->m_ObjectSubType = subType;
	pDiamondEffect->Init();
	pDiamondEffect->SetXPos(pt.x);
	pDiamondEffect->SetYPos(pt.y);
	OBJECTMANAGER->InsertObject(pDiamondEffect);
	return pDiamondEffect;
}
