#ifndef  _COCOS2D_CCMENUITEMTABSPRITESELECTEDFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMTABSPRITESELECTEDFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemTabSpriteSelectedFrameProperty : public CCProperty
	{
	public:
		CCMenuItemTabSpriteSelectedFrameProperty();
		virtual ~CCMenuItemTabSpriteSelectedFrameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
