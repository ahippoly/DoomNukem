/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_icon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:08:25 by ahippoly          #+#    #+#             */
/*   Updated: 2020/03/03 23:09:11 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_header.h"
#include "editor.h"

t_icon create_icon(t_point pos, t_size size, int id_ref)
{
	t_icon new;

	new.pos = pos;
	new.size = size,
	new.id_ref = id_ref;
	return (new);
}

void add_icon(t_env *env, t_point pos, t_size size, int id_ref)
{
	env->icon_list[env->icon_count++] = create_icon(pos, size, id_ref);
	if (env->icon_count >= env->icon_list_size)
	{
		env->icon_list = double_array_size(env->icon_list, sizeof(t_icon), env->icon_count);
		env->icon_list_size *= 2;
	}
}

void print_icon(t_env *env, t_icon icon)
{
	SDL_Rect tmp;
	tmp = set_sdl_rect(icon.pos.x * TILE_SIZE, icon.pos.y * TILE_SIZE, icon.size.w, icon.size.h);
	//printf("mouse icon pos = %f, %f\n", icon.pos.x * TILE_SIZE, icon.pos.y * TILE_SIZE);
	SDL_RenderCopy(env->rend, env->img_list[icon.id_ref], NULL, &tmp);
}

void print_mouse_icon(t_env *env)
{
	if (env->mouse_icon.id_ref != -1)
	{
		SDL_SetRenderTarget(env->rend, env->editor_grid);
		env->mouse_icon.pos.x = (double)(env->mouse.x - env->mouse_icon.size.w / 2 - GRID_POS_X) / TILE_SIZE;
		env->mouse_icon.pos.y = (double)(env->mouse.y - env->mouse_icon.size.h / 2 - GRID_POS_Y) / TILE_SIZE;
		print_icon(env, env->mouse_icon);
		SDL_SetRenderTarget(env->rend, NULL);
	}
}

void print_player_spawn(t_env *env)
{
	if (env->player_spawn.x > 0.001)
	{
		SDL_SetRenderTarget(env->rend, env->editor_grid);
		print_icon(env, create_icon(env->player_spawn, create_t_size(30, 30), 0));
		SDL_SetRenderTarget(env->rend, NULL);
	}
}
