//
//  NSData+GenenUtil.h
//  EncryptionPoC
//
//  Created by qliu on 1/29/09.
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (GenenUtil)
+ (id)dataWithBase64EncodedString:(NSString *)string;     //  Padding '=' characters are optional. Whitespace is ignored.
- (NSString *)base64Encoding;
@end




