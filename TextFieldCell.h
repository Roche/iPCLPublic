//
//  TextFieldCell.h
//  Copyright 2014 Genentech. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface TextFieldCell : UITableViewCell
{
	UITextField *_textField;
	CGFloat _textFieldLeftPos;
}

@property (nonatomic, retain, readonly) UITextField *textField;
@property (nonatomic) CGFloat textFieldLeftPos;

- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

@end
