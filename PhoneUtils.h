//
//  PhoneUtils.h
//  On the Road
//
//  Created by qliu on 10/16/09.
//  Copyright 2009 Genentech, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PhoneUtils : NSObject {

}

+ (BOOL) isCell:(NSString *) number;
+ (NSString *) formatNumber:(NSString *) number asPhone:(BOOL) asPhone;
+ (NSString *) urlForNumber:(NSString *) number;
 
@end
