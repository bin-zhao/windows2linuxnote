#include "../include/SelectServerProcedure.h"
#include "../include/LoginProcedure.h"
#include "../include/LoggerSystem.h"
#include "../include/InputSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/TimeSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ProfSystem.h"
#include <list>


SelectServerProcedure::SelectServerProcedure()
{
	m_Type = _TYPED_SELECTSERVER_PROCEDURE_;
}

SelectServerProcedure::~SelectServerProcedure()
{

}

void SelectServerProcedure::ChangeToLoginProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLoginProcedure);
	LOGGERSYSTEM->LogInfo("SelectServerProcedure: ChangeToLoginProcedure\n");
}

bool  SelectServerProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("SelectServerProcedure::Init()")

		// 显示选服UI界面
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_SELECTSERVERWINDOW_);

		_END_PROF_CHUNK_()
		LOGGERSYSTEM->LogInfo("SelectServerProcedure: Enter\n");
		return true;
	} 
	while (false);

	return false;
}

void  SelectServerProcedure::Tick()
{
	// 执行输入处理
	OnInputEventHandler();
}

void  SelectServerProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("SelectServerProcedure::Destroy()")
	// 隐藏选服UI界面
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_SELECTSERVERWINDOW_);

	// 释放无用资源
	NinjiaTribeApp::get_instance2()->ForceFreeMemory();

	_END_PROF_CHUNK_()
	LOGGERSYSTEM->LogInfo("SelectServerProcedure: Leave\n");
}

void  SelectServerProcedure::OnInputEventHandler()
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
				;
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

void  SelectServerProcedure::OnSystemEnterBackEventHandler()
{

}

void  SelectServerProcedure::OnSystemEnterFrontEventHandler()
{

}

void  SelectServerProcedure::OnSystemPauseEventHandler()
{

}

void  SelectServerProcedure::OnSystemResumeEventHandler()
{

}
