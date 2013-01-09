//
//  MessageView.h
//  Avastin
//
//  Created by qliu on 7/15/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <UIKit/UIKit.h>
#define MESSAGE_VIEW_PADDING 8.0

@interface MessageView : UIView {
	float opacity;
	float width;
	float height;
	UILabel *messageLabel;
}

@property (assign) float opacity;
@property (retain) UILabel *messageLabel;
- (void) showMessage:(NSString *) message;

@end
