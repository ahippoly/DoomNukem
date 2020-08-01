/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_mobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:08 by alebui            #+#    #+#             */
/*   Updated: 2020/07/16 23:09:30 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	repulse_obj(t_obj *obj, float z_force)
{
	obj->z_force += z_force;
	obj->repulsed = 1;
}

void	load_repulsed_obj(t_data *d)
{
	int		i;
	t_obj	*obj;

	i = 0;
	while (i < d->nb_obj)
	{
		obj = &d->obj_list[i];
		if (obj->air_time > 0 && obj->repulsed == 1)
			move_with_collide(d, obj, get_angle(d->player_pos, obj->pos), 3);
		else
			obj->repulsed = 0;
		i++;
	}
}

void	shoot_gun(t_data *d, t_weapon *weapon)
{
	t_ray sorted[NB_MAX_OBJ];
	t_mob *origin;

	sort_ray_by_dist_player(d, d->player_pos, d->rot_calc, sorted);
	if (sorted[0].dist < weapon->range && sorted[0].room_id == TYPE_MOB)
	{
		origin = (t_mob*)sorted[0].obj_ref->origin;
		if (origin->life > -9999)
		{
			repulse_obj(sorted[0].obj_ref, weapon->z_force);
			change_mob_life(d, origin, weapon->dammage);
		}
	}
}

void	process_mobs_gameplay(t_data *d)
{
	load_repulsed_obj(d);
	move_mobs_in_range(d, d->mobs, d->nb_mob);
	process_mobs_anim(d);
}
