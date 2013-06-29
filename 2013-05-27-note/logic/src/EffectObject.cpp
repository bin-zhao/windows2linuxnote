#include "../include/EffectObject.h"
#include "../include/SceneManager.h"
#include "../include/SoundSystem.h"
#include "../include/EffectDataManager.h"


EffectObject::EffectObject()
{
	m_ObjectType = _TYPED_OBJECT_EFFECT_;
	m_bCollision = false;
}

EffectObject::~EffectObject()
{

}

bool EffectObject::IsFadeout()
{
	EffectItemData* pEffect = EffectDataManager::get_instance2()->GetEffectByType(GetObjectSubType());
	return pEffect->mEffectFadeout;
}

std::string EffectObject::GetIdleActionName()
{
	EffectItemData* pEffect = EffectDataManager::get_instance2()->GetEffectByType(GetObjectSubType());
	return pEffect->mEffectIdleAvatarName;
}

void EffectObject::Init()
{
	m_pAvatar = (cocos2d::CCSprite*)cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(cocos2d::CCPoint(0.5f, 0.5f));
	SCENEMANAGER->GetSceneEffectLayer()->addChild(m_pAvatar);
	PlayEffect(GetIdleActionName(), m_pAvatar);
}

void EffectObject::Tick()
{
	IObject::Tick();

	UpdatePosition();
	UpdateRotation();
}

void EffectObject::Destroy()
{
	if (m_pAvatar != NULL)
	{
		SCENEMANAGER->GetSceneEffectLayer()->removeChild(m_pAvatar, true);
		m_pAvatar = NULL;
	}
}

void EffectObject::PushCommand(int commandId, void* pPtr)
{
	
}

void EffectObject::PlayEffect(std::string effectName, cocos2d::CCNode* pNode)
{
	IObject::PlayEffect(effectName, pNode);
}

void EffectObject::StopEffect(std::string effectName)
{
	IObject::StopEffect(effectName);
}

void EffectObject::UpdateAvatar()
{
	IObject::UpdateAvatar();

	if (m_ObjectSubType == _TYPED_EFFECT_INVALID_)
	{
		if (IsFadeout())
		{
			int op = ((cocos2d::CCSprite*)m_pAvatar)->getOpacity();
			op -= 30;
			if (op <= 0)
			{
				SetIsValid(false);
				return;
			}

			((cocos2d::CCSprite*)m_pAvatar)->setOpacity(op);
		}
	}
}

void EffectObject::UpdatePosition()
{
	if (m_ObjectSubType != _TYPED_EFFECT_INVALID_)
	{
		if (IsFadeout())
		{
			int op = ((cocos2d::CCSprite*)m_pAvatar)->getOpacity();
			op -= 30;
			if (op <= 0)
			{
				SetIsValid(false);
				return;
			}

			((cocos2d::CCSprite*)m_pAvatar)->setOpacity(op);
		}
	}
}

void EffectObject::UpdateRotation()
{

}

void EffectObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	if (IsFadeout())
	{
		PlayEffect(animationName, pNode);
		return;
	}

	SetIsValid(false);
}
