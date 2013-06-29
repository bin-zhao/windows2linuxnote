#ifndef  _NINJIATRIBE_IWINDOW_H_
#define  _NINJIATRIBE_IWINDOW_H_


#include <cocos2d.h>
#include <string>
#include <list>

class IWindow : public cocos2d::CCNode, public cocos2d::CCTouchDelegate
{
public:
	enum
	{
		_TYPED_WINDOW_UNKOWN_,           // 未知类型的UI窗口
		_TYPED_WINDOW_LOADING_,          // 加载进度条窗口
		_TYPED_WINDOW_TOP_,              // 最顶层窗口
		_TYPED_WINDOW_ALERT_,            // Alert窗口
		_TYPED_WINDOW_MESSAGEBOX_,       // MessageBox窗口
		_TYPED_WINDOW_LOGO_,             // LOGO窗口
		_TYPED_WINDOW_LOGIN_,            // 登陆窗口
		_TYPED_WINDOW_LOBBY_,            // 大厅窗口
		
		_TYPED_WINDOW_ARENA_,            // 竞技场场景窗口
		_TYPED_WINDOW_ARENARESULT_,      // 竞技场结果面板
		_TYPED_WINDOW_PAUSE_,            // 竞技场暂停面板
		_TYPED_WINDOW_SYSTEM_SETTING_,   // 系统设置面板
		_TYPED_WINDOW_SHOP_,             // 商店面板
		_TYPED_WINDOW_SELECTBUFF_=13,    // SelectBuff窗口
		_TYPED_WINDOW_GAMEOVER_=14,		 // GameOver窗口
	};

public:
	enum
	{
		_TYPED_ALERT_WINDOW_UNKOWN_, // 未知子类型的警告提示窗口
	};

public:
	enum
	{
		_TYPED_WINDOW_ZORDER_UNKOWN_, // 未知的窗口Z-Order序列
		_TYPED_WINDOW_ZORDER_NORMAL_, // 普通的窗口Z-Order序列
		_TYPED_WINDOW_ZORDER_HIGH_,   // 高等级窗口的Z-Order序列
		_TYPED_WINDOW_ZOREDR_HIGHEST_,// 最高等级窗口的Z-Order序列
		_TYPED_WINDOW_ZOREDR_TOP_,    // 最高更急的窗口Z-Order序列(仅为整个客户端系统的系统信息面板)
	};

public:
	struct _SCRIPT_TIMER_FUNCTION_
	{
		long  long  mStartTime;     // 开始时间
		int         mIntervalTime;  // 间隔时间
		std::string mScriptFunction;// 脚本定时回调函数
		_SCRIPT_TIMER_FUNCTION_()
		{
			mStartTime    = 0;
			mIntervalTime = 0;
		}
	};

protected:
	int                 m_WindowType;       // 窗口所属类型
	std::string         m_WindowName;       // 窗口名称
	bool                m_bModelWindow;     // 是否为模态模式窗口
	int                 m_WindowZOrder;     // 窗口Z-Order序列
	std::string         m_ParentWindowName; // 窗口父窗口的名称
	bool                m_bLoaded;          // 是否已经加载
	bool                m_bShow;            // 该layout对应的根窗口是否可见
	bool                m_bTickListener;    // 是否帧回调处理
	cocos2d::CCNode*    m_pRootNode;        // 该Layout对应的根窗口

protected:
	long    long        m_TickCounter;      // 逻辑帧计数

protected:
	bool                m_bFadeout;         // 是否正在渐隐
	int                 m_FadeoutCounter;   // 渐隐计数器

protected:
	std::string         m_WindowDataList[16];// 窗口内部数据列表(用于进行保存部分玩家数据)

protected:
	std::list<_SCRIPT_TIMER_FUNCTION_> m_ScriptTimerList;// 脚本定时接口

public:
	IWindow();
	virtual ~IWindow();

public:
	/*
		得到当前LAYOUT名称
	*/
	int                GetWindowType();
	/*
		是否已经加载
	*/
	bool               IsLoad();
	/*
		得到根窗口指针
	*/
	cocos2d::CCNode*   GetRootNode();

public:
	/*
		设置窗口指定索引的数据
	*/
	void  SetWindowDataByPos(std::string str, unsigned int pos);
	/*
		得到
	*/
	std::string GetWindowDataByPos(unsigned int pos);

public:
	/*
		是否帧监听
	*/
	virtual    void    SetTickListenser(bool bListenser);
	/*
		设置LAYOUT显示于隐藏
	*/
	virtual    void    Show(bool bShow);
	/*
		判断LAYOYUT是否可见
	*/
	virtual    bool    IsVisible();
	/*
		是否正在渐隐中
	*/
	virtual    bool    IsFadeout();

public:
	/*
		设置X坐标
	*/
	virtual    void    SetXPosition(float xPos);
	/*
		得到X坐标
	*/
	virtual    float   GetXPosition();
	/*
		设置Y坐标
	*/
	virtual    void    SetYPosition(float yPos);
	/*
		得到Y坐标
	*/
	virtual    float   GetYPosition();
	/*
		设置X缩放比例
	*/
	virtual    void    SetXScale(float xScale);
	/*
		设置Y缩放比例
	*/
	virtual    void    SetYScale(float yScale);
	/*
		注册UI绑定事件
	*/
	virtual    void    RegisterEvent(int iEventType, bool bNotifyOnlyWhenVisible=false);
	/*
		分发事件
	*/
	virtual    void    PushEvent(int iEventType);
	/*
		分发事件
	*/
	virtual    void    PushEvent(int iEventType, char* pArgs);
	/*
		播放窗口打开时的音效
	*/
	virtual    void    PlayOpenSound();

public:
	/*
		注册脚本定时回调接口
	*/
	virtual    void    RegisterTimerFunction(float time, std::string functionName);

public:
	/*
		渐隐窗口
	*/
	virtual    void    Fadeout(float time);

public:
	/*
		初始化处理
	*/
	virtual    bool    Init();
	/*
		加载处理
	*/
	virtual    bool    Load();
	/*
		桢更新处理
	*/
	virtual    void    Tick();
	/*
		销毁处理
	*/ 
	virtual    void    Destroy();

public:
	/*
		消息事件响应处理
	*/
	virtual    void    OnEventHandler(int iEventType, std::list<std::string>& paramList)   =   0;


public:
	/*
		开始接触操作
	*/
	virtual    bool    ccTouchBegan(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
	/*
		移动操作
	*/
	virtual    void    ccTouchMoved(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
	/*
		接触结束操作
	*/
	virtual    void    ccTouchEnded(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
	/*
		接触取消操作
	*/
	virtual    void    ccTouchCancel(cocos2d::CCTouch* touche, cocos2d::CCEvent* event);
};


#endif
