#include "../include/MarsObject.h"
#include "../include/InputCommand.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/VariableSystem.h"
#include "../include/SoundSystem.h"
#include "../include/Common.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/PlayerDataManager.h"
#include "../include/LocalPlayerDataManager.h"

MarsObject::MarsObject()
{
	m_ObjectType = _TYPED_OBJECT_MARSOBJECT_;
	m_ObjectSubType = 0;
}

MarsObject::~MarsObject()
{

}

void MarsObject::Init()
{
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar,true);
	PlayEffect("marsbomb",m_pAvatar);
}

void MarsObject::Tick()
{
	IObject::Tick();
}

void MarsObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		SCENEMANAGER->GetSceneBackgroundLayer()->removeChild(m_pAvatar,true);
		m_pAvatar = NULL;
	}
}


void MarsObject::PushCommand(int commandId, void* pPtr)
{

}

void MarsObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	SetIsValid(false);
}

void MarsObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void MarsObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}

void MarsObject::create(cocos2d::CCPoint pt)
{
	MarsObject* pMarsEffect = new MarsObject;
	pMarsEffect->Init();
	pMarsEffect->SetXPos(pt.x);
	pMarsEffect->SetYPos(pt.y);
	OBJECTMANAGER->InsertObject(pMarsEffect);
}