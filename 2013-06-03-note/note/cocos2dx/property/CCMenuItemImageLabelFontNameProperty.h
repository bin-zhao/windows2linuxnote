#ifndef  _COCOS2D_CCMENUITEMIMAGELABELFONTNAMEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGELABELFONTNAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemImageLabelFontNameProperty : public CCProperty
	{
	public:
		CCMenuItemImageLabelFontNameProperty();
		virtual ~CCMenuItemImageLabelFontNameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif