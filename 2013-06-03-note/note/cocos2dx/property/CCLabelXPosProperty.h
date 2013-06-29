#ifndef  _COCOS2D_CCLABELXPOSPROPERTY_H_
#define  _COCOS2D_CCLABELXPOSPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCLabelXPosProperty : public CCProperty
	{
	public:
		CCLabelXPosProperty();
		virtual ~CCLabelXPosProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
