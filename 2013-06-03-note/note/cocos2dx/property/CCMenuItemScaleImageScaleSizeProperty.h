#ifndef  _COCOS2D_CCMENUITEMSCALEIMAGESCALESIZEPROPERTY_H_
#define  _COCOS2D_CCMENUITEMSCALEIMAGESCALESIZEPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCMenuItemScaleImageScaleSizeProperty : public CCProperty
	{
	public:
		CCMenuItemScaleImageScaleSizeProperty();
		virtual ~CCMenuItemScaleImageScaleSizeProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif
