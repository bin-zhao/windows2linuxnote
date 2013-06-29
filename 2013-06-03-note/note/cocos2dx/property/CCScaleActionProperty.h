#ifndef  _COCOS2D_CCSCALEACTIONPROPERTY_H_
#define  _COCOS2D_CCSCALEACTIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleActionProperty : public CCProperty
	{
	public:
		CCScaleActionProperty();
		virtual ~CCScaleActionProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
