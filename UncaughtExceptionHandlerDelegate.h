@protocol UncaughtExceptionHandlerDelegate<NSObject>
@optional
- (void)validateAndSaveCriticalApplicationDataOnAppCrash;
@end
