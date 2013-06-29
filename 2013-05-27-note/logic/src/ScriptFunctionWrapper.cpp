#include "../include/ScriptFunctionWrapper.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/EngineSystem.h"
#include "../include/DBSystem.h"
#include "../include/DebugerSystem.h"
#include "../include/EventSystem.h"
#include "../include/GuideSystem.h"
#include "../include/UISystem.h"
#include "../include/WindowManager.h"
#include "../include/InputSystem.h"
#include "../include/NetSystem.h"
#include "../include/ScriptSystem.h"
#include "../include/SoundSystem.h"
#include "../include/TimeSystem.h"
#include "../include/IProcedure.h"
#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/SelectServerProcedure.h"
#include "../include/ObjectManager.h"
#include "../include/SysLangDataManager.h"
#include <include/UIWindowManager.h>
using  namespace  uiloader;


NinjiaTribeApp*  Lua_GetNinjiaTribeApp()
{
	return NinjiaTribeApp::get_instance2();
}

EngineSystem*   Lua_GetEngineSystem()
{
	return EngineSystem::get_instance2();
}

DBSystem*       Lua_GetDBSystem()
{
	return DBSystem::get_instance2();
}

EventSystem*    Lua_GetEventSystem()
{
	return EventSystem::get_instance2();
}

GuideSystem*    Lua_GetGuideSystem()
{
	return GuideSystem::get_instance2();
}

UISystem*       Lua_GetUISystem()
{
	return UISystem::get_instance2();
}

SoundSystem*    Lua_GetSoundSystem()
{
	return SoundSystem::get_instance2();
}

ObjectManager*  Lua_GetObjectManager()
{
	return ObjectManager::get_instance2();
}

SceneManager*   Lua_GetSceneManager()
{
	return SceneManager::get_instance2();
}

IWindow*        Lua_GetWindow(int iWindowType)
{
	return WindowManager::get_instance2()->GetWindowByType(iWindowType);
}

const char*     Lua_GetSysLangTextById(int langId)
{
	return SysLangDataManager::get_instance2()->GetSysLangById(langId).c_str();
}

LocalPlayerDataManager* Lua_GetLocalPlayerDataManager()
{
	return LocalPlayerDataManager::get_instance2();
}

CCNode*         Lua_GetCCNodeByName(char* pName)
{
	return (CCNode*)UIWindowManager::get_instance()->GetUIWindow(pName);
}

CCSprite*       Lua_GetCCSpriteByName(char* pName)
{
	return (CCSprite*)UIWindowManager::get_instance()->GetUIWindow(pName);
}

CCLabelTTF*     Lua_GetCCLabelTTFByName(char* pName)
{
	return (CCLabelTTF*)UIWindowManager::get_instance()->GetUIWindow(pName);
}

CCMenuItem*     Lua_GetCCMenuItemByName(char* pName)
{
	return (CCMenuItem*)UIWindowManager::get_instance()->GetUIWindow(pName);
}

void            Lua_SetCCLabelTTFText(char* pLabelName, int sysLangId)
{
	Lua_GetCCLabelTTFByName(pLabelName)->setString(SysLangDataManager::get_instance2()->GetSysLangById(sysLangId).c_str());
}
