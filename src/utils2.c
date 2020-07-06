/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:32:21 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 15:32:45 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_point		create_t_point(float x, float y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

t_range		create_t_range(int start, int end)
{
	t_range range;

	range.start = start;
	range.end = end;
	return (range);
}

t_size		create_t_size(int w, int h)
{
	t_size size;

	size.w = w;
	size.h = h;
	return (size);
}

SDL_Rect	set_sdl_rect(int x, int y, int w, int h)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}

t_size		set_size(int w, int h)
{
	t_size size;

	size.w = w;
	size.h = h;
	return (size);
}
