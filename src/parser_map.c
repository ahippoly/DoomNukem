/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:24:31 by alebui            #+#    #+#             */
/*   Updated: 2020/07/18 06:08:33 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static int		read_room_list(int fd, t_map_data *map)
{
	char	*line;
	int		i;

	if (get_next_line(fd, &line) == 1)
		read_param(line, "ROOM_COUNT", &map->room_count);
	else
		return (-1);
	if (!(map->room_list = (t_room*)malloc(sizeof(t_room) * map->room_count)))
		return (-1);
	i = 0;
	free(line);
	while (get_next_line(fd, &line) == 1 && *line != '\0' &&
			i < map->room_count)
	{
		if ((read_room(line, &map->room_list[i++])) < 0)
			return (-1);
		free(line);
	}
	free(line);
	return (0);
}

static int		read_icon_list(int fd, t_map_data *map)
{
	char	*line;
	int		i;

	if (get_next_line(fd, &line) == 1)
	{
		read_param(line, "ICON_COUNT", &map->icon_count);
		free(line);
	}
	else
		return (-1);
	if (!(map->icon_list = (t_icon*)malloc(sizeof(t_icon) * map->icon_count)))
		return (-1);
	i = 0;
	while (get_next_line(fd, &line) == 1 && *line != '\0' &&
			i < map->icon_count)
	{
		if ((read_icon(line, &map->icon_list[i++])) < 0)
			return (-1);
		free(line);
	}
	free(line);
	return (0);
}

static int		read_head(int fd, char *line, t_map_data *map)
{
	int found;

	found = 0;
	if (ft_strnequ(line, "WALL LIST", 15))
		if (++found && (read_wall_list(fd, map)) < 0)
			return (-1);
	if (ft_strnequ(line, "ROOM LIST", 15))
	{
		if (++found && (read_room_list(fd, map)) < 0)
			return (-1);
	}
	if (ft_strnequ(line, "ICON LIST", 15))
	{
		if (++found && (read_icon_list(fd, map)) < 0)
			return (-1);
	}
	if (ft_strnequ(line, "WALL_REF MAP", 15))
	{
		if (++found && (read_wall_ref_list(fd, map)) < 0)
			return (-1);
	}
	if (found == 0)
		return (-1);
	return (0);
}

static void		map_init(t_map_data *map)
{
	map->is_valid = 0;
	map->wall_list = NULL;
	map->icon_list = NULL;
	map->room_list = NULL;
	map->player_spawn.x = 1;
	map->player_spawn.y = 1;
	map->icon_count = 0;
	map->wall_count = 0;
	map->room_count = 0;
}

t_map_data		read_map(char *path_file)
{
	int			fd;
	t_map_data	map;
	char		*line;

	line = NULL;
	map_init(&map);
	if ((fd = open(path_file, O_RDONLY)) == -1)
		return (map);
	if (read(fd, line, 0) == -1)
		return (map);
	map.is_valid = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if ((read_head(fd, line, &map)) < 0)
			map.is_valid = -1;
		free(line);
	}
	free(line);
	close(fd);
	return (map);
}
