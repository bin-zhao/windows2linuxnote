#ifndef  _NINJIATRIBE_ITEMDATAMANAGER_H_
#define  _NINJIATRIBE_ITEMDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <string>
#include <map>

#pragma pack(push, 1)
class ItemData : public IData
{
public:
	int   mItemType;               // 道具类型
	float mItemWidth;              // 道具宽度
	float mItemHeight;             // 道具高度
	float mItemCollisionWidth;     // 道具参与碰撞检测的宽度
	float mItemCollisionHeight;    // 道具参与碰撞检测的高度
	char  mItemAvatarName[64];     // 道具Avatar名称
	int   mItemAvatarNumber;       // 道具Avatar个数
	float mItemAvatarPlayInterval; // 道具Avatar播放间隔
	char  mItemSoundName[64];      // 道具音效名称
	int   mItemEffectType;         // 道具播放的特效类型(-1表示无特效)
	float mItemInitYSpeed;         // 道具初始化的Y轴速度
	float mItemInitMinXSpeed;      // 道具X轴最小速度
	float mItemInitMaxXSpeed;      // 道具X轴最大速度
	float mItemXReduceFactor;      // 道具X轴移动衰减系数
	float mItemYUpReduceFactor;    // 道具Y轴上升衰减系数
	float mItemYDownReduceFactor;  // 道具Y轴下降衰减系数
	int   mItemParticleId;         // 道具粒子特效Id
	int   mItemAwardScore;         // 道具奖励分数数目
	int   mItemAwardGold;          // 道具奖励金币数目
	bool  mItemCanBeMegneted;      // 道具是否可以被吸附
	float mItemDropRotation;       // 道具掉落的旋转角度

public:
	ItemData();
	virtual ~ItemData();

public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class ItemDataManager : public IDataManager, public cobra_win::Singleton2<ItemDataManager>
{
public:
	std::map<int, ItemData*> m_ItemList;

public:
	ItemDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~ItemDataManager();

public:
	/*
		根据道具类型得到指定的信息
	*/
	ItemData* GetItemByType(int type);

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
	friend   class   cobra_win::Singleton2<ItemDataManager>;
};


#endif
