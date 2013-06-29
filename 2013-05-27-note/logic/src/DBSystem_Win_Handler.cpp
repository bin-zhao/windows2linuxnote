#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include <include/common/MD5Crypto.h>
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)


bool DBSystem::LoadDBFile()
{
	do 
	{
		std::string dbFile = EngineSystem::GetAppFilePath("resource/data/game.data");

		std::string buffer = "";
		if (EngineSystem::GetDeviceType() == EngineSystem::_TYPED_IOS_DEVICE_ANDROID_)
		{
			if (EngineSystem::IsAndroid480X800())
			{
				buffer = "d42fcd0a5e6145fd988b55dc0570bb82";
			}
			else
			{
				buffer = "3ecae97470b968ec37bb640246a425e9";
			}
		}
		else
		{	
			buffer = "3ecae97470b968ec37bb640246a425e9";
		}

		// 进行静态数据md5码校验
		std::string md5Key = MD5Crypto::md5((char*)dbFile.c_str());
		if (md5Key.compare(buffer) != 0)
		{
			LOGGERSYSTEM->LogFatal("Init DBSystem Failed, DB Data Invalid\n");
			return false;
		}

		int ret = sqlite3_open(dbFile.c_str(), &m_pSQLite);
		if (ret != SQLITE_OK)
		{
			LOGGERSYSTEM->LogFatal("Init DBSystem Failed, DBFile=%s\n", dbFile.c_str());
			return false;
		}

		return true;
	} 
	while(false);

	return false;
}


#endif