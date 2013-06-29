#ifndef  _COCOS2D_CCSPRITEFLIPXPROPERTY_H_
#define  _COCOS2D_CCSPRITEFLIPXPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCSpriteFlipXProperty : public CCProperty
	{
	public:
		CCSpriteFlipXProperty();
		virtual ~CCSpriteFlipXProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
