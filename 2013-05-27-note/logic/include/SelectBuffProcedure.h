#ifndef  _NINJIATRIBE_SELECTBUFFPROCEDURE_H_
#define  _NINJIATRIBE_SELECTBUFFPROCEDURE_H_


#include "IProcedure.h"

class SelectBuffProcedure : public IProcedure
{
public:
	SelectBuffProcedure();
	virtual ~SelectBuffProcedure();

public:
	/*
		切换到游戏处理流程
	*/
	void  ChangeToArenaProcedure();
	/*
		切换到登陆处理流程
	*/
	void  ChangeToLoginProcedure();
	/*
		切换到Lobby处理流程
	*/
	void  ChangeToLobbyProcedure();
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
