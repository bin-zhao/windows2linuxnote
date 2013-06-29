#import "../include/NinjiaTribeViewController.h"
#include <UIKit/UITextField.h>
#include <Foundation/Foundation.h>
#include <CoreLocation/CoreLocation.h>
#include <Foundation/NSObject.h>
#import <EAGLView.h>


@implementation NinjiaTribeViewController


- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation 
{
	return UIInterfaceOrientationIsPortrait(interfaceOrientation);
}

- (void)didReceiveMemoryWarning 
{
    [super didReceiveMemoryWarning];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
}

- (void)textFieldDidBeginEditing:(UITextField *)textField 
{
    CGFloat keyboardHeight = 216.0f;  
    if (self.view.frame.size.height - keyboardHeight <= textField.frame.origin.y + textField.frame.size.height) 
    {  
        CGFloat y = textField.frame.origin.y - (self.view.frame.size.height - keyboardHeight - textField.frame.size.height - 5);  
        [UIView beginAnimations:@"srcollView" context:nil];  
        [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];  
        [UIView setAnimationDuration:0.275f];  
        self.view.frame = CGRectMake(self.view.frame.origin.x, -y, self.view.frame.size.width, self.view.frame.size.height);  
        [UIView commitAnimations];  
    } 
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField 
{
    [[EAGLView sharedEGLView] becomeFirstResponder];
    [[EAGLView sharedEGLView] resignFirstResponder];
    
	return YES;
}

- (void)textFieldDidEndEditing:(UITextField *)textField 
{
    [UIView beginAnimations:@"srcollView" context:nil];  
    [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];  
    [UIView setAnimationDuration:0.275f];  
    self.view.frame = CGRectMake(self.view.frame.origin.x, 0, self.view.frame.size.width, self.view.frame.size.height);  
    [UIView commitAnimations];
}

- (void)dealloc
{
    [super dealloc];
}

- (void) showDianjoyOfferWall
{

}

- (void) showYoumiOfferWall
{
	;
}

- (void) showImmobOfferWall
{
    ;
}

- (void) showDomobOfferWall
{
	;
}

- (void) queryDomobPoints
{
	;
}

@end
