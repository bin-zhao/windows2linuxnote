#ifndef  _NINJIATRIBE_SYSLANGDATAMANAGER_H_
#define  _NINJIATRIBE_SYSLANGDATAMANAGER_H_


#include <include/common/Singleton.h>
#include "IDataManager.h"
#include <map>

#pragma pack(push, 1)
class SysLangItemData : public IData
{
public:
	int         mLangId;  // 语言Id
	std::string mLangTextCN;// 中文简体语言文字

public:
	SysLangItemData();
	virtual ~SysLangItemData();

public:
	/*
		解析数据
	*/
	virtual  bool  ParseBuffer(char* pBuffer, unsigned int iLen);
};
#pragma pack(pop)


class SysLangDataManager : public IDataManager, public cobra_win::Singleton2<SysLangDataManager>
{
public:
	enum
	{
		_TYPED_SYSLANG_CN_, // 简体中文
		_TYPED_SYSLANG_EN_, // 英文
		_TYPED_SYSLANG_TW_, // 繁体中文
	};

public:
	enum
	{
		_TYPED_SYSLANG_UNKOWN_,                 // 未知的系统信息标示

		_TYPED_SYSLANG_SNS_RENN_LOGIN_SUCCESS_,      // 人人SNS登陆成功消息
		_TYPED_SYSLANG_SNS_RENN_LOGIN_FAILED_,       // 人人SNS登陆失败消息
		_TYPED_SYSLANG_SNS_RENN_SHARE_TEXT_,         // 人人SNS默认分享信息
		_TYPED_SYSLANG_SNS_RENN_SHARE_PICTURETEXT_,  // 人人SNS图片分享信息
		_TYPED_SYSLANG_SNS_RENN_SHARE_SUCCESS_,      // 人人分享成功消息
		_TYPED_SYSLANG_SNS_RENN_SHARE_FAILED_,       // 人人分享失败消息

		_TYPED_SYSLANG_SNS_WEIBO_SHARE_TEXT_,        // 微博SNS默认分享信息
		_TYPED_SYSLANG_SNS_WEIBO_SHARE_PICTURETEXT_, // 微博SNS图片分享信息
		_TYPED_SYSLANG_SNS_WEIBO_LOGIN_SUCCESS_,     // 微博SNS登陆成功消息
		_TYPED_SYSLANG_SNS_WEIBO_LOGIN_FAILED_,      // 微博SNS登陆失败消息
		_TYPED_SYSLANG_SNS_WEIBO_SHARE_SUCCESS_,     // 微博分享成功消息
		_TYPED_SYSLANG_SNS_WEIBO_SHARE_FAILED_,      // 微博分享失败消息

		_TYPED_SYSLANG_SNS_QQ_SHARE_TEXT_,           // 微信SNS默认分享信息
		_TYPED_SYSLANG_SNS_QQ_SHARE_PICTURETEXT_,    // 微信SNS图片分享信息
		_TYPED_SYSLANG_SNS_QQ_LOGIN_SUCCESS_,        // 微信SNS登陆成功消息
		_TYPED_SYSLANG_SNS_QQ_LOGIN_FAILED_,         // 微信SNS登陆失败消息
		_TYPED_SYSLANG_SNS_QQ_SHARE_SUCCESS_,        // 微信分享成功消息
		_TYPED_SYSLANG_SNS_QQ_SHARE_FAILED_,         // 微信分享失败消息

		_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_TEXT_,          // FACEBOOKSNS默认分享信息
		_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_PICTURETEXT_,   // FACEBOOKSNS图片分享信息
		_TYPED_SYSLANG_SNS_FACEBOOK_LOGIN_SUCCESS_,       // FACEBOOKSNS登陆成功消息
		_TYPED_SYSLANG_SNS_FACEBOOK_LOGIN_FAILED_,        // FACEBOOKSNS登陆失败消息
		_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_SUCCESS_,       // FACEBOOK分享成功消息
		_TYPED_SYSLANG_SNS_FACEBOOK_SHARE_FAILED_,        // FACEBOOK分享失败消息

		_TYPED_SYSLANG_SNS_TWITTER_SHARE_TEXT_,           // TWITTERSNS默认分享信息
		_TYPED_SYSLANG_SNS_TWITTER_SHARE_PICTURETEXT_,    // TWITTERSNS图片分享信息
		_TYPED_SYSLANG_SNS_TWITTER_LOGIN_SUCCESS_,        // TWITTERSNS登陆成功消息
		_TYPED_SYSLANG_SNS_TWITTER_LOGIN_FAILED_,         // TWITTERSNS登陆失败消息
		_TYPED_SYSLANG_SNS_TWITTER_SHARE_SUCCESS_,        // TWITTER分享成功消息
		_TYPED_SYSLANG_SNS_TWITTER_SHARE_FAILED_,         // TWITTER分享失败消息

		_TYPED_SYSLANG_GAMECENTER_INVALID_,                       // GameCenter不可用
		_TYPED_SYSLANG_GAMECENTER_AUTH_SUCCESS_,                  // GameCenter验证用户成功
		_TYPED_SYSLANG_GAMECENTER_AUTH_FAILED_,                   // GameCenter验证用户失败
		_TYPED_SYSLANG_GAMECENTER_SHOW_LEADERBOARD_SUCCESS_,      // GameCenter显示排名成功
		_TYPED_SYSLANG_GAMECENTER_SHOW_LEADERBOARD_FAILED_,       // GameCenter显示排名失败
		_TYPED_SYSLANG_GAMECENTER_SHOW_ACHIEVEMENT_SUCCESS_,      // GameCenter显示成就成功
		_TYPED_SYSLANG_GAMECENTER_SHOW_ACHIEVEMENT_FAILED_,       // GameCenter显示成就失败
		_TYPED_SYSLANG_GAMECENTER_REPORT_SCORE_SUCCESS_,          // GameCenter上传分数成功
		_TYPED_SYSLANG_GAMECENTER_REPORT_SCORE_FAILED_,           // GameCenter上传分数失败
		_TYPED_SYSLANG_GAMECENTER_SUBMIT_ACHIEVEMENT_SUCCESS_,    // GameCenter提交成就成功
		_TYPED_SYSLANG_GAMECENTER_SUBMIT_ACHIEVEMENT_FAILED_,     // GameCenter提交成就失败

		_TYPED_SYSLANG_OPEN_MOREGAME_FAILED_, // 打开其他游戏链接失败

		_TYPED_SYSLANG_ESTIMATE_TITLE_,       // 评论标题
		_TYPED_SYSLANG_ESTIMATE_OK_,          // 评论
		_TYPED_SYSLANG_ESTIMATE_NEVER_,       // 不评论
		_TYPED_SYSLANG_ESTIMATE_LATER_,       // 稍后评论

		_TYPED_SYSLANG_RECEIVE_YOUMI_POINTS_,   // 获得YouMi广告墙点数
		_TYPED_SYSLANG_RECEIVE_DIANJOY_POINTS_, // 获得DianJoy广告墙点数
		_TYPED_SYSLANG_RECEIVE_IMMOB_POINTS_,   // 获得力美广告墙点数
		_TYPED_SYSLANG_RECEIVE_TAPJOY_POINTS_,  // 获得Tapjoy广告墙点数
		_TYPED_SYSLANG_RECEIVE_DOMOB_POINTS_,   // 获得多盟广告墙点数
		_TYPED_SYSLANG_RECEIVE_91_POINTS_,      // 获得91广告墙点数

		_TYPED_SYSLANG_NO_NETWORK_, // 操作失败，请检查网络

		_TYPED_SYSLANG_RESULTWINDOW_PREFIX_DESC_TEXT_, // 结果面板前缀描述信息
		_TYPED_SYSLANG_RESULTWINDOW_SUFFIX_DESC_TEXT_, // 结果面板后缀描述信息
		_TYPED_SYSLANG_RESULTWINDOW_RISK_MODE_,        // 结果面板冒险模式描述信息
		_TYPED_SYSLANG_RESULTWINDOW_BOSS_MODE_,        // 结果面板BOSS模式描述信息
	};

protected:
	std::map<int, SysLangItemData*> m_SysLangList;

public:
	SysLangDataManager(bool bLoadFromDB, bool bEncryption);
	virtual ~SysLangDataManager();

public:
	/*
		得到指定Id的文字
	*/
	std::string GetSysLangById(int langId);
	/*
		根据指定的语言类型得到指定Id的文字
	*/
	std::string GetSysLangById(int langId, int langType);

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
	friend   class   cobra_win::Singleton2<SysLangDataManager>;
};


#endif
