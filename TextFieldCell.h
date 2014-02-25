//
//  TextFieldCell.h
//  Copyright 2014 Genentech. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface TextFieldCell : UITableViewCell
{
	UITextField *_textField;
	NSInteger _textFieldLeftPos;
}

@property (nonatomic, retain, readonly) UITextField *textField;
@property (nonatomic) NSInteger textFieldLeftPos;

- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier;

@end
