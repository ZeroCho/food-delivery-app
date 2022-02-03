//
//  TMapMarkerItem2.h
//  SKP-Sample
//
//  Created by heungguk on 13. 8. 1..
//  Copyright (c) 2013년 LBC. All rights reserved.
//

#import "TMapObject.h"
#import "TMapPoint.h"

/*
 *  마커 이미지 애니매이션기능과 Custom 풍선뷰를 지원하기 위해 만든 Class
 */

@interface TMapMarkerItem2 : TMapObject
{
    UIImage*    _image;
    NSString*   _markerTitle;
    BOOL         _visibleMode;
    CGPoint    _anchorPoint;
}

@property (nonatomic, retain) UIImage* image;

@property (nonatomic, retain) NSArray* aniImages;

@property (nonatomic, copy) NSString* markerTitle;

@property (nonatomic, assign) BOOL visibleMode;

@property (nonatomic, assign) CGPoint anchorPoint;

@property (nonatomic, assign) BOOL canShowCallout;

@property (nonatomic, assign) BOOL autoCalloutVisible;

@property (nonatomic, assign) double aniDuration;

@property (nonatomic, assign) BOOL lowZposition;

/*
 *  @abstract
 *      마커 객체 생성
 */
- (id)initWithTMapPoint:(TMapPoint *)_point;

/*
 *  @abstract
 *      마커 좌표설정
 */
- (void)setTMapPoint:(TMapPoint *)_point;

/*
 *  @abstract
 *      마커 좌표얻기
 */
- (TMapPoint*)getTMapPoint;

/*
 *  @abstract
 *      마커 타이틀설정
 */
- (void)setName:(NSString*)_name;

/*
 *  @abstract
 *      마커 타이틀얻기
 */
- (NSString*)getName;

/*
 *  @abstract
 *      마커의 보이기 숨기기 설정
 */
- (void)setVisible:(BOOL)visible;

/*
 *  @abstract
 *      마커의 보이기 숨기기 얻기
 */
- (BOOL)getVisible;

/*
 *  setIcon:
 *
 *  @abstract
 *      마커의 아이콘이미지를 설정 (anchorpoint 0.5, 0.5)
 */
- (void)setIcon:(UIImage *)icon;    // anchorPoint (0.5, 0.5)

/*
 *  setIcon:anchorPoint:
 *
 *  @abstract
 *      마커의 아이콘이미지와 중심점(anchorPoint)를 설정
 *
 *  @param anchorPoint      {0.0, 0.0} 에서  {1.0, 1.0} 사이값 default:중점 {0.5, 0.5}
 */
- (void)setIcon:(UIImage *)icon anchorPoint:(CGPoint)anchorPoint;

/*
 *  @abstract
 *      마커애니메이션 아이콘이미지들과 중심점(anchorPoint)를 설정
 *  @param icons            아이콘 애니매이션을 위한 이미지배열
 *  @param anchorPoint      {0.0, 0.0} 에서  {1.0, 1.0} 사이값 default:중점 {0.5, 0.5}
 */
- (void)setAnimationIcons:(NSArray*)icons anchorPoint:(CGPoint)anchorPoint;

/*
 *  @abstract
 *      애니메이션 속도 설정
 *  @param aniDuration      애니메이션 duration
 */
- (void)setAniDuration:(double)aniDuration;

/*
 *  @abstract
 *      마커의 zPosition의 낮게 하여 겹쳐 있을때 일반 마커들보다 아래로 위치하게 한다.
 *  @param lowZposition      zPositon 낮겨 할지 여부
 */
- (void)setLowZposition:(BOOL)lowZposition;

/*
 *  @abstract
 *      마커 애니메이션 시작
 */
- (void)startAnimation;

/*
 *  @abstract
 *      마커 애니메이션 중지
 */
- (void)stopAnimation;


- (UIImage*)getIcon;

//
- (NSString*)getID;

// CallOutView
- (void)setCanShowCallout:(BOOL)show;               // Callout 사용여부 default: NO
- (void)setAutoCalloutVisible:(BOOL)visible;		// 마커 추가시 풍선뷰 보기 (default: NO)

@end
