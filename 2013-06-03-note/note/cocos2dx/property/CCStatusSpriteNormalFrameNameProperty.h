#ifndef  _COCOS2D_CCSTATUSSPRITENORMALFRAMENAMEPROPERTY_H_
#define  _COCOS2D_CCSTATUSSPRITENORMALFRAMENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCStatusSpriteNormalFrameNameProperty : public CCProperty
	{
	public:
		CCStatusSpriteNormalFrameNameProperty();
		virtual ~CCStatusSpriteNormalFrameNameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
