#include "../include/SoundSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/VariableSystem.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/CommonButtonDataManager.h"
#include <SimpleAudioEngine.h>
#include <include/Common/String.h>
using namespace  cobra_win;


template<> SoundSystem* cobra_win::Singleton2<SoundSystem>::m_pMySelf = NULL;

SoundSystem::SoundSystem()
{
	m_MyTimer = 0;
	m_BackSoundName  = "";
}

SoundSystem::~SoundSystem()
{

}

void SoundSystem::MuteBackgroundMusic(bool bMute)
{
	if (bMute)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}

	VARIABLESYSTEM->SetVariable(VariableSystem::_TYPED_CONFIG_ACCOUNT_, "SOUND", "BackgroundMusicMute", bMute);
}

void SoundSystem::MuteEffectSound(bool bMute)
{
	if (bMute)
	{
		PauseAllEffectSound();
	}
	else
	{
		ResumeAllEffectSound();
	}

	VARIABLESYSTEM->SetVariable(VariableSystem::_TYPED_CONFIG_ACCOUNT_, "SOUND", "EffectSoundMute", bMute);
}

bool SoundSystem::IsBackgroundMusicMute()
{
	bool bMute = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_ACCOUNT_, "SOUND", "BackgroundMusicMute", bMute);

	return bMute;
}

bool SoundSystem::IsEffectSoundMute()
{
	bool bMute = false;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_ACCOUNT_, "SOUND", "EffectSoundMute", bMute);

	return bMute;
}

void SoundSystem::PlayEffect(int effectType, std::string soundName, bool bLoop)
{
	if (soundName.length() == 0)
		return;

	if (!IsCanPlay(effectType))
		return ;

	int soundId = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(soundName.c_str(), bLoop);
	InsertEffectInfo(effectType, soundName, soundId, bLoop);
}

void SoundSystem::StopEffect(int effectType)
{
	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<_EFFECT_INFO_>::iterator temp = iter;
		++iter;

		if ((*temp).mEffectType == effectType)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect((*temp).mSoundId);
			m_EffectList.erase(temp);
		}
	}
}

void SoundSystem::PlayBackgroundMusic(std::string soundName)
{
	if (m_BackSoundName.compare(soundName) == 0)
		return;

	m_BackSoundName = soundName;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(m_BackSoundName.c_str(), 1);
	if (IsBackgroundMusicMute())
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}
}

void SoundSystem::StopBackgroundMusic()
{
	m_BackSoundName  = "";
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
}

void SoundSystem::PlaySoliderCreatedEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_OTHER_, "resource/media/buysolider.mp3", false);
}

void SoundSystem::PlaySoliderLevelupEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_OTHER_, "resource/media/levelupsolider.mp3", false);
}

void SoundSystem::PlaySoliderSellEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_OTHER_, "resource/media/sellsolider.mp3", false);
}

void SoundSystem::PlayWinEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_EFFECT_, "resource/media/win.mp3", false);
}

void SoundSystem::PlayLoseEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_EFFECT_, "resource/media/lose.mp3", false);
}

void SoundSystem::PlayInvalidEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_EFFECT_, "resource/media/invalid.mp3", false);
}

void SoundSystem::PlaySelectedEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_OTHER_, "resource/media/select.mp3", false);
}

void SoundSystem::PlayRemoveAllBuildingEffect()
{
	PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_OTHER_, "resource/media/removeallbuilding.mp3", false);
}

bool   SoundSystem::Init()
{
	m_MyTimer = 0;
	CocosDenshion::SimpleAudioEngine::sharedEngine();

	if (m_BackSoundName.length() != 0)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(m_BackSoundName.c_str(), 1);
		if (IsBackgroundMusicMute())
			CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}

	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<_EFFECT_INFO_>::iterator temp = iter;
		++iter;

		if ((*temp).mLoop)
		{
			(*temp).mSoundId = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect((*temp).mSoundName);
		}
	}

	LOGGERSYSTEM->LogInfo("Init SoundSystem Success\n");
	return true;
}

void   SoundSystem::Tick()
{
	m_MyTimer++;

	float effectReleaseInterval = 1.5f;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "EffectReleaseInterval", effectReleaseInterval);
	int interval = (int)(effectReleaseInterval*NinjiaTribeApp::get_instance2()->GetFPS());

	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<_EFFECT_INFO_>::iterator temp = iter;
		++iter;

		if (!(*temp).mLoop)
		{
			if (m_MyTimer-(*temp).mStartTime>=interval)
			{
				CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect((*temp).mSoundId);
				m_EffectList.erase(temp);
			}
		}
	}

	if (NinjiaTribeApp::get_instance2()->IsActive() && !IsBackgroundMusicMute())
	{
		if (m_BackSoundName.length() != 0)
		{
			ResumeAllEffectSound();
			CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		}
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}
}

void   SoundSystem::Destroy()
{
	PauseAllEffectSound();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::end();

	LOGGERSYSTEM->LogInfo("Destroy SoundSystem Success\n");
}

bool   SoundSystem::IsCanPlay(int effectType)
{
	if (IsEffectSoundMute())
		return false;

	int len = m_EffectList.size();
	int maxSound = 20;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "MaxEffectSound", maxSound);
	if (len > maxSound)
	{
		for (int i=0; i<len-maxSound; i++)
		{
			std::list<_EFFECT_INFO_>::iterator iter = m_EffectList.begin();
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect((*iter).mSoundId);
			m_EffectList.erase(iter);
		}
	}

	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if ((*iter).mLoop)
		{
			if ((*iter).mEffectType == effectType)
			{
				return false;
			}
		}
	}

	return true;
}

void   SoundSystem::InsertEffectInfo(int effectType, std::string soundName, int soundId, bool bLoop)
{
	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		if ((*iter).mSoundId == soundId)
		{
			(*iter).mStartTime = m_MyTimer;
			return;
		}
	}

	_EFFECT_INFO_ info;
	info.mEffectType= effectType;
	info.mSoundId   = soundId;
	info.mStartTime = m_MyTimer;
	info.mLoop      = bLoop;
	String::copy(info.mSoundName, (char*)soundName.c_str(), sizeof(info.mSoundName));
	m_EffectList.push_back(info);
}

void SoundSystem::PauseAllEffectSound()
{
	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<_EFFECT_INFO_>::iterator temp = iter;
		++iter;

		if (!(*temp).mLoop)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->stopEffect((*temp).mSoundId);
			m_EffectList.erase(temp);
		}
		else
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseEffect((*temp).mSoundId);
		}
	}
}

void SoundSystem::ResumeAllEffectSound()
{
	std::list<_EFFECT_INFO_>::iterator iter   = m_EffectList.begin();
	std::list<_EFFECT_INFO_>::iterator iter_e = m_EffectList.end();
	for ( ; iter!=iter_e; )
	{
		std::list<_EFFECT_INFO_>::iterator temp = iter;
		++iter;

		if ((*temp).mLoop)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeEffect((*temp).mSoundId);
		}
	}
}

void SoundSystem::OnEnterBackgroundEventHandler()
{
	if (IsBackgroundMusicMute())
		return;

	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void SoundSystem::OnEnterForegroundEventHandler()
{
	if (IsBackgroundMusicMute())
		return;

	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void SoundSystem::OnMenuItemCallbackEventHandler(std::string eventName, std::string menuItemName)
{
	if (SOUNDSYSTEM == NULL)
		return;

	CommonButtonItemData* pButtonItem = CommonButtonDataManager::get_instance2()->GetCommonButtonByName(menuItemName);
	if (pButtonItem==NULL || pButtonItem->mSoundName[0]=='\0')
		return;

	// 播放音效
	SOUNDSYSTEM->PlayEffect(SoundSystem::_TYPED_EFFECTSOUND_COMMONBUTTON_, pButtonItem->mSoundName, false);
}
