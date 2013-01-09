//
//  GneJSONDataRequestHandler.h
//  RequestSender
//
//  Created by qliu on 7/8/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GneJSONDataRequestHandler : NSObject {

}

+ (NSArray *) parseDataListFromDictionary:(NSDictionary *) jsonData listDataKey:(NSString *) listDataKey;


+ (NSArray *) parseDataListFromDictionary:(NSDictionary *) jsonData rootObjectKey:(NSString *) rootObjectKey listDataKey:(NSString *) listDataKey 
								statusKey:(NSString *) statusKey statusMessageKey:(NSString *) statusMessageKey
									error:(NSError **) error;

//Parse an NSData object to get a list data out that identified by the specific listDataKey, statusKey and statusMessageKey is used to get error status
+ (NSArray *) parseDataListFromJSONData:(NSData *) data rootObjectKey:(NSString *) rootObjectKey listDataKey:(NSString *) listDataKey 
								 statusKey:(NSString *) statusKey statusMessageKey:(NSString *) statusMessageKey
								 error:(NSError **) error;

+ (NSDictionary *) parseDataFromJSONData:(NSData *) data error:(NSError **) error;
@end
