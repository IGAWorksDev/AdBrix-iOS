//
//  AdBrix.h
//  AdBrixLib
//
//  Created by wonje,song on 2015. 5. 21..
//  Copyright (c) 2015년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "AdBrixItem.h"
#import "AdBrixCommerceProductModel.h"
#import "AdBrixCommerceProductCategoryModel.h"
#import "AdBrixCommerceProductAttrModel.h"


typedef NS_ENUM(NSInteger, AdBrixCustomCohortType)
{
    AdBrixCustomCohort_1 = 1,
    AdBrixCustomCohort_2 = 2,
    AdBrixCustomCohort_3 = 3
};

typedef NS_ENUM(NSInteger, AdBrixCurrencyType)
{
    AdBrixCurrencyKRW = 1,
    AdBrixCurrencyUSD = 2,
    AdBrixCurrencyJPY = 3,
    AdBrixCurrencyEUR = 4,
    AdBrixCurrencyGBP = 5,
    AdBrixCurrencyCNY = 6,
    AdBrixCurrencyTWD = 7,
    AdBrixCurrencyHKD = 8
};

typedef NS_ENUM(NSInteger, AdbrixPaymentMethod)
{
    AdBrixPaymentCreditCard         = 1,
    AdBrixPaymentBankTransfer       = 2,
    AdBrixPaymentMobilePayment      = 3,
    AdBrixPaymentETC                = 4
};

typedef NS_ENUM(NSInteger, AdBrixSharingChannel)
{
    AdBrixSharingFacebook       = 1,
    AdBrixSharingKakaoTalk      = 2,
    AdBrixSharingKakaoStory     = 3,
    AdBrixSharingLine           = 4,
    AdBrixSharingWhatsApp       = 5,
    AdBrixSharingQQ             = 6,
    AdBrixSharingWeChat         = 7,
    AdBrixSharingSMS            = 8,
    AdBrixSharingEmail          = 9,
    AdBrixSharingCopyUrl        = 10,
    AdBrixSharingETC            = 11
};




@interface AdBrix : NSObject

/*!
 @abstract
 singleton AdBrix 객체를 반환한다.
 */
+ (AdBrix *)shared;

/*!
 @abstract
 first time experience의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)firstTimeExperience:(NSString *)activityName;


/*!
 @abstract
 first time experience의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)firstTimeExperience:(NSString *)activityName param:(NSString *)param;

/*!
 @abstract
 retension의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)retention:(NSString *)activityName;

/*!
 @abstract
 retension의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)retention:(NSString *)activityName param:(NSString *)param;

/*!
 @abstract
 buy의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 */
+ (void)buy:(NSString *)activityName  __attribute__((deprecated("use -purchase: instead")));

/*!
 @abstract
 buy의 Activity에 해당할때 호출한다.
 
 @param activityName              activity name.
 @param param                     parameter.
 */
+ (void)buy:(NSString *)activityName param:(NSString *)param  __attribute__((deprecated("use -purchase: instead")));


+ (void)showViralCPINotice:(UIViewController *)viewController;

/*!
 @abstract
 cohort 분석시 호출한다.
 
 @param customCohortType          cohort type : AdBrixCustomCohortType
 @param filterName                filter Name
 */
+ (void)setCustomCohort:(AdBrixCustomCohortType)customCohortType filterName:(NSString *)filterName;


#pragma mark - Commerce

+ (void)purchase:(NSString*)orderId productId:(NSString*)productId productName:(NSString*)productName price:(double)price quantity:(NSUInteger)quantity currencyString:(NSString *)currencyString category:(NSString*)categories __attribute__((deprecated("use -commercePurchase: instead")));

+ (void)purchaseList:(NSArray*)orderInfo __attribute__((deprecated("use -commercePurchase: instead")));

+ (void)purchase:(NSString*)purchaseDataJsonString __attribute__((deprecated("use -commercePurchase api: instead")));

+ (NSString *)currencyName:(NSUInteger)currency;

+ (NSString *)paymentMethod:(NSUInteger)method;

+ (NSString *)sharingChannel:(NSUInteger)channel;

+ (AdBrixItem*)createItemModel :(NSString*)orderId productId:(NSString*)productId productName:(NSString*)productName price:(double)price quantity:(NSUInteger)quantity currencyString:(NSString *)currencyString category:(NSString*)categories __attribute__((deprecated("use -createCommerceProductModel with commercePurchase api: instead")));
    
+ (AdBrixItem*)PurchaseItemModel :(NSString*)orderId productId:(NSString*)productId productName:(NSString*)productName price:(double)price quantity:(NSUInteger)quantity currencyString:(NSString *)currencyString category:(NSString*)categories __attribute__((deprecated("use -createCommerceProductModel with commercePurchase api: instead")));

#pragma mark - CommerceV2

+ (AdBrixCommerceProductModel*)createCommerceProductModel :(NSString*)productId productName:(NSString*)productName price:(double)price discount:(double)discount quantity:(NSUInteger)quantity currencyString:(NSString *)currencyString category:(AdBrixCommerceProductCategoryModel*)categories extraAttrsMap:(AdBrixCommerceProductAttrModel *)extraAttrs;

+ (void)purchase:(NSString *)prodictId price:(double)price currency:(NSString*)currency paymentMethod:(NSString *)paymentMethod;

+ (void)purchase:(NSString *)orderId product:(AdBrixCommerceProductModel *)product paymentMethod:(NSString *)paymentMethod;

+ (void)purchase:(NSString *)orderId productsInfos:(NSArray *)productsInfos paymentMethod:(NSString *)paymentMethod;

+ (void)commercePurchase:(NSString *)prodictId price:(double)price currency:(NSString*)currency paymentMethod:(NSString *)paymentMethod;

+ (void)commercePurchase:(NSString *)orderId product:(AdBrixCommerceProductModel *)product discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSString *)paymentMethod;

+ (void)commercePurchase:(NSString *)orderId productsInfos:(NSArray *)productsInfos discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSString *)paymentMethod;

+ (void)commerceDeeplinkOpen : (NSString *)deeplinkUrl;

+ (void)commerceLogin : (NSString *)userId;

+ (void)commerceRefund:(NSString *)orderId product:(AdBrixCommerceProductModel *)product penaltyCharge:(double)penaltyCharge;

+ (void)commerceRefundBulk:(NSString *)orderId productsInfos:(NSArray *)productsInfos penaltyCharge:(double)penaltyCharge;

+ (void)commerceAddToCart:(AdBrixCommerceProductModel *)product;

+ (void)commerceAddToCartBulk:(NSArray *)productsInfos;

+ (void)commerceAddToWishList:(AdBrixCommerceProductModel *)product;

+ (void)commerceProductView:(AdBrixCommerceProductModel*)product;

+ (void)commerceCategoryView:(AdBrixCommerceProductCategoryModel*)category;

+ (void)commerceCategoryView:(AdBrixCommerceProductCategoryModel*)category productsInfos:(NSArray *)productsInfos;

+ (void)commerceReviewOrder:(NSString *)orderId product:(AdBrixCommerceProductModel *)product discount:(double)discount deliveryCharge:(double)deliveryCharge;

+ (void)commerceReviewOrderBulk:(NSString *)orderId productsInfos:(NSArray *)productsInfos discount:(double)discount deliveryCharge:(double)deliveryCharge;

+ (void)commercePaymentView:(NSString *)orderId productsInfos:(NSArray *)productsInfos discount:(double)discount deliveryCharge:(double)deliveryCharge;

+ (void)commerceSearch:(NSArray *)productsInfos keyword:(NSString *) keyword;

+ (void)commerceShare:(NSString*)channel product:(AdBrixCommerceProductModel *)product;

#pragma mark - Overloaded CommerceV2

+ (void)purchase:(NSString *)prodictId price:(double)price currency:(NSString*)currency paymentMethod:(NSString *)paymentMethod atrrData: (NSDictionary *)attrData;

+ (void)purchase:(NSString *)orderId product:(AdBrixCommerceProductModel *)product paymentMethod:(NSString *)paymentMethod atrrData: (NSDictionary *)attrData;

+ (void)purchase:(NSString *)orderId productsInfos:(NSArray *)productsInfos paymentMethod:(NSString *)paymentMethod atrrData: (NSDictionary *)attrData;

+ (void)commercePurchase:(NSString *)prodictId price:(double)price currency:(NSString*)currency paymentMethod:(NSString *)paymentMethod atrrData: (NSDictionary *)attrData;

+ (void)commercePurchase:(NSString *)orderId product:(AdBrixCommerceProductModel *)product discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSString *)paymentMethod atrrData: (NSDictionary *)attrData;

+ (void)commercePurchase:(NSString *)orderId productsInfos:(NSArray *)productsInfos discount:(double)discount deliveryCharge:(double)deliveryCharge paymentMethod:(NSString *)paymentMethod atrrData: (NSDictionary *)attrData;

+ (void)commerceDeeplinkOpen : (NSString *)deeplinkUrl atrrData: (NSDictionary *)attrData;

+ (void)commerceLogin : (NSString *)userId atrrData: (NSDictionary *)attrData;

+ (void)commerceRefund:(NSString *)orderId product:(AdBrixCommerceProductModel *)product penaltyCharge:(double)penaltyCharge atrrData: (NSDictionary *)attrData;

+ (void)commerceRefundBulk:(NSString *)orderId productsInfos:(NSArray *)productsInfos penaltyCharge:(double)penaltyCharge atrrData: (NSDictionary *)attrData;

+ (void)commerceAddToCart:(AdBrixCommerceProductModel *)product atrrData: (NSDictionary *)attrData;

+ (void)commerceAddToCartBulk:(NSArray *)productsInfos atrrData: (NSDictionary *)attrData;

+ (void)commerceAddToWishList:(AdBrixCommerceProductModel *)product atrrData: (NSDictionary *)attrData;

+ (void)commerceProductView:(AdBrixCommerceProductModel*)product atrrData: (NSDictionary *)attrData;

+ (void)commerceCategoryView:(AdBrixCommerceProductCategoryModel*)category atrrData: (NSDictionary *)attrData;

+ (void)commerceCategoryView:(AdBrixCommerceProductCategoryModel*)category productsInfos:(NSArray *)productsInfos atrrData: (NSDictionary *)attrData;

+ (void)commerceReviewOrder:(NSString *)orderId product:(AdBrixCommerceProductModel *)product discount:(double)discount deliveryCharge:(double)deliveryCharge atrrData: (NSDictionary *)attrData;

+ (void)commerceReviewOrderBulk:(NSString *)orderId productsInfos:(NSArray *)productsInfos discount:(double)discount deliveryCharge:(double)deliveryCharge atrrData: (NSDictionary *)attrData;

+ (void)commercePaymentView:(NSString *)orderId productsInfos:(NSArray *)productsInfos discount:(double)discount deliveryCharge:(double)deliveryCharge atrrData: (NSDictionary *)attrData;

+ (void)commerceSearch:(NSArray *)productsInfos keyword:(NSString *) keyword atrrData: (NSDictionary *)attrData;

+ (void)commerceShare:(NSString*)channel product:(AdBrixCommerceProductModel *)product atrrData: (NSDictionary *)attrData;
@end
