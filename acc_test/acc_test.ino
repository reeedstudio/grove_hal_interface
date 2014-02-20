#include <seeed_grove_hal.h>
#include <Wire.h>
#include <Streaming.h>

#include "grove_acc_adxl345.h"


void setup()
{
    Serial.begin(115200);
    cout << "hello world" << endl;
    
    acc_adxl345_init();
}


void loop()
{
    float x, y, z;
    
    acc_adxl345_read_acc(&x, &y, &z);
    
    cout << x << '\t' << y << '\t' << z << endl;
    delay(100);
}