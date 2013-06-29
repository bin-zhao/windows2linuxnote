#include "../include/ScriptSystem.h"
#include "../include/VariableSystem.h"
#include "../Include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/LuaCocos2dHandler.h"
#include "../include/LuaNinjiaHandler.h"
#include "../include/TimeSystem.h"
#include <include/ScriptMgr.h>
#include <include/LuaLoader.h>
#include <include/common/FileLoader.h>
#include <include/common/File.h>
#include <include/common/String.h>
using  namespace  lualoader;


template<> ScriptSystem* cobra_win::Singleton2<ScriptSystem>::m_pMySelf = NULL;

ScriptSystem::ScriptSystem()
{

}

ScriptSystem::~ScriptSystem()
{

}

bool ScriptSystem::LoadLuaBuffer(char* pBuffer)
{
	return LUA_SCRIPT_MGR->load_lua_script_buffer(pBuffer);
}

bool  ScriptSystem::Init()
{
	do 
	{
		new ScriptMgr;
		if (!LUA_SCRIPT_MGR->init_script_manager())
			break;

		// 测试专用
		if (!LoadLuaBuffer("print(\"lua test ok!!!\")"))
		{
			LOGGERSYSTEM->LogInfo("Init ScriptSystem Failed, Lua Error=%s\n", LUA_SCRIPT_MGR->get_error_message());
			break;
		}

		// 测试专用
		if (!LoadLuaFile("resource/script/test.lua"))
		{
			LOGGERSYSTEM->LogInfo("Init ScriptSystem Failed, Lua Error=%s\n", LUA_SCRIPT_MGR->get_error_message());
			break;
		}

		// 测试专用
		LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
		if (!loader.call_lua_method("lua_test", 10))
		{
			LOGGERSYSTEM->LogInfo("Init ScriptSystem Failed, Lua Error=%s\n", loader.get_error_message());
			break;
		}

		// 注册cocos2d对象
		tolua_cocos2d_open(LUA_SCRIPT_MGR->get_lua_state());
		// 注册客户端对象
		tolua_ninjia_open(LUA_SCRIPT_MGR->get_lua_state());

		//  注册Lua回调处理
		cocos2d::CCScriptEngineProtocol* pLuaProtocal = dynamic_cast<cocos2d::CCScriptEngineProtocol*>(this);
		cocos2d::CCScriptEngineManager::sharedManager()->setScriptEngine(pLuaProtocal);

		LOGGERSYSTEM->LogInfo("Init ScriptSystem Success\n");
		return true;
	} 
	while (false);

	LOGGERSYSTEM->LogInfo("Init ScriptSystem Failed\n");
	return false;
}

void  ScriptSystem::Tick()
{
	static long long sLastReleaseTime = 0;
	if (TimeSystem::GetCurrentSecond()-sLastReleaseTime >= 5)
	{
		lua_gc(LUA_SCRIPT_MGR->get_lua_state(), LUA_GCCOLLECT, 0);
		sLastReleaseTime = TimeSystem::GetCurrentSecond();
	}
}

void  ScriptSystem::Destroy()
{
	if (LUA_SCRIPT_MGR != NULL)
	{
		LUA_SCRIPT_MGR->destroy_script_manager();
		delete LUA_SCRIPT_MGR;
	}

	cocos2d::CCScriptEngineManager::sharedManager()->setScriptEngine(NULL);
	LOGGERSYSTEM->LogInfo("Destroy ScriptSystem Success\n");
}

bool ScriptSystem::LoadLuaFile(std::string filename)
{
	bool bLuaEncrypt = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "IsLuaEncrypted", bLuaEncrypt);
	char key[1024] = "minitriple-cyou-inc";
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "LuaEncryptionKey", key, sizeof(key));

	char*        pBuffer = NULL;
	unsigned int iLength = 0;
	if (!EngineSystem::LoadAppFile((char*)filename.c_str(), pBuffer, iLength))
		return false;

	if (bLuaEncrypt)
	{
		// 开始XOR加密解密
		int keyLen = strlen(key);
		for (unsigned int i=0; i<iLength; i++)
		{
			char temp = pBuffer[i];
			pBuffer[i] = (char)(temp^key[i%keyLen]);
		}
	}

	// 加载字节流
	bool ret = LoadLuaBuffer(pBuffer);
	delete []pBuffer;
	return ret;
}

cocos2d::ccScriptType ScriptSystem::getScriptType()
{
	return cocos2d::kScriptTypeLua;
}

void ScriptSystem::removeScriptObjectByCCObject(cocos2d::CCObject* pObj)
{

}

void ScriptSystem::removeScriptHandler(int nHandler)
{

}

int ScriptSystem::executeString(const char* codes)
{
	return 0;
}

int ScriptSystem::executeScriptFile(const char* filename)
{
	return 0;
}

int ScriptSystem::executeGlobalFunction(const char* functionName)
{
	LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
	if (!loader.call_lua_method((char*)functionName))
	{
		LOGGERSYSTEM->LogError("Call Function=%s Failed, Err=%s\n", functionName, loader.get_error_message());
	}

	return 0;
}

int ScriptSystem::executeMenuItemClick(const char* functionName, int param0)
{
	LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
	if (!loader.call_lua_method((char*)functionName, param0))
	{
		LOGGERSYSTEM->LogError("Call Function=%s Failed, Err=%s\n", functionName, loader.get_error_message());
	}

	return 0;
}

int ScriptSystem::executeNodeEvent(cocos2d::CCNode* pNode, int nAction)
{
	return 0;
}

int ScriptSystem::executeMenuItemEvent(cocos2d::CCMenuItem* pMenuItem)
{
	return 0;
}

int ScriptSystem::executeNotificationEvent(cocos2d::CCNotificationCenter* pNotificationCenter, const char* pszName)
{
	return 0;
}

int ScriptSystem::executeCallFuncActionEvent(cocos2d::CCCallFunc* pAction, cocos2d::CCObject* pTarget)
{
	return 0;
}

int ScriptSystem::executeSchedule(cocos2d::CCTimer* pTimer, float dt, cocos2d::CCNode* pNode)
{
	return 0;
}

int ScriptSystem::executeLayerTouchesEvent(cocos2d::CCLayer* pLayer, int eventType, cocos2d::CCSet* pTouches)
{
	return 0;
}

int ScriptSystem::executeLayerTouchEvent(cocos2d::CCLayer* pLayer, int eventType, cocos2d::CCTouch* pTouch)
{
	return 0;
}
