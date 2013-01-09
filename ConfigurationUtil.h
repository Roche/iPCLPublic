//
//  ConfigurationUtil.h
//  iPhoneApprovals
//
//  Created by qliu on 2/22/09.
//  Copyright 2009 Genetech, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ConfigurationUtil : NSObject<UIAlertViewDelegate> {

}

+ (void)showAlertForChangingEnvSetting;

+ (id) getKeyFromInfoList:(NSString *) key;
@end
