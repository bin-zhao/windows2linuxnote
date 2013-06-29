#include "../include/TopWindow.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/VariableSystem.h"
#include "../include/SysLangDataManager.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;


TopWindow::TopWindow()
{
	m_WindowType   = _TYPED_WINDOW_TOP_;
	m_WindowZOrder = _TYPED_WINDOW_ZOREDR_TOP_;
}

TopWindow::~TopWindow()
{

}

bool TopWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_TOPWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_TOPWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);
	RegisterEvent(_TYPED_EVENT_POP_SYS_TEXT_, true);

	return IWindow::Init();
}

bool TopWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;

		return true;
	} 
	while (false);

	return false;
}

void TopWindow::Tick()
{
	IWindow::Tick();
}

void TopWindow::Destroy()
{
	IWindow::Destroy();
}

void TopWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_TOPWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_TOPWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_POP_SYS_TEXT_)
	{
		OnPopTextEventHandler(paramList);
	}
}

void TopWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void TopWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void TopWindow::OnPopTextEventHandler(std::list<std::string>& paramList)
{

}
