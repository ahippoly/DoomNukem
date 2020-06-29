#ifndef PROTO_SPRITE_H
# define PROTO_SPRITE_H

# include "data.h"


SDL_Texture     *load_sprite_bmp(char *str, t_data *d);

//sprite_init_gun.c
t_sprite    sprite_init_AR(t_img *img);
t_sprite    sprite_init_DD(t_img *img);
t_sprite    sprite_init_LMG(t_img *img);
t_sprite    sprite_init_Revolver(t_img *img);
t_sprite    sprite_init_SSG(t_img *img);
t_sprite    sprite_init_Melee(t_img *img);
void        load_sprite_gun(t_data *d);

//sprite_init_mob.c
void        load_sprite_mob(t_data *d);
t_sprite    sprite_init_Zombie(t_img *img);

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