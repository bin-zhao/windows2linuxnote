#ifndef  _COCOS2D_CCLAYERSIZEPROPERTY_H_
#define  _COCOS2D_CCLAYERSIZEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLayerSizeProperty : public CCProperty
{
public:
	CCLayerSizeProperty();
	virtual ~CCLayerSizeProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
