#ifndef  _NINJIATRIBE_SCRIPTWINDOW_H_
#define  _NINJIATRIBE_SCRIPTWINDOW_H_


#include "IWindow.h"

class ScriptWindow : public IWindow
{
protected:
	std::string m_ScriptFileName;

public:
	ScriptWindow(int iWindowType, std::string windowName, std::string scriptFileName);
	virtual ~ScriptWindow();

public:
	/*
		得到对应的窗口脚本名称
	*/
	std::string GetScriptFileName();

public:
	/*
		渐隐窗口
	*/
	virtual    void    Fadeout(float time);

public:
	/*
		初始化处理
	*/
	virtual    bool    Init();
	/*
		加载处理
	*/
	virtual    bool    Load();
	/*
		桢更新处理
	*/
	virtual    void    Tick();
	/*
		销毁处理
	*/ 
	virtual    void    Destroy();

public:
	/*
		消息事件响应处理
	*/
	virtual    void    OnEventHandler(int iEventType, std::list<std::string>& paramList);

public:
	/*
		开始接触操作
	*/
	virtual    bool    ccTouchBegan(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
	/*
		移动操作
	*/
	virtual    void    ccTouchMoved(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
	/*
		接触结束操作
	*/
	virtual    void    ccTouchEnded(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
	/*
		接触取消操作
	*/
	virtual    void    ccTouchCancel(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
};


#endif
