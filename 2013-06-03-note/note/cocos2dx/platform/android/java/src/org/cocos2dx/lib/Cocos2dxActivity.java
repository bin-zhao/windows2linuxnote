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

import org.cocos2dx.lib.Cocos2dxHelper.Cocos2dxHelperListener;

import android.app.Activity;
import android.app.AlertDialog;
import android.os.Bundle;
import android.os.Message;
import android.view.ViewGroup;
import android.widget.FrameLayout;

public abstract class Cocos2dxActivity extends Activity implements Cocos2dxHelperListener {
	// ===========================================================
	// System Event Constants
	// ===========================================================
	public static final int _TYPED_AD_SHOW_AD_                    = 101;
	public static final int _TYPED_AD_HIDE_AD_                    = 102;
	
	public static final int _TYPED_AD_SHOW_YOUMI_OFFERWALL_       = 201;
	public static final int _TYPED_AD_SHOW_DIANJOY_OFFERWALL_     = 202;
	public static final int _TYPED_AD_SHOW_IMMOB_OFFERWALL_       = 203;
	public static final int _TYPED_AD_SHOW_TAPJOY_OFFERWALL_      = 204;
	public static final int _TYPED_AD_SHOW_DOMOB_OFFERWALL_       = 205;
	public static final int _TYPED_AD_SHOW_91_OFFERWALL_          = 206;
	public static final int _TYPED_AD_QUERY_YOUMI_POINTS_         = 207;
	public static final int _TYPED_AD_QUERY_DIANJOY_POINTS_       = 208;
	public static final int _TYPED_AD_QUERY_IMMOB_POINTS_         = 209;
	public static final int _TYPED_AD_QUERY_TAPJOY_POINTS_        = 210;
	public static final int _TYPED_AD_QUERY_DOMOB_POINTS_         = 211;
	public static final int _TYPED_AD_QUERY_91_POINTS_            = 212;
	public static final int _TYPED_AD_SPEND_YOUMI_POINTS_         = 213;
	public static final int _TYPED_AD_SPEND_DIANJOY_POINTS_       = 214;
	public static final int _TYPED_AD_SPEND_IMMOB_POINTS_         = 215;
	public static final int _TYPED_AD_SPEND_TAPJOY_POINTS_        = 216;
	public static final int _TYPED_AD_SPEND_DOMOB_POINTS_         = 217;
	public static final int _TYPED_AD_SPEND_91_POINTS_            = 218;
	public static final int _TYPED_AD_UPDATE_YOUMI_POINTS_        = 219;
	public static final int _TYPED_AD_UPDATE_DIANJOY_POINTS_      = 220;
	public static final int _TYPED_AD_UPDATE_IMMOB_POINTS_        = 221;
	public static final int _TYPED_AD_UPDATE_TAPJOY_POINTS_       = 222;
	public static final int _TYPED_AD_UPDATE_DOMOB_POINTS_        = 223;
	public static final int _TYPED_AD_UPDATE_91_POINTS_           = 224;
	
	public static final int _TYPED_SNS_LOGIN_RENN_                = 301;
	public static final int _TYPED_SNS_SHARE_TEXT_IN_RENN_        = 302;
	public static final int _TYPED_SNS_SHARE_PICTURE_IN_RENN_     = 303;
	public static final int _TYPED_SNS_LOGIN_WEIBO_               = 304;
	public static final int _TYPED_SNS_SHARE_TEXT_IN_WEIBO_       = 305;
	public static final int _TYPED_SNS_SHARE_PICTURE_IN_WEIBO_    = 306;
	public static final int _TYPED_SNS_LOGIN_QQ_                  = 307;
	public static final int _TYPED_SNS_SHARE_TEXT_IN_QQ_          = 308;
	public static final int _TYPED_SNS_SHARE_PICTURE_IN_QQ_       = 309;
	public static final int _TYPED_SNS_LOGIN_FACEBOOK_            = 310;
	public static final int _TYPED_SNS_SHARE_TEXT_IN_FACEBOOK_    = 311;
	public static final int _TYPED_SNS_SHARE_PICTURE_IN_FACEBOOK_ = 312;
	public static final int _TYPED_SNS_LOGIN_TWITTER_             = 313;
	public static final int _TYPED_SNS_SHARE_TEXT_IN_TWITTER_     = 314;
	public static final int _TYPED_SNS_SHARE_PICTURE_IN_TWITTER_  = 315;
	
	public static final int _TYPED_PAYMENT_START_PAY_             = 401;
	public static final int _TYPED_PAYMENT_VERIFY_                = 402;
	
	public static final int _TYPED_SYS_OPEN_URL_                  = 501;
	public static final int _TYPED_SYS_SET_SYSLANG_               = 502;
	
	public static final int _TYPED_PLAYER_BEHAVIOR_EVENT_         = 601;

	// ===========================================================
	// Constants
	// ===========================================================
	private static final String TAG = Cocos2dxActivity.class.getSimpleName();
	
	// ===========================================================
	// Fields
	// ===========================================================
	private Cocos2dxGLSurfaceView mGLSurefaceView;
	private Cocos2dxHandler mHandler;

	// ===========================================================
	// Fields
	// ===========================================================
	public Handler myEventHandler = null;
	
	// ===========================================================
	// Constructors
	// ===========================================================
	@Override
	protected void onCreate(final Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		this.init();

		Cocos2dxHelper.init(this, this);
	}

	// ===========================================================
	// Getter & Setter
	// ===========================================================

	// ===========================================================
	// Methods for/from SuperClass/Interfaces
	// ===========================================================

	@Override
	protected void onResume() {
		super.onResume();

		Cocos2dxHelper.onResume();
		this.mGLSurefaceView.onResume();
	}

	@Override
	protected void onPause() {
		super.onPause();

		Cocos2dxHelper.onPause();
		this.mGLSurefaceView.onPause();
	}

	@Override
	public void showDialog(final String pTitle, final String pMessage) {
		Message msg = new Message();
		msg.what = Cocos2dxHandler.HANDLER_SHOW_DIALOG;
		msg.obj = new Cocos2dxHandler.DialogMessage(pTitle, pMessage);
		this.mHandler.sendMessage(msg);
	}

	@Override
	public void showEditTextDialog(final String pTitle, final String pContent, final int pInputMode, final int pInputFlag, final int pReturnType, final int pMaxLength) { 
		Message msg = new Message();
		msg.what = Cocos2dxHandler.HANDLER_SHOW_EDITBOX_DIALOG;
		msg.obj = new Cocos2dxHandler.EditBoxMessage(pTitle, pContent, pInputMode, pInputFlag, pReturnType, pMaxLength);
		this.mHandler.sendMessage(msg);
	}
	
	@Override
	public void runOnGLThread(final Runnable pRunnable) {
		this.mGLSurefaceView.queueEvent(pRunnable);
	}

	// ===========================================================
	// Methods
	// ===========================================================
	
    public void init() {
    	// Init handler
    	this.mHandler = new Cocos2dxHandler(this);
    			
    	// FrameLayout
        ViewGroup.LayoutParams framelayout_params =
            new ViewGroup.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT,
                                       ViewGroup.LayoutParams.FILL_PARENT);
        FrameLayout framelayout = new FrameLayout(this);
        framelayout.setLayoutParams(framelayout_params);

        // Cocos2dxEditText layout
        ViewGroup.LayoutParams edittext_layout_params =
            new ViewGroup.LayoutParams(ViewGroup.LayoutParams.FILL_PARENT,
                                       ViewGroup.LayoutParams.WRAP_CONTENT);
        Cocos2dxEditText edittext = new Cocos2dxEditText(this);
        edittext.setLayoutParams(edittext_layout_params);

        // ...add to FrameLayout
        framelayout.addView(edittext);

        // Cocos2dxGLSurfaceView
        this.mGLSurefaceView = this.onCreateGLSurfaceView();

        // ...add to FrameLayout
        framelayout.addView(mGLSurefaceView);

        mGLSurefaceView.setCocos2dxRenderer(new Cocos2dxRenderer());
        mGLSurefaceView.setCocos2dxEditText(edittext);

        // Set framelayout as the content view
		setContentView(framelayout);
    }
    
    public Cocos2dxGLSurfaceView onCreateGLSurfaceView() {
    	return new Cocos2dxGLSurfaceView(this);
    }

	// ===========================================================
	// Inner and Anonymous Classes
	// ===========================================================
}
