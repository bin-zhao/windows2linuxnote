#ifndef  _COCOS2D_CCMENUITEMIMAGELABELTEXTPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGELABELTEXTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemImageLabelTextProperty : public CCProperty
	{
	public:
		CCMenuItemImageLabelTextProperty();
		virtual ~CCMenuItemImageLabelTextProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif