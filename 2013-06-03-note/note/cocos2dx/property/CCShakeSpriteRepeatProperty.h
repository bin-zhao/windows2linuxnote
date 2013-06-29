#ifndef  _COCOS2D_CCSHAKESPRITEREPEATPROPERTY_H_
#define  _COCOS2D_CCSHAKESPRITEREPEATPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCShakeSpriteRepeatProperty : public CCProperty
	{
	public:
		CCShakeSpriteRepeatProperty();
		virtual ~CCShakeSpriteRepeatProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif