/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_intersect2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:57:12 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 15:59:40 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

float		calc_a(t_point p1, t_point p2)
{
	return ((p2.y - p1.y) / (p2.x - p1.x));
}

float		calc_b(t_point p1, float a)
{
	return (p1.y - p1.x * a);
}

int			is_equ_tolerance(float value1, float value2, float tolerance)
{
	if (value1 < value2 + tolerance && value1 > value2 - tolerance)
		return (1);
	return (0);
}

t_point		calc_intersect(float a1, float b1, float a2, float b2)
{
	t_point inter;

	inter.x = (b2 - b1) / (a1 - a2);
	inter.y = a1 * inter.x + b1;
	return (inter);
}

t_point		line_intersect(t_point pos, float rot, t_point p1, t_point p2)
{
	float	a1;
	float	b1;
	float	a2;
	float	b2;
	t_point	inter;

	sort_t_point_by_x(&p1, &p2);
	a1 = sin(rot) / cos(rot);
	b1 = calc_b(pos, a1);
	a2 = calc_a(p1, p2);
	b2 = calc_b(p1, a2);
	if (a1 == a2)
		return (create_t_point(-42, -42));
	inter = calc_intersect(a1, b1, a2, b2);
	if (inter.x < p1.x || inter.x > p2.x)
		return (create_t_point(-42, -42));
	return (inter);
}
