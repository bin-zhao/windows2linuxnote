#ifndef  _COCOS2D_CCSHAKESPRITEAUTOPLAYPROPERTY_H_
#define  _COCOS2D_CCSHAKESPRITEAUTOPLAYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCShakeSpriteAutoPlayProperty : public CCProperty
	{
	public:
		CCShakeSpriteAutoPlayProperty();
		virtual ~CCShakeSpriteAutoPlayProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif