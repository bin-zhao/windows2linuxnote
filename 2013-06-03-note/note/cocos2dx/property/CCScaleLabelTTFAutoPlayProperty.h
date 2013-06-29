#ifndef  _COCOS2D_CCSCALELABELTTFAUTOPLAYPROPERTY_H_
#define  _COCOS2D_CCSCALELABELTTFAUTOPLAYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCScaleLabelTTFAutoPlayProperty : public CCProperty
	{
	public:
		CCScaleLabelTTFAutoPlayProperty();
		virtual ~CCScaleLabelTTFAutoPlayProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif