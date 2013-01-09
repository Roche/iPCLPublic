//
//  TextFieldCell.h
//  On the Road
//
//  Created by Greg Martin on 10/28/09.
//  Copyright 2009 Slalom Consulting. All rights reserved.
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
