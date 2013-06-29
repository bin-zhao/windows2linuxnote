#ifndef  _COCOS2D_CCANIMATIONSPRITEAUTOPLAYPROPERTY_H_
#define  _COCOS2D_CCANIMATIONSPRITEAUTOPLAYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCAnimationSpriteAutoPlayProperty : public CCProperty
{
public:
	CCAnimationSpriteAutoPlayProperty();
	virtual ~CCAnimationSpriteAutoPlayProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
