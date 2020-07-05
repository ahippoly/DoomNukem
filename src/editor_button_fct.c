/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_fct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:08:14 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/24 20:07:17 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK

void	select_next_texture(t_env *env)
{
	if (env->selected_texture == NB_TEXTURE - 1)
		env->selected_texture = 0;
	else
		env->selected_texture++;
	change_selected_wall_texture(env, env->selected_texture);
}

void	set_player_spawn_mode(t_env *env)
{
	env->mouse_icon = create_icon(create_t_point(0, 0),
			create_t_size(30, 30), 0);
	env->player_spawn = create_t_point(0, 0);
	env->being_placed = &env->player_spawn;
	env->selected_mouse_mode = MOUSE_MODE_PLACING;
}

void	mob_placing_mode(t_env *env)
{
	t_icon new;

	env->mouse_icon = create_icon(create_t_point(0, 0),
			create_t_size(30, 30), env->selected_mob);
	new = create_icon(create_t_point(-1, -1),
			create_t_size(30, 30), env->selected_mob);
	add_icon(env, new);
	env->being_placed = &env->icon_list[env->icon_count - 1].pos;
	env->selected_mouse_mode = MOUSE_MODE_PLACING;
}

void	del_selected_wall(t_env *env)
{
	del_wall(env, env->selected_wall_id);
	env->selected_wall_id = -1;
}

void	set_room_text(t_env *env)
{
	int tmp;
	
	if (env->selected_wall_id > -1)
		if ((tmp = env->wall_list[env->selected_wall_id].room_id_ref) != -1)
			env->room_text[tmp] = env->selected_texture;
}

void	create_room_button(t_env *env)
{
	env->selected_mouse_mode = MOUSE_MODE_CREATE_ROOM;
}
