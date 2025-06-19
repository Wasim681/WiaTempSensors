#ifndef WIA_CLASS_TEMP_SENS_KY013
  #define WIA_CLASS_TEMP_SENS_KY013

  class TempSensorKY013{
    public: 
      TempSensorKY013(int analogPin): _pin(analogPin){ }
      bool init(){
        if(_pin == -1) return false;
          pinMode(_pin, INPUT);
          return true;
        }
      float getTempC(){ 
        int Vo = analogRead(_pin);
        float R2 = R1 * (1023.0 / (float)Vo - 1.0); // Calculate resistance of the thermistor
        float logR2 = log(R2);
        float T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // Calculate temperature in Kelvin
        T = T - 273.15; // Convert Kelvin to Celsius
        return T; }
    private:     
      float R1 = 10000;
      float c1 = 0.001129148;
      float c2 = 0.000234125;
      float c3 = 0.0000000876741;
      int _pin = -1;
  };

#endif