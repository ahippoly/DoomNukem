/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssprite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:20:41 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 14:12:22 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void			copy_frame_ssprite(t_ssprite *sprite, SDL_Point pos_anim,
					t_size size_anim)
{
	copy_frame_scale(sprite->dst, (SDL_Rect){size_anim.w, size_anim.h,
		sprite->frame_disp_size.w, sprite->frame_disp_size.h},
			sprite->src.pixels, (SDL_Rect){pos_anim.x, pos_anim.y,
				sprite->src.w, sprite->src.h});
}

void			load_anim(t_ssprite *sprite, int time, int anim_id)
{
	SDL_Point	curr_anim_pos;
	t_size		curr_anim_size;

	sprite->current_anim = anim_id;
	sprite->anim[anim_id].current_frame = 0;
	sprite->time = time;
	curr_anim_pos = sprite->anim[anim_id].pos[0];
	curr_anim_size = sprite->anim[anim_id].size[0];
	copy_frame_ssprite(sprite, curr_anim_pos, curr_anim_size);
}

void			process_anim(t_ssprite *sprite, int time)
{
	t_anim		*anim;
	SDL_Point	curr_anim_pos;
	t_size		curr_anim_size;

	if (sprite->current_anim < 0)
		return ;
	anim = &sprite->anim[sprite->current_anim];
	if (time - sprite->time > anim->speed)
	{
		sprite->time = time;
		anim->current_frame += 1;
		if (anim->current_frame >= anim->nb_frame)
		{
			if (sprite->callback != NULL)
				sprite->callback(sprite->param);
			sprite->callback = NULL;
			if (sprite->idle_anim >= 0)
				load_anim(sprite, time, sprite->idle_anim);
			else
				sprite->current_anim = -1;
			return ;
		}
		curr_anim_pos = anim->pos[anim->current_frame];
		curr_anim_size = anim->size[anim->current_frame];
		copy_frame_ssprite(sprite, curr_anim_pos, curr_anim_size);
	}
}

void			process_mobs_anim(t_data *d)
{
	int i;

	i = 0;
	while (i < d->nb_mob)
	{
		process_anim(&d->mobs[i].sprite, d->time);
		i++;
	}
}
