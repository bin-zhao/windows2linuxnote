#ifndef  _COCOS2D_CCSTATUSSPRITEUNNORMALFILENAMEPROPERTY_H_
#define  _COCOS2D_CCSTATUSSPRITEUNNORMALFILENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCStatusSpriteUnNormalFileNameProperty : public CCProperty
	{
	public:
		CCStatusSpriteUnNormalFileNameProperty();
		virtual ~CCStatusSpriteUnNormalFileNameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
