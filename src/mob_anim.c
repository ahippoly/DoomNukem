#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

SDL_Rect    get_sprite_mob_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos, int mob_ind)
{
    srcdim.x = d->sprite[mob_ind].frame_size.w * pos.x;
    srcdim.y = d->sprite[mob_ind].frame_size.h * pos.y;
    srcdim.w = d->sprite[mob_ind].frame_size.w - d->sprite[mob_ind].anim[d->sprite[mob_ind].index].offset.x;
    srcdim.h = d->sprite[mob_ind].frame_size.h - d->sprite[mob_ind].anim[d->sprite[mob_ind].index].offset.y;
    return (srcdim);
}

SDL_Rect    print_mob(SDL_Rect dstdim, int x, int y, int z)
{
    dstdim.x = 0 + x;
    dstdim.y = 0 + y;
    dstdim.w = WIN_SIZE_X - z;
    dstdim.h = WIN_SIZE_Y - z;
    return (dstdim);
}

void    copy_frame(t_sprite sprite, SDL_Rect size)
{
    SDL_Point pos;
    SDL_Point pos2;
    SDL_Point frame_max;

    frame_max.x = sprite.displayed_part.x + size.w;
    frame_max.y = sprite.displayed_part.y + size.h;

    pos.y = sprite.displayed_part.y;
    while (pos.y < frame_max.y)
    {
        pos.x = sprite.displayed_part.x;
        pos2.x = 0;
        while (pos.x < frame_max.x)
        {
            sprite.pixels_dst[pos2.x + pos2.y] = sprite.pixels[pos.x + pos.y];
            pos.x++;
        }
        pos2.y += sprite.frame_size.w;
        pos.y += sprite.total_size.w;
    }
}

void    mob_anim(t_data *d)
{
    SDL_Rect srcdim;
    SDL_Rect dstdim;
    SDL_Point pos;
    Uint32 currTime;
    int diff;
    int i;

    i = 0;
     while (i < d->mobs_on_screen)
     {
        diff = 0;      //Diff represente l'index dans l'animation, il est calculé plus bas en fonction du temps
        if (d->sprite[d->mob_ind].on >= 0)
        {
            currTime = SDL_GetTicks();
            diff = (currTime - d->sprite[d->mob_ind].time) / d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].speed;
        }
        pos.x = (d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].pos->x + diff) % d->sprite[d->mob_ind].nb_frame.x;
        pos.y = d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].pos->y + (d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].pos->x + diff) / d->sprite[d->mob_ind].nb_frame.x;
        if (diff < d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].nb_frame && d->sprite[d->mob_ind].on == 0)
        {   
            srcdim = get_sprite_mob_pos(srcdim, d, pos, d->mob_ind); //le SDL_Rect qui represente la frame de l'animation sur le sprite sheet
            dstdim = print_mob(dstdim, i * 500, 0, 500);    //le SDL_Rect qui represente la position a l'affichage de l'animation avec comme parametre x,y,z
            d->sprite[d->mob_ind].displayed_part.x = srcdim.x;
            d->sprite[d->mob_ind].displayed_part.y = srcdim.y;
            //copy_frame(d->sprite[d->mob_ind], srcdim);
            SDL_RenderCopy(d->rend, d->sprite[d->mob_ind].text, &srcdim, &dstdim);
        }
        else
            d->sprite[d->mob_ind].time = SDL_GetTicks(); //permet de boucler l'animation a l'infini en redemarrant le compteur temps
        i++;
    }
}