#ifndef  _NINJIATRIBE_ARENAWINDOW_H_
#define  _NINJIATRIBE_ARENAWINDOW_H_


#include "IWindow.h"

class ArenaWindow : public IWindow
{
public:
	ArenaWindow();
	virtual ~ArenaWindow();

public:
	/*
		初始化处理
	*/
	virtual    bool    Init();
	/*
		加载处理
	*/
	virtual    bool    Load();
	/*
		桢更新处理
	*/
	virtual    void    Tick();
	/*
		销毁处理
	*/ 
	virtual    void    Destroy();

public:
	/*
		消息事件响应处理
	*/
	virtual    void    OnEventHandler(int iEventType, std::list<std::string>& paramList);

private:
	/*
		显示登陆面板事件处理
	*/
	void   OnShowWindowEventHandler(std::list<std::string>& paramList);
	/*
		更新面板所有空间名称事件处理
	*/
	void   OnUpdateUITextEventHandler(std::list<std::string>& paramList);
	/*
		更新竞技场界面数值事件处理
	*/
	void   OnUpdateArenaWindowEventHandler(std::list<std::string>& paramList);
};


#endif
