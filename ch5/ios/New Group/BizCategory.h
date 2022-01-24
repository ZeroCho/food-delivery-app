//
//  BizCategory.h
//  skp
//
//  Created by developer on 12. 8. 28..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

@interface BizCategory : NSObject

// 업종 대분류 코드 (ex. 01)
@property (nonatomic, copy) NSString *upperBizCode;

// 업종 대분류 명칭 (ex. 식음료)
@property (nonatomic, copy) NSString *upperBizName;

// 업종 중분류 코드 (ex. 01)
@property (nonatomic, copy) NSString *middleBizCode;

// 업종 중분류 명칭 (ex. TV맛집)
@property (nonatomic, copy) NSString *middleBizName;

- (NSString *)toString;

@end