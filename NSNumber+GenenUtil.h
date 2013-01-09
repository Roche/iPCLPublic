//
//  NSNumber+GenenUtilsh
//  On the Road
//
//  Created by Greg Martin on 10/26/09.
//  Copyright 2009 Slalom Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSNumber (GenenUtil)

+ (NSNumber *)parseBool:(NSString *)value;
+ (NSNumber *)parseInteger:(NSString *)value;
+ (NSNumber *)parseDouble:(NSString *)value;

@end
