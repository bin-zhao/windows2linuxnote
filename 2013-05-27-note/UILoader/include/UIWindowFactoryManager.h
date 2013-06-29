#ifndef  _UILOADER_UIWINDOWFACTORYMANAGER_H_
#define  _UILOADER_UIWINDOWFACTORYMANAGER_H_


#include <include/common/Singleton.h>
#include "UIWindowFactory.h"
#include <map>
#include <string>
using  namespace  cobra_win;

namespace  uiloader
{


class UIWindowFactoryManager : public cobra_win::Singleton<UIWindowFactoryManager>
{
public:
	typedef	std::map<std::string, UIWindowFactory*> WindowFactoryRegistry;

private:
	WindowFactoryRegistry m_factoryRegistry;

public:
	UIWindowFactoryManager();
	~UIWindowFactoryManager();

public:
	/*
		增加工厂
	*/
	void  AddFactory(UIWindowFactory* pFactory);
	/*
		是否存在指定类型工厂
	*/
	bool  IsExistFactory(std::string windowType);
	/*
		根据类型获得指定工厂
	*/
	UIWindowFactory* GetFactory(std::string windowType);

public:
	/*
		初始化操作
	*/
	bool  Init();
	/*
		销毁操作
	*/
	void  Destroy();

public:
	template <typename T>
	static void AddFactory(char* pWindowTypeName);

public:
	friend  class  cobra_win::Singleton<UIWindowFactoryManager>;
};


template <typename T>
void UIWindowFactoryManager::AddFactory(char* pWindowTypeName)
{
	UIWindowFactory* pFactory = new T;
	pFactory->SetWindowType(pWindowTypeName);
	UIWindowFactoryManager::get_instance()->AddFactory(pFactory);
}


}


#endif
