#ifndef  _COCOS2D_CCANIMATIONSPRITEANIMATIONFRAMENAMEPROPERTY_H_
#define  _COCOS2D_CCANIMATIONSPRITEANIMATIONFRAMENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnimationSpriteAnimationFrameNameProperty : public CCProperty
{
public:
	CCAnimationSpriteAnimationFrameNameProperty();
	virtual ~CCAnimationSpriteAnimationFrameNameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
