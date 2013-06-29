#include "../include/LocalNotificationDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>


LocalNotificationItemData::LocalNotificationItemData()
{
	mNotifyType = -1;
	mNotifyIntervalDay = 0;
	mNotifyIntervalHour = 0;
	mNotifyIntervalMinite = 0;
	memset(mNotifyTextCN, 0, sizeof(mNotifyTextCN));
	memset(mNotifyTextEN, 0, sizeof(mNotifyTextEN));
}

LocalNotificationItemData::~LocalNotificationItemData()
{

}

bool LocalNotificationItemData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	// 解析字符串
	Parser parser(pBuffer, iLen, '\t');

	int id = 0;
	if (!parser.parser_int_value(id))
		return false;

	if (!parser.parser_int_value(mNotifyType))
		return false;

	if (!parser.parser_int_value(mNotifyIntervalDay))
		return false;

	if (!parser.parser_int_value(mNotifyIntervalHour))
		return false;

	if (!parser.parser_int_value(mNotifyIntervalMinite))
		return false;

	if (!parser.parser_string_value(mNotifyTextCN, sizeof(mNotifyTextCN)))
		return false;

	if (!parser.parser_string_value(mNotifyTextEN, sizeof(mNotifyTextEN)))
		return false;

	return true;
}

template<> LocalNotificationDataManager* cobra_win::Singleton2<LocalNotificationDataManager>::m_pMySelf = NULL;

LocalNotificationDataManager::LocalNotificationDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_LocalNotifyList.clear();
}

LocalNotificationDataManager::~LocalNotificationDataManager()
{

}

unsigned int LocalNotificationDataManager::GetLocalNotifyNumber()
{
	return m_LocalNotifyList.size();
}

LocalNotificationItemData* LocalNotificationDataManager::GetLocalNotifyByPos(unsigned int pos)
{
	assert(pos < m_LocalNotifyList.size());

	std::list<LocalNotificationItemData*>::iterator iter = m_LocalNotifyList.begin();
	for (unsigned int i=0; i<m_LocalNotifyList.size(); i++, ++iter)
	{
		if (i == pos)
		{
			return (*iter);
		}
	}

	return NULL;
}

std::string LocalNotificationDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/localnotify.txt";

	return "localnotify";
}

unsigned  int LocalNotificationDataManager::GetSize()
{
	return m_LocalNotifyList.size()*sizeof(LocalNotificationItemData);
}

bool  LocalNotificationDataManager::Init()
{
	do 
	{
		if (m_bLoadFromDB)
		{
			if (!LoadFromDB())
				break;
		}
		else
		{
			if (!LoadFromFile())
				break;
		}

		return true;
	} 
	while(false);

	return false;
}

void  LocalNotificationDataManager::Tick()
{

}

void  LocalNotificationDataManager::Destroy()
{
	std::list<LocalNotificationItemData*>::iterator iter   = m_LocalNotifyList.begin();
	std::list<LocalNotificationItemData*>::iterator iter_e = m_LocalNotifyList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete (*iter);
	}
	m_LocalNotifyList.clear();
}

bool  LocalNotificationDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	LocalNotificationItemData* pNotifyItem = (LocalNotificationItemData*)pData;
	assert(pNotifyItem != NULL);

	return true;
}

bool  LocalNotificationDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  LocalNotificationDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	LocalNotificationItemData* pItemData = new LocalNotificationItemData;
	if (!pItemData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pItemData))
		return false;

	m_LocalNotifyList.push_back(pItemData);
	return true;
}
