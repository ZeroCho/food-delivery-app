//
//  TMapPOIItem.h
//  skp
//
//  Created by developer on 12. 8. 17..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <CoreGraphics/CGColor.h>
#import "TMapPoint.h"
#import "TMapObject.h"
#import "TMapMarkerItem.h"

@interface TMapPOIItem : TMapMarkerItem
{
    NSString*   _address;
    NSString*   _content;
}

// POI ID입니다.
@property (nonatomic, copy)     NSString* poiID;

// 시설물 명칭입니다.
@property (nonatomic, copy)     NSString* poiName;
@property (nonatomic, copy)     NSString* name;

// 전화번호입니다.
@property (nonatomic, copy)     NSString* telNO;

// 시설물 입구 좌표입니다.
@property (nonatomic, assign)   CLLocationCoordinate2D frontCoordinate;

// 시설물 중심점 좌표입니다.
@property (nonatomic, assign)   CLLocationCoordinate2D noorCoordinate;

// 표출 주소 대분류명입니다.
@property (nonatomic, copy)     NSString* upperAddrName;

// 표출 주소 중분류명입니다.
@property (nonatomic, copy)     NSString* middleAddrName;

// 표출 주소 소분류명입니다.
@property (nonatomic, copy)     NSString* lowerAddrName;

// 표출 주소 세분류명입니다.
@property (nonatomic, copy)     NSString* detailAddrName;

// 본번입니다.
@property (nonatomic, copy)     NSString* firstNo;

// 부번입니다.
@property (nonatomic, copy)     NSString* secondNo;

// 도로명입니다.
@property (nonatomic, copy)     NSString* roadName;

// 건물번호1 입니다.
@property (nonatomic, copy)     NSString* buildingNo1;

// 건물번호2 입니다.
@property (nonatomic, copy)     NSString* buildingNo2;

// 주차 가능 유무 입니다. (0: 주차 불가능, 1: 주차 가능, null:정보 없음)
@property (nonatomic, copy)     NSString* parkFlag;

// 가맹점의 정보를 ';'을 구분자로 나열합니다.
// - OKCB: OKCashbag 가맹점
// - GIFT: 기프티콘
// - TMEM: T멤버쉽
// - OKMY: OK마이샵
@property (nonatomic, copy)     NSString* merchanFlag;

// 주소
@property (nonatomic, copy)     NSString* address;

// 상세정보
@property (nonatomic, copy)     NSString* content;

// 2015.04.03 추가
// 대표 업종명입니다
@property (nonatomic, copy)     NSString* bizName;

// 업종 대분류명입니다
@property (nonatomic, copy)     NSString* upperBizName;

// 업종 중분류명입니다
@property (nonatomic, copy)     NSString* middleBizName;

// 업종 소분류명입니다
@property (nonatomic, copy)     NSString* lowerBizName;

// 업종 상세분류명입니다
@property (nonatomic, copy)     NSString* detailBizName;

// POI 상세정보 유무입니다.
//해당 필드가 1로 설정되어 있으면, POI 상세정보 API를 이용하여 상세 정보를 조회할 수 있습니다.
//- 0: 없음
//- 1: 있음
//- null: 정보없음
//- 참고) 0: 없음, 1: 있음, null: 정보없음
@property (nonatomic, copy)     NSString* detailInfoFlag;

// 거리(요청좌표에서 떨어진 거리) 단위 :  km
@property (nonatomic, copy)     NSString* radius;

// RP_FLAG는 길안내 요청에 필요한 값입니다.
// - 길안내 목적지 설정 시, 여기서 받은 rpFlag 값을 설정해야 합니다.
@property (nonatomic, copy)     NSString* rpFlag;

- (id)initWithPOI:(NSDictionary*)poi;

- (void)setPOI:(NSDictionary*)poi;

/*
 *  getPOIID
 *
 *  @abstract
 *      poi 아이디를 얻어온다
 */
- (NSString*)getPOIID;

/*
 *  getPOIName
 *
 *  @abstract
 *      poi 이름을 얻어온다
 */
- (NSString*)getPOIName;

/*
 *  getPOIPoint
 *
 *  @abstract
 *      poi 좌표를 얻어온다
 */
- (TMapPoint*)getPOIPoint;

/*
 *  getPOIAddress
 *
 *  @abstract
 *      poi 주소를 얻어온다
 */
- (NSString*)getPOIAddress;

/*
 *  getPOIContent
 *
 *  @abstract
 *      poi 상세정보를 얻어온다
 */
- (NSString*)getPOIContent;

/*
 *  getDistance
 *
 *  @abstract
 *      poi와의 거리를 얻어온다.
 */
- (double)getDistance:(TMapPoint*)compareTmp;

@end
