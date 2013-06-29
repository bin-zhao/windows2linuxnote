#ifndef  _COCOS2D_CCSPRITEFRAMEPROPERTY_H_
#define  _COCOS2D_CCSPRITEFRAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCSpriteFrameProperty : public CCProperty
{
public:
	CCSpriteFrameProperty();
	virtual ~CCSpriteFrameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
