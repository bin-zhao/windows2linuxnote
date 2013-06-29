#ifndef  _COCOS2D_CCPROGRESSBARINNERFILENAMEPROPERTY_H_
#define  _COCOS2D_CCPROGRESSBARINNERFILENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCProgressBarInnerFileNameProperty : public CCProperty
{
public:
	CCProgressBarInnerFileNameProperty();
	virtual ~CCProgressBarInnerFileNameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif