#ifndef  _NINJIATRIBE_IAPSYSTEM_H_
#define  _NINJIATRIBE_IAPSYSTEM_H_


#include <include/common/Singleton.h>
#include <cocos2d.h>
using  namespace  cobra_win;

class IAPSystem : public cocos2d::CCPaymentDelegate, public cobra_win::Singleton2<IAPSystem>
{
public:
	enum
	{
		_TYPED_VERIFY_UNKOWN_, // 未知类型
		_TYPED_VERIFY_LOCAL_,  // 本地校验
		_TYPED_VERIFY_SERVER_, // 服务器校验
	};

public:
	IAPSystem();
	virtual ~IAPSystem();

public:
	/*
		校验指定的订单号
	*/
	void  VerifyIAPIdentifier();

public:
	/*
		初始化交易系统管理器
	*/
	bool  Init();
	/*
		交易系统逻辑桢更新
	*/
	void  Tick();
	/*
		销毁交易系统管理器
	*/
	void  Destroy();

public:
	/*
		购买失败
	*/
	virtual  void  onPayFailed(std::string IAPId, std::string error);
	/*
		购买成功
	*/
	virtual  void  onPaySuccess(std::string IAPId);
	/*
		校验订单成功
	*/
	virtual  void  onVerifySuccess(std::string IAPId);
	/*
		校验订单失败
	*/
	virtual  void  onVerifyFailed(std::string IAPId, std::string error);

public:
	friend  class  cobra_win::Singleton2<IAPSystem>;
};

#define  IAPSYSTEM  (IAPSystem::get_instance2())


#endif
