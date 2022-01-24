//
//  TMapOverlayItem.h
//  SkpTopLib
//
//  Created by heungguk on 2014. 3. 26..
//  Copyright (c) 2014년 skp. All rights reserved.
//

#import "TMapObject.h"
#import "TMapPoint.h"

@class TMapView;

@interface TMapOverlayItem : TMapObject

@property (nonatomic, retain) UIView* view;

@property (nonatomic, retain) TMapView* mapView;

@property (nonatomic, assign) UIImage* image;

@property (nonatomic, assign) TMapPoint* leftTopPoint;

@property (nonatomic, assign) TMapPoint* rightBottomPoint;


- (void)setImage:(UIImage *)image;

- (void)setLeftTopPoint:(TMapPoint *)leftTopPoint;

- (void)setRightBottomPoint:(TMapPoint *)rightBottomPoint;

@end
