/*
 * =====================================================================================
 *
 *       Filename:  PlayerObject.h
 *
 *    Description:  英雄对象
 *
 *        Version:  1.0
 *        Created:  2013-4-27 23:50:22
 *       Revision:  none
 *       Compiler:  vs
 *
 *         Author:  YOUR NAME (易罗阳), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef  _NINJIATRIBE_PLAYEROBJECT_H_
#define  _NINJIATRIBE_PLAYEROBJECT_H_

#include "IObject.h"
#include <string>

class PlayerObject : public IObject
{
public:
	enum 
	{
		_SUBTYPE_HERO_UNKOWN=0,
		_SUBTYPE_HERO_HERO1,
		_SUBTYPE_HERO_HERO2,
		_SUBTYPE_HERO_HERO3,
		_SUBTYPE_MONSTER_01=16,//怪物类型从16位置开始
		_SUBTYPE_MONSTER_BOWARROW,
		_SUBTYPE_MONSTER_03,
	};
	enum
	{
		_SUBTYPE_BUFF_SLOW=0,
	};
	struct _PLAYER_BUFF_INFO_
	{
		bool        mIsPlaying;        // 是否在播放
		int         mBuffType;         // Buff类型
		long long   mBuffStartTime;    // Buff开始时间
		int         mBuffLastTime;     // Buff持续时间
		std::string mBufferActionName; // BuffAvatar名称
		cocos2d::CCSprite* mBuffAvatar;// Buff表现Avatar
		_PLAYER_BUFF_INFO_()
		{
			mIsPlaying = false;
			mBuffType  = -1;
			mBuffStartTime = 0;
			mBuffLastTime  = 0;
			mBuffAvatar= NULL;
			mBufferActionName = "";
		}
	};
protected:
	std::map<int,_PLAYER_BUFF_INFO_> m_PlayerBuffList;//当前玩家buf列表
public:
    bool            bIsLeader;                  /* 是否是队长 scene init*/ 
    bool            bIsTeam;                    /* 是否在队伍中,默认False scene init*/
    bool            m_bDead;                    /* 是否死亡 */
	float           m_Speed;                    /* 速度 pdate*/
	int				m_AttackDst;				/* 攻击距离 pdate*/
	int				m_AttackAngle;				/* 攻击角度0～180 pdate*/
    DIRECTION       m_Dir;                      /* 方向 scene init*/
	float           m_AttackAbility;			/* 攻击力 */
    DIRECTION       m_PreDir;                   /* 前一时刻方向 */
protected:
	cocos2d::CCProgressBar* m_pPlayerHPBar;     /* 血量条 NULL*/
    float           m_PlayerHP;                 /* 英雄当前血量 pd*/
	float           m_PlayerMaxHP;              /* 英雄总血量 pd*/
protected:
	cocos2d::CCSprite* m_pPlayerAvatar;         /* 英雄avatar NULL*/
protected:
    long long m_PreShootTime;                   /* 前一次攻击时间 */
protected:
	//以下参数只对英雄参数有用
    long long m_PlayerGreenDiamonNumber;        /* 玩家吃到绿钻个数 gz*/
	long long m_PlayerBlueDiamonNumber;         /* 玩家吃到蓝钻个数 gz*/
    long long m_PlayerRedDiamonNumber;          /* 玩家吃到红钻个数 gz*/
	long long m_KillMonsterNumber;              /* 玩家杀敌数目 gz*/
public:
												/* 成员变量函数 */
	long long getPlayerGreenDiamonNumber() const { return m_PlayerGreenDiamonNumber; }
	void setPlayerGreenDiamonNumber(long long val) { m_PlayerGreenDiamonNumber = val; }
	long long getPlayerBlueDiamonNumber() const { return m_PlayerBlueDiamonNumber; }
	void setPlayerBlueDiamonNumber(long long val) { m_PlayerBlueDiamonNumber = val; }
	long long getPlayerRedDiamonNumber() const { return m_PlayerRedDiamonNumber; }
	void setPlayerRedDiamonNumber(long long val) { m_PlayerRedDiamonNumber = val; }
	long long getKillMonsterNumber() const { return m_KillMonsterNumber; }
	void setKillMonsterNumber(long long val) { m_KillMonsterNumber = val; }
	bool getDead() const { return m_bDead; }
	void setDead(bool val) { m_bDead = val; }
	float getPlayerHP() const { return m_PlayerHP; }
	void setPlayerHP(float val) { m_PlayerHP = val; }
	float getPlayerMaxHP() const { return m_PlayerMaxHP; }
	void setPlayerMaxHP(float val) { m_PlayerMaxHP = val; }
	float getSpeed() const { return m_Speed; }
	void setSpeed(float val) { m_Speed = val; }
public:

public:
	PlayerObject();
	virtual ~PlayerObject();
public:
	/*
		播放死亡音效
	*/
	void PlayDeadSound();
	/*
		播放死亡特效
	*/
	void PlayDeadEffect();
	/*
		播放攻击音效
	*/
	void PlayAttackSound();
	/*
		播放攻击特效
	*/
	void PlayAttackEffect();
	/*
		攻击
	*/
	bool Attack(cocos2d::CCPoint target);
public:
	/*
		getUpActionAnimationName
	*/
	virtual std::string getRunUpAnimationName();
	/*
		getDownActionAnimationName
	*/
	virtual std::string getDownActionAnimationName();
	/*
		getLeftActionAnimationName
	*/
	virtual std::string getLeftActionAnimationName();
	/*
		getRightActionAnimationName
	*/
	virtual std::string getRightActionAnimationName();
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
		判断对象是否在攻击范围内
	*/
	bool isInAttackScope(cocos2d::CCPoint targetPos);
	/*
		获取对象宽度
	*/
	virtual	float getPlayerObjectWidht();
	/*
		获取对象高度
	*/
	virtual float getPlayerObjectHeight();
public:
	/*
		创建PlayerObject对象
	*/
	static PlayerObject* create(int subType,cocos2d::CCPoint pt,bool IsLeader,bool bIsTeam,DIRECTION dir);
	/*
		创建PlayerObject对象
	*/
	static PlayerObject* create(int subType);
	void turnDir();
	void OnPlayerCollisionCommandHandler(void* ptr);
public:
	/*
		当前是否存在指定Buff
	*/
	virtual  bool  IsInBuff(int buffType);
	/*
		播放Buff特效处理
	*/
	virtual  void  PlayBuffEffect(int buffType);
	/*
		停止Buff特效处理
	*/
	virtual  void  StopBuffEffect(int buffType);
	/*
		更新玩家Buff
	*/
	virtual  void  UpdateBuffAvatar();
};
#endif
