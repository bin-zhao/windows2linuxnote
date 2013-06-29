#ifndef  _COCOS2D_CCMENUITEMSPRITEPUSHEDSELECTEDFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITEPUSHEDSELECTEDFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemSpritePushedSelectedFrameProperty : public CCProperty
{
public:
	CCMenuItemSpritePushedSelectedFrameProperty();
	virtual ~CCMenuItemSpritePushedSelectedFrameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
