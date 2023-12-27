//
//  TMapTapi.h
//  SKP-Sample
//
//  Created by heungguk on 13. 5. 9..
//  Copyright (c) 2013년 LBC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol TMapTapiDelegate <NSObject>
@optional

/*
 *  SKTMapApikeySucceed
 *
 *  @abstract
 *      setSKTMapApiKey: 성공시 발생하는 callback
 */
- (void)SKTMapApikeySucceed;

/*
 *  SKTMapApikeyFailed:
 *
 *  @abstract
 *      setSKTMapApiKey: 실패시 발생하는 callback
 */
- (void)SKTMapApikeyFailed:(NSError*)error;

@end

@interface TMapTapi : NSObject

/** TMap 연동 API 사용인증 (apikey)
 * @param delegate 성공여부 콜백 Delegate
 * @param apiKey apiKey
 */
+ (void)setSKTMapAuthenticationWithDelegate:(id<TMapTapiDelegate>)delegate apiKey:(NSString*)apiKey;

/** 길안내
 * @return 성공여부
 * @param destName 목적지명
 * @param coordinate 목적지의 좌표
 */
+ (BOOL)invokeRoute:(NSString*)destName coordinate:(CLLocationCoordinate2D)coordinate;

/** 상세 길안내
 * @return 성공여부
 * @param routeInfo 목적지 상세정보 (아래 예제 참고)
 */
+ (BOOL)invokeRoute:(NSDictionary*)routeInfo;

/** 특정위치 보기
 * @return 성공여부
 * @param destName 특정위치명
 * @param coordinate 특정위치 좌표
 */
+ (BOOL)invokeSetLocation:(NSString*)destName coordinate:(CLLocationCoordinate2D)coordinate;

/** 통합검색
 * @return 성공여부
 * @param destName 검색할 명칭
 */
+ (BOOL)invokeSearchPortal:(NSString*)destName;

/** 집으로
 * @return 성공여부
 */
+ (BOOL)invokeGoHome;

/** 회사로
 * @return 성공여부
 */
+ (BOOL)invokeGoCompany;

/** TMap 앱 설치여부
 * @return 설치여부
 */
+ (BOOL)isTmapApplicationInstalled;

/** TMap 앱스토어 URL
 * @return TMap 앱스토어 URL
 */
+ (NSString*)getTMapDownUrl;

@end



/*
 1. 필수
 rGoName	목적지 명칭
 rGoX       목적지 x 좌표 (경도)
 rGoY       목적지 y 좌표 (위도)
 
 2. 옵션
 rStName	출발지 명칭
 rStX       출발지 x 좌표 (경도)
 rStY       출발지 y 좌표 (위도)
 rV1Name	경유지1 명칭
 rV1X       경유지1 x 좌표 (경도)
 rV1Y       경유지1 y 좌표 (위도)
 rV2Name	경유지2명칭
 rV2X       경유지2 x 좌표 (경도)
 rV2Y       경유지2 y 좌표 (위도)
 
 ex) NSDictionary* routeInfo = [NSDictionary dictionaryWithObjectsAndKeys:
 @"강남역",@"rGoName",                              // 목적지명칭(필수)
 [NSNumber numberWithDouble:127.027621],@"rGoX",  // 목적지경도(필수)
 [NSNumber numberWithDouble:37.497942],@"rGoY",   // 목적지위도(필수)
 @"서울역",@"rStName",                              // 출발지명칭
 [NSNumber numberWithDouble:126.972646],@"rStX",  // 출발지경도
 [NSNumber numberWithDouble:37.553017],@"rStY",   // 출발지위도
 @"용산역",@"rV1Name",                              // 경유지1명칭
 [NSNumber numberWithDouble:126.964775],@"rV1X",  // 경유지1 경도
 [NSNumber numberWithDouble:37.52989],@"rV1Y",    // 경유지1 위도
 @"사당역",@"rV2Name",                              // 경유지2명칭
 [NSNumber numberWithDouble:126.981633],@"rV2X",  // 경유지2경도
 [NSNumber numberWithDouble:37.476559],@"rV2Y",nil]; // 경유지2위도
 */
