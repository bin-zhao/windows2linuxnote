/*
 * CCAccelerometer.h
 *
 *  Created on: Aug 9, 2011
 *      Author: laschweinski
 */

#ifndef CCAD_H_
#define CCAD_H_

#include "platform/CCAdDelegate.h"

namespace   cocos2d {

class CCAd
{
public:
    CCAd(){}
    ~CCAd(){}

public:
	void setDelegate(CCAdDelegate* pDelegate){}

public:
	void showAd(bool bShow){}
	void showYoumiOfferWall(){}
	void showDianjoyOfferWall(){}
	void showImmobOfferWall(){}
	void showTapjoyOfferWall(){}
	void showDomobOfferWall(){}
	void show91OfferWall(){}
	void pushDianjoyAd(){}

public:
	void queryYoumiPoints(){}
	void queryDianjoyPoints(){}
	void queryImmobPoints(){}
	void queryTapjoyPoints(){}
	void queryDomobPoints(){}
	void query91Points(){}

public:
	void updateYoumiPoints(){}
	void updateDianjoyPoints(){}
	void updateImmobPoints(){}
	void updateTapjoyPoints(){}
	void updateDomobPoints(){}
	void update91Points(){}

public:
	void spendYoumiPoints(int amount){}
	void spendDianjoyPoints(int amount){}
	void spendImmobPoints(int amount){}
	void spendTapjoyPoints(int amount){}
	void spendDomobPoints(int amount){}
	void spend91Points(int amount){}

public:
	void receiveYoumiPoints(int amount){}
	void receiveDianjoyPoints(int amount){}
	void receiveImmobPoints(int amount){}
	void receiveTapjoyPoints(int amount){}
	void receiveDomobPoints(int amount){}
	void receive91Points(int amount){}
};

}//namespace   cocos2d

#endif /* CCACCELEROMETER_H_ */
