//
//  MobileLaunchViewController.h
//  iPCL
//
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MessageView.h"
#import "LaunchViewProtocol.h"

typedef enum {
  ButtonsVisibilityAll = 0,
	ButtonsVisibilityOnlyUpdate,
	ButtonsVisibilityOnlyClose,
	ButtonsVisibilityNone,
}ButtonsVisibility;

@interface MobileLaunchViewController : UIViewController<LaunchViewProtocol> {
	MessageView			*messageView;
	UIView			*loadingView;
	BOOL _canContinue;
	UIImage *backgroundImageiPadPortrait;
	UIImage *backgroundImageiPadLandscape;
	UIImageView *backgroundImageView;
	ButtonsVisibility currentButtonsVisibility;
}

- (IBAction)continueClicked:(id) sender;
- (void)showLoading;
- (void)showMessage:(NSString *)message buttonsVisibility:(ButtonsVisibility)buttonsVisibility 
																	  hasInternetConnection:(BOOL)hasInternetConnection;
@end
