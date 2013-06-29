#ifndef  _COCOS2D_CCPOSITIONPROPERTY_H_
#define  _COCOS2D_CCPOSITIONPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCPositionProperty : public CCProperty
{
public:
	CCPositionProperty();
	virtual ~CCPositionProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
