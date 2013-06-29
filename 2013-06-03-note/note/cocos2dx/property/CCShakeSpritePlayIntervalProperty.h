#ifndef  _COCOS2D_CCSHAKESPRITEPLAYINTERVALPROPERTY_H_
#define  _COCOS2D_CCSHAKESPRITEPLAYINTERVALPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCShakeSpritePlayIntervalProperty : public CCProperty
	{
	public:
		CCShakeSpritePlayIntervalProperty();
		virtual ~CCShakeSpritePlayIntervalProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif