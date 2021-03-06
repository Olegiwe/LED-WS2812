#ifndef WS2812_H_
#define WS2812_H_
//--------------------------------------------------
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
//--------------------------------------------------
#define DELAY_LEN 48
#define LED_COUNT 300
#define ARRAY_LEN DELAY_LEN + LED_COUNT*24
#define HIGH 65
#define LOW 26
#define SAFE_LEVEL 32
#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)
typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} Colour;

//--------------------------------------------------
void ws2812_init(void);
void ws2812_pixel_rgb_to_buf_dma(uint8_t Rpixel , uint8_t Gpixel, uint8_t Bpixel, uint16_t posX);
void ws2812_single_led(uint8_t red, uint8_t green, uint8_t blue, uint16_t pos);
void ws2812_all_leds(uint8_t red, uint8_t green, uint8_t blue);
void ws2812_pattern(const Colour* colours, uint16_t chunk);
void ws2812_set_pattern(char* input_line);
void ws2812_light_from_string(char* str);
void ws2812_light_cascade(uint8_t red, uint8_t green, uint8_t blue, uint16_t init_pos, uint16_t number);
void ws2812_light_pattern(char* pattern_line);
#endif /* WS2812_H_ */