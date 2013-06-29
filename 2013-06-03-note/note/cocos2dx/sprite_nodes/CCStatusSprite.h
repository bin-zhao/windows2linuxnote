/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2011      Zynga Inc.

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

#ifndef __SPITE_NODE_CCSTATUSSPRITE_H__
#define __SPITE_NODE_CCSTATUSSPRITE_H__

#include "CCSprite.h"
#include "property/CCStatusSpriteNormalFileNameProperty.h"
#include "property/CCStatusSpriteNormalFrameNameProperty.h"
#include "property/CCStatusSpriteStatusProperty.h"
#include "property/CCStatusSpriteUnNormalFileNameProperty.h"
#include "property/CCStatusSpriteUnNormalFrameNameProperty.h"
#include <string>
namespace   cocos2d {

class CC_DLL CCStatusSprite : public CCSprite
{
public:
	enum
	{
		_TYPED_STATUS_UNKOWN_,    // 未知状态
		_TYPED_STATUS_NORMAL_,    // 正常状态
		_TYPED_STATUS_UNNORMAL_,  // 非正常状态
	};

protected:
	std::string m_NormalStatusFrameName;
	std::string m_UnNormalStatusFrameName;

	std::string m_NormalStatusFileName;
	std::string m_UnNormalStatusFileName;

protected:
	int m_Status;

public:
	CCStatusSprite(void);
	virtual ~CCStatusSprite(void);

public:
	//! get status
	int getStatus();
	//! set status
	void setStatus(int status);

public:
	//! set normal status frame name
	void setNormalStatusFrameName(std::string name);
	//! get normal status frame name
	std::string getNormalStatusFrameName();
	//! set unnormal status frame name
	void setUnNormalStatusFrameName(std::string name);
	//! get unnormal status frame name
	std::string getUnNormalStatusFrameName();
	//! set normal status file name
	void setNormalStatusFileName(std::string name);
	//! get normal status file name
	std::string getNormalStatusFileName();
	// set unnormal status file name
	void setUnNormalStatusFileName(std::string name);
	// get unnormal status file name
	std::string getUnNormalStatusFileName();

private:
	static CCStatusSpriteNormalFileNameProperty s_StatusSpriteNormalFileNameProperty;
	static CCStatusSpriteNormalFrameNameProperty s_StatusSpriteNormalFrameNameProperty;
	static CCStatusSpriteStatusProperty s_StatusSpriteStatusProperty;
	static CCStatusSpriteUnNormalFileNameProperty s_StatusSpriteUnNormalFileNameProperty;
	static CCStatusSpriteUnNormalFrameNameProperty s_StatusSpriteUnNormalFrameNameProperty;
};
}//namespace   cocos2d 

#endif // __SPITE_NODE_CCSPRITE_H__
