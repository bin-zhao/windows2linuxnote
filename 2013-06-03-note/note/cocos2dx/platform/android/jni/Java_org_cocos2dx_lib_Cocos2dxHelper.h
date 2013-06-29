/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

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
#ifndef __Java_org_cocos2dx_lib_Cocos2dxHelper_H__
#define __Java_org_cocos2dx_lib_Cocos2dxHelper_H__

#include <string>

typedef void (*EditTextCallback)(const char* pText, void* ctx);

extern "C" {
    extern const char * getApkPath();
	extern const char * getAndroidUDID();
	extern const char * getAndroidIMEI();
	extern const char * getAndroidMacAddr();
    extern void showDialogJNI(const char * pszMsg, const char * pszTitle);
    extern void showEditTextDialogJNI(const char* pszTitle, const char* pszContent, int nInputMode, int nInputFlag, int nReturnType, int nMaxLength, EditTextCallback pfEditTextCallback, void* ctx);
    extern void terminateProcessJNI();
    extern const char * getCurrentLanguageJNI();
    extern const char * getPackageNameJNI();
    extern void enableAccelerometerJNI();
    extern void disableAccelerometerJNI();

	extern void enableAdJNI();
	extern void disableAdJNI();

	extern void showYoumiOfferWallJNI();
	extern void showDianjoyOfferWallJNI();
	extern void showImmobOfferWallJNI();
	extern void showTapjoyOfferWallJNI();
	extern void showDomobOfferWallJNI();
	extern void show91OfferWallJNI();
	extern void pushDianjoyAdJNI();

	extern void queryYoumiPointsJNI();
	extern void queryDianjoyPointsJNI();
	extern void queryImmobPointsJNI();
	extern void queryTapjoyPointsJNI();
	extern void queryDomobPointsJNI();
	extern void query91PointsJNI();

	extern void updateYoumiPointsJNI();
	extern void updateDianjoyPointsJNI();
	extern void updateImmobPointsJNI();
	extern void updateTapjoyPointsJNI();
	extern void updateDomobPointsJNI();
	extern void update91PointsJNI();

	extern void spendYoumiPointsJNI(int amount);
	extern void spendDianjoyPointsJNI(int amount);
	extern void spendImmobPointsJNI(int amount);
	extern void spendTapjoyPointsJNI(int amount);
	extern void spendDomobPointsJNI(int amount);
	extern void spend91PointsJNI(int amount);

	extern void loginRennJNI();
	extern void shareTextInRennJNI(const char * pText);
	extern void sharePictureInRennJNI(const char * pFile, const char * pText);
	extern void loginWeiboJNI();
	extern void shareTextInWeiboJNI(const char * pText);
	extern void sharePictureInWeiboJNI(const char * pFile, const char * pText);
	extern void loginQQJNI();
	extern void shareTextInQQJNI(const char * pText);
	extern void sharePictureInQQJNI(const char * pFile, const char * pText);
	extern void loginFacebookJNI();
	extern void shareTextInFacebookJNI(const char * pText);
	extern void sharePictureInFacebookJNI(const char * pFile, const char * pText);
	extern void loginTwitterJNI();
	extern void shareTextInTwitterJNI(const char * pText);
	extern void sharePictureInTwitterJNI(const char * pFile, const char * pText);

	extern void payJNI(const char * pProductId, const char * pProductName, const char * pProductDesc, float productMoney, int chargePoint, const char * pIAPId);
	extern void verifyJNI(const char * pIAPId);

	extern void openURLJNI(const char* pURL);

	extern void setSysLangJNI(int type);

	extern void playerBehaviorLogEventJNI(const char* pText);
	extern void playerBehaviorLogEventWithLabelJNI(const char* pText, const char* pLable);
	extern void playerBehaviorBeginLogEventJNI(const char* pText);
	extern void playerBehaviorEndLogEventJNI(const char* pText);

	extern void showFeedbackDialogJNI();

	extern void isGameCenterAvailableJNI();
	extern void authenticateGameCenterJNI();
	extern void showLeaderBoardJNI(const char* pCategory);
	extern void reportGameScoreJNI(const char* pCategory, long long score);
	extern void submitAchievementJNI(const char* pIdentifier, double percentComplete);
}

#endif
