#include "../include/TCPConnectorThread.h"
#include "../include/VariableSystem.h"
#include "../include/NetSystem.h"
#include <include/net/Socket.h>
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)


#include <netdb.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void* TCPConnectorThread::run()
{
	do 
	{
		char serverURL[1024] = "www.changyou.com";
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "GameServerURL", serverURL, sizeof(serverURL));
		int serverPort = 9009;
		VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "GameServerPort", serverPort);

		struct hostent* pPtr = gethostbyname(serverURL);
		if (pPtr == NULL)
		{
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		if (pPtr->h_addrtype != AF_INET)
		{
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		char str[INET_ADDRSTRLEN] = "";
		const char* pIP = inet_ntop(AF_INET, *(pPtr->h_addr_list), str, sizeof(str));
		if (pIP == NULL)
		{
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		sockaddr_in serverAddr;
		bzero(&serverAddr, sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port   = htons(serverPort);
		inet_pton(AF_INET, pIP, &serverAddr.sin_addr);

		SOCKET& sock = NETSYSTEM->GetConnectSocket();
		sock = Socket::create_tcp_socket();
		if (sock == -1)
		{
			sock = -1;
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		int ret = Socket::connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr));
		if (ret == -1)
		{
			sock = -1;
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_SUCCESS_);
	} 
	while (false);

	return NULL;
}


#endif
