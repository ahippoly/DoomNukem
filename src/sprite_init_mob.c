#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

void      init_anim_Zombie(t_sprite *Zombie)
{
    int i;

    Zombie->anim[0].pos->x = 0;
    Zombie->anim[0].pos->y = 0;
    Zombie->anim[0].nb_frame = 2;
    Zombie->anim[1].pos->x = 2;
    Zombie->anim[1].pos->y = 0;
    Zombie->anim[1].nb_frame = 2;
    Zombie->anim[2].pos->x = 1;
    Zombie->anim[2].pos->y = 1; 
    Zombie->anim[2].nb_frame = 2;
    Zombie->anim[3].pos->x = 0;
    Zombie->anim[3].pos->y = 2; 
    Zombie->anim[3].nb_frame = 5;
    Zombie->anim[4].pos->x = 2;
    Zombie->anim[4].pos->y = 3; 
    Zombie->anim[4].nb_frame = 3;
    Zombie->anim[5].pos->x = 2;
    Zombie->anim[5].pos->y = 4; 
    Zombie->anim[5].nb_frame = 4;
    Zombie->anim[6].pos->x = 0;
    Zombie->anim[6].pos->y = 6; 
    Zombie->anim[6].nb_frame = 4;
    Zombie->anim[7].pos->x = 1;
    Zombie->anim[7].pos->y = 7; 
    Zombie->anim[7].nb_frame = 4;
}

t_sprite    sprite_init_Zombie(SDL_Texture *text)
{
    t_sprite Zombie;

    Zombie.index = 3;

    Zombie.total_size.w = 180;
    Zombie.total_size.h = 504;

    Zombie.nb_frame.x = 3;    
    Zombie.nb_frame.y = 9;  

    Zombie.frame_size.w = Zombie.total_size.w / Zombie.nb_frame.x;
    Zombie.frame_size.h = Zombie.total_size.h / Zombie.nb_frame.y;

    Zombie.idle_frame.x = 1;
    Zombie.idle_frame.y = 0;

    Zombie.displayed_part.x = 0;
    Zombie.displayed_part.y = 0;

    Zombie.nb_anim = 8;

    Zombie.idle_animation = 7;

    Zombie.text = text;
    init_anim_Zombie(&Zombie);
    return (Zombie);
}

void    load_sprite_mob(t_data *d)
{
    SDL_Texture *texture;
    t_sprite commando;

    texture = NULL;
    texture = load_sprite_bmp("Sprites/Mobs/ZombieScientist.bmp", d);
    d->sprite[10] = sprite_init_Zombie(texture);
    texture = NULL;
    texture = load_sprite_bmp("Sprites/Mobs/ZombieScientist.bmp", d);
    d->sprite[10] = sprite_init_Zombie(texture);
}