#ifndef  _NINJIATRIBE_ALERTWINDOW_H_
#define  _NINJIATRIBE_ALERTWINDOW_H_


#include "IWindow.h"

class AlertWindow : public IWindow
{
protected:
	int m_AlertType; // 警告窗口类型

public:
	AlertWindow();
	virtual ~AlertWindow();

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
		显示Top面板事件处理
	*/
	void   OnShowWindowEventHandler(std::list<std::string>& paramList);
	/*
		更新面板所有控件名称事件处理
	*/
	void   OnUpdateUITextEventHandler(std::list<std::string>& paramList);

private:
	/*
		确认按钮操作处理
	*/
	void   OnOKButtonClick(cocos2d::CCObject* pSender);
};


#endif
