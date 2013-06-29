#ifndef  _COCOS2D_CCSCALELABELTTFMAXSCALEPROPERTY_H_
#define  _COCOS2D_CCSCALELABELTTFMAXSCALEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleLabelTTFMaxScaleProperty : public CCProperty
	{
	public:
		CCScaleLabelTTFMaxScaleProperty();
		virtual ~CCScaleLabelTTFMaxScaleProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif