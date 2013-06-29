#ifndef  _COCOS2D_CCSPRITEFLIPYPROPERTY_H_
#define  _COCOS2D_CCSPRITEFLIPYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCSpriteFlipYProperty : public CCProperty
	{
	public:
		CCSpriteFlipYProperty();
		virtual ~CCSpriteFlipYProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
