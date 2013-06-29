#ifndef  _COCOS2D_CCSCALELABELTTFPLAYINTERVALPROPERTY_H_
#define  _COCOS2D_CCSCALELABELTTFPLAYINTERVALPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleLabelTTFPlayIntervalProperty : public CCProperty
	{
	public:
		CCScaleLabelTTFPlayIntervalProperty();
		virtual ~CCScaleLabelTTFPlayIntervalProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif