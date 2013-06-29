#include "../include/LoadingWindow.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/LoginProcedure.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;


LoadingWindow::LoadingWindow()
{
	m_WindowType = _TYPED_WINDOW_LOADING_;
}

LoadingWindow::~LoadingWindow()
{

}

bool LoadingWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_LOADINGWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_LOADINGWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_LOADINGWINDOW_BAR_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_LOADINGWINDOW_TEXT_, true);

	return IWindow::Init();
}

bool LoadingWindow::Load()
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

void LoadingWindow::Tick()
{
	IWindow::Tick();
}

void LoadingWindow::Destroy()
{
	IWindow::Destroy();
}

void LoadingWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_LOADINGWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_LOADINGWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_LOADINGWINDOW_BAR_)
	{
		OnUpdateLoadingBarEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_LOADINGWINDOW_TEXT_)
	{
		OnUpdateLoadingTextEventHandler(paramList);
	}
}

void LoadingWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void LoadingWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void LoadingWindow::OnUpdateLoadingBarEventHandler(std::list<std::string>& paramList)
{
	float percent = 0.0f;
	sscanf((*paramList.begin()).c_str(), "%f", &percent);

	cocos2d::CCProgressBar* pBar = (cocos2d::CCProgressBar*)UIWindowManager::get_instance()->GetUIWindow("loading/loadingbar");
	pBar->setPercent(percent);
}

void LoadingWindow::OnUpdateLoadingTextEventHandler(std::list<std::string>& paramList)
{
	cocos2d::CCSingleLineLabelTTF* pTips = (cocos2d::CCSingleLineLabelTTF*)UIWindowManager::get_instance()->GetUIWindow("loading/tips");
	pTips->setString((*paramList.begin()).c_str());
}
