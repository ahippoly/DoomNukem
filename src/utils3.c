/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:33:24 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 16:13:01 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static SDL_Rect	adapt_border(SDL_Rect pos_size, t_size max)
{
	adapt_min(&pos_size.x, &pos_size.w);
	adapt_min(&pos_size.y, &pos_size.h);
	adapt_max(&pos_size.x, &pos_size.w, max.w);
	adapt_max(&pos_size.y, &pos_size.h, max.h);
	return (pos_size);
}

void			draw_rectangle(unsigned int *pixels, SDL_Rect rect,
				t_size screen_size, int color)
{
	int			x;
	int			y;
	SDL_Point	end;

	rect = adapt_border(rect, screen_size);
	end.x = rect.x + rect.w;
	end.y = rect.y + rect.h;
	y = rect.y;
	while (y < end.y)
	{
		x = rect.x;
		while (x < end.x)
			pixels[x++ + y * screen_size.w] = color;
		y++;
	}
}

void			create_straight_line(unsigned int *pixels, SDL_Rect pos_size,
				t_size screen_length, int color)
{
	int i;
	int end;

	pos_size = adapt_border(pos_size, screen_length);
	i = pos_size.x;
	end = pos_size.x + pos_size.w;
	while (i < end)
	{
		pixels[i + pos_size.y * screen_length.w] = color;
		i++;
	}
}

void			create_straight_column(unsigned int *pixels, SDL_Rect pos_size,
				t_size screen_length, int color)
{
	int i;
	int end;

	pos_size = adapt_border(pos_size, screen_length);
	i = pos_size.y;
	end = pos_size.y + pos_size.h;
	while (i < end)
	{
		pixels[pos_size.x + i * screen_length.w] = color;
		i++;
	}
}
