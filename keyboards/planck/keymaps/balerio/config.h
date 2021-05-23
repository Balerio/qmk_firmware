#pragma once
#include "../../config.h"


#define ZELDA_PUZZLE_2  \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),

#define ZELDA_CHEST \
    Q__NOTE(_G5),     \
    Q__NOTE(_A5),    \
    Q__NOTE(_B5),     \
    Q__NOTE(_CS6),    \
    Q__NOTE(_G5),     \
    Q__NOTE(_A5),    \
    Q__NOTE(_B5),     \
    Q__NOTE(_CS6),    \
    Q__NOTE(_GS5),     \
    Q__NOTE(_AS5),     \
    Q__NOTE(_C6),     \
    Q__NOTE(_D6),  \
	Q__NOTE(_GS5),     \
    Q__NOTE(_AS5),     \
    Q__NOTE(_C6),     \
    Q__NOTE(_D6), \
	Q__NOTE(_A5),    \
    Q__NOTE(_B5),     \
    Q__NOTE(_CS6),    \
	Q__NOTE(_DS6),  \
	Q__NOTE(_A5),    \
    Q__NOTE(_B5),     \
    Q__NOTE(_CS6),    \
	Q__NOTE(_DS6),  \
	Q__NOTE(_AS5),    \
    Q__NOTE(_C6),     \
    Q__NOTE(_D6),    \
	Q__NOTE(_E6),  \
	Q__NOTE(_AS5),    \
    Q__NOTE(_C6),     \
    Q__NOTE(_D6),    \
	Q__NOTE(_E6),  \
	Q__NOTE(_B5),    \
    Q__NOTE(_CS6),     \
    Q__NOTE(_DS6),    \
	Q__NOTE(_F6),  \
	Q__NOTE(_C6),    \
    Q__NOTE(_D6),     \
    Q__NOTE(_E6),    \
	Q__NOTE(_FS6),  \
	Q__NOTE(_CS6),    \
    Q__NOTE(_DS6),     \
    Q__NOTE(_F6),    \
	Q__NOTE(_G6),  \
    Q__NOTE(_D6),     \
    Q__NOTE(_E6),    \
	Q__NOTE(_FS6),  \
	Q__NOTE(_GS6),  \
	S__NOTE(_REST),   \
	Q__NOTE(_A6),  \
    Q__NOTE(_AS6),     \
    Q__NOTE(_B6),    \
	HD_NOTE(_C7),

#define SONIC_RING_2 \
    E__NOTE(_E6),  \
    E__NOTE(_G6),  \
    HD_NOTE(_C7)

//#define STARTUP_SONG SONG(SONIC_RING_2)
// #define STARTUP_SONG SONG(PLANCK_SOUND)
#define STARTUP_SONG SONG(ZELDA_PUZZLE_2)
// #define STARTUP_SONG SONG(NO_SOUND)

#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                SONG(COLEMAK_SOUND), \
                                SONG(DVORAK_SOUND) \
                            }


    //#define AUDIO_CLICKY

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 2

