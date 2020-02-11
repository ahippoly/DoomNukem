/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:32:15 by apons             #+#    #+#             */
/*   Updated: 2020/02/07 21:14:39 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
//#include "libft.h"

SDL_Surface		*new_surface(int w, int h)
{
	Uint32	color[4];

	color[0] = 0x000000ff;
	color[1] = 0x0000ff00;
	color[2] = 0x00ff0000;
	color[3] = 0xff000000;
	return (SDL_CreateRGBSurface(0, w, h, 32,
				color[0], color[1], color[2], color[3]));
}

static int		init_sdl(t_enval *env)
{
	env->sdl.sdl_token = 1;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (0);
	if (!(env->sdl.win = SDL_CreateWindow("DoomNukem",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIN_W, WIN_H, 0)))
		return (0);
	SDL_GetWindowPosition(env->sdl.win, &env->sdl.winx, &env->sdl.winy);
	if (!(env->sdl.rend = SDL_CreateRenderer(env->sdl.win, -1,
			SDL_RENDERER_ACCELERATED)))
		return (0);
	if (!(env->sdl.screen = new_surface(WIN_W, WIN_H)))
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_enval *env;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "h") == 0 || ft_strcmp(argv[1], "help") == 0)
			ft_help();
		if (!(env = (t_enval *)malloc(sizeof(t_enval))))
			ft_exit(env, "Env malloc failed.", 0);
		init_values(argv[1], env);
		map_drawer(env);
		test(env);
		if (!init_sdl(env))
			ft_exit(env, "SDL init failed.", 0);
		init_texture(env);
		while (1)
		{
			display(env);
			event(env);
		}
	}
	else
		ft_putendl("Usage : ./wolf3d [map]. Try [(h)elp] instead for help.");
	return (0);
}
