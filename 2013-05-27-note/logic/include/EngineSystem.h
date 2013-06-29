#ifndef  _NINJIATRIBE_ENGINESYSTEM_H_
#define  _NINJIATRIBE_ENGINESYSTEM_H_


#include <include/common/Singleton.h>
#include <layers_scenes_transitions_nodes/CCScene.h>
#include <string>
using  namespace  cobra_win;

class EngineSystem : public cobra_win::Singleton2<EngineSystem>
{
public:
	const  static  int  _IOS_IPHONE_DEVICE_WIDTH_       = 640;
	const  static  int  _IOS_IPHONE_DEVICE_HEIGHT_      = 960;
	const  static  int  _IOS_IPAD_DEVICE_WIDTH_         = 768;
	const  static  int  _IOS_IPAD_DEVICE_HEIGHT_        = 1024;
	const  static  int  _ANDROID_480X320_DEVICE_WIDTH_  = 640;
	const  static  int  _ANDROID_480X320_DEVICE_HEIGHT_ = 960;
	const  static  int  _ANDROID_800X480_DEVICE_WIDTH_  = 640;
	const  static  int  _ANDROID_800X480_DEVICE_HEIGHT_ = 1167;

public:
	enum
	{
		_TYPED_IOS_DEVICE_UNKOWN_,     // 未知的设备类型
		_TYPED_IOS_DEVICE_IPHONE_,     // iPhone
		_TYPED_IOS_DEVICE_IPAD_,       // iPad
		_TYPED_IOS_DEVICE_ANDROID_,    // Android
	};

private:
	cocos2d::CCScene* m_pScene; // 场景指针

public:
	EngineSystem();
	virtual ~EngineSystem();

public:
    /*
        获取Document目录路径
    */
    static  std::string  GetDocumentDir();
    /*
        获取APP文件夹下面的文件路径
    */
    static  std::string  GetAppFilePath(std::string fileName);
	/*
		获得设备类型
	*/
	static  int          GetDeviceType();
	/*
		是否支持高清
	*/
	static  bool         IsSupportRetina();
	/*
		是否是iPad1
	*/
	static  bool         IsIPad1();
	/*
		是否显示广告墙按钮
	*/
	static   bool        IsShowOffers();
	/*
		是否为480*800分辨率设备(Android专用)
	*/
	static   bool        IsAndroid480X800();

public:
	/*
		得到引擎根场景指针
	*/
	cocos2d::CCScene* GetScene();

public:
	/*
		开始多点触摸功能
	*/
	void    EnableMultiTouch(bool bEnabled);
	/*
		打开指定URL
	*/
	void    OpenURL(char* pBuffer);
	/*
		截图
	*/
	bool    ScreenShot(std::string filename);

public:
	/*
		显示用户反馈界面
	*/
	void    ShowFeedbackDialog();

public:
	/*
		显示ADMob
	*/
	void    ShowAd(bool bShow);
	/*
		显示TapJoy广告墙
	*/
	void    showTapjoyOfferWall();
	/*
		显示Youmi广告墙
	*/
	void    showYoumiOfferWall();
	/*
		显示Dianjoy广告墙
	*/
	void    showDianjoyOfferWall();
	/*
		显示力美广告墙
	*/
	void    showImmobOfferWall();
	/*
		显示多盟广告墙
	*/
	void    showDomobOfferWall();
	/*
		显示91广告墙
	*/
	void    show91OfferWall();
	/*
		提示更新新版本
	*/
	void    UpdateNewVersionDialog(std::string title, std::string yes, std::string cancel);

public:
    /*
        强制进行内存回收处理
    */
    void    FreeMemory();

public:
	/*
		初始化引擎控制系统
	*/
	bool    Init();
	/*
		逻辑桢更新
	*/
	void    Tick();
	/*
		销毁引擎控制系统
	*/
	void    Destroy();

private:
	/*
		初始化场景管理器
	*/
	void    InitScene();
	/*
        加载系统必须的资源
    */
    void    LoadSysResource();

public:
	/*
		初始化引擎环境变量
	*/
	static   void    InitAppEnv();
	/*
		加载资源文件
	*/
	static   bool    LoadAppFile(char* pFileName, char*& pBuffer, unsigned int& iLength);
	/*
		加载用户存档文件
	*/
	static   bool    LoadTempFile(char* pFileName, char*& pBuffer, unsigned int& iLength);

private:
	/*
		引擎按钮操作回调处理(判断是否需要)
	*/
	static   void    OnEngineMenuItemCallbackEventHandler(std::string eventName, std::string menuItemName);

public:
	friend   class   cobra_win::Singleton2<EngineSystem>;
};

#define  ENGINESYSTEM  (EngineSystem::get_instance2())


#endif
