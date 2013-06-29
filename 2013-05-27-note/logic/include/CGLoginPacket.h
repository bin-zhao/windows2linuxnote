#ifndef  _NINJIATRIBE_CGLOGIN_PACKET_H_
#define  _NINJIATRIBE_CGLOGIN_PACKET_H_


#include "IPacket.h"
#include "PacketFactory.h"

class CGLoginPacket : public IPacket
{
protected:
	char m_PlayerAccount[64];
	char m_PlayerPassword[64];

public:
	CGLoginPacket();
	virtual ~CGLoginPacket();

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


#endif

