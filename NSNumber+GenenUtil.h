//
//  NSNumber+GenenUtilsh
//
//
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSNumber (GenenUtil)

+ (NSNumber *)parseBool:(NSString *)value;
+ (NSNumber *)parseInteger:(NSString *)value;
+ (NSNumber *)parseDouble:(NSString *)value;

@end
