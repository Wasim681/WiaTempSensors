#if defined(WIA_TEMP_SENS_DS18B20) || defined(WIA_TEMP_SENS_AHT20) || defined(WIA_TEMP_SENS_KY013)

  #ifdef WIA_TEMP_SENS_DS18B20

    // make sure you define this MACRO before including library header file there wise it will be consider '0'
    // this value is not fixed in the code ... it will depend upon the memory of the device selected
    // if u want more sensor of type DS18B20 just attach them and increase this count 
    // #define WIA_EXTRA_MAX_TEMP_SENS 0 

    #include "DS18B20.h"

    typedef TempSensorDS18B20 Wia_DS18B20;

    #ifndef TEMP_SENS
      #define TEMP_SENS
      typedef TempSensorDS18B20 TempSens;
    #endif
  #endif
  #ifdef WIA_TEMP_SENS_AHT20
    #include "AHT20.h"
    
    typedef TempSensorAHT20 Wia_AHT20;

    #ifndef TEMP_SENS
      #define TEMP_SENS
      typedef TempSensorAHT20 TempSens;
    #endif
  #endif
  #ifdef WIA_TEMP_SENS_KY013
    #include "KY013.h"
    
    typedef TempSensorKY013 Wia_KY013;
    
    #ifndef TEMP_SENS
      #define TEMP_SENS
      typedef TempSensorKY013 TempSens;
    #endif
  #endif
  
  class TemperatureConverter{
    public:
      
      /*
        @return: temperature in Kelvin
        @param temp: temperature value to convert
        @param isFahrenheit: Set to true if 'temp' is in Fahrenheit, false if in Celsius. 
      */
      static float toKelvin (float temp, bool isFahrenheit) { return (isFahrenheit?TemperatureConverter::toCelsius(temp, true):temp) + 273.15; }
      
      /*
        @return: temperature in Celsius
        @param temp: temperature value to convert
        @param isFahrenheit: Set to true if 'temp' is in Fahrenheit, false if in Kelvin. 
      */
      static float toCelsius(float temp, bool isFahrenheit) { return (isFahrenheit? ((temp - 32) * 5/9) : (temp - 273.15)); }
      
      /*
        @return: temperature in Fahrenheit
        @param temp: temperature value to convert
        @param isFahrenheit: Set to true if 'temp' is in Kelvin, false if in Celsius. 
      */
      static float toFahrenheit(float temp, bool isKelvin) { return ((isKelvin ? (temp - 273.15) : temp) * 9/5) + 32; } 
  }; 


#else 
  #error Make sure you define a temprature sensor[WIA_TEMP_SENS_DS18B20, WIA_TEMP_SENS_AHT20, WIA_TEMP_SENS_KY013] before '#include <TempSensor.h>' 
#endif