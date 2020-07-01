/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_floor2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:19:54 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/01 16:20:18 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_draw	calc_floor_draw_range_end(t_data *d, float dist1, t_room *room, int x)
{
	t_draw	draw;

	draw.start_y = ft_max(d->screen_height
	+ ((d->player_height - room->z_ground) * WIN_SIZE_Y) / dist1, 0);
	draw.end_y = WIN_SIZE_Y;
	draw.start_x = x;
	return (draw);
}
