//
//  KeyValuePair.h
//  On the Road
//
//  Created by Greg Martin on 10/4/09.
//  Copyright 2009 Slalom Consulting. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface KeyValuePair : NSObject
{
	NSObject *_key;
	NSString *_value;
	NSString *_detail;
	BOOL	_custom;
}

@property (nonatomic, retain) NSObject *key;
@property (nonatomic, retain) NSString *value;
@property (nonatomic, retain) NSString *detail;
@property (nonatomic) BOOL custom;

- (id)initWithKey:(NSObject *)key value:(NSString *)value;
+ (id)pairWithKey:(NSObject *)key value:(NSString *)value;
- (id)initWithKey:(NSObject *)key value:(NSString *)value custom:(BOOL) custom;
+ (id)pairWithKey:(NSObject *)key value:(NSString *)value custom:(BOOL) custom;
- (id)initWithKey:(NSObject *)key value:(NSString *)value detail:(NSString *)detail;
+ (id)pairWithKey:(NSObject *)key value:(NSString *)value detail:(NSString *)detail;
- (id)initWithKey:(NSObject *)key value:(NSString *)value detail:(NSString *)detail custom:(BOOL) custom;
+ (id)pairWithKey:(NSObject *)key value:(NSString *)value detail:(NSString *)detail custom:(BOOL) custom;

@end
