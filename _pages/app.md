---
layout: default
title: "App - Camp Sense Mobile"
permalink: /app/
---

# Camp Sense Mobile App

The Camp Sense app connects to the WattIsIt ESP32 hardware module via Bluetooth and displays battery energy usage and weather data.

## Features

### Energy Monitoring
- **Real-time Current Display**: Shows current amps into (charging) or out (discharging) the battery
- **Energy Tracking**: Total count of watt hours that went into and out of the battery
- **Reset Functionality**: Long press the battery on screen to reset the Wh counters
- **Shunt Configuration**: Long press the setting to configure your shunt resistor voltage drop rating (50mV, 75mV, or 100mV)

### Weather Information
- **Weather Screen**: Access by swiping left from the main screen
- **Return Navigation**: Swipe right on weather screen to return to energy view
- **Astronomy Data**: Optional sunrise, sunset, and other astronomy information based on location

## App Screenshots

|                     Energy                     |                    Weather                    |
| :--------------------------------------------: | :-------------------------------------------: |
| <img src="../images/campsense1.jpeg" width="300"> | <img src="../images/campsense2.png" width="300"> |

## Technical Details

- **Framework**: React Native with Expo
- **Platform**: iOS and Android
- **Communication**: Bluetooth Low Energy (BLE) with ESP32
- **Location Services**: Optional for astronomy data
- **Data Source**: ipgeolocation.io Astronomy API

## Development

The app source code is located in the `App/` folder and includes:

- `src/Energy.js` - Energy monitoring components
- `src/Weather.js` - Weather display components  
- `src/useBLE.js` - Bluetooth communication hooks
- `src/useLocation.js` - Location services hooks
- `src/EnergyContext.js` - State management for energy data

## Download the App

<div class="app-store-badges">
  <a href="https://apps.apple.com/us/app/camp-sense/id6741625671" target="_blank" rel="noopener">
    <img src="https://developer.apple.com/assets/elements/badges/download-on-the-app-store.svg" alt="Download on the App Store" class="app-badge">
  </a>
</div>

<p><strong>Available now on the App Store!</strong> The app is free and works on iPhone, iPad, and Mac with Apple Silicon.</p>
