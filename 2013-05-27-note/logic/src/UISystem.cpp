#include "../include/UISystem.h"
#include "../include/VariableSystem.h"
#include "../include/EventDef.h"
#include "../include/EventSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/WindowManager.h"
#include "../include/IWindow.h"
#include "../include/EngineSystem.h"
#include "../include/UILayer.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;


template<> UISystem* cobra_win::Singleton2<UISystem>::m_pMySelf = NULL;

UISystem::UISystem()
{
	m_pUILayer = NULL;
}

UISystem::~UISystem()
{

}

cocos2d::CCLayer* UISystem::GetUILayer()
{
	return m_pUILayer;
}

void UISystem::OnInputEventHandler()
{

}

void UISystem::RegisterUIEvent(int iEventType, int iWindowType)
{
	char buffer[1024] = "";
	sprintf(buffer, "%d", iWindowType);
	EVENTSYSTEM->RegisterEventHandler(iEventType, OnUISystemEventHandler, buffer);
}

void UISystem::RegisterUIEvent2(int iEventType, int iWindowType)
{
	char buffer[1024] = "";
	sprintf(buffer, "%d", iWindowType);
	EVENTSYSTEM->RegisterEventHandler(iEventType, OnUISystemEventHandler2, buffer);
}

void UISystem::RegisterUIEvent(int iEventType)
{
	EVENTSYSTEM->RegisterEventHandler(iEventType, OnUISystemEventHandler, "");
}

void UISystem::PushEvent(int iEventType)
{
	EVENTSYSTEM->PushEvent(iEventType);
}

void UISystem::PushEvent(int iEventType, std::string param0)
{
	EVENTSYSTEM->PushEvent(iEventType, param0);
}

bool UISystem::Init()
{
	do 
	{
		// 创建根窗口节点
		m_pUILayer = new UILayer();
		m_pUILayer->init();
		m_pUILayer->autorelease();
		m_pUILayer->setUIWindowType("CCLayer");
		m_pUILayer->setUIWindowName("root");
		m_pUILayer->setAnchorPoint(cocos2d::CCPointZero);
		ENGINESYSTEM->GetScene()->addChild(m_pUILayer);

		// 初始化UILoader
		bool bEncryption = false;
		char buffer[1024] = "com.cyou.mrd.yaojilayout357951";
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "UILayoutEncryptionKey", buffer, sizeof(buffer));
		uiloader::UILoaderSystem::get_instance()->Init(bEncryption, buffer);

		// 将根节点插入UILoader的管理器里面
		uiloader::UIWindowManager::get_instance()->InsertUIWindow((uiloader::UIWindow*)m_pUILayer);

		// 创建并初始化窗口管理器
		new WindowManager;
		WINDOWMANAGER->Init();

		// 所有窗口初始化操作
		for (size_t i=0; i<WINDOWMANAGER->GetWindowCount(); ++i)
		{
			IWindow* pWindow = WINDOWMANAGER->GetWindowByIndex(i);
			pWindow->Init();
		}

		LOGGERSYSTEM->LogInfo("Init UISystem Success\n");

		return true;
	} 
	while(false);

	LOGGERSYSTEM->LogInfo("Init UISystem Failed\n");
	return false;
}

void UISystem::Tick()
{
	WINDOWMANAGER->Tick();
}

void UISystem::Destroy()
{
	// 销毁UILoader
	uiloader::UILoaderSystem::get_instance()->Destroy();

	// 销毁窗口管理器
	if (WINDOWMANAGER != NULL)
	{
		WINDOWMANAGER->Destroy();
		delete WINDOWMANAGER;
	}

	// 销毁UI根窗口
	if (m_pUILayer != NULL)
	{
		ENGINESYSTEM->GetScene()->removeChild(m_pUILayer, true);
		m_pUILayer = NULL;
	}

	LOGGERSYSTEM->LogInfo("Destroy UISystem Success\n");
}

void UISystem::OnUISystemEventHandler(int iEventType, std::string owerData, std::list<std::string>& paramList)
{
	if (owerData != "")
	{
		int iWindowType = 0;
		sscanf(owerData.c_str(), "%d", &iWindowType);
		IWindow* pWindow = WINDOWMANAGER->GetWindowByType(iWindowType);
		if (pWindow == NULL)
			return ;

		// 如果在淡出中，则直接效果，防止逻辑BUG
		if (pWindow->IsFadeout())
			pWindow->Destroy();

		// 没有加载，则直接加载
		if (!pWindow->IsLoad())
			pWindow->Load();

		pWindow->OnEventHandler(iEventType, paramList);
	}

	return ;
}

void UISystem::OnUISystemEventHandler2(int iEventType, std::string owerData, std::list<std::string>& paramList)
{
	if (owerData != "")
	{
		int iWindowType = 0;
		sscanf(owerData.c_str(), "%d", &iWindowType);
		IWindow* pWindow = WINDOWMANAGER->GetWindowByType(iWindowType);
		if (pWindow == NULL)
			return ;

		// 如果在淡出中，相当于未加载，直接退出
		if (pWindow->IsFadeout())
			return;

		if (!pWindow->IsLoad())
			return;

		pWindow->OnEventHandler(iEventType, paramList);
	}

	return ;
}
