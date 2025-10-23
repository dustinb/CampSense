

#include "Adafruit_BMP280.h"
Adafruit_BMP280 bmp280;

void setup() {
  Serial.begin(115200);
  
  // put your setup code here, to run once:
   bmp280.begin(0x76, 0x58);
}

void loop() {
  float temp;
  float pressure;
  float altitude;

  // put your main code here, to run repeatedly:
  temp = bmp280.readTemperature();
  pressure = bmp280.readPressure();
  altitude = bmp280.readAltitude() * 3.28084;

  Serial.print("Temp:");
  Serial.println(temp);
  Serial.print("Altitude: ");
  Serial.println(altitude);
  Serial.print("Pressure: ");
  Serial.println(pressure);
  delay(2000);
}
