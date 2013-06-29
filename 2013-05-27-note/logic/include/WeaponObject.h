/*
 * =====================================================================================
 *
 *       Filename:  WeaponObject.h
 *
 *    Description:  武器对象(英雄武器,怪物武器)
 *
 *        Version:  1.0
 *        Created:  2013-4-30 10:03:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  _NINJIATRIBE_WEAPONOBJECT_H_
#define  _NINJIATRIBE_WEAPONOBJECT_H_

#include "IObject.h"
#include <string>

class WeaponObject : public IObject
{
public:
	enum 
	{
		_SUBTYPE_WEAPON_ARROW=2, //箭头武器
		_SUBTYPE_WEAPON_FIRE =3, //火法武器
		_SUBTYPE_WEAPON_NET  =16,//蜘蛛网的ID(通过创建武器的SUBTYPE来识别)
		_SUBTYPE_WEAPON_VENOM=17,//毒液武器的ID(通过创建武器的SUBTYPE来识别)
		_SUBTYPE_WEAPON_BOWAEEOW=18,//毒液武器的ID(通过创建武器的SUBTYPE来识别)
	};
private:
	bool m_isGood;                    //判断武器是(敌方/我方)
	cocos2d::CCPoint m_birthPos;      //出生地
	cocos2d::CCPoint m_dstPos;        //死亡地
	float m_moveSpeed;			      //移动速度
	
	float m_attackDamage;             //武器的伤害值
	float m_attackScope;			  //武器的碰撞检测范围
	float m_effectAttackScope;		  //特效的碰撞检测范围
	float m_moveRad;			      //箭,毒液等应该旋转的弧度
	bool  m_bUpdatePostion;           //是否更新位置
	
	cocos2d::CCSprite *m_WeaponAvatar;//武器图片
	cocos2d::CCSprite *m_EffectAvatar;//用于播放特效(例如火法的扩散特效)
	std::string	m_weaponResourceName; //武器图片名称
	std::string m_weaponEffectName;   //武器特效名称
	int m_liveTicker;				  //存活ticker计数(用于判断是否到达目的地)
	
	int m_deadTicker;				  //死亡ticker计数(在创建的时候就应该初始化)

public:
	WeaponObject();
	virtual ~WeaponObject();
public:
	cocos2d::CCPoint getBirthPos() const { return m_birthPos; }
	void setBirthPos(cocos2d::CCPoint val) { m_birthPos = val; }
	cocos2d::CCPoint getDstPos() const { return m_dstPos; }
	void setDstPos(cocos2d::CCPoint val) { m_dstPos = val; }
	bool getIsGood() const { return m_isGood; }
	void setIsGood(bool val) { m_isGood = val; }
	void setImgRotateAngle(float val) {m_WeaponAvatar->setRotation(val);}
	float getMoveRad() const { return m_moveRad; }
	void setMoveRad(float val) { m_moveRad = val; }
	float getAttackDamage() const { return m_attackDamage; }
	void setAttackDamage(float val) { m_attackDamage = val; }
	int getLiveTicker() const { return m_liveTicker; }
	void setLiveTicker(int val) { m_liveTicker = val; }
	int getDeadTicker() const { return m_deadTicker; }
	void setDeadTicker(int val) { m_deadTicker = val; }
	float getMoveSpeed() const { return m_moveSpeed; }
	void setMoveSpeed(float val) { m_moveSpeed = val; }
public:
	/*
		播放攻击音效
	*/
	void PlayAttackSound();
public:
	/*
		初始化操作
	*/
	virtual  void  Init();
	/*
		逻辑帧处理操作
	*/
	virtual  void  Tick();
	/*
		销毁操作
	*/
	virtual  void  Destroy();
public:
	/*
		逻辑指令处理操作
	*/
	virtual  void  PushCommand(int commandId, void* pPtr);
public:
	/*
		设置当前X坐标
	*/
	virtual void SetXPos(float xPos);
	/*
		设置当前Y坐标
	*/
	virtual void SetYPos(float yPos);
public:
	/*
		对象动画一轮播放完毕回调处理
	*/
	virtual  void  OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode);
	
	/*
		判断对象是否在攻击范围内(用于类似于火法特效)
	*/
	bool isInAttackScope(cocos2d::CCPoint targetPos);
	///*
	//	获取对象宽度
	//*/
	//virtual	float getWeaponObjectWidht();
	///*
	//	获取对象高度
	//*/
	//virtual float getWeaponObjectHeight();

	bool getIsHasSpreadAbility();
	static WeaponObject* create(int subType,cocos2d::CCPoint birthPt,cocos2d::CCPoint dstPt);
	void updateObjectPosition();
	bool isInEffectAttackScope(cocos2d::CCPoint targetPos);
public:
	/*
		创建WeaponObject对象
	*/

public://(预留,防止以后用于矩形碰撞检测)
	/*
		得到对应的Avatar宽度
	*/
	//virtual  float GetAvatarWidth();
	///*
	//	得到对应的Avatar高度
	//*/
	//virtual  float GetAvatarHeight();
	///*
	//	得到Avatar碰撞检测的宽度
	//*/
	//virtual  float GetAvatarCollisionWidth();
	///*
	//	得到Avatar碰撞检测的高度
	//*/
	//virtual  float GetAvatarCollisionHeight();
};
#endif
