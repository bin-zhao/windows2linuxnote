#ifndef  _COCOS2D_CCMENUITEMTABSPRITENORMALFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMTABSPRITENORMALFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemTabSpriteNormalFileProperty : public CCProperty
	{
	public:
		CCMenuItemTabSpriteNormalFileProperty();
		virtual ~CCMenuItemTabSpriteNormalFileProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
