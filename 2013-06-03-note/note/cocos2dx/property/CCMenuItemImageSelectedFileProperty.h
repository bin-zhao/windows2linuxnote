#ifndef  _COCOS2D_CCMENUITEMIMAGESELECTEDFILEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGESELECTEDFILEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCMenuItemImageSelectedFileProperty : public CCProperty
{
public:
	CCMenuItemImageSelectedFileProperty();
	virtual ~CCMenuItemImageSelectedFileProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
