//
//  TMapView.h
//  SKP-Sample
//
//  Created by developer on 12. 10. 6..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "TMapBaseView.h"
#import "TMap.h"

typedef enum {
    POSITION_BOTTOMLEFT,        // 하단 좌측
    POSITION_BOTTOMMIDDLE,      // 하단 중앙
    POSITION_BOTTOMRIGHT        // 하단 우측
} TMapLogoPositon;


@interface TMapInfo : NSObject
@property (nonatomic, retain) TMapPoint*    mapPoint;
@property (nonatomic, assign) NSInteger     zoomLevel;
@end

@class TMapView;

@protocol TMapViewDelegate <NSObject>
@optional
/*
 *  onClick:
 *
 *  @abstract
 *      mapView Touch 이벤트 발생
 */
- (void)onClick:(TMapPoint*)TMP;

/*
 *  onCustomObjectClick:
 *
 *  @abstract
 *      marker Touch 이벤트 발생
 */
- (void)onCustomObjectClick:(TMapObject*)obj;

/*
 *  onClickReverseLabelInfo:
 *
 *  @abstract
 *      mapView 내의 라벨 터치시 Poi정보 이벤트 발생
 *  @param labelInfo   eg.
 *          poiInfo: {
 *              id: "187381",
 *              name: "유니온스틸",
 *              poiLat: 37.50484327526123,
 *              poiLon: 127.05128184843082
 *              }
 */
- (void)onClickReverseLabelInfo:(NSDictionary*)labelInfo;

/*
 *  onCustomObjectClick:screenPoint:
 *
 *  @abstract
 *      marker Touch 이벤트 발생
 */
- (void)onCustomObjectClick:(TMapObject*)obj screenPoint:(CGPoint)point;

/*
 *  onLongClick:
 *
 *  @abstract
 *      mapView LongTouch 이벤트 발생
 */
- (void)onLongClick:(TMapPoint*)TMP;

/*
 *  onCustomObjectLongClick:
 *
 *  @abstract
 *      Marker LongTouch 이벤트 발생
 */
- (void)onCustomObjectLongClick:(TMapObject*)obj;

/*
 *  onCustomObjectLongClick:screenPoint:
 *
 *  @abstract
 *      Marker LongTouch 이벤트 발생
 */
- (void)onCustomObjectLongClick:(TMapObject*)obj screenPoint:(CGPoint)point;

/*
 *  onDidScrollWithZoomLevel:centerPoint:
 *
 *  @abstract
 *      지도 화면 이동시 이벤트 발생
 */
- (void)onDidScrollWithZoomLevel:(NSInteger)zoomLevel centerPoint:(TMapPoint*)mapPoint;

/*
 *  onDidEndScrollWithZoomLevel:centerPoint:
 *
 *  @abstract
 *      지도 화면 이동 종료시 이벤트 발생
 */
- (void)onDidEndScrollWithZoomLevel:(NSInteger)zoomLevel centerPoint:(TMapPoint*)mapPoint;

/*
 *  onUserLocationClick:
 *
 *  @abstract
 *      현위치 마커 터치시 이벤트 발생
 */
- (void)onUserLocationClick:(TMapPoint*)TMP;

/*
 *  onUserLocationLongClick:
 *
 *  @abstract
 *      현위치 마커 길게터치시 이벤트 발생
 */
- (void)onUserLocationLongClick:(TMapPoint*)TMP;

/*
 *  onCalloutRightbuttonClick:
 *
 *  @abstract
 *      풍선뷰 우측 버튼 터치시 이벤트 발생
 */
- (void)onCalloutRightbuttonClick: (TMapMarkerItem*)markerItem;

/*
 *  onClusteringMarkerClick:screenPoint:
 *
 *  @abstract
 *      클러스터링 된 마커를 터치시 이벤트 발생
 */
- (void)onClusteringMarkerClick:(NSArray*)markerItems screenPoint:(CGPoint)point;

/*
 *  mapView:viewForCalloutView:
 *
 *  @abstract
 *      TMapMarker2로 생성된 마커중 풍선뷰를 생성 callback
 */
- (UIView*)mapView:(TMapView *)mapView viewForCalloutView:(TMapMarkerItem2*)markerItem;

/*
 *  SKTMapApikeySucceed
 *
 *  @abstract
 *      setSKTMapApiKey: 성공시 발생하는 callback
 */
- (void)SKTMapApikeySucceed;

/*
 *  SKTMapApikeyFailed:
 *
 *  @abstract
 *      setSKTMapApiKey: 실패시 발생하는 callback
 */
- (void)SKTMapApikeyFailed:(NSError*)error;


@end


@interface TMapView : TMapBaseView

@property (nonatomic, weak) id <TMapViewDelegate> delegate;
@property (nonatomic, assign) id <TMapGpsManagerDelegate> gpsManagersDelegate;
@property (nonatomic, readonly) NSString* version;


/*
 *  initWithFrame: centerPoint: zoomLevel: tileType:
 *
 *  @abstract
 *      초기에 타일 타입을 설정 하는 intializer
 */
- (id)initWithFrame:(CGRect)frame tileType:(TMapTileType)type;

/*
 *  initWithFrame: centerPoint: zoomLevel:
 *
 *  @abstract
 *      초기에 중심좌표(위경도)와 줌레벨을 설정 하는 initializer
 */
- (id)initWithFrame:(CGRect)frame centerPoint:(TMapPoint*)mapPoint zoomLevel:(NSInteger)zoomLevel;

/*
 *  initWithFrame: centerPoint: zoomLevel: tileType:
 *
 *  @abstract
 *      초기에 중심좌표(위경도), 줌레벨, 타일 타입을 설정 하는 initializer
 */
- (id)initWithFrame:(CGRect)frame centerPoint:(TMapPoint*)mapPoint zoomLevel:(NSInteger)zoomLevel tileType:(TMapTileType)type;

/*
 *  setSKTMapApiKey:
 *
 *  @abstract
 *      planetX에서 발급받은 APIkey를 설정
 */
- (void)setSKTMapApiKey:(NSString*)key;

/*
 *  setTMapBackgroundColor:
 *
 *  @abstract
 *      맵의 배경 색상 설정
 *
 */
- (void)setTMapBackgroundColor:(UIColor *)backgroundColor;
/*
 *  setLanguage:
 *
 *  @abstract
 *      사용안함
 */
- (void)setLanguage:(TMapViewLanguage)language;

/*
 *  setMapType:
 *
 *  @abstract
 *      사용안함
 */
- (void)setMapType:(TMapViewType)type;

/*
 *  getMapType
 *
 *  @abstract
 *      사용안함
 */
- (TMapViewType)getMapType;

/*
 *  setCenterPoint:
 *
 *  @abstract
 *      화면 센터좌표 설정
 */
- (void)setCenterPoint:(TMapPoint*)tmp;

/*
 *  getCenterPoint
 *
 *  @abstract
 *      화면 센터좌표 얻기
 */
- (TMapPoint*)getCenterPoint;

/*
 *  setLocationPoint:
 *
 *  @abstract
 *      현재위치 좌표 설정
 */
- (void)setLocationPoint:(TMapPoint*)tmp;

/*
 *  getLocationPoint
 *
 *  @abstract
 *      현재위치 좌표 얻기
 */
- (TMapPoint*)getLocationPoint;

/*
 *  setIcon:
 *
 *  @abstract
 *      현재위치마커 이미지 설정
 */
- (void)setIcon:(UIImage *)icon;

/*
 *  setIconVisibility:
 *
 *  @abstract
 *      현재위치마커 숨기기 설정
 */
- (void)setIconVisibility:(BOOL)visible;

/*
 *  setZoomLevel:
 *
 *  @abstract
 *      줌레벨 설정
 */
- (void)setZoomLevel:(NSInteger)level;

- (void)setZoomLevel:(NSInteger)level animated:(BOOL)animated;

/*
 *  getZoomLevel
 *
 *  @abstract
 *      줌레벨 얻기
 */
- (NSInteger)getZoomLevel;
/*
 *  zoomOut
 *
 *  @abstract
 *      지도 축소
 */
- (void)zoomOut;

/*
 *  zoomIn
 *
 *  @abstract
 *      지도 확대
 */
- (void)zoomIn;

/*
 *  zoomEnable
 *
 *  @abstract
 *      줌확대 가능 여부
 */
- (bool)zoomEnable;

/*
 *  setRotationMode:
 *
 *  @abstract
 *      RotationMode 설정
 */
- (void)setRotationMode:(BOOL)rotationMode;

/*
 *  setCompassMode:
 *
 *  @abstract
 *      CompassMode 설정
 */
- (void)setCompassMode:(BOOL)compassMode;

/*
 *  setContinueCompassMode:
 *
 *  @abstract
 *      CompassMode 항상 표출 설정
 */
- (void)setContinueCompassMode:(BOOL)mode;

/*
 *  setCompassModeFix:
 *
 *  @abstract
 *      CompassModeFix 설정
 */
- (void)setCompassModeFix:(BOOL)compassMode;


/*
 *  setSightImage:
 *
 *  @abstract
 *      Compass 시야표출 이미지 설정
 */
- (void)setSightImage:(UIImage*)icon;

/*
 *  setTrackingDotImage:
 *
 *  @abstract
 *      TrackingDot 이미지 설정
 */
- (void)setTrackingDotImage:(UIImage*)icon;

/*
 *  setTrackingDotHaloImage:
 *
 *  @abstract
 *      TrackingDotHalo 이미지 설정
 */
- (void)setTrackingDotHaloImage:(UIImage*)icon;

/*
 *  getIsCompass
 *
 *  @abstract
 *      CompassMode 여부 얻기
 */
- (BOOL)getIsCompass;

/*
 *  setSightVisible:
 *
 *  @abstract
 *      현위치 숨기기 설정
 */
- (void)setSightVisible:(BOOL)flag;

/*
 *  getSightVisible
 *
 *  @abstract
 *      현위치 숨기기 상태
 */
- (BOOL)getSightVisible;

/*
 *  setTrackingMode:
 *
 *  @abstract
 *      트래킹모드 설정
 */
- (void)setTrackingMode:(BOOL)trackingMode;

/*
 *  getIsTracking
 *
 *  @abstract
 *      트래킹모드 상태
 */
- (BOOL)getIsTracking;

/*
 *  suspendLocationManagerIfTrackingModeAndCompassMode
 *
 *  @abstract
 *      트래킹모드나 콤파스모드 상태일때 위치서비스 중단
 */
- (void)suspendLocationManagerIfTrackingModeAndCompassMode;

/*
 *  resumeLocationManagerIfTrackingModeAndCompassMode
 *
 *  @abstract
 *      트래킹모드나 콤파스모드 상태일때 위치서비스 중단되었던것을 다시 재개
 */
- (void)resumeLocationManagerIfTrackingModeAndCompassMode;

#pragma mark - Overlay
/*
 *  addTMapCircleID:circle:
 *
 *  @abstract
 *      Circle을 맵에 추가
 */
- (void)addTMapCircleID:(NSString *)circleID Circle:(TMapCircle *)circle;

/*
 *  removeTMapCircleID:
 *
 *  @abstract
 *      Circle을 맵에서 제거
 */
- (void)removeTMapCircleID:(NSString *)circleID;

/*
 *  removeAllTMapCircles
 *
 *  @abstract
 *      모든 Circle을 맵에서 제거
 */
- (void)removeAllTMapCircles;

/*
 *  addTMapPolygonID:Polygon:
 *
 *  @abstract
 *      Polygon을 맵에 추가
 */
- (void)addTMapPolygonID:(NSString *)polygonID Polygon:(TMapPolygon *)polygon;

/*
 *  removeTMapPolygonID:
 *
 *  @abstract
 *      Polygon을 맵에서 제거
 */
- (void)removeTMapPolygonID:(NSString *)polygonID;

/*
 *  removeAllTMapPolygons
 *
 *  @abstract
 *      모든 Polygon을 맵에서 제거
 */
- (void)removeAllTMapPolygons;

/*
 *  addTMapPolyLineID:Line:
 *
 *  @abstract
 *      TMapPolyLine을 맵에 추가
 */
- (void)addTMapPolyLineID:(NSString *)polyLineID Line:(TMapPolyLine *)line;

/*
 *  removeTMapPolyLineID:
 *
 *  @abstract
 *      polyLine을 맵에서 제거
 */
- (void)removeTMapPolyLineID:(NSString *)polyLineID;

/*
 *  removeAllTMapPolyLines:
 *
 *  @abstract
 *      모든 polyLine을 맵에서 제거
 */
- (void)removeAllTMapPolyLines;

/*
 *  addTMapMarkerItemID:Marker:
 *
 *  @abstract
 *      Marker를 맵에 추가
 */
- (void)addTMapMarkerItemID:(NSString *)markerID Marker:(TMapMarkerItem *)marker;

/*
 *  addTMapMarkerItemID:markerItem2:
 *
 *  @abstract
 *      animation이 가능하고 Custom 풍선뷰를 사용하는 Marker를 맵에 추가
 */
- (void)addTMapMarkerItemID:(NSString *)markerID markerItem2:(TMapMarkerItem2 *)markerItem;

/*
 *  addTMapOverlayID:overlayItem:
 *
 *  @abstract
 *      오버레이 이미지를 추가
 */
- (void)addTMapOverlayID:(NSString*)overlayID overlayItem:(TMapOverlayItem*)overlayItem;

/*
 *  removeTMapOverlayID:
 *
 *  @abstract
 *      오버레이 이미지를 삭제
 */
- (void)removeTMapOverlayID:(NSString*)overlayID;

/*
 *  getMetersToPixel:
 *
 *  @abstract
 *      미터당 픽셀값을 얻오옴.
 */
- (int) getMetersToPixel:(double) meters;

/*
 *  removeTMapMarkerItemID:
 *
 *  @abstract
 *      Marker를 맵에서 삭제
 */
- (void)removeTMapMarkerItemID:(NSString *)markerID;

/*
 *  addTMapPOIItemID:Poi:
 *
 *  @abstract
 *      PoiItem을 맵에 추가
 */
- (void)addTMapPOIItemID:(NSString *)poiID Poi:(TMapPOIItem *)poiitem;

/*
 *  removeTMapPOIItemID:
 *
 *  @abstract
 *      PoiItem을 맵에서 제거
 */
- (void)removeTMapPOIItemID:(NSString *)poiID;

/*
 *  addTMapMarkerItemID:Marker:animated:
 *
 *  @abstract
 *      Marker를 맵에추가
 */
- (void)addTMapMarkerItemID:(NSString *)markerID Marker:(TMapMarkerItem *)marker animated:(BOOL)animated;

/*
 *  removeTMapMarkerItemID:animated:
 *
 *  @abstract
 *      Marker를 맵에서 제거
 *  @param  markerID    삭제할 마커ID
 *  @param  animated    삭제시 애니메이션 사용유무
 */
- (void)removeTMapMarkerItemID:(NSString *)markerID animated:(BOOL)animated;

/*
 *  removeAllTMapMarkerItems
 *
 *  @abstract
 *      모든 Marker를 맵에서 제거
 */
- (void)removeAllTMapMarkerItems;

/*
 *  getCircleFromID:
 *
 *  @abstract
 *      추가한 TMapCircle을 ID를 통해 얻어온다.
 *  @param  circleID    얻어올 circleID
 */
- (TMapCircle *)getCircleFromID:(NSString *)circleID;

/*
 *  getCircleFromID:
 *
 *  @abstract
 *      추가한 TMapCircle을 ID를 통해 얻어온다.
 *  @param  circleID    얻어올 circleID
 */
- (TMapPolyLine *)getPolyLineFromID:(NSString *)polyLineID;

/*
 *  getPolygonFromID:
 *
 *  @abstract
 *      추가한 TMapPolygon ID를 통해 얻어온다.
 *  @param  polygonID    얻어올 polygonID
 */
- (TMapPolygon *)getPolygonFromID:(NSString *)polygonID;

/*
 *  getMarketItemFromID:
 *
 *  @abstract
 *      추가한 TMapMarkerItem을 ID를 통해 얻어온다.
 *  @param  markerID    얻어올 markerID
 */
- (TMapMarkerItem *)getMarketItemFromID:(NSString *)markerID;

/*
 *  getMarketItem2FromID:
 *
 *  @abstract
 *      추가한 TMapMarkerItem2를 ID를 통해 얻어온다.
 *  @param  markerID    얻어올 markerID
 */
- (TMapMarkerItem2 *)getMarketItem2FromID:(NSString *)markerID;

/*
 *  getOverlayItemFromID:
 *
 *  @abstract
 *      추가한 getOverlayItemFromID를 ID를 통해 얻어온다.
 *  @param  overlayID    얻어올 overlayID
 */
- (TMapOverlayItem *)getOverlayItemFromID:(NSString *)overlayID;

#pragma mark - // 경로 탐색
/*
 *  addTMapPath:
 *
 *  @abstract
 *      길안내 라인을 맵에 그린다
 *  @param  polyline    길안내 PolyLine
 */
- (void)addTMapPath:(TMapPolyLine *)polyline;

/*
 *  removeTMapPath
 *
 *  @abstract
 *      길안내 라인을 맵에서 제거
 */
- (void)removeTMapPath;

/*
 *  setTMapPathIconStart:End:
 *
 *  @abstract
 *      길안내 출발점과 도착점 아이콘 설정
 *  @param  start   출발점 아이콘
 *  @param  end     도착점 아이콘
 */
- (void)setTMapPathIconStart:(TMapMarkerItem *)start End:(TMapMarkerItem *)end;

/*
 *  setTMapPathIconStart:End:
 *
 *  @abstract
 *      길안내 출발점, 도착점, 경유지 아이콘 설정
 *  @param  start   출발점 아이콘
 *  @param  end     도착점 아이콘
 *  @param  pass    경유지 아이콘
 */
- (void)setTMapPathIconStart:(TMapMarkerItem *)start
                         end:(TMapMarkerItem *)end
                        pass:(TMapMarkerItem *)pass;
#pragma mark -

/*
 *  setMapPositionType:
 *
 *  @abstract
 *      네비게이션 모드 설정 (맵의 Center를 하단 쪽으로 이동)
 */
- (void)setMapPositionType:(TMapViewPositionType)type;

/*
 *  getMapPositionType
 *
 *  @abstract
 *      네비게이션 모드 상태 얻어오기
 */
- (TMapViewPositionType)getMapPositionType;

/*
 *  convertPointToGpsX:andY
 *
 *  @abstract
 *      화면 좌표를 위경도좌표(WGS84)가 있는 TMapPoint로 얻어온다
 *  @param  x   스크린 X좌표
 *  @param  y   스크린 Y좌표
 */
- (TMapPoint *)convertPointToGpsX:(float)x andY:(float)y;

#pragma mark - CallOutView
/*
 *  showCallOutViewWithMarkerItemID:
 *
 *  @abstract
 *      해당 markerItem 의 풍선뷰를 보이도록 한다
 *  @param  markerItemID   markerItem의 ID
 */
- (void)showCallOutViewWithMarkerItemID:(NSString *)markerItemID;

#pragma mark - 레이어
/*
 *  setTrafficInfo:
 *
 *  @abstract
 *      도로소통정보 레이어 ON/OFF 설정
 */
- (void)setTrafficInfo:(BOOL)flag;

/*
 *  isTrafficInfo
 *
 *  @abstract
 *      도로소통정보 레이어 ON/OFF 상태 얻기
 */
- (BOOL)isTrafficInfo;

/*
 *  setUnexpectedInfo:
 *
 *  @abstract
 *      돌발정보 레이어 ON/OFF 설정
 */
- (void)setUnexpectedInfo:(BOOL)visible;

/*
 *  isUnexpectedInfo
 *
 *  @abstract
 *      돌발정보 레이어 ON/OFF 상태 얻기
 */
- (BOOL)isUnexpectedInfo;

/*
 *  setBicycleInfo:
 *
 *  @abstract
 *      자전거 도로 레이어 ON/OFF (도로소통정보 레이어가 ON상태이면 도로소통정보 OFF상태로 변경)
 */
//- (void)setBicycleInfo:(BOOL)flag;

/*
 *  isBicycleInfo:
 *
 *  @abstract
 *      자전거 도로 레이어 ON/OFF상태 얻기
 */
//- (BOOL)isBicycleInfo;

/*
 *  setBicycleFacilityInfo:
 *
 *  @abstract
 *      자전거도로 시설물 레이어 ON/OFF
 */
//- (void)setBicycleFacilityInfo:(BOOL)flag;

/*
 *  isBicycleFacilityInfo:
 *
 *  @abstract
 *      자전거도로 시설물 레이어 ON/OFF상태 얻기
 */
//- (BOOL)isBicycleFacilityInfo;

/*
 *  addCustomObject:ID:
 *
 *  @abstract
 *      지도위의 Object(marker, polygon, polyLine)등을 추가
 */
- (void)addCustomObject:(TMapObject*)customObject ID:(NSString*)_id;

/*
 *  clearCustomObjects
 *
 *  @abstract
 *      지도위의 모든Object(marker, polygon, polyLine)를 제거 한다
 */
- (void)clearCustomObjects;

/*
 *  removeCustomObject:
 *
 *  @abstract
 *      해당 Object를 제거한다
 */
- (void)removeCustomObject:(NSString*)_id;

/*
 *  showFullPath:
 *
 *  @abstract
 *      모든 Object들을 스크린에 나오도록 줌레벨을 조절하고 Object를 그린다
 * @param   objes PolyLine객체를 요소로 가지고 있는 Array
 */
- (void)showFullPath:(NSArray*)objs;

/*
 *  showAllPolyLine:
 *
 *  @abstract
 *      polyLine이 보여질수 있는 Scale로 ZoomLevel이 변경된다.
 * @param   polyLines PolyLine객체를 요소로 가지고 있는 Array
 */
- (void)showAllPolyLine:(NSArray*)polyLines;

/*
 *  resizeWidthFrame:
 *
 *  @abstract
 *      맵의 크기 위치를 변경한다
 */
- (void)resizeWidthFrame:(CGRect)frame;

/*
 *  isValidTMapPoint:
 *
 *  @abstract
 *      해당 좌표가 지도에 표출이 돼는 좌표값인지를 반환
 */
- (BOOL)isValidTMapPoint:(TMapPoint*)tmp;

/*
 *  setTMapTileType:
 *
 *  @abstract
 *      타일 타입을 설정
 */
- (void)setTMapTileType:(TMapTileType)tileType;

/*
 *  tmapTileType
 *
 *  @abstract
 *      현재 타일타입을 얻어온다.
 */
- (TMapTileType)tmapTileType;

/*
 *  getDisplayTMapInfo
 *
 *  @abstract
 *      해당 좌표들이 모두 표출될수 있는 mapInfo(zoomLevel, center)를 얻어온다.
 * @param points TMapPoint* 요소의 배열
 */
- (TMapInfo*)getDisplayTMapInfo:(NSArray*)points;

/*
 *  bringMarkerToFront:
 *
 *  @abstract
 *      해당 MarkerItem을 최상위 이동
 */
- (void)bringMarkerToFront:(TMapMarkerItem *)item;

/*
 *  sendMarkerToBack:
 *
 *  @abstract
 *      해당 MarkerItem을 최하위로 이동
 */
- (void)sendMarkerToBack:(TMapMarkerItem *)item;

/*
 *  setEnableClustering:
 *
 *  @abstract
 *      clustering 활성화 유뮤를 설정
 */
- (void)setEnableClustering:(BOOL)enable;

/*
 *  setClusteringIcon:anchorPoint:
 *
 *  @abstract
 *      clustering Icon을 설정한다.
 */
- (void)setClusteringIcon:(UIImage*)icon anchorPoint:(CGPoint)point;

/*
 *  getCaptureImage
 *
 *  @abstract
 *      mapView 캡쳐
 */
- (UIImage*)getCaptureImage;

- (void)setCaptureMode:(BOOL)mode;

/*
 *  setThreadNameForCapture:
 *
 *  @abstract
 *      NSThread를 통한 캡쳐모드시 
 *        캡쳐에사용하는 NSThread의 name property를 설정
 */
- (void)setNSThreadNameForCapture:(NSString*)threadName;

/*
 *  setUserScrollZoomEnable:
 *
 *  @abstract
 *      사용자 제스쳐로 지도이동을 막는다
 */
- (void)setUserScrollZoomEnable:(BOOL)enable;

/*
 *  getTMapPointFromScreenPoint:
 *
 *  @abstract
 *      스크린좌표를 위경도좌표(WGS84)좌표로 변환
 */
- (TMapPoint*)getTMapPointFromScreenPoint:(CGPoint)screenPoint;

/*
 *  getLeftTopPoint
 *
 *  @abstract
 *      스크린 좌상단의 위경도좌표를 얻어온다.
 */
- (TMapPoint*)getLeftTopPoint;

/*
 *  getRightBottomPoint
 *
 *  @abstract
 *      스크린 우하단의 위경도좌표를 얻어온다.
 */
- (TMapPoint*)getRightBottomPoint;

/*
 *  rotateMap
 *
 *  @abstract
 *      해당 각도 만큼 지도를 회전한다.
 */
- (void)rotateMap:(CGFloat)angle;

/*
 *  reDrawMap
 *
 *  @abstract
 *      지도를 다시그린다.
 */
- (void)reDrawMap;

/*
 *  setTMapLogoPosition
 *
 *  @abstract
 *      TMapLogo의 위치를 변경한다.
 */
- (void)setTMapLogoPosition:(TMapLogoPositon)logoPosition;

/*
 *  isHiddenLogo
 *
 *  @abstract
 *      TMapLogo를 숨기고 보인다.
 */
- (void)isHiddenLogo:(BOOL)visible;

/*
 *  zoomToLatSpan: lonSpan:
 *
 *  @abstract
 *      해당 Span값으로 줌을 변경한다.
 */
- (void)zoomToLatSpan:(double)latSpan lonSpan:(double)lonSpan;

/*
 *  zoomToTMapPointLeftTop: rightBottom:
 *
 *  @abstract
 *      해당 좌표로 줌을 변경한다.
 */
- (void)zoomToTMapPointLeftTop:(TMapPoint*)leftTop rightBottom:(TMapPoint*)rightBottom;

/*
 *  setZoomFixSetting
 *
 *  @abstract
 *      줌 고정 좌표를 설정한다.
 */
- (void)setZoomPosition:(TMapPoint*)point;

/*
 *  removeZoomPosition
 *
 *  @abstract
 *      설정된 줌 고정 좌표를 초기화한다.
 */
- (void)removeZoomPosition;

#pragma https
/*
 *  setHttpsMode
 *
 *  @abstract
 *      TMapTile https 프로토콜 서비스
 */
- (void)setHttpsMode:(BOOL)isActive;

@end
