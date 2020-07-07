/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:29:07 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 22:47:02 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_input		create_t_input(SDL_Rect pos_size, int default_value, int max)
{
	t_input input;

	input.pos_size = pos_size;
	input.value = default_value;
	input.max = max;
	input.is_in_input_mode = 0;
	return (input);
}

void		apply_update_wall(t_env *env)
{
	int		tmp;
	t_wall	*wall;
	t_range	*room_h;

	wall = &env->wall_list[env->selected_wall_id];
	if (env->selected_input == INPUT_TRANSPARENCY)
		wall->transparency = env->input_lst[INPUT_TRANSPARENCY].value;
	if (env->selected_input == INPUT_BEGIN_P1)
		wall->p1_height.start = env->input_lst[INPUT_BEGIN_P1].value;
	if (env->selected_input == INPUT_BEGIN_P2)
		wall->p2_height.start = env->input_lst[INPUT_BEGIN_P2].value;
	if (env->selected_input == INPUT_END_P1)
		wall->p1_height.end = env->input_lst[INPUT_END_P1].value;
	if (env->selected_input == INPUT_END_P2)
		wall->p2_height.end = env->input_lst[INPUT_END_P2].value;
	if (env->selected_input == INPUT_COLLIDE)
		wall->can_collide = env->input_lst[INPUT_COLLIDE].value;
	if ((tmp = wall->room_id_ref) > -1)
	{
		room_h = &env->room_height[tmp];
		if (env->selected_input == INPUT_ROOM_GROUND)
			room_h->start = env->input_lst[INPUT_ROOM_GROUND].value;
		if (env->selected_input == INPUT_ROOM_CEIL)
			room_h->end = env->input_lst[INPUT_ROOM_CEIL].value;
	}
}

void		update_wall_param(t_env *env)
{
	if (env->selected_input != -1 && env->selected_wall_id != -1)
		apply_update_wall(env);
}

void		get_wall_param(t_env *env)
{
	int		tmp;
	t_wall	*wall;

	wall = &env->wall_list[env->selected_wall_id];
	env->selected_texture = wall->texture_id;
	env->input_lst[INPUT_TRANSPARENCY].value = wall->transparency;
	env->input_lst[INPUT_BEGIN_P1].value = wall->p1_height.start;
	env->input_lst[INPUT_BEGIN_P2].value = wall->p2_height.start;
	env->input_lst[INPUT_END_P1].value = wall->p1_height.end;
	env->input_lst[INPUT_END_P2].value = wall->p2_height.end;
	env->input_lst[INPUT_COLLIDE].value = wall->can_collide;
	if ((tmp = wall->room_id_ref) > -1)
	{
		env->input_lst[INPUT_ROOM_GROUND].value = env->room_height[tmp].start;
		env->input_lst[INPUT_ROOM_CEIL].value = env->room_height[tmp].end;
	}
}
