#ifndef  _COCOS2D_CCMENUITEMSCALEIMAGENORMALFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSCALEIMAGENORMALFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemScaleImageNormalFileProperty : public CCProperty
	{
	public:
		CCMenuItemScaleImageNormalFileProperty();
		virtual ~CCMenuItemScaleImageNormalFileProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
