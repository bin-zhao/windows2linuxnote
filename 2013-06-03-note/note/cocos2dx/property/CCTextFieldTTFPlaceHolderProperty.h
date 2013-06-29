#ifndef  _COCOS2D_CCTEXTFIELDTTFPLACEHOLDERPROPERTY_H_
#define  _COCOS2D_CCTEXTFIELDTTFPLACEHOLDERPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCTextFieldTTFPlaceHolderProperty : public CCProperty
	{
	public:
		CCTextFieldTTFPlaceHolderProperty();
		virtual ~CCTextFieldTTFPlaceHolderProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif