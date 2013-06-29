#ifndef  _NINJIATRIBE_IDEBUGER_H_
#define  _NINJIATRIBE_IDEBUGER_H_


class IDebuger
{
public:
	/*
		调试器类型
	*/
	enum
	{
		_TYPED_DEBUGER_UNKOWN_,        // 未知类型调试器
		_TYPED_DEBUGER_NET_,           // 网络信息调试器
		_TYPED_DEBUGER_RENDER_,        // 渲染信息调试器
		_TYPED_DEBUGER_LOGIC_,         // 逻辑信息调试器
		_TYPED_DEBUGER_OTHER_,         // 其他类型调试器
	};

protected:
	int  m_DebugerType; // 调试器类型

public:
	IDebuger();
	virtual ~IDebuger();

public:
	/*
		得到当前调试器类型
	*/
	int GetDebugerType();

public:
	/*
		初始化调试器
	*/
	virtual  bool  Init()     =     0;
	/*
		逻辑桢更新
	*/
	virtual  void  Tick()     =     0;
	/*
		销毁调试器
	*/
	virtual  void  Destroy()  =     0;
};


#endif
