#include "proto_global.h"


SDL_Rect    get_sprite_mob_pos(SDL_Rect srcdim, t_data *d, SDL_Point pos, int ind)
{
    srcdim.x = d->sprite[ind].frame_size.w * pos.x;
    srcdim.y = d->sprite[ind].frame_size.h * pos.y;
    srcdim.w = d->sprite[ind].total_size.w;
    srcdim.h = d->sprite[ind].total_size.h;
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

void copy_frame_sprite(t_sprite *sprite, SDL_Rect pos_size)
{
	copy_frame(sprite->pixels_dst, (SDL_Rect){0, 0, sprite->frame_size.w, sprite->frame_size.h}, sprite->pixels, pos_size);
}

void    mob_anim(t_data *d)
{
    SDL_Rect srcdim;
    SDL_Rect dstdim;
    SDL_Point pos;
    Uint32 currTime;
    int diff;
    int i;

    i = MOB_INDEX; //index du premier mob
     while (i < NB_MAX_MOBS + 10)
     {
        if (d->sprite[i].on == 0)
        {
            diff = 0;      //Diff represente l'index dans l'animation, il est calculé plus bas en fonction du temps
            if (d->sprite[i].on >= 0)
            {
                currTime = SDL_GetTicks();
                diff = (currTime - d->sprite[i].time) / d->sprite[i].anim[d->sprite[i].index].speed;
            }
            //printf("diff= %d\n", diff);
            pos.x = (d->sprite[i].anim[d->sprite[i].index].pos->x + diff) % d->sprite[i].nb_frame.x;
            pos.y = d->sprite[i].anim[d->sprite[i].index].pos->y + (d->sprite[i].anim[d->sprite[i].index].pos->x + diff) / d->sprite[i].nb_frame.x;
            
            if (diff < d->sprite[i].anim[d->sprite[i].index].nb_frame && d->sprite[i].on == 0)
            {   
                srcdim = get_sprite_mob_pos(srcdim, d, pos, i); //le SDL_Rect qui represente la frame de l'animation sur le sprite sheet
                dstdim = print_mob(dstdim, 300, 300, 400);    //le SDL_Rect qui represente la position a l'affichage de l'animation avec comme parametre x,y,z
                d->sprite[i].displayed_part.x = srcdim.x;
                d->sprite[i].displayed_part.y = srcdim.y;
				copy_frame_sprite(&d->sprite[i], srcdim);
                //copy_frame(d->sprite[i].pixels_dst, srcdim);
                //if (i == d->mob_ind)
                //SDL_RenderCopy(d->rend, d->sprite[i].text, &srcdim, &dstdim);
            }
            else if (d->sprite[i].index != DEATH)
                d->sprite[i].time = SDL_GetTicks(); //permet de boucler l'animation a l'infini en redemarrant le compteur temps
            //else
            //    free mob after last frame of death animation
            //    d->sprite[i].on = -1;
            i++;
        }
    }
}