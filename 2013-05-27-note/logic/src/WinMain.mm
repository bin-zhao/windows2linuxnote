#include "../include/WinMain.h"
#include "../include/NinjiaTribeApp.h"


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

static bool get_module_folder_path(char* pPath, size_t iLen)
{
	int ret = (int)GetModuleFileName(NULL, pPath, (DWORD)iLen);
	if ( (ret==0) || (ret==iLen))
		return false;

	for (size_t i=strlen(pPath)-1; i>=0; i--)
	{
		switch( pPath[i] )
		{
		case	'/':
		case	'\\':
			pPath[i+1] = '\0';
			return true;
			break;
		}
	}

	return false;
}

static bool chg_module_folder(char* pPath)
{
	if (_chdir(pPath) != 0)
		return false;

	return true;
}

static inline void enable_mem_leak_check()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	do 
	{
#ifdef _DEBUG
		enable_mem_leak_check();
		_CrtSetBreakAlloc(0);
#endif

		char path[1024] = "";
		if (!get_module_folder_path(path, sizeof(path)))
			break;

		if (!chg_module_folder(path))
			break;

		NinjiaTribeApp myApp;
		cocos2d::CCApplication::sharedApplication()->run();
		return 0;
	}
	while (false);

	return 0;
}

#endif





#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

int main(int argc, char *argv[]) 
{
	// 初始化全局的App管理器对象
	// 不需要在手动的释放，因为在销毁的时候会自动的释放
	NinjiaTribeApp* pApp = new NinjiaTribeApp;

	// 创建自动释放池
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	int retVal = UIApplicationMain(argc, argv, nil, @"NinjiaTribeAppController");
	// 释放自动释放池
	[pool release];

	return retVal;
}

#endif
