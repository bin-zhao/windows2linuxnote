#include "../include/NetSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/TCPConnectorThread.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/PacketFactory.h"
#include "../include/PacketFactoryManager.h"
#include <include/net/Socket.h>
#include <include/net/WinNet.h>


// 数据包前缀大小
#define  _RECVED_PACKET_PREFIX_HEADER_ (sizeof(char)*2)
// 数据包头大小
#define  _RECVED_PACKET_HEADER_LENGTH_ (sizeof(char)*2+sizeof(int))


template<> NetSystem* cobra_win::Singleton2<NetSystem>::m_pMySelf = NULL;

NetSystem::NetSystem()
{
	m_ConnectSocket = -1;

	m_pConnectThread = NULL;

	m_TempRecvLength   = 0;
	m_TempPacketLength = 0;
	memset(m_TempPacketBuffer, 0, sizeof(m_TempPacketBuffer));
	m_pTempPacketNode  = NULL;

	m_SendPacketList.clear();
	m_RecvPacketList.clear();
}

NetSystem::~NetSystem()
{

}

SOCKET& NetSystem::GetConnectSocket()
{
	return m_ConnectSocket;
}

MemNode* NetSystem::QueryMemNode(unsigned int iLen)
{
	return m_PacketMemoryPool.query_mem_node(iLen);
}

void NetSystem::RecoverMemNode(MemNode* pNode)
{
	pNode->clear();
	m_PacketMemoryPool.insert_mem_node(pNode);
}

void NetSystem::ConnectServer()
{
	if (m_pConnectThread != NULL)
		return;

	m_pConnectThread = new TCPConnectorThread;
	m_pConnectThread->create_thread();
}

void NetSystem::SendPacket(MemNode* pNode)
{
	m_SendPacketList.push_back(pNode);
}

bool  NetSystem::Init()
{
	do 
	{
		// 初始化系统网络模块
		if (!WinNet::init_network())
			break;

		// 初始化网络数据包内存池
		m_PacketMemoryPool.init_allocator(16);

		// ConnectServer();
		LOGGERSYSTEM->LogInfo("Init NetSystem Success\n");
		return true;
	} 
	while (false);

	LOGGERSYSTEM->LogInfo("Init NetSystem Failed\n");
	return false;
}

void  NetSystem::Tick()
{
	ConnectTick();
	if (m_pConnectThread != NULL)
		return;

	// 如果已经断开连接，则不进行逻辑Tick
	if (m_ConnectSocket == -1)
		return;

	// 连接事件轮询监听
	FD_ZERO(&m_SocketReadSet);
	FD_SET(m_ConnectSocket, &m_SocketReadSet);
	FD_ZERO(&m_SocketWriteSet);
	FD_SET(m_ConnectSocket, &m_SocketWriteSet);
	FD_ZERO(&m_SocketExceptionSet);
	FD_SET(m_ConnectSocket, &m_SocketExceptionSet);

	struct timeval interval;
	interval.tv_sec  = 0;
	interval.tv_usec = 0;
	int ret = Socket::select(2, &m_SocketReadSet, &m_SocketWriteSet, &m_SocketExceptionSet, &interval);
	if (ret == 0)
		return;
	else if (ret == -1)
		return;

	do 
	{
		if (FD_ISSET(m_ConnectSocket, &m_SocketReadSet))
		{
			if (!OnSocketReadEventHandler())
				break;
		}
		if (FD_ISSET(m_ConnectSocket, &m_SocketWriteSet))
		{
			if (!OnSocketWriteEventHandler())
				break;
		}
		if (FD_ISSET(m_ConnectSocket, &m_SocketExceptionSet))
		{
			if (!OnSocketExceptionEventHandler())
				break;
		}

		// 数据包分发处理
		DispatchAllPacket();
	} 
	while (false);
}

void NetSystem::Destroy()
{
	Socket::close_socket(m_ConnectSocket);
	m_ConnectSocket = -1;

	// 销毁ConnectThread
	if (m_pConnectThread != NULL)
	{
		delete m_pConnectThread;
		m_pConnectThread = NULL;
	}

	// 释放临时接受数据包信息
	m_TempPacketLength = 0;
	m_TempRecvLength   = 0;
	memset(m_TempPacketBuffer, 0, sizeof(m_TempPacketBuffer));
	if (m_pTempPacketNode != NULL)
	{
		delete m_pTempPacketNode;
		m_pTempPacketNode = NULL;
	}

	// 清空待发送队列
	std::list<MemNode*>::iterator iter   = m_SendPacketList.begin();
	std::list<MemNode*>::iterator iter_e = m_SendPacketList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete (*iter);
	}
	m_SendPacketList.clear();

	// 清空接受队列
	iter   = m_RecvPacketList.begin();
	iter_e = m_RecvPacketList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete (*iter);
	}
	m_RecvPacketList.clear();

	// 销毁网络数据包内存池
	m_PacketMemoryPool.destroy_allocator();
	WinNet::destroy_network();
	LOGGERSYSTEM->LogInfo("Destroy NetSystem Success\n");
}

void NetSystem::ConnectTick()
{
	if (m_pConnectThread != NULL)
	{
		int state = m_pConnectThread->GetThreadState();
		if (state == TCPConnectorThread::_TYPED_THREAD_RUNING_)
		{// 连接中...
			;
		}
		else if (state == TCPConnectorThread::_TYPED_THREAD_EXIT_FAILED_)
		{// 连接失败
			delete m_pConnectThread;
			m_pConnectThread = NULL;
		}
		else if (state == TCPConnectorThread::_TYPED_THREAD_EXIT_SUCCESS_)
		{// 连接成功
			delete m_pConnectThread;
			m_pConnectThread = NULL;

			// 设置可重用性
			Socket::set_socket_reuse(m_ConnectSocket);
			// 设置接受缓冲区大小(128K)
			Socket::set_socket_recv_buffer_size(m_ConnectSocket, 128*1024);
			// 设置发送缓冲区大小(128K)
			Socket::set_socket_send_buffer_size(m_ConnectSocket, 128*1024);
			// 设置为非阻塞式连接
			Socket::set_socket_unblock(m_ConnectSocket);
		}
	}
}

void NetSystem::DispatchAllPacket()
{
	std::list<MemNode*>::iterator iter   = m_RecvPacketList.begin();
	std::list<MemNode*>::iterator iter_e = m_RecvPacketList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		MemNode* pTemp = *iter;
		if (pTemp->size() >= (_RECVED_PACKET_HEADER_LENGTH_+sizeof(short)))
		{
			unsigned short packetType = *((unsigned short*)(pTemp->get_buff()+_RECVED_PACKET_HEADER_LENGTH_));
			IPacketFactory* pFactory = PacketFactoryManager::get_instance()->GetPacketFactoryByType(packetType);
			if (pFactory != NULL)
			{
				pFactory->OnPacketHandler(pTemp->get_buff(), pTemp->size());
			}
			else
			{
				LOGGERSYSTEM->LogError("NET:	UnRegister Packet Factory, Packet Type=%u", packetType);
			}
		}

		RecoverMemNode(pTemp);
	}
	m_RecvPacketList.clear();
}

bool NetSystem::OnSocketReadEventHandler()
{
	while (true)
	{
		if (m_TempRecvLength < _RECVED_PACKET_HEADER_LENGTH_)
		{
			int recvLen = _RECVED_PACKET_HEADER_LENGTH_-m_TempRecvLength;
			int ret = Socket::recv(m_ConnectSocket, m_TempPacketBuffer+m_TempRecvLength, recvLen, 0);
			if (ret < 0)
			{// 读取出错了
				goto RECV_FAILED;
			}
			else if (ret == 0)
			{
				goto RECV_END;
			}

			m_TempRecvLength += ret;
			if (ret < recvLen)
			{// 数据包没有完全读物完，继续读
				continue;
			}

			m_TempPacketLength = *((int*)(m_TempPacketBuffer+_RECVED_PACKET_PREFIX_HEADER_));
			m_pTempPacketNode = QueryMemNode(m_TempPacketLength);
			m_pTempPacketNode->push(m_TempPacketBuffer, m_TempRecvLength);
			memset(m_TempPacketBuffer, 0, sizeof(m_TempPacketBuffer));
		}

		do 
		{
			int recvLen = m_TempPacketLength-m_TempRecvLength;
			int ret = Socket::recv(m_ConnectSocket, m_pTempPacketNode->get_buff()+m_pTempPacketNode->get_write_pos(), recvLen, 0);
			if (ret < 0)
			{// 读取出错了
				goto RECV_FAILED;
			}
			else if (ret == 0)
			{
				goto RECV_END;
			}

			m_pTempPacketNode->set_write_pos(m_pTempPacketNode->get_write_pos()+ret);
			m_TempRecvLength += ret;
			if (m_TempRecvLength == m_TempPacketLength)
			{// 包接受完毕了
				m_RecvPacketList.push_back(m_pTempPacketNode);

				// 重新读取
				m_TempRecvLength   = 0;
				m_TempPacketLength = 0;
				m_pTempPacketNode  = NULL;
				break;
			}
		} 
		while (true);
	}

RECV_FAILED:
	OnSocketExceptionEventHandler();
	return false;

RECV_END:
	return true;
}

bool NetSystem::OnSocketWriteEventHandler()
{
	while (true)
	{
		// 没有可发送数据，直接退出
		if (m_SendPacketList.size() <= 0)
			goto SEND_END;

		std::list<MemNode*>::iterator iter   = m_SendPacketList.begin();
		std::list<MemNode*>::iterator iter_e = m_SendPacketList.end();
		for ( ; iter!=iter_e; )
		{
			std::list<MemNode*>::iterator temp = iter;
			++iter;

			MemNode* pNode = (*temp);
			char*    pBuffer = pNode->get_buff();
			int packetLen = *((int*)(pBuffer+_RECVED_PACKET_PREFIX_HEADER_))+_RECVED_PACKET_PREFIX_HEADER_;
			int ret = Socket::send(m_ConnectSocket, pNode->get_buff()+pNode->get_read_pos(), packetLen-pNode->get_read_pos(), 0);
			if (ret < 0)
			{// 发送失败
				goto SEND_FAILED;
			}
			else if (ret == 0)
			{
				goto SEND_END;
			}

			pNode->set_read_pos(pNode->get_read_pos()+ret);
			if (pNode->get_read_pos() == packetLen)
			{// 回收该节点
				RecoverMemNode(pNode);
				m_SendPacketList.erase(temp);
			}
		}
	}
	
SEND_FAILED:
	OnSocketExceptionEventHandler();
	return false;

SEND_END:
	return true;
}

bool NetSystem::OnSocketExceptionEventHandler()
{
	// 关闭套接字
	Socket::close_socket(m_ConnectSocket);
	m_ConnectSocket = -1;

	// 释放临时接受数据包信息
	m_TempPacketLength = 0;
	m_TempRecvLength   = 0;
	memset(m_TempPacketBuffer, 0, sizeof(m_TempPacketBuffer));
	if (m_pTempPacketNode != NULL)
	{
		delete m_pTempPacketNode;
		m_pTempPacketNode = NULL;
	}

	// 回收发送缓冲区
	std::list<MemNode*>::iterator iter   = m_SendPacketList.begin();
	std::list<MemNode*>::iterator iter_e = m_SendPacketList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		(*iter)->clear();
		RecoverMemNode((*iter));
	}
	m_SendPacketList.clear();

	// 回收接受缓冲区
	iter   = m_RecvPacketList.begin();
	iter_e = m_RecvPacketList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		(*iter)->clear();
		RecoverMemNode((*iter));
	}
	m_RecvPacketList.clear();

	// 逻辑层抛事件
	// EVENTSYSTEM->PushEvent(_TYPED_EVENT_TCP_CONNECT_FAILED_);

	return true;
}
