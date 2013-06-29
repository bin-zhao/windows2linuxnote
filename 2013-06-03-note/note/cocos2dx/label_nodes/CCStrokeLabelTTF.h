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
#ifndef __CCSTROKELABEL_H__
#define __CCSTROKELABEL_H__
#include "CCLabelTTF.h"
#include "property/CCStrokeLabelStrokeColorProperty.h"
#include "property/CCStrokeLabelStrokeSizeProperty.h"

namespace cocos2d{

	/** @brief CCLabelTTF is a subclass of CCTextureNode that knows how to render text labels
	*
	* All features from CCTextureNode are valid in CCLabelTTF
	*
	* CCLabelTTF objects are slow. Consider using CCLabelAtlas or CCLabelBMFont instead.
	*/
	class CCRenderTexture;
	class CC_DLL CCStrokeLabelTTF : public CCLabelTTF
	{
	public:
		CCStrokeLabelTTF();
		virtual ~CCStrokeLabelTTF();

	public:
		virtual void setString(const char *label);
		virtual void setParent(CCNode * var);

	public:
		void setStrokeSize(int size);
		int  getStrokeSize();
		void setStrokeColor(ccColor3B color);
		ccColor3B getStrokeColor();
		
	public:
		CCRenderTexture* getStrokeRender();
		void updateStroke();

	private:
		void initStrokeRender();
		void destroyStrokeRender();

	protected:
		int       m_StrokeSize;
		ccColor3B m_StrokeColor;
		CCRenderTexture* m_pStrokeRender;

	public:
		static CCStrokeLabelStrokeColorProperty s_StrokeLabelStrokeColorProperty;
		static CCStrokeLabelStrokeSizeProperty s_StrokeLabelStrokeSizeProperty;
	};

} //namespace cocos2d
#endif //__CCLABEL_H__

