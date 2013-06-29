#include "../include/AnimationFileDataManager.h"
#include "../include/DBSystem.h"
#include "../include/EngineSystem.h"
#include <include/mem/DPacket.h>
#include <include/common/String.h>
#include <include/common/Parser.h>
#include <assert.h>


AnimationFileData::AnimationFileData()
{
	mAnimationIntervalTime = 0.0f;
	mAnimationFrameCount   = 0;
	memset(mAnimationName, 0, sizeof(mAnimationName));
	memset(mAnimationPrefix, 0, sizeof(mAnimationPrefix));
	memset(mAnimationFileName, 0, sizeof(mAnimationFileName));
}

AnimationFileData::~AnimationFileData()
{

}

bool AnimationFileData::ParseBuffer(char* pBuffer, unsigned int iLen)
{
	// 解析字符串
	Parser parser(pBuffer, iLen, '\t');

	int id = 0;
	if (!parser.parser_int_value(id))
		return false;

	if (!parser.parser_string_value(mAnimationName, sizeof(mAnimationName)))
		return false;

	if (!parser.parser_string_value(mAnimationPrefix, sizeof(mAnimationPrefix)))
		return false;

	if (!parser.parser_int_value(mAnimationFrameCount))
		return false;

	if (!parser.parser_float_value(mAnimationIntervalTime))
		return false;

	if (!parser.parser_string_value(mAnimationFileName, sizeof(mAnimationFileName)))
		return false;

	return true;
}

template<> AnimationFileDataManager* cobra_win::Singleton2<AnimationFileDataManager>::m_pMySelf = NULL;

AnimationFileDataManager::AnimationFileDataManager(bool bLoadFromDB, bool bEncryption) : IDataManager(bLoadFromDB, bEncryption)
{
	m_AnimationFileList.clear();
}	

AnimationFileDataManager::~AnimationFileDataManager()
{

}

unsigned int AnimationFileDataManager::GetAnimationNumber()
{
	return m_AnimationFileList.size();
}

AnimationFileData* AnimationFileDataManager::GetAnimationByIdx(unsigned int index)
{
	std::map<std::string, AnimationFileData*>::iterator iter   = m_AnimationFileList.begin();
	std::map<std::string, AnimationFileData*>::iterator iter_e = m_AnimationFileList.end();
	for (int i=0; iter!=iter_e; ++iter, ++i)
	{
		if (i == index)
			return iter->second;
	}

	return NULL;
}

AnimationFileData* AnimationFileDataManager::GetAnimationByName(std::string name)
{
	std::map<std::string, AnimationFileData*>::iterator iter = m_AnimationFileList.find(name);
	if (iter == m_AnimationFileList.end())
		return NULL;

	return iter->second;
}

std::string AnimationFileDataManager::GetName()
{
	if (!m_bLoadFromDB)
		return "resource/data/animationfile.txt";

	return "animationfile";
}

unsigned  int AnimationFileDataManager::GetSize()
{
	return m_AnimationFileList.size()*sizeof(AnimationFileData);
}

bool  AnimationFileDataManager::Init()
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

void  AnimationFileDataManager::Tick()
{

}

void  AnimationFileDataManager::Destroy()
{
	std::map<std::string, AnimationFileData*>::iterator iter   = m_AnimationFileList.begin();
	std::map<std::string, AnimationFileData*>::iterator iter_e = m_AnimationFileList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	return m_AnimationFileList.clear();
}

bool  AnimationFileDataManager::Varify(IData* pData)
{
	if (!DBSYSTEM->IsNeedVerify())
		return true;

	AnimationFileData* pAnimation = (AnimationFileData*)pData;
	assert(pAnimation != NULL);

	return true;
}

bool  AnimationFileDataManager::VarifyAfterLoadAll()
{
	return true;
}

bool  AnimationFileDataManager::LoadData(char* pBuffer, unsigned int iBufferLen)
{
	AnimationFileData* pItemData = new AnimationFileData;
	if (!pItemData->ParseBuffer(pBuffer, iBufferLen))
		return false;

	if (!Varify(pItemData))
		return false;

	m_AnimationFileList.insert(std::map<std::string, AnimationFileData*>::value_type(pItemData->mAnimationName, pItemData));
	return true;
}
