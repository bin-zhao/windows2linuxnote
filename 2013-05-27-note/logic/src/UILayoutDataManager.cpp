#include "../include/UILayoutDataManager.h"
#include "../include/EngineSystem.h"
#include "../include/DBSystem.h"
#include "../include/UIWindowDataManager.h"


UILayoutDataManager::UILayoutDataManager(bool bLoadFromDB, bool bEncryption, int iWindowType) : IDataManager(bLoadFromDB, bEncryption)
{
	m_iWindowType = iWindowType;
	m_pLayoutText = NULL;
}

UILayoutDataManager::~UILayoutDataManager()
{

}

int UILayoutDataManager::GetWindowType()
{	
	return m_iWindowType;
}

char*  UILayoutDataManager::GetLayoutText()
{
	return m_pLayoutText;
}

std::string UILayoutDataManager::GetName()
{
	UIWindowItemData* pWindow = UIWindowDataManager::get_instance2()->GetWindowByType(m_iWindowType);
	assert(pWindow != NULL);

	if (EngineSystem::GetDeviceType() == EngineSystem::_TYPED_IOS_DEVICE_ANDROID_)
	{
		if (!m_bLoadFromDB)
			return pWindow->mAndroidLayoutName;

		return pWindow->mAndroidEncryptedLayoutName;
	}
	else if (EngineSystem::GetDeviceType() == EngineSystem::_TYPED_IOS_DEVICE_IPHONE_)
	{
		if (!m_bLoadFromDB)
			return pWindow->mIphoneLayoutName;

		return pWindow->mIphoneEncryptedLayoutName;
	}
	else if (EngineSystem::GetDeviceType() == EngineSystem::_TYPED_IOS_DEVICE_IPAD_)
	{
		if (!m_bLoadFromDB)
			return pWindow->mIpadLayoutName;

		return pWindow->mIpadEncryptedLayoutName;
	}

	return "";
}

unsigned int UILayoutDataManager::GetSize()
{
	return strlen(m_pLayoutText);
}

bool  UILayoutDataManager::Varify(IData* pData)
{
	return true;
}

bool  UILayoutDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool UILayoutDataManager::Init()
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

void UILayoutDataManager::Tick()
{

}

void UILayoutDataManager::Destroy()
{
	if (m_pLayoutText != NULL)
	{
		delete []m_pLayoutText;
		m_pLayoutText = NULL;
	}
}

bool UILayoutDataManager::LoadFromFile()
{
	unsigned int iLength = 0;
	if (!EngineSystem::LoadAppFile((char*)GetName().c_str(), m_pLayoutText, iLength))
		return false;

	// 先进行解密
	if (m_bEncryption)
		DBSYSTEM->XORBuffer((char*)DBSYSTEM->GetEncryptionKey().c_str(), m_pLayoutText, iLength);

	return true;
}

bool UILayoutDataManager::LoadFromDB()
{
	unsigned int iLength = 0;
	if (!DBSystem::LoadDBTable((char*)GetName().c_str(), m_pLayoutText, iLength))
		return false;

	// 先进行解密
	if (m_bEncryption)
		DBSYSTEM->XORBuffer((char*)DBSYSTEM->GetEncryptionKey().c_str(), m_pLayoutText, iLength);

	return true;
}

bool UILayoutDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	return true;
}
