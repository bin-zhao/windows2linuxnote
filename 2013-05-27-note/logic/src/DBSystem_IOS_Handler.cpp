#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include <include/common/FileLoader.h>
#include <include/common/MD5Crypto.h>
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)


bool DBSystem::LoadDBFile()
{
	do 
	{
		std::string dbFile = EngineSystem::GetAppFilePath("resource/data/game.data");

		// 进行静态数据md5码校验
		char buffer[1024] = "88b6655c42c04ff8f13935d5d73ac6a6";
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
