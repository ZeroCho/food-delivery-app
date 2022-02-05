//
//  TMapPolygon.h
//  skp
//
//  Created by developer on 12. 8. 5..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreGraphics/CGColor.h>

#import "TMapPoint.h"
#import "TMapObject.h"

@interface TMapPolygon : TMapObject 
{
    UIColor*    _lineColor;
    UIColor*    _fillColor;
    CGFloat     _lineWidth;
    
    NSMutableArray*     _points;
}

@property (nonatomic, retain) UIColor*  lineColor;
@property (nonatomic, retain) UIColor*  fillColor;
@property (nonatomic, assign) CGFloat   lineWidth;
@property (nonatomic, readonly) NSMutableArray* points;

/*
 *  @abstract
 *      Polygon의 FillColor 알파값 설정
 */
- (void)setPolygonAreaColor:(CGColorRef)_color;

/*
 *  @abstract
 *      Polygon의 FillColor 알파값 얻기
 */
- (CGColorRef)getPolygonAreaColor;

/*
 *  @abstract
 *      Polygon의 외곽선 라인 굵기 설정
 */
- (void)setPolygonLineWidth:(float)_width;

/*
 *  @abstract
 *      Polygon의 외곽선 라인 굵기 얻기
 */
- (float)getPolygonLineWidth;

/*
 *  @abstract
 *      Polygon의 Point추가
 */
- (void)addPolygonPoint:(TMapPoint *)point;

/*
 *  @abstract
 *      Polygon의 Point목록 얻기
 */
- (NSArray *)getPolygonPoint;

/*
 *  @abstract
 *      Polygon의 외곽선 라인색상설정
 */
- (void)setPolygonLineColor:(CGColorRef)_color;

/*
 *  @abstract
 *      Polygon의 외곽선 라인색상얻기
 */
- (CGColorRef)getPolygonLineColor;

/*
 *  @abstract
 *      Polygon의 FillColor 알파값설정
 */
- (void)setPolygonAlpha:(int)alpha;

/*
 *  @abstract
 *      Polygon의 FillColor 알파값설정
 */
- (int)getPolygonAlpha;

/*
 *  @abstract
 *      Polygon의 외곽선 라인 알파값설정
 */
- (void)setPolygonLineAlpha:(int)alpha;

/*
 *  @abstract
 *      Polygon의 외곽선 라인 알파값얻기
 */
- (int)getPolygonLineAlpha;

/*
 *  @abstract
 *      Polygon의 면적
 */
- (double)getPolygonArea;

@end
