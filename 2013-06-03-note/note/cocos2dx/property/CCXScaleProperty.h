﻿#ifndef  _COCOS2D_CCXSCALEPROPERTY_H_
#define  _COCOS2D_CCXSCALEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCXScaleProperty : public CCProperty
{
public:
	CCXScaleProperty();
	virtual ~CCXScaleProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif