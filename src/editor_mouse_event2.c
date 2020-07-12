/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_mouse_event2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:12:03 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 23:13:21 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void			on_screen_place_mode(t_env *env)
{
	if (env->being_placed != NULL)
		*env->being_placed = create_t_point(((float)env->mouse.x - GRID_POS_X
		- env->map_move.x) / TILE_SIZE, ((float)env->mouse.y
		- GRID_POS_Y - env->map_move.y) / TILE_SIZE);
	env->mouse_icon.id_ref = -1;
	env->selected_mouse_mode = MOUSE_MODE_NEUTRAL;
	env->being_placed = NULL;
}

static void		process_hovered_corner(t_env *env)
{
	int			room_ground;
	int			room_ceil;

	room_ground = env->input_lst[INPUT_ROOM_GROUND].value;
	room_ceil = env->input_lst[INPUT_ROOM_CEIL].value;
	env->selected_mouse_mode = 0;
	env->hovered_corner.x = -1;
	env->start_room_point = create_point(-1, -1);
	env->room_height[env->room_count].start = room_ground;
	env->room_height[env->room_count].end = room_ceil;
	env->room_text[env->room_count] = 0;
	env->room_count++;
}

void			create_room_mode(t_env *env)
{
	t_point		hov_corner;
	t_point		selec_corner;

	hov_corner = convert_sdlpoint2tpoint(env->hovered_corner);
	selec_corner = convert_sdlpoint2tpoint(env->selected_corner);
	if (env->hovered_corner.x != -1)
	{
		process_hovered_corner(env);
		if (env->selected_corner.x == -1)
			env->selected_corner = env->hovered_corner;
		else if (!add_wall(selec_corner, hov_corner, env))
			return ;
		if (env->start_room_point.x < 0)
		{
			env->start_room_point = env->selected_corner;
			env->first_wall_room_id = env->wall_count;
		}
		else if (env->hovered_corner.x == env->start_room_point.x
				&& env->hovered_corner.y == env->start_room_point.y)
			process_hovered_corner(env);
		env->selected_corner = env->hovered_corner;
	}
}
