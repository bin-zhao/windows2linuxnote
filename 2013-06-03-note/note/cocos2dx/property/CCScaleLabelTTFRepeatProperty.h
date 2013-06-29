#ifndef  _COCOS2D_CCSCALELABELTTFREPEATPROPERTY_H_
#define  _COCOS2D_CCSCALELABELTTFREPEATPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleLabelTTFRepeatProperty : public CCProperty
	{
	public:
		CCScaleLabelTTFRepeatProperty();
		virtual ~CCScaleLabelTTFRepeatProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif