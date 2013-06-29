#ifndef  _COCOS2D_CCMENUITEMSCRIPTEVENTPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSCRIPTEVENTPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemScriptEventProperty : public CCProperty
	{
	public:
		CCMenuItemScriptEventProperty();
		virtual ~CCMenuItemScriptEventProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
