#include <UIKit/UIKit.h>
#include <cocos2d.h>
#include <EAGLView.h>
#include <Cocos2dEventTyper.h>
#include <CDAudioManager.h>
#include <GameKit/GameKit.h>
#include <GameKit/GKScore.h>
#include "../include/NinjiaTribeAppController.h"
#include "../include/NinjiaTribeViewController.h"
#include "../include/NinjiaTribeApp.h"
#include "../include/EventSystem.h"
#include "../include/EventTyper.h"
#include "../include/VariableSystem.h"
#include "Flurry.h"
#include "ALSystem.h"
#import "UMSocialSnsService.h"
#import "UMFeedback.h"

@implementation NinjiaTribeAppController


#pragma mark -
#pragma mark Application lifecycle

NinjiaTribeAppController* g_pNinjiaTribeAppController = NULL;

void uncaughtExceptionHandler(NSException *exception)
{
	[Flurry logError:@"Uncaught" message:@"Crash!" exception:exception];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 
{   
	NSLog(@"APP:	start didFinishLaunchingWithOptions");
	m_pAppNewVersionAlert = nil;
	
	// register ad event handler
	NSNotificationCenter* center = [NSNotificationCenter defaultCenter];
    [center addObserver:self selector:@selector(showAd:) name:_TYPED_COCOS2D_SHOW_AD_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(hideAd:) name:_TYPED_COCOS2D_HIDE_AD_EVENT_NAME_ object:nil];

    // register offerwall event handler
    [center addObserver:self selector:@selector(show91OfferWall:) name:_TYPED_COCOS2D_SHOW_91_OFFERWALL_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(showTapjoyOfferWall:) name:_TYPED_COCOS2D_SHOW_TAPJOY_OFFERWALL_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(showDomobOfferWall:) name:_TYPED_COCOS2D_SHOW_DOMOB_OFFERWALL_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(showDianjoyOfferWall:) name:_TYPED_COCOS2D_SHOW_DIANJOY_OFFERWALL_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(showImmobOfferWall:) name:_TYPED_COCOS2D_SHOW_IMMOB_OFFERWALL_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(showYoumiOfferWall:) name:_TYPED_COCOS2D_SHOW_YOUMI_OFFERWALL_EVENT_NAME_ object:nil];
    
    [center addObserver:self selector:@selector(query91Points:) name:_TYPED_COCOS2D_QUERY_91_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(queryTapjoyPoints:) name:_TYPED_COCOS2D_QUERY_TAPJOY_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(queryDomobPoints:) name:_TYPED_COCOS2D_QUERY_DOMOB_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(queryDianjoyPoints:) name:_TYPED_COCOS2D_QUERY_DIANJOY_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(queryImmobPoints:) name:_TYPED_COCOS2D_QUERY_IMMOB_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(queryYoumiPoints:) name:_TYPED_COCOS2D_QUERY_YOUMI_POINTS_EVENT_NAME_ object:nil];
    
    [center addObserver:self selector:@selector(update91Points:) name:_TYPED_COCOS2D_UPDATE_91_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(updateTapjoyPoints:) name:_TYPED_COCOS2D_UPDATE_TAPJOY_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(updateDomobPoints:) name:_TYPED_COCOS2D_UPDATE_DOMOB_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(updateDianjoyPoints:) name:_TYPED_COCOS2D_UPDATE_DIANJOY_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(updateImmobPoints:) name:_TYPED_COCOS2D_UPDATE_IMMOB_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(updateYoumiPoints:) name:_TYPED_COCOS2D_UPDATE_YOUMI_POINTS_EVENT_NAME_ object:nil];
    
    [center addObserver:self selector:@selector(spend91Points:) name:_TYPED_COCOS2D_SPEND_91_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(spendTapjoyPoints:) name:_TYPED_COCOS2D_SPEND_TAPJOY_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(spendDomobPoints:) name:_TYPED_COCOS2D_SPEND_DOMOB_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(spendDianjoyPoints:) name:_TYPED_COCOS2D_SPEND_DIANJOY_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(spendImmobPoints:) name:_TYPED_COCOS2D_SPEND_IMMOB_POINTS_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(spendYoumiPoints:) name:_TYPED_COCOS2D_SPEND_YOUMI_POINTS_EVENT_NAME_ object:nil];
    
    // register sns event handler
    [center addObserver:self selector:@selector(loginRenn:) name:_TYPED_COCOS2D_LOGIN_RENN_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(loginWeibo:) name:_TYPED_COCOS2D_LOGIN_WEIBO_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(loginQQ:) name:_TYPED_COCOS2D_LOGIN_QQ_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(loginFacebook:) name:_TYPED_COCOS2D_LOGIN_FACEBOOK_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(loginTwitter:) name:_TYPED_COCOS2D_LOGIN_TWITTER_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(shareTextInRenn:) name:_TYPED_COCOS2D_SHARE_REEN_TEXT_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(shareTextInWeibo:) name:_TYPED_COCOS2D_SHARE_WEIBO_TEXT_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(shareTextInQQ:) name:_TYPED_COCOS2D_SHARE_QQ_TEXT_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(shareTextInFacebook:) name:_TYPED_COCOS2D_SHARE_FACEBOOK_TEXT_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(shareTextInTwitter:) name:_TYPED_COCOS2D_SHARE_TWITTER_TEXT_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(sharePictureInRenn:) name:_TYPED_COCOS2D_SHARE_RENN_PICTURE_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(sharePictureInWeibo:) name:_TYPED_COCOS2D_SHARE_WEIBO_PICTURE_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(sharePictureInQQ:) name:_TYPED_COCOS2D_SHARE_QQ_PICTURE_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(sharePictureInFacebook:) name:_TYPED_COCOS2D_SHARE_FACEBOOK_PICTURE_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(sharePictureInTwitter:) name:_TYPED_COCOS2D_SHARE_TWITTER_PICTURE_EVENT_NAME_ object:nil];
    
    // register player behavior event handler
    [center addObserver:self selector:@selector(logPlayerBehaviorEvent:) name:_TYPED_COCOS2D_LOG_PLAYER_BEHAVIOR_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(logPlayerBehaviorEventWithLabel:) name:_TYPED_COCOS2D_LOG_PLAYER_BEHAVIOR_EVENT_NAME_WITH_LABEL_ object:nil];
    [center addObserver:self selector:@selector(beginLogPlayerBehaviorEvent:) name:_TYPED_COCOS2D_BEGIN_LOG_PLAYER_BEHAVIOR_EVENT_NAME_ object:nil];
    [center addObserver:self selector:@selector(endLogPlayerBehaviorEvent:) name:_TYPED_COCOS2D_END_LOG_PLAYER_BEHAVIOR_EVENT_NAME_ object:nil];
    
    // register show feedback dialog event handler
    [center addObserver:self selector:@selector(showFeedbackDialogEvent:) name:_TYPED_COCOS2D_SHOW_FEEDBACK_DIALOG_EVENT_NAME_ object:nil];
    
	// init flurry
    NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) 
    {
        [Flurry startSession:_TYPED_IPHONE_FLURRY_APP_KEY_];
    }
    else 
    {
		[Flurry startSession:_TYPED_IPAD_FLURRY_APP_KEY_];
    }
    
    // init UM SNS
    m_pUMSNSService = [[UMSocialControllerService alloc] initWithUMSocialData:[UMSocialData defaultData]];
    
    // Add the view controller's view to the window and display.
    m_pWindow = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    CGRect glViewFrame = CGRectMake(0, 0, [m_pWindow bounds].size.width, [m_pWindow bounds].size.height);
    EAGLView *__glView = [EAGLView viewWithFrame: glViewFrame
                                     pixelFormat: kEAGLColorFormatRGBA8
                                     depthFormat: GL_DEPTH_COMPONENT16
                              preserveBackbuffer: YES
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0 ];
    m_pViewController = [[NinjiaTribeViewController alloc] initWithNibName:nil bundle:nil];
    m_pViewController.wantsFullScreenLayout = YES;
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) 
    {
        NSString *reqSysVer = @"5";
        NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
        if ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending) 
        {
            if ([[UIScreen mainScreen] respondsToSelector: @selector(scale)]) 
            {
				CGFloat scale = [[UIScreen mainScreen] scale];
				if(scale == 2.0) 
					[__glView setDesignContentScaleFactor:scale];
			}

            [m_pViewController.view addSubview:__glView];
        }
        else
        {
			if ([[UIScreen mainScreen] respondsToSelector: @selector(scale)]) 
			{
				CGFloat scale = [[UIScreen mainScreen] scale];
				if(scale == 2.0) 
					[__glView setDesignContentScaleFactor:scale];
			}
			
            m_pViewController.view = __glView;
        }
    }
    else 
    {
        [m_pViewController.view addSubview:__glView];
    }
 
	[m_pWindow setRootViewController:m_pViewController];
    
    [m_pWindow makeKeyAndVisible];
    // hide status bar
    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    g_pNinjiaTribeAppController = self;

	ALSystemFactory::createALSystem();
    cocos2d::CCApplication::sharedApplication()->run();
    
    NSLog(@"APP:	end didFinishLaunchingWithOptions");
    return TRUE;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
	NSLog(@"APP:	start applicationWillResignActive");
    
	NinjiaTribeApp::get_instance2()->applicationDidPaused();
    
    NSLog(@"APP:	end applicationWillResignActive");
}

- (void)applicationDidBecomeActive:(UIApplication *)application 
{
    NSLog(@"APP:	start applicationDidBecomeActive");
    
	NinjiaTribeApp::get_instance2()->applicationDidResumed();
    
    NSLog(@"APP:	end applicationDidBecomeActive");
}

- (void)applicationDidEnterBackground:(UIApplication *)application 
{
	NSLog(@"APP:	start applicationDidEnterBackground");

    NinjiaTribeApp::get_instance2()->applicationDidEnterBackground();
    
    NSLog(@"APP:	end applicationDidEnterBackground");
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    NSLog(@"APP:	start applicationWillEnterForeground");
    
	[[CDAudioManager sharedManager] setResignBehavior:(kAMRBStop) autoHandle:TRUE];
    NinjiaTribeApp::get_instance2()->applicationWillEnterForeground();
    
    NSLog(@"APP:	end applicationWillEnterForeground");
}

- (void)applicationWillTerminate:(UIApplication *)application 
{
	NSLog(@"APP:	start applicationWillTerminate");
	
	NinjiaTribeApp::get_instance2()->Destroy();
	delete ALSystem::getInstance();
	
	NSLog(@"APP:	end applicationWillTerminate");
}

#pragma mark -
#pragma mark Memory management
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application
{
     NSLog(@"APP:    start applicationDidReceiveMemoryWarning\n");
     
     NSLog(@"APP:    end applicationDidReceiveMemoryWarning\n");
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
     NSLog(@"APP:    start didRegisterForRemoteNotificationsWithDeviceToken\n");
     
     NSLog(@"APP:    end didRegisterForRemoteNotificationsWithDeviceToken\n");
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
     NSLog(@"APP:    start didFailToRegisterForRemoteNotificationsWithError\n");
     
     NSLog(@"APP:    end didFailToRegisterForRemoteNotificationsWithError\n");   
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo 
{
     NSLog(@"APP:    start didReceiveRemoteNotification\n");
     
     NSLog(@"APP:    end didReceiveRemoteNotification\n"); 
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification 
{
	NSLog(@"APP:    start didReceiveLocalNotification\n");

	[UIApplication sharedApplication].applicationIconBadgeNumber = 0; 
	[[UIApplication sharedApplication] cancelAllLocalNotifications];
	
    NSLog(@"APP:    end didReceiveLocalNotification\n"); 
}

- (void)dealloc 
{
	[m_pUMSNSService release];
	[m_pWindow release];
    [super dealloc];
}

- (void)alertView:(UIAlertView *)alertview clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if (alertview == m_pAppNewVersionAlert)
    {
        if (buttonIndex == 1)
        {
            char buffer[1024] = "";
            VARIABLESYSTEM->GetVariable(VariableSystem::_TYPED_CONFIG_MEM_, "SYS", "NewVersionDownLoadURL", buffer, sizeof(buffer)-1);
            
            NSString* url = [NSString stringWithCString:buffer];
            [[UIApplication sharedApplication]openURL:[NSURL URLWithString:url]];
        }
    }
}

#pragma mark -
#pragma mark New Version Check
- (void)showAppNewVersionAlert:(NSString*)title oktitle:(NSString*)oktitle canceltitle:(NSString*)canceltitle
{
    if (m_pAppNewVersionAlert == nil)
    {
        m_pAppNewVersionAlert = [[UIAlertView alloc] initWithTitle:@"" message:title delegate:self cancelButtonTitle:canceltitle otherButtonTitles:oktitle, nil];
    }
    
    [m_pAppNewVersionAlert show];
    [m_pAppNewVersionAlert release];
}

#pragma mark -
#pragma mark Show AD
-(void) showAd:(NSNotification*)notify
{
    NSLog(@"AD: show\n");
}

-(void) hideAd:(NSNotification*)notify
{
    NSLog(@"AD: hide\n");
}

#pragma mark -
#pragma mark OfferWall
-(void) show91OfferWall:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  show 91 offerwall\n");
}

-(void) showTapjoyOfferWall:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  show tapjoy offerwall\n");
}

-(void) showDomobOfferWall:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start show domob offerwall\n");
    
    @try
	{
		[m_pViewController showDomobOfferWall];
	}
	@catch(...)
	{
		;
	}
	
	NSLog(@"OFFERWALL:  end show domob offerwall\n");
}

-(void) showDianjoyOfferWall:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start show dianjoy offerwall\n");
    
    @try
	{
		[m_pViewController showDianjoyOfferWall];
	}
	@catch(...)
	{
		;
	}
	
	NSLog(@"OFFERWALL:  end show dianjoy offerwall\n");
}

-(void) showImmobOfferWall:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start show immob offerwall\n");
    
    @try
	{
		[m_pViewController showImmobOfferWall];
	}
	@catch(...)
	{
		;
	}
	
	NSLog(@"OFFERWALL:  end show immob offerwall\n");
}

-(void) showYoumiOfferWall:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start show youmi offerwall\n");
    
    @try
	{
		[m_pViewController showYoumiOfferWall];
	}
	@catch(...)
	{
		;
	}
	
	NSLog(@"OFFERWALL:  end show youmi offerwall\n");
}

-(void) query91Points:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  query 91 points\n");
}

-(void) queryTapjoyPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  query tapjoy points\n");
}

-(void) queryDomobPoints:(NSNotification*)notify;
{
    NSLog(@"OFFERWALL:  start query domob points\n");
    
    @try
	{
		[m_pViewController queryDomobPoints];
	}
	@catch(...)
	{
		return;
	}
	
	NSLog(@"OFFERWALL:  end query domob points\n");
}

-(void) queryDianjoyPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  query dianjoy points\n");
}

-(void) queryImmobPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  query immob points\n");
}

-(void) queryYoumiPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  query youmi points\n");
}

-(void) update91Points:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  update 91 points\n");
}

-(void) updateTapjoyPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  update tapjoy points\n");
}

-(void) updateDomobPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  update domob points\n");
}

-(void) updateDianjoyPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  update dianjoy points\n");
}

-(void) updateImmobPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  update immob points\n");
}

-(void) updateYoumiPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  update youmi points\n");
}

-(void) spend91Points:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start spend 91 points\n");
    
    NSNumber* pointsNumber = notify.object;
	int points = [pointsNumber intValue];
    
    NSLog(@"OFFERWALL:  end spend 91 points\n");
}

-(void) spendTapjoyPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start spend tapjoy points\n");

    NSNumber* pointsNumber = notify.object;
	int points = [pointsNumber intValue];
    
    NSLog(@"OFFERWALL:  end spend tapjoy points\n"); 
}

-(void) spendDomobPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start spend domob points\n");

    NSNumber* pointsNumber = notify.object;
	int points = [pointsNumber intValue];
    
    NSLog(@"OFFERWALL:  end spend domob points\n");
}

-(void) spendDianjoyPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start spend dianjoy points\n");

    NSNumber* pointsNumber = notify.object;
	int points = [pointsNumber intValue];
    
    NSLog(@"OFFERWALL:  end spend dianjoy points\n");
}

-(void) spendImmobPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start spend immob points\n");

    NSNumber* pointsNumber = notify.object;
	int points = [pointsNumber intValue];
    
    NSLog(@"OFFERWALL:  end spend immob points\n");
}

-(void) spendYoumiPoints:(NSNotification*)notify
{
    NSLog(@"OFFERWALL:  start spend youmi points\n");

    NSNumber* pointsNumber = notify.object;
	int points = [pointsNumber intValue];
    
    NSLog(@"OFFERWALL:  end spend youmi points\n");
}

#pragma mark -
#pragma mark SNS
-(void) loginRenn:(NSNotification*)notify
{
    NSLog(@"SNS:    start login renn\n");
    
    UINavigationController* pAccountViewController = [m_pUMSNSService getSocialAccountController];
    [m_pViewController presentModalViewController:pAccountViewController animated:YES];
    
    NSLog(@"SNS:    end login renn\n");
}

-(void) loginWeibo:(NSNotification*)notify
{
    NSLog(@"SNS:    start login weibo\n");
    
    UINavigationController* pAccountViewController = [m_pUMSNSService getSocialAccountController];
    [m_pViewController presentModalViewController:pAccountViewController animated:YES];
    
    NSLog(@"SNS:    end login weibo\n");
}

-(void) loginQQ:(NSNotification*)notify
{
    NSLog(@"SNS:    start login qq\n");
    
    UINavigationController* pAccountViewController = [m_pUMSNSService getSocialAccountController];
    [m_pViewController presentModalViewController:pAccountViewController animated:YES];
    
    NSLog(@"SNS:    end login qq\n");
}

-(void) loginFacebook:(NSNotification*)notify
{
    NSLog(@"SNS:    start login facebook\n");
    
    UINavigationController* pAccountViewController = [m_pUMSNSService getSocialAccountController];
    [m_pViewController presentModalViewController:pAccountViewController animated:YES];
    
    NSLog(@"SNS:    end login facebook\n");
}

-(void) loginTwitter:(NSNotification*)notify
{
    NSLog(@"SNS:    start login twitter\n");
    
    UINavigationController* pAccountViewController = [m_pUMSNSService getSocialAccountController];
    [m_pViewController presentModalViewController:pAccountViewController animated:YES];
    
    NSLog(@"SNS:    end login twitter\n");
}

-(void) shareTextInRenn:(NSNotification*)notify
{
    NSLog(@"SNS:    start share text in renn\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:nil shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share text in renn\n");
}

-(void) shareTextInWeibo:(NSNotification*)notify
{
    NSLog(@"SNS:    start share text in weibo\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:nil shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share text in weibo\n");
}

-(void) shareTextInQQ:(NSNotification*)notify
{
    NSLog(@"SNS:    start share text in qq\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:nil shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share text in qq\n");
}

-(void) shareTextInFacebook:(NSNotification*)notify
{
    NSLog(@"SNS:    start share text in facebook\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:nil shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share text in facebook\n");
}

-(void) shareTextInTwitter:(NSNotification*)notify
{
    NSLog(@"SNS:    start share text in twitter\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:nil shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share text in twitter\n");
}

-(void) sharePictureInRenn:(NSNotification*)notify
{
    NSLog(@"SNS:    start share picture in renn\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    NSString* file = [dict objectForKey:@"shareFileName"];
    
    UIImage* pImage = ALSystem::getInstance()->shotScreen();
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:pImage shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share picture in renn\n");
}

-(void) sharePictureInWeibo:(NSNotification*)notify
{
    NSLog(@"SNS:    start share picture in weibo\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    NSString* file = [dict objectForKey:@"shareFileName"];
    
    UIImage* pImage = ALSystem::getInstance()->shotScreen();
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:pImage shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share picture in weibo\n");
}

-(void) sharePictureInQQ:(NSNotification*)notify
{
    NSLog(@"SNS:    start share picture in qq\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    NSString* file = [dict objectForKey:@"shareFileName"];
    
    UIImage* pImage = ALSystem::getInstance()->shotScreen();
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:pImage shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share picture in qq\n");
}

-(void) sharePictureInFacebook:(NSNotification*)notify
{
    NSLog(@"SNS:    start share picture in facebook\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    NSString* file = [dict objectForKey:@"shareFileName"];
    
    UIImage* pImage = ALSystem::getInstance()->shotScreen();
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:pImage shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share picture in facebook\n");
}

-(void) sharePictureInTwitter:(NSNotification*)notify
{
    NSLog(@"SNS:    start share picture in twitter\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text = [dict objectForKey:@"shareText"];
    NSString* file = [dict objectForKey:@"shareFileName"];
    
    UIImage* pImage = ALSystem::getInstance()->shotScreen();
    [UMSocialSnsService presentSnsController:m_pViewController appKey:_TYPED_IPHONE_UM_APP_KEY_ shareText:text shareImage:pImage shareToSnsNames:nil delegate:nil];
    
    NSLog(@"SNS:    end share picture in twitter\n");
}

-(void) logPlayerBehaviorEvent:(NSNotification*)notify
{
    NSLog(@"BEHAVIOR:  start log player behavior\n");

    NSString* textString = notify.object;
    
    NSLog(@"BEHAVIOR:  end log player behavior\n");
}

-(void) logPlayerBehaviorEventWithLabel:(NSNotification*)notify
{
    NSLog(@"BEHAVIOR:  start log player behavior with label\n");
    NSDictionary* dict = [notify userInfo];
    if (dict == nil)
        return;
    
    NSString* text  = [dict objectForKey:@"Text"];
    NSString* label = [dict objectForKey:@"Label"];
    
    NSLog(@"BEHAVIOR:  end log player behavior with label\n");
}

-(void) beginLogPlayerBehaviorEvent:(NSNotification*)notify
{
    NSLog(@"BEHAVIOR:  start begin log player behavior\n");

    NSString* textString = notify.object;
    
    NSLog(@"BEHAVIOR:  end begin log player behavior\n");
}

-(void) endLogPlayerBehaviorEvent:(NSNotification*)notify
{
    NSLog(@"BEHAVIOR:  start end log player behavior\n");

    NSString* textString = notify.object;
    
    NSLog(@"BEHAVIOR:  end end log player behavior\n");
}

-(void) showFeedbackDialogEvent:(NSNotification*)notify
{
    NSLog(@"BEHAVIOR:  start show feedback dialog\n");

    [UMFeedback showFeedback:m_pViewController withAppkey:_TYPED_IPHONE_UM_APP_KEY_];
    
    NSLog(@"BEHAVIOR:  end show feedback dialog\n");
}


@end
