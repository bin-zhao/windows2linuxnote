#ifndef  _COCOS2D_CCLABELFONTNAMEPROPERTY_H_
#define  _COCOS2D_CCLABELFONTNAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLabelFontNameProperty : public CCProperty
{
public:
	CCLabelFontNameProperty();
	virtual ~CCLabelFontNameProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
