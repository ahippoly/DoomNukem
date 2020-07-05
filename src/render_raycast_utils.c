/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:35:04 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/05 16:42:41 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	clear_p_tab(t_range screen_x, unsigned int *p_tab)
{
	int i;
	int end_y;

	end_y = WIN_SIZE_Y * WIN_SIZE_X;
	while (screen_x.start < screen_x.end)
	{
		i = 0;
		while (i < end_y)
		{
			p_tab[screen_x.start + i] = 0x00000000;
			i += WIN_SIZE_X;
		}
		screen_x.start++;
	}
}

t_room	*get_room_by_id(t_data *d, int room_id)
{
	if (room_id > -1)
		return (&d->map.room_list[room_id]);
	else
		return (NULL);	    //ATTENTION
}

void	add_to_queue(int *nb, t_ray *queue, t_ray *checked)
{
	if (checked->room_id > -1)
	{
		(*nb)++;
		queue[*nb] = *checked;
	}
}

void	draw_same_room(t_data *d, t_ray *ray, t_ray *checked, int x)
{
	if (ray->dist < RENDER_DISTANCE_MAX)
		print_floor_slice(d, d->fl[ray->room_id], calc_floor_draw_range(d,
		*ray, checked->dist, x), get_room_by_id(d, ray->room_id)->floor_text);
	ray->dist = checked->dist;
}