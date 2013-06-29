#include "../include/LocalPlayerDataManager.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/EngineSystem.h"
#include "../include/TimeSystem.h"
#include "../include/DBSystem.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include <include/common/FileLoader.h>
#include <include/common/Parser.h>
#include <include/common/File.h>
#include <include/common/String.h>
#include <include/mem/EPacket.h>
#include <include/mem/DPacket.h>
#include <include/common/MD5Crypto.h>
using  namespace  cobra_win;


template<> LocalPlayerDataManager* cobra_win::Singleton2<LocalPlayerDataManager>::m_pMySelf = NULL;

LocalPlayerDataManager::LocalPlayerDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_PlayerLastLogoutTime = 0;

	m_bNeedSaveToDisk = false;

	m_LocalCurrentPlayerId = 0;

	m_LocalRubyNum = 0;

	m_LocalGoldNum = 0;

	m_LocalHeroStateList.clear();

}

LocalPlayerDataManager::~LocalPlayerDataManager()
{

}

void LocalPlayerDataManager::NeedSaveToDisk()
{
	m_bNeedSaveToDisk = true;
}

std::string LocalPlayerDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "localdata";

	return "localdata";
}

std::string LocalPlayerDataManager::GetTempName()
{
	if (!m_bLoadFromDB)
		return "localdatatemp";

	return "localdatatemp";
}

unsigned int LocalPlayerDataManager::GetSize()
{
	return sizeof(LocalPlayerDataManager);
}

void LocalPlayerDataManager::OnSystemEnterBackEventHandler()
{

}

void LocalPlayerDataManager::OnSystemEnterFrontEventHandler()
{

}

void LocalPlayerDataManager::OnSystemPauseEventHandler()
{

}

void LocalPlayerDataManager::OnSystemResumeEventHandler()
{

}

bool LocalPlayerDataManager::Init()
{
	do 
	{
		if (!LoadFromFile())
			break;
		
		//设置默认玩家


		//如果没有默认状态
		if(m_LocalHeroStateList.size()<=0)
		{
			for(int i = 0; i<15;i++)
			{
				_LOCAL_HERO_STATE_ herostate;
				herostate.m_isActive = false;
				herostate.m_Rank = 1;
				herostate.m_KillNum = i*10;
				m_LocalHeroStateList.push_back(herostate);
			}
			NeedSaveToDisk();
		}

		OnSystemResumeEventHandler();		
		return true;
	} 
	while(false);

	return false;
}

void LocalPlayerDataManager::Tick()
{
	if (!m_bNeedSaveToDisk)
		return ;
	
	SaveToFile();
	m_bNeedSaveToDisk = false;
}

void LocalPlayerDataManager::Destroy()
{
	SaveToFile();
}

bool LocalPlayerDataManager::LoadFromFile()
{
	char* pBuffer     = NULL;
	long  iFileLength = 0;

	try
	{
		do 
		{
			std::string filePath = EngineSystem::GetDocumentDir()+GetName();
			pBuffer = LoadDBFile(filePath, iFileLength);
			if (pBuffer != NULL)
				break;

			filePath = EngineSystem::GetDocumentDir()+GetTempName();
			pBuffer = LoadDBFile(filePath, iFileLength);
			if (pBuffer != NULL)
				break;

			return true;
		} 
		while (false);
		
		// 先加载版本信息
		DPacket packet(pBuffer, iFileLength+1);
		int versionLen = 0;
		packet>>versionLen;
		char version[1024] = "";
		packet.read(version, versionLen);
		if (std::string("1.0.1").compare(version) == 0)
		{
			Load101VersionFile(pBuffer+packet.get_read_pos(), iFileLength-packet.get_read_pos());
		}
	}
	catch (...)
	{
		;
	}

	if (pBuffer != NULL)
	{
		delete []pBuffer;
	}
	return true;
}

bool LocalPlayerDataManager::LoadFromDB()
{
	do 
	{
		return true;
	}
	while (false);

	return false;
}

bool LocalPlayerDataManager::Varify(IData* pData)
{
	return true;
}

bool LocalPlayerDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool LocalPlayerDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	return true;
}

char* LocalPlayerDataManager::LoadDBFile(std::string fileName, long& length)
{
	FileLoader loader;
	if (!loader.load((char*)fileName.c_str(), FileLoader::_TYPED_READ_ONLY_))
	{
		loader.unload();
		return NULL;
	}

	length = loader.length();
	if (length <= (sizeof(char)*32+sizeof(int)))
	{
		loader.unload();
		return NULL;
	}
	
	// 读取文件信息
	char* pBuffer = new char[length+1];
	memset(pBuffer, 0, length+1);
	loader.read(pBuffer, length);
	loader.unload();

	// 先进行解密
	DBSYSTEM->XORBuffer((char*)DBSYSTEM->GetLocalDataEncryptionKey().c_str(), pBuffer, length);

	// 判断文件是否完整
	std::string md5Key = MD5Crypto::md5((unsigned char*)pBuffer, length-32);
	if (md5Key.compare(pBuffer+length-32) != 0)
	{
		delete[] pBuffer;
		return NULL;
	}

	return pBuffer;
}

void LocalPlayerDataManager::SaveToFile()
{
	// 设置当前保存的时间
	m_PlayerLastLogoutTime = TimeSystem::GetCurrentMicroSecond();

	// 版本号长度
	int versionLen = NinjiaTribeApp::get_instance2()->GetVersion().length();

	EPacket packet;
	// 插入版本信息
	packet<<versionLen;
	packet.append((char*)NinjiaTribeApp::get_instance2()->GetVersion().c_str(), versionLen);

	// 保存当前时间信息
	packet<<m_PlayerLastLogoutTime;

	// 保存基本信息
	packet<<m_LocalCurrentPlayerId;
	packet<<m_LocalRubyNum;
	packet<<m_LocalGoldNum;
	
	int num = m_LocalHeroStateList.size();
	packet<<num;
	if (num > 0)
	{
		std::list<_LOCAL_HERO_STATE_>::iterator iter   = m_LocalHeroStateList.begin();
		std::list<_LOCAL_HERO_STATE_>::iterator iter_e = m_LocalHeroStateList.end();
		for ( ; iter!=iter_e; ++iter)
		{	
			_LOCAL_HERO_STATE_ temp = (*iter);
			packet.append<_LOCAL_HERO_STATE_>(temp);
		}
	}


	// 增加md5存档校验码
	std::string md5Key = MD5Crypto::md5((unsigned char*)packet.get_packet_buff(), packet.size());
	packet.append((char*)md5Key.c_str(), md5Key.length());

	// 更新备份文件
	try
	{
		do 
		{
			std::string filePath = EngineSystem::GetDocumentDir();
			filePath += GetName();
			FileLoader loader;
			if (!loader.load((char*)filePath.c_str(), FileLoader::_TYPED_READ_ONLY_))
			{
				loader.unload();
				break;
			}

			int fileLength = loader.length();
			char* pBuffer = new char[fileLength+1];
			memset(pBuffer, 0, fileLength+1);
			loader.read(pBuffer, fileLength);
			loader.unload();

			filePath = EngineSystem::GetDocumentDir();
			filePath += GetTempName();
			if (!loader.load((char*)filePath.c_str(), FileLoader::_TYPED_CLEAR_WRITE_))
			{
				loader.unload();
				delete []pBuffer;
				break;
			}

			loader.write(pBuffer, fileLength);
			loader.unload();
			delete []pBuffer;
		}
		while (false);
	}
	catch (...)
	{
		;
	}

	try
	{
		// 先进行解密
		DBSYSTEM->XORBuffer((char*)DBSYSTEM->GetLocalDataEncryptionKey().c_str(), packet.get_packet_buff(), packet.size());

		std::string filePath = EngineSystem::GetDocumentDir();
		filePath += GetName();

		FileLoader loader;
		if (!loader.load((char*)filePath.c_str(), FileLoader::_TYPED_CLEAR_WRITE_))
			return ;

		loader.write(packet.get_packet_buff(), packet.size());
		loader.unload();
	}
	catch (...)
	{
		;
	}
}

void LocalPlayerDataManager::SynToInitialization()
{

}

bool LocalPlayerDataManager::Load101VersionFile(char* pBuffer, unsigned int iBufferLen)
{
	try
	{
		// 创建解包器
		DPacket packet(pBuffer, iBufferLen+1);

		// 加载上次保存的时间信息
		packet>>m_PlayerLastLogoutTime;

		// 加载基本信息
		packet>>m_LocalCurrentPlayerId;
		packet>>m_LocalRubyNum;
		packet>>m_LocalGoldNum;

		// 英雄状态存储
		int num = 0;
		packet>>num;
		for (int i=0; i<num; i++)
		{
			_LOCAL_HERO_STATE_ temp;
			packet.read<_LOCAL_HERO_STATE_>(temp);

			m_LocalHeroStateList.push_back(temp);
		}

	}
	catch (...)
	{
		return false;
	}

	return true;
}

void LocalPlayerDataManager::SetLocalCurrentPlayerId(int playerId)
{
	if(playerId == m_LocalCurrentPlayerId)
		return;
	m_LocalCurrentPlayerId = playerId;
	NeedSaveToDisk();
}

int LocalPlayerDataManager::GetLocalCurrentPlayerId()
{
	return m_LocalCurrentPlayerId;
}

unsigned int LocalPlayerDataManager::GetLocalHeroStateNumber()
{
	return m_LocalHeroStateList.size();
}

LocalPlayerDataManager::_LOCAL_HERO_STATE_* LocalPlayerDataManager::GetLocalHeroStateByPos(unsigned int pos)
{
	assert(pos < m_LocalHeroStateList.size());

	std::list<_LOCAL_HERO_STATE_>::iterator iter   = m_LocalHeroStateList.begin();
	std::list<_LOCAL_HERO_STATE_>::iterator iter_e = m_LocalHeroStateList.end();
	for ( int i=0; iter!=iter_e; ++iter)
	{
		if (i == pos)
		{
			return &(*iter);
		}

		i++;
	}
	return NULL;
}


void LocalPlayerDataManager::SetHeroState_Active(int pos,bool isActive)
{
	assert(pos < m_LocalHeroStateList.size());
	std::list<_LOCAL_HERO_STATE_>::iterator iter   = m_LocalHeroStateList.begin();
	std::list<_LOCAL_HERO_STATE_>::iterator iter_e = m_LocalHeroStateList.end();
	for ( int i=0; iter!=iter_e; ++iter)
	{
		if (i == pos)
		{
			(*iter).m_isActive = isActive;
			NeedSaveToDisk();
			return;
		}
		i++;
	}
}

int LocalPlayerDataManager::getRubyNum()
{
	return m_LocalRubyNum;
}

int LocalPlayerDataManager::getGlodNum()
{
	return m_LocalGoldNum;
}
