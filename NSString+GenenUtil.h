//
//  NSString+GenenUtil.h
//  RequestSender
//
//  Created by qliu on 7/8/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (GenenUtil)

+ (bool) isEmpty:(NSString *) source;
+ (bool) isValidPhoneNumber:(NSString *) phoneNumber;
+ (bool) isValidEmailAddress:(NSString *) email;
+ (bool) isValidPhoneNumber:(NSString *) phoneNumber allowEmpty:(BOOL) allowEmpty;
+ (bool) isValidEmailAddress:(NSString *) email allowEmpty:(BOOL) allowEmpty;
- (NSString *) trimStr:(NSString *) trimStr;
- (NSString *) trim;
- (NSString *) escapeXMLEntities;
- (bool) isNumeric; 
- (NSString *) capitalizedStringAsPersonName;
- (NSString *) capitalizedStringAsAddress;
- (NSArray *)tokens;
- (NSString *)urlEncodedString;
- (NSString *)stringOfNumericCharacters;
@end
