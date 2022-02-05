//
//  TMapAnnotation.h
//  SKP-Sample
//
//  Created by developer on 12. 9. 25..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMapType.h"

@class TMapBaseView, TMapLayer, TMapQuadTreeNode;

@interface TMapAnnotation : NSObject
{
    TMapLayer*      _layer;
    
    CLLocationCoordinate2D  _coordinate;
    STMapRect        _boundingRect;
    //STMapPoint       _mapPoint;
    CGPoint         _position;
    
    UIImage*        _icon;
    CGPoint         _anchorPoint;
    TMapBaseView*   _mapView;
    NSString*       _title;
    
    //
    NSString*       _annotationType;
}

@property (nonatomic, retain)   TMapLayer* layer;

@property (nonatomic, assign)   CLLocationCoordinate2D  coordinate;

@property (nonatomic, assign)   STMapRect boundingRect;

//@property (nonatomic, readonly) STMapPoint mapPoint;

@property (nonatomic, readonly) STMapPoint meterPoint;

@property (nonatomic, assign)   CGPoint position;

@property (nonatomic, retain)   UIImage* icon;

@property (nonatomic, assign)   CGPoint anchorPoint;

@property (nonatomic, assign)   TMapBaseView* mapView;

@property (nonatomic, retain)   NSString* annotationType;

@property (nonatomic, assign)   BOOL isUserLocationAnnotation;

@property (nonatomic, assign)   BOOL isAdAnnotation;

@property (nonatomic, assign)   BOOL isLabelAnnotation;

@property (nonatomic, copy)     NSString* title;

@property (nonatomic, copy)     NSString* markerTitle;

@property (nonatomic, assign)   BOOL canShowCallout;

@property (nonatomic, retain) UIImage* calloutLeftImage;

@property (nonatomic, retain) UIImage* calloutRightButtonImage;

@property (nonatomic, copy) NSString*   calloutTitle;

@property (nonatomic, copy) NSString*   calloutSubtitle;

@property (nonatomic, assign) BOOL clusteringEnabled;

@property (nonatomic, retain) NSMutableArray* annotationsInCluster;

@property (nonatomic, assign) BOOL autoCalloutVisible;

@property (nonatomic, retain) NSArray* aniImages;

+ (id)annotationWithMapView:(TMapBaseView *)mapView coordinate:(CLLocationCoordinate2D)coordinate andTitle:(NSString *)title;

- (id)initWithMapView:(TMapBaseView *)mapView coordinate:(CLLocationCoordinate2D)coordinate andTitle:(NSString *)title;

- (id)initWithAnnotation:(TMapAnnotation* )annotation;

- (void)setPosition:(CGPoint)position animated:(BOOL)animated;

// clustering
- (void)addAnnotation:(TMapAnnotation*)annotation;

- (void)addAnnotations:(NSArray *)annotations;

- (void)removeAnnotation:(TMapAnnotation*)annotation;

- (void)removeAnnotations:(NSArray *)annotations;

@end
