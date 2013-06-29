#ifndef  _NINJIATRIBE_DNSTHREAD_H_
#define  _NINJIATRIBE_DNSTHREAD_H_


#include <include/thread/IThread.h>
#include <include/common/Lock.h>
using  namespace  cobra_win;

class DNSThread : public IThread
{
public:
	enum
	{
		_TYPED_THREAD_RUNING_,        // 正在运行中
		_TYPED_THREAD_EXIT_FAILED_,   // DNS解析失败
		_TYPED_THREAD_EXIT_SUCCESS_,  // DNS解析成功
	};

public:
	ThreadLock m_ThreadLock;
	int        m_ThreadState;

public:
	DNSThread();
	virtual ~DNSThread();

public:
	/*
		得到当前线程运行状态
	*/
	int  GetThreadState();
	/*
		设置当前线程运行状态
	*/
	void SetThreadState(int IThreadState);

public:
	/*
		线程处理函数
	*/
	virtual   void*  run();
	/*
		发起关闭消息
	*/
	virtual   void   post_close_message();
};

#endif
