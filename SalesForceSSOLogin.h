//
//  SalesForceFacade.h
//  ICCalc
//
//  Created by Krzysztof Cieplucha on 8/13/12.
//
//

#import <Foundation/Foundation.h>

@interface SalesForceSSOLogin : NSObject <NSURLConnectionDataDelegate, NSXMLParserDelegate>

+ (id)loginWithUsername:(NSString *)aUsername password:(NSString *)aPassword andComplitionHandler:(void (^)(NSString *aToken, NSString *aSFHost, NSError *error))aComplitionHandler;

- (id)initWithUsername:(NSString *)aUsername password:(NSString *)aPassword andComplitionHandler:(void (^)(NSString *aToken, NSString *aSFHost, NSError *error))aComplitionHandler;

@end
