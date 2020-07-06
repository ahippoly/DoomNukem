/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:48:30 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 16:48:31 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
void    get_gun_pos(t_data *d, SDL_Point pos)
{
    //SDL_Rect srcdim;

    d->src_gun.x = d->sprite[d->gun_ind].frame_size.w * pos.x;
    d->src_gun.y = d->sprite[d->gun_ind].frame_size.h * pos.y;
    d->src_gun.w = d->sprite[d->gun_ind].frame_size.w - 
        d->sprite[d->gun_ind].anim[d->sprite[d->gun_ind].index].offset.x;
    d->src_gun.h = d->sprite[d->gun_ind].frame_size.h - 
        d->sprite[d->gun_ind].anim[d->sprite[d->gun_ind].index].offset.y;
    // return (srcdim);
}

void    gun_dimension(t_data *d)
{
    //SDL_Rect d->dst_gun;

    d->dst_gun.x = HALF_WIN_SIZE_X - d->sprite[d->gun_ind].size.x;
    d->dst_gun.y = HALF_WIN_SIZE_Y - d->sprite[d->gun_ind].size.y;
    d->dst_gun.w = (HALF_WIN_SIZE_X + d->sprite[d->gun_ind].size.x) - 
        d->dst_gun.x;
    d->dst_gun.h = HALF_WIN_SIZE_Y + d->sprite[d->gun_ind].size.y;
    if (d->gun_ind == 5)
        d->dst_gun.x += 40;
    if (d->gun_ind == 3 && (d->sprite[d->gun_ind].index == AIM || 
        d->sprite[d->gun_ind].index == AIMFIRE))
        d->dst_gun.y += 80;
    //return (dstdim);
}

void			gun_idle_anim(t_data *d)
{
    SDL_Point	pos;

    pos.x = 0;
    pos.y = 0;
    if (d->sprite[d->gun_ind].aim_on == 0)
    {
		pos.x = d->sprite[d->gun_ind].anim[IDLE].pos->x;
		pos.y = d->sprite[d->gun_ind].anim[IDLE].pos->y;
    }
    else if (d->sprite[d->gun_ind].aim_on == 1)
    {
		pos.x = d->sprite[d->gun_ind].anim[AIM].pos->x;
		pos.y = d->sprite[d->gun_ind].anim[AIM].pos->y;
		d->sprite[d->gun_ind].index = AIM;
    }
    get_gun_pos(d, pos);
    gun_dimension(d);
}

void			sprite_anim_gun(t_data *d)
{
    SDL_Point	pos;
    Uint32		currTime;
    int			diff;

    diff = 0;
    if (d->sprite[d->gun_ind].on >= 0)
    {
        currTime = SDL_GetTicks();
        diff = (currTime - d->sprite[d->gun_ind].time) / 100;
    }
    pos.x = (d->sprite[d->gun_ind].anim[d->sprite[d->gun_ind].index].pos->x + diff) % d->sprite[d->gun_ind].nb_frame.x;
    pos.y = d->sprite[d->gun_ind].anim[d->sprite[d->gun_ind].index].pos->y + (d->sprite[d->gun_ind].anim[d->sprite[d->gun_ind].index].pos->x + diff) / d->sprite[d->gun_ind].nb_frame.x;
    if (diff < d->sprite[d->gun_ind].anim[d->sprite[d->gun_ind].index].nb_frame && d->sprite[d->gun_ind].on == 0)
    {
        get_gun_pos(d, pos);
        gun_dimension(d);
    }
    else
    {
        d->sprite[d->gun_ind].index = IDLE;
        d->sprite[d->gun_ind].on = -1;
        gun_idle_anim(d);
    }
}