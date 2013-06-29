#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include "../include/LoggerSystem.h"
#include <include/common/FileLoader.h>
#include <include/common/MD5Crypto.h>
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)


bool DBSystem::LoadDBFile()
{
	do 
	{
		char*        pBuffer = NULL;
		unsigned int iLength = 0;
		if (!EngineSystem::LoadAppFile("resource/data/game.data", pBuffer, iLength))
		{
			LOGGERSYSTEM->LogFatal("Init DBSystem Failed, DB Data Invalid\n");
			return false;
		}

		std::string buffer = "";
		if (EngineSystem::IsAndroid480X800())
		{
			buffer = "d42fcd0a5e6145fd988b55dc0570bb82";
		}
		else
		{
			buffer = "3ecae97470b968ec37bb640246a425e9";
		}

		// 进行静态数据md5码校验
		std::string md5Key = MD5Crypto::md5(pBuffer, iLength);
		if (md5Key.compare(buffer) != 0)
		{
			delete []pBuffer;
			LOGGERSYSTEM->LogFatal("Init DBSystem Failed, DB Data Invalid2\n");
			return false;
		}

		// 保存到SD卡对应目录下面
		std::string dbFile = EngineSystem::GetDocumentDir()+"game.db";
		FileLoader loader;
		if (!loader.load((char*)dbFile.c_str(), FileLoader::_TYPED_CLEAR_WRITE_))
		{
			loader.unload();
			delete []pBuffer;
			return false;
		}

		loader.write(pBuffer, iLength);
		loader.unload();
		delete []pBuffer;

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
