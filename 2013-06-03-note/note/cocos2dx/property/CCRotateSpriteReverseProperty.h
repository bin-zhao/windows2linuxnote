#ifndef  _COCOS2D_CCROTATESPRITEREVERSEPROPERTY_H_
#define  _COCOS2D_CCROTATESPRITEREVERSEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCRotateSpriteReverseProperty : public CCProperty
	{
	public:
		CCRotateSpriteReverseProperty();
		virtual ~CCRotateSpriteReverseProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif