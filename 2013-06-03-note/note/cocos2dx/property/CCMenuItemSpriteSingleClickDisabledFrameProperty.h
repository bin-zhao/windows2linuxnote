#ifndef  _COCOS2D_CCMENUITEMSPRITESINGLECLICKDISABLEDFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITESINGLECLICKDISABLEDFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemSpriteSingleClickDisabledFrameProperty : public CCProperty
	{
	public:
		CCMenuItemSpriteSingleClickDisabledFrameProperty();
		virtual ~CCMenuItemSpriteSingleClickDisabledFrameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
