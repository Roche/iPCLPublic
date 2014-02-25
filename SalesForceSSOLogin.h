//
//  SalesForceFacade.h
//  ICCalc
//
//  Created by Krzysztof Cieplucha on 8/13/12.
//  Copyright 2014 Genetech, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

// for information purposes only so that you know what it is. Changes here will not affect anything - it's a macro. 
#define SALESFORCE_HOST_PATTERN @"(?<=https://)(.*?)(?=.salesforce.com)"

@protocol SalesForceSSOLoginParserDelegate <NSObject>
-(NSRegularExpression *)regexpForHostParsing;
@end


@interface SalesForceSSOLogin : NSObject <NSURLConnectionDataDelegate, NSXMLParserDelegate, SalesForceSSOLoginParserDelegate>

+ (id)loginWithUsername:(NSString *)aUsername password:(NSString *)aPassword andComplitionHandler:(void (^)(NSString *aToken, NSString *aSFHost, NSError *error))aComplitionHandler;

- (id)initWithUsername:(NSString *)aUsername password:(NSString *)aPassword andComplitionHandler:(void (^)(NSString *aToken, NSString *aSFHost, NSError *error))aComplitionHandler;

@end
