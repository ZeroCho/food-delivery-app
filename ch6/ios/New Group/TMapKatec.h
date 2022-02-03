//
//  TMapKatec.h
//  skp
//
//  Created by developer on 12. 8. 26..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TMapKatec : NSObject

/*
 *  getKatecWithLat:Lon:
 *
 *  Discussion:
 *      WGS84 좌표를 Katec좌표로 변환한 값을 얻어온다
 */
+ (CGPoint)getKatecWithLat:(double)lat Lon:(double)lon;

@end
