//
//  DataUtils.h
//  On the Road
//
//  Created by qliu on 9/23/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TIME_INTERVAL 30
#define CONTACT_ID_PREFIX @"CON"
#define ACCOUNT_ID_PREFIX @"ACT"
#define AFFILIATION_ID_PREFIX @"AFF"
#define INTERACTION_ID_PREFIX @"INT"
#define ATTENDEE_ID_PREFIX @"ATT"
#define DETAIL_ID_PREFIX @"DET"
#define DISCUSSION_ID_PREFIX @"DIS"
#define SAMPLE_ID_PREFIX @"SAM"
#define MEDCOMM_ID_PREFIX @"MED"

@interface DataUtils : NSObject {

}

+ (NSDate *) serverDateStringToDate:(NSString *) serverDate dateOnly:(BOOL) dateOnly;
+ (NSDate *) serverDateStringToDate:(NSString *) serverDate;
+ (NSString *) dateToLocalString:(NSDate *) date;
+ (NSString *) timeToLocalString:(NSDate *) date;
+ (NSString *) timeToExtendedLocalString:(NSDate *) date;
+ (NSString *) timeToSFDCString:(NSDate *) date;
+ (NSString *) timeToServerString:(NSDate *) date;
+ (NSString *) buildDisplayAddress:(NSString *)addressLine1 line2:(NSString *)addressLine2 city:(NSString *) city state:(NSString *) state zip:(NSString *) zip zip4:(NSString *) zip4;
+ (NSString *) buildAddressLine2:(NSString *) city state:(NSString *) state zip:(NSString *) zip zip4:(NSString *) zip4;
+ (NSString *) buildPhone:(NSString *) phone withExtension:(NSString *) ext;
+ (NSDate *) adjustDate:(NSDate *) sourceDate byInterval:(NSInteger) interval;
+ (NSString *) doubleToCurrency:(double) value;
+ (double) currencyToDouble:(NSString *) value;

@end
