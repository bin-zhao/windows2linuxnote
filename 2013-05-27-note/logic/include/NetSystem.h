#ifndef  _NINJIATRIBE_NETSYSTEM_H_
#define  _NINJIATRIBE_NETSYSTEM_H_


#include <include/common/Declare.h>
#include <include/mem/MemNode.h>
#include <include/mem/Allocator.h>
#include <include/common/Singleton.h>
#include <string>
#include <list>
using  namespace  cobra_win;

struct sockaddr;
class TCPConnectorThread;
class NetSystem : public cobra_win::Singleton2<NetSystem>
{
protected:
	fd_set  m_SocketReadSet;      // 套接字可读事件集合
	fd_set  m_SocketWriteSet;     // 套接字可写事件集合
	fd_set  m_SocketExceptionSet; // 套接字异常事件集合

protected:
	SOCKET  m_ConnectSocket;      // 客户端连接套接字

protected:
	unsigned int m_TempRecvLength;   // 当前接受数据数量
	char     m_TempPacketBuffer[128];// 临时接受数据包缓冲区(主要接受包头)
	unsigned int m_TempPacketLength; // 当前接受数据包大小
	MemNode* m_pTempPacketNode;      // 当前接受数据包内存块

protected:
	std::list<MemNode*> m_SendPacketList;  // 待发送包队列
	std::list<MemNode*> m_RecvPacketList;  // 已读取包队列
	Allocator<512, 4>   m_PacketMemoryPool;// 网络数据包内存池

protected:
	TCPConnectorThread* m_pConnectThread;  // 服务器连接线程

public:
	NetSystem();
	virtual ~NetSystem();

public:
	/*
		得到连接套接字
	*/
	SOCKET&  GetConnectSocket();
	/*
		从网络数据包内存池申请内存块
	*/
	MemNode* QueryMemNode(unsigned int iLen);
	/*
		回收网络数据包
	*/
	void     RecoverMemNode(MemNode* pNode);

public:
	/*
		连接游戏服务器
	*/
	void  ConnectServer();
	/*
		发送数据包
	*/
	void  SendPacket(MemNode* pNode);

public:
	/*
		初始化网络系统管理器
	*/
	bool  Init();
	/*
		网络系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁网络系统管理器
	*/
	void  Destroy();

protected:
	/*
		套接字可读事件处理
	*/
	bool  OnSocketReadEventHandler();
	/*
		套接字可写事件处理
	*/
	bool  OnSocketWriteEventHandler();
	/*
		套接字异常事件处理
	*/
	bool  OnSocketExceptionEventHandler();

private:
	/*
		连接状态Tick更新
	*/
	void  ConnectTick();
	/*
		分发所有已接收的数据包
	*/
	void  DispatchAllPacket();

public:
	friend  class  cobra_win::Singleton2<NetSystem>;
};

#define  NETSYSTEM  (NetSystem::get_instance2())


#endif
