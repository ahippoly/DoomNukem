#ifndef PROTO_SPRITE_H
# define PROTO_SPRITE_H

# include "data.h"


SDL_Texture     *load_sprite_bmp(char *str, t_data *d);

//sprite_init_gun.c
t_sprite    sprite_init_ar(t_img *img);
t_sprite    sprite_init_dd(t_img *img);
t_sprite    sprite_init_lmg(t_img *img);
t_sprite    sprite_init_revolver(t_img *img);
t_sprite    sprite_init_ssg(t_img *img);
t_sprite    sprite_init_melee(t_img *img);
void        clean_sprite_gun(t_data *d);
int         load_sprite_gun(t_data *d);
void        init_sprite(t_data *d);

//sprite_init_mob.c
int        load_sprite_mob(t_data *d);

//gun_anim.c
void        sprite_anim_gun(t_data *d);
void        gun_idle_anim(t_data *d);
SDL_Rect    get_gun_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos);

//mob_anim.c
SDL_Rect    get_sprite_mob_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos, int mob_ind);
SDL_Rect    print_mob(SDL_Rect dstdim, int x, int y, int z);
void        mob_idle_anim(t_data *d);
void        mob_anim(t_data *d);
void 		copy_frame_sprite(t_sprite *sprite, SDL_Rect pos_size);


#endif