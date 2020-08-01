/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:24:35 by alebui            #+#    #+#             */
/*   Updated: 2020/07/18 06:24:10 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int				read_param_wall(char *line, t_wall *wall)
{
	if ((read_param(line, "id", &wall->id)) == 1)
		return (-1);
	if ((read_paramf(line, "p1", &wall->p1.x)) == 1)
		return (-1);
	if ((read_paramf(line, "p2", &wall->p2.x)) == 1)
		return (-1);
	if ((read_param(line, "p1_height", &wall->p1_height.start)) == 1)
		return (-1);
	if ((read_param(line, "p2_height", &wall->p2_height.start)) == 1)
		return (-1);
	if ((read_param(line, "texture_id", &wall->texture_id)) == 1)
		return (-1);
	if ((read_param(line, "room_id_ref", &wall->room_id_ref)) == 1)
		return (-1);
	if ((read_param(line, "transparency", &wall->transparency)) == 1)
		return (-1);
	if ((read_param(line, "can_collide", &wall->can_collide)) == 1)
		return (-1);
	return (0);
}

t_wall_ref		*read_wall_ref(char *chunk)
{
	t_wall_ref	*wall_ref;

	wall_ref = NULL;
	wall_ref = add_wall_reference(wall_ref, ft_atoi(chunk));
	chunk = skip_until_char(chunk, ',', ' ');
	while (*chunk == ',')
	{
		chunk++;
		wall_ref = add_wall_reference(wall_ref, ft_atoi(chunk));
		chunk = skip_until_char(chunk, ',', ' ');
	}
	return (wall_ref);
}

int				read_wall_ref_list(int fd, t_map_data *map)
{
	char *line;

	if (get_next_line(fd, &line) == 1)
	{
		if ((read_param(line, "MAP_SIZE", &map->map_size.w)))
			return (-1);
	}
	else
	{
		ft_putendl("error while reading map");
		return (-1);
	}
	free(line);
	if (get_next_line(fd, &line) == 1)
	{
		if ((read_param(line, "PLAYER_SPAWN", &map->player_spawn.x)))
			return (-1);
	}
	else
	{
		ft_putendl("error while reading map");
		return (-1);
	}
	free(line);
	return (0);
}

int				read_icon(char *line, t_icon *icon)
{
	if ((read_param(line, "id", &icon->id_ref)) == 1)
	{
		ft_putendl("error while assigning value to icon on map reader\n");
		return (-1);
	}
	if ((read_param(line, "pos", &icon->pos_i.x)) == 1)
	{
		ft_putendl("error while assigning value to icon on map reader\n");
		return (-1);
	}
	return (0);
}
