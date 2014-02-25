//
//  KeychainUserData.h
//  keychain-test-1
//
//  Created by Michal Karwanski on 4/13/10.
//  Copyright 2010 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface KeychainUserData : NSObject {

	NSString *username;
	NSString *password;
	NSDictionary *data;
	
}

- (id) initWithUsername: (NSString *)aUserName password: (NSString *)aPassword data: (NSDictionary *)data;
- (id) initWithUsername: (NSString *)aUserName password: (NSString *)aPassword dataAsString: (NSString *)string;

@property (nonatomic, readonly) NSString *username;
@property (nonatomic, readonly) NSString *password;
@property (nonatomic, readonly) NSDictionary *data;
@property (nonatomic, readonly) NSString *dataAsString;

@end
