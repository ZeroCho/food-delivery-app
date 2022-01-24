//
//  TMapObject.h
//  skp
//
//  Created by developer on 12. 8. 5..
//  Copyright (c) 2012년 SKP. All rights reserved.
//

#import "TMapAnnotation.h"

@interface TMapObject : NSObject
{
    CLLocationCoordinate2D  _coordinate;
    NSString*   _objectID;
    TMapAnnotation* _annotation;
}
@property (nonatomic, assign) TMapAnnotation* annotation;

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@property (nonatomic, copy) NSString* objectID;

/*
 *  @abstract
 *      Object ID 설정
 */
- (void)setID:(NSString*)_ID;

/*
 *  @abstract
 *      Object ID 얻기
 */
- (NSString*)getID;

@end
