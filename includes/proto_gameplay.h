#ifndef PROTO_GAMEPLAY
# define PROTO_GAMEPLAY

# include "data.h"

void ref_origin(void *type_list, int nb_type, int type);

void anim_reload(t_data *d);
void reload_weapon(t_data *d, t_weapon *weapon);
void anim_weapon(t_data *d);
void shoot_attempt(t_data *d, t_weapon *weapon);
void aim_gun(t_data *d);
void process_gun(t_weapon *weapon, int time, t_data *d);



#endif