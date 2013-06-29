#ifndef  _NINJIATRIBE_TIMESYSTEM_H_
#define  _NINJIATRIBE_TIMESYSTEM_H_


#include <include/common/Singleton.h>
#include <cocos2d.h>
using  namespace  cobra_win;

// PLIST资源加载耗时统计
#define  _TRACE_LOADING_PLIST_(PLIST) \
{ \
	long long start = TIMESYSTEM->GetCurrentMicroSecond(); \
	\
	cocos2d::CCSpriteFrameCache* pFrameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache(); \
	pFrameCache->addSpriteFramesWithFile(PLIST); \
	\
	long long end = TIMESYSTEM->GetCurrentMicroSecond();\
	\
	LOGGERSYSTEM->LogTrace("Resource:loading %s, time=%f\n", PLIST, (float)(end-start)/1000000.0f); \
}

// PLIST资源卸载耗时统计
#define  _TRACE_UNLOAD_PLIST_(PLIST) \
{ \
	long long start = TIMESYSTEM->GetCurrentMicroSecond(); \
	\
	cocos2d::CCSpriteFrameCache* pFrameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache(); \
	pFrameCache->removeSpriteFramesFromFile(PLIST); \
	\
	long long end = TIMESYSTEM->GetCurrentMicroSecond();\
	\
	LOGGERSYSTEM->LogTrace("Resource:unload %s, time=%f\n", PLIST, (float)(end-start)/1000000.0f); \
}

// IMAGE资源加载耗时统计
#define  _TRACE_LOADING_IMAGE_(IMAGE) \
{ \
	long long start = TIMESYSTEM->GetCurrentMicroSecond(); \
	\
	cocos2d::CCTextureCache* pTextureCache = cocos2d::CCTextureCache::sharedTextureCache(); \
	pTextureCache->addImage(IMAGE); \
	\
	long long end = TIMESYSTEM->GetCurrentMicroSecond();\
	\
	LOGGERSYSTEM->LogTrace("Resource:loading %s, time=%f\n", IMAGE, (float)(end-start)/1000000.0f); \
}

class TimeSystem : public cobra_win::Singleton2<TimeSystem>
{
private:
	float  m_LastTickTime; // 上一帧耗时

public:
	TimeSystem();
	virtual ~TimeSystem();

public:
	/*
		得到上一桢耗时
	*/
	float GetLastTickTime();

public:
	/*
		初始化时间系统管理器
	*/
	bool  Init();
	/*
		时间系统逻辑桢更新
	*/
	void  Tick(float lastTickTime);
	/*
		时间网络系统管理器
	*/
	void  Destroy();

public:
	/*
		得到当前时间(精确到微秒)
	*/
	static long long GetCurrentMicroSecond();
	/*
		得到当前时间(精确到秒)
	*/
	static long long GetCurrentSecond();

public:
	/*
		得到两个时间相隔的天数
	*/
	static int GetIntervalDay(long long start, long long end);

public:
	/*
		获得当前秒数对应的具体时间
	*/
	static struct tm GetNowDateBySecond(long long sec);
	/*
		获得当前具体时间对应的秒数
	*/
	static long long GetNowSecondByDate(tm time);
	/*
		得到指定时间对应凌晨时的时间
	*/
	static long long GetDateZeroTime(long long sec);

public:
	friend  class  cobra_win::Singleton2<TimeSystem>;
};

#define  TIMESYSTEM  (TimeSystem::get_instance2())


#endif
