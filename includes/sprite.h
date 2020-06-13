#ifndef SPRITE_H
# define SPRITE_H

# define IDLE 0
# define FIRE 1
# define AIM 2
# define RELOAD 3
# define AIMFIRE 4
# define ICON 5
# define ALTFIRE 6

t_sprite    sprite_init_AR(SDL_Texture *text);
t_sprite    sprite_init_DD(SDL_Texture *text);
t_sprite    sprite_init_LMG(SDL_Texture *text);
t_sprite    sprite_init_Revolver(SDL_Texture *text);
t_sprite    sprite_init_SSG(SDL_Texture *text);
t_sprite    sprite_init_Melee(SDL_Texture *text);
t_sprite    sprite_init_Zombie(SDL_Texture *text);
void        load_sprite_mob(t_data *d);
void        load_sprite_gun(t_data *d);
SDL_Texture     *load_sprite_bmp(char *str, t_data *d);


#endif