#ifndef  _MINITRIPLE_GAMECENTERSYSTEM_H_
#define  _MINITRIPLE_GAMECENTERSYSTEM_H_


#include <include/common/Singleton.h>

class GameCenterSystem : public cobra_win::Singleton2<GameCenterSystem>
{
public:
	GameCenterSystem();
	virtual ~GameCenterSystem();

public:
	/*
		初始化GameCenter系统管理器
	*/
	bool  Init();
	/*
		GameCenter系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁GameCenter系统管理器
	*/
	void  Destroy();

public:
	friend  class  cobra_win::Singleton2<GameCenterSystem>;
};

#define  GAMECENTERSYSTEM  (GameCenterSystem::get_instance2())


#endif
