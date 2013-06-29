#ifndef  _COCOS2D_CCMENUITEMSPRITESINGLECLICKNORMALFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITESINGLECLICKNORMALFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemSpriteSingleClickNormalFrameProperty : public CCProperty
	{
	public:
		CCMenuItemSpriteSingleClickNormalFrameProperty();
		virtual ~CCMenuItemSpriteSingleClickNormalFrameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
