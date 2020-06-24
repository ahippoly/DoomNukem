#ifndef PROTO_SOUND
# define PROTO_SOUND

#include "data.h"

void    my_audio_callback(void *userdata, Uint8 *stream, int len);
void    init_sound(t_data *d);
int     play_sound(t_data *d, int index);
#endif