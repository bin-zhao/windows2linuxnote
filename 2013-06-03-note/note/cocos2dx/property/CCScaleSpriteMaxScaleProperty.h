#ifndef  _COCOS2D_CCSCALESPRITEMAXSCALEPROPERTY_H_
#define  _COCOS2D_CCSCALESPRITEMAXSCALEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleSpriteMaxScaleProperty : public CCProperty
	{
	public:
		CCScaleSpriteMaxScaleProperty();
		virtual ~CCScaleSpriteMaxScaleProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif