#ifndef  _COCOS2D_CCSPRITETEXTURERECTPROPERTY_H_
#define  _COCOS2D_CCSPRITETEXTURERECTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCSpriteTextureRectProperty : public CCProperty
{
public:
	CCSpriteTextureRectProperty();
	virtual ~CCSpriteTextureRectProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
