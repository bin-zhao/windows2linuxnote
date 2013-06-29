#ifndef  _COCOS2D_CCSTROKELABELSTROKESIZEPROPERTY_H_
#define  _COCOS2D_CCSTROKELABELSTROKESIZEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCStrokeLabelStrokeSizeProperty : public CCProperty
	{
	public:
		CCStrokeLabelStrokeSizeProperty();
		virtual ~CCStrokeLabelStrokeSizeProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
