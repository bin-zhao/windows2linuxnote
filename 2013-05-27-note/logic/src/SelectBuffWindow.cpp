#include "../include/HeroObject.h"
#include "../include/SelectBuffWindow.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/VariableSystem.h"
#include "../include/LobbyProcedure.h"
#include "../include/LocalPlayerDataManager.h"
#include <include/UILoaderSystem.h>
#include <include/UIWindowManager.h>
#include <cocos2d.h>
using  namespace  uiloader;
using  namespace  cocos2d;


SelectBuffWindow::SelectBuffWindow():m_pLobbyPlayerIndex(0)
{
	m_WindowType = _TYPED_WINDOW_SELECTBUFF_;
}

SelectBuffWindow::~SelectBuffWindow()
{

}

bool SelectBuffWindow::Init()
{
	RegisterEvent(_TYPED_EVENT_SHOW_SELECTBUFFWINDOW_);
	RegisterEvent(_TYPED_EVENT_HIDE_SELECTBUFFWINDOW_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_UI_TEXT_, true);
	RegisterEvent(_TYPED_EVENT_UPDATE_SELECTBUFFWINDOW_, true);
	return IWindow::Init();
}

bool SelectBuffWindow::Load()
{
	do 
	{
		if (!IWindow::Load())
			break;
		cocos2d::CCMenuItemImage* pMenuItem;	//按钮事件挂接
		pMenuItem= (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("buff/play");
		pMenuItem->setTarget(this,menu_selector(SelectBuffWindow::OnBtnPlayHandler));
		
		//createPlayerTeam();						//创建队伍

		//cocos2d::CCMenuItemImage* pMenuItem;	//按钮事件挂接
		//pMenuItem= (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("lobby/left");
		//pMenuItem->setTarget(this,menu_selector(SelectBuffWindow::OnBtnLeftHandler));
		//pMenuItem = (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("lobby/right");
		//pMenuItem->setTarget(this,menu_selector(SelectBuffWindow::OnBtnRightHandler));
		//pMenuItem = (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("lobby/play");
		//pMenuItem->setTarget(this,menu_selector(SelectBuffWindow::OnBtnPlayHandler));
		//pMenuItem = (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("lobby/back");
		//pMenuItem->setTarget(this,menu_selector(SelectBuffWindow::OnBtnBackHandler));

		//setIndexOfHero();
		//setNameString();
		//setRubyString();							
		//setGoldString();
		//setKillNumString();
		//往localPlayer填写数据(初始化时使用)
		//int n = LocalPlayerDataManager::get_instance2()->GetLocalCurrentPlayerId();
		//LocalPlayerDataManager::get_instance2()->SetLocalCurrentPlayerId(3);
		//n = LocalPlayerDataManager::get_instance2()->GetLocalCurrentPlayerId();
		//LocalPlayerDataManager::get_instance2()->SetHeroState_Active(0,true);
		//LocalPlayerDataManager::get_instance2()->SetHeroState_Active(1,true);
		//LocalPlayerDataManager::get_instance2()->SetHeroState_Active(2,true);



		return true;
	} 
	while (false);

	return false;
}

void SelectBuffWindow::Tick()
{
	IWindow::Tick();
	//playerTeamTick();
}

void SelectBuffWindow::Destroy()
{
	std::vector<HeroObject*>::iterator iter = m_pLobbyPlayerVector.begin();
	std::vector<HeroObject*>::iterator iter_e = m_pLobbyPlayerVector.end();
	for(;iter!=iter_e;iter++)
	{
		(*iter)->Destroy();
		delete *iter;
	}
	m_pLobbyPlayerVector.clear();
	IWindow::Destroy();
}

void SelectBuffWindow::OnEventHandler(int iEventType, std::list<std::string>& paramList)
{
	if (iEventType == _TYPED_EVENT_SHOW_SELECTBUFFWINDOW_)
	{
		OnShowWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_HIDE_SELECTBUFFWINDOW_)
	{
		Destroy();
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_SELECTBUFFWINDOW_)
	{
		OnUpdateWindowEventHandler(paramList);
	}
	else if (iEventType == _TYPED_EVENT_UPDATE_UI_TEXT_)
	{
		OnUpdateUITextEventHandler(paramList);
	}
}

void SelectBuffWindow::OnShowWindowEventHandler(std::list<std::string>& paramList)
{
	Show(true);
}

void SelectBuffWindow::OnUpdateUITextEventHandler(std::list<std::string>& paramList)
{

}

void SelectBuffWindow::OnUpdateWindowEventHandler(std::list<std::string>& paramList)
{
	
}

void SelectBuffWindow::OnStartDragEventHandler(std::list<std::string>& paramList)
{

}

void SelectBuffWindow::OnDragingEventHandler(std::list<std::string>& paramList)
{

}

void SelectBuffWindow::OnEndDragEventHandler(std::list<std::string>& paramList)
{

}

void SelectBuffWindow::updateLeftMovePlayerTeamShape()
{
	int totalHeroNums = 0;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_,"SYS","TotalHeroNums",totalHeroNums);
	//当前英雄停止动画
	m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->stopAnimation();
	//索引左移
	m_pLobbyPlayerIndex--;
	if(m_pLobbyPlayerIndex<0)
	{
		m_pLobbyPlayerIndex = totalHeroNums - 1;
	}
	//调整位置和缩放
	for(int i =0;i<totalHeroNums;i++)
	{
		m_pLobbyPlayerVector.at(i)->SetXPos((i-m_pLobbyPlayerIndex)*103.0f);
		if(i!=m_pLobbyPlayerIndex)
		{
			m_pLobbyPlayerVector.at(i)->setScale(0.5f);
		}
	}
	//播放动画和设置中间位置英雄缩放
	if(m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->m_isActive)
	m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->playAnimation();
	m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->setScale(1.0f);
}

void SelectBuffWindow::updateRightMovePlayerTeamShape()
{
	int totalHeroNums = 0;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_,"SYS","TotalHeroNums",totalHeroNums);
	//当前英雄停止动画
	m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->stopAnimation();
	//索引左移
	m_pLobbyPlayerIndex++;
	if(m_pLobbyPlayerIndex>(totalHeroNums-1))
	{
		m_pLobbyPlayerIndex = 0;
	}
	//调整位置和缩放
	for(int i =0;i<totalHeroNums;i++)
	{
		m_pLobbyPlayerVector.at(i)->SetXPos((i-m_pLobbyPlayerIndex)*103.0f);
		if(i!=m_pLobbyPlayerIndex)
		{
			m_pLobbyPlayerVector.at(i)->setScale(0.5f);
		}
	}
	//播放动画和设置中间位置英雄缩放
	if(m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->m_isActive)
	m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->playAnimation();
	m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->setScale(1.0f);
}

void SelectBuffWindow::createPlayerTeam()
{
	int totalHeroNums = 0;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_,"SYS","TotalHeroNums",totalHeroNums);
	//创建英雄
	for(int i=0;i<totalHeroNums;i++)
	{
		HeroObject* t = HeroObject::create(i,ccp((i-m_pLobbyPlayerIndex)*103,0));
		m_pLobbyPlayerVector.push_back(t);
	}
	//更新队形显示
	for(int i=0;i<totalHeroNums;i++)
	{
		if(i!=m_pLobbyPlayerIndex)
		{
			m_pLobbyPlayerVector.at(i)->setScale(0.5f);
		}
		else
		{
			m_pLobbyPlayerVector.at(i)->playAnimation();
		}
	}
}
void SelectBuffWindow::playerTeamTick()
{
	int totalHeroNums = 0;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_,"SYS","TotalHeroNums",totalHeroNums);
	for(int i=0;i<totalHeroNums;i++)
	{
		m_pLobbyPlayerVector.at(i)->RenderTick();
	}
}

void SelectBuffWindow::setPlayeEnable(bool bl)
{
	cocos2d::CCMenuItemImage* pMenuItem;	//按钮事件挂接
	pMenuItem = (cocos2d::CCMenuItemImage*)UIWindowManager::get_instance()->GetUIWindow("lobby/play");
	pMenuItem->setEnabled(bl);
}

void SelectBuffWindow::OnBtnLeftHandler(cocos2d::CCObject* pSender)
{
	updateLeftMovePlayerTeamShape();
	if(m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->m_isActive)
		setPlayeEnable(true);
	else
		setPlayeEnable(false);
	setIndexOfHero();
	setNameString();
	setRubyString();
	setKillNumString();
}

void SelectBuffWindow::OnBtnRightHandler(cocos2d::CCObject* pSender)
{
	updateRightMovePlayerTeamShape();
	if(m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->m_isActive)
		setPlayeEnable(true);
	else
		setPlayeEnable(false);
	setIndexOfHero();
	setNameString();
	setRubyString();
	setKillNumString();
}

void SelectBuffWindow::OnBtnPlayHandler(cocos2d::CCObject* pSender)
{
	NinjiaTribeApp::get_instance2()->m_pLobbyProcedure->ChangeToArenaProcedure();
	//向下一个窗口传递英雄索引
	//VARIABLESYSTEM->SetVariable(VariableSystem::_TYPED_CONFIG_MEM_,"PLAYERINDEX",m_pLobbyPlayerIndex);
}

void SelectBuffWindow::OnBtnBackHandler(cocos2d::CCObject* pSender)
{
	NinjiaTribeApp::get_instance2()->m_pLobbyProcedure->ChangeToLoginProcedure();
}


void SelectBuffWindow::setIndexOfHero()
{
	int totalHeroNums = 0;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_,"SYS","TotalHeroNums",totalHeroNums);
	char buffer[128] = "";
	::sprintf(buffer,"%d of %d",m_pLobbyPlayerIndex+1,totalHeroNums);
	((cocos2d::CCLabelTTF*)UIWindowManager::get_instance()->GetUIWindow("lobby/indexofhero"))->setString(buffer);
}

void SelectBuffWindow::setNameString()
{
	((cocos2d::CCLabelTTF*)UIWindowManager::get_instance()->GetUIWindow("lobby/heroname"))->setString(m_pLobbyPlayerVector.at(m_pLobbyPlayerIndex)->getHeroName().c_str());
}

void SelectBuffWindow::setRubyString()
{
	char buffer[128] = "";
	::sprintf(buffer,"%d",LocalPlayerDataManager::get_instance2()->getRubyNum());
	((cocos2d::CCLabelTTF*)UIWindowManager::get_instance()->GetUIWindow("lobby/rubytotalnum"))->setString(buffer);
}

void SelectBuffWindow::setGoldString()
{
	char buffer[128] = "";
	::sprintf(buffer,"%d",LocalPlayerDataManager::get_instance2()->getGlodNum());
	((cocos2d::CCLabelTTF*)UIWindowManager::get_instance()->GetUIWindow("lobby/goldtotalnum"))->setString(buffer);
}

void SelectBuffWindow::setKillNumString()
{
	char buffer[128] = "";
	::sprintf(buffer,"%d",LocalPlayerDataManager::get_instance2()->GetLocalHeroStateByPos(m_pLobbyPlayerIndex)->m_KillNum);
	((cocos2d::CCLabelTTF*)UIWindowManager::get_instance()->GetUIWindow("lobby/killnum"))->setString(buffer);
}
