//
//  EmailUtils.h
//  On the Road
//
//  Created by qliu on 10/1/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import <MessageUI/MFMailComposeViewController.h>

@interface EmailUtils : NSObject {

}
+ (void) sendEmail:(NSString *) toEmail callBack:(UIViewController <MFMailComposeViewControllerDelegate> *) requester;
@end
