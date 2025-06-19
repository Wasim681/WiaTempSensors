#define WIA_TEMP_SENS_DS18B20
#include <WiaTempSensors.h>

Wia_DS18B20 sensor;

void setup() {
  Serial.begin(115200);
  sensor.init();
}

void loop() {
  float tempC = sensor.getTempC();
  Serial.printf("Current Temp is: %.2f °C\n", tempC);
  delay(5000); 
}
