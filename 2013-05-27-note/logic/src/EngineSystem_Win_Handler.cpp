#include "../include/EngineSystem.h"
#include "../include/VariableSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/NinjiaTribeApp.h"
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include <io.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>

std::string EngineSystem::GetDocumentDir()
{
	return "./";
}

std::string EngineSystem::GetAppFilePath(std::string fileName)
{
	return "./"+fileName;
}

int EngineSystem::GetDeviceType()
{
	return _TYPED_IOS_DEVICE_IPHONE_;
	//return _TYPED_IOS_DEVICE_IPAD_;
}

bool EngineSystem::IsSupportRetina()
{
	return false;
}

bool EngineSystem::IsIPad1()
{
	return false;
}

bool EngineSystem::IsShowOffers()
{
	return true;
}

void EngineSystem::EnableMultiTouch(bool bEnabled)
{

}

void EngineSystem::OpenURL(char* pBuffer)
{

}

bool EngineSystem::ScreenShot(std::string filename)
{
	return true;
}

void EngineSystem::UpdateNewVersionDialog(std::string title, std::string yes, std::string cancel)
{

}

bool EngineSystem::Init()
{
	do
	{
		// 是否显示帧率
		bool bShowFPS = false;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "ShowFPS", bShowFPS);
		bool bResourceEncryptioned = true;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "ResourceEncryptioned", bResourceEncryptioned);

		// 创建游戏导演类，并进行参数设计
		// 初始化全局的字体，字体大小等信息
		cocos2d::CCDirector* pDirector = cocos2d::CCDirector::sharedDirector();
		pDirector->setResEncryptioned(bResourceEncryptioned);
		pDirector->setResEncryptionedKey("com.cyou.mrd.yaojiimage87564");
		pDirector->setDefaultFontName("Heiti SC");
		pDirector->setDefaultMenuItemFontName("Heiti SC");
		pDirector->setDisplayStats(bShowFPS);
		pDirector->setAnimationInterval(1.0f/NinjiaTribeApp::get_instance2()->GetFPS());
		pDirector->setDefaultFontSize(20);
		pDirector->setDefaultMenuItemFontSize(22);
		pDirector->setProjection(cocos2d::kCCDirectorProjection2D);
		pDirector->registerMenuItemEventCallback(OnEngineMenuItemCallbackEventHandler);

		// 初始化场景对象
		InitScene();
		LoadSysResource();

		// 设置所有动画Sprite播放间隔
		float interval = 0.3f;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "AnimationSpritePlayInterval", interval);
		pDirector->setAnimationSpritePlayInterval(interval);

		LOGGERSYSTEM->LogInfo("Init EngineSystem Success\n");
		return true;
	}
	while (false);

	LOGGERSYSTEM->LogFatal("Init EngineSystem Failed!!!\n");
	return false;
}

void EngineSystem::InitAppEnv()
{
	// 初始化窗口大小
	if (_TYPED_IOS_DEVICE_IPHONE_ == GetDeviceType())
	{
		cocos2d::CCEGLView::sharedOpenGLView()->setFrameSize(_IOS_IPHONE_DEVICE_WIDTH_, _IOS_IPHONE_DEVICE_HEIGHT_);
	}
	else if (_TYPED_IOS_DEVICE_IPAD_ == GetDeviceType())
	{
		cocos2d::CCEGLView::sharedOpenGLView()->setFrameSize(_IOS_IPAD_DEVICE_WIDTH_, _IOS_IPAD_DEVICE_HEIGHT_);
	}
	else if (_TYPED_IOS_DEVICE_ANDROID_ == GetDeviceType())
	{
		cocos2d::CCEGLView::sharedOpenGLView()->setFrameSize(_ANDROID_800X480_DEVICE_WIDTH_, _ANDROID_800X480_DEVICE_WIDTH_);
	}

	// 创建游戏导演类
	cocos2d::CCDirector* pDirector = cocos2d::CCDirector::sharedDirector();
	pDirector->setOpenGLView(cocos2d::CCEGLView::sharedOpenGLView());

	// 设置多分辨率相关的配置信息
	if (_TYPED_IOS_DEVICE_IPHONE_ == GetDeviceType())
	{
		cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(_IOS_IPHONE_DEVICE_WIDTH_, _IOS_IPHONE_DEVICE_HEIGHT_, kResolutionShowAll);
	}
	else if (_TYPED_IOS_DEVICE_IPAD_ == GetDeviceType())
	{
		cocos2d::CCFileUtils::sharedFileUtils()->setResourceDirectory("ipad");
		cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(_IOS_IPAD_DEVICE_WIDTH_, _IOS_IPAD_DEVICE_HEIGHT_, kResolutionShowAll);
	}
	else if (_TYPED_IOS_DEVICE_ANDROID_ == GetDeviceType())
	{
		// 设置多分辨率相关的配置信息
		int iWidth  = cocos2d::CCDirector::sharedDirector()->getWinSize().width;
		int iHeight = cocos2d::CCDirector::sharedDirector()->getWinSize().height;
		int temp = int(float(iWidth)*480.0f/iHeight);
		if (abs(temp-720) <= abs(temp-800))
		{
			cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(_ANDROID_480X320_DEVICE_WIDTH_, _ANDROID_480X320_DEVICE_HEIGHT_, kResolutionShowAll);
		}
		else
		{
			cocos2d::CCFileUtils::sharedFileUtils()->setResourceDirectory("480X800/");
			cocos2d::CCEGLView::sharedOpenGLView()->setDesignResolutionSize(_ANDROID_800X480_DEVICE_WIDTH_, _ANDROID_800X480_DEVICE_HEIGHT_, kResolutionShowAll);
		}
	}
}

bool EngineSystem::LoadAppFile(char* pFileName, char*& pBuffer, unsigned int& iLength)
{
	assert(pFileName != NULL);
	assert(strlen(pFileName) > 0);

	std::string filepath = EngineSystem::GetDocumentDir();
	filepath += pFileName;

	unsigned long iTemp = 0;
	unsigned char* pTemp = cocos2d::CCFileUtils::sharedFileUtils()->getFileData((char*)filepath.c_str(), "rb", &iTemp);
	if (iTemp==0 || pTemp==NULL)
		return false;

	pBuffer = (char*)pTemp;
	iLength = (unsigned int)iTemp;

	return true;
}

bool EngineSystem::LoadTempFile(char* pFileName, char*& pBuffer, unsigned int& iLength)
{
	assert(pFileName != NULL);
	assert(strlen(pFileName) > 0);

	std::string filepath = EngineSystem::GetDocumentDir();
	filepath += pFileName;

	FileLoader loader;
	if (!loader.load((char*)filepath.c_str(), FileLoader::_TYPED_READ_ONLY_))
		return false;

	// 读取文件内容
	iLength = loader.length();
	pBuffer = new char[iLength+1];
	memset(pBuffer, 0, iLength+1);
	loader.read(pBuffer, iLength);
	loader.unload();

	return true;
}



#endif
