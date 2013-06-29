#ifndef  _COCOS2D_CCROTATEACTIONPROPERTY_H_
#define  _COCOS2D_CCROTATEACTIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCRotateActionProperty : public CCProperty
	{
	public:
		CCRotateActionProperty();
		virtual ~CCRotateActionProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
