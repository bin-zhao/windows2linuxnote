#ifndef  _COCOS2D_CCSTROKELABELSTROKECOLORPROPERTY_H_
#define  _COCOS2D_CCSTROKELABELSTROKECOLORPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCStrokeLabelStrokeColorProperty : public CCProperty
	{
	public:
		CCStrokeLabelStrokeColorProperty();
		virtual ~CCStrokeLabelStrokeColorProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
