//
//  TMapPathData.h
//  skp
//
//  Created by developer on 12. 8. 19..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import "TMapPoint.h"
#import "TMapPolyLine.h"
#import "TMapPOIItem.h"

typedef enum {
    CAR_PATH,			// 자동차도로
    PEDESTRIAN_PATH,	// 보행자도로
//    BICYCLE_PATH,		// 저전거도로
} TMapPathType;

@protocol TMapPathDelegate <NSObject>

/**
 *
 *      TMapPathData 관련 함수 호출시 ApiName, Http StatusCode, request URL 값을 받을수 있습니다.
 *
 */
@optional
- (void)onResponseCodeCallbackWithApiName:(NSString*)apiName resCode:(int)resCode URL:(NSString*)url;
@end

@interface TMapPathData : NSObject

@property (nonatomic, readonly) NSString* errorMessage;

@property (nonatomic, assign) id <TMapPathDelegate> delegate;


#pragma mark - POI 검색
// https://developers.skplanetx.com/apidoc/kor/t-map/poi/

/**
 *  @abstract
 *      업종 코드를 검색합니다.
 *  @return
 *      BizCategory의 배열.
 *
 */
- (NSArray *)getBizCategory;

/**
 *  @abstract
 *      POI 통합 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *  @param keyword      검색 키워드입니다.
 *
 */
- (NSArray*)requestFindAllPOI:(NSString *)keyword;

/**
 *  @abstract
 *      POI 통합 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *  @param keyword      검색 키워드입니다.
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~99 )
 *
 */
- (NSArray*)requestFindAllPOI:(NSString *)keyword resultCount:(NSInteger)resultCount;

/**
 *  @abstract
 *      POI 명칭 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *
 */
- (NSArray*)requestFindTitlePOI:(NSString*)keyword;

/**
 *  @abstract
 *      POI 명칭 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~99 )
 *
 */
- (NSArray*)requestFindTitlePOI:(NSString*)keyword resultCount:(NSInteger)resultCount;

/**
 *  @abstract
 *      POI 주소 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *
 */
- (NSArray*)requestFindAddressPOI:(NSString*)keyword;

/**
 *  @abstract
 *      POI 주소 검색
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param keyword      검색 키워드입니다.
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~99 )
 *
 */
- (NSArray*)requestFindAddressPOI:(NSString *)keyword resultCount:(NSInteger)resultCount;

/**
 *  @abstract
 *      카테고리 주변 POI 검색
 *
 *  @discussion
 *      반경을 기준으로 한 카테고리 갬색 주변 POI 검색을 제공합니다.
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param point        반경검색에 사용되는 중심 좌표.
 *  @param categoryName 조회할 업종명칭을 ‘;’ 구분자로 최대 5개까지 입력 가능합니다. - getBizCategory API에서 검색된 middleBizName값.
 *                      단일 업종조회(eg. 주유소) 여러개의 업종조회(eg. 편의점;한식;한의원)
 *  @param radius       반경정보. 1~33의 값을 입력하시면 됩니다. (1=300m 입니다.) 1: 300m, 2: 600m, 3: 900m, 4: 1200m.... 33: 9900m
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~200 )
 *
 */
- (NSArray*)requestFindNameAroundPOI:(TMapPoint*)point categoryName:(NSString *)categoryName radius:(NSInteger)radius resultCount:(NSInteger)resultCount;

/**
 *  @abstract
 *      주변 검색 API - deprecated (사용안함)
 *
 *  @discussion
 *      (2013.06.17 후로 BizCode에 대해서 파라미터로 검색하는 기능을 제공하지 않음) - requestFindNameAroundPOI:로 사용하시기 바랍니다.
 *  @return
 *      nil
 */
- (NSArray*)requestFindGeoPOI:(TMapPoint*)point LCode:(NSString*)classLCode MCode:(NSString*)classMCode;

/**
 *  @abstract
 *      키워드 주변 검색 API
 *
 *  @discussion
 *      반경을 기준으로 한 키워드 검색 주변 POI를 제공합니다.
 *
 *  @return TMapPOIItem의 배열 입니다.
 *
 *  @param point        반경검색에 사용되는 중심 좌표.
 *  @param keywordName  검색 키워드입니다.
 *  @param radius       반경정보. 0~33의 값을 입력하시면 됩니다. (1=300m 입니다.) 1: 300m, 2: 600m, 3: 900m, 4: 1200m.... 33: 9900m
 *                      “0”: 검색반경을 서버에 위임
 *  @param resultCount  출력되는 개수를 지정합니다.( 유효값: 1~200 )
 */
- (NSArray*)requestFindAroundKeywordPOI:(TMapPoint*)point keywordName:(NSString *)keywordName radius:(NSInteger)radius resultCount:(NSInteger)resultCount;

/**
 *  @abstract
 *      주변 대표 POI검색 (only for TNAVI) TNAVI에서만 제공됩니다.
 *
 *  @discussion
 *      반경을 기준으로 한 주변 대표POI를 제공합니다.
 *
 *  @return TMapPOIIte
 *
 *  @param point        반경검색에 사용되는 중심 좌표.
 *  @param radius       반경정보. 단위 km 예) 0.44 -> 0.44km = 440m
 */
//- (TMapPOIItem*)requestFindNearestPOI:(TMapPoint*)point radius:(CGFloat)radius;

# pragma mark - reverseGeoCoding
/**
 * @abstract
 *      Reverse Geocoding
 *
 * @discussion
 *      좌표를 통해 주소정보를 얻습니다.
 *
 * @return 주소정보 (fullAddress)
 * @param tmp 좌표정보
 *
 */
- (NSString*)convertGpsToAddressAt:(TMapPoint*)tmp;

/**
 * @abstract
 *      Reverse Geocoding
 *
 * @discussion
 *      좌표를 통해 주소정보를 얻습니다.
 *
 * @return 주소정보
 * @param tmp 좌표정보
 *
 */
- (NSDictionary*)convertGpsToAddressInfo:(TMapPoint*)tmp;

/**
 * @abstract
 *      Reverse Geocoding
 *
 * @discussion
 *      좌표를 통해 주소정보를 얻습니다.
 *
 * @return 주소정보
 *
 * @param mapPoint 좌표정보
 * @param addressType 주소 타입 (도로명주소: A03, A04)
 *                      A00: 선택한 좌표계에 해당하는 행정동,법정동 주소 입니다.
 *                      A01: 선택한 좌표게에 해당하는 행정동 입니다.     예) 망원2동, 일산1동
 *                      A02: 선택한 좌표계에 해당하는 법정동 주소입니다.  예) 방화동, 목동
 *                      A03: 선택한 좌표계에 해당하는 새주소 길입니다.
 *                      A04: 선택한 좌표계에 해당하는 새주소 건물번호입니다.    예) 양천로 14길 95-11
 *
 */
- (NSDictionary*)reverseGeocoding:(TMapPoint*)mapPoint addressType:(NSString*)type;

/**
 * 주소정보를 통해 위경도값을 얻습니다.
 *
 * @return 주소정보 (위경도값포함한 정보)
 *              - addressFlag   : 주소 타입
 *              - adminDong     : 행정동 명칭
 *              - bunji         : 지번
 *              - city_do       : 시/도 명칭
 *              - coordType     : 좌표 타입
 *              - gu_gun        : 구/군 명칭
 *              - lat           : 구주소 요청시 위도
 *              - lon           : 구주소 요청시 경도
 *              - legalDong     : 법정 동명칭
 *              - matchFlag     : 구주소 매칭 구분코드
 *              - newBuildingCateName   : 우, 건물군 이름
 *              - newBuildingIndex      : 건물 번호
 *              - newBuildingName       : 건물 명칭
 *              - newLat        : 도로명주소 요청시 위도
 *              - newLon        : 도로명주소 요청시 경도
 *              - newRoadName   : 도로명
 *              - newMatchFlag  : 도로명주소 매칭 구분코드
 *
 * @param addressType(필수)      주소 타입 (F01, F02)
 *                                  F01: 지번주소, 구주소타입
 *                                  F02: 도로명주소, 새주소타입
 *                                  F00: 구분없음
 * @param city_do(필수)          시/도 명칭입니다.
 * @param gu_gun(필수)           군/구 명칭입니다.
 * @param dong_roadName(필수)    F01(구주소)의 경우 동명칭입니다.
 *                              F02(도로명주소)의 경우 도로명명칭입니다.
 * @param bunji_buildingNO      F01(구주소)의 경우 지번입니다. 형식: 본번-부번, 산
 *                              F02(도로명주소)의 경우 건물번호입니다.
 * @param detailAddress         상세주소입니다.
 *
 */
- (NSDictionary*)geoCodingWithAddressType:(NSString*)addressType
                                  city_do:(NSString*)city_do
                                   gu_gun:(NSString*)gu_gun
                            dong_roadName:(NSString*)dong_roadName
                         bunji_buildingNO:(NSString*)bunji_buildingNO
                            detailAddress:(NSString*)detailAddress;


#pragma mark - 경로탐색
/**
 * 출발, 목적지 좌표를 통해 자동차경로탐색을 요청 polyline로 반환
 *
 * @return 경로 PolyLine
 */
- (TMapPolyLine *)findPathDataFrom:(TMapPoint*)startPoint to:(TMapPoint*)endPoint;

/**
 * 출발, 목적지 좌표와 Type(자동차경로, 보행자경로, 자전거경로)을 설정하여 탐색을 요청 polyline로 반환
 *
 * @return 경로 PolyLine
 */
- (TMapPolyLine *)findPathDataWithType:(TMapPathType)type startPoint:(TMapPoint*)startPoint endPoint:(TMapPoint*)endPoint;

/**
 * 출발, 목적지 좌표를 통해 자동차경로탐색을 요청 경로 및 음성정보를 NSDictionary로 반환
 *
 * @return 경로 및 음성정보 NSDictionary
 */
- (NSDictionary*)findPathDataAllWithStartPoint:(TMapPoint*)startPoint endPoint:(TMapPoint*)endPoint;

/**
 * 출발, 목적지 좌표와 Type(자동차경로, 보행자경로, 자전거경로)을 설정하여 탐색을 요청 경로 및 음성정보를 NSDictionary로 반환
 *
 * @return 경로 및 음성정보를 NSDictionary
 */
- (NSDictionary*)findPathDataAllWithType:(TMapPathType)type startPoint:(TMapPoint*)startPoint endPoint:(TMapPoint*)endPoint;

/**
 * 출발지, 목적지, 경유지 좌표와 Type(자동차경로, 보행자경로, 자전거경로)을 설정하여 탐색을 요청 polyline로 반환
 *
 * @return 경로 PolyLine
 */
- (TMapPolyLine*)findPathDataWithType:(TMapPathType)type
                           startPoint:(TMapPoint*)startPoint
                             endPoint:(TMapPoint*)endPoint
                           passPoints:(NSArray*)passPoints
                         searchOption:(NSInteger)searchOption;

/**
 * 출발지, 목적지, 경유지 좌표를 설정하여 탐색을 요청 polyline로 반환 (경유지 최대 30개)
 *
 * @return 경로 PolyLine
 */
- (TMapPolyLine*)findMultiPathDataWithStartPoint:(TMapPoint*)startPoint
                                        endPoint:(TMapPoint*)endPoint
                                      passPoints:(NSArray*)passPoints
                                    searchOption:(NSInteger)searchOption;



/**
 * @abstract
 *      타임머신 자동차 길 안내
 *
 * @discussion
 *      출발 혹은 도착시간을 예측한 자동차 길 안내정보를 제공합니다.
 *
 */
- (NSDictionary*)findTimeMachineCarPathWithStartPoint:(TMapPoint*)startPoint        // 출발지
                                             endPoint:(TMapPoint*)endPoint          // 도착지
                                          isStartTime:(BOOL)isStartTime             // 어떤시간을 기준 (YES: 출발시간기준, NO:도착시간 기준)
                                                 time:(NSDate*)date                 // 출발 혹은 도착시간
                                            wayPoints:(NSArray*)wayPoints;          // 경유지 (TMapPoint 배열, nil: 경유지 없음)

/**
 * @abstract
 *      타임머신 자동차 길 안내
 *
 * @discussion
 *      출발 혹은 도착시간을 예측한 자동차 길 안내정보를 제공합니다.
 *
 */

// searchOption
//-	00 : 교통최적+추천
//-	01 : 교통최적+무료우선
//-	02 : 교통최적+최소시간
//-	03 : 교통최적+초보
//-	04 : 교통최적+고속도로우선
//-	10 : 최단거리+유/무료

- (NSDictionary*)findTimeMachineCarPathWithStartPoint:(TMapPoint*)startPoint        // 출발지
                                             endPoint:(TMapPoint*)endPoint          // 도착지
                                          isStartTime:(BOOL)isStartTime             // 어떤시간을 기준 (YES: 출발시간기준, NO:도착시간 기준)
                                                 time:(NSDate*)date                 // 출발 혹은 도착시간
                                            wayPoints:(NSArray*)wayPoints           // 경유지 (TMapPoint 배열, nil: 경유지 없음)
                                         searchOption:(NSString*)searchOption;      // 경로탐색 시 우선순위를 정하는 옵션

/**
 * @abstract
 *      poi 자동완성
 * @discussion
 *      poi 검색 자동완성 문자열을 제공합니다.
 * @return 
 *      입력된 text의 자동완성 문자열 배열
 */
- (NSArray*)autoCompleteWithText:(NSString*)text;

#pragma mark - 유효성검사
/**
 *  @abstract
 *      ApiKey 유효성 검사
 *
 *  @return         HTTP StatusCode. - 성공:200 (그외 에러 아래 참고)
 *
 *  @discussion
 *      statusCode  ErrorCode   Messages
 *      401         1004        발급되지 않은 BizAppId입니다.
 *      500         1005        시스템 오류입니다.
 *      403         2000        사용할 수 없는 라이브러리 입니다.
 *      400         1100        요청 데이터 오류입니다.
 */
- (NSInteger)validateApiKey:(NSString*)appID;

- (NSInteger)validateApiKey:(NSString*)appID error:(NSError **)error;

    
@end
