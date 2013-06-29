#ifndef  _NINJIATRIBE_GUIDESYSTEM_H_
#define  _NINJIATRIBE_GUIDESYSTEM_H_


#include <include/common/Singleton.h>
#include <string>
using  namespace  cobra_win;

class GuideSystem : public cobra_win::Singleton2<GuideSystem>
{
public:
	enum
	{
		_TYPED_GUIDE_STEP_UNKOWN_,
		_TYPED_GUIDE_STEP_NUMBER_,
	};

private:
	int  m_GuideStepType;  // 新手引导类型
	int  m_GuideStepIndex; // 当前新手引导索引

public:
	GuideSystem();
	virtual ~GuideSystem();

public:
	/*
		是否需要新手引导
	*/
	bool  IsNeedGuide();
	/*
		得到当前新手引导类型
	*/
	int   GetGuideType();
	/*
		得到当前新手引导步骤
	*/
	int   GetGuideIndex();

public:
	/*
		开始指定类型的新手引导
	*/
	void  StartGuide(int guideType);
	/*
		下一步
	*/
	void  Next();
	/*
		结束
	*/
	void  Finish();

public:
	/*
		初始化新手引导系统管理器
	*/
	bool  Init();
	/*
		新手引导系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁新手引导系统管理器
	*/
	void  Destroy();

public:
	/*
		引擎按钮操作回调处理(判断是否需要)
	*/
	static   void    OnMenuItemCallbackEventHandler(std::string eventName, std::string menuItemName);

public:
	friend  class  cobra_win::Singleton2<GuideSystem>;
};

#define  GUIDESYSTEM  (GuideSystem::get_instance2())


#endif
