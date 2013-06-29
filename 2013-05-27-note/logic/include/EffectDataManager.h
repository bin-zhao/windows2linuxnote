#ifndef  _NINJIATRIBE_EFFECTDATAMANAGER_H_
#define  _NINJIATRIBE_EFFECTDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <string>
#include <map>

#pragma pack(push, 1)
class EffectItemData : public IData
{
public:
	int   mEffectType;                // 特效类型
	char  mEffectIdleAvatarName[128]; // 特效空闲动作名称
	bool  mEffectFadeout;             // 特效是否渐隐
	char  mEffectSoundName[128];      // 特效音效名称

public:
	EffectItemData();
	virtual ~EffectItemData();

public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class EffectDataManager : public IDataManager, public cobra_win::Singleton2<EffectDataManager>
{
public:
	std::map<int, EffectItemData*> m_EffectList;

public:
	EffectDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~EffectDataManager();

public:
	/*
		根据特效类型得到指定的信息
	*/
	EffectItemData* GetEffectByType(int type);

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
	friend   class   cobra_win::Singleton2<EffectDataManager>;
};


#endif
