#include "../include/IAPSystem.h"
#include "../include/LoggerSystem.h"
#include "../include/VariableSystem.h"
#include <CCPaymentDelegate.h>
#include <cocos2d.h>


template<> IAPSystem* cobra_win::Singleton2<IAPSystem>::m_pMySelf = NULL;

IAPSystem::IAPSystem()
{

}

IAPSystem::~IAPSystem()
{

}

void IAPSystem::VerifyIAPIdentifier()
{
	int type = _TYPED_VERIFY_SERVER_;
	VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_SYSTEM_, "SYS", "IAPVerifyType", type);
	if (type == _TYPED_VERIFY_LOCAL_)
	{
		;
	}
	else if (type == _TYPED_VERIFY_SERVER_)
	{
		;
	}
}

bool  IAPSystem::Init()
{
	//  注册PAY回调处理
	cocos2d::CCPaymentDelegate* pDelegate = dynamic_cast<cocos2d::CCPaymentDelegate*>(this);
	cocos2d::CCDirector::sharedDirector()->getPayment()->setDelegate(pDelegate);

	LOGGERSYSTEM->LogInfo("Init IAPSystem Success\n");
	return true;
}

void  IAPSystem::Tick()
{

}

void  IAPSystem::Destroy()
{
	cocos2d::CCDirector::sharedDirector()->getPayment()->setDelegate(NULL);

	LOGGERSYSTEM->LogInfo("Destroy IAPSystem Success\n");
}