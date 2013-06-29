#ifndef  _NINJIATRIBE_PLAYERBEHAVIORSYSTEM_H_
#define  _NINJIATRIBE_PLAYERBEHAVIORSYSTEM_H_


#include <include/common/Singleton.h>
#include <string>
using  namespace  cobra_win;

class PlayerBehaviorSystem : public cobra_win::Singleton2<PlayerBehaviorSystem>
{
public:
	PlayerBehaviorSystem();
	virtual ~PlayerBehaviorSystem();

public:
	/*
		初始化用户行为跟踪系统管理器
	*/
	bool  Init();
	/*
		用户行为跟踪系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁用户行为跟踪系统管理器
	*/
	void  Destroy();

public:
	/*
		开始记录用户某个行为
	*/
	void  BeginPlayerBehaviorEvent(std::string text);
	/*
		结束记录用户某个行为
	*/
	void  EndPlayerBehaviorEvent(std::string text);

public:
	/*
		记录用户行为
	*/
	void  LogPlayerBehaviorEvent(std::string text);
	/*
		记录用户行为
	*/
	void  LogPlayerBehaviorEvent(std::string text, std::string label);

public:
	friend  class  cobra_win::Singleton2<PlayerBehaviorSystem>;
};

#define  PLAYERBEHAVIORSYSTEM  (PlayerBehaviorSystem::get_instance2())


#endif
