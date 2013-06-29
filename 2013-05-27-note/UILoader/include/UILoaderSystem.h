#ifndef  _UILOADER_UILOADERSYSTEM_H_
#define  _UILOADER_UILOADERSYSTEM_H_


#include <include/common/Singleton.h>
#include <cocos2d.h>
using  namespace  cobra_win;

namespace  uiloader
{


class UILoaderSystem : public cobra_win::Singleton<UILoaderSystem>
{
private:
	bool        m_bEncryption;    // 布局文件是否加密
	std::string m_EncryptionKey;  // 解密的KEY值

public:
	UILoaderSystem();
	~UILoaderSystem();

public:
	/*
		加载指定的资源文件
	*/
	cocos2d::CCNode* LoadFromFile(char* pFileName);
	/*
		加载指定的内存缓冲区
	*/
	cocos2d::CCNode* LoadFromBuffer(char* pBuffer, unsigned int iBufferLen);

public:
	/*
		布局文件是否加密
	*/
	bool  IsEncryption();
	/*
		获得加密的KEY
	*/
	std::string GetEncryptionKey();

public:
	/*
		初始化操作
	*/
	bool  Init(bool bEncryption, std::string encryptionKey);
	/*
		销毁操作
	*/
	void  Destroy();

public:
	friend  class  cobra_win::Singleton<UILoaderSystem>;
};


}


#endif
