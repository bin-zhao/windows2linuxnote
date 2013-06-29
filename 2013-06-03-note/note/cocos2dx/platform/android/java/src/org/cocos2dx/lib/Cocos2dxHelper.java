/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

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
package org.cocos2dx.lib;

import java.io.UnsupportedEncodingException;
import java.util.Locale;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.res.AssetManager;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Environment;
import android.telephony.TelephonyManager;


public class Cocos2dxHelper {
	// ===========================================================
	// Constants
	// ===========================================================

	// ===========================================================
	// Fields
	// ===========================================================

	public static Cocos2dxMusic sCocos2dMusic;
	public static Cocos2dxSound sCocos2dSound;
	public static AssetManager sAssetManager;
	public static Cocos2dxAccelerometer sCocos2dxAccelerometer;
	public static Cocos2dxAd sCocos2dxAd;
	public static Cocos2dxSNS sCocos2dxSNS;
	public static Cocos2dxPayment sCocos2dxPayment;
	public static Cocos2dxSystem sCocos2dxSystem;
	public static Cocos2dxPlayerBehaviorTrace sCocos2dxPlayerBehaviorTrace;
	public static boolean sAccelerometerEnabled;
	public static String sPackageName;

	public static Cocos2dxHelperListener sCocos2dxHelperListener;

	// ===========================================================
	// Constructors
	// ===========================================================

	public static void init(final Context pContext, final Cocos2dxHelperListener pCocos2dxHelperListener) {
		final ApplicationInfo applicationInfo = pContext.getApplicationInfo();

		Cocos2dxHelper.sCocos2dxHelperListener = pCocos2dxHelperListener;

		// 获得设备信息
		TelephonyManager tm = (TelephonyManager)((Cocos2dxActivity)pContext).getSystemService(YojiSyntheTown.TELEPHONY_SERVICE);
		WifiManager wifi = (WifiManager)((Cocos2dxActivity)pContext).getSystemService(Context.WIFI_SERVICE);    
		WifiInfo info = wifi.getConnectionInfo();
		Cocos2dxHelper.nativeSetAndroidIMEI(info.getMacAddress());
		
		Cocos2dxHelper.sPackageName = applicationInfo.packageName;
		Cocos2dxHelper.nativeSetApkPath(applicationInfo.sourceDir);
		Cocos2dxHelper.nativeSetAndroidIMEI(tm.getDeviceId());
		Cocos2dxHelper.nativeSetExternalAssetPath(Cocos2dxHelper.getAbsolutePathOnExternalStorage(applicationInfo, "assets/"));

		Cocos2dxHelper.sCocos2dxAccelerometer = new Cocos2dxAccelerometer(pContext);
		Cocos2dxHelper.sCocos2dxAd = new Cocos2dxAd(pContext);
		Cocos2dxHelper.sCocos2dxSNS = new Cocos2dxSNS(pContext);
		Cocos2dxHelper.sCocos2dxPayment = new Cocos2dxPayment(pContext);
		Cocos2dxHelper.sCocos2dxSystem = new Cocos2dxSystem(pContext);
		Cocos2dxHelper.sCocos2dxPlayerBehaviorTrace = new Cocos2dxPlayerBehaviorTrace(pContext);
		Cocos2dxHelper.sCocos2dMusic = new Cocos2dxMusic(pContext);
		Cocos2dxHelper.sCocos2dSound = new Cocos2dxSound(pContext);
		Cocos2dxHelper.sAssetManager = pContext.getAssets();
		Cocos2dxBitmap.setContext(pContext);
	}

	// ===========================================================
	// Getter & Setter
	// ===========================================================

	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	// ===========================================================
	// Methods
	// ===========================================================

	private static native void nativeSetApkPath(final String pApkPath);

	private static native void nativeSetAndroidUDID(final String udid);

	private static native void nativeSetAndroidIMEI(final String imei);

	private static native void nativeSetAndroidMacAddr(final String macAddr);

	private static native void nativeSetExternalAssetPath(final String pExternalAssetPath);

	private static native void nativeSetEditTextDialogResult(final byte[] pBytes);

	public static String getCocos2dxPackageName() {
		return Cocos2dxHelper.sPackageName;
	}

	public static String getCurrentLanguage() {
		return Locale.getDefault().getLanguage();
	}
	
	public static String getDeviceModel(){
		return Build.MODEL;
    }

	public static AssetManager getAssetManager() {
		return Cocos2dxHelper.sAssetManager;
	}

	public static void enableAccelerometer() {
		Cocos2dxHelper.sAccelerometerEnabled = true;
		Cocos2dxHelper.sCocos2dxAccelerometer.enable();
	}

	public static void disableAccelerometer() {
		Cocos2dxHelper.sAccelerometerEnabled = false;
		Cocos2dxHelper.sCocos2dxAccelerometer.disable();
	}

	public static void enableAd() {
		Cocos2dxHelper.sCocos2dxAd.showAd(true);
	}

	public static void disableAd() {
		Cocos2dxHelper.sCocos2dxAd.showAd(false);
	}

	public static void showYoumiOfferWall() {
		Cocos2dxHelper.sCocos2dxAd.showYoumiOfferWall();
	}

	public static void showDianjoyOfferWall() {
		Cocos2dxHelper.sCocos2dxAd.showDianJoyOfferWall();
	}

	public static void showImmobOfferWall() {
		Cocos2dxHelper.sCocos2dxAd.showImmobOfferWall();
	}

	public static void showTapjoyOfferWall() {
		Cocos2dxHelper.sCocos2dxAd.showTapjoyOfferWall();
	}

	public static void showDomobOfferWall() {
		Cocos2dxHelper.sCocos2dxAd.showDomobOfferWall();
	}

	public static void show91OfferWall() {
		Cocos2dxHelper.sCocos2dxAd.show91OfferWall();
	}

	public static void pushDianjoyAd() {
		;
	}

	public static void queryYoumiPoints() {
		Cocos2dxHelper.sCocos2dxAd.queryYouMiPoints();
	}

	public static void queryDianjoyPoints() {
		Cocos2dxHelper.sCocos2dxAd.queryDianLePoints();
	}

	public static void queryImmobPoints() {
		Cocos2dxHelper.sCocos2dxAd.queryImmobPoints();
	}
	
	public static void queryTapjoyPoints() {
		Cocos2dxHelper.sCocos2dxAd.queryTapjoyPoints();
	}
	
	public static void queryDomobPoints() {
		Cocos2dxHelper.sCocos2dxAd.queryDomobPoints();
	}
	
	public static void query91Points() {
		Cocos2dxHelper.sCocos2dxAd.query91Points();
	}
	
	public static void spendYoumiPoints(final int amount){
		Cocos2dxHelper.sCocos2dxAd.spendYouMiPoints(amount);
	}

	public static void spendDianjoyPoints(final int amount) {
		Cocos2dxHelper.sCocos2dxAd.spendDianjoyPoints(amount);
	}

	public static void spendImmobPoints(int amount) {
		Cocos2dxHelper.sCocos2dxAd.spendImmobPoints(amount);
	}
	
	public static void spendTapjoyPoints(int amount) {
		Cocos2dxHelper.sCocos2dxAd.spendTapjoyPoints(amount);
	}
	
	public static void spendDomobPoints(int amount) {
		Cocos2dxHelper.sCocos2dxAd.spendDomobPoints(amount);
	}
	
	public static void spend91Points(int amount) {
		Cocos2dxHelper.sCocos2dxAd.spend91Points(amount);
	}

	public static void updateYoumiPoints() {
		Cocos2dxHelper.sCocos2dxAd.updateYouMiPoints();
	}

	public static void updateDianjoyPoints() {
		Cocos2dxHelper.sCocos2dxAd.updateDianJoyPoints();
	}

	public static void updateImmobPoints() {
		Cocos2dxHelper.sCocos2dxAd.updateImmobPoints();
	}

	public static void updateTapjoyPoints() {
		Cocos2dxHelper.sCocos2dxAd.updateTapjoyPoints();
	}

	public static void updateDomobPoints() {
		Cocos2dxHelper.sCocos2dxAd.updateDomobPoints();
	}

	public static void update91Points() {
		Cocos2dxHelper.sCocos2dxAd.update91Points();
	}

	public static void loginRenn() {
		Cocos2dxHelper.sCocos2dxSNS.loginRenn();
	}

	public static void shareTextInRenn(final String text) {
		Cocos2dxHelper.sCocos2dxSNS.shareTextInRenn(text);
	}

	public static void sharePictureInRenn(final String file, final String text) {
		Cocos2dxHelper.sCocos2dxSNS.sharePictureInRenn(file, text);
	}
	
	public static void loginWeibo() {
		Cocos2dxHelper.sCocos2dxSNS.loginWeibo();
	}

	public static void shareTextInWeibo(final String text) {
		Cocos2dxHelper.sCocos2dxSNS.shareTextInWeibo(text);
	}

	public static void sharePictureInWeibo(final String file, final String text) {
		Cocos2dxHelper.sCocos2dxSNS.sharePictureInWeibo(file, text);
	}
	
	public static void loginQQ() {
		Cocos2dxHelper.sCocos2dxSNS.loginQQ();
	}

	public static void shareTextInQQ(final String text) {
		Cocos2dxHelper.sCocos2dxSNS.shareTextInQQ(text);
	}

	public static void sharePictureInQQ(final String file, final String text){
		Cocos2dxHelper.sCocos2dxSNS.sharePictureInQQ(file, text);
	}

	public static void loginFacebook() {
		Cocos2dxHelper.sCocos2dxSNS.loginFacebook();
	}

	public static void shareTextInFacebook(final String text) {
		Cocos2dxHelper.sCocos2dxSNS.shareTextInFacebook(text);
	}

	public static void sharePictureInFacebook(final String file, final String text) {
		Cocos2dxHelper.sCocos2dxSNS.sharePictureInFacebook(file, text);
	}

	public static void loginTwitter() {
		Cocos2dxHelper.sCocos2dxSNS.loginTwitter();
	}

	public static void shareTextInTwitter(final String text) {
		Cocos2dxHelper.sCocos2dxSNS.shareTextInTwitter(text);
	}

	public static void sharePictureInTwitter(final String file, final String text) {
		Cocos2dxHelper.sCocos2dxSNS.sharePictureInTwitter(file, text);
	}

	public static void pay(final String productId, final String productName, final String productDesc, final String IAPId, final int productMoney, final int chargePoint, final int giveGold){
		Cocos2dxHelper.sCocos2dxPayment.pay(productId, productName, productDesc, productMoney, chargePoint, giveGold, IAPId);
	}
	
	public static void openURL(final String url){
		Cocos2dxHelper.sCocos2dxSystem.openURL(url);
	}
	
	public static void setSysLang(final int type){
		Cocos2dxHelper.sCocos2dxSystem.setSysLang(url);
	}

	public static void playerBehaviorLogEvent(final String event) {
		Cocos2dxHelper.sCocos2dxPlayerBehaviorTrace.logEvent(event);
	}
	
	public static void preloadBackgroundMusic(final String pPath) {
		Cocos2dxHelper.sCocos2dMusic.preloadBackgroundMusic(pPath);
	}

	public static void playBackgroundMusic(final String pPath, final boolean isLoop) {
		Cocos2dxHelper.sCocos2dMusic.playBackgroundMusic(pPath, isLoop);
	}

	public static void resumeBackgroundMusic() {
		Cocos2dxHelper.sCocos2dMusic.resumeBackgroundMusic();
	}

	public static void pauseBackgroundMusic() {
		Cocos2dxHelper.sCocos2dMusic.pauseBackgroundMusic();
	}

	public static void stopBackgroundMusic() {
		Cocos2dxHelper.sCocos2dMusic.stopBackgroundMusic();
	}

	public static void rewindBackgroundMusic() {
		Cocos2dxHelper.sCocos2dMusic.rewindBackgroundMusic();
	}

	public static boolean isBackgroundMusicPlaying() {
		return Cocos2dxHelper.sCocos2dMusic.isBackgroundMusicPlaying();
	}

	public static float getBackgroundMusicVolume() {
		return Cocos2dxHelper.sCocos2dMusic.getBackgroundVolume();
	}

	public static void setBackgroundMusicVolume(final float volume) {
		Cocos2dxHelper.sCocos2dMusic.setBackgroundVolume(volume);
	}

	public static void preloadEffect(final String path) {
		Cocos2dxHelper.sCocos2dSound.preloadEffect(path);
	}

	public static int playEffect(final String path, final boolean isLoop) {
		return Cocos2dxHelper.sCocos2dSound.playEffect(path, isLoop);
	}

	public static void resumeEffect(final int soundId) {
		Cocos2dxHelper.sCocos2dSound.resumeEffect(soundId);
	}

	public static void pauseEffect(final int soundId) {
		Cocos2dxHelper.sCocos2dSound.pauseEffect(soundId);
	}

	public static void stopEffect(final int soundId) {
		Cocos2dxHelper.sCocos2dSound.stopEffect(soundId);
	}

	public static float getEffectsVolume() {
		return Cocos2dxHelper.sCocos2dSound.getEffectsVolume();
	}

	public static void setEffectsVolume(final float volume) {
		Cocos2dxHelper.sCocos2dSound.setEffectsVolume(volume);
	}

	public static void unloadEffect(final String path) {
		Cocos2dxHelper.sCocos2dSound.unloadEffect(path);
	}

	public static void pauseAllEffects() {
		Cocos2dxHelper.sCocos2dSound.pauseAllEffects();
	}

	public static void resumeAllEffects() {
		Cocos2dxHelper.sCocos2dSound.resumeAllEffects();
	}

	public static void stopAllEffects() {
		Cocos2dxHelper.sCocos2dSound.stopAllEffects();
	}

	public static void end() {
		Cocos2dxHelper.sCocos2dMusic.end();
		Cocos2dxHelper.sCocos2dSound.end();
	}

	public static void onResume() {
		if (Cocos2dxHelper.sAccelerometerEnabled) {
			Cocos2dxHelper.sCocos2dxAccelerometer.enable();
		}
	}

	public static void onPause() {
		if (Cocos2dxHelper.sAccelerometerEnabled) {
			Cocos2dxHelper.sCocos2dxAccelerometer.disable();
		}
	}

	public static void terminateProcess() {
		android.os.Process.killProcess(android.os.Process.myPid());
	}

	private static void showDialog(final String pTitle, final String pMessage) {
		Cocos2dxHelper.sCocos2dxHelperListener.showDialog(pTitle, pMessage);
	}

	private static void showEditTextDialog(final String pTitle, final String pMessage, final int pInputMode, final int pInputFlag, final int pReturnType, final int pMaxLength) {
		Cocos2dxHelper.sCocos2dxHelperListener.showEditTextDialog(pTitle, pMessage, pInputMode, pInputFlag, pReturnType, pMaxLength);
	}

	public static void setEditTextDialogResult(final String pResult) {
		try {
			final byte[] bytesUTF8 = pResult.getBytes("UTF8");

			Cocos2dxHelper.sCocos2dxHelperListener.runOnGLThread(new Runnable() {
				@Override
				public void run() {
					Cocos2dxHelper.nativeSetEditTextDialogResult(bytesUTF8);
				}
			});
		} catch (UnsupportedEncodingException pUnsupportedEncodingException) {
			/* Nothing. */
		}
	}

	private static String getAbsolutePathOnExternalStorage(final ApplicationInfo pApplicationInfo, final String pPath) {
		return Environment.getExternalStorageDirectory() + "/Android/data/" + pApplicationInfo.packageName + "/files/" + pPath;
	}

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================

	public static interface Cocos2dxHelperListener {
		public void showDialog(final String pTitle, final String pMessage);
		public void showEditTextDialog(final String pTitle, final String pMessage, final int pInputMode, final int pInputFlag, final int pReturnType, final int pMaxLength);

		public void runOnGLThread(final Runnable pRunnable);
	}
}
