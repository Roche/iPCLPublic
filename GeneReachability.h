//
//  GeneReachability.h
//  iPhoneCommonLibrary
//
//  Created by Ken Hansen on 9/21/11.
//  Copyright 2011 Genentech Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Reachability.h"

#define kGeneReachabilityChangedNotification @"GeneReachabilityChangedNotification"

@interface GeneReachability : NSObject {
    BOOL _isOnGeneNetwork;
    BOOL _isB2bReachable;
    BOOL _isInternetReachable;
    BOOL _isOnWifi;
}

@property (nonatomic)  BOOL isOnGeneNetwork;
@property (nonatomic)  BOOL isInternetReachable;
@property (nonatomic)  BOOL isB2bReachable;
@property (nonatomic)  BOOL isOnWifi;
    
+ (GeneReachability *) sharedGeneReachability;

+ (BOOL) isInternetReachable;

/**
 * used to update iVars when reachability changes
 */
- (void) updateInterfaceWithReachability: (Reachability*) curReach;


@end
