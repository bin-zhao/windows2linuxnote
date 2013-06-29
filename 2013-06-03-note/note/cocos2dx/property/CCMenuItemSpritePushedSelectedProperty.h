#ifndef  _COCOS2D_CCMENUITEMSPRITEPUSHEDSELECTEDPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITEPUSHEDSELECTEDPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemSpritePushedSelectedProperty : public CCProperty
	{
	public:
		CCMenuItemSpritePushedSelectedProperty();
		virtual ~CCMenuItemSpritePushedSelectedProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
