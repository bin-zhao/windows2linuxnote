#ifndef  _COCOS2D_CCANIMATIONSPRITEANIMATIONFRAMECOUNTPROPERTY_H_
#define  _COCOS2D_CCANIMATIONSPRITEANIMATIONFRAMECOUNTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnimationSpriteAnimationFrameCountProperty : public CCProperty
{
public:
	CCAnimationSpriteAnimationFrameCountProperty();
	virtual ~CCAnimationSpriteAnimationFrameCountProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
