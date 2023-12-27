//
//  TMapGpsManager.h
//  skp
//
//  Created by developer on 12. 8. 19..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "TMapPoint.h"

@protocol TMapGpsManagerDelegate <NSObject>
- (void)locationChanged:(TMapPoint*)newTmp;
- (void)headingChanged:(double)heading;
@end

@interface TMapGpsManager : NSObject <CLLocationManagerDelegate>
{
    id<TMapGpsManagerDelegate> delegate;
    CLLocationManager *locMgr;
    
    TMapPoint* curTMP;
}

@property (nonatomic, assign) id<TMapGpsManagerDelegate> delegate;


// 백그라운드에서도 위치정보 얻어오도록 설정 (iOS8 이상에서 사용가능)
@property (nonatomic, assign) BOOL alwaysAuthorization;

/*
 *  openGps
 *
 *  @abstract
 *      GPS 동작을 시작
 */
- (void)openGps;

/*
 *  closeGps
 *
 *  @abstract
 *      GPS 동작을 종료
 */
- (void)closeGps;

/*
 *  setMinTime:
 *
 *  @abstract
 *      사용안함 (안드로이드전용)
 */
- (void)setMinTime:(int)mintime;

/*
 *  getMinTime:
 *
 *  @abstract
 *      사용안함 (안드로이드전용)
 */
- (int)getMinTime;

/*
 *  setMinDistance:
 *
 *  @abstract
 *      얼마나 위치 이동이 일어났을때 이벤트를 발생시킬지 설정
 */
- (void)setMinDistance:(int)mindistance;

/*
 *  getMinDistance
 *
 *  @abstract
 *      setMinDistance: 에서 설정한 값을 얻기
 */
- (int)getMinDistance;

/*
 *  getLocation
 *
 *  @abstract
 *      현재위치 좌표를 얻기
 */
- (TMapPoint*)getLocation;

/*
 *  getSatellite
 *
 *  @abstract
 *      사용안함 (안드로이드전용)
 */
- (int)getSatellite;

/*
 *  setProviderType:
 *
 *  @abstract
 *      사용안함 (안드로이드전용)
 */
- (void) setProviderType:(NSString *)type;

/*
 *  getProvider
 *
 *  @abstract
 *      사용안함 (안드로이드전용)
 */
- (NSString *)getProvider;

/*
 *  startHeading
 *
 *  @abstract
 *      Heading Mode 시작
 */
- (void)startHeading;

/*
 *  stopHeading
 *
 *  @abstract
 *      Heading Mode 종료
 */
- (void)stopHeading;

/*
 *  getAccuracy
 *
 *  @abstract
 *      Returns the horizontal accuracy of the location. Negative if the lateral location is invalid.
 */
+ (double)getAccuracy;

/*
 *  setAlwaysAuthorization
 *
 *  @abstract
 *      iOS 8이상에서 백그라운드에서도 위치정보 수집가능여부 설정
 */
- (void)setAlwaysAuthorization:(BOOL)alwaysAuthorization;


@end
