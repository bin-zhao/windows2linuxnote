/*
 * CCAccelerometer.h
 *
 *  Created on: Aug 9, 2011
 *      Author: laschweinski
 */

#ifndef CCSYSTEM_H_
#define CCSYSTEM_H_

#include "platform/CCSystemDelegate.h"

namespace   cocos2d {

class CCSystem
{
public:
    CCSystem(){}
    ~CCSystem(){}

public:
	void setDelegate(CCSystemDelegate* pDelegate){}

public:
	void setSysLang(int lang){}

public:
	void showFeedbackDialog(){}

public:
	void onAppExit(){}

public:
	bool isNetworkAvailable(){}
};

}//namespace   cocos2d

#endif /* CCACCELEROMETER_H_ */
