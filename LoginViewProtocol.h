//
//  LoginViewProtocol.h
//  iPhoneCommonLibrary
//
//  Created by Maciej Skolecki on 9/30/11.
//  Copyright 2011 Genentech Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol LoginViewProtocol <NSObject>

/*
 loginPrompt is for getting error messages
 such as "Invalid login. Please retry", etc.
 You can display it in an alert, label, etc. to the user
 */
@property (nonatomic, retain) NSString *loginPrompt;
@end
