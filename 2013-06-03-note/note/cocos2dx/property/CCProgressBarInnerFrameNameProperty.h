#ifndef  _COCOS2D_CCPROGRESSBARINNERFRAMENAMEPROPERTY_H_
#define  _COCOS2D_CCPROGRESSBARINNERFRAMENAMEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCProgressBarInnerFrameNameProperty : public CCProperty
	{
	public:
		CCProgressBarInnerFrameNameProperty();
		virtual ~CCProgressBarInnerFrameNameProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif