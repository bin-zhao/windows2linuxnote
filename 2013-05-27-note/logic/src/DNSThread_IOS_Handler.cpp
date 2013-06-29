#include "../include/DNSThread.h"
#include "../include/VariableSystem.h"
#include "../include/NetSystem.h"
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)


#include <netdb.h>

void* DNSThread::run()
{
	char buffer[1024] = "www.changyou.com";
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "ServerHostURL", buffer, sizeof(buffer));
	struct hostent* pPtr = gethostbyname(buffer);
	if (pPtr == NULL)
	{
		SetThreadState(DNSThread::_TYPED_THREAD_EXIT_FAILED_);
		pthread_exit(NULL);
		return NULL;
	}

	SetThreadState(DNSThread::_TYPED_THREAD_EXIT_SUCCESS_);
	pthread_exit(NULL);
	return NULL;
}

void DNSThread::post_close_message()
{

}


#endif
