//
//  TMapCircle.h
//  SKP-Sample
//
//  Created by developer on 12. 9. 25..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import "TMapPoint.h"
#import "TMapObject.h"

@interface TMapCircle : TMapObject
{
    UIColor*    _lineColor;
    UIColor*    _fillColor;
    CGFloat     _lineWidth;
    
    CGFloat _radius;
    BOOL    _radiusHidden;
}

@property (nonatomic, retain) UIColor* lineColor;

@property (nonatomic, retain) UIColor* fillColor;

@property (nonatomic, assign) CGFloat lineWidth;

@property (nonatomic, assign) CGFloat radius;

@property (nonatomic, readonly) BOOL radiusHidden;

#pragma mark - API methods

/*
 *  @abstract
 *      TMapCircle 객체를 생성
 */
- (id)initWithTMapPoint:(TMapPoint*)mapPoint;

/*
 *  @abstract
 *      TMapCircle 객체를 생성
 */
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

/*
 *  @abstract
 *      Circle의 중심 좌표를 설정
 */
- (void)setCenterPoint:(TMapPoint *)_point;

/*
 *  @abstract
 *      Circle의 중심 좌표를 얻기
 */
- (TMapPoint *)getCenterPoint;

/*
 *  @abstract
 *      Circle의 반지름 설정
 */
- (void)setCircleRadius:(int)_radius;

/*
 *  @abstract
 *      Circle의 반지름 얻기
 */
- (int)getCircleRadius;

/*
 *  @abstract
 *      Circle의 FillColor설정
 */
- (void)setCircleAreaColor:(CGColorRef)_color;

/*
 *  @abstract
 *      Circle의 FillColor얻기
 */
- (CGColorRef)getCircleAreaColor;

/*
 *  @abstract
 *      Circle의 외각 라인두깨 설정
 */
- (void)setCircleLineWidth:(float)_width;

/*
 *  @abstract
 *      Circle의 외각 라인두깨 얻기
 */
- (float)getCircleLineWidth;

/*
 *  @abstract
 *      Circle의 외각라인색상 설정
 */
- (void)setCircleLineColor:(CGColorRef)_color;

/*
 *  @abstract
 *      Circle의 외각라인색상 얻기
 */
- (CGColorRef)getCircleLineColor;

/*
 *  @abstract
 *      Circle의 FillColor 알파값 설정
 */
- (void)setCircleAreaAlpha:(int)alpha;

/*
 *  @abstract
 *      Circle의 FillColor 알파값 얻기
 */
- (int)getCircleAreaAlpha;

/*
 *  @abstract
 *      Circle의 외각라인색상 알파값 설정
 */
- (void)setCircleLineAlpha:(int)alpha;

/*
 *  @abstract
 *      Circle의 외각라인색상 알파값 얻기
 */
- (int)getCircleLineAlpha;

/*
 *  @abstract
 *      Circle의 외각라인 보이기 설정
 */
- (void)setRadiusVisible:(bool)flag;

@end
