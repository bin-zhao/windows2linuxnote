#ifndef  _COCOS2D_CCMENUITEMSPRITESINGLECLICKNORMALFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITESINGLECLICKNORMALFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemSpriteSingleClickNormalFileProperty : public CCProperty
	{
	public:
		CCMenuItemSpriteSingleClickNormalFileProperty();
		virtual ~CCMenuItemSpriteSingleClickNormalFileProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
