/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CCFADELABEL_H__
#define __CCFADELABEL_H__

#include "CCLabelTTF.h"

namespace cocos2d{

	/** @brief CCFadeLabelTTF is a subclass of CCTextureNode that knows how to render text labels
	*
	* All features from CCTextureNode are valid in CCFadeLabelTTF
	*
	* CCFadeLabelTTF objects are slow. Consider using CCLabelAtlas or CCLabelBMFont instead.
	*/
	class CC_DLL CCAnimationLabelTTF : public CCLabelTTF
	{
	protected:
		bool  m_bScale;
		bool  m_bFadeIn;
		bool  m_bMoveBy;

	protected:
		float m_MaxScale;
		float m_ScaleTime;
		float m_FadeInTime;
		float m_FadeOutTime;
		float m_MoveByTime;
		float m_MoveByXPos;
		float m_MoveByYPos;

	protected:
		CCAction* m_pAction;

	public:
		CCAnimationLabelTTF();
		virtual ~CCAnimationLabelTTF();

	public:
		char * description();

	public:
		//! set whether scale
		void  setIsScale(bool bScale);
		//! get whether scale
		bool  getIsScale();
		//! set whether scale
		void  setIsFadeIn(bool bFadeIn);
		//! get whether scale
		bool  getIsFadeIn();
		//! set whether scale
		void  setIsMoveBy(bool bMoveBy);
		//! get whether scale
		bool  getIsMoveBy();

	public:
		//! set max scale
		void  setMaxScale(float maxScale);
		//! get max scale
		float getMaxScale();
		//! set scale time
		void  setScaleTime(float time);
		//! get scale time
		float getScaleTime();
		//! set fadein time
		void  setFadeInTime(float time);
		//! get fadein time
		float getFadeInTime();
		//! set fadeout time
		void  setFadeOutTime(float time);
		//! get fadeout time
		float getFadeOutTime();
		//! set moveby time
		void  setMoveByTime(float time);
		//! get moveby time
		float getMoveByTime();
		//! set moveby xpos
		void  setMoveByXPos(float xPos);
		//! get moveby xpos
		float getMoveByXPos();
		//! set moveby ypos
		void  setMoveByYPos(float yPos);
		//! get moveby ypos
		float getMoveByYPos();

	public:
		//! start animation text effect
		void  start();
		//! stop animation text effect
		void  stop();

	private:
		void  callback();

	public:
		virtual bool init();
	};

} //namespace cocos2d
#endif //__CCFADELABEL_H__

