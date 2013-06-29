#include "../include/GameOverWindow.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/ArenaProcedure.h"
#include "../include/NinjiaTribeApp.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;
using namespace cocos2d;


GameOverWindow::GameOverWindow()
{
	m_WindowType = _TYPED_WINDOW_GAMEOVER_;
}

GameOverWindow::~GameOverWindow()
{

}

bool GameOverWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_GAMEOVERWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_GAMEOVERWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);

	return IWindow::Init();
}

bool GameOverWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;
		cocos2d::CCMenuItemImage* pMenuItemBtnBack = (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("gameover/back");
		pMenuItemBtnBack->setTarget(this,menu_selector(GameOverWindow::OnBackBtnHandler));
		return true;
	} 
	while (false);

	return false;
}

void GameOverWindow::Tick()
{
	IWindow::Tick();
}

void GameOverWindow::Destroy()
{
	IWindow::Destroy();
}

void GameOverWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_GAMEOVERWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_GAMEOVERWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
}

void GameOverWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void GameOverWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void GameOverWindow::OnBackBtnHandler(cocos2d::CCObject* pSender)
{
	//Destroy();
	//EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_ARENAWINDOW_);
	NinjiaTribeApp::get_instance2()->m_pArenaProcedure->ChangeToLobbyProcedure();
}
