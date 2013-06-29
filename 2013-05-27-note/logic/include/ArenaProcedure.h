#ifndef  _NINJIATRIBE_ARENAPROCEDURE_H_
#define  _NINJIATRIBE_ARENAPROCEDURE_H_


#include "IProcedure.h"
#include "../include/IObject.h"
#include <queue>
class ArenaProcedure : public IProcedure
{
public:
	enum
	{
		_TYPED_ARENAPROCEDURE_UNKOWN_,   // 未知的竞技场子流程
		_TYPED_ARENAPROCEDURE_BEGIN_,    // 竞技场开始子流程
		_TYPED_ARENAPROCEDURE_COOLDOWN_, // 竞技场倒计时子流程
		_TYPED_ARENAPROCEDURE_GAMING_,   // 竞技场游戏中子流程
		_TYPED_ARENAPROCEDURE_PAUSE_,    // 竞技场暂停流程
		_TYPED_ARENAPROCEDURE_END_,      // 竞技场结束子流程
		_TYPED_ARENAPROCEDURE_NUMBER_,   // 竞技场子流程个数
	};
public:
	std::queue<DIRECTION> dirQueue;      // 用户输入方向队列
protected:
	cocos2d::CCPoint ptTouchBegin;		 // 鼠标点击点
	cocos2d::CCPoint ptTouchEnd;		 // 鼠标抬起点
protected:
	int  m_SubType;       // 当前所属子流程
	bool m_bInputEnabled; // 是否处于可输入状态
protected:
	long long m_LogicTickCounter; // 计时器

public:
	ArenaProcedure();
	virtual ~ArenaProcedure();

public:
	/*
		得到当前子流程
	*/
	int   GetSubType();

public:
	/*
		切换到大厅处理流程
	*/
	void  ChangeToLobbyProcedure();

public:
	/*
		开始倒计时
	*/
	void  StartCoolDown();
	/*
		开始游戏
	*/
	void  StartGame();
	/*
		游戏结束
	*/
	void  EndGame(bool bWin);
	/*
		暂停游戏
	*/
	void  PauseGame();
	/*
		恢复游戏
	*/
	void  ResumeGame();
	/*
		重玩游戏
	*/
	void  ReplayGame();

public:
	/*
		初始化流程
	*/
	virtual      bool     Init();
	/*
		逻辑桢处理
	*/
	virtual      void     Tick();
	/*
		销毁流程
	*/
	virtual      void     Destroy();

public:
	/*
		系统输入消息响应处理
	*/
	virtual      void     OnInputEventHandler();

public:
	/*
		系统进入后台事件响应处理
	*/
	virtual      void     OnSystemEnterBackEventHandler();
	/*
		系统进入前台事件响应处理
	*/
	virtual      void     OnSystemEnterFrontEventHandler();
	/* 
		系统暂停事件响应处理
	*/
	virtual      void     OnSystemPauseEventHandler();
	/*
		系统恢复事件响应处理
	*/
	virtual      void     OnSystemResumeEventHandler();
};


#endif
