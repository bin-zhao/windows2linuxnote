#ifndef  _COCOS2D_CCSTATUSSPRITEUNNORMALFRAMENAMEPROPERTY_H_
#define  _COCOS2D_CCSTATUSSPRITEUNNORMALFRAMENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCStatusSpriteUnNormalFrameNameProperty : public CCProperty
	{
	public:
		CCStatusSpriteUnNormalFrameNameProperty();
		virtual ~CCStatusSpriteUnNormalFrameNameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
