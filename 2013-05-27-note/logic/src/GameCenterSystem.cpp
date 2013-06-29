#include "../include/GameCenterSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/VariableSystem.h"


template<> GameCenterSystem* cobra_win::Singleton2<GameCenterSystem>::m_pMySelf = NULL;

GameCenterSystem::GameCenterSystem()
{

}

GameCenterSystem::~GameCenterSystem()
{

}

bool GameCenterSystem::Init()
{
	do
	{
		LOGGERSYSTEM->LogInfo("Init GameCenterSystem Success\n");
	}
	while (false);

	return true;
}

void GameCenterSystem::Tick()
{

}

void GameCenterSystem::Destroy()
{
	LOGGERSYSTEM->LogInfo("Destroy GameCenterSystem Success\n");
}
