#include "proto_global.h"

static void      init_anim_ssg(t_sprite *sprite)
{
    sprite->anim[IDLE].pos->x = 0;
    sprite->anim[IDLE].pos->y = 0;
    sprite->anim[IDLE].nb_frame = 1;
    sprite->anim[IDLE].offset.x = -10;
    sprite->anim[IDLE].offset.y = 0;
    sprite->anim[FIRE].pos->x = 1;
    sprite->anim[FIRE].pos->y = 0; 
    sprite->anim[FIRE].nb_frame = 3;
    sprite->anim[FIRE].offset.x = -10;
    sprite->anim[FIRE].offset.y = 0;
    sprite->anim[RELOAD].pos->x = 4;
    sprite->anim[RELOAD].pos->y = 0; 
    sprite->anim[RELOAD].nb_frame = 18;
    sprite->anim[RELOAD].offset.x = -10;
    sprite->anim[RELOAD].offset.y = 0;
}

t_sprite    sprite_init_ssg(SDL_Texture *text)
{
    t_sprite sprite;

    sprite.size.x = 300;
    sprite.size.y = 0;
    sprite.aim_on = 0;
    sprite.anim_end = 0;
    sprite.time = 0;
    sprite.on = -1;
    sprite.index = 3;
    sprite.total_size.w = 1836;
    sprite.total_size.h = 186;
    sprite.nb_frame.x = 12;    
    sprite.nb_frame.y = 2;  
    sprite.frame_size.w = sprite.total_size.w / sprite.nb_frame.x;
    sprite.frame_size.h = sprite.total_size.h / sprite.nb_frame.y;
    sprite.idle_frame.x = 1;
    sprite.idle_frame.y = 0;
    sprite.displayed_part.x = 0;
    sprite.displayed_part.y = 0;
    sprite.nb_anim = 4;
    sprite.idle_animation = 3;
    sprite.text = text;
    init_anim_ssg(&sprite);
    return (sprite);
}

static void      init_anim_melee(t_sprite *sprite)
{
    sprite->anim[IDLE].pos->x = 0;
    sprite->anim[IDLE].pos->y = 0;
    sprite->anim[IDLE].nb_frame = 1;
    sprite->anim[IDLE].offset.x = 0;
    sprite->anim[IDLE].offset.y = 5;
    sprite->anim[FIRE].pos->x = 1;
    sprite->anim[FIRE].pos->y = 0;
    sprite->anim[FIRE].nb_frame = 10;
    sprite->anim[FIRE].offset.x = 0;
    sprite->anim[FIRE].offset.y = 5;
    sprite->anim[RELOAD].pos->x = 0;
    sprite->anim[RELOAD].pos->y = 0;
    sprite->anim[RELOAD].nb_frame = 0;
    sprite->anim[RELOAD].offset.x = 0;
    sprite->anim[RELOAD].offset.y = 5;
}

t_sprite    sprite_init_melee(SDL_Texture *text)
{
    t_sprite sprite;

    sprite.size.x = 300;
    sprite.size.y = 100;
    sprite.aim_on = 0;
    sprite.anim_end = 0;
    sprite.time = 0;
    sprite.on = -1;
    sprite.index = 3;
    sprite.total_size.w = 320;
    sprite.total_size.h = 1100;
    sprite.nb_frame.x = 1;    
    sprite.nb_frame.y = 11;  
    sprite.frame_size.w = sprite.total_size.w / sprite.nb_frame.x;
    sprite.frame_size.h = sprite.total_size.h / sprite.nb_frame.y;
    sprite.idle_frame.x = 0;
    sprite.idle_frame.y = 0;
    sprite.displayed_part.x = 0;
    sprite.displayed_part.y = 0;
    sprite.nb_anim = 2;
    sprite.idle_animation = 0;
    sprite.text = text;
    init_anim_melee(&sprite);
    return (sprite);
}