#include "../include/IDataManager.h"
#include "../include/EngineSystem.h"
#include "../include/DBSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>


IData::IData()
{

}

IData::~IData()
{

}

IDataManager::IDataManager(bool bLoadFromDB, bool bEncryption)
{
	m_bLoadFromDB = bLoadFromDB;
	m_bEncryption = bEncryption;
}

IDataManager::~IDataManager()
{

}

bool IDataManager::Init()
{
	do 
	{
		if (m_bLoadFromDB)
			if (!LoadFromDB())
				break;
		else
			if (!LoadFromFile())
				break;

		return true;
	} 
	while(false);

	return false;
}

void IDataManager::Tick()
{

}

void IDataManager::Destroy()
{

}

bool IDataManager::LoadFromFile()
{
	char*        pBuffer = NULL;
	unsigned int iLength = 0;
	// 加载文件
	if (!EngineSystem::LoadAppFile((char*)GetName().c_str(), pBuffer, iLength))
		return false;

	// 先进行解密
	if (m_bEncryption)
		DBSYSTEM->XORBuffer((char*)DBSYSTEM->GetEncryptionKey().c_str(), pBuffer, iLength);

	// 构建DPacket解包器
	DPacket packet(pBuffer, iLength+1);

	// 跳过第一行
	char   buffer[10240] = "";
	size_t pos = 0;
	do 
	{
		if (pos == sizeof(buffer))
			return false;

		if (packet.get_read_pos() >= packet.size())
			return false;

		packet.read(buffer+pos, 1);
		if (pos>0 && *(buffer+pos)=='\r')
			break;

		pos++;
	}
	while(true);

	// 逐行读取解析
	do 
	{
		char   buffer[10240] = "";
		size_t num           = 0;
		bool   reset         = false;

		{
			size_t pos = 0;
			do 
			{
				if (pos == sizeof(buffer))
				{
					reset = true;
					break;
				}

				if (packet.get_read_pos() >= packet.size())
					break;

				packet.read(buffer+pos, 1);
				if (pos>0 && *(buffer+pos)=='\n')
				{
					if (*(buffer+pos-1) == '\r')
					{
						*(buffer+pos-1) = '\0';
					}

					*(buffer+pos) = '\0';
					num = pos;
					break;
				}

				pos++;
			}
			while(true);
		}

		if (reset || num<=2)
			break;

		if (!LoadData(buffer, num-1))
			return false;

		;
	}
	while (true);

	delete []pBuffer;
	return true;
}

bool IDataManager::LoadFromDB()
{
	char*        pBuffer = NULL;
	unsigned int iLength = 0;
	// 加载数据库表
	if (!DBSystem::LoadDBTable((char*)GetName().c_str(), pBuffer, iLength))
		return false;

	// 先进行解密
	if (m_bEncryption)
		DBSYSTEM->XORBuffer((char*)DBSYSTEM->GetEncryptionKey().c_str(), pBuffer, iLength);

	// 构建DPacket解包器
	DPacket packet(pBuffer, iLength+1);

	// 跳过第一行
	char   buffer[10240] = "";
	size_t pos = 0;
	do 
	{
		if (pos == sizeof(buffer))
			return false;

		if (packet.get_read_pos() >= packet.size())
			return false;

		packet.read(buffer+pos, 1);
		if (pos>0 && *(buffer+pos)=='\r')
			break;

		pos++;
	}
	while(true);

	// 逐行读取解析
	do 
	{
		char   buffer[10240] = "";
		size_t num           = 0;
		bool   reset         = false;

		{
			size_t pos = 0;
			do 
			{
				if (pos == sizeof(buffer))
				{
					reset = true;
					break;
				}

				if (packet.get_read_pos() >= packet.size())
					break;

				packet.read(buffer+pos, 1);
				if (pos>0 && *(buffer+pos)=='\n')
				{
					if (*(buffer+pos-1) == '\r')
					{
						*(buffer+pos-1) = '\0';
					}

					*(buffer+pos) = '\0';
					num = pos;
					break;
				}

				pos++;
			}
			while(true);
		}

		if (reset || num<=2)
			break;

		if (!LoadData(buffer, num-1))
			return false;

		;
	}
	while (true);

	delete []pBuffer;
	return true;
}
