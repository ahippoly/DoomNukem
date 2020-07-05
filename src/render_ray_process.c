/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:45:10 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 01:03:48 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_ray	check_inter_with_obj(t_obj *obj, t_rot rot, t_point pos, t_rot look_rot)
{
	t_ray res;

	res.dist = 9999;
	res.scale = 0;
	res.inter = inter_with_dir(pos, rot, obj->p1, obj->p2);
	res.obj_ref = obj;
	res.room_id = obj->room_id;
	if (res.inter.x != -42)
	{
		res.dist = ft_frange((look_rot.cos_rot) * (res.inter.x - pos.x)
			+ (look_rot.sin_rot) * (res.inter.y - pos.y), 0.00000042, res.dist);
		res.scale = calc_ray_hit_scale(obj->p1, obj->p2, res.inter);
		res.mod_scale = get_float_part(res.scale * obj->length);
		res.z_height.pos = obj->z_height.pos + obj->z_step.pos * res.scale;
		res.z_height.size = obj->z_height.size + obj->z_step.size * res.scale;
		if (res.room_id < -1)
			res.z_text = 1;
		else
			res.z_text = res.z_height.size;
	}
	return (res);
}

t_ray	check_perp_obj(t_obj *obj, t_point pos)
{
	t_point	p1;
	t_point	p2;
	t_ray	res;
	t_rot	look_rot;

	init_ray(&res, obj);
	look_rot.cos_rot = cos(obj->rotation.rot + M_PI_2);
	look_rot.sin_rot = sin(obj->rotation.rot + M_PI_2);
	init_perp_points(&p1, &p2, pos, look_rot);
	if (obj->can_collide == 0)
		return (res);
	res.inter = find_intersect(p1, p2, obj->p1, obj->p2);
	if (res.inter.x != -42)
	{
		res.dist = fabs((look_rot.cos_rot) * (res.inter.x - pos.x)
			+ (look_rot.sin_rot) * (res.inter.y - pos.y));
		res.scale = calc_ray_hit_scale(obj->p1, obj->p2, res.inter);
		res.mod_scale = get_float_part(res.scale * obj->length);
		res.z_height.pos = obj->z_height.pos + obj->z_step.pos * res.scale;
		res.z_height.size = obj->z_height.size + obj->z_step.size * res.scale;
		define_z_text(&res);
	}
	return (res);
}

void	sort_ray_by_dist_player(t_data *d, t_point pos,
	t_rot current_angle, t_ray *sorted)
{
	int			i;
	int			j;
	int			tmp;
	t_ray		ray;

	sorted[0] = check_inter_with_obj(&d->obj_list[0], current_angle,
		pos, d->rot_calc);
	i = 1;
	while (i < d->nb_obj)
	{
		ray = check_inter_with_obj(&d->obj_list[i], current_angle,
			pos, d->rot_calc);
		j = 0;
		while (ray.dist > sorted[j].dist && j < i)
			j++;
		tmp = j;
		j = i;
		while (j-- > tmp)
			sorted[j + 1] = sorted[j];
		sorted[j + 1] = ray;
		i++;
	}
}

void	sort_ray_by_dist(t_data *d, t_point pos, t_rot current_angle,
	t_ray *sorted)
{
	int			i;
	int			j;
	int			tmp;
	t_ray		ray;

	sorted[0] = check_inter_with_obj(&d->obj_list[0],
		current_angle, pos, current_angle);
	i = 1;
	while (i < d->nb_obj)
	{
		ray = check_inter_with_obj(&d->obj_list[i], current_angle,
			pos, current_angle);
		j = 0;
		while (ray.dist > sorted[j].dist && j < i)
			j++;
		tmp = j;
		j = i;
		while (j-- > tmp)
			sorted[j + 1] = sorted[j];
		sorted[j + 1] = ray;
		i++;
	}
}

void	sort_perp_ray(t_data *d, t_point pos, t_ray *sorted)
{
	int			i;
	int			j;
	int			tmp;
	t_ray		ray;

	sorted[0] = check_perp_obj(&d->obj_list[0], pos);
	i = 1;
	while (i < d->nb_obj)
	{
		ray = check_perp_obj(&d->obj_list[i], pos);
		j = 0;
		while (ray.dist > sorted[j].dist && j < i)
			j++;
		tmp = j;
		j = i;
		while (j > tmp)
		{
			j--;
			sorted[j + 1] = sorted[j];
		}
		sorted[j] = ray;
		i++;
	}
}
