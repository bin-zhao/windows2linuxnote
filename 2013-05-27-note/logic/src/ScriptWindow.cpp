#include "../include/ScriptWindow.h"
#include "../include/ScriptSystem.h"
#include "../include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include <include/LuaLoader.h>
#include <include/ScriptMgr.h>
using  namespace  lualoader;
using  namespace  cocos2d;


ScriptWindow::ScriptWindow(int iWindowType, std::string windowName, std::string scriptFileName)
{
	m_WindowType = iWindowType;
	m_WindowName = windowName;
	m_ScriptFileName = scriptFileName;
	m_bTickListener  = false;
}

ScriptWindow::~ScriptWindow()
{

}

std::string ScriptWindow::GetScriptFileName()
{
	return m_ScriptFileName;
}

void ScriptWindow::Fadeout(float time)
{
	IWindow::Fadeout(time);

	char buffer[1024] = "";
	sprintf(buffer, "On_%s_Fadeout_Handler", m_WindowName.c_str());
	LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
	if (!loader.call_lua_method(buffer, m_WindowType))
	{
		LOGGERSYSTEM->LogError("Tick ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
		return;
	}
}

bool ScriptWindow::Init()
{
	do 
	{
		if (!SCRIPTSYSTEM->LoadLuaFile(m_ScriptFileName))
		{
			LOGGERSYSTEM->LogError("Load ScriptWindow=%s File Failed, ScriptFile=%s, Error=%s\n", m_WindowName.c_str(), m_ScriptFileName.c_str(), LUA_SCRIPT_MGR->get_error_message());
			break;
		}

		char buffer[1024] = "";
		sprintf(buffer, "On_%s_Init_Handler", m_WindowName.c_str());
		LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
		if (!loader.call_lua_method(buffer, m_WindowType))
		{
			LOGGERSYSTEM->LogError("Init ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
			break;
		}

		return IWindow::Init();
	} 
	while (false);

	return false;
}

static void RecursionSetSubWindowType(cocos2d::CCNode* pNode, int windowType)
{
	if (pNode->getChildrenCount() <= 0)
		return;

	cocos2d::CCArray*  pArray = pNode->getChildren();
	cocos2d::CCObject* pObject;
	CCARRAY_FOREACH(pArray, pObject)
	{
		cocos2d::CCNode* pTemp = (cocos2d::CCNode*)pObject;
		pTemp->setTag(windowType);

		RecursionSetSubWindowType(pTemp, windowType);
	}
}

bool ScriptWindow::Load()
{
	do 
	{
		IWindow::Load();

		m_pRootNode->setTag(GetWindowType());
		RecursionSetSubWindowType(m_pRootNode, GetWindowType());

		char buffer[1024] = "";
		sprintf(buffer, "On_%s_Load_Handler", m_WindowName.c_str());
		LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
		if (!loader.call_lua_method(buffer, m_WindowType))
		{
			LOGGERSYSTEM->LogError("Load ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
			break;
		}

		return true;
	} 
	while (false);

	return false;
}

void ScriptWindow::Tick()
{
	IWindow::Tick();

	if (m_bLoaded)
	{
		if (m_bTickListener)
		{
			char buffer[1024] = "";
			sprintf(buffer, "On_%s_Tick_Handler", m_WindowName.c_str());
			LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
			if (!loader.call_lua_method(buffer, m_WindowType))
			{
				LOGGERSYSTEM->LogError("Tick ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
				return;
			}
		}
	}
}

void ScriptWindow::Destroy()
{
	do 
	{
		char buffer[1024] = "";
		sprintf(buffer, "On_%s_Destroy_Handler", m_WindowName.c_str());
		LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
		if (!loader.call_lua_method(buffer, m_WindowType))
		{
			LOGGERSYSTEM->LogError("Destroy ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
			break;
		}

		IWindow::Destroy();
		return;
	} 
	while (false);

	return ;
}

void ScriptWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	do 
	{
		std::vector<std::string> tempList;
		std::list<std::string>::iterator iter   = paramList.begin();
		std::list<std::string>::iterator iter_e = paramList.end();
		for ( ; iter!=iter_e; ++iter)
		{
			tempList.push_back(*iter);
		}

		LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());

		char buffer[1024] = "";
		sprintf(buffer, "On_%s_Event_Handler", m_WindowName.c_str());
		bool ret = false;
		if (paramList.size() == 0)
		{
			ret = loader.call_lua_method(buffer, m_WindowType, iEventType);
		}
		else if (paramList.size() == 1)
		{
			ret = loader.call_lua_method(buffer, m_WindowType, iEventType, tempList[0].c_str());
		}
		else if (paramList.size() == 2)
		{
			ret = loader.call_lua_method(buffer, m_WindowType, iEventType, tempList[0].c_str(), tempList[1].c_str());
		}
		else if (paramList.size() == 3)
		{
			ret = loader.call_lua_method(buffer, m_WindowType, iEventType, tempList[0].c_str(), tempList[1].c_str(), tempList[2].c_str());
		}
		else if (paramList.size() == 4)
		{
			ret = loader.call_lua_method(buffer, m_WindowType, iEventType, tempList[0].c_str(), tempList[1].c_str(), tempList[2].c_str(), tempList[3].c_str());
		}
		else if (paramList.size() == 5)
		{
			ret = loader.call_lua_method(buffer, m_WindowType, iEventType, tempList[0].c_str(), tempList[1].c_str(), tempList[2].c_str(), tempList[3].c_str(), tempList[4].c_str());
		}

		if (!ret)
		{
			LOGGERSYSTEM->LogError("On ScriptWindow=%s EventHandler Failed, Method=%s, ParamNumber=%d, Err=%s\n", m_WindowName.c_str(), buffer, paramList.size(), loader.get_error_message());
			break;
		}
	} 
	while (false);

	return;
}

bool ScriptWindow::ccTouchBegan(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	if (m_bModelWindow)
	{
		cocos2d::CCPoint touchLocation = touche->getLocation();

		char buffer[1024] = "";
		sprintf(buffer, "On_%s_OnTouchBegin_Handler", m_WindowName.c_str());
		LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
		if (!loader.call_lua_method(buffer, m_WindowType, touchLocation.x, touchLocation.y))
		{
			LOGGERSYSTEM->LogError("On TouchBegan ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
		}
	}

	return IWindow::ccTouchBegan(touche, event);
}

void ScriptWindow::ccTouchMoved(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	if (!m_bModelWindow)
		return;

	cocos2d::CCPoint preTouchLocation = touche->getPreviousLocation();
	cocos2d::CCPoint touchLocation    = touche->getLocation();

	char buffer[1024] = "";
	sprintf(buffer, "On_%s_OnTouchMove_Handler", m_WindowName.c_str());
	LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
	if (!loader.call_lua_method(buffer, m_WindowType, preTouchLocation.x, preTouchLocation.y, touchLocation.x, touchLocation.y))
	{
		LOGGERSYSTEM->LogError("On TouchMoved ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
	}
}

void ScriptWindow::ccTouchEnded(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	if (!m_bModelWindow)
		return;

	cocos2d::CCPoint touchLocation = touche->getLocation();

	char buffer[1024] = "";
	sprintf(buffer, "On_%s_OnTouchEnd_Handler", m_WindowName.c_str());
	LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
	if (!loader.call_lua_method(buffer, m_WindowType, touchLocation.x, touchLocation.y))
	{
		LOGGERSYSTEM->LogError("On TouchEnded ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
	}
}

void ScriptWindow::ccTouchCancel(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	if (!m_bModelWindow)
		return;

	cocos2d::CCPoint touchLocation = touche->getLocation();

	char buffer[1024] = "";
	sprintf(buffer, "On_%s_OnTouchCancel_Handler", m_WindowName.c_str());
	LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
	if (!loader.call_lua_method(buffer, m_WindowType, touchLocation.x, touchLocation.y))
	{
		LOGGERSYSTEM->LogError("On TouchCancel ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), buffer, loader.get_error_message());
	}
}
