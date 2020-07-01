/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collide_z.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:24:44 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/01 15:46:08 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	init_wall_hit(int *wall_hit, int room_count)
{
	int i;

	i = 0;
	while (i < room_count)
		wall_hit[i++] = 0;
}

int		check_in_room(t_ray *ray, float pos_y, int *wall_hit)
{
	if (ray->inter.y > pos_y)
	{
		if (*wall_hit % 2 == 1)
			return (1);
		else
			*wall_hit = -NB_WALL_MAX;
	}
	*wall_hit += 1;
	return (0);
}

int		check_obj_room(t_data *d, t_point pos)
{
	int		wall_hits[NB_WALL_MAX];
	int		i;
	int		room_ref;
	t_ray	sorted[NB_MAX_OBJ];
	int		max;

	sort_ray_by_dist(d, (t_point){pos.x, 0},
		(t_rot){M_PI_2, cos(M_PI_2), sin(M_PI_2)}, sorted);
	init_wall_hit(wall_hits, d->map.room_count);
	i = 0;
	max = d->nb_obj;
	while (i < max)
	{
		if (sorted[i].dist > 9998)
			break ;
		if ((room_ref = sorted[i].room_id) > -1)
		{
			if (check_in_room(&sorted[i], pos.y, &wall_hits[room_ref]))
				return (room_ref);
		}
		i++;
	}
	return (-1);
}

float	set_room_ground(t_data *d, t_point pos)
{
	int room_id;

	if ((room_id = check_obj_room(d, pos)) > -1)
		return (d->map.room_list[room_id].z_ground);
	else
		return (DEFAULT_Z_GROUND);
}
