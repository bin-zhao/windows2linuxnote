#ifndef  _NINJIATRIBE_NINJIATRIBEAPPCONTROLLER_H_
#define  _NINJIATRIBE_NINJIATRIBEAPPCONTROLLER_H_


#import <UIKit/UIKit.h>
#import <EAGLView.h>


#define  _TYPED_IPHONE_FLURRY_APP_KEY_  @"6Q46SRXPB8T23B96VV5X"
#define  _TYPED_IPAD_FLURRY_APP_KEY_    @"GD3HPQ5MR2NPC73J3TQ2"

#define  _TYPED_IPHONE_UM_APP_KEY_  @"514c602956240bcd04006205"
#define  _TYPED_IPAD_UM_APP_KEY_    @"514c602956240bcd04006205"

@class NinjiaTribeViewController;
@class UMSocialControllerService;
@interface NinjiaTribeAppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate, UIApplicationDelegate>
{
    UIWindow*    m_pWindow;
	UIAlertView* m_pAppNewVersionAlert;
    NinjiaTribeViewController* m_pViewController;
	UMSocialControllerService* m_pUMSNSService;
}

-(void) showAd:(NSNotification*)notify;
-(void) hideAd:(NSNotification*)notify;

-(void) show91OfferWall:(NSNotification*)notify;
-(void) showTapjoyOfferWall:(NSNotification*)notify;
-(void) showDomobOfferWall:(NSNotification*)notify;
-(void) showDianjoyOfferWall:(NSNotification*)notify;
-(void) showImmobOfferWall:(NSNotification*)notify;
-(void) showYoumiOfferWall:(NSNotification*)notify;

-(void) query91Points:(NSNotification*)notify;
-(void) queryTapjoyPoints:(NSNotification*)notify;
-(void) queryDomobPoints:(NSNotification*)notify;
-(void) queryDianjoyPoints:(NSNotification*)notify;
-(void) queryImmobPoints:(NSNotification*)notify;
-(void) queryYoumiPoints:(NSNotification*)notify;

-(void) update91Points:(NSNotification*)notify;
-(void) updateTapjoyPoints:(NSNotification*)notify;
-(void) updateDomobPoints:(NSNotification*)notify;
-(void) updateDianjoyPoints:(NSNotification*)notify;
-(void) updateImmobPoints:(NSNotification*)notify;
-(void) updateYoumiPoints:(NSNotification*)notify;

-(void) spend91Points:(NSNotification*)notify;
-(void) spendTapjoyPoints:(NSNotification*)notify;
-(void) spendDomobPoints:(NSNotification*)notify;
-(void) spendDianjoyPoints:(NSNotification*)notify;
-(void) spendImmobPoints:(NSNotification*)notify;
-(void) spendYoumiPoints:(NSNotification*)notify;

-(void) loginRenn:(NSNotification*)notify;
-(void) loginWeibo:(NSNotification*)notify;
-(void) loginQQ:(NSNotification*)notify;
-(void) loginFacebook:(NSNotification*)notify;
-(void) loginTwitter:(NSNotification*)notify;

-(void) shareTextInRenn:(NSNotification*)notify;
-(void) shareTextInWeibo:(NSNotification*)notify;
-(void) shareTextInQQ:(NSNotification*)notify;
-(void) shareTextInFacebook:(NSNotification*)notify;
-(void) shareTextInTwitter:(NSNotification*)notify;

-(void) sharePictureInRenn:(NSNotification*)notify;
-(void) sharePictureInWeibo:(NSNotification*)notify;
-(void) sharePictureInQQ:(NSNotification*)notify;
-(void) sharePictureInFacebook:(NSNotification*)notify;
-(void) sharePictureInTwitter:(NSNotification*)notify;

-(void) logPlayerBehaviorEvent:(NSNotification*)notify;
-(void) logPlayerBehaviorEventWithLabel:(NSNotification*)notify;
-(void) beginLogPlayerBehaviorEvent:(NSNotification*)notify;
-(void) endLogPlayerBehaviorEvent:(NSNotification*)notify;

-(void) showFeedbackDialogEvent:(NSNotification*)notify;

-(void) showAppNewVersionAlert:(NSString*)title oktitle:(NSString*)oktitle canceltitle:(NSString*)canceltitle;

@end


#endif
