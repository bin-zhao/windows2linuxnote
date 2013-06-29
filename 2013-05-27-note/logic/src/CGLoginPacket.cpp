#include "../include/CGLoginPacket.h"
#include "../include/PacketTyper.h"
#include "../include/NetSystem.h"
#include <include/mem/MemNode.h>
using  namespace  cobra_win;


CGLoginPacket::CGLoginPacket()
{
	
}

CGLoginPacket::~CGLoginPacket()
{

}

unsigned  int  CGLoginPacket::GetPacketType()
{
	return _TYPED_PACKET_C2G_LOGIN_;
}

unsigned  int  CGLoginPacket::GetPacketLength()
{
	return sizeof(m_PlayerAccount)+sizeof(m_PlayerPassword);
}

bool  CGLoginPacket::Read(char* pBuffer, unsigned int iLen)
{
	return true;
}

void  CGLoginPacket::Send()
{
	MemNode* pNode = NETSYSTEM->QueryMemNode(GetPacketLength());

	pNode->push(m_PlayerAccount, sizeof(m_PlayerAccount));
	pNode->push(m_PlayerPassword, sizeof(m_PlayerPassword));

	NETSYSTEM->SendPacket(pNode);
}