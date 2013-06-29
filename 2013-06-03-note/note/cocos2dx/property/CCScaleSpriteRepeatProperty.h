#ifndef  _COCOS2D_CCSCALESPRITEREPEATPROPERTY_H_
#define  _COCOS2D_CCSCALESPRITEREPEATPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleSpriteRepeatProperty : public CCProperty
	{
	public:
		CCScaleSpriteRepeatProperty();
		virtual ~CCScaleSpriteRepeatProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif