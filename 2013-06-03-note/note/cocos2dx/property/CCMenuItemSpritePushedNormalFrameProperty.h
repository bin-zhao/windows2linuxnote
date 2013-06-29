#ifndef  _COCOS2D_CCMENUITEMSPRITEPUSHEDNORMALFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITEPUSHEDNORMALFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemSpritePushedNormalFrameProperty : public CCProperty
{
public:
	CCMenuItemSpritePushedNormalFrameProperty();
	virtual ~CCMenuItemSpritePushedNormalFrameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
