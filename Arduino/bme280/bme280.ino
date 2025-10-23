

#include "Adafruit_BME280.h"
Adafruit_BME280 bme280;

void setup() {
  Serial.begin(115200);
  
  // put your setup code here, to run once:
   bme280.begin(0x76);
}

void loop() {
  float temp;
  float pressure;
  float altitude;
  float humidity;

  // put your main code here, to run repeatedly:
  temp = bme280.readTemperature();
  pressure = bme280.readPressure();
  altitude = bme280.readAltitude(1013.25) * 3.28084; // Sea level pressure in hPa
  humidity = bme280.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");
  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" ft");
  Serial.println("---");
  delay(2000);
}
