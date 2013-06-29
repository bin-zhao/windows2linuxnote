#include "../include/PacketFactoryManager.h"
#include "../include/LoggerSystem.h"
#include "../include/PacketFactory.h"
#include "../include/GCLoginPacket.h"


PacketFactoryManager::PacketFactoryManager()
{
	m_PacketFactoryList.clear();
}

PacketFactoryManager::~PacketFactoryManager()
{

}

void PacketFactoryManager::RegisterFactory(IPacketFactory* pPacketFactory)
{
	m_PacketFactoryList[pPacketFactory->GetPacketType()] = pPacketFactory;
}

IPacketFactory* PacketFactoryManager::GetPacketFactoryByType(unsigned int type)
{
	std::map<int, IPacketFactory*>::iterator iter = m_PacketFactoryList.find(type);
	if (iter == m_PacketFactoryList.end())
		return NULL;

	return iter->second;
}

bool  PacketFactoryManager::Init()
{
	RegisterFactory(new GCLoginPacketFactory);

	LOGGERSYSTEM->LogInfo("Init PacketFactoryManager Success\n");
	return true;
}

void  PacketFactoryManager::Tick()
{

}

void  PacketFactoryManager::Destroy()
{
	std::map<int, IPacketFactory*>::iterator iter   = m_PacketFactoryList.begin();
	std::map<int, IPacketFactory*>::iterator iter_e = m_PacketFactoryList.end();
	for ( ; iter!=iter_e; ++iter)
	{
		delete iter->second;
	}
	m_PacketFactoryList.clear();

	LOGGERSYSTEM->LogInfo("Destroy PacketFactoryManager Success\n");
}
