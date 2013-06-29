#ifndef  _COCOS2D_CCMOVEACTIONPROPERTY_H_
#define  _COCOS2D_CCMOVEACTIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMoveActionProperty : public CCProperty
	{
	public:
		CCMoveActionProperty();
		virtual ~CCMoveActionProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
