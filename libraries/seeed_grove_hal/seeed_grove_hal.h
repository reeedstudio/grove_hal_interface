#ifndef __SEEED_GROVE_HAL_H__
#define __SEEED_GROVE_HAL_H__

#include <Arduino.h>

// pin mode
#define HAL_PIN_HIGH    0x1
#define HAL_PIN_LOW     0x0

#define HAL_PIN_INPUT   0x0
#define HAL_PIN_OUTPUT  0x1
#define HAL_PIN_PULLUP  0x2


typedef signed char    int8;
typedef unsigned char  uint8;
typedef signed short   int16;
typedef unsigned short uint16;
typedef signed long    int32;
typedef unsigned long  uint32;


// init
void grove_hal_init();


// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define grove_hal_min(a,b) ((a)<(b)?(a):(b))
#define grove_hal_max(a,b) ((a)>(b)?(a):(b))

#define abs(x) ((x)>0?(x):-(x))


// digital
void grove_hal_pin_mode(int16 pin, int16 mode);
void grove_hal_pin_write(int16 pin, int16 state);
int16 grove_hal_pin_read(int16 pin);

uint16 grove_hal_pulse_in(uint8 pin, uint8 state, uint32 timeout);

// analog
int16 grove_hal_analogRead(int16 pin);


// delay
void grove_hal_delay_us(uint32 us);
void grove_hal_delay_ms(uint32 ms);

uint32 grove_hal_millis();
uint32 grove_hal_micros();


// I2C
void grove_hal_i2c_begin();
bool grove_hal_i2c_write(uint8 dev_addr, uint8 reg_addr, uint8 *data, uint8 len); 
bool grove_hal_i2c_write_one(uint8 dev_addr, uint8 reg_addr, uint8 data);
uint8 grove_hal_i2c_read(uint8 dev_addr, uint8 reg_addr, uint8 *buff, uint8 len);
uint8 grove_hal_i2c_read_one(uint8 dev_addr, uint8 reg_addr, uint8 *dta); 


// UART
typedef enum
{
	BAUD_2400 	= 0,		            // 2400
	BAUD_4800 	= 1,		            // 4800
	BAUD_9600 	= 2,		            // 9600
	BAUD_14400 	= 3,		            // 14400
	BAUD_19200 	= 4,		            // 19200
	BAUD_28800 	= 5,		            // 28800
	BAUD_38400 	= 6,		            // 38400
	BAUD_57600 	= 7,		            // 57600
	BAUD_76800 	= 8,		            // 76800
	BAUD_115200 = 9,		            // 115200
	BAUD_230400 = 10,		            // 230400
}uart_band_t;


void uart_init(uart_band_t Baud);
void uart_send_byte(uint8 data);
void uart_send_data(uint8 *pbuff, int len);						
void uart_send_string(const char *pStr); 													
bool uart_rx_buff_is_full();
uint16 uart_get_rx_cnt();
uint16 uart_read_data(uint8 *dst, int len);
void uart_clear_rx_buff();


// software i2c



#endif