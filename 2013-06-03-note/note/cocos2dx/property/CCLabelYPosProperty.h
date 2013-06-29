#ifndef  _COCOS2D_CCLABELYPOSPROPERTY_H_
#define  _COCOS2D_CCLABELYPOSPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCLabelYPosProperty : public CCProperty
	{
	public:
		CCLabelYPosProperty();
		virtual ~CCLabelYPosProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
