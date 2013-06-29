#ifndef  _NINJIATRIBE_WINDOWMANAGER_H_
#define  _NINJIATRIBE_WIDNOWMANAGER_H_


#include <include/common/Singleton.h>
#include <map>
using  namespace  cobra_win;

class IWindow;
class UILayoutDataManager;
class WindowManager : public cobra_win::Singleton2<WindowManager>
{
private:
	std::map<int, IWindow*> m_WindowList;

public:
	WindowManager();
	virtual ~WindowManager();

public:
	/*
		根据指定的Layout名称得到对应的UI窗口
	*/
	IWindow* GetWindowByType(int iWindowType);
	/*
		判断指定窗口是否显示
	*/
	bool     IsWindowVisible(int iWindowType);
	/*
		隐藏所有UI窗口
	*/
	void     HideAllWindow(bool bVisible);
	/*
		得到UI窗口个数
	*/
	size_t   GetWindowCount();
	/*
		得到指定索引的UI窗口
	*/
	IWindow* GetWindowByIndex(size_t iIndex);

public:
	/*
		得到指定UI窗口对应的布局管理器
	*/
	UILayoutDataManager* GetUILayoutByWindowType(int iWindowType);

public:
	/*
		初始化UI窗口管理器
	*/
	bool     Init();
	/*
		逻辑桢更新
	*/
	void     Tick();
	/*
		销毁UI窗口管理器
	*/
	void     Destroy();

private:
	friend  class  cobra_win::Singleton2<WindowManager>;
};

#define  WINDOWMANAGER  (WindowManager::get_instance2())


#endif
