const IS_DEV = process.env.APP_VARIANT === "development";
const IS_PREVIEW = process.env.APP_VARIANT === "preview";

const getUniqueIdentifier = () => {
  if (IS_DEV) {
    return "com.oldbute.wattisit.dev";
  }

  if (IS_PREVIEW) {
    return "com.oldbute.wattisit.preview";
  }

  return "com.oldbute.wattisit";
};

const getAppName = () => {
  if (IS_DEV) {
    return "Camp Sense (Dev)";
  }

  if (IS_PREVIEW) {
    return "Camp Sense (Preview)";
  }

  return "Camp Sense";
};

export default {
  expo: {
    name: getAppName(),
    slug: "WattIsIt",
    version: "1.0.1",
    buildNumber: "3",
    orientation: "portrait",
    icon: "./assets/icon.png",
    userInterfaceStyle: "light",
    splash: {
      image: "./assets/camp4.jpg",
      resizeMode: "contain",
      backgroundColor: "#ffffff",
    },
    env: {
      EXPO_PUBLIC_IPGEO_API_KEY: process.env.EXPO_PUBLIC_IPGEO_API_KEY,
    },
    plugins: [
      "react-native-ble-plx",
      [
        "expo-location",
        {
          locationAlwaysAndWhenInUsePermission:
            "Camp Sense uses your latitude and longitude to get astronomy data from api.ipgeolocation.io.  This allows accurate sunrise, sunset, and moonrise times. This is optional and does not affect the energy monitoring.",
        },
      ],
    ],
    ios: {
      supportsTablet: true,
      bundleIdentifier: getUniqueIdentifier(),
      buildNumber: "3",
      infoPlist: {
        NSBluetoothAlwaysUsageDescription:
          "Camp Sense uses Bluetooth in the background to stay connected to your WattIsIT energy monitor.",
        NSBluetoothPeripheralUsageDescription:
          "Camp Sense uses Bluetooth to stay connected to your WattIsIt energy monitor.",
        "ITSAppUsesNonExemptEncryption": false,
        NSLocationAlwaysUsageDescription:
          "Camp Sense uses your latitude and longitude to get astronomy data from api.ipgeolocation.io.  This allows accurate sunrise, sunset, and moonrise times. This is optional and does not affect the energy monitoring.",
        NSLocationWhenInUseUsageDescription: 
          "Camp Sense uses your latitude and longitude to get astronomy data from api.ipgeolocation.io.  This allows accurate sunrise, sunset, and moonrise times. This is optional and does not affect the energy monitoring.",
        NSLocationAlwaysAndWhenInUseUsageDescription:
          "Camp Sense uses your latitude and longitude to get astronomy data from api.ipgeolocation.io.  This allows accurate sunrise, sunset, and moonrise times. This is optional and does not affect the energy monitoring."
      },
    },
    android: {
      adaptiveIcon: {
        foregroundImage: "./assets/adaptive-icon.png",
        backgroundColor: "#ffffff",
      },
      versionCode: 3,
      package: getUniqueIdentifier(),
      permissions: [
        "android.permission.BLUETOOTH",
        "android.permission.BLUETOOTH_CONNECT",
        "android.permission.BLUETOOTH_SCAN",
        "android.permission.ACCESS_FINE_LOCATION",
        "android.permission.ACCESS_COARSE_LOCATION",
      ],
    },
    web: {
      favicon: "./assets/favicon.png",
    },
    extra: {
      eas: {
        projectId: "b36ab266-2a21-4099-9502-a3a48f6e3816",
      },
    },
    owner: "oldbute",
  },
};
