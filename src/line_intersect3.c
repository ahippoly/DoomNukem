/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_intersect3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:57:47 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 15:58:40 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_point		default_case(t_point p1, t_point p2, t_point p3, t_point p4)
{
	float	a1;
	float	a2;
	float	b1;
	float	b2;
	t_point	inter;

	a1 = (p2.y - p1.y) / (p2.x - p1.x);
	b1 = p1.y - p1.x * a1;
	a2 = (p4.y - p3.y) / (p4.x - p3.x);
	b2 = p3.y - p3.x * a2;
	if (a1 == a2 && b1 == b2 && ((p1.x > p3.x && p1.x < p4.x)
	|| (p2.x > p3.x && p2.x < p4.x)
	|| (p3.x > p1.x - INTER_TOLERANCE && p3.x < p2.x - INTER_TOLERANCE)))
		return (create_t_point(-41, -41));
	inter.x = (b2 - b1) / (a1 - a2);
	if (inter.x < p2.x - INTER_TOLERANCE && inter.x > p1.x + INTER_TOLERANCE
		&& inter.x < p4.x - INTER_TOLERANCE && inter.x > p3.x + INTER_TOLERANCE
		&& (a1 != a2))
		inter.y = a1 * inter.x + b1;
	else
		inter = create_t_point(-42, -42);
	return (inter);
}

t_point		first_segment_vertical_case(t_point p1, t_point p2, t_point p3,
				t_point p4)
{
	float	a2;
	float	b2;
	t_point	inter;

	a2 = (p4.y - p3.y) / (p4.x - p3.x);
	b2 = p3.y - p3.x * a2;
	inter.x = p1.x;
	inter.y = a2 * inter.x + b2;
	if (inter.y > ft_fmax(p2.y, p1.y) - INTER_TOLERANCE || inter.y <
			ft_fmin(p1.y, p2.y) + INTER_TOLERANCE || inter.x > p4.x -
				INTER_TOLERANCE || inter.x < p3.x + INTER_TOLERANCE)
	{
		inter.x = -42;
		inter.y = -42;
	}
	return (inter);
}

t_point		convert_sdlpoint2tpoint(SDL_Point point)
{
	t_point new_point;

	new_point.x = point.x;
	new_point.y = point.y;
	return (new_point);
}

t_point		find_intersect(t_point p1, t_point p2, t_point p3, t_point p4)
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
		inter = default_case(p1, p2, p3, p4);
	else if (line1_diff_x < INTER_TOLERANCE && line1_diff_x > -INTER_TOLERANCE)
		inter = first_segment_vertical_case(p1, p2, p3, p4);
	else if (line2_diff_x < INTER_TOLERANCE && line2_diff_x > -INTER_TOLERANCE)
		inter = first_segment_vertical_case(p3, p4, p1, p2);
	else
	{
		inter.x = -42;
		inter.y = -42;
	}
	return (inter);
}
