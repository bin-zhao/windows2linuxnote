#ifndef  _NINJIATRIBE_SNSSYSTEM_H_
#define  _NINJIATRIBE_SNSSYSTEM_H_


#include <include/common/Singleton.h>
#include <cocos2d.h>
#include <string>
#include <vector>
#include <map>
using  namespace  cobra_win;
using  namespace  std;

class SNSSystem : public cocos2d::CCSNSDelegate, public cobra_win::Singleton2<SNSSystem>
{
public:
	SNSSystem();
	virtual ~SNSSystem();

public:
	/*
		登陆/登出人人
	*/
	void  LoginRenn();
	/*
		登陆/登出微博
	*/
	void  LoginWeibo();
	/*
		登陆/登出QQ
	*/
	void  LoginQQ();
	/*
		登陆/登出Facebook
	*/
	void  LoginFacebook();
	/*
		登陆/登出Twitter
	*/
	void  LoginTwitter();
	/*
		人人分享文字
	*/
	void  ShareTextInRenn();
	/*
		微博分享文字
	*/
	void  ShareTextInWeibo();
	/*
		QQ分享文字
	*/
	void  ShareTextInQQ();
	/*
		Facebook分享文字
	*/
	void  ShareTextInFacebook();
	/*
		Twitter分享文字
	*/
	void  ShareTextInTwitter();
	/*
		人人拍照并分享图片
	*/
	void  SharePictureInRenn(std::string filename);
	/*
		微博拍照并分享图片
	*/
	void  SharePictureInWeibo(std::string filename);
	/*
		QQ拍照并分享图片
	*/
	void  SharePictureInQQ(std::string filename);
	/*
		Facebook拍照并分享图片
	*/
	void  SharePictureInFacebook(std::string filename);
	/*
		Twitter拍照并分享图片
	*/
	void  SharePictureInTwitter(std::string filename);

public:
	/*
		初始化SNS系统管理器
	*/
	bool  Init();
	/*
		SNS系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁SNS系统管理器
	*/
	void  Destroy();

public:
	virtual  void  onLoginRennSuccess();
	virtual  void  onLoginRennFailed(std::string error);
	virtual  void  onShareTextInRennSuccess();
	virtual  void  onShareTextInRennFailed(std::string error);
	virtual  void  onSharePictureInRennSuccess();
	virtual  void  onSharePictureInRennFailed(std::string error);

public:
	virtual  void  onLoginWeiboSuccess();
	virtual  void  onLoginWeiboFailed(std::string error);
	virtual  void  onShareTextInWeiboSuccess();
	virtual  void  onShareTextInWeiboFailed(std::string error);
	virtual  void  onSharePictureInWeiboSuccess();
	virtual  void  onSharePictureInWeiboFailed(std::string error);

public:
	virtual  void  onLoginQQSuccess();
	virtual  void  onLoginQQFailed(std::string error);
	virtual  void  onShareTextInQQSuccess();
	virtual  void  onShareTextInQQFailed(std::string error);
	virtual  void  onSharePictureInQQSuccess();
	virtual  void  onSharePictureInQQFailed(std::string error);

public:
	virtual  void  onLoginFacebookSuccess();
	virtual  void  onLoginFacebookFailed(std::string error);
	virtual  void  onShareTextInFacebookSuccess();
	virtual  void  onShareTextInFacebookFailed(std::string error);
	virtual  void  onSharePictureInFacebookSuccess();
	virtual  void  onSharePictureInFacebookFailed(std::string error);

public:
	virtual  void  onLoginTwitterSuccess();
	virtual  void  onLoginTwitterFailed(std::string error);
	virtual  void  onShareTextInTwitterSuccess();
	virtual  void  onShareTextInTwitterFailed(std::string error);
	virtual  void  onSharePictureInTwitterSuccess();
	virtual  void  onSharePictureInTwitterFailed(std::string error);

public:
	friend  class  cobra_win::Singleton2<SNSSystem>;
};

#define  SNSSYSTEM  (SNSSystem::get_instance2())


#endif
