/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:51:59 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 20:23:16 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Put these lines before SDL_Quit() :
** if (data->sound.token == 1)
** 		free_sound(data);
** Mix_CloseAudio();
*/

void				ft_exit(t_enval *env, char *s, int flag, int i)
{
	if (env)
	{
		if (env->sdl.sdl_token)
		{
			free_doom(env, i);
			if (env->sdl.rend)
				SDL_DestroyRenderer(env->sdl.rend);
			if (env->sdl.win)
				SDL_DestroyWindow(env->sdl.win);
			SDL_Quit();
		}
	}
	if (s)
		ft_putendl_fd(s, 2);
	exit(flag ? EXIT_SUCCESS : EXIT_FAILURE);
}
