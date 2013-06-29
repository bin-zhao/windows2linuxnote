#include "../include/LoadingProcedure.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ProfSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/InputSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/TimeSystem.h"


LoadingProcedure::LoadingProcedure()
{
	m_Type = _TYPED_LOADING_PROCEDURE_;
}

LoadingProcedure::~LoadingProcedure()
{

}

bool  LoadingProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("LoadingProcedure::Init()")
		;
		_END_PROF_CHUNK_()
		LOGGERSYSTEM->LogInfo("LoadingProcedure: Enter\n");
		return true;
	} 
	while (false);

	return false;
}

void  LoadingProcedure::Tick()
{
	// 执行输入处理
	OnInputEventHandler();
}

void  LoadingProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("LoadingProcedure::Destroy()")
		;
	_END_PROF_CHUNK_()
	LOGGERSYSTEM->LogInfo("LoadingProcedure: Leave\n");
}

void  LoadingProcedure::OnInputEventHandler()
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

void  LoadingProcedure::OnSystemEnterBackEventHandler()
{

}

void  LoadingProcedure::OnSystemEnterFrontEventHandler()
{

}

void  LoadingProcedure::OnSystemPauseEventHandler()
{

}

void  LoadingProcedure::OnSystemResumeEventHandler()
{

}
