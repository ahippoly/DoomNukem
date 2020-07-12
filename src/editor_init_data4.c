/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_init_data4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:11:41 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/08 02:33:09 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void			init_sprites_env(t_env *env)
{
	if (!(env->img_list[IMG_AFRIT] = SDL_CreateTexture(env->rend,
		SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING,
		env->sprites[SPRITE_ID_AFRIT].dst_w,
		env->sprites[SPRITE_ID_AFRIT].dst_h)))
		exit_editor(env, "error : failed to create texture");
	SDL_SetTextureBlendMode(env->img_list[IMG_AFRIT], SDL_BLENDMODE_BLEND);
	if (!(env->img_list[IMG_ORC] = SDL_CreateTexture(env->rend,
		SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING,
		env->sprites[SPRITE_ID_PYRO].dst_w,
		env->sprites[SPRITE_ID_PYRO].dst_h)))
		exit_editor(env, "error : failed to create texture");
	SDL_SetTextureBlendMode(env->img_list[IMG_ORC], SDL_BLENDMODE_BLEND);
}

void			init_img(t_env *env)
{
	if (!(env->img_list = malloc_texture_tab(NB_IMG)))
		exit_editor(env, "error : failed to malloc texture tab");
	env->icon_count = 0;
	env->selected_mob = 0 + ICON_MOB_RANGE_BEGIN;
	if (!(env->icon_list = (t_icon*)p_malloc(sizeof(t_icon) * ICON_ARRAY_SIZE)))
		exit_editor(env, "error: failed to malloc");
	env->being_placed = NULL;
	env->icon_list_size = ICON_ARRAY_SIZE;
	if (!(env->img_list[IMG_PLAYER] = bmp_to_texture(IMG_PATH_0, env->rend)))
		exit_editor(env, "error : failed to transform bmp to texture");
	if (!(env->img_list[IMG_KEY] = bmp_to_texture(IMG_PATH_3, env->rend)))
		exit_editor(env, "error : failed to transform bmp to texture");
	if (!(env->img_list[IMG_HEAL_PACK] = bmp_to_texture(IMG_PATH_4, env->rend)))
		exit_editor(env, "error : failed to transform bmp to texture");
	if (!(env->img_list[IMG_SHIP] = bmp_to_texture(IMG_PATH_5, env->rend)))
		exit_editor(env, "error : failed to transform bmp to texture");
	if (!(env->img_list[IMG_JETPACK] = bmp_to_texture(IMG_PATH_6, env->rend)))
		exit_editor(env, "error : failed to transform bmp to texture");
	init_sprites_env(env);
}

void			init_create_button2(t_env *env)
{
	env->buttons_lst[BUTTON_MAP_OUTPUT] = create_txt_button("Map_output",
		create_point(0.730 * WIN_SIZE_X, 0.800 * WIN_SIZE_Y),
		(SDL_Point){0xFFFF88CC, 0xFFFFFFFF}, (SDL_Point){1, BUTTON_MAP_OUTPUT});
	env->buttons_lst[BUTTON_SET_PLAYER_SPAWN] = create_txt_button(
		"set_player_spawn", create_point(0.730 * WIN_SIZE_X, 0.900
		* WIN_SIZE_Y),
		(SDL_Point){0xFFFF88CC, 0xFFFFFFFF}, (SDL_Point){1,
		BUTTON_SET_PLAYER_SPAWN});
	env->buttons_lst[BUTTON_MOB_LEFT] = create_txt_button("<",
		create_point(0.762 * WIN_SIZE_X, 0.445 * WIN_SIZE_Y),
		(SDL_Point){0xFFDDDDDD, 0xFF88FF88}, (SDL_Point){2, BUTTON_MOB_LEFT});
	env->buttons_lst[BUTTON_MOB_RIGHT] = create_txt_button(">",
		create_point(0.958 * WIN_SIZE_X, 0.445 * WIN_SIZE_Y),
		(SDL_Point){0xFFDDDDDD, 0xFF88FF88}, (SDL_Point){2, BUTTON_MOB_RIGHT});
	env->buttons_lst[BUTTON_MOB_PLACING] = create_txt_button("Place",
		create_point(0.822 * WIN_SIZE_X, 0.555 * WIN_SIZE_Y),
		(SDL_Point){0xFFDDDDDD, 0xFF88FF88}, (SDL_Point){1,
		BUTTON_MOB_PLACING});
	env->buttons_lst[BUTTON_FLOOR_TEXT] = create_txt_button("Set_floor_text",
		create_point(0.730 * WIN_SIZE_X, 0.950 * WIN_SIZE_Y),
		(SDL_Point){0xFFFF88CC, 0xFFDDDDDD}, (SDL_Point){1,
		BUTTON_FLOOR_TEXT});
}
