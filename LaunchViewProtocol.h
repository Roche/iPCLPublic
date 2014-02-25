//
//  LaunchViewProtocol.h
//  iPhoneCommonLibrary
//
//  Created by Maciej Skolecki on 9/30/11.
//  Copyright 2011 Genentech Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
  ButtonsVisibilityAll = 0,
	ButtonsVisibilityOnlyUpdate,
	ButtonsVisibilityOnlyClose,
	ButtonsVisibilityNone,
}ButtonsVisibility;


@protocol LaunchViewProtocol <NSObject>
@optional
- (void)showLoading;
- (void)showMessage:(NSString *)message buttonsVisibility:(ButtonsVisibility)buttonsVisibility 
																	  hasInternetConnection:(BOOL)hasInternetConnection;
- (void) hideMessageView;
@end
