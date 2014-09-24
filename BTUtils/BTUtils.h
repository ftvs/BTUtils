//
//  BTUtils.h
//
//  Version 1.3.9
//
//  Created by Borut Tomazin on 8/30/2013.
//  Copyright 2013 Borut Tomazin
//
//  Distributed under the permissive zlib License
//  Get the latest version from here:
//
//  https://github.com/borut-t/BTUtils
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

#import <UIKit/UIKit.h>
//#import "NSString+BTUtils.h"
//#import "NSData+BTUtils.h"
//#import "UIImage+BTUtils.h"
//#import "UIView+BTUtils.h"
//#import "UINavigationController+BTUtils.h"
//#import "UITabBarController+BTUtils.h"

#define RGB(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1]
#define RGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define SYSTEM_VERSION_GREATER_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define DEVICE_SIZE [[[[UIApplication sharedApplication] keyWindow] rootViewController].view convertRect:[[UIScreen mainScreen] bounds] fromView:nil].size
#define RADIANS_TO_DEGREES(radians) ((radians) * (180.0 / M_PI))
#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)

/**
 Drop-in replacement for standard NSLog
 */
#ifdef DEBUG
#	define BSLog(format, ...) NSLog((@"%s[%d] " format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#	define BSLog(...)
#endif


@interface BTUtils : NSObject


#pragma mark - Device
/**
 Returns the current version of the operating system.
 */
+ (NSString *)OSVersion;

/**
 Returns app version string using key 'CFBundleShortVersionString'.
 */
+ (NSString *)appVersion;

/**
 Returns app build string using key 'CFBundleVersion'.
 */
+ (NSString *)appBuild;

/**
 Returns device model.
 */
+ (NSString *)deviceModel;

/**
 Returns screen size.
 */
+ (CGSize)screenSize;

/**
 Returns interface orienation.
 */
+ (UIInterfaceOrientation)orientation;

/**
 Returns YES when UIUserInterfaceIdiom is Pad.
 */
+ (BOOL)isPad;

/**
 Returns YES when UIUserInterfaceIdiom is Phone.
 */
+ (BOOL)isPhone;

/**
 Returns YES if device is phone and 4inch (a.k.a. iPhone 5/5s/5c).
 */
+ (BOOL)isPhone4Inch;

/**
 Returns YES if device screen has retina resolution.
 */
+ (BOOL)isRetina;

/** 
 Returns YES if right-to-left system language is set.
 */
+ (BOOL)isRTL;

/**
 Returns the string representation of a specified CFUUID object.
 */
+ (NSString *)CFUUID;



#pragma mark - Network
/**
 Toggles network activity indicator.
 
 @param show A toggle boolean value defining network loader visibility.
 */
+ (void)showNetworkLoader:(BOOL)show;

/**
 Returns resource path for selected file name.
 
 @param name A file name represented on filesystem.
 */
+ (NSString *)resourcePath:(NSString *)name;

/**
 Returns App Store link for selected appId.
 
 @param appId And appId to generate App Store link with.
 */
+ (NSString *)appStoreLinkForAppId:(NSString *)appId;

/**
 Url encodes string.
 
 @param string An input string to be url encoded.
 */
+ (NSString *)urlEncodedString:(NSString *)string;



#pragma mark - Image
/**
 Returns uncached image from filesystem.
 
 @param name An image name to be loaded from the filesystem.
 */
+ (UIImage *)imageNamed:(NSString *)name;

/**
 Generates new UIImage for selected color and size.
 
 @param color UIColor of the target image.
 @param size CGSize of the target image.
 */
+ (UIImage *)imageWithColor:(UIColor *)color andSize:(CGSize)size;

/**
 Captures screen for selected view.
 
 @param view View that is going to be captured.
 @return View screenshot.
 */
+ (UIImage *)captureView:(UIView *)view;

/**
 Captures frame inside selected view.
 
 @param frame Frame that is going to be captured.
 @param view View hosting frame.
 @return View frame screenshot.
 */
+ (UIImage *)captureFrame:(CGRect)frame inView:(UIView *)view;


@end
