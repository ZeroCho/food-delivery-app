import React, {useEffect, useState} from 'react';
import {Alert, Dimensions, Text, View} from 'react-native';
import {NaverMapView, NaverMapPathOverlay, NaverMapMarkerOverlay } from '@mj-studio/react-native-naver-map';
import {useSelector} from 'react-redux';
import {RootState} from '../store/reducer';
import Geolocation from '@react-native-community/geolocation';
import {NativeStackScreenProps} from '@react-navigation/native-stack';
import {LoggedInParamList} from '../../AppInner';
import TMap from '../modules/TMap';

type IngScreenProps = NativeStackScreenProps<LoggedInParamList, 'Delivery'>;

function Ing({navigation}: IngScreenProps) {
  console.dir(navigation);
  const deliveries = useSelector((state: RootState) => state.order.deliveries);
  const [myPosition, setMyPosition] = useState<{
    latitude: number;
    longitude: number;
  } | null>(null);

  useEffect(() => {
    Geolocation.getCurrentPosition(
      info => {
        console.log('내 위치', info);
        setMyPosition({
          latitude: info.coords.latitude,
          longitude: info.coords.longitude,
        });
      },
      console.error,
      {
        enableHighAccuracy: true,
        timeout: 20000,
      },
    );
  }, []);

  if (!deliveries?.[0]) {
    return (
      <View style={{alignItems: 'center', justifyContent: 'center', flex: 1}}>
        <Text>주문을 먼저 수락해주세요!</Text>
      </View>
    );
  }

  if (!myPosition || !myPosition.latitude) {
    return (
      <View style={{alignItems: 'center', justifyContent: 'center', flex: 1}}>
        <Text>내 위치를 로딩 중입니다. 권한을 허용했는지 확인해주세요.</Text>
      </View>
    );
  }

  const {start, end} = deliveries?.[0];
  console.log('start', start, 'end', end);
  return (
    <View>
      <View
        style={{
          width: Dimensions.get('window').width,
          height: Dimensions.get('window').height,
        }}
      >
        <NaverMapView
          style={{height: Dimensions.get('window').height - 120}}
          initialCamera={{
            latitude: (start.latitude + end.latitude) / 2,
            longitude: (start.longitude + end.longitude) / 2,
            zoom: 10,
            tilt: 50,
          }}
          isShowZoomControls
          isShowLocationButton
          isShowCompass={false}
          isShowScaleBar
        >
          {myPosition?.latitude && (
            <NaverMapMarkerOverlay
              latitude={myPosition.latitude}
              longitude={myPosition.longitude}
              width={100}
              height={100}
              anchor={{x: 0.5, y: 0.5}}
              caption={{text: '나'}}
              image={require('../assets/red-dot.png')}
            />
          )}
          {myPosition?.latitude && (
            <NaverMapPathOverlay
              coords={[
                {
                  latitude: myPosition.latitude,
                  longitude: myPosition.longitude,
                },
                {latitude: start.latitude, longitude: start.longitude},
              ]}
              color="orange"
            />
          )}
          <NaverMapMarkerOverlay
            latitude={start.latitude}
            longitude={start.longitude}
            width={15}
            height={15}
            globalZIndex={1000}
            anchor={{x: 0.5, y: 0.5}}
            caption={{text: '출발'}}
            image={require('../assets/blue-dot.png')}
            onTap={() => {
              TMap.openNavi(
                '출발지',
                start.longitude.toString(),
                start.latitude.toString(),
                'MOTORCYCLE',
              ).then(data => {
                console.log('TMap callback', data);
                if (!data) {
                  Alert.alert('알림', '티맵을 설치하세요.');
                }
              });
            }}
          />
          <NaverMapPathOverlay
            coords={[
              {
                latitude: start.latitude,
                longitude: start.longitude,
              },
              {latitude: end.latitude, longitude: end.longitude},
            ]}
            globalZIndex={1000}
            color="orange"
            onTap={() => {
              TMap.openNavi(
                '도착지',
                end.longitude.toString(),
                end.latitude.toString(),
                'MOTORCYCLE',
              ).then(data => {
                console.log('TMap callback', data);
                if (!data) {
                  Alert.alert('알림', '티맵을 설치하세요.');
                }
              });
            }}
          />
          <NaverMapMarkerOverlay
            latitude={end.latitude}
            longitude={end.longitude}
            width={15}
            globalZIndex={1000}
            height={15}
            anchor={{x: 0.5, y: 0.5}}
            caption={{text: '도착'}}
            image={require('../assets/green-dot.png')}
            onTap={() => {
              console.log(navigation);
              navigation.push('Complete', {orderId: deliveries[0].orderId});
            }}
          />
        </NaverMapView>
      </View>
    </View>
  );
}

export default Ing;
