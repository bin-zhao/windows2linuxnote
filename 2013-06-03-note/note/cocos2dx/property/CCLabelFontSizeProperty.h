#ifndef  _COCOS2D_CCLABELFONTSIZEPROPERTY_H_
#define  _COCOS2D_CCLABELFONTSIZEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelFontSizeProperty : public CCProperty
{
public:
	CCLabelFontSizeProperty();
	virtual ~CCLabelFontSizeProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
