#ifndef  _COCOS2D_CCMENUITEMSPRITEPUSHEDNORMALFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITEPUSHEDNORMALFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemSpritePushedNormalFileProperty : public CCProperty
{
public:
	CCMenuItemSpritePushedNormalFileProperty();
	virtual ~CCMenuItemSpritePushedNormalFileProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
