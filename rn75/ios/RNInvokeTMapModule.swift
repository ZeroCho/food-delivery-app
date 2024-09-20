import Foundation
import TMapSDK

@objc(TMap)
class TMap: NSObject{

  //Init에 api key 인증
  override init() {
    super.init()
    TMapApi.setSKTMapAuthenticationWithDelegate(self, apiKey: "l7xx3fcf34960c684fb4ad18e23c7342c415")
  }

  //TMap이 설치되었는지 확인
  @objc func checkTmapApplicationInstalled(_ resolve:RCTPromiseResolveBlock, rejecter reject:RCTPromiseRejectBlock) -> Void {
    let isInstalled = TMapApi.isTmapApplicationInstalled();
    if(isInstalled){
      resolve(isInstalled)
    }else{
      reject(isInstalled)
    }
  }

  //받은 routeInfo를 이용해서 TMap에 넘김
  @objc func openNavi(_ name: String, longitude: String, latitude: String, vehicle: String, resolver resolve: @escaping RCTPromiseResolveBlock, rejecter reject: @escaping RCTPromiseRejectBlock) -> Bool {
    print("y,x \(latitude), \(longitude)")

    let installed = TMapTapi.isTmapApplicationInstalled()
    if installed {
      let latitudeValue = Double(latitude) ?? 0.0
      let longitudeValue = Double(longitude) ?? 0.0
      let centerCoordinate = CLLocationCoordinate2D(latitude: latitudeValue, longitude: longitudeValue)

      let flag = TMapTapi.invokeRoute(name, coordinate: centerCoordinate)
      print(flag ? "Yes" : "No")

      if flag {
        resolve(true)
      } else {
        resolve(false)
      }
    } else {
      resolve(false)
    }
  }
}

extension TMap: TMapTapiDelegate {
  func SKTMapApikeySucceed() {
    print("TMap api key 인증이 성공되었습니다")
  }

  func SKTMapApikeyFailed(error: NSError?) {
    print(error ?? "TMap api key 인증에 실패했습니다.")
  }
}
