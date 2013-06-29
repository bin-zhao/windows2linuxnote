#ifndef  _COCOS2D_CCMENUITEMIMAGEDISABLEDFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGEDISABLEDFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemImageDisabledFileProperty : public CCProperty
{
public:
	CCMenuItemImageDisabledFileProperty();
	virtual ~CCMenuItemImageDisabledFileProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
