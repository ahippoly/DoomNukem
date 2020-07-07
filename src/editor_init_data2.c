/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_init_data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:44:40 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 22:56:26 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void		init_input2(t_env *env)
{
	env->input_lst[INPUT_ROOM_GROUND] = create_t_input(
		set_sdl_rect(0.200 * WIN_SIZE_X, 0.890 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
	env->input_lst[INPUT_ROOM_CEIL] = create_t_input(
		set_sdl_rect(0.305 * WIN_SIZE_X, 0.890 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
	env->input_lst[INPUT_COLLIDE] = create_t_input(
		set_sdl_rect(0.530 * WIN_SIZE_X, 0.900 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 1, 1);
}

void			init_input(t_env *env)
{
	if (!(env->input_lst = malloc_input(NB_INPUT)))
		exit_editor(env, "error : failed to malloc");
	env->input_lst[INPUT_TRANSPARENCY] = create_t_input(
		set_sdl_rect(0.835 * WIN_SIZE_X, 0.650 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 0, 100);
	env->input_lst[INPUT_BEGIN_P1] = create_t_input(
		set_sdl_rect(0.200 * WIN_SIZE_X, 0.720 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
	env->input_lst[INPUT_BEGIN_P2] = create_t_input(
		set_sdl_rect(0.305 * WIN_SIZE_X, 0.720 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 20, 190);
	env->input_lst[INPUT_END_P1] = create_t_input(
		set_sdl_rect(0.200 * WIN_SIZE_X, 0.780 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
	env->input_lst[INPUT_END_P2] = create_t_input(
		set_sdl_rect(0.305 * WIN_SIZE_X, 0.780 * WIN_SIZE_Y,
		0.060 * WIN_SIZE_X, 0.040 * WIN_SIZE_Y), 30, 200);
	init_input2(env);
}

static void		init_env2(t_env *env)
{
	env->p1_height = create_t_range(0, 10);
	env->p2_height = create_t_range(0, 10);
	env->map_move = create_point(0, 0);
	env->hovered_wall_id = -1;
	env->selected_wall_id = -1;
	env->selected_input = -1;
	env->room_list = NULL;
	env->map_name = NULL;
	if (!(env->wall_list = (t_wall*)malloc(sizeof(t_wall) * NB_WALL_MAX)))
		exit_editor(env, "error: failed to malloc");
	env->quit = 0;
}

static int		malloc_env(t_env *env)
{
	if (!(env->room_height = malloc_range(NB_WALL_MAX)))
		exit_editor(env, "error: failed to malloc rooms");
	if (!(env->room_text = malloc_int_tab(NB_WALL_MAX)))
		exit_editor(env, "error: failed to malloc room texture");
	if (!(env->sprite_img = malloc_img(NB_SPRITE)))
		exit_editor(env, "error: failed to malloc sprites");
	if (!(env->sprites = malloc_ssprite(NB_SPRITE)))
		exit_editor(env, "error : failed to malloc sprites");
	if (!(env->p_screen = alloc_image(WIN_SIZE_X, WIN_SIZE_Y)))
		exit_editor(env, "error : failed to malloc");
	if (!(env->p_grid = alloc_image(GRID_SIZE_X, GRID_SIZE_Y)))
		exit_editor(env, "error : failed to malloc");
	return (1);
}

void			init_env(t_env *env)
{
    init_sdl_ressources(env);
	malloc_env(env);
	init_texture(env);
	init_buttons(env);
	init_txt_img(env);
	init_mouse_mode(env);
	init_sprites_img_env(env);
	env->sprites[SPRITE_ID_AFRIT] = sprite_init_afrit(
		env->sprite_img[SPRITE_ID_AFRIT]);
	env->sprites[SPRITE_ID_PYRO] = sprite_init_pyro(
		env->sprite_img[SPRITE_ID_PYRO]);
	init_img(env);
	env->map_size = create_t_size(MAP_SIZE_X, MAP_SIZE_Y);
	init_input(env);
	env->map_wall_ref = init_wall_ref(env->map_size);
	env->grid_pos = set_sdl_rect(GRID_POS_X, GRID_POS_Y,
		GRID_SIZE_X, GRID_SIZE_Y);
	env->wall_count = 0;
	env->room_count = 0;
	env->icon_count = 0;
	env->player_spawn = create_t_point(0, 0);
	env->total_wall_created = 0;
	env->selected_corner.x = -1;
	env->mouse_icon.id_ref = -1;
	init_env2(env);
}
