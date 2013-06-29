#ifndef  _COCOS2D_CCSHAKESPRITEYMOVEPROPERTY_H_
#define  _COCOS2D_CCSHAKESPRITEYMOVEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCShakeSpriteYMoveProperty : public CCProperty
	{
	public:
		CCShakeSpriteYMoveProperty();
		virtual ~CCShakeSpriteYMoveProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif