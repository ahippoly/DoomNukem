#include "proto_global.h"

static void      init_anim_ar2(t_sprite *AR)
{
    AR->anim[RELOAD].pos->x = 2;
    AR->anim[RELOAD].pos->y = 1;   
    AR->anim[RELOAD].nb_frame = 24;
    AR->anim[RELOAD].offset.x = 0;
    AR->anim[RELOAD].offset.y = 12;
    AR->anim[AIMFIRE].pos->x = 0;
    AR->anim[AIMFIRE].pos->y = 0;   
    AR->anim[AIMFIRE].nb_frame = 2;
    AR->anim[AIMFIRE].offset.x = 0;
    AR->anim[AIMFIRE].offset.y = 12;
    AR->anim[ICON].pos->x = 2;
    AR->anim[ICON].pos->y = 7;   
    AR->anim[ICON].nb_frame = 1;
    AR->anim[ICON].offset.x = 0;
    AR->anim[ICON].offset.y = 0;
}

static void      init_anim_ar(t_sprite *AR)
{
    AR->anim[IDLE].pos->x = 3;
    AR->anim[IDLE].pos->y = 0;
    AR->anim[IDLE].nb_frame = 1;
    AR->anim[IDLE].offset.x = 0;
    AR->anim[IDLE].offset.y = 12;
    AR->anim[FIRE].pos->x = 2;
    AR->anim[FIRE].pos->y = 0;
    AR->anim[FIRE].nb_frame = 3;
    AR->anim[FIRE].offset.x = 0;
    AR->anim[FIRE].offset.y = 12;
    AR->anim[AIM].pos->x = 1;
    AR->anim[AIM].pos->y = 0; 
    AR->anim[AIM].nb_frame = 1;
    AR->anim[AIM].offset.x = 0;
    AR->anim[AIM].offset.y = 12;
    init_anim_ar2(AR);
}

t_sprite    sprite_init_ar(t_img *img)
{
    t_sprite AR;

    AR.size.x = 400;
    AR.size.y = 400;
    AR.aim_on = 0;
    AR.anim_end = 0;
    AR.time = 0;
    AR.on = -1;
    AR.index = 1;
    AR.total_size.w = 1280;
    AR.total_size.h = 1440;
    AR.nb_frame.x = 4;    
    AR.nb_frame.y = 8;  
    AR.frame_size.w = AR.total_size.w / AR.nb_frame.x;
    AR.frame_size.h = AR.total_size.h / AR.nb_frame.y;
    AR.idle_frame.x = 3;
    AR.idle_frame.y = 0;
    AR.displayed_part.x = 0;
    AR.displayed_part.y = 0;
    AR.nb_anim = 4;
    AR.idle_animation = 3;
    AR.img = img;
    init_anim_ar(&AR);
    return (AR);
}

static void      init_anim_dd(t_sprite *DD)
{
    DD->anim[IDLE].pos->x = 3;
    DD->anim[IDLE].pos->y = 0;
    DD->anim[IDLE].nb_frame = 1;
    DD->anim[IDLE].offset.x = 0;
    DD->anim[IDLE].offset.y = 0;
    DD->anim[FIRE].pos->x = 0;
    DD->anim[FIRE].pos->y = 0;
    DD->anim[FIRE].nb_frame = 7;
    DD->anim[FIRE].offset.x = 0;
    DD->anim[FIRE].offset.y = 0;
    DD->anim[AIM].pos->x = 1;
    DD->anim[AIM].pos->y = 2; 
    DD->anim[AIM].nb_frame = 4;
    DD->anim[AIM].offset.x = 0;
    DD->anim[AIM].offset.y = 0;
    DD->anim[ICON].pos->x = 0;
    DD->anim[ICON].pos->y = 2;
    DD->anim[ICON].nb_frame = 1;
    DD->anim[ICON].offset.x = 0;
    DD->anim[ICON].offset.y = 0;
}

t_sprite    sprite_init_dd(t_img *img)
{
    t_sprite DD;

    DD.size.x = 300;
    DD.size.y = 0;
    DD.aim_on = 0;
    DD.anim_end = 0;
    DD.time = 0;
    DD.on = -1;
    DD.index = 2;
    DD.total_size.w = 1085;
    DD.total_size.h = 378;
    DD.nb_frame.x = 5;    
    DD.nb_frame.y = 3;  
    DD.frame_size.w = DD.total_size.w / DD.nb_frame.x;
    DD.frame_size.h = DD.total_size.h / DD.nb_frame.y;
    DD.idle_frame.x = 3;
    DD.idle_frame.y = 2;
    DD.displayed_part.x = 0;
    DD.displayed_part.y = 0;
    DD.nb_anim = 3;
    DD.idle_animation = 2;
    DD.img = img;
    init_anim_dd(&DD);
    return (DD);
}