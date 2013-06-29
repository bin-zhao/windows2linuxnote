#ifndef  _NINJIATRIBE_IPROCEDURE_H_
#define  _NINJIATRIBE_IPROCEDURE_H_


class IProcedure
{
public:
	enum
	{
		_TYPED_UNKOWN_PROCEDURE_,        // 未知类型
		_TYPED_LOGO_PROCEDURE_,          // LOGO显示流程(Android专用)
		_TYPED_SELECTSERVER_PROCEDURE_,  // 选择服务器流程
		_TYPED_LOADING_PROCEDURE_,       // Loading流程
		_TYPED_LOGIN_PROCEDURE_,         // 登陆流程
		_TYPED_LOBBY_PROCEDURE_,         // 大厅流程
		_TYPED_SELECTBUFF_PROCEDURE_,    // BUFF流程
		_TYPED_BOSSLOBBY_PROCEDURE_,     // BOSS大厅流程
		_TYPED_ARENA_PROCEDURE_,         // 竞技场流程
	};

protected:
	int  m_Type;// 当前流程标示

public:
	IProcedure();
	virtual ~IProcedure();

public:
	/*
		得到当前流程标示
	*/
	int  GetType();

public:
	/*
		初始化流程
	*/
	virtual      bool     Init()       =    0;
	/*
		逻辑桢处理
	*/
	virtual      void     Tick()       =    0;
	/*
		销毁流程
	*/
	virtual      void     Destroy()    =    0;

public:
	/*
		系统输入消息响应处理
	*/
	virtual      void     OnInputEventHandler()    =    0;

public:
	/*
		系统进入后台事件响应处理
	*/
	virtual      void     OnSystemEnterBackEventHandler()      =     0;
	/*
		系统进入前台事件响应处理
	*/
	virtual      void     OnSystemEnterFrontEventHandler()     =     0;
	/* 
		系统暂停事件响应处理
	*/
	virtual      void     OnSystemPauseEventHandler()          =     0;
	/*
		系统恢复事件响应处理
	*/
	virtual      void     OnSystemResumeEventHandler()         =     0;
};


#endif
