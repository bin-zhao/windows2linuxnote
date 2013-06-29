#include "../include/PlayerBehaviorSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/VariableSystem.h"
#include <cocos2d.h>


template<> PlayerBehaviorSystem* cobra_win::Singleton2<PlayerBehaviorSystem>::m_pMySelf = NULL;

PlayerBehaviorSystem::PlayerBehaviorSystem()
{

}

PlayerBehaviorSystem::~PlayerBehaviorSystem()
{

}

void PlayerBehaviorSystem::BeginPlayerBehaviorEvent(std::string text)
{
	cocos2d::CCDirector::sharedDirector()->getPlayerBehaviorTrace()->beginEvent(text);
}

void PlayerBehaviorSystem::EndPlayerBehaviorEvent(std::string text)
{
	cocos2d::CCDirector::sharedDirector()->getPlayerBehaviorTrace()->endEvent(text);
}

void PlayerBehaviorSystem::LogPlayerBehaviorEvent(std::string text)
{
	cocos2d::CCDirector::sharedDirector()->getPlayerBehaviorTrace()->logEvent(text);
}

void PlayerBehaviorSystem::LogPlayerBehaviorEvent(std::string text, std::string label)
{
	cocos2d::CCDirector::sharedDirector()->getPlayerBehaviorTrace()->logEvent(text, label);
}

bool PlayerBehaviorSystem::Init()
{
	LOGGERSYSTEM->LogInfo("Init PlayerBehaviorSystem Success\n");
	return true;
}

void PlayerBehaviorSystem::Tick()
{

}

void PlayerBehaviorSystem::Destroy()
{
	LOGGERSYSTEM->LogInfo("Destroy PlayerBehaviorSystem Success\n");
}
