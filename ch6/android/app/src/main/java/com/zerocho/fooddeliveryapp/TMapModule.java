package com.zerocho.fooddeliveryapp;

import android.util.Log;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.skt.Tmap.TMapTapi;
import org.jetbrains.annotations.NotNull;
import java.util.HashMap;

public class TMapModule extends ReactContextBaseJavaModule {
    TMapModule(ReactApplicationContext context) {
        super(context);
    }

    @NotNull
    @Override
    public String getName() {
        return "TMap";
    }

    @ReactMethod
    public void openNavi(String name, String longitude, String latitude, String vehicle, Promise promise) {
        TMapTapi tMapTapi = new TMapTapi(getReactApplicationContext());
        tMapTapi.setOnAuthenticationListener(new TMapTapi.OnAuthenticationListenerCallback() {
            @Override
            public void SKTMapApikeySucceed() {
                boolean isTmapApp = tMapTapi.isTmapApplicationInstalled();
                Log.i("TMap", isTmapApp ? "설치됨" : "미설치");
                if (isTmapApp) {
                    HashMap pathInfo = new HashMap();
                    pathInfo.put("rGoName", name);
                    pathInfo.put("rGoX", longitude);
                    pathInfo.put("rGoY", latitude);
                    pathInfo.put("rSOpt", vehicle.equals("MOTORCYCLE") ? 6 : 0);

                    boolean result = tMapTapi.invokeRoute(pathInfo);
                    if (result) {
                        promise.resolve(true);
                    } else {
                        promise.resolve(true);
                    }
                } else {
                    promise.resolve(false);
                }
            }

            @Override
            public void SKTMapApikeyFailed(String errorMsg) {
                Log.e("TMap", errorMsg);
                promise.resolve(false);
            }
        });
        tMapTapi.setSKTMapAuthentication("l7xx23d57d02cdef4970ad53c247b91f85c0");
        boolean isTmapApp = tMapTapi.isTmapApplicationInstalled();
        if (isTmapApp) {
            boolean result = tMapTapi.invokeNavigate(name, Float.parseFloat(longitude), Float.parseFloat(latitude), 0, false, vehicle.equals("MOTORCYCLE") ? 6 : 0);
            if (result) {
                promise.resolve(true);
            } else {
                promise.resolve(true);
            }
        }
    }
}
