//
//  UIUtils.h - UI related utility for Genentech Common Utility framework
//  gEmpFind
//
//  Created by qliu on 12/23/08.
//  Copyright 2008 Genentech, Inc All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UIUtils : NSObject 
{
}

+ (void) displayAlert:(NSString *) title withMessage:(NSString *) message;
+ (void) displayAlert:(NSString *) title withMessage:(NSString *) message sender:(id)sender;
+ (UILabel *) newLabelWithPrimaryColor:(UIColor *)primaryColor selectedColor:(UIColor *)selectedColor fontSize:(CGFloat)fontSize bold:(BOOL)bold;
+ (UIButton *) buttonWithImage:(UIImage *)image	
					    target:(id)target
					  selector:(SEL)selector
						 frame:(CGRect)frame;
+ (UIButton *) buttonWithTitle:	(NSString *)title
					buttonType:(UIButtonType) buttonType
					    target:(id)target
					  selector:(SEL)selector
						 frame:(CGRect)frame
					  fontSize:(CGFloat)fontSize
					titleColor:(UIColor *) textColor;

@end
