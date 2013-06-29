#ifndef  _COCOS2D_CCANIMATIONSPRITEANIMATIONINTERVALPROPERTY_H_
#define  _COCOS2D_CCANIMATIONSPRITEANIMATIONINTERVALPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnimationSpriteAnimationIntervalProperty : public CCProperty
{
public:
	CCAnimationSpriteAnimationIntervalProperty();
	virtual ~CCAnimationSpriteAnimationIntervalProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
