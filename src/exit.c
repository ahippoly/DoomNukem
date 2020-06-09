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

void				ft_exit(t_enval *env, char *s, int flag, int free_buff)
{
	if (env)
	{
		if (env->sdl.sdl_token)
		{
			free_textures(env->wtex, env->wptex);
			//while (1){}
			SDL_FreeSurface(env->sdl.screen);
			//while (1){}
			if(env->sdl.text)
				SDL_DestroyTexture(env->sdl.text);
			//while (1){}
			if (env->sdl.rend)
				SDL_DestroyRenderer(env->sdl.rend);
			//while (1){}
			if (env->sdl.win)
				SDL_DestroyWindow(env->sdl.win);
			ft_putendl("Faulty Part !");
			//while(1){}
			SDL_Quit();
		}
		free_doom(env, free_buff);
	}
	//while (1){}
	if (s)
		ft_putendl_fd(s, 2);
	exit(flag ? EXIT_FAILURE : EXIT_SUCCESS);
}
