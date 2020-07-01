#include "proto_global.h"

static void      init_anim_ar2(t_sprite *sprite)
{
    sprite->anim[RELOAD].pos->x = 2;
    sprite->anim[RELOAD].pos->y = 1;   
    sprite->anim[RELOAD].nb_frame = 24;
    sprite->anim[RELOAD].offset.x = 0;
    sprite->anim[RELOAD].offset.y = 12;
    sprite->anim[AIMFIRE].pos->x = 0;
    sprite->anim[AIMFIRE].pos->y = 0;   
    sprite->anim[AIMFIRE].nb_frame = 2;
    sprite->anim[AIMFIRE].offset.x = 0;
    sprite->anim[AIMFIRE].offset.y = 12;
    sprite->anim[ICON].pos->x = 2;
    sprite->anim[ICON].pos->y = 7;   
    sprite->anim[ICON].nb_frame = 1;
    sprite->anim[ICON].offset.x = 0;
    sprite->anim[ICON].offset.y = 0;
}

static void      init_anim_ar(t_sprite *sprite)
{
    sprite->anim[IDLE].pos->x = 3;
    sprite->anim[IDLE].pos->y = 0;
    sprite->anim[IDLE].nb_frame = 1;
    sprite->anim[IDLE].offset.x = 0;
    sprite->anim[IDLE].offset.y = 12;
    sprite->anim[FIRE].pos->x = 2;
    sprite->anim[FIRE].pos->y = 0;
    sprite->anim[FIRE].nb_frame = 3;
    sprite->anim[FIRE].offset.x = 0;
    sprite->anim[FIRE].offset.y = 12;
    sprite->anim[AIM].pos->x = 1;
    sprite->anim[AIM].pos->y = 0; 
    sprite->anim[AIM].nb_frame = 1;
    sprite->anim[AIM].offset.x = 0;
    sprite->anim[AIM].offset.y = 12;
    init_anim_ar2(sprite);
}

t_sprite    sprite_init_ar(SDL_Texture *text)
{
    t_sprite sprite;

    sprite.size.x = 400;
    sprite.size.y = 400;
    sprite.aim_on = 0;
    sprite.anim_end = 0;
    sprite.time = 0;
    sprite.on = -1;
    sprite.index = 1;
    sprite.total_size.w = 1280;
    sprite.total_size.h = 1440;
    sprite.nb_frame.x = 4;    
    sprite.nb_frame.y = 8;  
    sprite.frame_size.w = sprite.total_size.w / sprite.nb_frame.x;
    sprite.frame_size.h = sprite.total_size.h / sprite.nb_frame.y;
    sprite.idle_frame.x = 3;
    sprite.idle_frame.y = 0;
    sprite.displayed_part.x = 0;
    sprite.displayed_part.y = 0;
    sprite.nb_anim = 4;
    sprite.idle_animation = 3;
    sprite.text = text;
    init_anim_ar(&sprite);
    return (sprite);
}

static void      init_anim_dd(t_sprite *sprite)
{
    sprite->anim[IDLE].pos->x = 3;
    sprite->anim[IDLE].pos->y = 0;
    sprite->anim[IDLE].nb_frame = 1;
    sprite->anim[IDLE].offset.x = 0;
    sprite->anim[IDLE].offset.y = 0;
    sprite->anim[FIRE].pos->x = 0;
    sprite->anim[FIRE].pos->y = 0;
    sprite->anim[FIRE].nb_frame = 7;
    sprite->anim[FIRE].offset.x = 0;
    sprite->anim[FIRE].offset.y = 0;
    sprite->anim[AIM].pos->x = 1;
    sprite->anim[AIM].pos->y = 2; 
    sprite->anim[AIM].nb_frame = 4;
    sprite->anim[AIM].offset.x = 0;
    sprite->anim[AIM].offset.y = 0;
    sprite->anim[ICON].pos->x = 0;
    sprite->anim[ICON].pos->y = 2;
    sprite->anim[ICON].nb_frame = 1;
    sprite->anim[ICON].offset.x = 0;
    sprite->anim[ICON].offset.y = 0;
}

t_sprite    sprite_init_dd(SDL_Texture *text)
{
    t_sprite sprite;

    sprite.size.x = 300;
    sprite.size.y = 0;
    sprite.aim_on = 0;
    sprite.anim_end = 0;
    sprite.time = 0;
    sprite.on = -1;
    sprite.index = 2;
    sprite.total_size.w = 1085;
    sprite.total_size.h = 378;
    sprite.nb_frame.x = 5;    
    sprite.nb_frame.y = 3;  
    sprite.frame_size.w = sprite.total_size.w / sprite.nb_frame.x;
    sprite.frame_size.h = sprite.total_size.h / sprite.nb_frame.y;
    sprite.idle_frame.x = 3;
    sprite.idle_frame.y = 2;
    sprite.displayed_part.x = 0;
    sprite.displayed_part.y = 0;
    sprite.nb_anim = 3;
    sprite.idle_animation = 2;
    sprite.text = text;
    init_anim_dd(&sprite);
    return (sprite);
}