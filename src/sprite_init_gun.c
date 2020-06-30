#include "proto_global.h"


static void      init_anim_AR(t_sprite *AR)
{
    int i;

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

t_sprite    sprite_init_AR(t_img img)
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
    init_anim_AR(&AR);
    return (AR);
}

static void      init_anim_DD(t_sprite *DD)
{
    int i;
    
    DD->anim[IDLE].pos->x = 4;
    DD->anim[IDLE].pos->y = 1;
    DD->anim[IDLE].nb_frame = 1;
    DD->anim[IDLE].offset.x = 0;
    DD->anim[IDLE].offset.y = 0;
    DD->anim[FIRE].pos->x = 0;
    DD->anim[FIRE].pos->y = 0;
    DD->anim[FIRE].nb_frame = 10;
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

t_sprite    sprite_init_DD(t_img img)
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
    init_anim_DD(&DD);
    return (DD);
}

static void      init_anim_LMG(t_sprite *LMG)
{
    int i;

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

t_sprite    sprite_init_LMG(t_img img)
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
    init_anim_LMG(&LMG);
    return (LMG);
}

static void      init_anim_Rev(t_sprite *Rev)
{
    int i;
 
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

t_sprite    sprite_init_Revolver(t_img img)
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
    init_anim_Rev(&Rev);
    return (Rev);
}

static void      init_anim_SSG(t_sprite *SSG)
{
    int i;


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

t_sprite    sprite_init_SSG(t_img img)
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
    init_anim_SSG(&SSG);
    return (SSG);
}

static void      init_anim_Melee(t_sprite *Melee)
{
    int i;

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

t_sprite    sprite_init_Melee(t_img img)
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
    init_anim_Melee(&Melee);
    return (Melee);
}


void    load_sprite_gun(t_data *d)
{

    d->sprite[0] = sprite_init_Melee(ft_load_bmp2(SPRITE_PATH_0));

    d->sprite[1] = sprite_init_Revolver(ft_load_bmp2(SPRITE_PATH_1));


    d->sprite[2] = sprite_init_SSG(ft_load_bmp2(SPRITE_PATH_2));


    d->sprite[3] = sprite_init_AR(ft_load_bmp2(SPRITE_PATH_3));

    d->sprite[4] = sprite_init_LMG(ft_load_bmp2(SPRITE_PATH_4));
    

    d->sprite[5] = sprite_init_DD(ft_load_bmp2(SPRITE_PATH_5));
}