#ifndef  _COCOS2D_CCMENUITEMTABSPRITESELECTEDPROPERTY_H_
#define  _COCOS2D_CCMENUITEMTABSPRITESELECTEDPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemTabSpriteSelectedProperty : public CCProperty
	{
	public:
		CCMenuItemTabSpriteSelectedProperty();
		virtual ~CCMenuItemTabSpriteSelectedProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
