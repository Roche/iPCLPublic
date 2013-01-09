//
//  NSBundle+Orientation.h
//  iPhoneCommonLibrary
//
//  Created by Michal Karwanski on 10/11/11.
//  Copyright 2011 Genentech Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSBundle (Orientation)

- (BOOL)isOrientationSupported:(UIInterfaceOrientation)interfaceOrientation;

@end
