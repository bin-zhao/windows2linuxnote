#ifndef  _NINJIATRIBE_LOGICDEBUGER_H_
#define  _NINJIATRIBE_LOGICDEBUGER_H_


#include "IDebuger.h"

class LogicDebuger : public IDebuger
{
public:
	LogicDebuger();
	virtual ~LogicDebuger();

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
