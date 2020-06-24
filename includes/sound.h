#ifndef SOUND_H
# define SOUND_H

#include "render.h"

#define MUS_PATH1 "Sound/Music/Urdak.wav"

#define ARLONG_PATH "Sound/Guns/ARlong.wav"
#define ARSHORT_PATH "Sound/Guns/ARshort.wav"
#define ARRELOAD_PATH "Sound/Guns/ARReload.wav"
#define DDLONG_PATH "Sound/Guns/DDlong.wav"
#define DDSHORT_PATH "Sound/Guns/DDshort.wav"
#define LMGLONG_PATH "Sound/Guns/LMGlong.wav"
#define LMGSHORT_PATH "Sound/Guns/LMGshort.wav"
#define LMGRELOAD_PATH "Sound/Guns/LMGReload.wav"
#define REVSHORT_PATH "Sound/Guns/Revshort.wav"
#define REVRELOAD_PATH "Sound/Guns/RevReload.wav"
#define MELEESHORT_PATH "Sound/Guns/Meleeattack.wav"
#define SHOTGUNSHORT_PATH "Sound/Guns/Shotgunshot.wav"
#define SHOTGUNRELOAD_PATH "Sound/Guns/ShotungReload.wav"

#define MELEESHORT 0
#define REVSHORT 1
#define SHOTGUNSHORT 2
#define ARLONG 3
#define LMGLONG 4
#define DDLONG 5

#define REVRELOAD 6
#define SHOTGUNRELOAD 7
#define ARRELOAD 8
#define LMGRELOAD 9


#define ARSHORT 13
#define LMGSHORT 14
#define DDSHORT 15

# define MUS1 16

void    my_audio_callback(void *userdata, Uint8 *stream, int len);
void    init_sound(t_data *d);
int     play_sound(t_data *d, int index);
#endif