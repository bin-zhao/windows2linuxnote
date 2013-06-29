#ifndef  _COCOS2D_CCROTATIONPROPERTY_H_
#define  _COCOS2D_CCROTATIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCRotationProperty : public CCProperty
{
public:
	CCRotationProperty();
	virtual ~CCRotationProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif