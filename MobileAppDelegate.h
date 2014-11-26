//
//  MobileAppDelegate.h
//  LaunchPad
//
//  Created by qliu on 7/29/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SecurityUtil.h"
#import "UncaughtExceptionHandlerDelegate.h"
#import "LaunchViewProtocol.h"
#import "LoginViewProtocol.h"
#import "MobileLaunchViewController.h"

@class LogInViewController;
@class MobileLaunchViewController;
@class LoginRequestDataHandler;
@class OMAppMeasurement;
@class GeneReachability;

#define IPHONE_INTERNALS_VIEW 'iivt'

enum AppDelegateStartMode {
	AppDelegateStartModeInit,
	AppDelegateStartModeResume
};

enum LoginControllerDisplayMode {
	LoginControllerNotShown,
	LoginControllerShownModally,
	LoginControllerShownAsRootViewController
};


@protocol LogoutFunctionalityDelegate <NSObject>

@optional

- (BOOL)shouldSupportLogoutFunctionality;
- (void)applicationDidRequestLogout;
- (BOOL)shouldShowLoginViewModally;

@end

@protocol MobileLoginSequenceDelegate <NSObject>

@optional

- (void)loginViewWillAppear;
- (void)loginViewDidAppear;
- (void)loginViewWillDisappear;
- (void)loginViewDidDisappear;
- (void)launchingViewWillAppear;
- (void)launchingViewDidAppear;
- (void)launchingViewWillDisappear;
- (void)launchingViewDidDisappear;
- (void)upgradeInformationWillAppearWithContinue:(BOOL)canContinue;
- (void)upgradeInformationDidAppearWithContinue:(BOOL)canContinue;
- (void)upgradeInformationIsDismissed;
- (void)waitUntilOnlineInfoWillAppear;
- (void)waitUntilOnlineInfoDidAppear;
- (void)waitUntilOnlineInfoWillDisappear;
- (void)waitUntilOnlineInfoDidDisappear;
- (void)loginWillOccur;
- (void)loginDidFailWithState:(LoginStateValue)loginStateValue error:(NSString *)loginError;
- (void)loginDidSucceed;

@end

@interface MobileAppDelegate : NSObject <LoginRequestDataHandler, UncaughtExceptionHandlerDelegate, MobileLoginSequenceDelegate, LogoutFunctionalityDelegate> {
	UIWindow					*window;

	UIViewController<LaunchViewProtocol> *launchController;
	UIViewController<LoginViewProtocol> *loginController;

	enum LoginControllerDisplayMode loginControllerDisplayMode;

	BOOL                        useStaticData;
	BOOL                        connected;	
	SecurityUtil				*secUtil;				//Security utility for login
	SecurityUtil				*backgroundSecUtil;		//Security utility for background login (different LoginRequestDataHandler is used)
	BOOL                        needUserInfo;			//set to True to get user info during login
    
    AppStatus                   *savedAppStatus;
   	NSString                    *versionNumber;         // versionNumber saved w/ appStatus so don't prompt after upgrade
    BOOL                        loginFailed;	
    BOOL                        backgroundLogin;    
    BOOL                        appSupportsOffline;
    GeneReachability            *geneReachability;
    enum AppDelegateStartMode   appDelegateStartMode;
    BOOL                        waitingForReachabilityToLogin;
    
    NSString                    *_technicalUnixId;
    NSString                    *_technicalUnixPassword;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) SecurityUtil *secUtil;
@property (nonatomic, retain) SecurityUtil *backgroundSecUtil;
@property (nonatomic, retain) UIViewController<LaunchViewProtocol> *launchController;
@property (nonatomic, retain) UIViewController<LoginViewProtocol> *loginController;


@property (nonatomic) BOOL useStaticData;
@property (nonatomic) BOOL connected;

@property (nonatomic, retain)   AppStatus           *savedAppStatus;
@property (nonatomic, retain)   NSString            *versionNumber; 
@property (nonatomic)           BOOL                loginFailed;
@property (nonatomic)           BOOL                backgroundLogin;
@property (nonatomic)           BOOL                appSupportsOffline;
@property (nonatomic, retain)   GeneReachability    *geneReachability;
@property (nonatomic)           BOOL                waitingForReachabilityToLogin;
@property (nonatomic)           enum AppDelegateStartMode   appDelegateStartMode;

@property (nonatomic, copy)     NSString            *technicalUnixId;
@property (nonatomic, copy)     NSString            *technicalUnixPassword;

//- (void) showLoginView:(NSString *) prompt;
- (void)showLoginViewModallyWithMessage:(NSString *)message animated:(BOOL)animated;
- (void)showOrUpdateLoginViewWithMessage:(NSString *)message;
- (void)hideLoginView;
- (void)login:(id) sender;
- (BOOL)isLaunchingViewShown;

- (void) continueAppSetup;

- (void) invalidateLoginAndSave;
- (void) performSynchronousCheckOfContentServer;
- (void) passControlToLaunchControllerToPromptForUpgrade: (AppStatus *) appStatus;
- (BOOL) checkSavedAppStatusForUpgrade;
- (void) continueAfterUpgradePrompt;
- (void) continueAfterSuccessfulLogin;
- (void) reportLoginErrorAndStopUntilOnline:(NSString *) loginError;
- (void) handleReachAbilityChangeAfterLoginError;
- (void) loginDataReturned:(LoginStateValue) loginState appStatus:(AppStatus *) appStatus loginError:(NSString *) loginError;
- (void) performLoginSequence;
- (BOOL) shouldUseDefaultExceptionHandler;

/*
 This function performs the actual logout, including presenting loginViewController
 
 To use this, user needs to do:
 - (void)applicationDidRequestLogout {
[self logoutAndShowLoginView];
 // custom UI or model updates after logout
 }
*/

/*
  When calling this method, make sure that either you're calling it as a response to a button tapped by the user or 
  if you're doing it from some other code, that your view controller's stack is initialized. 
 */
- (void)logoutAndShowLoginView;

- (void) initSettings;
- (void) setupApplicationTheme;

- (void) performBackgroundAuthentication:(id <LoginRequestDataHandler>) handler;
- (void) cleanup;

- (void) performAppMainLogic;
- (void) handleGeneReachabilityChanged: (NSNotification* )note;
- (void) initGeneReachability;
- (id)   init;

- (void) applicationWillEnterForeground:(UIApplication *)application;


- (MobileLaunchViewController<LaunchViewProtocol> *)applicationsLaunchingViewController;
- (UIViewController<LoginViewProtocol> *)applicationsLoginViewController;

@end
