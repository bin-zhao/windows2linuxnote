#include "../include/ArenaWindow.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/ArenaProcedure.h"
#include "../include/SceneManager.h"
#include "../include/ObjectManager.h"
#include "../include/Common.h"
#include "../include/LocalPlayerDataManager.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;
using  namespace  cocos2d;


ArenaWindow::ArenaWindow()
{
	m_WindowType = _TYPED_WINDOW_ARENA_;
}

ArenaWindow::~ArenaWindow()
{

}

bool  ArenaWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_ARENAWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_ARENAWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_ARENAWINDOW_, true);

	return IWindow::Init();
}

bool  ArenaWindow::Load()
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

void  ArenaWindow::Tick()
{
	IWindow::Tick();
}

void  ArenaWindow::Destroy()
{
	IWindow::Destroy();
}

void  ArenaWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_ARENAWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_ARENAWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_ARENAWINDOW_)
	{
		OnUpdateArenaWindowEventHandler(paramList);
	}
}

void  ArenaWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void  ArenaWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{
	
}

void  ArenaWindow::OnUpdateArenaWindowEventHandler(std::list<std::string>& paramList)
{
	
}
