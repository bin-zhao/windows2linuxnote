#ifndef  _COCOS2D_CCFADEINACTIONPROPERTY_H_
#define  _COCOS2D_CCFADEINACTIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCFadeInActionProperty : public CCProperty
	{
	public:
		CCFadeInActionProperty();
		virtual ~CCFadeInActionProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
