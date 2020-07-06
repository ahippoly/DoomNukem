/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:39:17 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 15:39:26 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		copy_frame(unsigned int *dst, SDL_Rect dst_size,
				unsigned int *src, SDL_Rect pos_size)
{
	SDL_Point pos;
	SDL_Point pos2;
	SDL_Point frame_max;

	pos.y = pos_size.y * pos_size.w;
	pos2.y = 0;
	frame_max.y = dst_size.h * dst_size.w;
	while (pos2.y < frame_max.y)
	{
		pos.x = pos_size.x;
		pos2.x = 0;
		while (pos2.x < dst_size.w)
		{
			dst[pos2.x + pos2.y] = src[pos.x + pos.y];
			pos2.x++;
			pos.x++;
		}
		pos2.y += dst_size.w;
		pos.y += pos_size.w;
	}
}

void		copy_frame_scale(unsigned int *dst, SDL_Rect dst_size,
				unsigned int *src, SDL_Rect pos_size)
{
	t_point		pos;
	SDL_Point	pos2;
	SDL_Point	frame_max;
	t_point		step;
	int			y;

	pos2.y = 0;
	frame_max.y = dst_size.h * dst_size.w;
	step.x = (double)dst_size.x / dst_size.w;
	step.y = (double)dst_size.y / dst_size.h;
	pos.y = pos_size.y;
	y = pos_size.y * pos_size.w;
	while (pos2.y < frame_max.y)
	{
		pos.x = pos_size.x;
		pos2.x = 0;
		while (pos2.x < dst_size.w)
		{
			dst[pos2.x + pos2.y] = src[(int)pos.x + y];
			pos2.x++;
			pos.x += step.x;
		}
		pos2.y += dst_size.w;
		pos.y += step.y;
		y = (int)pos.y * pos_size.w;
	}
}
