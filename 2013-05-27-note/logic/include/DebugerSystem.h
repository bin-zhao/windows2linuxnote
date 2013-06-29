#ifndef  _NINJIATRIBE_DEBUGERSYSTEM_H_
#define  _NINJIATRIBE_DEBUGERSYSTEM_H_


#include <include/common/Singleton.h>
using  namespace  cobra_win;

class IDebuger;
class NetDebuger;
class LogicDebuger;
class RenderDebuger;
class DebugerSystem : public cobra_win::Singleton2<DebugerSystem>
{
public:
	NetDebuger*    m_pNetDebuger;    // 网络信息调试器
	LogicDebuger*  m_pLogicDebuger;  // 逻辑信息调试器
	RenderDebuger* m_pRenderDebuger; // 渲染信息调试器

public:
	DebugerSystem();
	virtual ~DebugerSystem();

public:
	/*
		初始化调试器控制系统
	*/
	bool     Init();
	/*
		逻辑桢更新
	*/
	void     Tick();
	/*
		销毁调试器控制系统
	*/
	void     Destroy();

public:
	friend   class   cobra_win::Singleton2<DebugerSystem>;
};

#define  DEBUGERSYSTEM  (DebugerSystem::get_instance2())


#endif
