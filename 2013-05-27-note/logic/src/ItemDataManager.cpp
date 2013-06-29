#include "../include/ItemDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>


ItemData::ItemData()
{
	mItemType           = 0;
	mItemWidth          = 0.0f;
	mItemHeight         = 0.0f;
	mItemCollisionWidth = 0.0f;
	mItemCollisionHeight= 0.0f;
	mItemAvatarNumber   = 0;
	mItemEffectType     = -1;
	mItemAvatarPlayInterval= 0.0f;
	mItemInitYSpeed       = 0.0f;
	mItemInitMinXSpeed    = 0.0f;
	mItemInitMaxXSpeed    = 0.0f;
	mItemXReduceFactor    = 0.0f;
	mItemYUpReduceFactor  = 0.0f;
	mItemYDownReduceFactor= 0.0f;
	mItemParticleId       = 0;
	mItemAwardScore       = 0;
	mItemAwardGold        = 0;
	mItemCanBeMegneted    = false;
	mItemDropRotation     = 0;
	memset(mItemAvatarName, 0, sizeof(mItemAvatarName));
	memset(mItemSoundName, 0, sizeof(mItemSoundName));
}

ItemData::~ItemData()
{

}

bool ItemData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	// 解析字符串
	Parser parser(pBuffer, iLen, '\t');

	int id = 0;
	if (!parser.parser_int_value(id))
		return false;

	if (!parser.parser_int_value(mItemType))
		return false;

	if (!parser.parser_float_value(mItemWidth))
		return false;

	if (!parser.parser_float_value(mItemHeight))
		return false;

	if (!parser.parser_float_value(mItemCollisionWidth))
		return false;

	if (!parser.parser_float_value(mItemCollisionHeight))
		return false;

	if (!parser.parser_string_value(mItemAvatarName, sizeof(mItemAvatarName)))
		return false;

	if (!parser.parser_int_value(mItemAvatarNumber))
		return false;

	if (!parser.parser_float_value(mItemAvatarPlayInterval))
		return false;

	if (!parser.parser_string_value(mItemSoundName, sizeof(mItemSoundName)))
		return false;

	if (!parser.parser_int_value(mItemEffectType))
		return false;

	if (!parser.parser_float_value(mItemInitYSpeed))
		return false;

	if (!parser.parser_float_value(mItemInitMinXSpeed))
		return false;

	if (!parser.parser_float_value(mItemInitMaxXSpeed))
		return false;

	if (!parser.parser_float_value(mItemXReduceFactor))
		return false;

	if (!parser.parser_float_value(mItemYUpReduceFactor))
		return false;

	if (!parser.parser_float_value(mItemYDownReduceFactor))
		return false;

	if (!parser.parser_int_value(mItemParticleId))
		return false;

	if (!parser.parser_int_value(mItemAwardScore))
		return false;

	if (!parser.parser_int_value(mItemAwardGold))
		return false;

	if (!parser.parser_bool_value(mItemCanBeMegneted))
		return false;

	if (!parser.parser_float_value(mItemDropRotation))
		return false;

	return true;
}

template<> ItemDataManager* cobra_win::Singleton2<ItemDataManager>::m_pMySelf = NULL;

ItemDataManager::ItemDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_ItemList.clear();
}	

ItemDataManager::~ItemDataManager()
{

}

ItemData* ItemDataManager::GetItemByType(int type)
{
	std::map<int, ItemData*>::iterator iter = m_ItemList.find(type);
	if (iter == m_ItemList.end())
		return NULL;

	return iter->second;
}

std::string ItemDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/item.txt";

	return "item";
}

unsigned  int ItemDataManager::GetSize()
{
	return m_ItemList.size()*sizeof(ItemData);
}

bool  ItemDataManager::Init()
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

void  ItemDataManager::Tick()
{

}

void  ItemDataManager::Destroy()
{
	std::map<int, ItemData*>::iterator iter   = m_ItemList.begin();
	std::map<int, ItemData*>::iterator iter_e = m_ItemList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	return m_ItemList.clear();
}

bool  ItemDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	ItemData* pButtonItem = (ItemData*)pData;
	assert(pButtonItem != NULL);

	return true;
}

bool  ItemDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  ItemDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	ItemData* pItemData = new ItemData;
	if (!pItemData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pItemData))
		return false;

	m_ItemList.insert(std::map<int, ItemData*>::value_type(pItemData->mItemType, pItemData));
	return true;
}
