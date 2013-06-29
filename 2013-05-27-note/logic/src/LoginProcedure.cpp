#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/SelectServerProcedure.h"
#include "../include/SoundSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ArenaProcedure.h"
#include "../include/LoggerSystem.h"
#include "../include/InputSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "../include/TimeSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/ProfSystem.h"
#include <list>


LoginProcedure::LoginProcedure()
{
	m_Type = _TYPED_LOGIN_PROCEDURE_;
}

LoginProcedure::~LoginProcedure()
{

}

void LoginProcedure::ChangeToLobbyProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLobbyProcedure);
	LOGGERSYSTEM->LogInfo("LoginProcedure: ChangeToLobbyProcedure\n");
}

void LoginProcedure::ChangeToSelectServerProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pSelServerProcedure);
	LOGGERSYSTEM->LogInfo("LoginProcedure: ChangeToSelectServerProcedure\n");
}

bool  LoginProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("LoginProcedure::Init()")

		_BEGIN_PROF_CHUNK_("LoginProcedure::Load login.plist")
		// 加载相关资源
		_TRACE_LOADING_PLIST_("resource/image/login.plist");
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("LoginProcedure::Show Top&Login Window")
		// 显示UI
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_TOPWINDOW_);
		EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_LOGINWINDOW_);
		//// 显示进度条面板
		//EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_LOADINGWINDOW_);
		_END_PROF_CHUNK_()

		// 播放音效
		_BEGIN_PROF_CHUNK_("LoginProcedure::Play Lobby.mp3")
		SOUNDSYSTEM->PlayBackgroundMusic("resource/media/lobby.mp3");
		_END_PROF_CHUNK_()

		_END_PROF_CHUNK_()

		LOGGERSYSTEM->LogInfo("LoginProcedure: Enter\n");
		return true;
	} 
	while (false);

	return false;
}

void  LoginProcedure::Tick()
{
	// 执行输入处理
	OnInputEventHandler();
}

void  LoginProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("LoginProcedure::Destroy()")

	// 隐藏UI
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_LOGINWINDOW_);

	// 释放无用资源
	_TRACE_UNLOAD_PLIST_("resource/image/login.plist");
	NinjiaTribeApp::get_instance2()->ForceFreeMemory();

	_END_PROF_CHUNK_()

	LOGGERSYSTEM->LogInfo("LoginProcedure: Leave\n");
}

void  LoginProcedure::OnInputEventHandler()
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

void  LoginProcedure::OnSystemEnterBackEventHandler()
{

}

void  LoginProcedure::OnSystemEnterFrontEventHandler()
{

}

void  LoginProcedure::OnSystemPauseEventHandler()
{

}

void  LoginProcedure::OnSystemResumeEventHandler()
{

}
