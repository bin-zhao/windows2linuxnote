#ifndef  _COCOS2D_CCLABELHEIGHTPROPERTY_H_
#define  _COCOS2D_CCLABELHEIGHTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelHeightProperty : public CCProperty
{
public:
	CCLabelHeightProperty();
	virtual ~CCLabelHeightProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
