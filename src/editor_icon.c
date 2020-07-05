/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_icon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:08:25 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/24 20:07:17 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

// OKK
t_icon			create_icon(t_point pos, t_size size, int id_ref)
{
	t_icon		new;

	new.pos = pos;
	new.size = size,
	new.id_ref = id_ref;
	return (new);
}

void			print_icon(t_env *env, t_icon icon)
{
	SDL_Rect tmp;
	//printf("icon pos : x = %f, y = %f\n", icon.pos.x, icon.pos.y);
	if (icon.pos.x > 0)
	{
		tmp = set_sdl_rect(icon.pos.x * TILE_SIZE - icon.size.w / 2 + env->map_move.x, icon.pos.y * TILE_SIZE - icon.size.h / 2 + env->map_move.y, icon.size.w, icon.size.h);
		//printf("mouse icon pos = %f, %f\n", icon.pos.x * TILE_SIZE, icon.pos.y * TILE_SIZE);
		if ((SDL_RenderCopy(env->rend, env->img_list[icon.id_ref], NULL, &tmp)) < 0)
			exit_editor(env, "error : failed to render copy");
	}
}

void			print_mouse_icon(t_env *env)
{
	if (env->mouse_icon.id_ref != -1)
	{
		if ((SDL_SetRenderTarget(env->rend, env->editor_grid)) < 0)
			exit_editor(env, "error : failed to render target");
		env->mouse_icon.pos.x = (float)(env->mouse.x - GRID_POS_X - env->map_move.x) / TILE_SIZE;
		env->mouse_icon.pos.y = (float)(env->mouse.y - GRID_POS_Y - env->map_move.y) / TILE_SIZE;
		print_icon(env, env->mouse_icon);
		if ((SDL_SetRenderTarget(env->rend, NULL)) < 0)
			exit_editor(env, "error : failed to render target");
	}
}

void			print_player_spawn(t_env *env)
{
	if (env->player_spawn.x > 0.001)
	{
		if ((SDL_SetRenderTarget(env->rend, env->editor_grid)) < 0)
			exit_editor(env, "error : failed to render target");
		print_icon(env, create_icon(env->player_spawn, create_t_size(ICON_PLAYER_SIZE, ICON_PLAYER_SIZE), 0));
		if ((SDL_SetRenderTarget(env->rend, NULL)) < 0)
			exit_editor(env, "error : failed to render target");
	}
}

void			print_icon_list(t_env *env)
{
	int i;

	i = 0;
	if ((SDL_SetRenderTarget(env->rend, env->editor_grid)) < 0)
		exit_editor(env, "error : failed to render target");
	while (i < env->icon_count)
	{
		print_icon(env, env->icon_list[i++]);
	}
	if ((SDL_SetRenderTarget(env->rend, NULL)) < 0)
		exit_editor(env, "error : failed to render target");
}
