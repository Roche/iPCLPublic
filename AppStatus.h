//
//  AppStatus.h
//  RequestSender
//
//  Created by qliu on 7/10/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


#define APP_PARAMS_KEY @"parameters"

@interface AppStatus : NSObject {
	BOOL            newVersionAvailable;
	BOOL            upgradeRequired;
	BOOL            isKilled;
	NSString        *appMessage;
	NSDictionary    *userData; 
	NSDictionary    *appParams;
    NSDate          *lastNagDate;
}

@property (nonatomic) BOOL newVersionAvailable;
@property (nonatomic) BOOL upgradeRequired;
@property (nonatomic, readonly) BOOL isKilled;
@property (nonatomic, readonly) BOOL isAllowedOsVersion;
@property (nonatomic, retain) NSDictionary *appParams;
@property (nonatomic, retain) NSString *appMessage;
@property (nonatomic, retain) NSDictionary *userData;
@property (nonatomic, retain) NSDate *lastNagDate;


- (id)initWithDictionary:(NSDictionary *) data;

- (void)updateWithAppStatus:(AppStatus *)appStatus;
- (void)parseAppParams:(NSArray *)params;
- (NSDictionary *) toDictionary;

@end


