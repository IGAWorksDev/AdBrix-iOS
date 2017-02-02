//
//  AdBrixCommerceProductModel.h
//  AdBrixLib
//
//  Created by igaworks on 2017. 1. 13..
//  Copyright © 2017년 hoiil,jung. All rights reserved.
//

#ifndef AdBrixCommerceProductAttrModel_h
#define AdBrixCommerceProductAttrModel_h


#import <Foundation/Foundation.h>

@interface AdBrixCommerceProductAttrModel : NSObject

+ (AdBrixCommerceProductAttrModel*)create :(NSDictionary *)attrData;

- (void)setKeyAndVal :(int)pIndex key:(NSString *)key value:(NSString *)value;

- (NSString *)getKey :(int)pIndex;

- (NSString *)getValue :(int)pIndex;

@end

#endif /* AdBrixCommerceProductAttrModel_h */
