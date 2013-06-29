#ifndef  _COCOS2D_CCMENUITEMTABSPRITENORMALFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMTABSPRITENORMALFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemTabSpriteNormalFrameProperty : public CCProperty
	{
	public:
		CCMenuItemTabSpriteNormalFrameProperty();
		virtual ~CCMenuItemTabSpriteNormalFrameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
