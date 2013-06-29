#include "../include/DBSystem.h"
#include "../include/VariableSystem.h"
#include "../include/EngineSystem.h"
#include "../include/IDataManager.h"
#include "../include/LoggerSystem.h"
#include "../include/UILayoutDataManager.h"
#include "../include/PreLoadResourceDataManager.h"
#include "../include/UIWindowDataManager.h"
#include "../include/CommonButtonDataManager.h"
#include "../include/ItemDataManager.h"
#include "../include/AnimationFileDataManager.h"
#include "../include/EffectDataManager.h"
#include "../include/SysLangDataManager.h"
#include "../include/PlayerDataManager.h"
#include "../include/WeaponDataManager.h"

#include "../include/LocalPlayerDataManager.h"


template<> DBSystem* cobra_win::Singleton2<DBSystem>::m_pMySelf = NULL;

DBSystem::DBSystem()
{
	m_pSQLite = NULL;
	m_DataManagerList.clear();
	m_UILayoutDataManagerList.clear();
}

DBSystem::~DBSystem()
{

}

void DBSystem::RegisterDataManager(IDataManager* pDataManager)
{
	assert(pDataManager != NULL);

	m_DataManagerList.push_back(pDataManager);
}

void DBSystem::RegisterUILayoutDataManager(UILayoutDataManager* pDataManager)
{
	assert(pDataManager != NULL);

	m_UILayoutDataManagerList.insert(std::map<int, UILayoutDataManager*>::value_type(pDataManager->GetWindowType(), pDataManager));
}

int DBSystem::GetDBSize()
{
	unsigned int iDBSystemSize = 0;
	std::list<IDataManager*>::iterator iter   = m_DataManagerList.begin();
	std::list<IDataManager*>::iterator iter_e = m_DataManagerList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		iDBSystemSize += (*iter)->GetSize();
	}

	std::map<int, UILayoutDataManager*>::iterator iter2   = m_UILayoutDataManagerList.begin();
	std::map<int, UILayoutDataManager*>::iterator iter2_e = m_UILayoutDataManagerList.end();
	for ( ; iter2!=iter2_e; ++iter2)
	{
		iDBSystemSize += iter2->second->GetSize();
	}

	return iDBSystemSize;
}

sqlite3* DBSystem::GetSQLite()
{
	return m_pSQLite;
}

bool DBSystem::IsNeedVerify()
{
	bool bNeedVerify = true;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "IsDataNeedVerify", bNeedVerify);

	return bNeedVerify;
}

std::string DBSystem::GetEncryptionKey()
{
	char buffer[1024] = "com.cyou.mrd.yaojidata1231";
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "DataEncryptionKey", buffer, sizeof(buffer));

	return buffer;
}

std::string DBSystem::GetLocalDataEncryptionKey()
{
	char buffer[1024] = "&^#*(#*(-%$!^*(-&^%@##$-cyou-inc";
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "LocalDataEncryptionKey", buffer, sizeof(buffer));

	return buffer;
}

UILayoutDataManager* DBSystem::GetUILayoutDataManagerByType(int type)
{
	std::map<int, UILayoutDataManager*>::iterator iter = m_UILayoutDataManagerList.find(type);
	if (iter == m_UILayoutDataManagerList.end())
		return NULL;

	return iter->second;
}

bool DBSystem::Init()
{
	bool bFromDB = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "DataLoadFromDB", bFromDB);
	bool bResourceEncryption = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "DataEncryptioned", bResourceEncryption);
	bool bVarify = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "DataVarifyAfterLoadAll", bVarify);

	// 打开SQLite数据库
	if (bFromDB)
	{
		if (!LoadDBFile())
			return false;
	}

	// 注册数据管理器
	RegisterDataManager(new SysLangDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new UIWindowDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new CommonButtonDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new PreLoadResourceDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new ItemDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new AnimationFileDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new EffectDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new PlayerDataManager(bFromDB, bResourceEncryption));
	RegisterDataManager(new WeaponDataManager(bFromDB, bResourceEncryption));

	// 第二部注册所有的玩家数据，只有静态数据全部初始化完之后，在初始化玩家数据
	// 因为这里面会存在先后的顺序
	RegisterDataManager(new LocalPlayerDataManager(bFromDB, bResourceEncryption));

	// 初始化所有的数据管理器
	unsigned int iDBSystemSize = 0;
	std::list<IDataManager*>::iterator iter   = m_DataManagerList.begin();
	std::list<IDataManager*>::iterator iter_e = m_DataManagerList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if (!(*iter)->Init())
		{
			LOGGERSYSTEM->LogFatal("Init DBSystem Failed, DBTable=%s\n", (*iter)->GetName().c_str());
			return false;
		}

		iDBSystemSize += (*iter)->GetSize();
	}

	// 注册UI布局数据管理器
	for (unsigned int i=0; i<UIWindowDataManager::get_instance2()->GetWindowNumber(); i++)
	{
		UIWindowItemData* pWindowItem = UIWindowDataManager::get_instance2()->GetWindowByPos(i);
		assert(pWindowItem != NULL);

		UILayoutDataManager* pLayout = new UILayoutDataManager(bFromDB, bResourceEncryption, pWindowItem->mWindowType);
		if (!pLayout->Init())
		{
			LOGGERSYSTEM->LogFatal("Init DBSystem Failed, DBTable=%s\n", pLayout->GetName().c_str());
			return false;
		}
		RegisterUILayoutDataManager(pLayout);
	}

	// 释放SQLite数据
	if (m_pSQLite != NULL)
	{
		sqlite3_close(m_pSQLite);
		m_pSQLite = NULL;
	}

	// 所有数据表关联性校验
	if (IsNeedVerify())
	{
		iter   = m_DataManagerList.begin();
		iter_e = m_DataManagerList.end();
		for ( ; bVarify && iter!=iter_e; ++iter)
		{
			if (!(*iter)->VarifyAfterLoadAll())
			{
				LOGGERSYSTEM->LogFatal("Varify DBSystem Failed, DBTable=%s\n", (*iter)->GetName().c_str());
				return false;
			}
		}
	}

	LOGGERSYSTEM->LogInfo("Init DBSystem Success, DBSystemSize=%u\n", iDBSystemSize);

	return true;
}

void DBSystem::Tick()
{
	std::list<IDataManager*>::iterator iter   = m_DataManagerList.begin();
	std::list<IDataManager*>::iterator iter_e = m_DataManagerList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		(*iter)->Tick();
	}
}

void DBSystem::Destroy()
{
	std::list<IDataManager*>::iterator iter   = m_DataManagerList.begin();
	std::list<IDataManager*>::iterator iter_e = m_DataManagerList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		(*iter)->Destroy();
		delete (*iter);
	}
	m_DataManagerList.clear();

	std::map<int, UILayoutDataManager*>::iterator iter2   = m_UILayoutDataManagerList.begin();
	std::map<int, UILayoutDataManager*>::iterator iter2_e = m_UILayoutDataManagerList.end();
	for ( ; iter2!=iter2_e; ++iter2)
	{
		iter2->second->Destroy();
		delete iter2->second;
	}
	m_UILayoutDataManagerList.clear();

	LOGGERSYSTEM->LogInfo("Destroy DBSystem Success\n");
}

char* DBSystem::XORBuffer(char* pKey, char* pBuffer, unsigned int iBufferLen)
{
	assert(pKey != NULL);
	assert(strlen(pKey) > 0);
	assert(pBuffer != NULL);
	assert(iBufferLen > 0);

	// 开始XOR加密解密
	int keyLen = strlen(pKey);
	for (unsigned int i=0; i<iBufferLen; i++)
	{
		char temp = pBuffer[i];
		pBuffer[i] = (char)(temp^pKey[i%keyLen]);
	}

	return pBuffer;
}

bool DBSystem::LoadDBTable(char* pTableName, char*& pBuffer, unsigned int& iLength)
{
	assert(pTableName != NULL);
	assert(strlen(pTableName) > 0);

	sqlite3_stmt* pSTMT  = NULL;
	char*         pError = NULL;

	do 
	{
		char sql[1024] = "";
		sprintf(sql, "select * from %s", pTableName);
		int ret = sqlite3_prepare(DBSYSTEM->GetSQLite(), sql, strlen(sql), &pSTMT, (const char **)&pError);
		if (ret != SQLITE_OK)
			break;

		ret = sqlite3_step(pSTMT);
		if (ret != SQLITE_ROW)
			break;

		char* pText = (char*)sqlite3_column_blob(pSTMT, 0);
		unsigned int iLength = sqlite3_column_bytes(pSTMT, 0);

		pBuffer = new char[iLength+1];
		memset(pBuffer, 0, iLength+1);
		memcpy(pBuffer, pText, iLength);

		sqlite3_finalize(pSTMT);
		return true;
	}
	while (false);

	if (pSTMT != NULL)
	{
		sqlite3_finalize(pSTMT);
		pSTMT = NULL;
	}
	return false;
}
