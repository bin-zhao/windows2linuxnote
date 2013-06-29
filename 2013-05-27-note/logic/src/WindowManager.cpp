#include "../include/WindowManager.h"
#include "../include/EngineSystem.h"
#include "../include/IWindow.h"
#include "../include/UILayoutDataManager.h"
#include "../include/UIWindowDataManager.h"
#include "../include/TopWindow.h"
#include "../include/AlertWindow.h"
#include "../include/MessageBoxWindow.h"
#include "../include/LogoWindow.h"
#include "../include/LoginWindow.h"
#include "../include/LobbyWindow.h"
#include "../include/SelectBuffWindow.h"
#include "../include/GameOverWindow.h"
#include "../include/LoadingWindow.h"
#include "../include/ScriptWindow.h"
#include "../include/ArenaWindow.h"
#include "../include/ResultWindow.h"
#include "../include/DBSystem.h"


template<> WindowManager* cobra_win::Singleton2<WindowManager>::m_pMySelf = NULL;

WindowManager::WindowManager()
{
	m_WindowList.clear();
}

WindowManager::~WindowManager()
{

}

IWindow* WindowManager::GetWindowByType(int iWindowType)
{
	std::map<int, IWindow*>::iterator iter = m_WindowList.find(iWindowType);
	if (iter == m_WindowList.end())
		return NULL;

	return iter->second;
}

bool WindowManager::IsWindowVisible(int iWindowType)
{
	std::map<int, IWindow*>::iterator iter = m_WindowList.find(iWindowType);
	if (iter == m_WindowList.end())
		return false;

	return iter->second->IsVisible();
}

void WindowManager::HideAllWindow(bool bVisible)
{
	std::map<int, IWindow*>::iterator iter   = m_WindowList.begin();
	std::map<int, IWindow*>::iterator iter_e = m_WindowList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if (iter->second->IsLoad())
		{
			iter->second->Show(bVisible);
		}
	}
}

size_t WindowManager::GetWindowCount()
{
	return m_WindowList.size();
}

IWindow* WindowManager::GetWindowByIndex(size_t iIndex)
{
	if (iIndex >= m_WindowList.size())
		return NULL;

	std::map<int, IWindow*>::iterator iter = m_WindowList.begin();
	for (size_t i=0; i!=iIndex; ++i)
	{
		++iter;
	}
	return iter->second;
}

UILayoutDataManager* WindowManager::GetUILayoutByWindowType(int iWindowType)
{
	return DBSYSTEM->GetUILayoutDataManagerByType(iWindowType);
}

bool WindowManager::Init()
{
	m_WindowList.clear();

	IWindow* pWindow = new TopWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new AlertWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new MessageBoxWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new LogoWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new LoginWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new LoadingWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new LobbyWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new SelectBuffWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new GameOverWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	pWindow = new ArenaWindow();
	m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));
	//pWindow = new ResultWindow();
	//m_WindowList.insert(std::map<int, IWindow*>::value_type(pWindow->GetWindowType(), pWindow));

	// 注册脚本窗口
	for (unsigned int i=0; i<UIWindowDataManager::get_instance2()->GetWindowNumber(); i++)
	{
		UIWindowItemData* pItem = UIWindowDataManager::get_instance2()->GetWindowByPos(i);
		if (pItem && pItem->mIsScriptWindow)
		{
			ScriptWindow* pScriptWindow = new ScriptWindow(pItem->mWindowType, pItem->mWindowName, pItem->mWindowScriptName);
			m_WindowList.insert(std::map<int, IWindow*>::value_type(pScriptWindow->GetWindowType(), pScriptWindow));
		}
	}

	return true;
}

void WindowManager::Tick()
{
	std::map<int, IWindow*>::iterator iter   = m_WindowList.begin();
	std::map<int, IWindow*>::iterator iter_e = m_WindowList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if (iter->second->IsLoad())
		{
			iter->second->Tick();
		}
	}
}

void WindowManager::Destroy()
{
	std::map<int, IWindow*>::iterator iter   = m_WindowList.begin();
	std::map<int, IWindow*>::iterator iter_e = m_WindowList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if (iter->second->IsLoad())
		{
			iter->second->Destroy();
		}

		delete iter->second;
	}
	m_WindowList.clear();
}
