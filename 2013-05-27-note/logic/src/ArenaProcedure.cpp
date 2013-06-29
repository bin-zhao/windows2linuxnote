#include "../include/ArenaProcedure.h"
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
#include "../include/InputCommand.h"
#include "../include/SoundSystem.h"
#include "../include/UISystem.h"
#include "../include/ObjectManager.h"
#include "../include/SceneManager.h"
#include "../include/LocalPlayerDataManager.h"
#include <list>


ArenaProcedure::ArenaProcedure()
{
	m_Type    = _TYPED_ARENA_PROCEDURE_;
	m_SubType = _TYPED_ARENAPROCEDURE_UNKOWN_;
	m_bInputEnabled = false;

	m_LogicTickCounter = 0;
}

ArenaProcedure::~ArenaProcedure()
{

}

int ArenaProcedure::GetSubType()
{
	return m_SubType;
}

void ArenaProcedure::ChangeToLobbyProcedure()
{
	// 切换流程
	NinjiaTribeApp::get_instance2()->SetActiveProcedure(NinjiaTribeApp::get_instance2()->m_pLobbyProcedure);
	LOGGERSYSTEM->LogInfo("ArenaProcedure: ChangeToLobbyProcedure\n");
}

void ArenaProcedure::StartCoolDown()
{
	m_SubType = _TYPED_ARENAPROCEDURE_COOLDOWN_;
	SOUNDSYSTEM->PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_OTHER_, "resource/media/cooldown.mp3", false);
	LOGGERSYSTEM->LogInfo("ArenaProcedure: StartCoolDown()\n");
}

void ArenaProcedure::StartGame()
{
	m_SubType = _TYPED_ARENAPROCEDURE_GAMING_;

	m_LogicTickCounter = 0;
	LOGGERSYSTEM->LogInfo("ArenaProcedure: StartGame()\n");
}

void ArenaProcedure::EndGame(bool bWin)
{
	if (!bWin)
		SOUNDSYSTEM->PlayLoseEffect();
	else
		SOUNDSYSTEM->PlayWinEffect();

	// 设置当前竞技场状态
	m_SubType = _TYPED_ARENAPROCEDURE_END_;

	EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_ARENARESULTWINDOW_, _to_event_param_(bWin));
	LOGGERSYSTEM->LogInfo("ArenaProcedure: EndGame()\n");
}

void ArenaProcedure::PauseGame()
{
	if (m_SubType == _TYPED_ARENAPROCEDURE_PAUSE_)
		return;

	if (m_SubType != _TYPED_ARENAPROCEDURE_GAMING_)
		return;

	// 设置当前竞技场状态
	m_SubType = _TYPED_ARENAPROCEDURE_PAUSE_;
	// 显示暂停面板
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_SHOW_PAUSEWINDOW_);
	LOGGERSYSTEM->LogInfo("ArenaProcedure: PauseGame()\n");
}

void ArenaProcedure::ResumeGame()
{
	// 设置当前竞技场状态
	m_SubType = _TYPED_ARENAPROCEDURE_GAMING_;
	// 隐藏暂停面板
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_PAUSEWINDOW_);
	LOGGERSYSTEM->LogInfo("ArenaProcedure: ResumeGame()\n");
}

void ArenaProcedure::ReplayGame()
{
	LOGGERSYSTEM->LogInfo("ArenaProcedure: ReplayGame()\n");

	m_bInputEnabled = false;
	m_LogicTickCounter = 0;

	// 释放并销毁场景管理器
	if (SCENEMANAGER != NULL)
	{
		SCENEMANAGER->Destroy();
		delete SCENEMANAGER;
	}

	// 创建并初始化场景管理器
	new SceneManager;
	SCENEMANAGER->Init();

	// 开始游戏
	StartCoolDown();
}

bool  ArenaProcedure::Init()
{
	do 
	{
		_BEGIN_PROF_CHUNK_("ArenaProcedure::Init()")

		// 设置当前竞技场状态
		m_bInputEnabled = false;
		m_LogicTickCounter = 0;

		_BEGIN_PROF_CHUNK_("ArenaProcedure::Init SceneManager")
		// 创建并初始化场景管理器
		new SceneManager;
		SCENEMANAGER->Init();
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("ArenaProcedure::Start Cool Down")
		// 开始游戏
		//StartCoolDown();
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("ArenaProcedure::Play Arena.mp3")
		// 播放音效
		SOUNDSYSTEM->PlayBackgroundMusic("resource/media/background.mp3");
		_END_PROF_CHUNK_()

		_END_PROF_CHUNK_()
		LOGGERSYSTEM->LogInfo("ArenaProcedure: Enter\n");
		return true;
	} 
	while (false);

	return false;
}

void  ArenaProcedure::Tick()
{
	if (GetSubType() == _TYPED_ARENAPROCEDURE_END_)
		return;

	// 执行输入处理
	OnInputEventHandler();
	if (GetSubType() == _TYPED_ARENAPROCEDURE_COOLDOWN_)
	{
		m_LogicTickCounter++;
		return;
	}

	if (GetSubType() == _TYPED_ARENAPROCEDURE_PAUSE_)
		return;

	m_LogicTickCounter++;
	SCENEMANAGER->Tick();
}

void  ArenaProcedure::Destroy()
{
	_BEGIN_PROF_CHUNK_("ArenaProcedure::Destroy()")

	_BEGIN_PROF_CHUNK_("ArenaProcedure::Destroy SceneManager()")
	// 释放并销毁场景管理器
	if (SCENEMANAGER != NULL)
	{
		SCENEMANAGER->Destroy();
		delete SCENEMANAGER;
	}
	_END_PROF_CHUNK_()

	// 停止所有动画
	cocos2d::CCAnimationCache::purgeSharedAnimationCache();

	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_GAMEOVERWINDOW_);
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_HIDE_ARENAWINDOW_);

	_BEGIN_PROF_CHUNK_("ArenaProcedure::Stop Arena.mp3")
	// 停止背景音乐
	SOUNDSYSTEM->StopBackgroundMusic();
	_END_PROF_CHUNK_()

	_BEGIN_PROF_CHUNK_("ArenaProcedure::ForceFreeMemory")
	NinjiaTribeApp::get_instance2()->ForceFreeMemory();
	_END_PROF_CHUNK_()

	_END_PROF_CHUNK_()
	LOGGERSYSTEM->LogInfo("ArenaProcedure: Leave\n");
}

void  ArenaProcedure::OnInputEventHandler()
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
				if(m_SubType != _TYPED_ARENAPROCEDURE_PAUSE_ && m_SubType!= _TYPED_ARENAPROCEDURE_END_)
				{
					m_bInputEnabled = true;
					ptTouchBegin.x = inputEvent.mXPos;
					ptTouchBegin.y = inputEvent.mYPos;
				}
			}
			break;
		case _TYPED_INPUT_EVENT_TOUCHMOVE_:
			{
				;
			}
			break;
		case _TYPED_INPUT_EVENT_TOUCHEND_:
			{
				m_bInputEnabled = false;
				ptTouchEnd.x = inputEvent.mXPos;
				ptTouchEnd.y = inputEvent.mYPos;

				if(SCENEMANAGER->m_pHerosList.empty())
					return;
				
				//获取当前英雄朝向
				DIRECTION leaderDir = SCENEMANAGER->m_pHerosList.front()->m_Dir;
				//判断方向,并放入缓冲区
				float xLen = ::abs(ptTouchEnd.x - ptTouchBegin.x);
				float yLen = ::abs(ptTouchEnd.y - ptTouchBegin.y);
				if(xLen>yLen)//lr
				{
					if(ptTouchEnd.x > ptTouchBegin.x)
					{
						if(DIR_LEFT!=leaderDir)
						{
							dirQueue.push(DIR_RIGHT);
						}
						
					}
					else
					{
						if(DIR_RIGHT!=leaderDir)
						{
							dirQueue.push(DIR_LEFT);
						}
					}
				}
				else
				{
					if(ptTouchEnd.y > ptTouchBegin.y)
					{
						if(DIR_DOWN != leaderDir)
						{
							dirQueue.push(DIR_UP);
						}
					}
					else
					{
						if(DIR_UP != leaderDir)
						{
							dirQueue.push(DIR_DOWN);
						}
					}
				}


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

void  ArenaProcedure::OnSystemEnterBackEventHandler()
{
	if (m_SubType!=_TYPED_ARENAPROCEDURE_PAUSE_ && m_SubType!=_TYPED_ARENAPROCEDURE_END_)
	{
		m_bInputEnabled = false;
	}

	PauseGame();
}

void  ArenaProcedure::OnSystemEnterFrontEventHandler()
{

}

void  ArenaProcedure::OnSystemPauseEventHandler()
{
	if (m_SubType!=_TYPED_ARENAPROCEDURE_PAUSE_ && m_SubType!=_TYPED_ARENAPROCEDURE_END_)
	{
		m_bInputEnabled = false;
	}

	PauseGame();
}

void  ArenaProcedure::OnSystemResumeEventHandler()
{

}
