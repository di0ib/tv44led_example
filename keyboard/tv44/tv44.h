#ifndef TV44_H
#define TV44_H

#include "matrix.h"
#include "keymap_common.h"
#ifdef BACKLIGHT_ENABLE
	#include "backlight.h"
#endif
#ifdef RGBLIGHT_ENABLE
  #include "rgblight1.h"
#endif
#include <stddef.h>
#ifdef MIDI_ENABLE
	#include <keymap_midi.h>
#endif

void matrix_init_user(void);
void matrix_scan_user(void);
void process_action_user(keyrecord_t *record);

#endif
