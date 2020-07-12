/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:48:11 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 15:59:42 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_point		calc_intersect_point(t_point p1, t_point p2, t_point p3, t_point p4)
{
	t_point	inter;
	float	a1;
	float	b1;
	float	a2;
	float	b2;

	a1 = calc_a(p1, p2);
	a2 = calc_a(p3, p4);
	b1 = calc_b(p1, a1);
	b2 = calc_b(p3, a2);
	inter.x = (b2 - b1) / (a1 - a2);
	inter.y = a1 * inter.x + b1;
	return (inter);
}

t_point		calc_inter_first_vertical(t_point p1, t_point p3, t_point p4)
{
	t_point	inter;
	float	a2;
	float	b2;

	a2 = calc_a(p3, p4);
	b2 = calc_b(p3, a2);
	inter.x = p1.x;
	inter.y = a2 * inter.x + b2;
	return (inter);
}

t_point		find_intersect_no_bound(t_point p1, t_point p2, t_point p3,
				t_point p4)
{
	t_point inter;
	float	line1_diff_x;
	float	line2_diff_x;

	sort_t_point_by_x(&p1, &p2);
	sort_t_point_by_x(&p3, &p4);
	line1_diff_x = p2.x - p1.x;
	line2_diff_x = p4.x - p3.x;
	if (!(is_equ_tolerance(line1_diff_x, 0, INTER_TOLERANCE) ||
			is_equ_tolerance(line2_diff_x, 0, INTER_TOLERANCE)))
		inter = calc_intersect_point(p1, p2, p3, p4);
	else if (line1_diff_x < INTER_TOLERANCE && line1_diff_x > -INTER_TOLERANCE)
		inter = calc_inter_first_vertical(p1, p3, p4);
	else if (line2_diff_x < INTER_TOLERANCE && line2_diff_x > -INTER_TOLERANCE)
		inter = calc_inter_first_vertical(p3, p1, p2);
	else
		inter = (t_point){-42, -42};
	return (inter);
}

t_point		segment_intersect(SDL_Point point1, SDL_Point point2,
				SDL_Point point3, SDL_Point point4)
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_point p4;

	p1 = convert_sdlpoint2tpoint(point1);
	p2 = convert_sdlpoint2tpoint(point2);
	p3 = convert_sdlpoint2tpoint(point3);
	p4 = convert_sdlpoint2tpoint(point4);
	return (find_intersect(p1, p2, p3, p4));
}

t_point		inter_with_dir(t_point pos, t_rot rot, t_point p3, t_point p4)
{
	t_point p2;

	p2.x = pos.x + (rot.cos_rot) * RAY_LENGTH;
	p2.y = pos.y + (rot.sin_rot) * RAY_LENGTH;
	return (find_intersect(pos, p2, p3, p4));
}
