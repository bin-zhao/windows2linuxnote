#ifndef  _COCOS2D_CCLABELCOLORPROPERTY_H_
#define  _COCOS2D_CCLABELCOLORPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelColorProperty : public CCProperty
{
public:
	CCLabelColorProperty();
	virtual ~CCLabelColorProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
