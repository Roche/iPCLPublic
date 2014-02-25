//
//  Copyright 2014 Genentech. All rights reserved.

#import "NSNumber+GenenUtil.h"
#import "NSString+GenenUtil.h"
#import "NSData+GenenUtil.h"
#import "NSError+GenenUtil.h"
#import "NSDictionary+GenenUtil.h"
#import "UsageTracking.h"

#define OPAQUE_HEXCOLOR(c) [UIColor colorWithRed:((c>>16)&0xFF)/255.0 green:((c>>8)&0xFF)/255.0 blue:(c&0xFF)/255.0 alpha:1.0] 
#define DEFAULT_TOOLBAR_TINT_COLOR 0xE26F24 //0x533414
#define DEFAULT_RED_COLOR 0x990000
#define DEFAULT_GRAY_COLOR 0x4C4C4C
#define DEFAULT_BACKGROUND_IMAGE @""
#define TEXT_COLOR_ON_BACKGROUND 0xffffff
#define APP_DISPLAY_TITLE nil
#define DEFAULT_FONT_SIZE 13.0
#define DEFAULT_LARGE_FONT_SIZE 14.0
#define STANDARD_ANIMATION_DURATION 0.3
#define LAUNCH_CONTROLLER_INDICATOR_POSITION_IPHONE CGRectMake(142, 378, 37, 37)
#define LAUNCH_CONTROLLER_INDICATOR_POSITION_IPAD CGRectMake(142, 378, 37, 37) // for now, change later

#define kCellPadding 10
#define kDefaultSelectionStyle UITableViewCellSelectionStyleGray
#define kSecondsInDay 86400

#define HAS_DONE_INITIAL_LOAD_PREFERENCE @"HAS_DONE_INITIAL_LOAD_PREFERENCE"
#define LAST_SELECTED_TERRITORY_PREFERENCE @"LAST_SELECTED_TERRITORY_PREFERENCE"
#define LAST_SYNC_DATE_PREFERENCE @"LAST_SYNC_DATE_PREFERENCE"
#define SYNC_START_PREFERENCE @"SYNC_START_PREFERENCE"
#define SYNC_FAILED_PREFERENCE @"SYNC_FAILED_PREFERENCE"
#define LAST_EDITED_MEDCOMM_ID_PREFERENCE @"LAST_EDITED_MEDCOMM_ID_PREFERENCE"
#define LAST_EDITED_INTERACTION_ID_PREFERENCE @"LAST_EDITED_INTERACTION_ID_PREFERENCE"

#define LocStr(key) NSLocalizedString((key), @"")
#define LocStrDefVal(key, defVal) NSLocalizedStringWithDefaultValue((key), nil, [NSBundle mainBundle], (defVal), @"")
#define LocDef(key) NSLocalizedStringWithDefaultValue([NSString stringWithCString:(#key) encoding:NSUTF8StringEncoding], nil, [NSBundle mainBundle], (key), @"")

enum ViewMode {
	ViewModeCreate,
	ViewModeUpdate
};


extern NSString * DEFAULT_BACKGROUND_COLOR;
extern NSString * LAUNCH_BACKGROUND_IMAGE;
extern NSString *LAUNCH_BACKGROUND_IMAGE_IPHONE_5;
extern NSString * LAUNCH_BACKGROUND_PORTRAIT_IMAGE_IPAD;
extern NSString * LAUNCH_BACKGROUND_LANDSCAPE_IMAGE_IPAD;
extern NSString * DEFAULT_TINT_COLOR;
extern NSString * IMPERSONATE_USERID;
extern NSString * DEFAULT_LOADING_INDICATOR_STYLE;

BOOL isIPad(void);
BOOL isiPhone5(void);
