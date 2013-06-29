#ifndef  _COCOS2D_CCMENUITEMIMAGELABELFONTSIZEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMIMAGELABELFONTSIZEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemImageLabelFontSizeProperty : public CCProperty
	{
	public:
		CCMenuItemImageLabelFontSizeProperty();
		virtual ~CCMenuItemImageLabelFontSizeProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif