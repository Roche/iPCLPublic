//
//  NSDictionary+GenenUtil.h
//
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSDictionary (GenenUtil)

- (NSString *)queryString;
- (id)objectForIntKey:(int)key;

@end
