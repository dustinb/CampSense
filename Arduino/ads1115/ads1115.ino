#include <Wire.h>

#include "ADS1X15.h"
ADS1115 ADS(0x48);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);

   Wire.begin();
   delay(1000);
   ADS.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  ADS.setGain(1);
  int16_t adc = ADS.readADC(0);
  float f = ADS.toVoltage(1);
  float adcVolts = adc * f;
  Serial.print("ADC: ");
  Serial.println(adcVolts);

  int R1 = 36000;
  int R2 = 10000;

  float vbat = ((R1 + R2) * adcVolts) / R2;
  Serial.print("Battery Voltage: ");
  Serial.println(vbat);
}
