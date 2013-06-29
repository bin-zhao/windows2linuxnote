#ifndef  _COCOS2D_CCLAYERCOLORPROPERTY_H_
#define  _COCOS2D_CCLAYERCOLORPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCLayerColorProperty : public CCProperty
{
public:
	CCLayerColorProperty();
	virtual ~CCLayerColorProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
