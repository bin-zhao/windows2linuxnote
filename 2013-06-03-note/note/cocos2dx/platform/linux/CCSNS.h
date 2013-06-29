/*
 * CCAccelerometer.h
 *
 *  Created on: Aug 9, 2011
 *      Author: laschweinski
 */

#ifndef CCSNS_H_
#define CCSNS_H_

#include "platform/CCSNSDelegate.h"

namespace   cocos2d {

class CCSNS
{
public:
    CCSNS(){}
    ~CCSNS(){}

public:
	void setDelegate(CCSNSDelegate* pDelegate){}

public:
	void loginRenn(){}
	void shareTextInRenn(std::string text){}
	void sharePictureInRenn(std::string file, std::string text){}
	void loginWeibo(){}
	void shareTextInWeibo(std::string text){}
	void sharePictureInWeibo(std::string file, std::string text){}
	void loginQQ(){}
	void shareTextInQQ(std::string text){}
	void sharePictureInQQ(std::string file, std::string text){}
	void loginFacebook(){}
	void shareTextInFacebook(std::string text){}
	void sharePictureInFacebook(std::string file, std::string text){}
	void loginTwitter(){}
	void shareTextInTwitter(std::string text){}
	void sharePictureInTwitter(std::string file, std::string text){}

public:
	void onLoginRennSuccess(){}
	void onLoginRennFailed(std::string error){}
	void onShareTextInRennSuccess(){}
	void onShareTextInRennFailed(std::string error){}
	void onSharePictureInRennSuccess(){}
	void onSharePictureInRennFailed(std::string error){}

public:
	void onLoginWeiboSuccess(){}
	void onLoginWeiboFailed(std::string error){}
	void onShareTextInWeiboSuccess(){}
	void onShareTextInWeiboFailed(std::string error){}
	void onSharePictureInWeiboSuccess(){}
	void onSharePictureInWeiboFailed(std::string error){}

public:
	void onLoginQQSuccess(){}
	void onLoginQQFailed(std::string error){}
	void onShareTextInQQSuccess(){}
	void onShareTextInQQFailed(std::string error){}
	void onSharePictureInQQSuccess(){}
	void onSharePictureInQQFailed(std::string error){}

public:
	void onLoginFacebookSuccess(){}
	void onLoginFacebookFailed(std::string error){}
	void onShareTextInFacebookSuccess(){}
	void onShareTextInFacebookFailed(std::string error){}
	void onSharePictureInFacebookSuccess(){}
	void onSharePictureInFacebookFailed(std::string error){}

public:
	void onLoginTwitterSuccess(){}
	void onLoginTwitterFailed(std::string error){}
	void onShareTextInTwitterSuccess(){}
	void onShareTextInTwitterFailed(std::string error){}
	void onSharePictureInTwitterSuccess(){}
	void onSharePictureInTwitterFailed(std::string error){}
};

}//namespace   cocos2d

#endif /* CCACCELEROMETER_H_ */
