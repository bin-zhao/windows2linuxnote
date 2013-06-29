#include "../include/NetDebuger.h"


NetDebuger::NetDebuger()
{
	m_DebugerType = _TYPED_DEBUGER_NET_;

	m_AllDownLoadBytes = 0;
	m_AllUpLoadBytes   = 0;
}

NetDebuger::~NetDebuger()
{

}

bool  NetDebuger::Init()
{
	return true;
}

void  NetDebuger::Tick()
{

}

void  NetDebuger::Destroy()
{

}
