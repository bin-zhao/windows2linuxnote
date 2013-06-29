#ifndef  _COCOS2D_CCLABELHALIGNMENTPROPERTY_H_
#define  _COCOS2D_CCLABELHALIGNMENTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelHAlignmentProperty : public CCProperty
{
public:
	CCLabelHAlignmentProperty();
	virtual ~CCLabelHAlignmentProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
