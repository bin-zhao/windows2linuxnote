#ifndef  _COCOS2D_CCROTATESPRITEREPEATPROPERTY_H_
#define  _COCOS2D_CCROTATESPRITEREPEATPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCRotateSpriteRepeatProperty : public CCProperty
	{
	public:
		CCRotateSpriteRepeatProperty();
		virtual ~CCRotateSpriteRepeatProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif