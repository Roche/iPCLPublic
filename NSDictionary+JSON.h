//
//  NSDictionary+JSON.h
//  On the Road
//
//  Created by Marcin Obel on 3/23/10.
//  Copyright 2010 Genentech Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSDictionary (JSON)

- (NSString*)serializeToJSON;
	
@end
