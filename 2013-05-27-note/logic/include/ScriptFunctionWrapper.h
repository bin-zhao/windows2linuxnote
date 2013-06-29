#ifndef  _NINJIATRIBE_SCRIPTFUNCTIONWRAPPER_H_
#define  _NINJIATRIBE_SCRIPTFUNCTIONWRAPPER_H_


#include "../include/NinjiaTribeApp.h"
#include "../include/VariableSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/EngineSystem.h"
#include "../include/DBSystem.h"
#include "../include/DebugerSystem.h"
#include "../include/EventSystem.h"
#include "../include/GuideSystem.h"
#include "../include/UISystem.h"
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
#include "../include/SceneManager.h"
#include "../include/IWindow.h"
#include "../include/LocalPlayerDataManager.h"
using namespace cocos2d;


NinjiaTribeApp* Lua_GetNinjiaTribeApp();

EngineSystem*   Lua_GetEngineSystem();

DBSystem*       Lua_GetDBSystem();

EventSystem*    Lua_GetEventSystem();

GuideSystem*    Lua_GetGuideSystem();

UISystem*       Lua_GetUISystem();

SoundSystem*    Lua_GetSoundSystem();

ObjectManager*  Lua_GetObjectManager();

SceneManager*   Lua_GetSceneManager();

IWindow*        Lua_GetWindow(int iWindowType);

const char*     Lua_GetSysLangTextById(int langId);

LocalPlayerDataManager*  Lua_GetLocalPlayerDataManager();

CCNode*         Lua_GetCCNodeByName(char* pName);
CCSprite*       Lua_GetCCSpriteByName(char* pName);
CCLabelTTF*     Lua_GetCCLabelTTFByName(char* pName);
CCMenuItem*     Lua_GetCCMenuItemByName(char* pName);

void            Lua_SetCCLabelTTFText(char* pLabelName, int sysLangId);


#endif
