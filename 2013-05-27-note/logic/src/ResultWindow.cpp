#include "../include/ResultWindow.h"
#include "../include/EventTyper.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/LobbyProcedure.h"
#include "../include/ArenaProcedure.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;
using  namespace  cocos2d;


ResultWindow::ResultWindow()
{
	m_WindowType = _TYPED_WINDOW_ARENARESULT_;
}

ResultWindow::~ResultWindow()
{

}

bool ResultWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_ARENARESULTWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_ARENARESULTWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);

	return IWindow::Init();
}

bool ResultWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;

		cocos2d::CCMenuItem* pMenuItem = (cocos2d::CCMenuItem*)UIWindowManager::get_instance()->GetUIWindow("result/back");
		pMenuItem->setTarget(this, menu_selector(ResultWindow::OnBackButtonClick));
		pMenuItem = (cocos2d::CCMenuItem*)UIWindowManager::get_instance()->GetUIWindow("result/restart");
		pMenuItem->setTarget(this, menu_selector(ResultWindow::OnReStartButtonClick));

		return true;
	} 
	while (false);

	return false;
}

void ResultWindow::Tick()
{
	IWindow::Tick();
}

void ResultWindow::Destroy()
{
	IWindow::Destroy();
}

void ResultWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_ARENARESULTWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_ARENARESULTWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
}

void ResultWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void ResultWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void ResultWindow::OnReStartButtonClick(cocos2d::CCObject* pSender)
{
	NinjiaTribeApp::get_instance2()->m_pArenaProcedure->ReplayGame();
}

void ResultWindow::OnBackButtonClick(cocos2d::CCObject* pSender)
{
	NinjiaTribeApp::get_instance2()->m_pArenaProcedure->ChangeToLobbyProcedure();
}
