#ifndef  _VIP3D_HEROOBJECT_H_
#define  _VIP3D_HEROOBJECT_H_

#include "IObject.h"

class HeroObject : public IObject
{
public:
	bool m_blRun;									//是否奔跑
	std::string m_strName;							//英雄的名字
	long m_killNum;									//杀敌数名
	bool m_isActive;								//是否被激活
protected:
	//cocos2d::CCSprite* m_pHeroAvatar;				//英雄Avatar
public:
	HeroObject();
	virtual ~HeroObject();
public:
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
		设置当前X坐标
	*/
	virtual void SetXPos(float xPos);
	/*
		设置当前Y坐标
	*/
	virtual void SetYPos(float yPos);

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
	static HeroObject* create(int subType,cocos2d::CCPoint pt);
	/*
		设置缩放
	*/
	void setScale(float x);
	/*
		播放动画
	*/
	void playAnimation();
	/*
		停止动画
	*/
	void stopAnimation();
	/*
		获取英雄名字
	*/
	std::string getHeroName();
	/*
		设置杀敌数
	*/
	void setKillNum(long killNum);
	/*
		获取杀敌数
	*/
	long getKillNum();
};


#endif
