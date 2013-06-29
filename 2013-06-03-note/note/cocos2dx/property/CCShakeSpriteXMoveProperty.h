#ifndef  _COCOS2D_CCSHAKESPRITEXMOVEPROPERTY_H_
#define  _COCOS2D_CCSHAKESPRITEXMOVEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCShakeSpriteXMoveProperty : public CCProperty
	{
	public:
		CCShakeSpriteXMoveProperty();
		virtual ~CCShakeSpriteXMoveProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif