//
//  Copyright 2014 Genentech. All rights reserved.

#import <Foundation/Foundation.h>

#define SEARCH_DELAY 0.5


@interface NSTimerFactory : NSObject 
{
}
+(NSTimer*)Create:(NSTimeInterval) timeToExecute selector:(SEL)functionToExecute target:(id)aTarget;

@end
