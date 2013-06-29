#ifndef  _NINJIATRIBE_SCRIPTSYSTEM_H_
#define  _NINJIATRIBE_SCRIPTSYSTEM_H_


#include <include/common/Singleton.h>
#include <script_support/CCScriptSupport.h>
#include <string>
using  namespace  cobra_win;

class ScriptSystem : public cocos2d::CCScriptEngineProtocol, public cobra_win::Singleton2<ScriptSystem>
{
public:
	ScriptSystem();
	virtual ~ScriptSystem();

public:
	/*
		加载指定的文件
	*/
	bool  LoadLuaFile(std::string filename);
	/*
		加载指定的Lua Buffer
	*/
	bool  LoadLuaBuffer(char* pBuffer);
	
public:
	/*
		初始化脚本系统管理器
	*/
	bool  Init();
	/*
		脚本系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁脚本系统管理器
	*/
	void  Destroy();

public:
	virtual cocos2d::ccScriptType getScriptType();
    virtual void removeScriptObjectByCCObject(cocos2d::CCObject* pObj);
    virtual void removeScriptHandler(int nHandler);
    virtual int executeString(const char* codes);
    virtual int executeScriptFile(const char* filename);
    virtual int executeGlobalFunction(const char* functionName);
	virtual int executeMenuItemClick(const char* functionName, int param0);
    virtual int executeNodeEvent(cocos2d::CCNode* pNode, int nAction);
    virtual int executeMenuItemEvent(cocos2d::CCMenuItem* pMenuItem);
    virtual int executeNotificationEvent(cocos2d::CCNotificationCenter* pNotificationCenter, const char* pszName);
    virtual int executeCallFuncActionEvent(cocos2d::CCCallFunc* pAction, cocos2d::CCObject* pTarget = NULL);
    virtual int executeSchedule(cocos2d::CCTimer* pTimer, float dt, cocos2d::CCNode* pNode = NULL);
    virtual int executeLayerTouchesEvent(cocos2d::CCLayer* pLayer, int eventType, cocos2d::CCSet* pTouches);
    virtual int executeLayerTouchEvent(cocos2d::CCLayer* pLayer, int eventType, cocos2d::CCTouch* pTouch);

public:
	friend  class  cobra_win::Singleton2<ScriptSystem>;
};

#define  SCRIPTSYSTEM  (ScriptSystem::get_instance2())


#endif
