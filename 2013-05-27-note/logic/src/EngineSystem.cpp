#include "../include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/TimeSystem.h"
#include "../include/VariableSystem.h"
#include "../include/PreLoadResourceDataManager.h"
#include "../include/GuideSystem.h"
#include "../include/SoundSystem.h"
#include <include/common/String.h>
#include <CCDirector.h>
#include <textures/CCTextureCache.h>
#include <cocos2d.h>


template<> EngineSystem* cobra_win::Singleton2<EngineSystem>::m_pMySelf = NULL;

EngineSystem::EngineSystem()
{
	m_pScene = NULL;
}

EngineSystem::~EngineSystem()
{

}

bool EngineSystem::IsAndroid480X800()
{
	if (EngineSystem::GetDeviceType() != EngineSystem::_TYPED_IOS_DEVICE_ANDROID_)
		return false;

	// 设置多分辨率相关的配置信息
	int iWidth  = int(cocos2d::CCDirector::sharedDirector()->getWinSize().width);
	int iHeight = int(cocos2d::CCDirector::sharedDirector()->getWinSize().height);
	if (((iWidth%_ANDROID_800X480_DEVICE_WIDTH_==0)&&(iHeight%_ANDROID_800X480_DEVICE_WIDTH_==0))
		||((iWidth%_ANDROID_800X480_DEVICE_WIDTH_==0)&&(iHeight%_ANDROID_800X480_DEVICE_WIDTH_==0)))
		return true;

	return false;
}

void EngineSystem::ShowFeedbackDialog()
{
	cocos2d::CCDirector::sharedDirector()->getSystem()->showFeedbackDialog();
}

void EngineSystem::ShowAd(bool bShow)
{
	cocos2d::CCDirector::sharedDirector()->getAd()->showAd(bShow);
}

void EngineSystem::showTapjoyOfferWall()
{
	cocos2d::CCDirector::sharedDirector()->getAd()->showTapjoyOfferWall();
}

void EngineSystem::showYoumiOfferWall()
{
	cocos2d::CCDirector::sharedDirector()->getAd()->showYoumiOfferWall();
}

void EngineSystem::showDianjoyOfferWall()
{
	cocos2d::CCDirector::sharedDirector()->getAd()->showDianjoyOfferWall();
}

void EngineSystem::showImmobOfferWall()
{
	cocos2d::CCDirector::sharedDirector()->getAd()->showImmobOfferWall();
}

void EngineSystem::showDomobOfferWall()
{
	cocos2d::CCDirector::sharedDirector()->getAd()->showDomobOfferWall();
}

void EngineSystem::show91OfferWall()
{
	cocos2d::CCDirector::sharedDirector()->getAd()->show91OfferWall();
}

cocos2d::CCScene* EngineSystem::GetScene()
{
	return m_pScene;
}

void EngineSystem::FreeMemory()
{
	// 释放无用的图片资源
	cocos2d::CCTextureCache::sharedTextureCache()->removeUnusedTextures();
}

void EngineSystem::Tick()
{
	//FreeMemory();
}

void EngineSystem::Destroy()
{
	cocos2d::CCDirector::sharedDirector()->registerMenuItemEventCallback(NULL);
	m_pScene = NULL;
	LOGGERSYSTEM->LogInfo("Destroy EngineSystem Success\n");
}

void EngineSystem::InitScene()
{
	m_pScene = cocos2d::CCScene::create();
	cocos2d::CCDirector::sharedDirector()->runWithScene(m_pScene);
}

void EngineSystem::LoadSysResource()
{
	// 预先进行必要的资源加载
	for (unsigned int i=0; i<PreLoadResourceDataManager::get_instance2()->GetPreLoadResourceNumber(); i++)
	{
		PreLoadResourceItemData* pItem = PreLoadResourceDataManager::get_instance2()->GetItemDataByPos(i);
		if (pItem->mType == 0)
		{
			_TRACE_LOADING_PLIST_(pItem->mFileName);
		}
		else if (pItem->mType == 1)
		{
			_TRACE_LOADING_IMAGE_(pItem->mFileName);
		}
	}
}

void EngineSystem::OnEngineMenuItemCallbackEventHandler(std::string eventName, std::string menuItemName)
{
	// 回调给音效系统管理器
	SoundSystem::OnMenuItemCallbackEventHandler(eventName, menuItemName);
	// 回调给新手引导层处理
	GuideSystem::OnMenuItemCallbackEventHandler(eventName, menuItemName);
}
