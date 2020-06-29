#include "proto_global.h"

static void      init_anim_lmg2(t_sprite *LMG)
{
    LMG->anim[RELOAD].pos->x = 4;
    LMG->anim[RELOAD].pos->y = 1; 
    LMG->anim[RELOAD].nb_frame = 22;
    LMG->anim[RELOAD].offset.x = 0;
    LMG->anim[RELOAD].offset.y = 32;
    LMG->anim[AIMFIRE].pos->x = 1;
    LMG->anim[AIMFIRE].pos->y = 6; 
    LMG->anim[AIMFIRE].nb_frame = 3;
    LMG->anim[AIMFIRE].offset.x = 0;
    LMG->anim[AIMFIRE].offset.y = 0;
    LMG->anim[ICON].pos->x = 3;
    LMG->anim[ICON].pos->y = 1; 
    LMG->anim[ICON].nb_frame = 1;
    LMG->anim[ICON].offset.x = 0;
    LMG->anim[ICON].offset.y = 0;
}

static void      init_anim_lmg(t_sprite *LMG)
{
    LMG->anim[IDLE].pos->x = 3;
    LMG->anim[IDLE].pos->y = 7;
    LMG->anim[IDLE].nb_frame = 1;    
    LMG->anim[IDLE].offset.x = 0;
    LMG->anim[IDLE].offset.y = 32;
    LMG->anim[FIRE].pos->x = 4;
    LMG->anim[FIRE].pos->y = 6; 
    LMG->anim[FIRE].nb_frame = 3;
    LMG->anim[FIRE].offset.x = 0;
    LMG->anim[FIRE].offset.y = 32;
    LMG->anim[AIM].pos->x = 0;
    LMG->anim[AIM].pos->y = 0; 
    LMG->anim[AIM].nb_frame = 1;
    LMG->anim[AIM].offset.x = 0;
    LMG->anim[AIM].offset.y = 0;
    init_anim_lmg2(LMG);
}

t_sprite    sprite_init_lmg(t_img *img)
{
    t_sprite LMG;

    LMG.size.x = 400;
    LMG.size.y = 400;
    LMG.aim_on = 0;
    LMG.anim_end = 0;
    LMG.time = 0;
    LMG.on = -1;
    LMG.index = 3;
    LMG.total_size.w = 1600;
    LMG.total_size.h = 1600;
    LMG.nb_frame.x = 5;    
    LMG.nb_frame.y = 8;  
    LMG.frame_size.w = LMG.total_size.w / LMG.nb_frame.x;
    LMG.frame_size.h = LMG.total_size.h / LMG.nb_frame.y;
    LMG.idle_frame.x = 0;
    LMG.idle_frame.y = 7;
    LMG.displayed_part.x = 0;
    LMG.displayed_part.y = 0;
    LMG.nb_anim = 7;
    LMG.idle_animation = 2;
    LMG.img = img;
    init_anim_lmg(&LMG);
    return (LMG);
}

static void      init_anim_rev(t_sprite *Rev)
{
    Rev->anim[IDLE].pos->x = 2;
    Rev->anim[IDLE].pos->y = 6; 
    Rev->anim[IDLE].nb_frame = 1;
    Rev->anim[IDLE].offset.x = 0;
    Rev->anim[IDLE].offset.y = 0;
    Rev->anim[FIRE].pos->x = 1;
    Rev->anim[FIRE].pos->y = 2;
    Rev->anim[FIRE].nb_frame = 4;
    Rev->anim[FIRE].offset.x = 0;
    Rev->anim[FIRE].offset.y = 0;
    Rev->anim[AIM].pos->x = 2;
    Rev->anim[AIM].pos->y = 6; 
    Rev->anim[AIM].nb_frame = 1;
    Rev->anim[AIM].offset.x = 0;
    Rev->anim[AIM].offset.y = 0;
    Rev->anim[RELOAD].pos->x = 1;
    Rev->anim[RELOAD].pos->y = 3; 
    Rev->anim[RELOAD].nb_frame = 13;
    Rev->anim[RELOAD].offset.x = 0;
    Rev->anim[RELOAD].offset.y = 0;
    Rev->anim[ALTFIRE].pos->x = 0;
    Rev->anim[ALTFIRE].pos->y = 0;
    Rev->anim[ALTFIRE].nb_frame = 9;  
    Rev->anim[ALTFIRE].offset.x = 0;
    Rev->anim[ALTFIRE].offset.y = 0; 
}

t_sprite    sprite_init_revolver(t_img *img)
{
    t_sprite Rev;

    Rev.size.x = 400;
    Rev.size.y = 300;
    Rev.aim_on = 0;
    Rev.anim_end = 0;
    Rev.time = 0;
    Rev.on = -1;
    Rev.index = 3;
    Rev.total_size.w = 1280;
    Rev.total_size.h = 1176;
    Rev.nb_frame.x = 4;    
    Rev.nb_frame.y = 7;  
    Rev.frame_size.w = Rev.total_size.w / Rev.nb_frame.x;
    Rev.frame_size.h = Rev.total_size.h / Rev.nb_frame.y;
    Rev.idle_frame.x = 0;
    Rev.idle_frame.y = 7;
    Rev.displayed_part.x = 0;
    Rev.displayed_part.y = 0;
    Rev.nb_anim = 5;
    Rev.idle_animation = 3;
    Rev.img = img;
    init_anim_rev(&Rev);
    return (Rev);
}