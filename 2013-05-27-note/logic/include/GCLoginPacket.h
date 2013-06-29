#ifndef  _NINJIATRIBE_GCLOGIN_PACKET_H_
#define  _NINJIATRIBE_GCLOGIN_PACKET_H_


#include "IPacket.h"
#include "PacketFactory.h"

class GCLoginPacket : public IPacket
{
protected:
	int m_LoginRet;

public:
	GCLoginPacket();
	virtual ~GCLoginPacket();

public:
	/*
		得到数据包类型
	*/
	virtual  unsigned  int  GetPacketType();
	/*
		得到数据包长度
	*/
	virtual  unsigned  int  GetPacketLength();

public:
	/*
		读取字节流
	*/
	virtual  bool  Read(char* pBuffer, unsigned int iLen);
	/*
		发送字节流
	*/
	virtual  void  Send();
};

class GCLoginPacketFactory : public IPacketFactory
{
public:
	GCLoginPacketFactory();
	virtual ~GCLoginPacketFactory();

public:
	/*
		获得数据包类型
	*/
	virtual  unsigned  int  GetPacketType();

public:
	/*
		数据包处理操作
	*/
	virtual  bool  OnPacketHandler(char* pBuffer, unsigned int iLen);

private:
	/*
		逻辑数据包处理
	*/
	static   void  OnGCLoginPacketHandler(GCLoginPacket* pPacket);
};


#endif

