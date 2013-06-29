#include "../include/WeaponObject.h"
#include "../include/SwordObject.h"
#include "../include/InputCommand.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/VariableSystem.h"
#include "../include/SoundSystem.h"
#include "../include/Common.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/WeaponDataManager.h"
#include <cocos2d.h>

WeaponObject::WeaponObject()
{
	m_ObjectType = _TYPED_OBJECT_WEAPONOBJECT_;
	m_ObjectSubType = 0;
	
	//动态生成
	m_birthPos=ccp(0,0);          //出生地
	m_dstPos=ccp(0,0);            //死亡地
	m_moveRad=0;			      //箭,毒液等应该旋转的弧度
	m_bUpdatePostion=true;		  //默认需要更新位置
	m_liveTicker=0;
	m_deadTicker=0;
	//从配置表中读取
	m_isGood=0;                   //判断武器是(敌方/我方)
	m_attackScope=0;			  //武器的碰撞检测范围
	m_effectAttackScope=0;		  //特效的碰撞检测范围
	m_moveSpeed=0;			      //移动速度
	m_attackDamage=0;             //武器的伤害值
	m_WeaponAvatar=NULL;          //武器图片
	m_EffectAvatar=NULL;          //用于播放特效(例如火法的扩散特效)
}

WeaponObject::~WeaponObject()
{

}

void WeaponObject::SetXPos(float xPos)
{
	IObject::SetXPos(xPos);
}

void WeaponObject::SetYPos(float yPos)
{
	IObject::SetYPos(yPos);
}




void WeaponObject::Init()
{
	//将avater加入到背景层
	m_pAvatar = cocos2d::CCSprite::create();
	m_pAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	SCENEMANAGER->GetSceneBackgroundLayer()->addChild(m_pAvatar);
	WeaponData* pWeaponData = WeaponDataManager::get_instance2()->GetWeaponById(GetObjectSubType());
	m_attackScope = pWeaponData->m_attackScope;
	m_effectAttackScope = pWeaponData->m_AddAttackRadius;
	m_attackDamage = pWeaponData->m_AttackDamage;
	m_moveSpeed = pWeaponData->m_Speed;
	m_weaponResourceName = pWeaponData->m_AvatarResourceName;
	m_isGood = pWeaponData->m_isGood;
	m_weaponEffectName = pWeaponData->m_EffectName;
	m_bUpdatePostion = true;
	m_WeaponAvatar = cocos2d::CCSprite::createWithSpriteFrameName(m_weaponResourceName.c_str());
	m_pAvatar->addChild(m_WeaponAvatar);
	m_EffectAvatar = cocos2d::CCSprite::create();
	m_EffectAvatar->setAnchorPoint(ccp(0.5f,0.5f));
	m_pAvatar->addChild(m_EffectAvatar);
}

void WeaponObject::Tick()
{
	IObject::Tick();
	m_liveTicker++;
	if(m_bUpdatePostion)
	updateObjectPosition();
}

void WeaponObject::Destroy()
{
	if(m_pAvatar != NULL)
	{
		if(m_WeaponAvatar!=NULL)
		{
			m_pAvatar->removeChild(m_WeaponAvatar,true);
			m_WeaponAvatar = NULL;
		}
		if(m_EffectAvatar!=NULL)
		{
			m_pAvatar->removeChild(m_EffectAvatar,true);
			m_EffectAvatar = NULL;
		}
		SCENEMANAGER->GetSceneBackgroundLayer()->removeChild(m_pAvatar,true);
		m_pAvatar = NULL;
	}
}


void WeaponObject::PushCommand(int commandId, void* pPtr)
{
	if(_TYPED_INPUT_COMMAND_WEAPON_PLAYEFFECT_ == commandId)
	{
		//隐藏weapon
		m_WeaponAvatar->setVisible(false);
		m_bUpdatePostion=false;
		//播放特效
		PlayEffect(m_weaponEffectName,m_EffectAvatar);
	}
}

void WeaponObject::OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode)
{
	//判断是否具有溅射能力(请记得将结点从武器容器释放)
	if(getIsHasSpreadAbility())
	{
		SetIsValid(false);
	}
	else//如果不具备溅射能力由外部设为false
	{

	}
}



//判断targetPos是否在英雄攻击范围之内
bool WeaponObject::isInAttackScope(cocos2d::CCPoint targetPos)
{
	cocos2d::CCPoint selfPos = getPos();
	//计算目标与武器之间的距离
	float dst_x = ::fabs(selfPos.x - targetPos.x);
	float dst_y = ::fabs(selfPos.y - targetPos.y);
	float dst   = ::sqrt(dst_x*dst_x + dst_y*dst_y);
	//如果距离不够,直接返回false
	if(dst > m_attackScope)
		return false;
	return true;
}

bool WeaponObject::isInEffectAttackScope(cocos2d::CCPoint targetPos)
{
	cocos2d::CCPoint selfPos = getPos();
	//计算目标与武器之间的距离
	float dst_x = ::fabs(selfPos.x - targetPos.x);
	float dst_y = ::fabs(selfPos.y - targetPos.y);
	float dst   = ::sqrt(dst_x*dst_x + dst_y*dst_y);
	//如果距离不够,直接返回false
	if(dst > m_effectAttackScope)
		return false;
	return true;
}

void WeaponObject::updateObjectPosition()
{
	float spdx = ::cos(m_moveRad)*m_moveSpeed;
	float spdy = ::sin(m_moveRad)*m_moveSpeed;
	SetXPos(GetXPos()+spdx);
	SetYPos(GetYPos()+spdy);
}

bool WeaponObject::getIsHasSpreadAbility()
{
	WeaponData* pWeaponData = WeaponDataManager::get_instance2()->GetWeaponById(GetObjectSubType());
	assert(pWeaponData != NULL);
	return pWeaponData->m_bHasSpreedAbility;
}

WeaponObject* WeaponObject::create(int subType,cocos2d::CCPoint birthPt,cocos2d::CCPoint dstPt)
{
	WeaponObject* tmpWeaponObject = new WeaponObject;
	tmpWeaponObject->SetObjectSubType(subType);
	tmpWeaponObject->setBirthPos(birthPt);
	tmpWeaponObject->setDstPos(dstPt);
	float dx = dstPt.x - birthPt.x;
	float dy = dstPt.y - birthPt.y;
	float len = ::sqrt(dx*dx+dy*dy);
	float unitdx = dx/len;//单位向量
	float unitdy = dy/len;
	float imgrotateRad = ::atan2(-unitdy,unitdx);
	float moveRad = ::atan2(unitdy,unitdx);
	float imgrotateangle = imgrotateRad*180/3.1415926f;
	tmpWeaponObject->Init();
	tmpWeaponObject->setDeadTicker((int)(len/tmpWeaponObject->getMoveSpeed()));
	tmpWeaponObject->setImgRotateAngle(imgrotateangle);
	tmpWeaponObject->setMoveRad(moveRad);
	tmpWeaponObject->SetXPos(birthPt.x);
	tmpWeaponObject->SetYPos(birthPt.y);
	OBJECTMANAGER->InsertObject(tmpWeaponObject);
	return tmpWeaponObject;
}