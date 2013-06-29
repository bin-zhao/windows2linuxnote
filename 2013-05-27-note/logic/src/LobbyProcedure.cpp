#include "../include/LobbyProcedure.h"
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
#include "../include/SelectBuffProcedure.h"
#include "../include/WindowManager.h"
#include "../include/IWindow.h"
#include <list>


LobbyProcedure::LobbyProcedure()
{
	m_Type = _TYPED_LOBBY_PROCEDURE_;
}

LobbyProcedure::~LobbyProcedure()
{

}

void LobbyProcedure::ChangeToArenaProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pArenaProcedure);
	LOGGERSYSTEM->LogInfo("LoginProcedure: ChangeToArenaProcedure\n");
}

void LobbyProcedure::ChangeToSelectBuffProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pSelectBuffProcedure);
	LOGGERSYSTEM->LogInfo("LoginProcedure: ChangeToArenaProcedure\n");
}

void LobbyProcedure::ChangeToLoginProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLoginProcedure);
	LOGGERSYSTEM->LogInfo("LoginProcedure: ChangeToArenaProcedure\n");
}

bool  LobbyProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("LobbyProcedure::Init()")
		
		_BEGIN_PROF_CHUNK_("LobbyProcedure::Play Lobby.mp3")
		//显示Lobby窗口
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_LOBBYWINDOW_);
		// 播放音效
		SOUNDSYSTEM->PlayBackgroundMusic("resource/media/lobby.mp3");
		LOGGERSYSTEM->LogInfo("LobbyProcedure: Enter\n");
		_END_PROF_CHUNK_()

		_END_PROF_CHUNK_()
		return true;
	} 
	while (false);

	return false;
}

void  LobbyProcedure::Tick()
{
	// 执行输入处理
	OnInputEventHandler();
}

void  LobbyProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("LobbyProcedure::Destroy()")

	_BEGIN_PROF_CHUNK_("LobbyProcedure::Hide Lobby Window")
	// 隐藏UI
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_LOBBYWINDOW_);
	_END_PROF_CHUNK_()

	_BEGIN_PROF_CHUNK_("LobbyProcedure::ForceFreeMomery")
	// 释放无用资源
	NinjiaTribeApp::get_instance2()->ForceFreeMemory();
	_END_PROF_CHUNK_()

	_BEGIN_PROF_CHUNK_("LobbyProcedure::StopBackground Music")
	if (NinjiaTribeApp::get_instance2()->m_pActiveProcedure != NinjiaTribeApp::get_instance2()->m_pLoginProcedure)
	{// 停止背景音乐
		SOUNDSYSTEM->StopBackgroundMusic();
	}
	_END_PROF_CHUNK_()

	_END_PROF_CHUNK_()
	LOGGERSYSTEM->LogInfo("LobbyProcedure: Leave\n");
}

void  LobbyProcedure::OnInputEventHandler()
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

void  LobbyProcedure::OnSystemEnterBackEventHandler()
{

}

void  LobbyProcedure::OnSystemEnterFrontEventHandler()
{

}

void  LobbyProcedure::OnSystemPauseEventHandler()
{

}

void  LobbyProcedure::OnSystemResumeEventHandler()
{

}
