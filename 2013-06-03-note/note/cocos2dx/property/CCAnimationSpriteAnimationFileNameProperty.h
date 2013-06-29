#ifndef  _COCOS2D_CCANIMATIONSPRITEANIMATIONFILENAMEPROPERTY_H_
#define  _COCOS2D_CCANIMATIONSPRITEANIMATIONFILENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnimationSpriteAnimationFileNameProperty : public CCProperty
{
public:
	CCAnimationSpriteAnimationFileNameProperty();
	virtual ~CCAnimationSpriteAnimationFileNameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif