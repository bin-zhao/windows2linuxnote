#ifndef  _COCOS2D_CCANCHORPROPERTY_H_
#define  _COCOS2D_CCANCHORPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnchorProperty : public CCProperty
{
public:
	CCAnchorProperty();
	virtual ~CCAnchorProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
