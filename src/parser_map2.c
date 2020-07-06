/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:24:35 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 21:06:04 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
static void	set_wall(t_wall *wall)
{
    wall->length = hypot(wall->p2.x - wall->p1.x, wall->p2.y - wall->p1.y);
    wall->rotation = calc_line_angle(wall->p1, wall->p2);
    wall->alpha = (float)(100 - wall->transparency) / 100;
	wall->p1_z_start = (float)wall->p1_height.start / UNIT;
	wall->p1_z_size = (float)(wall->p1_height.end - wall->p1_height.start) / UNIT;
	wall->p2_z_start = (float)wall->p2_height.start / UNIT;
	wall->p2_z_size = (float)(wall->p2_height.end - wall->p2_height.start) / UNIT;
	wall->z_text_offset = 0;
}

int		read_param_wall(char *line, t_wall *wall)
{
	if ((read_param(line, "id", &wall->id)) == 1)
		return (-1);
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

int		read_wall(char *line, t_wall *wall)
{
	if ((read_param_wall(line, wall)) < 0)
		return (-1);
	set_wall(wall);
	return (0);
}

int		read_room(char *line, t_room *room)
{
    int error;

    error = 0;
    error += read_param(line, "id", &room->room_id);
    error += read_param(line, "nb_wall", &room->nb_wall);
    error += read_param(line, "wall_ref_range", &room->wall_ref.start);
	error += read_param(line, "height", &room->height.start);
	error += read_param(line, "floor_text", &room->floor_text);
    if (error > 0)
	{
		ft_putendl("error while assigning value to room on map reader\n");
		return (-1);
	}
	room->z_ground = (float)room->height.start / UNIT;
	room->z_ceil = (float)room->height.end / UNIT;
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

int read_wall_ref_list(int fd, t_map_data *map)
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
	return (0);
}

int		read_icon(char *line, t_icon *icon)
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