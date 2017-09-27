//
//  MobileLaunchViewController.h
//  iPCL
//
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MessageView.h"
#import "LaunchViewProtocol.h"


/*
  Tags of internal subviews. Buttons, message views etc.  Exposed here
  so that it is possible to customize them by users of the library.
*/

#define INDICATOR_TAG 1001
#define CONTINUE_BUTTON_TAG 1003
#define UPGRADE_BUTTON_TAG 1002
#define CLOSE_BUTTON_TAG 1004
#define MESSAGE_VIEW_TAG 1005

@interface MobileLaunchViewController : UIViewController<LaunchViewProtocol, CAAnimationDelegate> {
	MessageView			*messageView;
	UIView			*loadingView;
	BOOL _canContinue;
	UIImage *backgroundImageiPadPortrait;
	UIImage *backgroundImageiPadLandscape;
	UIImageView *backgroundImageView;
	ButtonsVisibility currentButtonsVisibility;
}

- (void)continueClicked:(id) sender;
- (void)showLoading;
- (void)showMessage:(NSString *)message buttonsVisibility:(ButtonsVisibility)buttonsVisibility 
																	  hasInternetConnection:(BOOL)hasInternetConnection;
- (void) hideMessageView;
@end
