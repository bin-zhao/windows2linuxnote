#include "../include/EngineSystem.h"
#include "../include/VariableSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/NinjiaTribeApp.h"
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)


#include <EAGLView.h>
#include <Foundation/NSFileManager.h>
#include <UIKit/UIKit.h>


std::string EngineSystem::GetDocumentDir()
{
	NSArray* pPathArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSAllDomainsMask, YES);
	if ([pPathArray count] <= 0)
		return "";

	NSString* pDocumentPath = [pPathArray objectAtIndex:0];
	const char* pPath = [pDocumentPath UTF8String];
	if (pPath==NULL || strlen(pPath)==0)
		return "";

	if (pPath[strlen(pPath)-1] == '/')
		return pPath;

	char buffer[1024] = "";
	sprintf(buffer, "%s/", pPath);
	return buffer;
}

std::string EngineSystem::GetAppFilePath(std::string fileName)
{
	NSString* pNSFileName = [NSString stringWithCString:fileName.c_str()];
	NSString* pAppDir     = [[NSBundle mainBundle] resourcePath];
	NSString* pFileName   = [pAppDir stringByAppendingPathComponent:pNSFileName];

	return [pFileName UTF8String];
}

int EngineSystem::GetDeviceType()
{
	static int type = _TYPED_IOS_DEVICE_UNKOWN_;
	if (type == _TYPED_IOS_DEVICE_UNKOWN_)
	{
		if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPhone)
		{
			type = _TYPED_IOS_DEVICE_IPHONE_;
		}
		else if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
		{
			type = _TYPED_IOS_DEVICE_IPAD_;
		}
	}

	return type;
}

bool EngineSystem::IsSupportRetina()
{
	return ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640,960), [[UIScreen mainScreen] currentMode].size) : false);
}

bool EngineSystem::IsIPad1()
{
	if ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
	{
		return ![UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera];
	}
	
	return false;
}

bool EngineSystem::IsShowOffers()
{
	return true;
}

void EngineSystem::EnableMultiTouch(bool bEnabled)
{
	if (bEnabled)
	{
		[[EAGLView sharedEGLView] setMultipleTouchEnabled:YES];
	}
	else 
	{
		[[EAGLView sharedEGLView] setMultipleTouchEnabled:NO];
	}
}

void EngineSystem::OpenURL(char* pBuffer)
{
	if (pBuffer==NULL || strlen(pBuffer)==0)
		return;

	NSString* url = [NSString stringWithCString:pBuffer];
	[[UIApplication sharedApplication]openURL:[NSURL URLWithString:url]];
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
}

bool EngineSystem::LoadAppFile(char* pFileName, char*& pBuffer, unsigned int& iLength)
{
	assert(pFileName != NULL);
	assert(strlen(pFileName) > 0);

	FileLoader loader;
	if (!loader.load((char*)(EngineSystem::GetAppFilePath(pFileName)).c_str(), FileLoader::_TYPED_READ_ONLY_))
		return false;

	// 读取文件内容
	iLength = loader.length();
	pBuffer = new char[iLength+1];
	memset(pBuffer, 0, iLength+1);
	loader.read(pBuffer, iLength);
	loader.unload();

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
