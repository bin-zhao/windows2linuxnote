#ifndef  _COCOS2D_CCMENUITEMIMAGESELECTEDFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGESELECTEDFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemImageSelectedFrameProperty : public CCProperty
{
public:
	CCMenuItemImageSelectedFrameProperty();
	virtual ~CCMenuItemImageSelectedFrameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
