/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:14:20 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 20:18:54 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	move_attempt(t_data *d, t_point *pos, float speed, t_rot look_rot)
{
	pos->y += speed * look_rot.sin_rot * d->diff_time;
	pos->x += speed * look_rot.cos_rot * d->diff_time;
}

float	mod_pi(float rot)
{
	rot = fmod(rot, PI_X_2);
	if (rot < 0)
		rot = PI_X_2 + rot;
	return (rot);
}

int		is_angle_in_range(float rot, float min, float max)
{
	if (min > max && (rot > min || rot < max))
		return (1);
	else if (rot > min && rot < max)
		return (1);
	return (0);
}

int		check_collide(t_data *d, t_ray *res, float z_pos, int *will_collide)
{
	if (res->z_height.pos + res->z_height.size > z_pos
			&& res->z_height.pos - d->z_offset < z_pos)
		(*will_collide)++;
	return (*will_collide);
}

t_point	check_wall_front(t_point pos, t_rot rot, t_ray *ray)
{
	return (find_intersect_no_bound(pos, (t_point){pos.x + (rot.cos_rot),
		pos.y + (rot.sin_rot)}, (ray->obj_ref->p1), (ray->obj_ref->p2)));
}
