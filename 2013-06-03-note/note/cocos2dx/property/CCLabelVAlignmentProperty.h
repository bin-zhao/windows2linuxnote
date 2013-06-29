#ifndef  _COCOS2D_CCLABELVALIGNMENTPROPERTY_H_
#define  _COCOS2D_CCLABELVALIGNMENTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelVAlignmentProperty : public CCProperty
{
public:
	CCLabelVAlignmentProperty();
	virtual ~CCLabelVAlignmentProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
