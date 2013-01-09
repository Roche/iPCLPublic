//
//  UsageTracking.h
//  Avastin
//
//  Created by qliu on 7/24/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADMS_Measurement.h"

#define kDNANotificationPageViewed @"kDNANotificationPageViewed"

@interface UsageTracking : NSObject {
}

/**
 * invoke tracking with specified tracking object
 */
+ (void) trackWith:(ADMS_Measurement*) tracking pageViewed:(NSString *) pageName section:(NSString *) section;

/**
 * invoke tracking w/ appDelegate.tracking
 */
+ (void) pageViewed:(NSString *) pageName section:(NSString *) section;

@end
