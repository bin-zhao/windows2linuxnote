#ifndef  _NINJIATRIBE_UIWINDOWDATAMANAGER_H_
#define  _NINJIATRIBE_UIWINDOWDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <map>

#pragma pack(push, 1)
class UIWindowItemData : public IData
{
public:
	int  mWindowType;                      // 窗口类型
	char mWindowName[128];                 // 窗口名称
	int  mWindowZOrder;                    // 窗口Z-Order序列
	bool mIsModelWindow;                   // 是否模态窗口
	bool mIsScriptWindow;                  // 是否为脚本控制的窗口
	char mWindowScriptName[128];           // 脚本名称
	char mWindowParentName[128];           // 挂载的父窗口名称("root"为系统窗口)
	char mIpadLayoutName[128];             // iPad上的布局文件名称
	char mIpadEncryptedLayoutName[128];    // iPad上的布局文件表名
	char mIphoneLayoutName[128];           // iPhone上的布局文件名称
	char mIphoneEncryptedLayoutName[128];  // iPhone上的布局文件表名
	char mAndroidLayoutName[128];          // Android上的布局文件名称
	char mAndroidEncryptedLayoutName[128]; // Android上的布局文件表名
	char mSoundName[128];                  // 打开时音效名称名称

public:
	UIWindowItemData();
	virtual ~UIWindowItemData();

public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class UIWindowDataManager : public IDataManager, public cobra_win::Singleton2<UIWindowDataManager>
{
private:
	std::map<int, UIWindowItemData*> m_WindowList;

public:
	UIWindowDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~UIWindowDataManager();

public:
	/*
		根据窗口类型得到对应的信息
	*/
	UIWindowItemData* GetWindowByType(int type);
	/*
		得到UI窗口的个数
	*/
	unsigned  int     GetWindowNumber();
	/*
		得到指定位置的窗口信息
	*/
	UIWindowItemData* GetWindowByPos(unsigned int pos);

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
	friend   class   cobra_win::Singleton2<UIWindowDataManager>;
};


#endif
