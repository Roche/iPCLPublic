//
//  AboutCell.h
//  LaunchPad
//
//  Created by qliu on 7/29/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface AboutCell : UITableViewCell {
	UILabel *appName;
	UILabel *appDesc;
	UILabel *appCopyright;
	UILabel *appVersion;
	UILabel *envUnixId;
	UILabel *frameworkVersion;
}

@end
