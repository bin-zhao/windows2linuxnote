#ifndef  _NINJIATRIBE_MOREGAMESYSTEM_H_
#define  _NINJIATRIBE_MOREGAMESYSTEM_H_


#include <include/common/Singleton.h>
#include <cocos2d.h>
using  namespace  cobra_win;
using  namespace  std;


class MoreGameSystem : public cobra_win::Singleton2<MoreGameSystem>
{
public:
	MoreGameSystem();
	virtual ~MoreGameSystem();

public:
	/*
		打开其他游戏面板
	*/
	void  OpenMoreGamePanel();

public:
	/*
		初始化其他游戏系统管理器
	*/
	bool  Init();
	/*
		其他游戏系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁其他游戏系统管理器
	*/
	void  Destroy();

public:
	friend  class  cobra_win::Singleton2<MoreGameSystem>;
};

#define  MOREGAMESYSTEM  (MoreGameSystem::get_instance2())


#endif
