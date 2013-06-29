#ifndef  _NINJIATRIBE_DBSYSTEM_H_
#define  _NINJIATRIBE_DBSYSTEM_H_


#include <include/common/Singleton.h>
#include <include/sqlite3.h>
#include <string>
#include <list>
#include <map>
using  namespace  cobra_win;

class IDataManager;
class UILayoutDataManager;
class DBSystem : public cobra_win::Singleton2<DBSystem>
{
private:
	sqlite3* m_pSQLite;

private:
	std::list<IDataManager*> m_DataManagerList;
	std::map<int, UILayoutDataManager*> m_UILayoutDataManagerList;

public:
	DBSystem();
	virtual ~DBSystem();

public:
	/*
		得到DB总体内存占用大小
	*/
	int         GetDBSize();
	/*
		得到SQLite数据库对象
	*/
	sqlite3*    GetSQLite();
	/*
		是否需要数据校验
	*/
	bool        IsNeedVerify();
	/*
		得到数据文件加密的KEY
	*/
	std::string GetEncryptionKey();
	/*
		得到玩家本地存档文件加密KEY
	*/
	std::string GetLocalDataEncryptionKey();
	/*
		得到指定UI窗口类型的UI局部数据管理器
	*/
	UILayoutDataManager* GetUILayoutDataManagerByType(int type);

public:
	/*
		初始化数据管理系统
	*/
	bool   Init();
	/*
		数据管理系统帧更新
	*/
	void   Tick();
	/*
		销毁数据管理系统
	*/
	void   Destroy();

private:
	/*
		注册数据管理器
	*/
	void   RegisterDataManager(IDataManager* pDataManager);
	/*
		注册UI窗口布局的数据管理器
	*/
	void   RegisterUILayoutDataManager(UILayoutDataManager* pDataManager);
	/*
		加载指定的SQLite文件
	*/
	bool   LoadDBFile();

public:
	/*
		加密解密操作
	*/
	static  char*  XORBuffer(char* pKey, char* pBuffer, unsigned int iBufferLen);
	/*
		加载指定的数据库表
	*/
	static  bool   LoadDBTable(char* pTableName, char*& pBuffer, unsigned int& iLength);

public:
	friend  class  cobra_win::Singleton2<DBSystem>;
};

#define   DBSYSTEM   (DBSystem::get_instance2())


#endif
