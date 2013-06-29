#ifndef  _NINJIATRIBE_SOUNDSYSTEM_H_
#define  _NINJIATRIBE_SOUNDSYSTEM_H_


#include <include/common/Singleton.h>
#include <string>
#include <list>
using  namespace  cobra_win;

class SoundSystem : public cobra_win::Singleton2<SoundSystem>
{
public:
	enum
	{
		_TYPED_EFFECTSOUND_UNKOWN_,        // 未知音效类型
		_TYPED_EFFECTSOUND_COMMONBUTTON_,  // 按钮点击音效
		_TYPED_EFFECTSOUND_ITEM_,          // 道具音效
		_TYPED_EFFECTSOUND_EFFECT_,        // 特效音效
		_TYPED_EFFECTSOUND_MONSTER_,       // 怪物死亡音效
		_TYPED_EFFECTSOUND_OTHER_,         // 其他音效类型
		_TYPED_EFFECTSOUND_NUMBER_,        // 音效总数
	};

public:
	struct _EFFECT_INFO_
	{
		int       mEffectType;     // 音效类型
		char      mSoundName[128]; // 音效名称
		int       mSoundId;        // 音效索引Id
		long long mStartTime;      // 音效开始时间
		bool      mLoop;           // 是否循环

		_EFFECT_INFO_()
		{
			memset(this, 0, sizeof(_EFFECT_INFO_));
		}
	};

private:
	long long   m_MyTimer;
	std::string m_BackSoundName;
	std::list<_EFFECT_INFO_> m_EffectList;

public:
	SoundSystem();
	virtual ~SoundSystem();

public:
	/*
		设置背景音乐静音
	*/
	void   MuteBackgroundMusic(bool bMute);
	/*
		设置特效音效静音
	*/
	void   MuteEffectSound(bool bMute);
	/*
		是否背景音乐静音
	*/
	bool   IsBackgroundMusicMute();
	/*
		是否特效音效静音
	*/
	bool   IsEffectSoundMute();

public:
	/*
		播放指定音效类型和名称的音效
	*/
	void   PlayEffect(int effectType, std::string soundName, bool bLoop);
	/*
		停止指定类型的音效
	*/
	void   StopEffect(int effectType);
	/*
		播放背景音效
	*/
	void   PlayBackgroundMusic(std::string soundName);
	/*
		停止背景音效
	*/
	void   StopBackgroundMusic();

public:
	/*
		播放炮塔建造时音效
	*/
	void   PlaySoliderCreatedEffect();
	/*
		播放炮塔升级音效
	*/
	void   PlaySoliderLevelupEffect();
	/*
		播放出售炮塔音效
	*/
	void   PlaySoliderSellEffect();
	/*
		播放通关成功音效
	*/
	void   PlayWinEffect();
	/*
		播放通关失败音效
	*/
	void   PlayLoseEffect();
	/*
		播放禁止操作音效
	*/
	void   PlayInvalidEffect();
	/*
		播放选择音效
	*/
	void   PlaySelectedEffect();
	/*
		播放全部清除建筑音效
	*/
	void   PlayRemoveAllBuildingEffect();

public:
	/*
		初始化数据管理系统
	*/
	bool   Init();
	/*
		数据管理系统帧更新
	*/
	void   Tick();
	/*
		销毁数据管理系统
	*/
	void   Destroy();

private:
	/*
		是否可以播放
	*/
	bool   IsCanPlay(int effectType);
	/*
		播放特效音效
	*/
	void   InsertEffectInfo(int effectType, std::string soundName, int soundId, bool bLoop);
	/*
		暂停所有特效
	*/
	void   PauseAllEffectSound();
	/*
		恢复音效
	*/
	void   ResumeAllEffectSound();

public:
	/*
		程序进入后台回调处理
	*/
	void   OnEnterBackgroundEventHandler();
	/*
		程序进入前台回调处理
	*/
	void   OnEnterForegroundEventHandler();

public:
	/*
		引擎按钮操作回调处理(判断是否需要)
	*/
	static   void    OnMenuItemCallbackEventHandler(std::string eventName, std::string menuItemName);

public:
	friend  class  Singleton2<SoundSystem>;
};

#define  SOUNDSYSTEM  (SoundSystem::get_instance2())


#endif
