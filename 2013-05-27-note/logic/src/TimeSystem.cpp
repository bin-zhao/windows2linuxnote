#include "../include/TimeSystem.h"
#include "../include/LoggerSystem.h"
#include <platform/platform.h>


template<> TimeSystem* cobra_win::Singleton2<TimeSystem>::m_pMySelf = NULL;

TimeSystem::TimeSystem()
{
	m_LastTickTime = 0.0f;
}

TimeSystem::~TimeSystem()
{

}

long long TimeSystem::GetCurrentMicroSecond()
{
	cocos2d::cc_timeval val;
	cocos2d::CCTime::gettimeofdayCocos2d(&val, NULL);

	long long time = val.tv_sec;
	time = time*1000000+val.tv_usec;
	return time;
}

long long TimeSystem::GetCurrentSecond()
{
	cocos2d::cc_timeval val;
	cocos2d::CCTime::gettimeofdayCocos2d(&val, NULL);

	long long time = val.tv_sec;
	return time;
}

float TimeSystem::GetLastTickTime()
{
	return m_LastTickTime;
}

bool  TimeSystem::Init()
{
	LOGGERSYSTEM->LogInfo("Init TimeSystem Success\n");
	return true;
}

void  TimeSystem::Tick(float lastTickTime)
{
	m_LastTickTime = lastTickTime;
}

void  TimeSystem::Destroy()
{
	LOGGERSYSTEM->LogInfo("Destroy TimeSystem Success\n");
}

int TimeSystem::GetIntervalDay(long long start, long long end)
{
	long long startDay = GetDateZeroTime(start);
	long long endDay   = GetDateZeroTime(end);
	if (startDay == endDay)
		return 0;

	long long temp = endDay-startDay;
	temp = temp/(60*60*24);
	return int(temp);
}

struct tm TimeSystem::GetNowDateBySecond(long long sec)
{
	time_t local = sec;
	struct tm* pDate = gmtime(&local);
	return *pDate;
}

long long TimeSystem::GetNowSecondByDate(tm date)
{
	long long time = mktime(&date);
	return time;
}

long long TimeSystem::GetDateZeroTime(long long sec)
{
	time_t local = sec;
	struct tm* pDate = gmtime(&local);

	pDate->tm_hour = 23;
	pDate->tm_min  = 59;
	pDate->tm_sec  = 59;
	return GetNowSecondByDate(*pDate);
}
