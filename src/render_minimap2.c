/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:48:55 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 03:39:33 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_point	calc_map_scale(t_map_data *map)
{
	t_point	scale;

	scale.x = (float)MINI_MAP_SIZE_X / map->map_size.w;
	scale.y = (float)MINI_MAP_SIZE_Y / map->map_size.h;
	return (scale);
}

void	draw_wall_mini_map(t_data *d, t_wall wall, t_point scale,
	t_map_data *map)
{
	t_point diff_pos;

	diff_pos.x = -d->player_pos.x + map->map_size.w * 0.5;
	diff_pos.y = -d->player_pos.y + map->map_size.h * 0.5;
	draw_line(create_point(scale.x * (wall.p1.x + diff_pos.x),
				scale.y * (wall.p1.y + diff_pos.y)),
			create_point(scale.x * (wall.p2.x + diff_pos.x),
				scale.y * (wall.p2.y + diff_pos.y)),
			(t_img){d->p_mini_map_bg, (SDL_Rect){0, 0,
			MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y}, 0, 0},
			0xFFFFBB88);
}

void	create_mini_map(t_data *d, t_map_data *map)
{
	int		i;
	t_point	scale;

	free(d->p_mini_map_bg);
	if (!(d->p_mini_map_bg = alloc_image(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y)))
		exit_game(d, "error : failed to malloc mini map background");
	draw_rectangle(d->p_mini_map_bg, set_sdl_rect(0, 0, MINI_MAP_SIZE_X,
	MINI_MAP_SIZE_Y), set_size(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y), 0xFF77AA77);
	draw_rectangle(d->p_mini_map_bg, set_sdl_rect(2, 2, MINI_MAP_SIZE_X - 4,
	MINI_MAP_SIZE_Y - 4), set_size(MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y),
			0xFF000000);
	scale.x = (float)MINI_MAP_SIZE_X / map->map_size.w;
	scale.y = (float)MINI_MAP_SIZE_Y / map->map_size.h;
	i = 0;
	while (i < map->wall_count)
		draw_wall_mini_map(d, map->wall_list[i++], scale, map);
}
