#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

static void      init_anim_Zombie2(t_sprite *Zombie)
{
    Zombie->anim[4].pos->x = 2;
    Zombie->anim[4].pos->y = 3; 
    Zombie->anim[4].nb_frame = 3;
    Zombie->anim[4].offset.x = 14;
    Zombie->anim[4].offset.y = 0;
    Zombie->anim[5].pos->x = 2;
    Zombie->anim[5].pos->y = 4; 
    Zombie->anim[5].nb_frame = 4;
    Zombie->anim[5].offset.x = 14;
    Zombie->anim[5].offset.y = 0;
    Zombie->anim[6].pos->x = 0;
    Zombie->anim[6].pos->y = 6; 
    Zombie->anim[6].nb_frame = 4;
    Zombie->anim[6].offset.x = 14;
    Zombie->anim[6].offset.y = 0;
    Zombie->anim[7].pos->x = 1;
    Zombie->anim[7].pos->y = 7; 
    Zombie->anim[7].nb_frame = 4;
    Zombie->anim[7].offset.x = 14;
    Zombie->anim[7].offset.y = 0;
}

static void      init_anim_Zombie(t_sprite *Zombie)
{
    Zombie->anim[0].pos->x = 0;
    Zombie->anim[0].pos->y = 0;
    Zombie->anim[0].nb_frame = 2;
    Zombie->anim[0].offset.x = 14;
    Zombie->anim[0].offset.y = 0;
    Zombie->anim[1].pos->x = 2;
    Zombie->anim[1].pos->y = 0;
    Zombie->anim[1].nb_frame = 2;
    Zombie->anim[1].offset.x = 14;
    Zombie->anim[1].offset.y = 0;
    Zombie->anim[2].pos->x = 1;
    Zombie->anim[2].pos->y = 1; 
    Zombie->anim[2].nb_frame = 2;
    Zombie->anim[2].offset.x = 14;
    Zombie->anim[2].offset.y = 0;
    Zombie->anim[3].pos->x = 0;
    Zombie->anim[3].pos->y = 2; 
    Zombie->anim[3].nb_frame = 5;
    Zombie->anim[3].offset.x = 14;
    Zombie->anim[3].offset.y = 0;
    init_anim_Zombie2(Zombie);
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
    Zombie.nb_anim = 8;
    Zombie.text = text;
    init_anim_Zombie(&Zombie);
    return (Zombie);
}

static void    load_zombies(t_data *d)
{
    int i;

    i = 0;
    while (i < 10)
    {
        d->mob[i].sprite = d->sprite[ZOMBIE];
        d->mob[i].sprite.index = ZOMBIE;
        d->mob[i].life = 100;
        i++;
    }
}

void    load_sprite_mob(t_data *d)
{
    SDL_Texture *texture;
    t_sprite commando;

    texture = NULL;
    texture = load_sprite_bmp("Sprites/Mobs/ZombieScientist.bmp", d);
    d->sprite[ZOMBIE] = sprite_init_Zombie(texture);
    load_zombies(d);
}