#include "../include/DBSystem.h"
#include "../include/ProfSystem.h"
#include "../include/DebugerSystem.h"
#include "../include/EngineSystem.h"
#include "../include/EventTyper.h"
#include "../include/EventSystem.h"
#include "../include/GuideSystem.h"
#include "../include/UISystem.h"
#include "../include/IAPSystem.h"
#include "../include/InputSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/NetSystem.h"
#include "../include/MoreGameSystem.h"
#include "../include/GameCenterSystem.h"
#include "../include/SNSSystem.h"
#include "../include/NotifySystem.h"
#include "../include/PlayerBehaviorSystem.h"
#include "../include/ScriptSystem.h"
#include "../include/SoundSystem.h"
#include "../include/TimeSystem.h"
#include "../include/VariableSystem.h"
#include "../include/IProcedure.h"
#include "../include/LogoProcedure.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/LoadingProcedure.h"
#include "../include/LoginProcedure.h"
#include "../include/LobbyProcedure.h"
#include "../include/ArenaProcedure.h"
#include "../include/SelectBuffProcedure.h"
#include "../include/SelectServerProcedure.h"
#include "../Include/SysLangDataManager.h"
#include <script_support/CCScriptSupport.h>
#include <cocos2d.h>
using  namespace  cocos2d;


template<> NinjiaTribeApp* cobra_win::Singleton2<NinjiaTribeApp>::m_pMySelf = NULL;

NinjiaTribeApp::NinjiaTribeApp()
{
	m_pLogoProcedure      = NULL;
	m_pSelServerProcedure = NULL;
	m_pLoadingProcedure   = NULL;
	m_pLoginProcedure     = NULL;
	m_pLobbyProcedure     = NULL;
	m_pSelectBuffProcedure = NULL;
	m_pArenaProcedure     = NULL;

	m_pPreProcedure    = NULL;
	m_pActiveProcedure = NULL;

	m_bRun             = true;
	m_bActive          = true;
}

NinjiaTribeApp::~NinjiaTribeApp()
{

}

std::string NinjiaTribeApp::GetVersion()
{
	return "1.0.1";
}

void NinjiaTribeApp::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool NinjiaTribeApp::IsActive()
{
	return m_bActive;
}

void NinjiaTribeApp::SetRun(bool bRun)
{
	m_bRun = bRun;
}

int NinjiaTribeApp::GetFPS()
{
	int fps = 30;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "FPS", fps);

	if (fps < 20)
		fps = 20;
	else if (fps > 60)
		fps = 60;

	return fps;
}

int NinjiaTribeApp::GetAppChannel()
{
	char buffer[1024] = "";
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "AppChannelType", buffer, sizeof(buffer)-1);
	if (std::string("ios").compare(buffer) == 0)
	{
		return _TYPED_APP_CHANNEL_IOS_;
	}
	else if (std::string("win32").compare(buffer) == 0)
	{
		return _TYPED_APP_CHANNEL_WIN32_;
	}
	else if (std::string("huawei").compare(buffer) == 0)
	{
		return _TYPED_APP_CHANNEL_HUAWEI_;
	}
	else if (std::string("gfan").compare(buffer) == 0)
	{
		return _TYPED_APP_CHANNEL_GFAN_;
	}
	else if (std::string("91").compare(buffer) == 0)
	{
		return _TYPED_APP_CHANNEL_91_;
	}
	else if (std::string("xiaomi").compare(buffer) == 0)
	{
		return _TYPED_APP_CHANNEL_XIAOMI_;
	}

	return _TYPED_APP_CHANNEL_UNKOWN_;
}

int NinjiaTribeApp::GetAppWidth()
{
	int width = 960;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "Width", width);

	return width;
}

int NinjiaTribeApp::GetAppHeight()
{
	int height = 640;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "Height", height);

	return height;
}

void NinjiaTribeApp::SetActiveProcedure(IProcedure* pProcedure)
{
	if (pProcedure==NULL || m_pActiveProcedure==pProcedure)
		return ;

	m_pPreProcedure    = m_pActiveProcedure;
	m_pActiveProcedure = pProcedure;
}

IProcedure* NinjiaTribeApp::GetActiveProcedure()
{
	return m_pActiveProcedure;
}

void NinjiaTribeApp::ForceFreeMemory()
{
	ENGINESYSTEM->FreeMemory();
}

void NinjiaTribeApp::UpdateGoodsList(float dt)
{

}

void NinjiaTribeApp::PushAd(float dt)
{

}

void NinjiaTribeApp::UpdateRankList(float dt)
{

}

void NinjiaTribeApp::UpdateRankList2(float dt)
{

}

void NinjiaTribeApp::UpdateServerURL(float dt)
{

}

void NinjiaTribeApp::VerifyIAPList(float dt)
{

}

void NinjiaTribeApp::UpdateOfferWallPoints(float dt)
{
	// 开始更新各个平台的点数
	cocos2d::CCDirector::sharedDirector()->getAd()->updateDianjoyPoints();
	cocos2d::CCDirector::sharedDirector()->getAd()->updateYoumiPoints();
	cocos2d::CCDirector::sharedDirector()->getAd()->updateImmobPoints();
	cocos2d::CCDirector::sharedDirector()->getAd()->updateTapjoyPoints();
	cocos2d::CCDirector::sharedDirector()->getAd()->updateDomobPoints();
	cocos2d::CCDirector::sharedDirector()->getAd()->update91Points();
}

void NinjiaTribeApp::UpdateSystemPopText(int sysLangId)
{
;
}

void NinjiaTribeApp::UpdateSystemPopText(int sysLangId, std::string add)
{

}

bool NinjiaTribeApp::Init()
{
	do 
	{
		// 初始化CCNode
		onEnter();

		// 设置接收事件
		CCDirector::sharedDirector()->getAd()->setDelegate(dynamic_cast<cocos2d::CCAdDelegate*>(this));
		CCDirector::sharedDirector()->getSystem()->setDelegate(dynamic_cast<cocos2d::CCSystemDelegate*>(this));

		// 初始化随机数生成器
		srand((unsigned)time(NULL));

		// 初始化应用程序引擎层环境变量
		EngineSystem::InitAppEnv();

		// 初始化配置系统管理器
		new VariableSystem;
		if (!VARIABLESYSTEM->Init())
			break;

		// 初始化日志系统管理器
		new LoggerSystem;
		if (!LOGGERSYSTEM->Init())
			break;

		// 初始化性能统计系统管理器
		new ProfSystem;
		if (!PROFSYSTEM->Init())
			break;

		_BEGIN_PROF_CHUNK_("TimeSystem::Init()")
		// 初始化时间系统管理器
		new TimeSystem;
		if (!TIMESYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("NetSystem::Init()")
		// 初始化网络系统管理器
		new NetSystem;
		if (!NETSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("InputSystem::Init()")
		// 初始化输入控制系统
		new InputSystem;
		if (!INPUTSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("EventSystem::Init()")
		// 初始化事件响应处理系统
		new EventSystem;
		if (!EVENTSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("PlayerBehaviorSystem::Init()")
		// 初始化用户行为跟踪系统管理器
		new PlayerBehaviorSystem;
		if (!PLAYERBEHAVIORSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("DBSystem::Init()")
		// 初始化数据管理系统管理器
		new DBSystem;
		if (!DBSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("SNSSystem::Init()")
		// 初始化SNS系统管理器
		new SNSSystem;
		if (!SNSSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("MoreGameSystem::Init()")
		// 初始化更多游戏系统管理器
		new MoreGameSystem;
		if (!MOREGAMESYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("EngineSystem::Init()")
		// 初始化引擎系统管理器
		new EngineSystem;
		if (!ENGINESYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("SoundSystem::Init()")
		// 初始化音效管理器
		new SoundSystem;
		if (!SOUNDSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("ScriptSystem::Init()")
		// 初始化脚本系统管理器
		new ScriptSystem;
		if (!SCRIPTSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("UISystem::Init()")
		// 初始化UI系统管理器
		new UISystem;
		if (!UISYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("GuideSystem::Init()")
		// 初始化新手引导系统管理器
		new GuideSystem;
		if (!GUIDESYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("GameCenterSystem::Init()")
		// 初始化GameCenter管理器
		new GameCenterSystem;
		if (!GAMECENTERSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("IAPSystem::Init()")
		// 初始化IAP交易系统管理器
		new IAPSystem;
		if (!IAPSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("NotifySystem::Init()")
		// 初始化本地通知系统管理器
		new NotifySystem;
		if (!NOTIFYSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		_BEGIN_PROF_CHUNK_("DebugerSystem::Init()")
		// 初始化调试器管理器
		new DebugerSystem;
		if (!DEBUGERSYSTEM->Init())
			break;
		_END_PROF_CHUNK_()

		m_pLogoProcedure      = new LogoProcedure;
		m_pSelServerProcedure = new SelectServerProcedure;
		m_pLoadingProcedure   = new LoadingProcedure;
		m_pLoginProcedure     = new LoginProcedure;
		m_pLobbyProcedure     = new LobbyProcedure;
		m_pSelectBuffProcedure = new SelectBuffProcedure;
		m_pArenaProcedure     = new ArenaProcedure;

		if (EngineSystem::GetDeviceType()==EngineSystem::_TYPED_IOS_DEVICE_ANDROID_)
		{
			m_pPreProcedure    = m_pLogoProcedure;
			m_pActiveProcedure = m_pLogoProcedure;
			m_pActiveProcedure->Init();
		}
		else
		{
			bool bSelServer = false;
			VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "SelectServer", bSelServer);
			if (bSelServer)
			{
				// 选择服务器
				m_pPreProcedure    = m_pSelServerProcedure;
				m_pActiveProcedure = m_pSelServerProcedure;
				m_pActiveProcedure->Init();
			}
			else
			{
				m_pPreProcedure    = m_pLoginProcedure;
				m_pActiveProcedure = m_pLoginProcedure;
				m_pActiveProcedure->Init();
			}
		}

		// 注册游戏帧循环
		schedule(schedule_selector(NinjiaTribeApp::Tick));

		// 进行定时申请商品列表
		float updateGoodsListInterval = 200.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "UpdateGoodsListInterval", updateGoodsListInterval);
		schedule(schedule_selector(NinjiaTribeApp::UpdateGoodsList), updateGoodsListInterval);

		// 进行定时Push广告
		float pushAdInterval = 300.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "PushAdInterval", pushAdInterval);
		schedule(schedule_selector(NinjiaTribeApp::PushAd), pushAdInterval);

		// 进行定时申请排名列表
		float updateRankListInterval = 20.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "UpdateRankListInterval", updateRankListInterval);
		schedule(schedule_selector(NinjiaTribeApp::UpdateRankList), updateRankListInterval);

		// 进行定时申请排名列表
		float updateRankListInterval2 = 300.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "UpdateRankListInterval2", updateRankListInterval2);
		schedule(schedule_selector(NinjiaTribeApp::UpdateRankList2), updateRankListInterval2);

		// 进行定时服务器DNS解析
		float updateServerURLInterval = 100.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "UpdateServerURLInterval", updateServerURLInterval);
		schedule(schedule_selector(NinjiaTribeApp::UpdateServerURL), updateServerURLInterval);

		// 进行定时验证IA订单的操作
		float verifyIAPInterval = 10.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "VerifyIAPListInterval", verifyIAPInterval);
		schedule(schedule_selector(NinjiaTribeApp::VerifyIAPList), verifyIAPInterval);

		// 进行更新各个广告墙积分的操作
		float updateOfferWallPoints = 100.0f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "UpdateOfferWallPointsInterval", updateOfferWallPoints);
		schedule(schedule_selector(NinjiaTribeApp::UpdateOfferWallPoints), updateOfferWallPoints);

		// 开始申请各个平台的点数
		cocos2d::CCDirector::sharedDirector()->getAd()->queryDianjoyPoints();
		cocos2d::CCDirector::sharedDirector()->getAd()->queryYoumiPoints();
		cocos2d::CCDirector::sharedDirector()->getAd()->queryImmobPoints();
		cocos2d::CCDirector::sharedDirector()->getAd()->queryTapjoyPoints();
		cocos2d::CCDirector::sharedDirector()->getAd()->queryDomobPoints();
		cocos2d::CCDirector::sharedDirector()->getAd()->query91Points();

		// 设置游戏默认语言
		int type = SysLangDataManager::_TYPED_SYSLANG_CN_;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_ACCOUNT_, "SYS", "SysLangType", type);
		cocos2d::CCDirector::sharedDirector()->getSystem()->setSysLang(type);

		LOGGERSYSTEM->LogInfo("Init NinjiaTribeApp Success\n");
		return true;
	} 
	while(false);

	return false;
}

void NinjiaTribeApp::Tick(float interval)
{
	if (m_pActiveProcedure != m_pPreProcedure)
	{
		m_pPreProcedure->Destroy();
		m_pActiveProcedure->Init();

		m_pPreProcedure = m_pActiveProcedure;
	}

	// 时间系统管理器帧更新
	TIMESYSTEM->Tick(interval);
	// 配置系统管理器桢更新
	VARIABLESYSTEM->Tick();
	// 日志系统管理器桢更新
	LOGGERSYSTEM->Tick();
	// 性能统计系统帧更新
	PROFSYSTEM->Tick();
	// 网络管理系统帧更新
	NETSYSTEM->Tick();
	// 输入控制系统管理器桢更新
	INPUTSYSTEM->Tick();
	// 事件响应处理系统桢更新
	EVENTSYSTEM->Tick();
	// 用户行为跟踪系统帧更新
	PLAYERBEHAVIORSYSTEM->Tick();
	// 数据管理系统帧更新
	DBSYSTEM->Tick();
	// SNS管理系统帧更新
	SNSSYSTEM->Tick();
	// 更多游戏管理系统帧更新
	MOREGAMESYSTEM->Tick();
	// 引擎系统管理器桢更新
	ENGINESYSTEM->Tick();
	// 音效管理器桢更新
	SOUNDSYSTEM->Tick();
	// 脚本系统管理器帧更新
	SCRIPTSYSTEM->Tick();
	// UI系统管理器桢更新
	UISYSTEM->Tick();
	// 新手引导系统管理器帧更新
	GUIDESYSTEM->Tick();
	// GameCenter系统管理器帧更新
	GAMECENTERSYSTEM->Tick();
	// IAP交易系统管理器帧更新
	IAPSYSTEM->Tick();
	// 本地通知系统管理器帧更新
	NOTIFYSYSTEM->Tick();
	// 调试器管理器帧更新
	DEBUGERSYSTEM->Tick();
	// 当前处理流程桢更新
	m_pActiveProcedure->Tick();

	// 是否终止程序
	if (!m_bRun)
	{
		Destroy();
	}
}

void NinjiaTribeApp::Destroy()
{
	// 对当前正在激活的流程进行销毁，释放必要资源
	if (m_pActiveProcedure != NULL)
	{
		m_pActiveProcedure->Destroy();
		m_pPreProcedure    = NULL;
		m_pActiveProcedure = NULL;
	}

	// 删除LOGO流程处理
	if (m_pLogoProcedure != NULL)
	{
		delete m_pLogoProcedure;
		m_pLogoProcedure = NULL;
	}

	// 删除Loading处理流程
	if (m_pLoadingProcedure != NULL)
	{
		delete m_pLoadingProcedure;
		m_pLoadingProcedure = NULL;
	}

	// 删除选择服务器流程处理
	if (m_pSelServerProcedure != NULL)
	{
		delete m_pSelServerProcedure;
		m_pSelServerProcedure = NULL;
	}

	// 删除登陆流程处理
	if (m_pLoginProcedure != NULL)
	{
		delete m_pLoginProcedure;
		m_pLoginProcedure = NULL;
	}

	// 删除大厅流程处理
	if (m_pLobbyProcedure != NULL)
	{
		delete m_pLobbyProcedure;
		m_pLobbyProcedure = NULL;
	}

	// 删除大厅流程处理
	if (m_pSelectBuffProcedure != NULL)
	{
		delete m_pSelectBuffProcedure;
		m_pSelectBuffProcedure = NULL;
	}

	// 删除竞技场流程处理
	if (m_pArenaProcedure != NULL)
	{
		delete m_pArenaProcedure;
		m_pArenaProcedure = NULL;
	}

	// 销毁调试器管理器
	if (DEBUGERSYSTEM != NULL)
	{
		DEBUGERSYSTEM->Destroy();
		delete DEBUGERSYSTEM;
	}

	// 销毁输入控制系统管理器
	if (INPUTSYSTEM != NULL)
	{
		INPUTSYSTEM->Destroy();
		delete INPUTSYSTEM;
	}

	// 销毁本地通知系统管理器
	if (NOTIFYSYSTEM != NULL)
	{
		NOTIFYSYSTEM->Destroy();
		delete NOTIFYSYSTEM;
	}

	// 销毁IAP交易系统管理器
	if (IAPSYSTEM != NULL)
	{
		IAPSYSTEM->Destroy();
		delete IAPSYSTEM;
	}

	//  销毁GameCenter管理器
	if (GAMECENTERSYSTEM != NULL)
	{
		GAMECENTERSYSTEM->Destroy();
		delete GAMECENTERSYSTEM;
	}

	// 销毁引导引导系统管理器
	if (GUIDESYSTEM != NULL)
	{
		GUIDESYSTEM->Destroy();
		delete GUIDESYSTEM;
	}

	// 销毁UI系统管理器
	if (UISYSTEM != NULL)
	{
		UISYSTEM->Destroy();
		delete UISYSTEM;
	}

	// 销毁脚本系统管理器
	if (SCRIPTSYSTEM != NULL)
	{
		SCRIPTSYSTEM->Destroy();
		delete SCRIPTSYSTEM;
	}

	// 销毁音效管理器
	if (SOUNDSYSTEM != NULL)
	{
		SOUNDSYSTEM->Destroy();
		delete SOUNDSYSTEM;
	}

	// 销毁更多游戏系统管理器
	if (MOREGAMESYSTEM != NULL)
	{
		MOREGAMESYSTEM->Destroy();
		delete MOREGAMESYSTEM;
	}

	// 销毁SNS系统管理器
	if (SNSSYSTEM != NULL)
	{
		SNSSYSTEM->Destroy();
		delete SNSSYSTEM;
	}

	// 销毁引擎系统管理器
	if (ENGINESYSTEM != NULL)
	{
		ENGINESYSTEM->Destroy();
		delete ENGINESYSTEM;
	}

	// 销毁数据系统管理器
	if (DBSYSTEM != NULL)
	{
		DBSYSTEM->Destroy();
		delete DBSYSTEM;
	}

	// 销毁用户行为跟踪系统管理器
	if (PLAYERBEHAVIORSYSTEM != NULL)
	{
		PLAYERBEHAVIORSYSTEM->Destroy();
		delete PLAYERBEHAVIORSYSTEM;
	}

	// 销毁事件响应处理系统
	if (EVENTSYSTEM != NULL)
	{
		EVENTSYSTEM->Destroy();
		delete EVENTSYSTEM;
	}

	// 销毁网络系统
	if (NETSYSTEM != NULL)
	{
		NETSYSTEM->Destroy();
		delete NETSYSTEM;
	}

	// 销毁时间系统管理器
	if (TIMESYSTEM != NULL)
	{
		TIMESYSTEM->Destroy();
		delete TIMESYSTEM;
	}

	// 销毁配置系统管理器
	if (VARIABLESYSTEM != NULL)
	{
		VARIABLESYSTEM->Destroy();
		delete VARIABLESYSTEM;
	}

	// 销毁性能统计系统
	if (PROFSYSTEM != NULL)
	{
		PROFSYSTEM->Destroy();
		delete PROFSYSTEM;
	}

	// 销毁日志系统管理器
	if (LOGGERSYSTEM != NULL)
	{
		LOGGERSYSTEM->Destroy();
		delete LOGGERSYSTEM;
	}

	cocos2d::CCDirector::sharedDirector()->end();
	cocos2d::CCScriptEngineManager::sharedManager()->removeScriptEngine();
	cocos2d::CCScriptEngineManager::sharedManager()->purgeSharedManager();
}

void NinjiaTribeApp::onReceiveYoumiPoints(int amount)
{
	if (amount <= 0)
		return;

	cocos2d::CCDirector::sharedDirector()->getAd()->spendYoumiPoints(amount);
	LOGGERSYSTEM->LogInfo("Receive YouMi Points=%d\n", amount);
}

void NinjiaTribeApp::onReceiveDianjoyPoints(int amount)
{
	if (amount <= 0)
		return;

	cocos2d::CCDirector::sharedDirector()->getAd()->spendDianjoyPoints(amount);
	LOGGERSYSTEM->LogInfo("Receive DianLe Points=%d\n", amount);
}

void NinjiaTribeApp::onReceiveImmobPoints(int amount)
{
	if (amount <= 0)
		return;

	cocos2d::CCDirector::sharedDirector()->getAd()->spendImmobPoints(amount);
	LOGGERSYSTEM->LogInfo("Receive Immob Points=%d\n", amount);
}

void NinjiaTribeApp::onReceiveTapjoyPoints(int amount)
{
	if (amount <= 0)
		return;

	cocos2d::CCDirector::sharedDirector()->getAd()->spendTapjoyPoints(amount);
	LOGGERSYSTEM->LogInfo("Receive Tapjoy Points=%d\n", amount);
}

void NinjiaTribeApp::onReceiveDomobPoints(int amount)
{
	if (amount <= 0)
		return;

	cocos2d::CCDirector::sharedDirector()->getAd()->spendDomobPoints(amount);
	LOGGERSYSTEM->LogInfo("Receive Domob Points=%d\n", amount);
}

void NinjiaTribeApp::onReceive91Points(int amount)
{
	if (amount <= 0)
		return;

	cocos2d::CCDirector::sharedDirector()->getAd()->spend91Points(amount);
	LOGGERSYSTEM->LogInfo("Receive 91 Points=%d\n", amount);
}

void NinjiaTribeApp::onAppExit()
{
	Destroy();
}

void NinjiaTribeApp::applicationDidPaused()
{
	m_pActiveProcedure->OnSystemPauseEventHandler();
	cocos2d::CCDirector::sharedDirector()->pause();
	SetActive(false);
}

void NinjiaTribeApp::applicationDidResumed()
{
	m_pActiveProcedure->OnSystemResumeEventHandler();
	cocos2d::CCDirector::sharedDirector()->resume();
	SetActive(true);
}

bool NinjiaTribeApp::applicationDidFinishLaunching()
{
	bool ret = Init();
	if (!ret)
	{
		delete this;
		exit(0);
	}
	return ret;
}

void NinjiaTribeApp::applicationDidEnterBackground()
{
	// 在Win32下面，因为resize了窗口会提前调用这个地方，所以加上
	// 必要的判断 
	if (m_pActiveProcedure == NULL)
		return;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	// 销毁音效系统
	if (SOUNDSYSTEM != NULL)
		SOUNDSYSTEM->Destroy();
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	if (SOUNDSYSTEM != NULL)
		SOUNDSYSTEM->OnEnterBackgroundEventHandler();
#endif

	m_pActiveProcedure->OnSystemEnterBackEventHandler();
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
	cocos2d::CCDirector::sharedDirector()->stopAnimation();
#endif
	cocos2d::CCDirector::sharedDirector()->pause();

	SetActive(false);
}

void NinjiaTribeApp::applicationWillEnterForeground()
{
	// 在Win32下面，因为resize了窗口会提前调用这个地方，所以加上
	// 必要的判断 
	if (m_pActiveProcedure == NULL)
		return;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	// 重置音效系统
	if (SOUNDSYSTEM != NULL)
		SOUNDSYSTEM->Init();
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	if (SOUNDSYSTEM != NULL)
		SOUNDSYSTEM->OnEnterForegroundEventHandler();
#endif

	m_pActiveProcedure->OnSystemEnterFrontEventHandler();
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
	cocos2d::CCDirector::sharedDirector()->startAnimation();
#endif
	cocos2d::CCDirector::sharedDirector()->resume();
	SetActive(true);
}

void NinjiaTribeApp::applicationAndroidSurfaceCreated()
{
	EVENTSYSTEM->PushEvent(_TYPED_EVENT_ANDROID_SURFACE_CREATED_);
}
