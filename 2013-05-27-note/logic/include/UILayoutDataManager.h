#ifndef  _NINJIATRIBE_UILAYOUTDATAMANAGER_H_
#define  _NINJIATRIBE_UILAYOUTDATAMANAGER_H_


#include "IDataManager.h"

class UILayoutDataManager : public IDataManager
{
protected:
	int    m_iWindowType; // 窗口类型
	char*  m_pLayoutText; // 布局信息

public:
	UILayoutDataManager(bool bLoadFromDB, bool bEncryption, int iWindowType);
	virtual ~UILayoutDataManager();

public:
	/*
		得到UI的布局信息
	*/
	virtual  char*  GetLayoutText();
	/*
		得到UI布局对应的窗口类型
	*/
	virtual  int    GetWindowType();
	/*
		得到对应的数据管理器名称
	*/
	virtual  std::string    GetName();
	/*
		得到对应的数据管理器内存占用大小
	*/
	virtual  unsigned  int  GetSize();

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

protected:
	/*
		校验加载的数据(单行数据的有效性校验)
	*/
	virtual   bool   Varify(IData* pData);
	/*
		校验加载的数据(所有数据加载完之后进行的关联性校验)
	*/
	virtual   bool   VarifyAfterLoadAll();
    
protected:
	/*
		从文件加载对应的资源
	*/
	virtual  bool  LoadFromFile();
	/*
		从数据库加载对应的资源
	*/
	virtual  bool  LoadFromDB();

protected:
	/*
		创建指定的ItemData数据
	*/
	virtual  bool  LoadData(char* pBuffer, unsigned int iBufferLen);
};


#endif
