//
//  TMapPolyLine.h
//  skp
//
//  Created by developer on 12. 8. 5..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <CoreGraphics/CGColor.h>
#import "TMapPoint.h"
#import "TMapObject.h"

@interface TMapPolyLine : TMapObject 
{
    UIColor*    _lineColor;
    UIColor*    _outLineColor;
    CGFloat     _lineWidth;
    CGFloat     _outLineWidth;
    
    NSMutableArray*     _points;
}

@property (nonatomic, retain) UIColor*  lineColor_;

@property (nonatomic, retain) UIColor*  outLineColor_;

@property (nonatomic, assign) CGFloat   lineWidth_;

@property (nonatomic, assign) CGFloat   outLineWidth_;

@property (nonatomic, readonly) NSMutableArray* points;

@property (nonatomic, assign) CLLocationCoordinate2D startCoordinate;

@property (nonatomic, assign) CLLocationCoordinate2D endCoordinate;

@property (nonatomic, retain) NSArray* passCoordinates;

/*
 *  @abstract
 *      라인색상설정
 */
- (void)setLineColor:(CGColorRef)_color;

/*
 *  @abstract
 *      라인색상얻기
 */
- (CGColorRef)getLineColor;

/*
 *  @abstract
 *      외곽선 라인색상설정
 */
- (void)setOutLineColor:(CGColorRef)_color;

/*
 *  @abstract
 *      외곽선 라인색상설정
 */
- (CGColorRef)getOutLineColor;

/*
 *  @abstract
 *      라인 굵기 설정
 */
- (void)setLineWidth:(float)_width;

/*
 *  @abstract
 *      라인 굵기 얻기
 */
- (float)getLineWidth;

/*
 *  @abstract
 *      외곽라인 굵기 설정
 */
- (void)setOutLineWidth:(float)_width;

/*
 *  @abstract
 *      외곽라인 굵기 얻기
 */
- (float)getOutLineWidth;

/*
 *  @abstract
 *      Line Point 추가
 */
- (void)addLinePoint:(TMapPoint *)point;

/*
 *  @abstract
 *      Line Point들 얻기
 */
- (NSArray *)getLinePoint;

/*
 *  @abstract
 *      Line의 거리 얻기
 */
- (double) getDistance;

/*
 *  @abstract
 *      Line dash(점선) 패턴 설정
 *  @param lineDashParttern     NSNumber의 배열 
 *
 *  @discussion
 *      dash패턴은 그려지는 라인길이, 안그려지는 라인길이 값이다.
 *      예를들어 [2,3]으로 설정하면 2길이를 그리고 3길이를 안그리고 다시 2길이를 그리는 형식으로 반복된다.
 */
- (void)setLineDashPattern:(NSArray*)lineDashParttern;  // NSNumber의 배열

/*
 *  @abstract
 *      Line dash(점선) 패턴 얻기
 */
- (NSArray *)getLineDashPattern;

/*
 *  @abstract
 *      외각선 dash(점선) 패턴 설정
 *  @param lineDashParttern     NSNumber의 배열
 *
 *  @discussion
 *      dash패턴은 그려지는 라인길이, 안그려지는 라인길이 값이다.
 *      예를들어 [2,3]으로 설정하면 2길이를 그리고 3길이를 안그리고 다시 2길이를 그리는 형식으로 반복된다.
 */
- (void)setOutLineDashPattern:(NSArray*)lineDashParttern;  // NSNumber의 배열

/*
 *  @abstract
 *      외각선 dash(점선) 패턴 얻기
 */
- (NSArray *)getOutLineDashPattern;

@end
