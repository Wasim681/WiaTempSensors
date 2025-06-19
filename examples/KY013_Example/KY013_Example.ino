#define WIA_TEMP_SENS_KY013
#include <WiaTempSensors.h>

Wia_KY013 sensor(A0);

void setup() {
  Serial.begin(115200);
  sensor.init();
}

void loop() {
  float tempC = sensor.getTempC();
  Serial.printf("Current Temp is: %.2f °C\n", tempC);
  delay(5000); 
}
