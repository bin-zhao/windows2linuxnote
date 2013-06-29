#ifndef  _NINJIATRIBE_LOBBYWINDOW_H_
#define  _NINJIATRIBE_LOBBYWINDOW_H_


#include "IWindow.h"

class HeroObject;
class LobbyWindow : public IWindow
{
private:
	std::vector<HeroObject*> m_pLobbyPlayerVector;//LobbyPlayer向量
	int m_pLobbyPlayerIndex;					  //LobbyPlayer索引
public:
	LobbyWindow();
	virtual ~LobbyWindow();
public:
	/*
		创建横排队伍
	*/
	void createPlayerTeam();
	/*
		更新队形
	*/
	void updateLeftMovePlayerTeamShape();
	void updateRightMovePlayerTeamShape();
	/*
		队伍tick
	*/
	void playerTeamTick();
	/*
		按钮事件处理
	*/
	void OnBtnLeftHandler(cocos2d::CCObject* pSender);
	void OnBtnRightHandler(cocos2d::CCObject* pSender);
	void OnBtnBackHandler(cocos2d::CCObject* pSender);
	void OnBtnPlayHandler(cocos2d::CCObject* pSender);
	/*
		play按钮是否使能
	*/
	void setPlayeEnable(bool bl);
	/*
		设置英雄索引字符串
	*/
	void setIndexOfHero();
	/*
		设置英雄名字字符串
	*/
	void setNameString();
	/*
		设置宝石数
	*/
	void setRubyString();
	/*
		设置金币数目
	*/
	void setGoldString();
	/*
		设置英雄杀敌数目
	*/
	void setKillNumString();

public:
	/*
		初始化处理
	*/
	virtual    bool    Init();
	/*
		加载处理
	*/
	virtual    bool    Load();
	/*
		桢更新处理
	*/
	virtual    void    Tick();
	/*
		销毁处理
	*/ 
	virtual    void    Destroy();

public:
	/*
		消息事件响应处理
	*/
	virtual    void    OnEventHandler(int iEventType, std::list<std::string>& paramList);

private:
	/*
		显示大厅面板事件处理
	*/
	void   OnShowWindowEventHandler(std::list<std::string>& paramList);
	/*
		更新面板所有空间名称事件处理
	*/
	void   OnUpdateUITextEventHandler(std::list<std::string>& paramList);
	/*
		更新大厅面板事件处理
	*/
	void   OnUpdateWindowEventHandler(std::list<std::string>& paramList);
	/*
		开始拖拽事件处理
	*/
	void   OnStartDragEventHandler(std::list<std::string>& paramList);
	/*
		拖拽中事件处理
	*/
	void   OnDragingEventHandler(std::list<std::string>& paramList);
	/*
		结束拖拽事件处理
	*/
	void   OnEndDragEventHandler(std::list<std::string>& paramList);
};
#endif
