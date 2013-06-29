#ifndef  _COCOS2D_CCPRIORITYPROPERTY_H_
#define  _COCOS2D_CCPRIORITYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCPriorityProperty : public CCProperty
{
public:
	CCPriorityProperty();
	virtual ~CCPriorityProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
