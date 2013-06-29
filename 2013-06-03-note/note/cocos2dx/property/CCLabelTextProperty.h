#ifndef  _COCOS2D_CCLABELTEXTPROPERTY_H_
#define  _COCOS2D_CCLABELTEXTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelTextProperty : public CCProperty
{
public:
	CCLabelTextProperty();
	virtual ~CCLabelTextProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
