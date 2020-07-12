/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_add_del3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:24:27 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/08 00:26:11 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	rearange_room_id(t_env *env)
{
	t_wall	wall;
	int		new_nb_room;
	int		i;

	i = 0;
	new_nb_room = 0;
	while (i < env->wall_count)
	{
		wall = env->wall_list[i];
		if (wall.room_id_ref != -1)
		{
			while (env->wall_list[i].room_id_ref == wall.room_id_ref
				&& i < env->wall_count)
			{
				env->wall_list[i].room_id_ref = new_nb_room;
				i++;
			}
			i--;
			new_nb_room++;
		}
		i++;
	}
}
