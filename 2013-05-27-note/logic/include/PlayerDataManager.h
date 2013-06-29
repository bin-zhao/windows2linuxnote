#ifndef  _NINJIATRIBE_PLAYERDATAMANAGER_H_
#define  _NINJIATRIBE_PLAYERDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <map>

#pragma pack(push, 1)
class PlayerData : public IData
{
public:
	int   m_PlayerId;        // 英雄Id
    char  m_PlayerName[128]; // 英雄名字
    int   m_WeaponType;      // 武器类型，0近程，1远程
    int   m_WeaponId;        // 武器ID
    int   m_AttackAngle;     // 攻击角度0～180
	int   m_AttackDistence;  // 攻击距离
    float m_AttackAbility;   // 攻击力
    int   m_DefenceAbility;  // 防御能力
    float   m_MaxHp;           // 初始血量
    float   m_Speed;           // 初始速度
    float   m_Width;           // 英雄宽度
    float   m_Height;          // 英雄高度
    float   m_CollisionWidth;  // 碰撞检测宽度
    float   m_CollisionHeight; // 碰撞检测高度
    int   m_AttackInterVal;  // 攻击间隔时间
    char   m_RunUpActionName[128];    //向上运动动画
    char   m_RunDownActionName[128];  //向下运动动画
    char   m_RunLeftActionName[128];  //向左运动动画
    char   m_RunRightActionName[128]; //向右运动动画
	char   m_LobbyDownActionNmae[128]; //Lobby向下运动动画
	char   m_BuffRightActionNmae[128]; //Buff向右运动动画
    char   m_AttackSoundName[128];    //攻击音效
    char   m_DeadSoundName[128];      //死亡音效

public:
	PlayerData();
	virtual ~PlayerData();

public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class PlayerDataManager : public IDataManager, public cobra_win::Singleton2<PlayerDataManager>
{
private:
	std::map<int, PlayerData*> m_PlayerList;

public:
	PlayerDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~PlayerDataManager();

public:
	/*
		获得指定Id的主角对象
	*/
	PlayerData* GetPlayerById(int playerId);

public:
	/*
		得到对应的数据管理器名称
	*/
	virtual  std::string   GetName();
	/*
		得到对应的数据管理器内存占用大小
	*/
	virtual  unsigned  int GetSize();

public:
	/*
		初始化数据管理器
	*/
	virtual  bool  Init();
	/*
		数据管理器帧更新处理
	*/
	virtual  void  Tick();
	/*
		销毁数据管理器
	*/
	virtual  void  Destroy();

public:
	/*
		校验加载的数据(单行数据的有效性校验)
	*/
	virtual  bool  Varify(IData* pData);
	/*
		校验加载的数据(所有数据加载完之后进行的表与表关联性校验)
	*/
	virtual  bool  VarifyAfterLoadAll();

protected:
	/*
		创建指定的ItemData数据
	*/
	virtual  bool  LoadData(char* pBuffer, unsigned int iBufferLen);

private:
	friend   class   cobra_win::Singleton2<PlayerDataManager>;
};


#endif
