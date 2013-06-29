#ifndef  _COCOS2D_CCFADEOUTACTIONPROPERTY_H_
#define  _COCOS2D_CCFADEOUTACTIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCFadeOutActionProperty : public CCProperty
	{
	public:
		CCFadeOutActionProperty();
		virtual ~CCFadeOutActionProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
