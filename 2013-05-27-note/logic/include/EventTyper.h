#ifndef  _NINJIATRIBE_EVENTTYPER_H_
#define  _NINJIATRIBE_EVENTTYPER_H_


enum
{
	_TYPED_EVENT_UNKOWN_,                         // 未知类型的事件

	_TYPED_EVENT_SNS_LOGIN_SUCCESS_,              // SNS登陆成功提示
	_TYPED_EVENT_SNS_LOGIN_FAILED_,               // SNS登陆失败提示
	_TYPED_EVENT_SNS_SHARE_SUCCESS_,              // SNS分享成功提示
	_TYPED_EVENT_SNS_SHARE_FAILED_,               // SNS分享失败提示
	_TYPED_EVENT_SNS_SHARETOLOGIN_SUCCESS_,       // 
	_TYPED_EVENT_SNS_ADDFRIEND_SUCCESS_,          // SNS添加好友成功提示
	_TYPED_EVENT_SNS_ADDFRIEND_FAILED_,           // SNS添加好友失败提示

	_TYPED_EVENT_GAMECENTER_AUTHENTICATION_,      // GameCenter验证回调消息

	_TYPED_EVENT_LOCAL_IAP_SUCCESS_,              // 本地购买成功消息
	_TYPED_EVENT_LOCAL_IAP_FAILED_,               // 本地购买失败消息

	_TYPED_EVENT_UPDATE_LOGIC_DEBUGER_,           // 更新逻辑调试器信息
	_TYPED_EVENT_UPDATE_NET_DEBUGER_,             // 更新网络调试器信息
	_TYPED_EVENT_UPDATE_RENDER_DEBUGER_,          // 更新渲染调试器信息

	_TYPED_EVENT_SHOW_TOPWINDOW_,                 // 显示整个客户端系统提示面板
	_TYPED_EVENT_HIDE_TOPWINDOW_,                 // 隐藏整个客户端系统提示面板
	_TYPED_EVENT_UPDATE_TOPWINDOW_,               // 更新整个客户端系统提示面板
	_TYPED_EVENT_FADEOUT_TOPWINDOW_,              // 渐隐整个客户端系统提示面板
	_TYPED_EVENT_POP_SYS_TEXT_,                   // 提示系统信息

	_TYPED_EVENT_SHOW_ALERTWINDOW_,               // 显示警告面板
	_TYPED_EVENT_HIDE_ALERTWINDOW_,               // 隐藏警告面板
	_TYPED_EVENT_UPDATE_ALERTWINDOW_,             // 更新警告面板
	_TYPED_EVENT_FADEOUT_ALERTWINDOW_,            // 渐隐警告面板

	_TYPED_EVENT_SHOW_MESSAGEBOXWINDOW_,          // 显示提示面板
	_TYPED_EVENT_HIDE_MESSAGEBOXWINDOW_,          // 隐藏提示面板
	_TYPED_EVENT_UPDATE_MESSAGEBOXWINDOW_,        // 更新提示面板
	_TYPED_EVENT_FADEOUT_MESSAGEBOXWINDOW_,       // 渐隐提示面板

	_TYPED_EVENT_SHOW_LOGOWINDOW_,                // 显示LOGO窗口
	_TYPED_EVENT_HIDE_LOGOWINDOW_,                // 隐藏LOGO窗口
	_TYPED_EVENT_UPDATE_LOGOWINDOW_,              // 更新LOGO窗口
	_TYPED_EVENT_FADEOUT_LOGOWINDOW_,             // 渐隐LOGO窗口

	_TYPED_EVENT_SHOW_SELECTSERVERWINDOW_,        // 显示选择服务器面板
	_TYPED_EVENT_HIDE_SELECTSERVERWINDOW_,        // 隐藏选择服务器面板
	_TYPED_EVENT_UPDATE_SELECTSERVERWINDOW_,      // 更新选择服务器面板
	_TYPED_EVENT_FADEOUT_SELECTSERVERWINDOW_,     // 渐隐更新选择服务器面板

	_TYPED_EVENT_SHOW_LOADINGWINDOW_,             // 显示加载进度条面板
	_TYPED_EVENT_HIDE_LOADINGWINDOW_,             // 隐藏加载进度条面板
	_TYPED_EVENT_UPDATE_LOADINGWINDOW_BAR_,       // 更新加载进度条面板的进度
	_TYPED_EVENT_UPDATE_LOADINGWINDOW_TEXT_,      // 更新加载进度条面板的文字
	_TYPED_EVENT_UPDATE_LOADINGWINDOW_,           // 更新加载进度条面板
	_TYPED_EVENT_FADEOUT_LOADINGWINDOW_,          // 渐隐加载进度条面板

	_TYPED_EVENT_SHOW_LOGINWINDOW_,               // 显示登陆面板
	_TYPED_EVENT_HIDE_LOGINWINDOW_,               // 隐藏登陆面板
	_TYPED_EVENT_UPDATE_LOGINWINDOW_,             // 更新登陆面板
	_TYPED_EVENT_FADEOUT_LOGINWINDOW_,            // 渐隐登陆面板

	_TYPED_EVENT_SHOW_LOBBYWINDOW_,               // 显示大厅窗口
	_TYPED_EVENT_HIDE_LOBBYWINDOW_,               // 隐藏大厅窗口
	_TYPED_EVENT_UPDATE_LOBBYWINDOW_,             // 更新大厅面板
	_TYPED_EVENT_FADEOUT_LOBBYWINDOW_,            // 渐隐大厅面板

	_TYPED_EVENT_SHOW_SELECTBUFFWINDOW_,               // 显示BUFF窗口
	_TYPED_EVENT_HIDE_SELECTBUFFWINDOW_,               // 隐藏BUFF窗口
	_TYPED_EVENT_UPDATE_SELECTBUFFWINDOW_,             // 更新BUFF面板
	_TYPED_EVENT_FADEOUT_SELECTBUFFWINDOW_,            // 渐隐BUFF面板

	_TYPED_EVENT_SHOW_PAUSEWINDOW_,               // 显示暂停窗口
	_TYPED_EVENT_HIDE_PAUSEWINDOW_,               // 隐藏暂停窗口
	_TYPED_EVENT_UPDATE_PAUSEWINDOW_,             // 更新暂停窗口
	_TYPED_EVENT_FADEOUT_PAUSEWINDOW_,            // 渐隐暂停窗口

	_TYPED_EVENT_SHOW_ABOUTWINDOW_,               // 显示关于窗口
	_TYPED_EVENT_HIDE_ABOUTWINDOW_,               // 隐藏关于窗口
	_TYPED_EVENT_UPDATE_ABOUTWINDOW_,             // 更新关于窗口
	_TYPED_EVENT_FADEOUT_ABOUTWINDOW_,            // 渐隐关于窗口

	_TYPED_EVENT_SHOW_ARENAWINDOW_,               // 显示竞技场窗口
	_TYPED_EVENT_HIDE_ARENAWINDOW_,               // 隐藏竞技场窗口
	_TYPED_EVENT_UPDATE_ARENAWINDOW_,             // 更新竞技场界面数值信息
	_TYPED_EVENT_FADEOUT_ARENAWINDOW_,            // 渐隐竞技场窗口

	_TYPED_EVENT_SHOW_ARENARESULTWINDOW_,         // 显示竞技场结果窗口
	_TYPED_EVENT_HIDE_ARENARESULTWINDOW_,         // 隐藏竞技场结果窗口
	_TYPED_EVENT_UPDATE_ARENARESULTWINDOW_,       // 更新竞技场结果窗口
	_TYPED_EVENT_FADEOUT_ARENARESULTWINDOW_,      // 渐隐竞技场结果窗口

	_TYPED_EVENT_SHOW_SYSTEMSETTINGWINDOW_,       // 显示系统设置面板
	_TYPED_EVENT_HIDE_SYSTEMSETTINGWINDOW_,       // 隐藏系统设置面板
	_TYPED_EVENT_UPDATE_SYSTEMSETTINGWINDOW_,     // 更新系统设置面板
	_TYPED_EVENT_FADEOUT_SYSTEMSETTINGWINDOW_,    // 渐隐系统设置面板

	_TYPED_EVENT_SHOW_GUIDEWINDOW_,               // 显示新手引导窗口
	_TYPED_EVENT_HIDE_GUIDEWINDOW_,               // 隐藏新手引导窗口
	_TYPED_EVENT_UPDATE_GUIDEWINDOW_,             // 更新新手引导窗口
	_TYPED_EVENT_FADEOUT_GUIDEWINDOW_,            // 渐隐新手引导窗口
	_TYPED_EVENT_NEXT_GUIDESTEP_,                 // 新手引导下一步

	_TYPED_EVENT_SHOW_SCOREWINDOW_,               // 显示排名信息面板
	_TYPED_EVENT_HIDE_SCOREWINDOW_,               // 隐藏排名信息面板
	_TYPED_EVENT_UPDATE_SCOREWINDOW_,             // 更新排名信息面板
	_TYPED_EVENT_FADEOUT_SCOREWINDOW_,            // 渐隐排名信息面板

	_TYPED_EVENT_SHOW_SHOPWINDOW_,                // 显示商店面板
	_TYPED_EVENT_HIDE_SHOPWINDOW_,                // 隐藏商店面板
	_TYPED_EVENT_UPDATE_SHOPWINDOW_,              // 更新商店面板
	_TYPED_EVENT_FADEOUT_SHOPWINDOW_,             // 渐隐商店面板

	_TYPED_EVENT_SHOW_SETTINGWINDOW_,             // 显示系统设置面板
	_TYPED_EVENT_HIDE_SETTINGWINDOW_,             // 隐藏系统设置面板
	_TYPED_EVENT_UPDATE_SETTINGWINDOW_,           // 更新系统设置面板
	_TYPED_EVENT_FADEOUT_SETTINGWINDOW_,          // 渐隐系统设置面板

	_TYPED_EVENT_SHOW_LOCALIAPWINDOW_,            // 显示本地购买信息面板
	_TYPED_EVENT_HIDE_LOCALIAPWINDOW_,            // 隐藏本地购买信息面板
	_TYPED_EVENT_UPDATE_LOCALIAPWINDOW_,          // 更新本地购买信息面板
	_TYPED_EVENT_FADEOUT_LOCALIAPWINDOW_,         // 渐隐本地购买信息面板

	_TYPED_EVENT_SHOW_REWARDWINDOW_,              // 显示连续登陆奖励窗口
	_TYPED_EVENT_HIDE_REWARDWINDOW_,              // 隐藏连续登陆奖励窗口
	_TYPED_EVENT_UPDATE_REWARDWINDOW_,            // 更新连续登陆奖励窗口
	_TYPED_EVENT_FADEOUT_REWARDWINDOW_,           // 渐隐连续登陆奖励窗口

	_TYPED_EVENT_SHOW_STORYWINDOW_,               // 显示剧情介绍窗口
	_TYPED_EVENT_HIDE_STORYWINDOW_,               // 隐藏剧情介绍窗口
	_TYPED_EVENT_UPDATE_STORYWINDOW_,             // 更新剧情介绍窗口
	_TYPED_EVENT_FADEOUT_STORYWINDOW_,            // 渐隐剧情介绍窗口

	_TYPED_EVENT_SHOW_GAMEOVERWINDOW_,               // 显示GAMEOVER介绍窗口
	_TYPED_EVENT_HIDE_GAMEOVERWINDOW_,               // 隐藏GAMEOVER介绍窗口
	_TYPED_EVENT_UPDATE_GAMEOVERWINDOW_,             // 更新GAMEOVER介绍窗口
	_TYPED_EVENT_FADEOUT_GAMEOVERWINDOW_,            // 渐隐GAMEOVER介绍窗口

	_TYPED_EVENT_UPDATE_UI_TEXT_,                 // 更新UI文字信息
	_TYPED_EVENT_ANDROID_SURFACE_CREATED_,        // 程序进入前台(Android更新描边字专用)

	_TYPED_EVENT_UPDATE_PLAYER_GOLD_,             // 更新玩家金币数量

	_TYPED_EVENT_NUMBER_,                         // 事件类型个数
};


#endif
