//
//  AdBrixCommerceProductModel.h
//  AdBrixLib
//
//  Created by igaworks on 2017. 1. 13..
//  Copyright © 2017년 hoiil,jung. All rights reserved.
//

#ifndef AdBrixCommerceProductCategoryModel_h
#define AdBrixCommerceProductCategoryModel_h


#import <Foundation/Foundation.h>

@interface AdBrixCommerceProductCategoryModel : NSObject

+ (AdBrixCommerceProductCategoryModel*)create :(NSString *)category1;

+ (AdBrixCommerceProductCategoryModel*)create :(NSString *)category1 category2:(NSString *)category2;

+ (AdBrixCommerceProductCategoryModel*)create :(NSString *)category1 category2:(NSString *)category2 category3:(NSString *)category3;

+ (AdBrixCommerceProductCategoryModel*)create :(NSString *)category1 category2:(NSString *)category2 category3:(NSString *)category3 category4:(NSString *)category4;

+ (AdBrixCommerceProductCategoryModel*)create :(NSString *)category1 category2:(NSString *)category2 category3:(NSString *)category3 category4:(NSString *)category4 category5:(NSString *)category5;

-(void)setCategoryFullString:(NSArray *) _categories;

- (NSString *)getFullString;

@end

#endif /* AdBrixCommerceProductCategoryModel_h */
