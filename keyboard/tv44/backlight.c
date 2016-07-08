
#include <avr/io.h>
#include "backlight.h"

uint8_t led_counter = 0;
uint8_t led_level = 0;

void bl_set()
{
	led_counter++;
	if (led_counter > 7) {
		led_counter = 0;
	}

    if (led_counter < led_level) {
        // output high
        DDRB |= (1<<2);
        PORTB |= (1<<2);
    } else {
        // Hi-Z
        DDRB &= ~(1<<2);
        PORTB &= ~(1<<2);
    }
}

void backlight_init_ports()
{
    DDRB &= ~(1<<2);
    PORTB &= ~(1<<2);
    
    backlight_init();
}

void backlight_set(uint8_t level)
{
	led_level = level;
}