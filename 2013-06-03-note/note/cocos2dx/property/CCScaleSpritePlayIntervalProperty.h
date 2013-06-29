#ifndef  _COCOS2D_CCSCALESPRITEPLAYINTERVALPROPERTY_H_
#define  _COCOS2D_CCSCALESPRITEPLAYINTERVALPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleSpritePlayIntervalProperty : public CCProperty
	{
	public:
		CCScaleSpritePlayIntervalProperty();
		virtual ~CCScaleSpritePlayIntervalProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif