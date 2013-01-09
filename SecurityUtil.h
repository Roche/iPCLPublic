//
//  SecurityUtil.h
//  iPhoneApprovals
//
//  Created by qliu on 1/26/09.
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncRequestSender.h"
#import "AppStatus.h"

#define kGneUnixIDKey @"kGneUnixIDKey"
#define kGnePasswordKey @"kGnePasswordKey"


//Data login state
typedef enum{
	LoginStateStart = 0,
	LoginStateDone,
	LoginStateWrongCredential,
	LoginStateError
} LoginStateValue;


@protocol LoginRequestDataHandler <NSObject>

- (void) loginDataReturned:(LoginStateValue) loginState appStatus:(AppStatus *) appStatus loginError:(NSString *) loginError;
@end


@interface SecurityUtil : NSObject <AsyncRequestSecurityUtil, AsyncRequestDataHandler> {
	id <LoginRequestDataHandler> dataHandler;
	NSString *unixId;
	NSString *unixPassword;
    NSString *_applicationUnixId;
    NSString *_applicationUnixPassword;
	LoginStateValue loginState;
	NSString *loginError;
	NSDictionary *currentHeaders;
	NSMutableData *requestData;
	NSString *flowState;
	NSString *ipAddress;
	NSString *ipV6Address;
	NSString *broadcastIpAddress;
	NSString *broadcastV6IpAddress;
	NSString *lastKnownLat;
	NSString *lastKnownLon;
	NSString *lastKnownAlt;
	NSString *bundleDisplayName;
	NSString *bundleName;
	NSString *bundleIdentifier;
	NSString *bundleVersion;
	
	BOOL loggedIn;
	BOOL useStaticData;
	
}
@property (nonatomic, retain) id <LoginRequestDataHandler> dataHandler;
@property (nonatomic) BOOL loggedIn;
@property (nonatomic) BOOL useStaticData;
@property (nonatomic) LoginStateValue loginState;
@property (nonatomic, retain) NSString *loginError;
@property (nonatomic, retain) NSString *unixId;
@property (nonatomic, retain) NSString *unixPassword;
@property (nonatomic, copy) NSString *applicationUnixId;
@property (nonatomic, copy) NSString *applicationUnixPassword;
@property (nonatomic, retain) NSDictionary *currentHeaders;
@property (nonatomic, retain) NSString *flowState;
@property (nonatomic, retain) NSString *ipAddress;
@property (nonatomic, retain) NSString *ipV6Address;
@property (nonatomic, retain) NSString *broadcastIpAddress;
@property (nonatomic, retain) NSString *broadcastV6IpAddress;
@property (nonatomic, retain) NSString *lastKnownLat;
@property (nonatomic, retain) NSString *lastKnownLon;
@property (nonatomic, retain) NSString *lastKnownAlt;
@property (nonatomic, copy) NSString *bundleDisplayName;
@property (nonatomic, copy) NSString *bundleName;
@property (nonatomic, copy) NSString *bundleIdentifier;
@property (nonatomic, retain) NSString *bundleVersion;


- (BOOL) needLogin;
- (void) performLogin:(BOOL) getUserDetail;
- (void) performLogout;
- (void) addAuthHeader:(NSMutableURLRequest *) urlRequest updateTimestamp:(BOOL) performUpdateTimestamp;
@end


