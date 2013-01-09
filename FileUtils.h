//
//  FileUtils.h
//  Avastin
//
//  Created by qliu on 7/14/09.
//  Copyright 2009 Genentech. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface FileUtils : NSObject {

}

+ (NSString *)documentsDirectory;
+ (NSString *)cacheDirectory;
+ (NSString *)resourceDirectory;
+ (NSString *) copyFileToDocumentsDirecory:(NSString *) source overwrite:(BOOL) overwriteIfExists;
+ (NSString *) copyFileToDocumentsDirecory:(NSString *) source overwrite:(BOOL) overwriteIfExists checkDate:(BOOL) checkDateForOverwrite;
+ (NSDate *) getFileLastModifiedDate:(NSString *) filePath;
+ (NSDate *) getFileLastModifiedDate:(NSString *) file inDirectory:(NSString *) directory;
+ (BOOL) fileExists:(NSString *) file inDirectory:(NSString *) directory;
+ (BOOL) fileExistsAtPath:(NSString *) filePath;
+ (NSNumber *) fileSize:(NSString *) file inDirectory:(NSString *) directory;
+ (void) removeFileAtPath:(NSString *) filePath;
+ (void)moveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;

/**
   Adds file protection attributes to the file at path. 

   This method allows to add NSFileProtectionComplete attribute to a
   file at a specified path. Adding this attribute encrypts the file
   thus protecting it from unauthorized read. This method should be
   invoked on all files written by the app unless the requirements
   clearly dictate otherwise 
*/
+ (void) addFileProtectionAttributesToFilePath: (NSString *) filePath;

@end
