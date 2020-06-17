#include "global_header.h"
#include "render.h"
#include "editor.h"
#include "img_file.h"
#include "sprite.h"

SDL_Rect    get_sprite_mob_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos)
{
    srcdim.x = d->sprite[d->mob_ind].frame_size.w * pos.x;
    srcdim.y = d->sprite[d->mob_ind].frame_size.h * pos.y;
    srcdim.w = d->sprite[d->mob_ind].frame_size.w - d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].offset.x;
    srcdim.h = d->sprite[d->mob_ind].frame_size.h - d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].offset.y;
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

void    mob_idle_anim(t_data *d)
{
    SDL_Rect srcdim;
    SDL_Rect dstdim;
    SDL_Point pos;
    int i;

    i = 0;
    while (i < d->mobs_on_screen)
    {
    pos.x = d->sprite[d->mob_ind].anim[IDLE].pos->x;
    pos.y = d->sprite[d->mob_ind].anim[IDLE].pos->y;

    srcdim = get_sprite_mob_pos(srcdim, d, pos);
    dstdim = print_mob(dstdim, 500 * i, 0, 500);
    SDL_RenderCopy(d->rend, d->sprite[d->mob_ind].text, &srcdim, &dstdim);
    i++;
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
        diff = 0;
        if (d->sprite[d->mob_ind].on >= 0)
        {
            currTime = SDL_GetTicks();
            diff = (currTime - d->sprite[d->mob_ind].time) / 100;
        }
        pos.x = (d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].pos->x + diff) % d->sprite[d->mob_ind].nb_frame.x;
        pos.y = d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].pos->y + (d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].pos->x + diff) / d->sprite[d->mob_ind].nb_frame.x;
        if (diff < d->sprite[d->mob_ind].anim[d->sprite[d->mob_ind].index].nb_frame && d->sprite[d->mob_ind].on == 0)
        {
            srcdim = get_sprite_mob_pos(srcdim, d, pos);
            dstdim = print_mob(dstdim, i * 500, 0, 500);
            SDL_RenderCopy(d->rend, d->sprite[d->mob_ind].text, &srcdim, &dstdim);
        }
        else if (d->sprite[d->mob_ind].index != IDLE)
            d->sprite[d->mob_ind].time = SDL_GetTicks();
        else
        {
            d->sprite[d->mob_ind].index = IDLE;
            d->sprite[d->mob_ind].on = -1;
            mob_idle_anim(d);
        }
        i++;
    }
}