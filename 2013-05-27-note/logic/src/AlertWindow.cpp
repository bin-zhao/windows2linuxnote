#include "../include/AlertWindow.h"
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


AlertWindow::AlertWindow()
{
	m_WindowType   = _TYPED_WINDOW_ALERT_;
	m_bModelWindow = true;
	m_AlertType    = _TYPED_ALERT_WINDOW_UNKOWN_;
}

AlertWindow::~AlertWindow()
{

}

bool AlertWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_ALERTWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_ALERTWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);

	return IWindow::Init();
}

bool AlertWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;

		cocos2d::CCMenuItem* pMenuItem = (cocos2d::CCMenuItem*)UIWindowManager::get_instance()->GetUIWindow("alert/ok");
		pMenuItem->setTarget(this, menu_selector(AlertWindow::OnOKButtonClick));
		return true;
	} 
	while (false);

	return false;
}

void AlertWindow::Tick()
{
	IWindow::Tick();
}

void AlertWindow::Destroy()
{
	IWindow::Destroy();
}

void AlertWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_ALERTWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_ALERTWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
}

void AlertWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void AlertWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void AlertWindow::OnOKButtonClick(cocos2d::CCObject* pSender)
{
	Destroy();
}
