//
//  LoggingUtils.h
//  iPhoneApprovals
//
//  Created by qliu on 2/26/09.
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncRequestSender.h"

#define SFDC_TARGET @"SFDC"

extern NSInteger logLevel; 

/** Macros for logging
 
 * LOG_MESSAGE(LEVEL,formatString, ...) 
 * Invokes NSLog if LEVEL >= LOG_LEVEL string from Info.plist
 * LOG_LEVELs in order and corresponding string
 *      LOG_LEVEL_DEBUG DEBUG 
 *      LOG_LEVEL_INFO  INFO
 *      LOG_LEVEL_WARN  WARN
 *      LOG_LEVEL_ERROR ERROR
 *      LOG_LEVEL_NONE  NONE
 *
 * LOG_LEVEL defaults to LOG_LEVEL_ERROR 
 *
 * To have method printed in output change NSLog(@"DEBUG %s:" format,__func__, ##__VA_ARGS__);
 * Or add this to the LOG_MESSAGE format
 */ 
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO  2
#define LOG_LEVEL_WARN  3
#define LOG_LEVEL_ERROR 4
#define LOG_LEVEL_NONE  5

// To add
#define LOG_MESSAGE(LEVEL, format, ...)    \
if (LEVEL>=logLevel) {\
if (LEVEL == LOG_LEVEL_ERROR) NSLog(@"ERROR:" format, ##__VA_ARGS__); \
else if(LEVEL == LOG_LEVEL_WARN) NSLog(@"WARN:" format, ##__VA_ARGS__); \
else if(LEVEL == LOG_LEVEL_INFO) NSLog(@"INFO:" format, ##__VA_ARGS__); \
else if(LEVEL == LOG_LEVEL_DEBUG) NSLog(@"DEBUG %s:" format,__func__, ##__VA_ARGS__); \
else (void)0; } \
else (void)0;


typedef enum{
	ServerLoggingVerbose = 1,
	ServerLoggingInfo = 2,
	ServerLoggingSevere = 4
} ServerLoggingLevel;

typedef enum{
	ServerLoggingStatusInProgress = 0,
	ServerLoggingStatusBegin,
	ServerLoggingStatusEnd,
	ServerLoggingStatusWarn,
	ServerLoggingStatusError
} ServerLoggingStatus;


@interface LoggingUtils : NSObject <AsyncRequestDataHandler> {
    AsyncRequestSender    *request;
}

@property (nonatomic, retain)   AsyncRequestSender    *request;

/** Macros and methods for logging
 
 * Invokes esb package defined in plist in esbServerLoggingNSName key
 * e.g. GneCOMM_SFAMobile.Services:remoteLogging or Gne_NonValUtils.Logging.Services:remoteLogging
 * uses asynchronous request (AsyncRequestSender)
 * message is prepended by 
 * "<BundleName> error in <function>:"
 * errorMessage is prepended by 
 * "<BundleName> <versionShortString> <bundleVersion>
 * UnixId: <UnixId>
 * function: <function>"
 * An email rule can be configured in the ESB to provide notification of these errors through a gRemedy ticket
 * Specify the following fields
 * Entity:             <BundleName>
 * Process Status:     ERROR
 * Source System:      iPhone
 * Target System:      <BundleName>
 * Error Type:         any
 * Email Address:      iphone-<BundleName>-adm-d@gene.com
 * The message (prepended as indicated above) will be the subject of the message
 */

/** Retrieve LOG_LEVEL from Info.plist and set logLevel for LOG_MESSAGE macro
 *
 * Defaults to LOG_LEVEL_ERROR if not found in plist
 */
+ (void) initLogLevelFromInfoList;

/** Attempts creation of string using UTF8 encoding if fails uses base64
 *
 * @param data To be encoded as string
 * @return NSString
 */
+ (NSString *) NStringWithUtf8OrBase64EncodingFromData:(NSData *) data;

/**
 * log Error with ESB
 * Invokes esb package defined in plist in esbServerLoggingNSName key
 * e.g. GneCOMM_SFAMobile.Services:remoteLogging or Gne_NonValUtils.Logging.Services:remoteLogging
 * uses synchronous request (NSMutableURLRequest) - for use in background processes
 */
+ (void) syncLogError:(NSString *) targetSystem function:(NSString *) function errorMessage:(NSString *) errorMessage data:(NSString *) data;

/** syncLogError convenience method
 
 * targetSystem set to bundleName
 * message set to "<BundleName> error in <function>:"
 */
+ (void) syncLogError:(NSString *) function errorMessage:(NSString *) errorMessage data:(NSString *) data ;

/** syncLogError for potentially improperly coded data
 
 * @param encodedData invokes NStringWithUtf8OrBase64EncodingFromData on encoded data before passing to syncLogError as string
 */
+ (void) syncLogError:(NSString *) targetSystem function:(NSString *) function errorMessage:(NSString *) errorMessage encodedData:(NSData *) data;

/** log Error with ESB
 *
 * @param targetSystem Target System field in ESB mail rule
 * @param function Prepended to Message and ErrorMessage
 * @param message Becomes subject of ESB email rule. 
 * Prepended by "<BundleName> error in <function>:"
 *
 * @param errorMessage Attached as a file to email created by ESB
 * Prepended by 
 * "<BundleName> <versionShortString> <bundleVersion>
 * UnixId: <UnixId>
 * function: <function>"
 *
 * @param data Attached  as afile to email created by ESB
 */
+ (void) logError:(NSString *) targetSystem function:(NSString *) function message:(NSString *) message errorMessage:(NSString *) errorMessage data:(NSString *) data;

/** logError convenience method
 *
 * message set to "<BundleName> error in <function>:"
 */
+ (void) logError:(NSString *) targetSystem function:(NSString *) function errorMessage:(NSString *) errorMessage data:(NSString *) data;

/** logError convenience method
 *
 * targetSystem set to bundleName
 */
+ (void) logError:(NSString *) function message:(NSString *) message errorMessage:(NSString *) errorMessage data:(NSString *) data;

/** logError convenience method
 *
 * targetSystem set to bundleName
 * message set to "<BundleName> error in <function>:"
 */
+ (void) logError:(NSString *) function errorMessage:(NSString *) errorMessage data:(NSString *) data;

/** logError for potentially improperly coded data
 
 * @param encodedData invokes NStringWithUtf8OrBase64EncodingFromData on encoded data before passing to syncLogError as string
 */
+ (void) logError:(NSString *) targetSystem function:(NSString *) function message:(NSString *) message errorMessage:(NSString *) errorMessage encodedData:(NSData *) data;

/** log result of async logging - primarily for debugging
 *
 * @param requestId
 * @param dataReturned
 * @param requestState
 * @param requestError
 */ 
- (void) requestDataReturned:(NSString *) requestId dataReturned:(NSData *)dataReturned requestState:(AsyncRequestStateValue) requestState requestError:(NSString *) requestError;

@end
