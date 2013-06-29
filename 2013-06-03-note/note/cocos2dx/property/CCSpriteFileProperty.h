#ifndef  _COCOS2D_CCSPRITEFILEPROPERTY_H_
#define  _COCOS2D_CCSPRITEFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCSpriteFileProperty : public CCProperty
{
public:
	CCSpriteFileProperty();
	virtual ~CCSpriteFileProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
