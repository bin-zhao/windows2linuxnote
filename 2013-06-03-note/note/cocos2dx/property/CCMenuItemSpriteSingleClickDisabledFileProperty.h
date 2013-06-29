#ifndef  _COCOS2D_CCMENUITEMSPRITESINGLECLICKDISABLEDFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITESINGLECLICKDISABLEDFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemSpriteSingleClickDisabledFileProperty : public CCProperty
	{
	public:
		CCMenuItemSpriteSingleClickDisabledFileProperty();
		virtual ~CCMenuItemSpriteSingleClickDisabledFileProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
