#ifndef  _COCOS2D_CCCONTENTSIZEPROPERTY_H_
#define  _COCOS2D_CCCONTENTSIZEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

class CCContentSizeProperty : public CCProperty
{
public:
	CCContentSizeProperty();
	virtual ~CCContentSizeProperty();

public:
	virtual std::string	get(CCNode* receiver);
	virtual void set(CCNode* receiver, std::string value);
};

}

#endif
