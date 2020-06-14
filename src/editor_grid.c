/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 04:55:20 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/14 01:52:07 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_header.h"
#include "editor.h"

void			create_grid(unsigned int *pixels, float scale, t_env *env)
{
	int			i;
	int			total_step;

	i = 0;
	while (i < GRID_SIZE_X)
	{
		draw_rectangle(pixels, set_sdl_rect(
			i + env->map_move.x % TILE_SIZE, 0, 1, GRID_SIZE_Y),
				set_size(GRID_SIZE_X, GRID_SIZE_Y), 0xffaabbff);
		i += TILE_SIZE;
	}
	i = 0;
	while (i < GRID_SIZE_Y)
	{
		draw_rectangle(pixels, set_sdl_rect(0,
		i + env->map_move.y % TILE_SIZE, GRID_SIZE_X, 1),
				set_size(GRID_SIZE_X, GRID_SIZE_Y), 0xffaabbff);
		i += TILE_SIZE;
	}
}

SDL_Point		check_tiles_hitbox(SDL_Point mouse,
	unsigned int *pixels, t_env *env)
{
	SDL_Point	rest;
	SDL_Point	adapted_point;
	SDL_Rect	box_pos;
	SDL_Point	map_pos;

	map_pos.x = -1;
	map_pos.y = -1;
	if (mouse.x < GRID_POS_X || mouse.x > GRID_POS_X + GRID_SIZE_X
			|| mouse.y < GRID_POS_Y || mouse.y > GRID_POS_Y + GRID_SIZE_Y)
		return (map_pos);
	adapted_point.x = (mouse.x + TILE_HITBOX - GRID_POS_X - env->map_move.x);
	adapted_point.y = (mouse.y + TILE_HITBOX - GRID_POS_Y - env->map_move.y);
	rest.x = adapted_point.x % TILE_SIZE;
	rest.y = adapted_point.y % TILE_SIZE;
	if (rest.x <= TILE_HITBOX * 2 && rest.y <= TILE_HITBOX * 2)
	{
		map_pos.x = adapted_point.x / TILE_SIZE;
		map_pos.y = adapted_point.y / TILE_SIZE;
		box_pos.x = map_pos.x * TILE_SIZE - TILE_HITBOX + env->map_move.x;
		box_pos.y = map_pos.y * TILE_SIZE - TILE_HITBOX + env->map_move.y;
		draw_rectangle(pixels, set_sdl_rect(box_pos.x, box_pos.y,
		TILE_HITBOX * 2, TILE_HITBOX * 2),
				set_size(GRID_SIZE_X, GRID_SIZE_Y), 0x0000ff00);
	}
	return (map_pos);
}

void			display_selected_point(t_env *env)
{
	int			hitbox;

	if (env->selected_corner.x != -1)
	{
		hitbox = TILE_HITBOX - 2;
		draw_rectangle(env->p_grid,
				set_sdl_rect(env->selected_corner.x * TILE_SIZE - hitbox / 2
					+ env->map_move.x,
					env->selected_corner.y * TILE_SIZE - hitbox / 2
					+ env->map_move.y, hitbox, hitbox),
				set_size(GRID_SIZE_X, GRID_SIZE_Y),
				0xFF0000FF);
	}
}
