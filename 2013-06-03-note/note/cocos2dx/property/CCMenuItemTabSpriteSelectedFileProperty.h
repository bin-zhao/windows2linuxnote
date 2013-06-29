#ifndef  _COCOS2D_CCMENUITEMTABSPRITESELECTEDFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMTABSPRITESELECTEDFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemTabSpriteSelectedFileProperty : public CCProperty
	{
	public:
		CCMenuItemTabSpriteSelectedFileProperty();
		virtual ~CCMenuItemTabSpriteSelectedFileProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
