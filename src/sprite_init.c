/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:08:24 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 23:02:04 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void			init_sprites_img(t_data *d)
{
	d->sprite_img[SPRITE_ID_AFRIT] = ft_load_bmp2(SPRITE_PATH_AFRIT,
		BMP_TYPE_ABGR, 0);
	if (d->sprite_img[SPRITE_ID_AFRIT].w == -42)
		exit_game(d, "error : failed to init sprites images");
	d->sprite_img[SPRITE_ID_PYRO] = ft_load_bmp2(SPRITE_PATH_PYRO,
		BMP_TYPE_BGRA, 0);
}

void			init_sprites_img_env(t_env *e)
{
	e->sprite_img[SPRITE_ID_AFRIT] = read_img_surface(SPRITE_PATH_AFRIT,
		SDL_PIXELFORMAT_RGBA32);
	e->sprite_img[SPRITE_ID_PYRO] = read_img_surface(SPRITE_PATH_PYRO,
		SDL_PIXELFORMAT_RGBA32);
}

void			init_anim_range_x(t_ssprite *sprite, t_anim *anim,
					SDL_Point start, int nb_frame)
{
	int i;

	i = 0;
	while (i < nb_frame)
	{
		if (start.y >= sprite->nb_frame.y)
			return ;
		anim->pos[i].x = start.x * sprite->frame_size.w + anim->offset.x;
		anim->pos[i].y = start.y * sprite->frame_size.h + anim->offset.y;
		anim->size[i].w = sprite->frame_disp_size.w;
		anim->size[i].h = sprite->frame_disp_size.h;
		start.x++;
		i++;
		if (start.x >= sprite->nb_frame.x)
		{
			start.x = 0;
			start.y += 1;
		}
	}
}

void			init_curr_frames(t_ssprite *sprite)
{
	int i;

	i = 0;
	while (i < NB_ANIM)
		sprite->anim[i++].current_frame = 0;
}

void			set_sprite_callback(t_ssprite *sprite, void (*funct)(t_param),
					t_param param)
{
	sprite->callback = funct;
	sprite->param = param;
}
