#include "../include/LogoProcedure.h"
#include "../include/LoggerSystem.h"
#include "../include/InputSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/TimeSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ProfSystem.h"
#include "../include/LoginProcedure.h"
#include "../include/SelectServerProcedure.h"
#include <list>


LogoProcedure::LogoProcedure()
{
	m_Type = _TYPED_LOGO_PROCEDURE_;
	
	m_LogicTickCounter = 0;
}

LogoProcedure::~LogoProcedure()
{

}

void  LogoProcedure::ChangeToNextProcedure()
{
	bool bSelServer = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "SelectServer", bSelServer);
	if (bSelServer)
	{
		NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pSelServerProcedure);
	}
	else
	{
		NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLoginProcedure);
	}
}

bool  LogoProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("LogoProcedure::Init()")

		// 显示UI
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_LOGOWINDOW_);

		_END_PROF_CHUNK_()
		LOGGERSYSTEM->LogInfo("LogoProcedure: Enter\n");
		return true;
	} 
	while (false);

	return false;
}

void  LogoProcedure::Tick()
{
	// 执行输入处理
	OnInputEventHandler();

	m_LogicTickCounter++;
	
	float idleTime = 0.5f;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "LogoProcedureIdleTime", idleTime);
	if (m_LogicTickCounter >= int(idleTime*NinjiaTribeApp::get_instance2()->GetFPS()))
	{
		ChangeToNextProcedure();
	}
}

void  LogoProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("SelectServerProcedure::Destroy()")
	// 隐藏UI
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_LOGOWINDOW_);
	// 释放无用资源
	NinjiaTribeApp::get_instance2()->ForceFreeMemory();
	_END_PROF_CHUNK_()

	LOGGERSYSTEM->LogInfo("LogoProcedure: Leave\n");
}

void  LogoProcedure::OnInputEventHandler()
{
	std::list<InputEvent>& inputList = INPUTSYSTEM->GetInputEventQueue();
	std::list<InputEvent>::iterator iter   = inputList.begin();
	std::list<InputEvent>::iterator iter_e = inputList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		InputEvent& inputEvent = *iter;
		if (inputEvent.mProcessed)
			continue;

		switch (inputEvent.mEventID)
		{
		case _TYPED_INPUT_EVENT_TOUCHBEGIN_:
			{
				;
			}
			break;
		case _TYPED_INPUT_EVENT_TOUCHMOVE_:
			{
				;
			}
			break;
		case _TYPED_INPUT_EVENT_TOUCHEND_:
			{
				ChangeToNextProcedure();
			}
			break;
		case _TYPED_INPUT_EVENT_ACCELERATE_:
			{
				;
			}
			break;
		case _TYPED_INPUT_EVENT_KEY_BACK_CLICKED_:
			{
				;
			}
			break;
		case _TYPED_INPUT_EVENT_KEY_MENU_CLICKED_:
			{
				;
			}
			break;
		}
	}
	inputList.clear();
}

void  LogoProcedure::OnSystemEnterBackEventHandler()
{

}

void  LogoProcedure::OnSystemEnterFrontEventHandler()
{

}

void  LogoProcedure::OnSystemPauseEventHandler()
{

}

void  LogoProcedure::OnSystemResumeEventHandler()
{

}
