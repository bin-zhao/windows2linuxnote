#ifndef  _NINJIATRIBE_LOCALPLAYERDATAMANAGER_H_
#define  _NINJIATRIBE_LOCALPLAYERDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <map>
#include <list>
using  namespace  cobra_win;

class LocalPlayerDataManager : public IDataManager, public cobra_win::Singleton2<LocalPlayerDataManager>
{


protected:
	bool  m_bNeedSaveToDisk; // 存盘标志位

protected:
	long long m_PlayerLastLogoutTime; // 上一次登出时的时间
protected:
	int  m_LocalCurrentPlayerId;	  //  玩家选择的英雄人物ID
	int  m_LocalRubyNum;			  //  玩家宝石数目
	int  m_LocalGoldNum;			  //  玩家金币数目
public:
	#pragma pack(1)					  //  让编译器对这个结构作1字节对齐
	struct _LOCAL_HERO_STATE_		  //  英雄状态存储
	{
		bool m_isActive;			  //  是否被激活
		int  m_Rank;				  //  英雄等级
		long m_KillNum;				  //  杀敌数目
		_LOCAL_HERO_STATE_()
		{
			memset(this,0,sizeof(_LOCAL_HERO_STATE_));
		}
	};
	#pragma pack()					  //取消1字节对齐，恢复为默认4字节对齐
protected:
	std::list<_LOCAL_HERO_STATE_> m_LocalHeroStateList;//英雄状态列表
public:
	LocalPlayerDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~LocalPlayerDataManager();
public:
	/*
		设置激活状态
	*/
	void SetHeroState_Active(int pos,bool isActive);
	/*
		通过pos获取英雄状态
	*/
	LocalPlayerDataManager::_LOCAL_HERO_STATE_* GetLocalHeroStateByPos(unsigned int pos);
	/*
		设置用户选择的玩家ID
	*/
	void SetLocalCurrentPlayerId (int playerId);
	/*
		获取用户选择的玩家ID
	*/
	int GetLocalCurrentPlayerId ();
	/*
		获取用户状态数量
	*/
	unsigned int GetLocalHeroStateNumber();
	/*
		获取用户宝石数目
	*/
	int getRubyNum();
	/*
		获取用户金币数目
	*/
	int getGlodNum();

public:
	/*
		设置需要存盘
	*/
	void  NeedSaveToDisk();

public:
    /*
        获得对应数据管理器对应资源的名称（可为文件，也可以为数据库表名称）
    */
    virtual   std::string  GetName();
	/*
        获得对应数据管理器对应资源的名称（可为文件，也可以为数据库表名称）
    */
    virtual   std::string  GetTempName();
	/*
		得到对应的数据管理器内存占用大小
	*/
	virtual   unsigned int GetSize();
    
public:
	/*
        初始化数据管理器
    */
	virtual   bool   Init();
	/*
        数据管理器桢更新
    */
	virtual   void   Tick();
	/*
        销毁数据管理器
    */
	virtual   void   Destroy();
    
private:
    /*
        加载对应的资源文件
    */
    virtual   bool   LoadFromFile();
    /*
        加载对应的资源流信息
    */
    virtual   bool   LoadFromDB();

public:
	/*
		校验加载的数据(单行数据的有效性校验)
	*/
	virtual   bool   Varify(IData* pData);
	/*
		校验加载的数据(所有数据加载完之后进行的表与表关联性校验)
	*/ 
	virtual   bool   VarifyAfterLoadAll();

protected:
	/*
		创建指定的ItemData数据
	*/
	virtual   bool   LoadData(char* pBuffer, unsigned int iBufferLen);

public:
	/*
		系统进入后台事件响应处理
	*/
	void  OnSystemEnterBackEventHandler();
	/*
		系统进入前台事件响应处理
	*/
	void  OnSystemEnterFrontEventHandler();
	/*
		系统暂停事件响应处理
	*/
	void  OnSystemPauseEventHandler();
	/*
		系统恢复事件响应处理
	*/
	void  OnSystemResumeEventHandler();

private:
	/*
		加载文件
	*/
	char* LoadDBFile(std::string fileName, long& length);
	/*
		同步保存
	*/
	void  SaveToFile();
	/*
		同步到初始状态(一般文件校验失败，则直接设置为初始状态)
	*/
	void  SynToInitialization();

private:
	/*
		加载1.0.1版本的存档文件
	*/
	bool  Load101VersionFile(char* pBuffer, unsigned int iBufferLen);
    
private:
	friend   class   Singleton2<LocalPlayerDataManager>;
};



#endif
