/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_map_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:30:07 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/25 16:50:58 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

// OKK
static void	*ft_memcpy2(void *s1, const void *s2, size_t n)
{
	char	*c1;
	char	*c2;

	if (n == 0 || s1 == s2)
		return (s1);
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (s1);
}

static void	map2env_icon(t_env *e, t_map_data *map, int i)
{
	e->icon_count = map->icon_count;
	ft_memcpy2(e->icon_list , map->icon_list, sizeof(t_icon) * map->icon_count);
	i = 0;
	while (i < map->icon_count)
	{
		e->icon_list[i].pos.x = (double)e->icon_list[i].pos_i.x / UNIT;
		e->icon_list[i].pos.y = (double)e->icon_list[i].pos_i.y / UNIT;
		e->icon_list[i].size = (t_size){ICON_DEFAULT_SIZE, ICON_DEFAULT_SIZE};
		i++;
	}
	free(map->icon_list);
}

static void	map2env_room(t_env *e, t_map_data *map, int i)
{
	e->room_count = map->room_count;
	i = 0;
	while (i < map->room_count)
	{
		e->room_height[i].start = map->room_list[i].height.start;
		e->room_height[i].end = map->room_list[i].height.end;
		e->room_text[i] = map->room_list[i].floor_text;
		i++;
	}
	free(map->room_list);
}

static void	map2env(t_env *e, t_map_data *map)
{
	int	i;

	if (map->is_valid != 1)
		exit_editor(e, "error : failed to read map, initializing new map");
	e->wall_count = map->wall_count;
	ft_memcpy2(e->wall_list, map->wall_list, sizeof(t_wall) * map->wall_count);
	free(map->wall_list);
	map2env_icon(e, map, i);
	map2env_room(e, map, i);
	e->player_spawn.x = map->player_spawn.x;
	e->player_spawn.y = map->player_spawn.y;
	// print_player_spawn(e);
}

void		load_map(t_env *e, int ac, char **av)
{
	t_map_data map;
	
	if (ac > 1)
	{
		e->map_name = strdup(av[1]);
		map = read_map(av[1]);
		map2env(e, &map);
	}
}