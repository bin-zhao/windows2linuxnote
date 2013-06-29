#ifndef  _NINJIATRIBE_MESSAGEBOXWINDOW_H_
#define  _NINJIATRIBE_MESSAGEBOXWINDOW_H_


#include "IWindow.h"

class MessageBoxWindow : public IWindow
{
protected:
	int m_AlertType; // 子类型
	int m_SubType;   // 附加类型

public:
	MessageBoxWindow();
	virtual ~MessageBoxWindow();

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
	/*
		取消按钮操作处理
	*/
	void   OnCancelButtonClick(cocos2d::CCObject* pSender);
};


#endif
