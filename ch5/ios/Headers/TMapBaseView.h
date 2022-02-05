//
//  TMapBaseView.h
//  Sample
//
//  Created by developer on 12. 9. 19..
//
//

#import <UIKit/UIKit.h>

#import "TMapType.h"

#define kRMUserLocationAnnotationTypeName   @"RMUserLocationAnnotation"
#define kRMTrackingHaloAnnotationTypeName   @"RMTrackingHaloAnnotation"
#define kRMAccuracyCircleAnnotationTypeName @"RMAccuracyCircleAnnotation"

@class TMapAnnotation, TMapUserLocation;

@protocol UserLocationProtectedMethods <NSObject>
- (void)setUserLocationImage:(UIImage*)iamge;
- (void)setUserLocationTraking:(BOOL)tracking;
- (void)changeUserLocation:(CLLocation*)location;
- (CLLocationCoordinate2D)coordinateAtPoint:(CGPoint)point;
- (void)reDrawMap;
- (void)rejustZoomWidthWidth:(double)width height:(double)height;
- (void)addOverlayView:(UIView*)overlayView info:(NSDictionary*)info;
- (void)zoomToCoordLeftTop:(CLLocationCoordinate2D)leftTop rightBottom:(CLLocationCoordinate2D)rightBottom;
- (void)setPoweredByPosition:(int)type;
@end

@protocol TMapTileSource;

@interface TMapBaseView : UIView <UserLocationProtectedMethods>
{
    BOOL    _compassMode;
    BOOL    _compassMode2;
    BOOL    _rotationMode;
    // Navi or Normal
    TMapViewPositionType _centerPointType;
    
    UIImage*    _userLocationImage;
    UIImage*    _sightImage;
    UIImage*    _trackingDotImage;
    UIImage*    _trackingDotHaloImage;
     
@private
    //TMapBaseViewInternal *_internal;
}
@property (nonatomic, assign) BOOL userEnableMode;

@property (nonatomic, assign) BOOL enableClustering;

@property (nonatomic, retain) UIImage* clusteringImage;

@property (nonatomic, assign) CGPoint clusteringAnchorPoint;

@property (nonatomic, readonly) double metersPerPixel;

@property (nonatomic, assign) NSUInteger boundingMask;

@property (nonatomic, assign)  TMapUserTrackingMode userTrackingMode;

@property (nonatomic, assign)   BOOL showsUserLocation;

@property (nonatomic, assign)   BOOL showsUserLocationLayer;

@property (nonatomic, retain) TMapUserLocation *userLocation;

@property (nonatomic, assign) NSInteger zoomLevel;

@property (nonatomic, assign) CGPoint  fixMode; //2018.06.18 추가

@property (nonatomic, assign) CGFloat zoomScale;

@property (nonatomic, assign) BOOL  trafficMode;

@property (nonatomic, assign) BOOL  unexpectedMode;

@property (nonatomic, assign) BOOL  bicycleMode;

@property (nonatomic, assign) BOOL  bicycleFacilityMode;

@property (nonatomic, assign) BOOL  useCaptureDraw;

@property (nonatomic, assign) NSString* captureThreadName;

@property (nonatomic, assign) id<TMapTileSource> tileSource;

@property (nonatomic, readonly) CLLocationCoordinate2D leftTopCoordinate;

@property (nonatomic, readonly) CLLocationCoordinate2D rightBottomCoordinate;

@property (nonatomic, retain) NSMutableArray* annotations;

- (void)setZoomLevel:(NSInteger)level;

- (void)setZoomLevel:(NSInteger)level animated:(BOOL)animated;

- (void)setFixMode:(CGPoint)fixMode; //2018.06.18 추가

- (void)setTileHttpsMode:(BOOL)mode; //2018.08 추가


//2018.07.05 끝

// deprecated.(iOS7 SDK에서 문제발생) setCenterCoordinate로 대체 사용.
//- (void)setCenter:(CLLocationCoordinate2D)coord;

- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate;

- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

- (CLLocationCoordinate2D)centerCoordinate;

//- (void)changeScrollPoint;

// annotations
- (void)addAnnotation:(TMapAnnotation*)annotation;

- (void)addAnnotation:(TMapAnnotation*)annotation animated:(BOOL)animated;

- (void)removeAnnotation:(TMapAnnotation *)annotation;

- (void)removeAnnotations:(NSArray *)annotations;

- (void)removeAllAnnotations;

- (void)removeAnotationWithTitle:(NSString*)title;

- (void)removeAnotationWithTitles:(NSArray*)titles;

- (CGPoint)screenPointFromCoordinate:(CLLocationCoordinate2D)coordinate;

- (CGPoint)screenPointFromMapPoint:(STMapPoint)mapPoint;

- (CGPoint)screenPointFromMeterPoint:(STMapPoint)meterPoint;

- (STMapPoint)mapPointFromScreenPoint:(CGPoint)screenPoint;

- (CLLocationCoordinate2D)coordinateFromScreenPoint:(CGPoint)screenPoint;

- (CGPoint)overlayPointFromCoordinate:(CLLocationCoordinate2D)coordinate;

// location
- (void)startUserLocation;

// gesture
- (void)onClick:(CLLocationCoordinate2D)coordinate;
- (void)onLongClick:(CLLocationCoordinate2D)coordinate;

- (void)onCustomObjectClick:(TMapAnnotation*)annotation;
- (void)onCustomObjectLongClick:(TMapAnnotation*)annotation;

- (void)onDidScroll:(CLLocationCoordinate2D)coordinate zoomLevel:(NSInteger)zoomLevel;
- (void)onDidEndScroll:(CLLocationCoordinate2D)coordinate zoomLevel:(NSInteger)zoomLevel;

- (void)onUserLocationClick:(CLLocationCoordinate2D)coordinate;
- (void)onUserLocationLongClick:(CLLocationCoordinate2D)coordinate;

- (void)onClusteringMarkerClick:(NSArray *)annotations screenPoint:(CGPoint)point;

// gps
- (void)gpsLocationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation;
- (void)gpsLocationManager:(CLLocationManager *)manager didUpdateHeading:(CLHeading *)newHeading;

- (void)rotateMap:(CGFloat)angle;

- (void)bringAnnotationToFront:(TMapAnnotation *)annotation; // 최상위로
- (void)sendAnnotationToBack:(TMapAnnotation *)annotation;    // 최하위로

- (void)showCallOutView:(TMapAnnotation *)annotation;

@end


