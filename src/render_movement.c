/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:40:04 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 20:16:26 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_ray	check_collide_with_all(t_data *d, int *will_collide,
	t_obj *obj, t_rot rot)
{
	int		i;
	float	diff_x;
	t_point	pos;
	t_ray	sorted[NB_MAX_OBJ];
	t_ray	res;

	i = 0;
	pos = obj->pos;
	sort_perp_ray(d, pos, sorted);
	while (i < d->nb_obj)
	{
		if (sorted[i].dist < WALL_SIZE)
		{
			diff_x = check_wall_front(pos, rot, &sorted[i]).x - pos.x;
			if ((diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0
				&& (rot.cos_rot) < 0))
			{
				res = sorted[i];
				if (check_collide(d, &res, obj->z_height.pos, will_collide) > 1)
					break ;
			}
		}
		i++;
	}
	return (res);
}

t_ray	check_collide_with_all_player(t_data *d, int *will_collide, t_rot rot)
{
	int		i;
	float	diff_x;
	t_point	pos;
	t_ray	sorted[NB_MAX_OBJ];
	t_ray	res;

	i = 0;
	pos = d->player_pos;
	sort_perp_ray(d, pos, sorted);
	while (i < d->nb_obj)
	{
		if (sorted[i].dist < WALL_SIZE)
		{
			diff_x = check_wall_front(pos, rot, &sorted[i]).x - pos.x;
			if ((diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0
				&& (rot.cos_rot) < 0))
			{
				res = sorted[i];
				if (check_collide(d, &res, d->z_pos, will_collide) > 1)
					break ;
			}
		}
		i++;
	}
	return (res);
}

void	move_with_collide(t_data *d, t_obj *obj, t_rot rot, float speed)
{
	int		will_collide;
	t_ray	res;
	t_point	*pos;

	pos = &obj->pos;
	will_collide = 0;
	res = check_collide_with_all(d, &will_collide, obj, rot);
	if (will_collide == 1)
		move_attempt(d, pos, cos(rot.rot - res.obj_ref->rotation.rot)
			* speed, res.obj_ref->rotation);
	else if (will_collide < 1)
		move_attempt(d, pos, speed, rot);
	obj->z_ground = set_room_ground(d, obj->pos);
}

void	move_with_collide_player(t_data *d, t_point *pos, t_rot rot,
	float speed)
{
	int		will_collide;
	t_ray	res;

	will_collide = 0;
	res = check_collide_with_all_player(d, &will_collide, rot);
	if (will_collide == 1)
	{
		move_attempt(d, pos, cos(rot.rot - res.obj_ref->rotation.rot)
			* speed, res.obj_ref->rotation);
		move_grabbed_wall(d, res.obj_ref->rotation,
			cos(rot.rot - res.obj_ref->rotation.rot) * speed);
	}
	else if (will_collide < 1)
	{
		move_attempt(d, pos, speed, rot);
		move_grabbed_wall(d, rot, speed);
	}
	d->z_ground = set_room_ground(d, *pos);
}
