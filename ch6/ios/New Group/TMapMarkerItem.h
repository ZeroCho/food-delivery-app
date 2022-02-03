//
//  TMapMarkerItem.h
//  skp
//
//  Created by developer on 12. 8. 5..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TMapPoint.h"
#import "TMapObject.h"

typedef enum {
    GONE,           // 화면에 보이지 않음
    HIDDEN,         // 영역을 차지하고 있으나 화면에 보이지않음
    VISIBLE          // 화면에 보임
} TMapMarkerItemType;

@interface TMapMarkerItem : TMapObject
{
    UIImage*    _image;
    NSString*   _markerTitle;
    BOOL         _visibleMode;
    CGPoint    _anchorPoint;
}

@property (nonatomic, retain) UIImage* image;

@property (nonatomic, copy) NSString* markerTitle;

@property (nonatomic, assign) BOOL visibleMode;

@property (nonatomic, assign) CGPoint anchorPoint;

@property (nonatomic, assign) BOOL canShowCallout;

@property (nonatomic, retain) UIImage* calloutLeftImage;

@property (nonatomic, retain) UIImage* calloutRightButtonImage;

@property (nonatomic, copy) NSString*   calloutTitle;

@property (nonatomic, copy) NSString*   calloutSubtitle;

@property (nonatomic, assign) BOOL enableClustering;

@property (nonatomic, assign) BOOL autoCalloutVisible;

@property (nonatomic, assign) BOOL lowZposition;
/*
 *  initWithTMapPoint:
 *
 *  @abstract
 *      마커 객체 생성
 */
- (id)initWithTMapPoint:(TMapPoint *)_point;

/*
 *  setTMapPoint:
 *
 *  @abstract
 *      마커의 좌표 설정
 */
- (void)setTMapPoint:(TMapPoint *)_point;

/*
 *  getTMapPoint:
 *
 *  @abstract
 *      마커의 좌표값 얻기
 */
- (TMapPoint*)getTMapPoint;

/*
 *  setName:
 *
 *  @abstract
 *      마커의 타이틀 설정
 */
- (void)setName:(NSString*)_name;

/*
 *  getName
 *
 *  @abstract
 *      마커의 타이틀 얻기
 */
- (NSString*)getName;

/*
 *  setVisible:
 *
 *  @abstract
 *      마커의 보이기 숨기기 설정
 */
- (void)setVisible:(BOOL)visible;

/*
 *  getVisible
 *
 *  @abstract
 *      마커의 보이기 숨기기 상태
 */
- (BOOL)getVisible;

/*
 *  setIcon:
 *
 *  @abstract
 *      마커의 아이콘이미지를 설정 (anchorpoint 0.5, 0.5)
 */
- (void)setIcon:(UIImage *)icon;

/*
 *  setIcon:anchorPoint:
 *
 *  @abstract
 *      마커의 아이콘이미지와 중심점(anchorPoint)를 설정
 *      anchorPoint {0.0, 0.0} 에서  {1.0, 1.0} 사이값 default:중점 {0.5, 0.5}
 */
- (void)setIcon:(UIImage *)icon anchorPoint:(CGPoint)anchorPoint;

/*
 *  getIcon
 *
 *  @abstract
 *      마커의 아이콘 이미지 얻어오기
 */
- (UIImage*)getIcon;

/*
 *  getID
 *
 *  @abstract
 *      마커의 ID를 얻어오기
 */
- (NSString*)getID;

#pragma mark - Callout 관련 메소드들
/*
 *  setCanShowCallout:
 *
 *  @abstract
 *      Callout 사용여부 설정
 */
- (void)setCanShowCallout:(BOOL)show;

/*
 *  setCalloutLeftImage:
 *
 *  @abstract
 *      Callout 좌측 이미지 설정
 */
- (void)setCalloutLeftImage:(UIImage*)image;

/*
 *  setCalloutLeftImage:
 *
 *  @abstract
 *      Callout 좌측 이미지 설정
 */
- (void)setCalloutRightButtonImage:(UIImage*)image; // Callout 오른쪽 버튼 이미지 default: NO

/*
 *  setCalloutTitle:
 *
 *  @abstract
 *      Callout 타이틀 설정
 */
- (void)setCalloutTitle:(NSString*)title;

/*
 *  setCalloutSubtitle:
 *
 *  @abstract
 *      Callout 서브타이틀 설정
 */
- (void)setCalloutSubtitle:(NSString*)subtitle;     // Callout 서브 타이틀

/*
 *  setAutoCalloutVisible:
 *
 *  @abstract
 *      마커 생성시 Callout(풍선뷰) 보이기 설정
 */
- (void)setAutoCalloutVisible:(BOOL)visible;

#pragma mark - Clustering
/*
 *  setEnableClustering:
 *
 *  @abstract
 *       마커 클러스터링 사용여부 설정
 */
- (void)setEnableClustering:(BOOL)enable;

/*
 *  @abstract
 *      마커의 zPosition의 낮게 하여 겹쳐 있을때 일반 마커들보다 아래로 위치하게 한다.
 *  @param lowZposition      zPositon 낮겨 할지 여부
 */
- (void)setLowZposition:(BOOL)lowZposition;

@end
 