#ifndef PROTO_SOUND
# define PROTO_SOUND

#include "data.h"

void    init_sound(t_data *d);
int     play_sound(t_data *d, int index);
void	stop_sound(t_data *d, int index);

#endif