#ifndef PROTO_SSPRITE_H
# define PROTO_SSPRITE_H

# include "data.h"

void init_sprites_img(t_data *d);
void init_sprites_img_env(t_env *e);
void init_anim_range_x(t_ssprite *sprite, t_anim *anim, SDL_Point start, int nb_frame);
void copy_frame_ssprite(t_ssprite *sprite, SDL_Point pos_anim);
void init_curr_frames(t_ssprite *sprite);
static void      init_anim_afrit2(t_ssprite *afrit);
t_ssprite    sprite_init_afrit2(t_img src_img);
void load_anim(t_ssprite *sprite, int time, int anim_id);
void process_anim(t_ssprite *sprite, int time);
void process_mobs_anim(t_data *d);
void set_sprite_callback(t_ssprite *sprite, void *(*funct)(void *), void *param);




#endif