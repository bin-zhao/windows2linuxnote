#ifndef  _COCOS2D_CCMENUITEMSPRITEPUSHEDSELECTEDFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSPRITEPUSHEDSELECTEDFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemSpritePushedSelectedFileProperty : public CCProperty
{
public:
	CCMenuItemSpritePushedSelectedFileProperty();
	virtual ~CCMenuItemSpritePushedSelectedFileProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
