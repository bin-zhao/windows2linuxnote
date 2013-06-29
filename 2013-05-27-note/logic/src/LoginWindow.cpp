#include "../include/LoginWindow.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/LoginProcedure.h"
#include "../include/NinjiaTribeApp.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;
using namespace cocos2d;


LoginWindow::LoginWindow()
{
	m_WindowType = _TYPED_WINDOW_LOGIN_;
}

LoginWindow::~LoginWindow()
{

}

bool LoginWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_LOGINWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_LOGINWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);

	return IWindow::Init();
}

bool LoginWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;
		cocos2d::CCMenuItemImage* pMenuItemBtnPlay = (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("login/play");
		pMenuItemBtnPlay->setTarget(this,menu_selector(LoginWindow::OnPlayBtnHandler));
		return true;
	} 
	while (false);

	return false;
}

void LoginWindow::Tick()
{
	IWindow::Tick();
}

void LoginWindow::Destroy()
{
	IWindow::Destroy();
}

void LoginWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_LOGINWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_LOGINWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
}

void LoginWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void LoginWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void LoginWindow::OnPlayBtnHandler(cocos2d::CCObject* pSender)
{
	NinjiaTribeApp::get_instance2()->m_pLoginProcedure->ChangeToLobbyProcedure();
}
