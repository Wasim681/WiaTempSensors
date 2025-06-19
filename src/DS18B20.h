#ifndef WIA_CLASS_TEMP_SENS_DS18B20
  #define WIA_CLASS_TEMP_SENS_DS18B20

  #ifndef TEMPERATURE_PRECISION
    #define TEMPERATURE_PRECISION 10
  #endif
  
  #ifndef WIA_MAX_TEMP_SENS
    #define WIA_MAX_TEMP_SENS 1
  #endif

  #include <OneWire.h>
  #define REQUIRESNEW  true   // Use if you want to minimise code size
  #include <DallasTemperature.h>
  const int max_sensor =  1 + WIA_MAX_TEMP_SENS;

  class TempSensorDS18B20{
    public: 
      TempSensorDS18B20(int pin): oneWire(pin){ }
      bool init(){
        sensor.begin();
        cur_count = sensor.getDeviceCount();
        if(cur_count <= 0) return false;
        if(max_sensor < cur_count)
        cur_count = max_sensor;
        for(int i = 0 ; i < cur_count; i++){
          Serial.print("init::getAddress-"+ String(i));
          Serial.println(String(sensor.getAddress(insideThermometer[i], i)?" success":" fail"));
          Serial.print("init::setResolution-"+String(i));
          Serial.println(String(sensor.setResolution(insideThermometer[i], TEMPERATURE_PRECISION)?"success":"fail"));
        }
        Serial.println("init::Power-Mode"+ String(sensor.isParasitePowerMode()?"Parasite":"External"));
        return true;
        }
      float getTempC(){ return sensor.getTempCByIndex(0); }
      float getTempC(int i){ return sensor.getTempCByIndex(i); }
    private:     
      OneWire oneWire;
      DallasTemperature sensor{&oneWire};
      DeviceAddress insideThermometer[max_sensor];
      int cur_count = 0;
  };

#endif