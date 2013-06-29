#ifndef  _NINJIATRIBE_RESULTWINDOW_H_
#define  _NINJIATRIBE_RESULTWINDOW_H_


#include "IWindow.h"

class ResultWindow : public IWindow
{
public:
	ResultWindow();
	virtual ~ResultWindow();

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

public:
	/*
		重新开始按钮操作处理
	*/
	void   OnReStartButtonClick(cocos2d::CCObject* pSender);
	/*
		返回按钮操作处理
	*/
	void   OnBackButtonClick(cocos2d::CCObject* pSender);
};


#endif
