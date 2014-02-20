// demo of Grove - Led Bar
// this demo will show you how to use setLevel function of this library
// first, you need to choos which io to used. 

#include <LED_Bar.h>
#include <seeed_grove_hal.h>
#include <Streaming.h>

#include <Wire.h>

void setup()
{
    // nothing to initialize
    led_bar_init(9, 8);
    Serial.begin(115200);
}

void loop()
{
    for(int i=0; i<=10; i++)
    {
        led_bar_set_level(i);
        delay(100);
    }
}
