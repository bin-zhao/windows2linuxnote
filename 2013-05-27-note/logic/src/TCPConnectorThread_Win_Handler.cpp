#include "../include/TCPConnectorThread.h"
#include "../include/VariableSystem.h"
#include "../include/NetSystem.h"
#include <include/net/Socket.h>
#include <cocos2d.h>


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)


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

		char* pIP = inet_ntoa(*(struct in_addr*)*pPtr->h_addr_list);
		if (pIP == NULL)
		{
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		sockaddr_in serverAddr; 
		serverAddr.sin_family      = AF_INET;
		serverAddr.sin_addr.s_addr = inet_addr(pIP);
		serverAddr.sin_port        = htons(serverPort);

		SOCKET& sock = NETSYSTEM->GetConnectSocket();
		sock = Socket::create_tcp_socket();
		if (sock == INVALID_SOCKET)
		{
			sock = -1;
			SetThreadState(TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_);
			break;
		}

		int ret = Socket::connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
		if (ret == SOCKET_ERROR)
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
