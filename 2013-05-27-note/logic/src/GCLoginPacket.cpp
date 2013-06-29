#include "../include/GCLoginPacket.h"
#include "../include/PacketTyper.h"
#include "../include/NetSystem.h"
#include <include/mem/DPacket.h>
using  namespace  cobra_win;


GCLoginPacket::GCLoginPacket()
{

}

GCLoginPacket::~GCLoginPacket()
{

}

unsigned  int  GCLoginPacket::GetPacketType()
{
	return _TYPED_PACKET_G2C_LOGIN_;
}

unsigned  int  GCLoginPacket::GetPacketLength()
{
	return sizeof(int);
}

bool  GCLoginPacket::Read(char* pBuffer, unsigned int iLen)
{
	DPacket packet(pBuffer, iLen);

	packet>>m_LoginRet;

	return true;
}

void  GCLoginPacket::Send()
{
	;
}

GCLoginPacketFactory::GCLoginPacketFactory()
{

}


GCLoginPacketFactory::~GCLoginPacketFactory()
{

}

unsigned  int GCLoginPacketFactory::GetPacketType()
{
	return _TYPED_PACKET_G2C_LOGIN_;
}

bool GCLoginPacketFactory::OnPacketHandler(char* pBuffer, unsigned int iLen)
{
	GCLoginPacket packet;
	if (!packet.Read(pBuffer, iLen))
		return false;

	OnGCLoginPacketHandler(&packet);
	return true;
}	

void GCLoginPacketFactory::OnGCLoginPacketHandler(GCLoginPacket* pPacket)
{

}
