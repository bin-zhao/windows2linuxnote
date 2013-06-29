#ifndef  _NINJIATRIBE_LOADINGWINDOW_H_
#define  _NINJIATRIBE_LOADINGWINDOW_H_


#include "IWindow.h"

class LoadingWindow : public IWindow
{
public:
	LoadingWindow();
	virtual ~LoadingWindow();

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
		更新加载进度条进度事件处理
	*/
	void   OnUpdateLoadingBarEventHandler(std::list<std::string>& paramList);
	/*
		更新加载进度提示文字事件处理
	*/
	void   OnUpdateLoadingTextEventHandler(std::list<std::string>& paramList);
};


#endif
