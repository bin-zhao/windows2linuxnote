#ifndef  _NINJIATRIBE_NINJIATRIBEVIEWCONTROLLER_H_
#define  _NINJIATRIBE_NINJIATRIBEVIEWCONTROLLER_H_


#import <UIKit/UIKit.h>

@interface NinjiaTribeViewController : UIViewController<UITextViewDelegate> 
{
    
}

- (void) showDianjoyOfferWall;
- (void) showYoumiOfferWall;
- (void) showImmobOfferWall;
- (void) showDomobOfferWall;

- (void) queryDomobPoints;

@end


#endif
