/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_mobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:08 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 11:44:40 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	repulse_obj(t_data *d, t_obj *obj, float z_force)
{
	int i;

	i = 0;
	obj->z_force += z_force;
	while (i < d->nb_repulsed)
	{
		if (d->repulsed[i++] == obj)
			return ;
	}
	d->repulsed[d->nb_repulsed++] = obj;
}

void	load_repulsed_obj(t_data *d, t_obj **repulsed, int nb_pulse)
{
	int		i;
	t_obj	*obj;

	i = 0;
	while (i < nb_pulse)
	{
		obj = repulsed[i];
		if (obj->air_time > 0)
			move_with_collide(d, obj, get_angle(d->player_pos, obj->pos), 3);
		else
			del_from_array(*repulsed, &d->nb_repulsed, obj, sizeof(t_obj*));
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
			repulse_obj(d, sorted[0].obj_ref, weapon->z_force);
			change_mob_life(d, origin, weapon->dammage);
		}
	}
}

void	process_mobs_gameplay(t_data *d)
{
	load_repulsed_obj(d, d->repulsed, d->nb_repulsed);
	move_mobs_in_range(d, d->mobs, d->nb_mob);
	process_mobs_anim(d);
}
