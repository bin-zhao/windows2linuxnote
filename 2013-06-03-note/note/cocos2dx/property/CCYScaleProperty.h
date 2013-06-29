#ifndef  _COCOS2D_CCYSCALEPROPERTY_H_
#define  _COCOS2D_CCYSCALEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCYScaleProperty : public CCProperty
{
public:
	CCYScaleProperty();
	virtual ~CCYScaleProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif