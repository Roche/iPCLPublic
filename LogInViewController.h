//
//  LogInViewController.h
//  iPhoneApprovals
//
//  Created by qliu on 1/15/09.
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MobileAppDelegate.h"
#import "TextFieldCell.h"

@interface LogInViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate, LoginViewProtocol>
{
}

@property (nonatomic, retain) IBOutlet UINavigationBar *navBar;
@property (nonatomic, retain, readonly) TextFieldCell *usernameCell;
@property (nonatomic, retain, readonly) TextFieldCell *passwordCell;
@property (nonatomic, retain) NSString *loginPrompt;

- (void) refreshData;

@end
