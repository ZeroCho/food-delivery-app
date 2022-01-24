import {NativeModules} from 'react-native';
const {TMap} = NativeModules;

interface TMapInterface {
  openNavi(
    name: string,
    long: string,
    lat: string,
    naviVehicle: string,
  ): Promise<boolean>;
}
export default TMap as TMapInterface;
