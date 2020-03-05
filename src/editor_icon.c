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

void add_icon(t_env *env, t_icon new)
{
	env->icon_list[env->icon_count++] = new;
	if (env->icon_count >= env->icon_list_size)
	{
		env->icon_list = double_array_size(env->icon_list, sizeof(t_icon), env->icon_count);
		env->icon_list_size *= 2;
	}
}

void print_icon(t_env *env, t_icon icon)
{
	SDL_Rect tmp;
	//printf("icon pos : x = %f, y = %f\n", icon.pos.x, icon.pos.y);
	if (icon.pos.x > 0)
	{
		tmp = set_sdl_rect(icon.pos.x * TILE_SIZE - icon.size.w / 2 + env->map_move.x, icon.pos.y * TILE_SIZE - icon.size.h / 2 + env->map_move.y, icon.size.w, icon.size.h);
		//printf("mouse icon pos = %f, %f\n", icon.pos.x * TILE_SIZE, icon.pos.y * TILE_SIZE);
		SDL_RenderCopy(env->rend, env->img_list[icon.id_ref], NULL, &tmp);
	}
}

void print_mouse_icon(t_env *env)
{
	if (env->mouse_icon.id_ref != -1)
	{
		SDL_SetRenderTarget(env->rend, env->editor_grid);
		env->mouse_icon.pos.x = (double)(env->mouse.x - GRID_POS_X - env->map_move.x) / TILE_SIZE;
		env->mouse_icon.pos.y = (double)(env->mouse.y - GRID_POS_Y - env->map_move.y) / TILE_SIZE;
		print_icon(env, env->mouse_icon);
		SDL_SetRenderTarget(env->rend, NULL);
	}
}

void print_player_spawn(t_env *env)
{
	if (env->player_spawn.x > 0.001)
	{
		SDL_SetRenderTarget(env->rend, env->editor_grid);
		print_icon(env, create_icon(env->player_spawn, create_t_size(ICON_PLAYER_SIZE, ICON_PLAYER_SIZE), 0));
		SDL_SetRenderTarget(env->rend, NULL);
	}
}

void print_icon_list(t_env *env)
{
	int i;

	i = 0;
	SDL_SetRenderTarget(env->rend, env->editor_grid);
	while (i < env->icon_count)
	{
		print_icon(env, env->icon_list[i++]);
	}
	SDL_SetRenderTarget(env->rend, NULL);

}
