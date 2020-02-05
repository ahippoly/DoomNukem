/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:32:15 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 10:22:35 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

void init_sdl_ressources(t_enval *env)
{
	env->win = NULL;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
        ft_error("Failed to Init SDL", env, 0);
    if (!(env->win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WIN_W, WIN_H, SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP)))
        ft_error("Failed to create Window", env, 0);
    if (!(env->rend = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_TARGETTEXTURE)))
        ft_error("Failed to create Renderer", env, 0);
    env->screen = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_BGRA32, SDL_TEXTUREACCESS_STREAMING, WIN_W, WIN_H);
    // env->editor_grid = SDL_CreateTexture(env->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, GRID_SIZE_X, GRID_SIZE_Y);
}

int		main(int argc, char **argv)
{
	t_enval *env;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "h") == 0 || ft_strcmp(argv[1], "help") == 0)
			ft_help();
		if (!(env = (t_enval *)malloc(sizeof(t_enval))))
		{
			ft_putendl("malloc failed.");
			return (0);
		}
		init_sdl_ressources(env);
		init_values(argv[1], env);
		init_mlx(env);
		ray_draw(env);
		mlx_handle_hooks(env);
	}
	else
		ft_putendl("Usage : ./wolf3d [map]. Try [(h)elp] instead for help.");
	return (0);
}
