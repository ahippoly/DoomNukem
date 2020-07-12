/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_init_data3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 04:37:07 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/08 04:42:59 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static int		malloc_editor_button(t_env *env)
{
	if (!(env->buttons_lst = malloc_button(NB_BUTTONS)))
		exit_editor(env, "error: failes to malloc editor buttons");
	return (0);
}

t_button		create_txt_button(char *name, SDL_Point pos,
	SDL_Point color, SDL_Point button_param)
{
	return (create_button(create_text_img(name, button_param.x, color.x, pos),
		create_text_img(name, button_param.x, color.y, pos), button_param.y));
}

static void		init_create_button(t_env *env)
{
	env->buttons_lst[BUTTON_DEL] = create_txt_button("del", create_point(0.85
		* WIN_SIZE_X, 0.020 * WIN_SIZE_Y),
		(SDL_Point){0xFF8888FF, 0xFFFFFFFF}, (SDL_Point){2, BUTTON_DEL});
	env->buttons_lst[BUTTON_TEXT_LEFT] = create_txt_button("<",
		create_point(0.762 * WIN_SIZE_X, 0.195 * WIN_SIZE_Y),
		(SDL_Point){0xFFDDDDDD, 0xFF88FF88}, (SDL_Point){2, BUTTON_TEXT_LEFT});
	env->buttons_lst[BUTTON_TEXT_RIGHT] = create_txt_button(">",
		create_point(0.958 * WIN_SIZE_X, 0.195 * WIN_SIZE_Y),
		(SDL_Point){0xFFDDDDDD, 0xFF88FF88}, (SDL_Point){2, BUTTON_TEXT_RIGHT});
	env->buttons_lst[BUTTON_CREATE_ROOM] = create_txt_button("Create_room",
		create_point(0.730 * WIN_SIZE_X, 0.850 * WIN_SIZE_Y),
		(SDL_Point){0xFFFF88CC, 0xFFFFFFFF}, (SDL_Point){1,
		BUTTON_CREATE_ROOM});
	init_create_button2(env);
}

static void		init_select_button(t_env *env)
{
	env->buttons_fct[BUTTON_DEL] = del_selected_wall;
	env->buttons_fct[BUTTON_TEXT_LEFT] = select_previous_texture;
	env->buttons_fct[BUTTON_TEXT_RIGHT] = select_next_texture;
	env->buttons_fct[BUTTON_CREATE_ROOM] = create_room_button;
	env->buttons_fct[BUTTON_MAP_OUTPUT] = map_output;
	env->buttons_fct[BUTTON_SET_PLAYER_SPAWN] = set_player_spawn_mode;
	env->buttons_fct[BUTTON_MOB_LEFT] = select_previous_mob;
	env->buttons_fct[BUTTON_MOB_RIGHT] = select_next_mob;
	env->buttons_fct[BUTTON_MOB_PLACING] = mob_placing_mode;
	env->buttons_fct[BUTTON_FLOOR_TEXT] = set_room_text;
}

void			init_buttons(t_env *env)
{
	malloc_editor_button(env);
	init_create_button(env);
	init_select_button(env);
}
