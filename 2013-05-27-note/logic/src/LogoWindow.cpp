#include "../include/LogoWindow.h"
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


LogoWindow::LogoWindow()
{
	m_WindowType   = _TYPED_WINDOW_LOGO_;
	m_bModelWindow = false;
}

LogoWindow::~LogoWindow()
{

}

bool LogoWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_LOGOWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_LOGOWINDOW_, true);

	return IWindow::Init();
}

bool LogoWindow::Load()
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

void LogoWindow::Tick()
{
	IWindow::Tick();
}

void LogoWindow::Destroy()
{
	IWindow::Destroy();
}

void LogoWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_LOGOWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_LOGOWINDOW_)
	{
		Destroy();
	}
}

void LogoWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}
