#include "tv44.h"
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "progmem.h"

__attribute__ ((weak))
void matrix_init_user(void) {}

__attribute__ ((weak))
void matrix_scan_user(void) {}

__attribute__ ((weak))
void process_action_user(keyrecord_t *record) {}

void matrix_init_kb(void) {
#ifdef BACKLIGHT_ENABLE
	backlight_init_ports();
#endif
	matrix_init_user();
}

void matrix_scan_kb(void) {
	matrix_scan_user();
	bl_set();
}

void process_action_kb(keyrecord_t *record) {
	process_action_user(record);
}
