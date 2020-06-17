#ifndef SPRITE_H
# define SPRITE_H

# define IDLE 0
# define FIRE 1
# define AIM 2
# define RELOAD 3
# define AIMFIRE 4
# define ICON 5
# define ALTFIRE 6

# define ZOMBIE 10


SDL_Texture     *load_sprite_bmp(char *str, t_data *d);

//sprite_init_gun.c
t_sprite    sprite_init_AR(SDL_Texture *text);
t_sprite    sprite_init_DD(SDL_Texture *text);
t_sprite    sprite_init_LMG(SDL_Texture *text);
t_sprite    sprite_init_Revolver(SDL_Texture *text);
t_sprite    sprite_init_SSG(SDL_Texture *text);
t_sprite    sprite_init_Melee(SDL_Texture *text);
void        load_sprite_gun(t_data *d);

//sprite_init_mob.c
void        load_sprite_mob(t_data *d);
t_sprite    sprite_init_Zombie(SDL_Texture *text);

//gun_anim.c
void        sprite_anim_gun(t_data *d);
void        gun_idle_anim(t_data *d);
SDL_Rect    get_gun_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos);

//mob_anim.c
SDL_Rect    get_sprite_mob_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos);
SDL_Rect    print_mob(SDL_Rect dstdim, int x, int y, int z);
void        mob_idle_anim(t_data *d);
void        mob_anim(t_data *d);

#endif