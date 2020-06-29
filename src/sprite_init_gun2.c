#include "proto_global.h"

static void      init_anim_ssg(t_sprite *SSG)
{
    SSG->anim[IDLE].pos->x = 0;
    SSG->anim[IDLE].pos->y = 0;
    SSG->anim[IDLE].nb_frame = 1;
    SSG->anim[IDLE].offset.x = -10;
    SSG->anim[IDLE].offset.y = 0;
    SSG->anim[FIRE].pos->x = 1;
    SSG->anim[FIRE].pos->y = 0; 
    SSG->anim[FIRE].nb_frame = 3;
    SSG->anim[FIRE].offset.x = -10;
    SSG->anim[FIRE].offset.y = 0;
    SSG->anim[RELOAD].pos->x = 4;
    SSG->anim[RELOAD].pos->y = 0; 
    SSG->anim[RELOAD].nb_frame = 18;
    SSG->anim[RELOAD].offset.x = -10;
    SSG->anim[RELOAD].offset.y = 0;
}

t_sprite    sprite_init_ssg(t_img *img)
{
    t_sprite SSG;

    SSG.size.x = 300;
    SSG.size.y = 0;
    SSG.aim_on = 0;
    SSG.anim_end = 0;
    SSG.time = 0;
    SSG.on = -1;
    SSG.index = 3;
    SSG.total_size.w = 1836;
    SSG.total_size.h = 186;
    SSG.nb_frame.x = 12;    
    SSG.nb_frame.y = 2;  
    SSG.frame_size.w = SSG.total_size.w / SSG.nb_frame.x;
    SSG.frame_size.h = SSG.total_size.h / SSG.nb_frame.y;
    SSG.idle_frame.x = 1;
    SSG.idle_frame.y = 0;
    SSG.displayed_part.x = 0;
    SSG.displayed_part.y = 0;
    SSG.nb_anim = 4;
    SSG.idle_animation = 3;
    SSG.img = img;
    init_anim_ssg(&SSG);
    return (SSG);
}

static void      init_anim_melee(t_sprite *Melee)
{
    Melee->anim[IDLE].pos->x = 0;
    Melee->anim[IDLE].pos->y = 0;
    Melee->anim[IDLE].nb_frame = 1;
    Melee->anim[IDLE].offset.x = 0;
    Melee->anim[IDLE].offset.y = 5;
    Melee->anim[FIRE].pos->x = 1;
    Melee->anim[FIRE].pos->y = 0;
    Melee->anim[FIRE].nb_frame = 10;
    Melee->anim[FIRE].offset.x = 0;
    Melee->anim[FIRE].offset.y = 5;
    Melee->anim[RELOAD].pos->x = 0;
    Melee->anim[RELOAD].pos->y = 0;
    Melee->anim[RELOAD].nb_frame = 0;
    Melee->anim[RELOAD].offset.x = 0;
    Melee->anim[RELOAD].offset.y = 5;
}

t_sprite    sprite_init_melee(t_img *img)
{
    t_sprite Melee;

    Melee.size.x = 300;
    Melee.size.y = 100;
    Melee.aim_on = 0;
    Melee.anim_end = 0;
    Melee.time = 0;
    Melee.on = -1;
    Melee.index = 3;
    Melee.total_size.w = 320;
    Melee.total_size.h = 1100;
    Melee.nb_frame.x = 1;    
    Melee.nb_frame.y = 11;  
    Melee.frame_size.w = Melee.total_size.w / Melee.nb_frame.x;
    Melee.frame_size.h = Melee.total_size.h / Melee.nb_frame.y;
    Melee.idle_frame.x = 0;
    Melee.idle_frame.y = 0;
    Melee.displayed_part.x = 0;
    Melee.displayed_part.y = 0;
    Melee.nb_anim = 2;
    Melee.idle_animation = 0;
    Melee.img = img;
    init_anim_melee(&Melee);
    return (Melee);
}