#ifndef  _NINJIATRIBE_EFFECTOBJECT_H_
#define  _NINJIATRIBE_EFFECTOBJECT_H_


#include "IObject.h"

class EffectObject : public IObject
{
public:
	enum
	{
		_TYPED_EFFECT_UNKOWN_,
		_TYPED_EFFECT_INVALID_,         // 禁止操作特效
		_TYPED_EFFECT_MONSTER_DEAD_,    // 怪物死亡特效
		_TYPED_EFFECT_CREATE_SOLIDER_,  // 创建炮塔战士特效
		_TYPED_EFFECT_SOLIDER_LEVELUP_, // 炮塔战士升级特效
	};

public:
	EffectObject();
	virtual ~EffectObject();

public:
	/*
		是否渐隐
	*/
	virtual bool IsFadeout();
	/*
		得到空闲动作名称
	*/
	virtual std::string GetIdleActionName();

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
	/*
		播放特效处理
	*/
	virtual  void  PlayEffect(std::string effectName, cocos2d::CCNode* pNode);
	/*
		停止特效处理
	*/
	virtual  void  StopEffect(std::string effectName);

public:
	/*
		更新Avatar
	*/
	virtual  void  UpdateAvatar();

public:
	/*
		更新对象位置
	*/
	virtual  void  UpdatePosition();
	/*
		更新对象旋转角度
	*/
	virtual  void  UpdateRotation();

public:
	/*
		对象动画一轮播放完毕回调处理
	*/
	virtual  void  OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode);
};


#endif
