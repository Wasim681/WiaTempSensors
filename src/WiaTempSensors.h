#if defined(WIA_TEMP_SENS_DS18B20) || defined(WIA_TEMP_SENS_AHT20) || defined(WIA_TEMP_SENS_KY013)

  #ifdef WIA_TEMP_SENS_DS18B20
  
    // #define WIA_MAX_TEMP_SENS 1

    #include "DS18B20.h"
    typedef TempSensorDS18B20 Wia_DS18B20;
    #ifndef DS18B20
    typedef TempSensorDS18B20 DS18B20;
    #endif
  #endif
  #ifdef WIA_TEMP_SENS_AHT20
    #include "AHT20.h"
    typedef TempSensorAHT20 Wia_AHT20;
    #ifndef AHT20
    typedef TempSensorAHT20 AHT20;
    #endif
  #endif
  #ifdef WIA_TEMP_SENS_KY013
    #include "KY013.h"
    typedef TempSensorKY013 Wia_KY013;
    #ifndef KY013
    typedef TempSensorKY013 KY013;
    #endif
  #endif
  
#else 
  #error Make sure you define a temprature sensor[WIA_TEMP_SENS_DS18B20, WIA_TEMP_SENS_AHT20, WIA_TEMP_SENS_KY013] before '#include <TempSensor.h>' 
#endif