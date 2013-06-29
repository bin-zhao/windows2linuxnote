#ifndef  _COCOS2D_CCMENUITEMIMAGEDISABLEDFRAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGEDISABLEDFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemImageDisabledFrameProperty : public CCProperty
{
public:
	CCMenuItemImageDisabledFrameProperty();
	virtual ~CCMenuItemImageDisabledFrameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
