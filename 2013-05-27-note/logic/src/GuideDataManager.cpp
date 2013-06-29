#include "../include/GuideDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>
#include <vector>


GuideItemData::GuideItemData()
{
	mGuideType      = 0;
	mGuideIndex     = 0;
	mMaskRedColor   = 0;
	mMaskGreenColor = 0;
	mMaskBlueColor  = 0;
	mMaskAlphaColor = 0;
	mMaskStartXPos  = 0.0f;
	mMaskStartYPos  = 0.0f;
	mMaskEndXPos    = 0.0f;
	mMaskEndYPos    = 0.0f;
	mArrowXPos      = 0.0f;
	mArrowYPos      = 0.0f;
	mArrowRotation  = 0.0f;
	mGuideXPos      = 0.0f;
	mGuideYPos      = 0.0f;
	mShowGuide               = false;
	mClickAnyWhereToNextStep = false;
	mClickButtonToNextStep   = false;
	mShowGuideArrow          = false;
	memset(mButtonEventName, 0, sizeof(mButtonEventName));
	memset(mButtonName, 0, sizeof(mButtonName));
	memset(mArrowImageName, 0, sizeof(mArrowImageName));
	memset(mGuideImageName, 0, sizeof(mGuideImageName));
	memset(mGuideTextCn, 0, sizeof(mGuideTextCn));
	memset(mGuideTextEn, 0, sizeof(mGuideTextEn));
}

GuideItemData::~GuideItemData()
{

}

bool GuideItemData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	// 解析字符串
	Parser parser(pBuffer, iLen, '\t');

	int id = 0;
	if (!parser.parser_int_value(id))
		return false;

	if (!parser.parser_int_value(mGuideType))
		return false;

	if (!parser.parser_int_value(mGuideIndex))
		return false;

	if (!parser.parser_int_value(mMaskRedColor))
		return false;

	if (!parser.parser_int_value(mMaskGreenColor))
		return false;

	if (!parser.parser_int_value(mMaskBlueColor))
		return false;

	if (!parser.parser_int_value(mMaskAlphaColor))
		return false;

	if (!parser.parser_float_value(mMaskStartXPos))
		return false;

	if (!parser.parser_float_value(mMaskStartYPos))
		return false;

	if (!parser.parser_float_value(mMaskEndXPos))
		return false;

	if (!parser.parser_float_value(mMaskEndYPos))
		return false;

	if (!parser.parser_bool_value(mClickAnyWhereToNextStep))
		return false;

	if (!parser.parser_bool_value(mClickButtonToNextStep))
		return false;

	return true;
}

template<> GuideDataManager* cobra_win::Singleton2<GuideDataManager>::m_pMySelf = NULL;

GuideDataManager::GuideDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_GuideStepList.clear();
}	

GuideDataManager::~GuideDataManager()
{

}

int GuideDataManager::GetGuideStepNumberByType(int guideType)
{
	int count = 0;
	std::list<GuideItemData*>::iterator iter   = m_GuideStepList.begin();
	std::list<GuideItemData*>::iterator iter_e = m_GuideStepList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if ((*iter)->mGuideType == guideType)
			count++;
	}

	return count;
}

GuideItemData* GuideDataManager::GetGuideStepInfoByIndex(int guideType, int guideIdx)
{
	std::vector<GuideItemData*> temp;
	std::list<GuideItemData*>::iterator iter   = m_GuideStepList.begin();
	std::list<GuideItemData*>::iterator iter_e = m_GuideStepList.end();
	for (; iter!=iter_e; ++iter)
	{
		if ((*iter)->mGuideType==guideType)
			temp.push_back((*iter));
	}

	if (temp.size() <= (unsigned int)guideIdx)
		return NULL;

	return temp[guideIdx];
}

std::string GuideDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/guide.txt";

	return "guide";
}

unsigned  int GuideDataManager::GetSize()
{
	return m_GuideStepList.size()*sizeof(GuideItemData);
}

bool  GuideDataManager::Init()
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

void  GuideDataManager::Tick()
{

}

void  GuideDataManager::Destroy()
{
	std::list<GuideItemData*>::iterator iter   = m_GuideStepList.begin();
	std::list<GuideItemData*>::iterator iter_e = m_GuideStepList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete (*iter);
	}
	m_GuideStepList.clear();
}

bool  GuideDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	GuideItemData* pButtonItem = (GuideItemData*)pData;
	assert(pButtonItem != NULL);

	if (pButtonItem->mButtonName[0] == '\0')
		return false;

	return true;
}

bool  GuideDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  GuideDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	GuideItemData* pItemData = new GuideItemData;
	if (!pItemData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pItemData))
		return false;

	m_GuideStepList.push_back(pItemData);
	return true;
}
