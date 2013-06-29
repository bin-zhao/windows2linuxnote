#ifndef  _NINJIATRIBE_UISYSTEM_H_
#define  _NINJIATRIBE_UISYSTEM_H_


#include <layers_scenes_transitions_nodes/CCLayer.h>
#include <include/common/Singleton.h>
#include <string>
#include <list>
using  namespace  cobra_win;

class UISystem : public cobra_win::Singleton2<UISystem>
{
private:
	cocos2d::CCLayer* m_pUILayer; // UI根窗口层

public:
	UISystem();
	virtual ~UISystem();

public:
	/*
		得到UI根窗口层
	*/
	cocos2d::CCLayer* GetUILayer();

public:
	/*
		UISystem消息响应处理
	*/
	void     OnInputEventHandler();

public:
	/*
		注册UI系统事件(UI窗口绑定事件，必须回调到指定的窗口)
	*/
	void     RegisterUIEvent(int iEventType, int iWindowType);
	/*
		注册UI系统事件(UI窗口绑定事件，必须回调到指定的窗口)
	*/
	void     RegisterUIEvent2(int iEventType, int iWindowType);
	/*
		注册UI系统事件(非UI窗口绑定事件，回调到UISystem即可)
	*/
	void     RegisterUIEvent(int iEventType);
	/*
		分发事件
	*/
	void     PushEvent(int iEventType);
	/*
		分发事件
	*/
	void     PushEvent(int iEventType, std::string param0);

public:
	/*
		初始化UI管理系统
	*/
	bool     Init();
	/*
		逻辑桢更新
	*/
	void     Tick();
	/*
		销毁UI管理系统
	*/
	void     Destroy();

public:
	/*
		UI系统事件响应处理函数
	*/
	static   void    OnUISystemEventHandler(int iEventType, std::string owerData, std::list<std::string>& paramList);
	/*
		UI系统事件响应处理函数
	*/
	static   void    OnUISystemEventHandler2(int iEventType, std::string owerData, std::list<std::string>& paramList);

public:
	friend   class   cobra_win::Singleton2<UISystem>;
};

#define  UISYSTEM  (UISystem::get_instance2())


#endif
