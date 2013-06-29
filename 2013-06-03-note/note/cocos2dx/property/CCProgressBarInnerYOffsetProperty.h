#ifndef  _COCOS2D_CCPROGRESSBARINNERYOFFSETPROPERTY_H_
#define  _COCOS2D_CCPROGRESSBARINNERYOFFSETPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCProgressBarInnerYOffsetProperty : public CCProperty
{
public:
	CCProgressBarInnerYOffsetProperty();
	virtual ~CCProgressBarInnerYOffsetProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif