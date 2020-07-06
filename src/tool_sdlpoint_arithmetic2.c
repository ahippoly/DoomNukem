/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_sdlpoint_arithmetic2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:15:00 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 15:15:13 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

SDL_Point	add_sdl_point(SDL_Point p, SDL_Point add, int is_sub)
{
	if (is_sub == 1)
	{
		p.x -= add.x;
		p.y -= add.y;
	}
	else
	{
		p.x += add.x;
		p.y += add.y;
	}
	return (p);
}

t_point		add_t_point(t_point p, t_point add, int is_sub)
{
	if (is_sub == 1)
	{
		p.x -= add.x;
		p.y -= add.y;
	}
	else
	{
		p.x += add.x;
		p.y += add.y;
	}
	return (p);
}

SDL_Point	mult_sdl_point(SDL_Point p, float mul)
{
	p.x = mul * p.x;
	p.y = mul * p.y;
	return (p);
}

t_point		mult_t_point(t_point p, float mul)
{
	p.x = mul * p.x;
	p.y = mul * p.y;
	return (p);
}

void		swap_point(SDL_Point *p1, SDL_Point *p2)
{
	SDL_Point tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
