#ifndef  _NINJIATRIBE_IOBJECT_H_
#define  _NINJIATRIBE_IOBJECT_H_


#include <string>
#include <cocos2d.h>
enum DIRECTION
{
	DIR_UP,
	DIR_LEFT,
	DIR_DOWN,
	DIR_RIGHT,
	DIR_OTHER,
};
class IObject
{
public:
	enum
	{
		_TYPED_OBJECT_UNKOWN_,        // 未知的对象类型
		_TYPED_OBJECT_EFFECT_,        // 特效对象类型
		_TYPED_OBJECT_ITEM_,          // 道具对象类型
		_TYPED_OBJECT_HEROOBJECT_,    // 英雄对象类型(Lobby使用)
		_TYPED_OBJECT_PLAYEROBJECT_,  // Player对象类型(Arena使用)
		_TYPED_OBJECT_MONSTEROBJECT_, // Monster对象类型(Arena使用)
		_TYPED_OBJECT_MARSOBJECT_,    // 法师爆炸对象类型(Arena使用)
		_TYPED_OBJECT_SMOGOBJECT_,    // 烟雾对象类型(Arena使用)
		_TYPED_OBJECT_SWORDOBJECT_,   // 刀光效果
		_TYPED_OBJECT_DIAMONDOBJECT_, // 钻石对象
		_TYPED_OBJECT_WEAPONOBJECT_,  // 武器对象
	};
public:
	struct _OBJECT_ANIMATION_
	{
		std::string  mAnimationName;     // 动画名称
		bool         mAnimationIsPlayed; // 是否播放
		unsigned int mAnimationIdx;      // 动画索引
		unsigned int mAnimationNumber;   // 动画个数
		unsigned int mAnimationInterval; // 动画间隔时间
		long  long   mAnimationStartTime;// 动画开始时间
		cocos2d::CCNode* mAnimationNode; // 动画绑定节点
		_OBJECT_ANIMATION_()
		{
			mAnimationName     = "";
			mAnimationIsPlayed = false; 
			mAnimationIdx      = 0;
			mAnimationNumber   = 0;
			mAnimationInterval = 0;
			mAnimationStartTime= 0;
			mAnimationNode     = NULL;
		}
	};

protected:
	std::string m_ObjectId;        // 对象的Id
	int         m_ObjectType;      // 对象类型
	int         m_ObjectSubType;   // 对象子类型
	long  long  m_LogicTickCounter;// 当前对象的逻辑Tick计数
	long  long  m_AvatarTickCounter;// 当前对象Avatar的Tick计数

protected:
	bool        m_IsValid;        // 是否可用
	bool        m_bCollision;     // 是否参与碰撞计算

protected:
	cocos2d::CCNode* m_pAvatar;   // 对象对应的Avatar
	
protected:
	std::map<std::string, _OBJECT_ANIMATION_> m_ObjectAnimationList;	

public:
	IObject();
	virtual ~IObject();

public:
	/*
		设置对象Id
	*/
	void  SetObjectId(std::string objectId);
	/*
		得到对象Id
	*/
	std::string GetObjectId();
	/*
		设置对象类型
	*/
	void  SetObjectType(int objectType);
	/*
		得到对象类型
	*/
	int   GetObjectType();
	/*
		设置对象子类型
	*/
	void  SetObjectSubType(int objectSubType);
	/*
		得到对象子类型
	*/
	int   GetObjectSubType();
	/*
		设置对象是否可用
	*/
	void  SetIsValid(bool bValid);
	/*
		得到对象是否可用
	*/
	bool  GetIsValid();
	/*
		设置是否参与碰撞计算
	*/
	void  SetIsCollision(bool bIsCollision);
	/*
		是否参与碰撞计算
	*/
	bool  GetIsCollision();

public:
	/*
		得到空闲动作名称
	*/
	virtual std::string GetIdleActionName();

public:
	/*
		设置当前X坐标
	*/
	virtual  void  SetXPos(float xPos);
	/*
		得到当前X坐标
	*/
	virtual  float GetXPos();
	/*
		设置当前Y坐标
	*/
	virtual  void  SetYPos(float yPos);
	/*
		得到当前Y坐标
	*/
	virtual  float GetYPos();
	/*
		设置坐标
	*/
	virtual void setPos(cocos2d::CCPoint pt);
	/*
		得到坐标
	*/
	virtual cocos2d::CCPoint getPos();
	/*
		设置旋转角度
	*/
	virtual  void  SetRotation(float rotation);	
	/*
		设置是否可见
	*/
	virtual  void  SetVisible(bool bShow);

public:
	/*
		得到对应的Avatar宽度
	*/
	virtual  float GetAvatarWidth();
	/*
		得到对应的Avatar高度
	*/
	virtual  float GetAvatarHeight();
	/*
		得到Avatar碰撞检测的宽度
	*/
	virtual  float GetAvatarCollisionWidth();
	/*
		得到Avatar碰撞检测的高度
	*/
	virtual  float GetAvatarCollisionHeight();

public:
	/*
		初始化操作
	*/
	virtual  void  Init()      =   0;
	/*
		逻辑帧处理操作
	*/
	virtual  void  Tick();
	/*
		Avatar帧更新处理操作
	*/
	virtual  void  RenderTick();
	/*
		销毁操作
	*/
	virtual  void  Destroy()   =   0;

public:
	/*
		逻辑指令处理操作
	*/
	virtual  void  PushCommand(int commandId, void* pPtr);
	/*
		是否指定的特效正在播放
	*/
	virtual  bool  IsEffectPlaying(std::string effectName);
	/*
		播放特效处理
	*/
	virtual  void  PlayEffect(std::string effectName, cocos2d::CCNode* pNode);
	/*
		停止特效处理
	*/
	virtual  void  StopEffect(std::string effectName);
	/*
		播放音效
	*/
	virtual  void  PlaySound(std::string soundName);

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
		建筑被选中事件处理
	*/
	virtual  void  OnSelectedCommandHandler(void* pPtr);
	/*
		建筑被取消选中事件处理
	*/
	virtual  void  OnUnSelectedCommandHandler(void* pPtr);

public:
	/*
		对象动画一轮播放完毕回调处理
	*/
	virtual  void  OnAnimationEndEventHandler(std::string animationName, cocos2d::CCNode* pNode);
};


#endif
