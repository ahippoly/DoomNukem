/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:41:23 by alebui            #+#    #+#             */
/*   Updated: 2020/08/01 07:07:55 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int		init_sdl_ressources(t_env *env)
{
	env->win = NULL;
	if (0 != SDL_Init(SDL_INIT_VIDEO))
		exit_editor(env, "error : failed to init SDL");
	if (!(env->win = SDL_CreateWindow("Editor", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_SIZE_X, WIN_SIZE_Y, SDL_WINDOW_SHOWN)))
		exit_editor(env, "error : failed to create window");
	if (!(env->rend = SDL_CreateRenderer(env->win, -1,
		SDL_RENDERER_ACCELERATED)))
		exit_editor(env, "error : failed to create Renderer");
	if (!(env->screen = SDL_CreateTexture(env->rend,
		SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING,
		WIN_SIZE_X, WIN_SIZE_Y)))
		exit_editor(env, "error : failed to create texture");
	if (!(env->editor_grid = SDL_CreateTexture(env->rend,
		SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET,
		GRID_SIZE_X, GRID_SIZE_Y)))
		exit_editor(env, "error : failed to create texture");
	return (0);
}

void	init_sdl_ressources_rend(t_data *d)
{
	d->win = NULL;
	if (0 != SDL_Init(SDL_INIT_VIDEO))
		exit_game(d, "error : failed to init SDL");
	if (!(d->win = SDL_CreateWindow("DooM Nukem", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_SIZE_X, WIN_SIZE_Y, SDL_WINDOW_SHOWN)))
		exit_game(d, "error : failed to create window");
	if (!(d->rend = SDL_CreateRenderer(d->win, -1, SDL_RENDERER_ACCELERATED)))
		exit_game(d, "error : failed to create renderer");
	if (!(d->screen = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ARGB32,
	SDL_TEXTUREACCESS_STREAMING, WIN_SIZE_X, WIN_SIZE_Y)))
		exit_game(d, "error : failed to create texture");
	if (!(d->mini_map = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_RGBA32,
	SDL_TEXTUREACCESS_STREAMING, MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y)))
		exit_game(d, "error : failed to create texture");
	SDL_SetRelativeMouseMode(SDL_FALSE);
}
