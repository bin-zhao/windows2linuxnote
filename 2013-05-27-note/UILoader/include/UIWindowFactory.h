#ifndef  _UILOADER_UIWINDOWFACTORY_H_
#define  _UILOADER_UIWINDOWFACTORY_H_


#include "UIWindow.h"
#include "UIWindowManager.h"
#include <string>

namespace  uiloader
{


class UIWindowFactory
{
protected:
	std::string m_WindowType;

public:
	UIWindowFactory();
	virtual ~UIWindowFactory();

public:
	/*
		设置窗口类型
	*/
	void        SetWindowType(std::string windowType);
	/*
		得到窗口类型
	*/
	std::string GetWindowType();

public:
	/*
		创建对应名称的窗口
	*/
	virtual UIWindow* CreateUIWindow(std::string windowName) =  0;
	/*
		销毁指定窗口
	*/
	virtual void      DestroyUIWindow(UIWindow* pWindow)     =  0;
};


template <typename T>
class TmplUIWindowFactory : public UIWindowFactory
{
public:
	TmplUIWindowFactory();

public:
	/*
		创建对应名称的窗口
	*/
	virtual UIWindow* CreateUIWindow(std::string windowName);
	/*
		销毁指定窗口
	*/
	virtual void      DestroyUIWindow(UIWindow* pWindow);
};

template <typename T>
TmplUIWindowFactory<T>::TmplUIWindowFactory()
{

}

template <typename T>
UIWindow* TmplUIWindowFactory<T>::CreateUIWindow(std::string windowName)
{
	UIWindow* pWindow = (UIWindow*)new T();
	pWindow->setUIWindowType((char*)m_WindowType.c_str());
	pWindow->setUIWindowName((char*)windowName.c_str());

	return pWindow;
}

template <typename T>
void TmplUIWindowFactory<T>::DestroyUIWindow(UIWindow* pWindow)
{
	delete pWindow;
}


}


#endif
