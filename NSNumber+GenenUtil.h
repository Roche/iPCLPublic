//
//  NSNumber+GenenUtilsh
//

#import <Foundation/Foundation.h>


@interface NSNumber (GenenUtil)

+ (NSNumber *)parseBool:(NSString *)value;
+ (NSNumber *)parseInteger:(NSString *)value;
+ (NSNumber *)parseDouble:(NSString *)value;

@end
