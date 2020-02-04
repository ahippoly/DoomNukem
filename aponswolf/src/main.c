/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:32:15 by apons             #+#    #+#             */
/*   Updated: 2020/02/04 20:25:55 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
//#include "libft.h"

static int		init_sdl(t_enval *env)
{
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
	return (1);
}

void			put_texture(t_enval *env)
{
	SDL_LockSurface(env->sdl.screen);
	env->sdl.text = SDL_CreateTextureFromSurface(env->sdl.rend, env->sdl.screen);
	SDL_RenderCopy(env->sdl.rend, env->sdl.text, NULL, NULL);
	SDL_UnlockSurface(env->sdl.screen);

}

void			display(t_enval *env)
{
	ray_draw(env);
	put_texture(env);
	SDL_RenderPresent(env->sdl.rend);
	SDL_DestroyTexture(env->sdl.text);
	SDL_SetRenderDrawColor(env->sdl.rend, 0, 0, 0, 0);
	SDL_RenderClear(env->sdl.rend);
}

int				main(int argc, char **argv)
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
		init_values(argv[1], env);
		if (!init_sdl(env))
		{
			ft_putendl("SDL init failed.");
			return (0);
		}	
		init_texture(env);
		//init_mlx(env);
		while (1)
		{
			display(env);	
		}
		//mlx_handle_hooks(env);
	}
	else
		ft_putendl("Usage : ./wolf3d [map]. Try [(h)elp] instead for help.");
	return (0);
}
