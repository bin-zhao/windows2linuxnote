#ifndef  _COCOS2D_CCMENUITEMSPRITEPUSHEDDISABLEDFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITEPUSHEDDISABLEDFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemSpritePushedDisabledFileProperty : public CCProperty
	{
	public:
		CCMenuItemSpritePushedDisabledFileProperty();
		virtual ~CCMenuItemSpritePushedDisabledFileProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
