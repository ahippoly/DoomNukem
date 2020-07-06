/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:24:31 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 20:41:39 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//A CHECK
static int read_wall_list(int fd, t_map_data *map)
{
    char    *line;
    int     i;

    if (get_next_line(fd, &line) == 1)
	{
		if ((read_param(line, "WALL_COUNT", &map->wall_count)))
			return (-1);
	}
    else
	{
		ft_putendl("error while reading map");
		return (-1);
	}
    // printf("WALL COUNT READED, value = %i\n", map->wall_count);
    if (!(map->wall_list = (t_wall*)malloc(sizeof(t_wall) * map->wall_count)))
    {
		ft_putendl("Failed to malloc");
		return (-1);
	}
    i = 0;
    while (get_next_line(fd, &line) == 1 && *line != '\0' && i < map->wall_count)
	{
        if ((read_wall(line, &map->wall_list[i++])) < 0)
			return (-1);
	}
	//printf("map reader, wall_count = %i\n", map->wall_count);
	return (0);
}

static int read_room_list(int fd, t_map_data *map)
{
    char *line;
    int i;

    if (get_next_line(fd, &line) == 1)
        read_param(line, "ROOM_COUNT", &map->room_count);
    else
	{
        ft_putendl("error while reading map");
		return (-1);
	}
    if (!(map->room_list = (t_room*)malloc(sizeof(t_room) * map->room_count)))
	{
        ft_putendl("Failed to malloc");
		return (-1);
	}
    i = 0;
    while (get_next_line(fd, &line) == 1 && *line != '\0' && i < map->room_count)
	{
		if ((read_room(line, &map->room_list[i++])) < 0)
			return (-1);
	}
	return (0);
}

static int	read_icon_list(int fd, t_map_data *map)
{
    char	*line;
    int		i;

    if (get_next_line(fd, &line) == 1)
        read_param(line, "ICON_COUNT", &map->icon_count);
    else
	{
        ft_putendl("error while reading map");
		return (-1);
	}
    if (!(map->icon_list = (t_icon*)malloc(sizeof(t_icon) * map->icon_count)))
	{
        ft_putendl("error : failed to malloc");
		return (-1);
	}
    i = 0;
    while (get_next_line(fd, &line) == 1 && *line != '\0' && i < map->icon_count)
	{
		if ((read_icon(line, &map->icon_list[i++])) < 0)
			return (-1);
	}
	i = 0;
	while (i < map->icon_count)
		i++;
	return (0);
}

static int		read_head(int fd, char *line, t_map_data *map)
{
    if (ft_strequ(line, "WALL LIST"))
	{
		if ((read_wall_list(fd, map)) < 0)
			return (-1);
	}
    if (ft_strequ(line, "ROOM LIST"))
		if ((read_room_list(fd, map)) < 0)
			return (-1);
	if (ft_strequ(line, "ICON LIST"))
		if ((read_icon_list(fd, map)) < 0)
			return (-1);
	if (ft_strequ(line, "WALL_REF MAP"))
		if ((read_wall_ref_list(fd, map)) < 0)
			return (-1);
	return (0);
}

t_map_data		read_map(char *path_file)
{
    int         fd;
    t_map_data	map;
    char		*line;

    map.is_valid = 0;
    line = NULL;
	map.wall_list = NULL;
	map.icon_list = NULL;
	map.room_list = NULL;
	map.player_spawn.x = 1;
	map.player_spawn.y = 1;
	if ((fd = open(path_file, O_RDONLY)) == -1)
		return (map);
	if (read(fd, line, 0) == -1)
		return (map);
	map.icon_count = 0;
	map.wall_count = 0;
	map.room_count = 0;
    while (get_next_line(fd, &line) == 1)
	{
		if ((read_head(fd, line, &map)) < 0)
			map.is_valid = -1;
	}
    map.is_valid = 1;
    close(fd);
    return (map);
}