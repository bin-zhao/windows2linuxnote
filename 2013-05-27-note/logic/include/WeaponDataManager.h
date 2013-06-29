#ifndef  _NINJIATRIBE_WEAPONDATAMANGER_H_
#define  _NINJIATRIBE_WEAPONDATAMANGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <map>

#pragma pack(push, 1)
class WeaponData : public IData
{
public:
	int   m_WeaponId;                // 武器Id
    float m_attackScope;             // 武器的攻击范围
    float m_Speed;                   // 武器移动速度
    float m_AttackDamage;            // 武器攻击力
    bool  m_bHasSpreedAbility;       // 是否具备溅射能力
    float m_AddAttackRadius;         // 溅射半径
    char  m_AvatarResourceName[128]; // 武器图片名称
    char  m_EffectName[128];         // 武器特效名称
	bool  m_isGood;
public:
	WeaponData();
	virtual ~WeaponData();
public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class WeaponDataManager : public IDataManager, public cobra_win::Singleton2<WeaponDataManager>
{
private:
	std::map<int, WeaponData*> m_WeaponList;

public:
	WeaponDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~WeaponDataManager();

public:
	/*
		获得指定Id的主角对象
	*/
	WeaponData* GetWeaponById(int playerId);

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
	friend   class   cobra_win::Singleton2<WeaponDataManager>;
};


#endif
