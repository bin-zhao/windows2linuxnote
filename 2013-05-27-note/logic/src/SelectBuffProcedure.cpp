#include "../include/SelectBuffProcedure.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ProfSystem.h"
#include "../include/SoundSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/InputSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/TimeSystem.h"
#include "../include/ArenaProcedure.h"
#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/WindowManager.h"
#include "../include/IWindow.h"

#include <list>


SelectBuffProcedure::SelectBuffProcedure()
{
	m_Type = _TYPED_SELECTBUFF_PROCEDURE_;
}

SelectBuffProcedure::~SelectBuffProcedure()
{

}

void SelectBuffProcedure::ChangeToArenaProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pArenaProcedure);
	LOGGERSYSTEM->LogInfo("BuffProcedure: ChangeToArenaProcedure\n");
}

void SelectBuffProcedure::ChangeToLoginProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLoginProcedure);
	LOGGERSYSTEM->LogInfo("BuffProcedure: ChangeToLoginProcedure\n");
}

void SelectBuffProcedure::ChangeToLobbyProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLobbyProcedure);
	LOGGERSYSTEM->LogInfo("BuffProcedure: ChangeToLobbyProcedure\n");
}


bool  SelectBuffProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("BuffProcedure::Init()")
		
		_BEGIN_PROF_CHUNK_("BuffProcedure::Play Lobby.mp3")
		//显示buff窗口
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_SELECTBUFFWINDOW_);
		_END_PROF_CHUNK_()

		_END_PROF_CHUNK_()
		return true;
	} 
	while (false);

	return false;
}

void  SelectBuffProcedure::Tick()
{
	// 执行输入处理
	OnInputEventHandler();
}

void  SelectBuffProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("BuffProcedure::Destroy()")

	_BEGIN_PROF_CHUNK_("BuffProcedure::Hide Lobby Window")
	// 隐藏UI
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_SELECTBUFFWINDOW_);
	_END_PROF_CHUNK_()

	_BEGIN_PROF_CHUNK_("BuffProcedure::ForceFreeMomery")
	// 释放无用资源
	NinjiaTribeApp::get_instance2()->ForceFreeMemory();
	_END_PROF_CHUNK_()

	_BEGIN_PROF_CHUNK_("BuffProcedure::StopBackground Music")

	_END_PROF_CHUNK_()

	_END_PROF_CHUNK_()
	LOGGERSYSTEM->LogInfo("BuffProcedure: Leave\n");
}

void  SelectBuffProcedure::OnInputEventHandler()
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

void  SelectBuffProcedure::OnSystemEnterBackEventHandler()
{

}

void  SelectBuffProcedure::OnSystemEnterFrontEventHandler()
{

}

void  SelectBuffProcedure::OnSystemPauseEventHandler()
{

}

void  SelectBuffProcedure::OnSystemResumeEventHandler()
{

}
