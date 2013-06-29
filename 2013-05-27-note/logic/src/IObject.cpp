#include "../include/IObject.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/SceneManager.h"
#include "../include/SoundSystem.h"
#include "../include/InputCommand.h"


IObject::IObject()
{
	m_ObjectId      = "";
	m_ObjectType    = _TYPED_OBJECT_UNKOWN_;
	m_ObjectSubType = -1;

	m_IsValid    = true;
	m_bCollision = true;
	m_pAvatar    = NULL;
	m_LogicTickCounter  = 0;
	m_AvatarTickCounter = 0;
}

IObject::~IObject()
{

}

void IObject::SetObjectId(std::string objectId)
{
	m_ObjectId = objectId;
}

std::string IObject::GetObjectId()
{
	return m_ObjectId;
}

void IObject::SetObjectType(int objectType)
{
	m_ObjectType = objectType;
}

int IObject::GetObjectType()
{
	return m_ObjectType;
}

void IObject::SetObjectSubType(int objectSubType)
{
	m_ObjectSubType = objectSubType;
}

int IObject::GetObjectSubType()
{
	return m_ObjectSubType;
}

void IObject::SetIsValid(bool bValid)
{
	m_IsValid = bValid;
}

bool IObject::GetIsValid()
{
	return m_IsValid;
}

void IObject::SetIsCollision(bool bIsCollision)
{
	m_bCollision = bIsCollision;
}

bool IObject::GetIsCollision()
{
	return m_bCollision;
}

std::string IObject::GetIdleActionName()
{
	return "";
}

void  IObject::SetXPos(float xPos)
{
	if (m_pAvatar == NULL)
		return;

	m_pAvatar->setPositionX(xPos);
}

float IObject::GetXPos()
{
	return m_pAvatar->getPositionX();
}

void  IObject::SetYPos(float yPos)
{
	if (m_pAvatar == NULL)
		return;

	m_pAvatar->setPositionY(yPos);
}

float IObject::GetYPos()
{
	return m_pAvatar->getPositionY();
}

void IObject::SetRotation(float rotation)
{
	if (m_pAvatar == NULL)
		return;

	m_pAvatar->setRotation(rotation);
}

void IObject::SetVisible(bool bShow)
{
	m_pAvatar->setVisible(bShow);
}

float IObject::GetAvatarWidth()
{
	return 0.0f;
}

float IObject::GetAvatarHeight()
{
	return 0.0f;
}

float IObject::GetAvatarCollisionWidth()
{
	return 0.0f;
}

float IObject::GetAvatarCollisionHeight()
{
	return 0.0f;
}

void IObject::Tick()
{
	m_LogicTickCounter++;
}

void IObject::RenderTick()
{
	m_AvatarTickCounter++;
	UpdateAvatar();
}

void IObject::PushCommand(int commandId, void* pPtr)
{
	if (commandId == _TYPED_INPUT_COMMAND_SELECTED_)
	{
		OnSelectedCommandHandler(pPtr);
	}
	else if (commandId == _TYPED_INPUT_COMMAND_UNSELECTED_)
	{	
		OnUnSelectedCommandHandler(pPtr);
	}
}

bool IObject::IsEffectPlaying(std::string effectName)
{
	std::map<std::string, _OBJECT_ANIMATION_>::iterator iter = m_ObjectAnimationList.find(effectName);
	if (iter == m_ObjectAnimationList.end())
		return false;

	if (iter->second.mAnimationIsPlayed)
		return true;

	return false;
}

void IObject::PlayEffect(std::string effectName, cocos2d::CCNode* pNode)
{
	std::map<std::string, _OBJECT_ANIMATION_>::iterator iter   = m_ObjectAnimationList.begin();
	std::map<std::string, _OBJECT_ANIMATION_>::iterator iter_e = m_ObjectAnimationList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if (iter->second.mAnimationNode==pNode && effectName.compare(iter->second.mAnimationName)!=0)
		{
			m_ObjectAnimationList.erase(iter);
			break;
		}
	}

	cocos2d::CCAnimation* pAnimation = SCENEMANAGER->GetAnimtionByName(effectName);

	iter = m_ObjectAnimationList.find(effectName);
	if (iter == m_ObjectAnimationList.end())
	{
		_OBJECT_ANIMATION_ animation;
		animation.mAnimationName     = effectName;
		animation.mAnimationIsPlayed = true;
		animation.mAnimationIdx      = 0;
		animation.mAnimationNumber   = pAnimation->getFrames()->count();
		animation.mAnimationInterval =int(pAnimation->getDelayPerUnit()*NinjiaTribeApp::get_instance2()->GetFPS());
		animation.mAnimationStartTime= m_AvatarTickCounter;
		animation.mAnimationNode     = pNode;
		if (animation.mAnimationInterval == 0)
			animation.mAnimationInterval = 1;
		((cocos2d::CCSprite*)pNode)->setDisplayFrameWithAnimationName(effectName.c_str(), animation.mAnimationIdx);
		m_ObjectAnimationList.insert(std::map<std::string, _OBJECT_ANIMATION_>::value_type(effectName, animation));
		return;
	}
	else if (iter->second.mAnimationNode != pNode)
	{
		assert(0);
	}

	_OBJECT_ANIMATION_& animation = iter->second;
	animation.mAnimationIsPlayed = true;
	animation.mAnimationIdx      = 0;
	animation.mAnimationNumber   = pAnimation->getFrames()->count();
	animation.mAnimationInterval =int(pAnimation->getDelayPerUnit()*NinjiaTribeApp::get_instance2()->GetFPS());
	animation.mAnimationStartTime= m_AvatarTickCounter;
	animation.mAnimationNode     = pNode;
	if (animation.mAnimationInterval == 0)
		animation.mAnimationInterval = 1;
	((cocos2d::CCSprite*)pNode)->setDisplayFrameWithAnimationName(effectName.c_str(), animation.mAnimationIdx);
}

void IObject::StopEffect(std::string effectName)
{
	std::map<std::string, _OBJECT_ANIMATION_>::iterator iter = m_ObjectAnimationList.find(effectName);
	if (iter != m_ObjectAnimationList.end())
	{
		iter->second.mAnimationIsPlayed = false;
		m_ObjectAnimationList.erase(iter);
	}
}

void IObject::PlaySound(std::string soundName)
{
	SOUNDSYSTEM->PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_EFFECT_, soundName, false);
}	

void IObject::UpdateAvatar()
{
	//float factor = SCENEMANAGER->GetTickSpeedFactor();
	float factor = 1.0f;
	std::map<std::string, _OBJECT_ANIMATION_>::iterator iter   = m_ObjectAnimationList.begin();
	std::map<std::string, _OBJECT_ANIMATION_>::iterator iter_e = m_ObjectAnimationList.end();
	for ( ; iter!=iter_e; )
	{
		std::map<std::string, _OBJECT_ANIMATION_>::iterator temp = iter;
		++iter;

		_OBJECT_ANIMATION_& animation = temp->second;
		if (animation.mAnimationIsPlayed)
		{
			int interval = int(float(animation.mAnimationInterval)/factor);
			if (interval <= 0)
				interval = 1;

			if ((m_AvatarTickCounter-animation.mAnimationStartTime)%interval == 0)
			{
				animation.mAnimationIdx++;
				if (animation.mAnimationIdx == animation.mAnimationNumber)
				{
					animation.mAnimationIsPlayed = false;
					
					std::string name = animation.mAnimationName;
					cocos2d::CCNode* pNode = animation.mAnimationNode;
					m_ObjectAnimationList.erase(temp);
					OnAnimationEndEventHandler(name, pNode);
				}
				else
				{
					((cocos2d::CCSprite*)animation.mAnimationNode)->setDisplayFrameWithAnimationName(animation.mAnimationName.c_str(), animation.mAnimationIdx);
				}
			}
		}
	}	
}

void IObject::UpdatePosition()
{

}

void IObject::UpdateRotation()
{

}

void IObject::OnSelectedCommandHandler(void* pPtr)
{

}

void IObject::OnUnSelectedCommandHandler(void* pPtr)
{

}

void IObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	
}

void IObject::setPos(cocos2d::CCPoint pt)
{
	SetXPos(pt.x);
	SetYPos(pt.y);
}

cocos2d::CCPoint IObject::getPos()
{
	return ccp(GetXPos(),GetYPos());
}