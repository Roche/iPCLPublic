//
//  AboutViewController.h
//  HelpUtils
//
//  Created by qliu on 1/23/09.
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

enum hiddenScreenInvocationState {
	initialState,
	firstTap,
	secondTap,
	thirdTap,
};

@interface AboutViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
	UITableView *aboutTable;
	UIButton *logoutButton;

}

@property (nonatomic, readonly) UITableView *aboutTable;
@property (nonatomic, readonly) UIButton *logoutButton;

@end
