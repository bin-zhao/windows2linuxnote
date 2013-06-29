#include "../include/MessageBoxWindow.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/VariableSystem.h"
#include "../include/SysLangDataManager.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  cocos2d;
using  namespace  uiloader;


MessageBoxWindow::MessageBoxWindow()
{
	m_WindowType   = _TYPED_WINDOW_MESSAGEBOX_;
	m_bModelWindow = true;
	m_AlertType    = _TYPED_ALERT_WINDOW_UNKOWN_;
	m_SubType      = 0;
}

MessageBoxWindow::~MessageBoxWindow()
{

}

bool MessageBoxWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_MESSAGEBOXWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_MESSAGEBOXWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);

	return IWindow::Init();
}

bool MessageBoxWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;

		cocos2d::CCMenuItem* pMenuItem = (cocos2d::CCMenuItem*)UIWindowManager::get_instance()->GetUIWindow("messagebox/ok");
		pMenuItem->setTarget(this, menu_selector(MessageBoxWindow::OnOKButtonClick));

		pMenuItem = (cocos2d::CCMenuItem*)UIWindowManager::get_instance()->GetUIWindow("messagebox/cancel");
		pMenuItem->setTarget(this, menu_selector(MessageBoxWindow::OnCancelButtonClick));
		return true;
	} 
	while (false);

	return false;
}

void MessageBoxWindow::Tick()
{
	IWindow::Tick();
}

void MessageBoxWindow::Destroy()
{
	IWindow::Destroy();
}

void MessageBoxWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_MESSAGEBOXWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_MESSAGEBOXWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
}

void MessageBoxWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void MessageBoxWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void MessageBoxWindow::OnOKButtonClick(cocos2d::CCObject* pSender)
{
	Destroy();
}

void MessageBoxWindow::OnCancelButtonClick(cocos2d::CCObject* pSender)
{

}
