#ifndef  _COCOS2D_CCROTATESPRITEROTATIONPROPERTY_H_
#define  _COCOS2D_CCROTATESPRITEROTATIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCRotateSpriteRotationProperty : public CCProperty
	{
	public:
		CCRotateSpriteRotationProperty();
		virtual ~CCRotateSpriteRotationProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif