#ifndef  _UILOADER_UIWINDOWMANAGER_H_
#define  _UILOADER_UIWINDOWMANAGER_H_


#include <include/common/Singleton.h>
#include <string>
#include <map>
using  namespace  cobra_win;

namespace  uiloader
{


class UIWindow;
class UIWindowManager : public cobra_win::Singleton<UIWindowManager>
{
private:
	std::map<std::string, UIWindow*> m_WindowList;

public:
	UIWindowManager();
	~UIWindowManager();

public:
	/*
		得到指定名称的UIWindow
	*/
	UIWindow* GetUIWindow(std::string windowName);
	/*
		是否存在指定的UIWindow
	*/
	bool      IsUIWindowExist(std::string windowName);
	/*
		插入指定的UIWindow
	*/
	void      InsertUIWindow(UIWindow* pWindow);
	/*
		创建指定的UIWindow
	*/
	UIWindow* CreateUIWindow(std::string windowType, std::string windowName);
	/*
		删除指定的UIWindow
	*/
	void      RemoveUIWindow(UIWindow* pWindow);
	/*
		删除所有的UIWindow
	*/
	void      RemoveAllUIWindows();

private:
	/*
		删除指定名称的UIWindow
	*/
	void      RemoveAllChildren(UIWindow* pWindow);
	
private:
	friend  class  cobra_win::Singleton<UIWindowManager>;
};


}


#endif
