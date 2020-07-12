/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_sdlpoint_arithmetic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:12:20 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 15:15:08 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		sort_point_by_x(SDL_Point *p1, SDL_Point *p2)
{
	if (p1->x > p2->x)
		swap_point(p1, p2);
}

void		swap_t_point(t_point *p1, t_point *p2)
{
	t_point tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void		sort_t_point_by_x(t_point *p1, t_point *p2)
{
	if (p1->x > p2->x)
		swap_t_point(p1, p2);
}

SDL_Point	create_point(int x, int y)
{
	SDL_Point p;

	p.x = x;
	p.y = y;
	return (p);
}

SDL_Point	convert_t_point(t_point point)
{
	SDL_Point new_point;

	new_point.x = point.x;
	new_point.y = point.y;
	return (new_point);
}
