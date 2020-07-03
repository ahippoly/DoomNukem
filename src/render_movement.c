/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:40:04 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 01:13:28 by ahippoly         ###   ########.fr       */
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

int		check_collide(t_data *d, t_ray res, t_obj *obj)
{
	if (res.z_height.pos + res.z_height.size > obj->z_height.pos
			&& res.z_height.pos - d->z_offset < obj->z_height.pos)
		return (1);
	return (0);
}

t_ray	check_collide_with_all(t_data *d, int *will_collide, t_obj *obj, t_rot rot)
{
	int		i;
	t_point	inter;
	float	diff_x;
	t_point	pos;
	t_ray	sorted[NB_MAX_OBJ];

	i = -1;
	pos = obj->pos;
	sort_perp_ray(d, pos, sorted);
	while (++i < d->nb_obj)
	{
		if (sorted[i].dist < WALL_SIZE)
		{
			inter = find_intersect_no_bound(pos, (t_point){pos.x
			+ (rot.cos_rot), pos.y + (rot.sin_rot)},
			(sorted[i].obj_ref->p1), (sorted[i].obj_ref->p2));
			diff_x = inter.x - pos.x;
			if ((diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0
				&& (rot.cos_rot) < 0))
				if ((*will_collide += check_collide(d , sorted[i], obj)) > 1)
					break;
		}
	}
	return (sorted[i]);
}

void	move_with_collide(t_data *d, t_obj *obj, t_rot rot, float speed)
{
	t_ray	sorted[NB_MAX_OBJ];
	int		will_collide;
	t_ray	res;
	t_point	*pos;

	pos = &obj->pos;
	will_collide = 0;
	res = check_collide_with_all(d, &will_collide, obj, rot);
	if (will_collide == 1)
		move_attempt(d, pos, cos(rot.rot - res.obj_ref->rotation.rot) * speed, res.obj_ref->rotation);
	else if (will_collide < 1)
		move_attempt(d, pos, speed, rot);
	obj->z_ground = set_room_ground(d, obj->pos);
}

void	move_with_collide_player(t_data *d, t_point *pos, t_rot rot, float speed)
{
	t_ray	sorted[NB_MAX_OBJ];
	t_point inter;
	float	diff_x;
	int		will_collide;
	int		i;
	t_ray	res;

	sort_perp_ray(d, *pos, sorted);
	i = 0;
	will_collide = 0;
	while (i < d->nb_obj)
	{
		if (sorted[i].dist < WALL_SIZE)
		{
			inter = find_intersect_no_bound(*pos, (t_point){pos->x + (rot.cos_rot), pos->y + (rot.sin_rot)}, (sorted[i].obj_ref->p1), (sorted[i].obj_ref->p2));
			diff_x = inter.x - pos->x;
			if ( (diff_x > 0 && (rot.cos_rot) > 0) || (diff_x < 0 && (rot.cos_rot) < 0) )
			{
				res = sorted[i];
				if (res.z_height.pos + res.z_height.size > d->z_pos
						&& res.z_height.pos - d->z_offset < d->z_pos)
					if (++will_collide > 1)
						break;
			}
		}
		i++;
	}
	if (will_collide == 1)
	{
		move_attempt(d, pos, cos(rot.rot - res.obj_ref->rotation.rot) * speed, res.obj_ref->rotation);
		move_grabbed_wall(d, res.obj_ref->rotation, cos(rot.rot - res.obj_ref->rotation.rot) * speed);
	}
	else if (will_collide < 1)
	{
		move_attempt(d, pos, speed, rot);
		move_grabbed_wall(d, rot, speed);
	}
	d->z_ground = set_room_ground(d, *pos);
}

void	gravity_obj(t_data *d, t_obj *objs, int nb_obj)
{
	int		i;
	t_obj	*obj;

	i = 0;
	while (i < nb_obj)
	{
		obj = &objs[i];
		if (obj->z_ground > -1)
		{
			obj->z_height.pos += obj->z_force;
			if (obj->z_height.pos > obj->z_ground)
			{
				obj->z_height.pos -=  GRAVITY_FORCE * obj->air_time * obj->air_time ;
				obj->air_time += d->time - d->time_last_frame;
			}
			obj->z_text_offset = obj->z_height.pos + obj->z_height.size;
			if (obj->z_height.pos < obj->z_ground)
			{
				obj->z_height.pos = obj->z_ground;
				obj->z_force = 0;
				obj->air_time = 0;
			}
		}
		i++;
	}
}

void	gravity(t_data *d)
{
	d->z_pos += d->z_force;
	d->player_height = d->z_pos + d->z_offset;
	if (d->z_pos > d->z_ground)
	{
		d->z_pos -= GRAVITY_FORCE * d->air_time * d->air_time ;
		d->air_time += d->time - d->time_last_frame;
	}
	if (d->z_pos < d->z_ground)
	{
		d->z_pos = d->z_ground;
		d->z_force = 0;
		d->air_time = 0;
	}
	gravity_obj(d, d->obj_list, d->nb_obj);
}

