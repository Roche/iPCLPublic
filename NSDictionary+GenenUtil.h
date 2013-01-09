//
//  NSDictionary+GenenUtil.h
//  On the Road
//
//  Created by Greg Martin on 1/19/10.
//  Copyright 2010 Slalom Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSDictionary (GenenUtil)

- (NSString *)queryString;
- (id)objectForIntKey:(int)key;

@end
