//
//  AsyncRequestSender.h
//  RequestSender
//
//  Created by qliu on 7/8/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>
#define kGneInvalidCredentialError @"invalid login credential"

typedef enum{
	AsyncRequestStateNormal = 0,
	AsyncRequestStateLoading,
	AsyncRequestStateError,
	AsyncRequestStateLoaded
} AsyncRequestStateValue;

@protocol AsyncRequestSecurityUtil <NSObject>
- (void) addAuthHeader:(NSMutableURLRequest *) urlRequest updateTimestamp:(BOOL) performUpdateTimestamp;
@end

@protocol AsyncRequestDataHandler <NSObject>
- (void) requestDataReturned:(NSString *) requestId dataReturned:(NSData *)dataReturned requestState:(AsyncRequestStateValue) requestState requestError:(NSString *) requestError;
@end


@interface AsyncRequestSender : NSObject {
	id <AsyncRequestSecurityUtil> secUtil;
	id <AsyncRequestDataHandler> dataHandler;
	AsyncRequestStateValue loadingState;
	
    NSMutableData *requestData;
	NSString *requestUrl;
	NSString *requestIdentifier;
	NSString *loadingError;
	BOOL localFile;
	BOOL usePost;
	BOOL updateServerTimestamp;
	NSString *postData;
}

@property (nonatomic, retain) id <AsyncRequestSecurityUtil> secUtil;
@property (nonatomic, retain) id <AsyncRequestDataHandler> dataHandler;
@property (nonatomic, assign) AsyncRequestStateValue loadingState;
@property (nonatomic, retain) NSURLConnection *requestConnection;
@property (nonatomic, retain) NSMutableData *requestData;
@property (nonatomic, retain) NSString *requestUrl;
@property (nonatomic, retain) NSString *requestIdentifier;
@property (nonatomic, retain) NSString *loadingError;
@property (nonatomic, retain) NSString *postData;
@property (nonatomic) BOOL updateServerTimestamp;
@property (nonatomic) BOOL localFile;
@property (nonatomic) BOOL usePost;

//Initialization Methods
- (id) init:(NSString *) requestId url:(NSString *) url;
- (id) init:(NSString *) requestId url:(NSString *) url isLocal:(BOOL) localFlag;
- (id) init:(NSString *) requestId url:(NSString *) url updateServerStamp:(BOOL) updateServerStamp isLocal:(BOOL) localFlag isPost:(BOOL) postFlag dataToPost:(NSString *) dataToPost;

//Main method to load request
- (void) loadRequest;
@end
