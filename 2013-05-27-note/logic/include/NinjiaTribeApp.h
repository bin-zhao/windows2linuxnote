#ifndef  _NINJIATRIBE_NINJIATRIBEAPP_H_
#define  _NINJIATRIBE_NINJIATRIBEAPP_H_


#include <include/common/Singleton.h>
#include <CCApplication.h>
#include <CCAdDelegate.h>
#include <CCSystemDelegate.h>
#include <base_nodes/CCNode.h>
using  namespace  cobra_win;

class IProcedure;
class LogoProcedure;
class LoginProcedure;
class LobbyProcedure;
class ArenaProcedure;
class LoadingProcedure;
class SelectServerProcedure;
class SelectBuffProcedure;
class NinjiaTribeApp : public cocos2d::CCNode, public cocos2d::CCApplication, public cocos2d::CCAdDelegate, public cocos2d::CCSystemDelegate, public cobra_win::Singleton2<NinjiaTribeApp>
{
public:
	enum
	{
		_TYPED_APP_CHANNEL_UNKOWN_,   // 未知渠道类型
		_TYPED_APP_CHANNEL_WIN32_,    // Win32渠道
		_TYPED_APP_CHANNEL_IOS_,      // IOS渠道
		_TYPED_APP_CHANNEL_HUAWEI_,   // HuaWei渠道
		_TYPED_APP_CHANNEL_GFAN_,     // 机锋渠道
		_TYPED_APP_CHANNEL_XIAOMI_,   // 小米渠道
		_TYPED_APP_CHANNEL_91_,       // 91渠道
	};

public:
	LogoProcedure*         m_pLogoProcedure;     // LOGO处理流程
	SelectServerProcedure* m_pSelServerProcedure;// 选择服务器处理流程
	LoadingProcedure*      m_pLoadingProcedure;  // Loading处理流程
	LoginProcedure*        m_pLoginProcedure;    // 登陆处理流程
	LobbyProcedure*        m_pLobbyProcedure;    // 大厅处理流程
	SelectBuffProcedure*   m_pSelectBuffProcedure;// BUFF处理流程
	ArenaProcedure*        m_pArenaProcedure;    // 竞技场处理流程

public:
	IProcedure* m_pPreProcedure;    // 上一帧对应的处理流程
	IProcedure* m_pActiveProcedure; // 当前激活的处理流程

public:
	bool        m_bRun;    // 添加变量,在每一帧最后执行退出操作
	bool        m_bActive; // 当前窗口是否激活

public:
	NinjiaTribeApp();
	virtual ~NinjiaTribeApp();

public:
	/*
		得到游戏版本号
	*/
	std::string  GetVersion();
	/*
        设置窗口激活状态
    */
	void         SetActive(bool bActive);
	/*
        窗口是否激活
    */
	bool         IsActive();
	/*
		设置是否运行
	*/
	void         SetRun(bool bRun);
	/*
		得到客户端帧率
	*/
	int          GetFPS();
	/*
		得到App渠道类型
	*/
	int          GetAppChannel();
	/*
		得到客户端窗口宽度
	*/
	int          GetAppWidth();
	/*
		得到客户端窗口高度
	*/
	int          GetAppHeight();

public:
	/*
		切换流程
	*/
	void         SetActiveProcedure(IProcedure* pProcedure);
	/*
		得到当前流程
	*/
	IProcedure*  GetActiveProcedure();
	/*
        强制进行内存回收处理
    */
    void         ForceFreeMemory();

public:
	/*
		定时商店玩家物品信息
	*/
	void         UpdateGoodsList(float dt);
	/*
		定时Push广告消息
	*/
	void         PushAd(float dt);
	/*
		定时更新玩家排行消息
	*/
	void         UpdateRankList(float dt);
	/*
		每隔10分钟刷新一次玩家排行消息
	*/
	void         UpdateRankList2(float dt);
	/*
		定时DNS解析
	*/
	void         UpdateServerURL(float dt);
	/*
		定时验证尚未验证的订单
	*/
	void         VerifyIAPList(float dt);
	/*
		定时更新各个广告墙积分
	*/
	void         UpdateOfferWallPoints(float dt);

public:
	/*
		提示系统消息
	*/
	void         UpdateSystemPopText(int sysLangId);
	/*
		提示系统消息
	*/
	void         UpdateSystemPopText(int sysLangId, std::string add);

public:
	/*
		初始化游戏管理器
	*/
	bool         Init();
	/*
		逻辑桢处理
	*/
	void         Tick(float interval);
	/*
		销毁游戏管理器
	*/
	void         Destroy();

public:
	/*
		收到YouMi点数
	*/
	virtual  void  onReceiveYoumiPoints(int amount);
	/*
		收到点乐点数
	*/
	virtual  void  onReceiveDianjoyPoints(int amount);
	/*
		收到点乐点数
	*/
	virtual  void  onReceiveImmobPoints(int amount);
	/*
		收到点乐点数
	*/
	virtual  void  onReceiveTapjoyPoints(int amount);
	/*
		收到多盟点数
	*/
	virtual  void  onReceiveDomobPoints(int amount);
	/*
		收到91点数
	*/
	virtual  void  onReceive91Points(int amount);

public:
	/*
		外部退出游戏
	*/
	virtual  void  onAppExit();

public:
	/*
		游戏失去焦点处理操作
	*/
	virtual  void  applicationDidPaused();
	/*
		游戏获得焦点处理操作
	*/
	virtual  void  applicationDidResumed();
	/*
		初始化完成之后，进行必要操作处理
	*/
    virtual  bool  applicationDidFinishLaunching();
	/*
		游戏进入后台处理操作
	*/
    virtual  void  applicationDidEnterBackground();
	/*
		游戏进入前台运行处理操作
	*/
    virtual  void  applicationWillEnterForeground();
	/*
		游戏OpenGL Context Created On Android
	*/
	virtual  void  applicationAndroidSurfaceCreated();

public:
	friend   class   cobra_win::Singleton2<NinjiaTribeApp>;
};


#endif
