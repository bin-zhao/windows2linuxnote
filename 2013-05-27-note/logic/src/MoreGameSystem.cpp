#include "../include/MoreGameSystem.h"
#include "../include/VariableSystem.h"
#include "../include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/SysLangDataManager.h"
#include "../include/NinjiaTribeApp.h"


template<> MoreGameSystem* cobra_win::Singleton2<MoreGameSystem>::m_pMySelf = NULL;

MoreGameSystem::MoreGameSystem()
{

}

MoreGameSystem::~MoreGameSystem()
{

}

void MoreGameSystem::OpenMoreGamePanel()
{
	// Win32测试专用，正常退出时，判断是否有内存泄露
	NinjiaTribeApp::get_instance2()->SetRun(false);
}

bool MoreGameSystem::Init()
{
	LOGGERSYSTEM->LogInfo("Init MoreGameSystem Success\n");
	return true;
}

void MoreGameSystem::Tick()
{

}

void MoreGameSystem::Destroy()
{
	LOGGERSYSTEM->LogInfo("Destroy MoreGameSystem Success\n");
}
