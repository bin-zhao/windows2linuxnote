#ifndef  _COCOS2D_CCANIMATIONSPRITEANIMATIONREPEATPROPERTY_H_
#define  _COCOS2D_CCANIMATIONSPRITEANIMATIONREPEATPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnimationSpriteAnimationRepeatProperty : public CCProperty
{
public:
	CCAnimationSpriteAnimationRepeatProperty();
	virtual ~CCAnimationSpriteAnimationRepeatProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
