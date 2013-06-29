#ifndef  _VIP3D_SMOGOBJECT_H_
#define  _VIP3D_SMOGOBJECT_H_

#include "IObject.h"

class SmogObject : public IObject
{
public:
	SmogObject();
	virtual ~SmogObject();
public:
	enum 
	{
		_SUBTYPE_DROP_GEMS=0,
		_SUBTYPE_DROP_HERO=1,	
		_SUBTYPE_DROP_NOTHING=2,
	};
	/*
		得到Mask动作名称
	*/
	//virtual std::string GetMaskActionName();
	/*
		得到空闲动作名称
	*/
	//virtual std::string GetIdleActionName();
public:
	/*
		得到对应的Avatar宽度
	*/
	//virtual  float GetAvatarWidth();
	/*
		得到对应的Avatar高度
	*/
	//virtual  float GetAvatarHeight();
	/*
		得到Avatar碰撞检测的宽度
	*/
	//virtual  float GetAvatarCollisionWidth();
	/*
		得到Avatar碰撞检测的高度
	*/
	//virtual  float GetAvatarCollisionHeight();
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
		对象动画一轮播放完毕回调处理
	*/
	virtual  void  OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode);
public:
	/*
		创建对象
	*/
	//static void create(cocos2d::CCPoint pt);
	static void create(cocos2d::CCPoint pt,int subType);
	/*
		设置X坐标
	*/
	void SetXPos(float xPos);
	/*
		设置Y坐标
	*/
	void SetYPos(float yPos);
};


#endif
