/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:35:15 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 15:35:23 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		adapt_min(int *pos, int *length)
{
	if (*pos < 0)
	{
		*length += *pos;
		*pos = 0;
	}
}

void		adapt_max(int *pos, int *length, int max)
{
	if (*pos + *length > max)
		*length = ft_max(0, max - *pos);
}

float		get_float_part(float value)
{
	int int_part;

	int_part = (int)value;
	return (value - int_part - INTER_TOLERANCE);
}

t_point		sdl_p_to_t_p(SDL_Point p)
{
	t_point new;

	new.x = p.x;
	new.y = p.y;
	return (new);
}

t_rot		calc_sin_cos_rot(float rot)
{
	t_rot new;

	new.rot = rot;
	new.cos_rot = cos(rot);
	new.sin_rot = sin(rot);
	return (new);
}
