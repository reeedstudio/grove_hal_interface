
#include <Wire.h>
#include <Streaming.h>

#include <grove_acc_adxl345_arduino.h>
#include <grove_acc_adxl345.h>

ACC_ADXL345 acc;


void setup()
{
    Serial.begin(115200);
    cout << "hello world" << endl;
    
    acc.begin();
    
}


void loop()
{
    float x, y, z;
    acc.getAcc(&x, &y, &z);
    
    cout << x << '\t' << y << '\t' << z << endl;
    
    delay(100);
}

