//
//  LoginManager.h
//  iPhoneCommonLibrary
//
//  Created by Yuliang Ma on 11/14/12.
//  Copyright (c) 2012 Genentech Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LoginManager : NSObject
+ (void)loginWithUsername: (NSString *)username password: (NSString *)password;
@end
