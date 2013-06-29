#ifndef  _UILOADER_UILOADER_H_
#define  _UILOADER_UILOADER_H_


namespace  uiloader
{


class XMLParser;
class UIWindow;
class UILoader
{
public:
	UILoader();
	~UILoader();

public:
	/*
		从文件加载指定的布局文件
	*/
	UIWindow* LoadFromFile(char* pFileName);
	/*
		从内存加载指定的布局文件
	*/
	UIWindow* LoadFromBuffer(char* pBuffer, unsigned int iBufferLen);
};


}


#endif
