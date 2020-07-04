/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:17:22 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/05 00:25:48 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

float	calc_ray_hit_scale(t_point p1, t_point p2, t_point inter)
{
	sort_t_point_by_x(&p1, &p2);
	if (is_equ_tolerance(p2.x - p1.x, 0, INTER_TOLERANCE))
		return (get_float_part((inter.y - p1.y) / (p2.y - p1.y)));
	return (get_float_part((inter.x - p1.x) / (p2.x - p1.x)));
}

void	init_ray(t_ray *res, t_obj *obj)
{
	res->dist = 9999;
	res->scale = 0;
	res->obj_ref = obj;
	res->room_id = obj->room_id;
}

void	init_perp_points(t_point *p1, t_point *p2, t_point pos, t_rot look_rot)
{
	p1->x = pos.x - look_rot.cos_rot * 30;
	p1->y = pos.y - look_rot.sin_rot * 30;
	p2->x = pos.x + look_rot.cos_rot * 30;
	p2->y = pos.y + look_rot.sin_rot * 30;
}

void	define_z_text(t_ray *res)
{
	if (res->room_id < -1)
		res->z_text = 1;
	else
		res->z_text = res->z_height.size;
}
