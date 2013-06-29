#ifndef  _COCOS2D_CCPROGRESSBARPERCENTPROPERTY_H_
#define  _COCOS2D_CCPROGRESSBARPERCENTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCProgressBarPercentProperty : public CCProperty
{
public:
	CCProgressBarPercentProperty();
	virtual ~CCProgressBarPercentProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif