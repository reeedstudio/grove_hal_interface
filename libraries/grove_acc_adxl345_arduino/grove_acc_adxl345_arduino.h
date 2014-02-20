#ifndef __GROVE_ACC_ADXL345_ARDUINO_H__
#define __GROVE_ACC_ADXL345_ARDUINO_H__

#include <Arduino.h>
#include <Wire.h>
#include <seeed_grove_hal.h>

#include <grove_acc_adxl345.h>

class ACC_ADXL345{

public:

    void begin()
    {
        acc_adxl345_init();
        
       // Serial.println(ADXL345_INT1_PIN);
    }
    
    void getAcc(float *ax, float *ay, float *az)
    {
        //acc_adxl345_read_acc(ax, ay, az);
    }
    
    void getAcc(double *xyz)
    {
        //getAcceleration(xyz);
    }

};


#endif