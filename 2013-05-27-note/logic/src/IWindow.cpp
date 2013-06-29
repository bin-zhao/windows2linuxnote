#include "../include/IWindow.h"
#include "../include/UISystem.h"
#include "../include/LoggerSystem.h"
#include "../include/EngineSystem.h"
#include "../include/SoundSystem.h"
#include "../include/UILayoutDataManager.h"
#include "../include/UIWindowDataManager.h"
#include "../include/WindowManager.h"
#include "../include/NinjiaTribeApp.h"
#include <include/UIWindow.h>
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <include/LuaLoader.h>
#include <include/ScriptMgr.h>
#include <cocos2d.h>
#include <string>
using  namespace  uiloader;
using  namespace  lualoader;


IWindow::IWindow()
{
	m_WindowType   = _TYPED_WINDOW_UNKOWN_;
	m_WindowName   = "";
	m_bModelWindow = false;
	m_WindowZOrder = _TYPED_WINDOW_ZORDER_NORMAL_;
	m_bLoaded      = false;
	m_bShow        = false;
	m_bFadeout     = false;
	m_pRootNode    = NULL;
	m_bTickListener= true;
	m_TickCounter  = 0;

	m_FadeoutCounter= 0;

	m_ParentWindowName = "root";
}

IWindow::~IWindow()
{

}

int IWindow::GetWindowType()
{
	return m_WindowType;
}

bool IWindow::IsLoad()
{	
	return m_bLoaded;
}

cocos2d::CCNode* IWindow::GetRootNode()
{
	return m_pRootNode;
}

void IWindow::SetWindowDataByPos(std::string str, unsigned int pos)
{
	m_WindowDataList[pos] = str;
}

std::string IWindow::GetWindowDataByPos(unsigned int pos)
{
	return m_WindowDataList[pos];
}

void IWindow::SetTickListenser(bool bListenser)
{
	m_bTickListener = bListenser;
}

void IWindow::Show(bool bShow)
{
	if (m_bShow == bShow)
		return ;

	m_bShow = bShow;
	if (m_pRootNode == NULL)
		return ;

	if (bShow)
	{
		m_pRootNode->setVisible(true);
		PlayOpenSound();
	}
	else
	{
		m_pRootNode->setVisible(false);
	}
}

bool IWindow::IsFadeout()
{
	return m_bFadeout;
}

bool IWindow::IsVisible()
{
	if (m_bFadeout)
		return false;

	return m_bShow;
}

void IWindow::SetXPosition(float xPos)
{
	if (m_pRootNode == NULL)
		return ;

	m_pRootNode->setPositionX(xPos);
}

float IWindow::GetXPosition()
{
	if (m_pRootNode == NULL)
		return 0.0f;

	return m_pRootNode->getPositionX();
}

void IWindow::SetYPosition(float yPos)
{
	if (m_pRootNode == NULL)
		return ;

	m_pRootNode->setPositionY(yPos);
}

float IWindow::GetYPosition()
{
	if (m_pRootNode == NULL)
		return 0.0f;

	return m_pRootNode->getPositionY();
}

void IWindow::SetXScale(float xScale)
{
	if (m_pRootNode == NULL)
		return ;

	m_pRootNode->setScaleX(xScale);
}

void IWindow::SetYScale(float yScale)
{
	if (m_pRootNode == NULL)
		return ;

	m_pRootNode->setScaleY(yScale);
}

void IWindow::RegisterEvent(int iEventType, bool bNotifyOnlyWhenVisible)
{
	if (!bNotifyOnlyWhenVisible)
		UISYSTEM->RegisterUIEvent(iEventType, m_WindowType);
	else
		UISYSTEM->RegisterUIEvent2(iEventType, m_WindowType);
}

void IWindow::PushEvent(int iEventType)
{
	UISYSTEM->PushEvent(iEventType);
}

void IWindow::PushEvent(int iEventType, char* pArgs)
{
	assert(pArgs != NULL);

	UISYSTEM->PushEvent(iEventType, std::string(pArgs));
}

void IWindow::PlayOpenSound()
{
	UIWindowItemData* pItem = UIWindowDataManager::get_instance2()->GetWindowByType(m_WindowType);
	if (pItem==NULL && pItem->mSoundName[0]=='\0')
		return ;

	SOUNDSYSTEM->PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_COMMONBUTTON_, pItem->mSoundName, false);
}

void IWindow::RegisterTimerFunction(float time, std::string functionName)
{
	_SCRIPT_TIMER_FUNCTION_ func;
	func.mStartTime     = m_TickCounter;
	func.mIntervalTime  = int(time*NinjiaTribeApp::get_instance2()->GetFPS());
	func.mScriptFunction= functionName;
	m_ScriptTimerList.push_back(func);
}

void IWindow::Fadeout(float time)
{
	if (!m_bLoaded || m_bFadeout)
		return ;

	// 渐隐中
	m_bFadeout       = true;
	m_FadeoutCounter = int(NinjiaTribeApp::get_instance2()->GetFPS()*time);
}

bool IWindow::Init()
{
	UIWindowItemData* pWindowItem = UIWindowDataManager::get_instance2()->GetWindowByType(this->GetWindowType());
	m_bModelWindow = pWindowItem->mIsModelWindow;
	m_WindowZOrder = pWindowItem->mWindowZOrder;
	m_WindowName   = pWindowItem->mWindowName;
	m_ParentWindowName = pWindowItem->mWindowParentName;

	onEnter();
	LOGGERSYSTEM->LogInfo("Init UI Window, WindowType=%d, WindowName=%s\n", m_WindowType, m_WindowName.c_str());
	return true;
}

bool IWindow::Load()
{
	do 
	{
		m_bFadeout =false;
		m_FadeoutCounter = 0;

		// 加载布局文件
		UILayoutDataManager* pLayoutDataManager = WindowManager::get_instance2()->GetUILayoutByWindowType(this->GetWindowType());
		char* pText = pLayoutDataManager->GetLayoutText();
		unsigned int iLen = strlen(pText);
		m_pRootNode = (cocos2d::CCNode*)UILoaderSystem::get_instance()->LoadFromBuffer(pText, iLen);

		// 绑定到父节点
		UIWindowManager::get_instance()->GetUIWindow(m_ParentWindowName)->addChild(m_pRootNode, m_WindowZOrder);
		m_pRootNode->setVisible(false);

		// 注册消息处理事件
		if (m_bModelWindow)
		{
			cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, m_pRootNode->getPriority(), true);
		}

		m_bLoaded = true;
	} 
	while (false);

	LOGGERSYSTEM->LogInfo("Load UI Window, WindowType=%d, WindowName=%s\n", m_WindowType, m_WindowName.c_str());
	return true;
}

void IWindow::Tick()
{
	m_TickCounter++;

	// 淡出中...
	if (m_bFadeout)
	{
		m_FadeoutCounter--;
		if (m_FadeoutCounter <= 0)
		{
			m_bFadeout = false;
			m_FadeoutCounter = 0;
			Destroy();
		}
	}

	// 脚本定时回调处理
	std::list<_SCRIPT_TIMER_FUNCTION_>::iterator iter   = m_ScriptTimerList.begin();
	std::list<_SCRIPT_TIMER_FUNCTION_>::iterator iter_e = m_ScriptTimerList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<_SCRIPT_TIMER_FUNCTION_>::iterator temp = iter;
		++iter;

		if (((*temp).mStartTime+(*temp).mIntervalTime) <= m_TickCounter)
		{
			LuaLoader loader(LUA_SCRIPT_MGR->get_lua_state());
			if (!loader.call_lua_method((char*)((*temp).mScriptFunction.c_str()), m_WindowType))
			{
				LOGGERSYSTEM->LogError("Timer ScriptWindow=%s Failed, Method=%s, Err=%s\n", m_WindowName.c_str(), (*temp).mScriptFunction.c_str(), loader.get_error_message());
				return;
			}

			m_ScriptTimerList.erase(temp);
		}
	}
}

void IWindow::Destroy()
{
	do 
	{
		// 删除脚本定时回调列表
		m_ScriptTimerList.clear();

		// 卸载消息处理事件
		if (m_bModelWindow)
		{
			cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
		}

		// 从父节点删除当前窗口
		if (m_pRootNode != NULL)
		{
			UIWindowManager::get_instance()->RemoveUIWindow((UIWindow*)m_pRootNode);
			UIWindowManager::get_instance()->GetUIWindow(m_ParentWindowName)->removeChild(m_pRootNode, true);
			m_pRootNode = NULL;
		}

		m_bShow   = false;
		m_bLoaded = false;

		m_bFadeout= false;
		m_FadeoutCounter = 0;
	}
	while (false);

	LOGGERSYSTEM->LogInfo("UnLoad UI Window, WindowType=%d, WindowName=%s\n", m_WindowType, m_WindowName.c_str());
}

bool IWindow::ccTouchBegan(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{
	return m_bModelWindow;
}

void IWindow::ccTouchMoved(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{

}

void IWindow::ccTouchEnded(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{

}

void IWindow::ccTouchCancel(cocos2d::CCTouch* touche, cocos2d::CCEvent* event)
{

}
