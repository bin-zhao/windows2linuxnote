#ifndef  _COCOS2D_CCSTATUSSPRITENORMALFILENAMEPROPERTY_H_
#define  _COCOS2D_CCSTATUSSPRITENORMALFILENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCStatusSpriteNormalFileNameProperty : public CCProperty
	{
	public:
		CCStatusSpriteNormalFileNameProperty();
		virtual ~CCStatusSpriteNormalFileNameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
