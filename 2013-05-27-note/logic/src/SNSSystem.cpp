#include "../include/SNSSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/VariableSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/SoundSystem.h"
#include "../include/SysLangDataManager.h"
#include <cocos2d.h>


template<> SNSSystem* cobra_win::Singleton2<SNSSystem>::m_pMySelf = NULL;

SNSSystem::SNSSystem()
{
	
}

SNSSystem::~SNSSystem()
{

}

bool SNSSystem::Init()
{
	//  注册SNS回调处理
	cocos2d::CCSNSDelegate* pDelegate = dynamic_cast<cocos2d::CCSNSDelegate*>(this);
	cocos2d::CCDirector::sharedDirector()->getSNS()->setDelegate(pDelegate);

	LOGGERSYSTEM->LogInfo("Init SNSSystem Success\n");
	return true;
}

void SNSSystem::Tick()
{

}

void SNSSystem::Destroy()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->setDelegate(NULL);

	LOGGERSYSTEM->LogInfo("Destroy SNSSystem Success\n");
}

void SNSSystem::LoginRenn()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->loginRenn();
}

void SNSSystem::LoginWeibo()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->loginWeibo();
}

void SNSSystem::LoginQQ()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->loginQQ();
}

void SNSSystem::LoginFacebook()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->loginFacebook();
}

void SNSSystem::LoginTwitter()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->loginTwitter();
}

void SNSSystem::ShareTextInRenn()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->shareTextInRenn("hello world");
}

void SNSSystem::ShareTextInWeibo()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->shareTextInWeibo("hello world");
}

void SNSSystem::ShareTextInQQ()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->shareTextInQQ("hello world");
}

void SNSSystem::ShareTextInFacebook()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->shareTextInFacebook("hello world");
}

void SNSSystem::ShareTextInTwitter()
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->shareTextInTwitter("hello world");
}

void SNSSystem::SharePictureInRenn(std::string filename)
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->sharePictureInRenn(filename, "hello world");
}

void SNSSystem::SharePictureInWeibo(std::string filename)
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->sharePictureInWeibo(filename, "hello world");
}

void SNSSystem::SharePictureInQQ(std::string filename)
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->sharePictureInQQ(filename, "hello world");
}

void SNSSystem::SharePictureInFacebook(std::string filename)
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->sharePictureInFacebook(filename, "hello world");
}

void SNSSystem::SharePictureInTwitter(std::string filename)
{
	cocos2d::CCDirector::sharedDirector()->getSNS()->sharePictureInTwitter(filename, "hello world");
}

void SNSSystem::onLoginRennSuccess()
{

}

void SNSSystem::onLoginRennFailed(std::string error)
{

}

void SNSSystem::onShareTextInRennSuccess()
{

}

void SNSSystem::onShareTextInRennFailed(std::string error)
{

}

void SNSSystem::onSharePictureInRennSuccess()
{

}

void SNSSystem::onSharePictureInRennFailed(std::string error)
{

}

void SNSSystem::onLoginWeiboSuccess()
{

}

void SNSSystem::onLoginWeiboFailed(std::string error)
{

}

void SNSSystem::onShareTextInWeiboSuccess()
{

}

void SNSSystem::onShareTextInWeiboFailed(std::string error)
{

}

void SNSSystem::onSharePictureInWeiboSuccess()
{

}

void SNSSystem::onSharePictureInWeiboFailed(std::string error)
{

}

void SNSSystem::onLoginQQSuccess()
{

}

void SNSSystem::onLoginQQFailed(std::string error)
{

}

void SNSSystem::onShareTextInQQSuccess()
{

}

void SNSSystem::onShareTextInQQFailed(std::string error)
{

}

void SNSSystem::onSharePictureInQQSuccess()
{

}

void SNSSystem::onSharePictureInQQFailed(std::string error)
{

}

void SNSSystem::onLoginFacebookSuccess()
{

}

void SNSSystem::onLoginFacebookFailed(std::string error)
{

}

void SNSSystem::onShareTextInFacebookSuccess()
{

}

void SNSSystem::onShareTextInFacebookFailed(std::string error)
{

}

void SNSSystem::onSharePictureInFacebookSuccess()
{

}

void SNSSystem::onSharePictureInFacebookFailed(std::string error)
{

}


void SNSSystem::onLoginTwitterSuccess()
{

}

void SNSSystem::onLoginTwitterFailed(std::string error)
{

}

void SNSSystem::onShareTextInTwitterSuccess()
{

}

void SNSSystem::onShareTextInTwitterFailed(std::string error)
{

}

void SNSSystem::onSharePictureInTwitterSuccess()
{

}

void SNSSystem::onSharePictureInTwitterFailed(std::string error)
{

}
