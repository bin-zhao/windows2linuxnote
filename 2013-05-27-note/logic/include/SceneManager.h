#ifndef  _NINJIATRIBE_SCENEMANAGER_H_
#define  _NINJIATRIBE_SCENEMANAGER_H_


#include <include/common/Singleton.h>
#include "../include/IObject.h"
#include "../include/PlayerObject.h"
#include "../include/DiamondObject.h"
#include "../include/WeaponObject.h"
#include <cocos2d.h>
#include <list>
#include <map>
using  namespace  cobra_win;

class EffectObject;
class SceneManager : public cobra_win::Singleton2<SceneManager>
{
public:
	enum{
		LEFTBOUND = -240,
		RIGHTBOUND = 880,
		UPBOUND = 1040,
		DOWNBOUND = -80,
	};
public:
	struct MonsterListAndTicker
	{
		std::list<PlayerObject*> pMonsterList;//怪物链表
		int frametickCounter;//帧技术
		int changeDirTickCounter;//计算步长
	};
	struct PersonPointerAndPos
	{
		PlayerObject* pPerson;
		cocos2d::CCPoint pos;
	};

	std::list<PlayerObject*> m_pHerosList;//英雄队伍
private:
	std::list<MonsterListAndTicker> m_ppMonsterList;//怪物队伍
	std::list<DiamondObject*> m_pGemsList;//宝石链表
	std::list<PlayerObject*> m_AloneHeroList;//未加入到队伍的英雄链表
	std::list<WeaponObject*> m_pWeaponObjectGoodList;//武器链表(player的武器都存放在这里)
	std::list<WeaponObject*> m_pWeaponObjectBadList; //武器链表(monster的武器都存放在这里)
	std::vector<int> m_heroIndexSave;//用于英雄掉落控制
protected:
	long long m_LogicTickCounter; // 场景逻辑计数器
protected:
	bool      m_bShakeScene;        // 场景震动
	long long m_ShakeSceneBeginTime;// 场景开始震动的时间

protected:
	bool      m_bInverseScene;        // 场景反色
	long long m_InverseSceneBeginTime;// 场景反色开始时间
	cocos2d::ccBlendFunc m_LastInverseBlendFunc;

protected:
	float     m_TickSpeedFactor; // 场景Tick加速比例 
	bool      m_bTickPaused;     // 场景Tick暂停标志位
	bool      m_bGameOver;       // 游戏结束标志位
	
public:
	SceneManager();
	virtual ~SceneManager();
public:
	/*
		设置场景Tick加速比例
	*/
	void  SetTickSpeedFactor(float speed);
	/*
		得到场景Tick加速比例
	*/
	float GetTickSpeedFactor();
	/*
		设置场景暂停标志位
	*/
	void  SetTickPaused(bool bPause);
	/*
		得到场景暂停标志位
	*/
	bool  GetTickPaused();
	/*
		得到GameOver标志位
	*/
	bool getGameOver() const { return m_bGameOver; }
	/*
		设置Gameover标志位
	*/
	void setGameOver(bool val) { m_bGameOver = val; }

public:
	/*
		得到场景跟节点
	*/
	cocos2d::CCNode* GetSceneRootLayer();
	/*
		得到场景背景层根节点
	*/
	cocos2d::CCNode* GetSceneBackgroundLayer();
	/*
		得到场景效果播放层
	*/
	cocos2d::CCNode* GetSceneEffectLayer();
	/*
		得到场景反色层根节点
	*/
	cocos2d::CCNode* GetSceneInverseLayer();

	/*
		得到Lobby的PlayerLayer层
	*/
	cocos2d::CCNode* SceneManager::GetSceneLobbyPlayerLayer();
	cocos2d::CCNode* GetScenePlayerLayer();
public:
	/*
		屏幕反色处理
	*/
	void  InverseScene();
	/*
		振屏操作处理
	*/
	void  ShakeScene();

public:
	/*
		根据动画名称得到CCAnimation
	*/
	cocos2d::CCAnimation* GetAnimtionByName(std::string name);

public:
	/*
		初始化场景管理器
	*/
	bool  Init();
	/*
		场景逻辑桢更新
	*/
	void  Tick();
	/*
		销毁场景管理器
	*/
	void  Destroy();

protected:
	/*
		更新竞技场震屏效果
	*/
	void  UpdateSceneShake();
	/*
		更新竞技场反色效果
	*/
	void  UpdateSceneInverse();
public:
	/*
		创建player对象
	*/
	void createPlayerObject(int subType,cocos2d::CCPoint pt,bool IsLeader,bool bIsTeam,DIRECTION dir);
	void createMonsterObject(int subType,cocos2d::CCPoint pt,bool IsLeader,bool bIsTeam,DIRECTION dir);
	/*
		更新背景层
	*/
	void UpdateBackgroundLayer();
	void UpdateHeroTeamShape();
	void insertIntoHeroList(PlayerObject *pPlayerObject);
	void insertIntoMonsterList(std::list<PlayerObject*> &pMonsterList,PlayerObject* pMonsterObject);
	cocos2d::CCPoint playerLayerPos2bkLayerPos(cocos2d::CCPoint playerLayerPos);
	cocos2d::CCPoint playerLayerPos2bkLayerPos(float playerLayerPosx,float playerLayerPosy);
	cocos2d::CCPoint bkLayerPos2playerLayerPos(cocos2d::CCPoint bkLayerPos);
	cocos2d::CCPoint bkLayerPos2playerLayerPos(float bkLayerPosx,float bkLayerPosy);
	SceneManager::MonsterListAndTicker createMonsterTeam(int num,int *pPlayerTypeBuf,cocos2d::CCPoint ptPos,DIRECTION dir);
	void UpdateMonsterTeamShape(MonsterListAndTicker &MonsterListAndTicker);
	void updateAppMonsterTeamShape();
	void updateHeroAttack();
	void getAllMonsterPos(std::vector<cocos2d::CCPoint> &posVector);
	void getMonsterTeamPos(MonsterListAndTicker &MonsterListAndTicker,std::vector<cocos2d::CCPoint> &posVector);
	void getAllMonsterPosandPointer(std::vector<SceneManager::PersonPointerAndPos> &MonsterVector);
	void getMonsterTeamPosandPointer(MonsterListAndTicker &MonsterListAndTicker,std::vector<SceneManager::PersonPointerAndPos> &MonsterVector);
	void updateMonsterKilled();
	void createGemObject(int subType,cocos2d::CCPoint pt);
	void updateCollisionGem2Heros();
	void inGemsScope(cocos2d::CCPoint atBkLayerpt);
	void createAloneHero(int subType,cocos2d::CCPoint pt);
	void updateCollisionAloneHero2HeroTeam();
	int inAloneHeroScope(cocos2d::CCPoint atBkLayerpt);
	DIRECTION changeMonsterTeamDirction(cocos2d::CCPoint leaderPtAtBkLayer,DIRECTION dir);
	bool targetPosHaveMonster(cocos2d::CCPoint pos);
	bool targettPosIsBound(cocos2d::CCPoint pos);
	cocos2d::CCPoint getDstPos(const cocos2d::CCPoint leaderPtAtBkLayer,DIRECTION dir);
	DIRECTION getrandDirectTion(DIRECTION orgdir);
	void updateCollisionHero2Bound();
	void updateCollisionWeapon2Monster();
	void createWeapon(int subType,cocos2d::CCPoint birthPt,cocos2d::CCPoint dstPt);
	void updateAllMonstersAttack();
	void UpdateMonsterTeamAttack(MonsterListAndTicker &MonsterListAndTicker);
	void getAllHeroPosandPointer(std::vector<SceneManager::PersonPointerAndPos> &allHerosVector);
	void updateCollisionWeapon2Heros();
	void updateAllWeaponKilled();
	void allHerosSlowDown();
	void gameOver();
	void updateCollisionHero2Monster();
	void updateHeroKilled();
	void FlushMonsters();
	bool findAndRemove(int n);
	void initDropHeroIndexVector();
	int reserveHeros();
	int getHeroIndexVal(int index);
public:
	friend  class  cobra_win::Singleton2<SceneManager>;
};

#define  SCENEMANAGER  (SceneManager::get_instance2())


#endif
