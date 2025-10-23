#include <AHT20.h>
#include <Wire.h>

AHT20 aht20;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Wait for serial to initialize
  while (!Serial) {
    delay(10);
  }
  
  Serial.println("Starting I2C Scanner...");
  Serial.println("Scanning for I2C devices...");
  
  // I2C Scanner
  byte error, address;
  int nDevices = 0;
  
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  
  if (nDevices == 0) {
    Serial.println("No I2C devices found");
  } else {
    Serial.print("Found ");
    Serial.print(nDevices);
    Serial.println(" device(s)");
  }
  
  Serial.println("Done scanning.\n");
  
  // Now try to initialize AHT20
  Serial.println("Attempting to initialize AHT20...");
  if (!aht20.begin()) {
    Serial.println("AHT20 sensor not found!");
    Serial.println("Make sure:");
    Serial.println("1. AHT20 is properly connected to SDA and SCL pins");
    Serial.println("2. AHT20 is powered (3.3V or 5V depending on your board)");
    Serial.println("3. Pull-up resistors are present (4.7kΩ recommended)");
    Serial.println("4. Check the I2C address above - AHT20 should appear at 0x38");
  } else {
    Serial.println("AHT20 sensor initialized successfully");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp;
  float humidity;

  temp = aht20.getTemperature();
  humidity = aht20.getHumidity();

  Serial.print("Temp: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  
  delay(1500);
}
