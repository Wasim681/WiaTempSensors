#ifndef WIA_CLASS_TEMP_SENS_AHT20
  #define WIA_CLASS_TEMP_SENS_AHT20
  
  #include <Wire.h>
  #include <Adafruit_Sensor.h>
  #include <Adafruit_BME280.h>  
  
  class TempSensorAHT20{
    public: 
      bool init(){
        bool init_sensor = sensor.begin(0x76);
        delay(5);
        if(!init_sensor){
            Serial.println("Could not find a valid sensor, check wiring, address, sensor ID!");
            Serial.print("SensorID was: 0x"); Serial.println(sensor.sensorID(), 16);
            Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
            Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
            Serial.print("        ID of 0x60 represents a BME 280.\n");
            Serial.print("        ID of 0x61 represents a BME 680.\n");
            return false;
        }
        Serial.println("init::sensorID"+ String(sensor.sensorID(), HEX));
        return true;
        }
      float getTempC(){ return sensor.readTemperature(); }
      float getHumidity(){ return sensor.readHumidity(); }
    private:
      Adafruit_BME280 sensor; 
  };

#endif