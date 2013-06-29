#ifndef  _COCOS2D_CCNODEPRIORITYPROPERTY_H_
#define  _COCOS2D_CCNODEPRIORITYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCNodePriorityProperty : public CCProperty
{
public:
	CCNodePriorityProperty();
	virtual ~CCNodePriorityProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
