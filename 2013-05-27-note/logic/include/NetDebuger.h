#ifndef  _NINJIATRIBE_NETDEBUGER_H_
#define  _NINJIATRIBE_NETDEBUGER_H_


#include "IDebuger.h"

class NetDebuger : public IDebuger
{
protected:
	long long m_AllDownLoadBytes; // 总的下行字节数量
	long long m_AllUpLoadBytes;   // 总的上行字节数量

public:
	NetDebuger();
	virtual ~NetDebuger();

public:
	/*
		初始化调试器
	*/
	virtual  bool  Init();
	/*
		逻辑桢更新
	*/
	virtual  void  Tick();
	/*
		销毁调试器
	*/
	virtual  void  Destroy();
};


#endif
