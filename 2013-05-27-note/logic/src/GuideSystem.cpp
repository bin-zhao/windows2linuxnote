#include "../include/GuideSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/VariableSystem.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/NinjiaTribeApp.h"


template<> GuideSystem* cobra_win::Singleton2<GuideSystem>::m_pMySelf = NULL;

GuideSystem::GuideSystem()
{
	m_GuideStepType = _TYPED_GUIDE_STEP_UNKOWN_;
	m_GuideStepIndex= -1;
}

GuideSystem::~GuideSystem()
{

}

bool GuideSystem::IsNeedGuide()
{
	return true;
}

int GuideSystem::GetGuideType()
{
	return m_GuideStepType;
}

int GuideSystem::GetGuideIndex()
{
	return m_GuideStepIndex;
}

void GuideSystem::StartGuide(int guideType)
{

}

void GuideSystem::Next()
{

}

void GuideSystem::Finish()
{

}

bool  GuideSystem::Init()
{
	LOGGERSYSTEM->LogInfo("Init GuideSystem Success\n");
	return true;
}

void  GuideSystem::Tick()
{

}

void  GuideSystem::Destroy()
{
	LOGGERSYSTEM->LogInfo("Destroy GuideSystem Success\n");
}

void GuideSystem::OnMenuItemCallbackEventHandler(std::string eventName, std::string menuItemName)
{
	if (GUIDESYSTEM == NULL)
		return;
}
