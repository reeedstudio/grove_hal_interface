// seeedstudio grove hal.cpp for Arduino 

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <seeed_grove_hal.h>

// init
void grove_hal_init()
{
    // nothing to init
}


// digital
void grove_hal_pin_mode(int16 pin, int16 mode)
{
    pinMode(pin, mode);
}

void grove_hal_pin_write(int16 pin, int16 state)
{
    digitalWrite(pin, state);
}

int16 grove_hal_pin_read(int16 pin)
{
    return digitalRead(pin);
}

uint16 grove_hal_pulse_in(uint8 pin, uint8 state, uint32 timeout)
{
    pulseIn(pin, state, timeout);
}

// analog
int16 grove_hal_analogRead(int16 pin)
{
    return analogRead(pin);
}

// delay
void grove_hal_delay_us(uint32 us)
{
    delayMicroseconds(us);
}

void grove_hal_delay_ms(uint32 ms)
{
    delay(ms);
}

uint32 grove_hal_millis()
{
    return millis();
}

uint32 grove_hal_micros()
{
    return micros();
}

// I2C
void grove_hal_i2c_begin()
{
    Wire.begin();
}

bool grove_hal_i2c_write(uint8 dev_addr, uint8 reg_addr, uint8 *data, uint8 len)
{
    Wire.beginTransmission(dev_addr);
    Wire.write(reg_addr);
    for(int i=0; i<len; i++)
    {
        Wire.write(data[i]);
    }
    Wire.endTransmission();
}

bool grove_hal_i2c_write_one(uint8 dev_addr, uint8 reg_addr, uint8 data)
{
    grove_hal_i2c_write(dev_addr, reg_addr, &data, 1);
    
    return 1;
}

uint8 grove_hal_i2c_read(uint8 dev_addr, uint8 reg_addr, uint8 *buff, uint8 len)
{
    Wire.beginTransmission(dev_addr);
    Wire.write(reg_addr);
    Wire.endTransmission();
    
    Wire.beginTransmission(dev_addr);         // start transmission to device
    Wire.requestFrom(dev_addr, len);
    
    int index = 0;
    while(Wire.available())
    {
        buff[index++] = Wire.read();
    }
    
    Wire.endTransmission();
    
    return index;
}

uint8 grove_hal_i2c_read_one(uint8 dev_addr, uint8 reg_addr, uint8 *dta)
{
    return grove_hal_i2c_read(dev_addr, reg_addr, dta, 1);    
}

// UART
void uart_init(uart_band_t Baud){}
void uart_send_byte(uint8 data){}
void uart_send_data(uint8 *pbuff, int len){}					
void uart_send_string(const char *pStr){}												
bool uart_rx_buff_is_full(){return 0;}
uint16 uart_get_rx_cnt(){return 0;}
uint16 uart_read_data(uint8 *dst, int len){return 0;}
void uart_clear_rx_buff(){}
