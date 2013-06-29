#include "../include/DNSThread.h"
#include "../include/VariableSystem.h"
#include "../include/NetSystem.h"


DNSThread::DNSThread()
{
	m_ThreadState = _TYPED_THREAD_RUNING_;
}

DNSThread::~DNSThread()
{

}

int DNSThread::GetThreadState()
{
	int ret = _TYPED_THREAD_RUNING_;

	m_ThreadLock.lock();
	ret = m_ThreadState;
	m_ThreadLock.unlock();

	return ret;
}

void DNSThread::SetThreadState(int IThreadState)
{
	m_ThreadLock.lock();
	m_ThreadState = IThreadState;
	m_ThreadLock.unlock();
}
