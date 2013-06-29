#ifndef  _COCOS2D_CCMENUITEMIMAGENORMALFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGENORMALFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemImageNormalFrameProperty : public CCProperty
{
public:
	CCMenuItemImageNormalFrameProperty();
	virtual ~CCMenuItemImageNormalFrameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
