#ifndef  _COCOS2D_CCVISIBLEPROPERTY_H_
#define  _COCOS2D_CCVISIBLEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCVisibleProperty : public CCProperty
{
public:
	CCVisibleProperty();
	virtual ~CCVisibleProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif