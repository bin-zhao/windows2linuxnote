#ifndef  _COCOS2D_CCROTATESPRITEAUTOPLAYPROPERTY_H_
#define  _COCOS2D_CCROTATESPRITEAUTOPLAYPROPERTY_H_

#include "CCProperty.h"

namespace  cocos2d
{

	class CCRotateSpriteAutoPlayProperty : public CCProperty
	{
	public:
		CCRotateSpriteAutoPlayProperty();
		virtual ~CCRotateSpriteAutoPlayProperty();

	public:
		virtual std::string	get(CCNode* receiver);
		virtual void set(CCNode* receiver, std::string value);
	};

}

#endif