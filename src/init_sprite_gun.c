#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

void      init_anim_AR(t_sprite *AR)
{
    int i;

    AR->anim[0].pos->x = 0;
    AR->anim[0].pos->y = 0;
    AR->anim[0].nb_frame = 2;
    AR->anim[0].current_frame = 0; 
    AR->anim[1].pos->x = 2;
    AR->anim[1].pos->y = 0;
    AR->anim[1].nb_frame = 4;
    AR->anim[1].current_frame = 2;
    AR->anim[2].pos->x = 2;
    AR->anim[2].pos->y = 1; 
    AR->anim[2].nb_frame = 21;
    AR->anim[2].current_frame = 6;    
    AR->anim[3].pos->x = 2;
    AR->anim[3].pos->y = 7;   
    AR->anim[3].nb_frame = 1;
    AR->anim[3].current_frame = 27; 
}

t_sprite    init_sprite_AR(SDL_Texture *text)
{
    t_sprite AR;

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

    AR.text = text;
    init_anim_AR(&AR);
    return (AR);
}

void      init_anim_DD(t_sprite *DD)
{
    int i;

    DD->anim[0].pos->x = 0;
    DD->anim[0].pos->y = 0;
    DD->anim[0].nb_frame = 10;
    DD->anim[0].current_frame = 0; 
    DD->anim[1].pos->x = 0;
    DD->anim[1].pos->y = 2;
    DD->anim[1].nb_frame = 1;
    DD->anim[1].current_frame = 11;
    DD->anim[2].pos->x = 1;
    DD->anim[2].pos->y = 2; 
    DD->anim[2].nb_frame = 4;
    DD->anim[2].current_frame = 12;    
}

t_sprite    init_sprite_DD(SDL_Texture *text)
{
    t_sprite DD;

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

    DD.text = text;
    init_anim_DD(&DD);
    return (DD);
}

void      init_anim_LMG(t_sprite *LMG)
{
    int i;

    LMG->anim[0].pos->x = 0;
    LMG->anim[0].pos->y = 0;
    LMG->anim[0].nb_frame = 1;
    LMG->anim[1].pos->x = 1;
    LMG->anim[1].pos->y = 0;
    LMG->anim[1].nb_frame = 2;
    LMG->anim[2].pos->x = 3;
    LMG->anim[2].pos->y = 0; 
    LMG->anim[2].nb_frame = 5;
    LMG->anim[3].pos->x = 3;
    LMG->anim[3].pos->y = 1; 
    LMG->anim[3].nb_frame = 1;
    LMG->anim[4].pos->x = 4;
    LMG->anim[4].pos->y = 1; 
    LMG->anim[4].nb_frame = 22;
    LMG->anim[5].pos->x = 1;
    LMG->anim[5].pos->y = 6; 
    LMG->anim[5].nb_frame = 3;
    LMG->anim[6].pos->x = 4;
    LMG->anim[6].pos->y = 6; 
    LMG->anim[6].nb_frame = 5;
}

t_sprite    init_sprite_LMG(SDL_Texture *text)
{
    t_sprite LMG;

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

    LMG.text = text;
    init_anim_LMG(&LMG);
    return (LMG);
}


void      init_anim_Rev(t_sprite *Rev)
{
    int i;

    Rev->anim[0].pos->x = 0;
    Rev->anim[0].pos->y = 0;
    Rev->anim[0].nb_frame = 9;
    Rev->anim[1].pos->x = 1;
    Rev->anim[1].pos->y = 2;
    Rev->anim[1].nb_frame = 4;
    Rev->anim[2].pos->x = 1;
    Rev->anim[2].pos->y = 3; 
    Rev->anim[2].nb_frame = 13;
    Rev->anim[3].pos->x = 2;
    Rev->anim[3].pos->y = 6; 
    Rev->anim[3].nb_frame = 1;
    Rev->anim[4].pos->x = 3;
    Rev->anim[4].pos->y = 6; 
    Rev->anim[4].nb_frame = 1;
}

t_sprite    init_sprite_Revolver(SDL_Texture *text)
{
    t_sprite Rev;

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

    Rev.text = text;
    init_anim_Rev(&Rev);
    return (Rev);
}

void      init_anim_SSG(t_sprite *SSG)
{
    int i;

    SSG->anim[0].pos->x = 0;
    SSG->anim[0].pos->y = 0;
    SSG->anim[0].nb_frame = 1;
    SSG->anim[1].pos->x = 1;
    SSG->anim[1].pos->y = 0;
    SSG->anim[1].nb_frame = 1;
    SSG->anim[2].pos->x = 2;
    SSG->anim[2].pos->y = 0; 
    SSG->anim[2].nb_frame = 3;
    SSG->anim[3].pos->x = 2;
    SSG->anim[3].pos->y = 1; 
    SSG->anim[3].nb_frame = 6;
    SSG->anim[4].pos->x = 2;
    SSG->anim[4].pos->y = 3; 
    SSG->anim[4].nb_frame = 22;
}

t_sprite    init_sprite_SSG(SDL_Texture *text)
{
    t_sprite SSG;

    SSG.index = 3;

    SSG.total_size.w = 459;
    SSG.total_size.h = 1023;

    SSG.nb_frame.x = 3;    
    SSG.nb_frame.y = 11;  

    SSG.frame_size.w = SSG.total_size.w / SSG.nb_frame.x;
    SSG.frame_size.h = SSG.total_size.h / SSG.nb_frame.y;

    SSG.idle_frame.x = 1;
    SSG.idle_frame.y = 0;

    SSG.displayed_part.x = 0;
    SSG.displayed_part.y = 0;

    SSG.nb_anim = 4;

    SSG.idle_animation = 3;

    SSG.text = text;
    init_anim_SSG(&SSG);
    return (SSG);
}

void      init_anim_Melee(t_sprite *Melee)
{
    int i;

    Melee->anim[0].pos->x = 0;
    Melee->anim[0].pos->y = 0;
    Melee->anim[0].nb_frame = 1;
    Melee->anim[1].pos->x = 1;
    Melee->anim[1].pos->y = 0;
    Melee->anim[1].nb_frame = 10;
}

t_sprite    init_sprite_Melee(SDL_Texture *text)
{
    t_sprite Melee;

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

    Melee.text = text;
    init_anim_Melee(&Melee);
    return (Melee);
}