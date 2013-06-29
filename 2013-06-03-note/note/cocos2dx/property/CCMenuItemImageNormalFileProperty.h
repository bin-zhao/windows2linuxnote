#ifndef  _COCOS2D_CCMENUITEMIMAGENORMALFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGENORMALFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemImageNormalFileProperty : public CCProperty
{
public:
	CCMenuItemImageNormalFileProperty();
	virtual ~CCMenuItemImageNormalFileProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
