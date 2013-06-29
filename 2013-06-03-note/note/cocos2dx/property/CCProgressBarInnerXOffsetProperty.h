#ifndef  _COCOS2D_CCPROGRESSBARINNERXOFFSETPROPERTY_H_
#define  _COCOS2D_CCPROGRESSBARINNERXOFFSETPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCProgressBarInnerXOffsetProperty : public CCProperty
{
public:
	CCProgressBarInnerXOffsetProperty();
	virtual ~CCProgressBarInnerXOffsetProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif