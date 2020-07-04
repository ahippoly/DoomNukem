/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gravity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:17:59 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 20:21:14 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	gravity_obj(t_data *d, t_obj *objs, int nb_obj)
{
	int		i;
	t_obj	*obj;

	i = 0;
	while (i < nb_obj)
	{
		obj = &objs[i++];
		if (obj->z_ground > -1)
		{
			obj->z_height.pos += obj->z_force;
			if (obj->z_height.pos > obj->z_ground)
			{
				obj->z_height.pos -= GRAVITY_FORCE * obj->air_time
					* obj->air_time;
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
	}
}

void	gravity(t_data *d)
{
	d->z_pos += d->z_force;
	d->player_height = d->z_pos + d->z_offset;
	if (d->z_pos > d->z_ground)
	{
		d->z_pos -= GRAVITY_FORCE * d->air_time * d->air_time;
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
