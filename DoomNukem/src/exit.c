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

static void        free_surface(t_sprite *tab, int nb_surface)
{
    int i;

    i = nb_surface;
    while (i >= 0)
    {
        if (tab[i].img)
            SDL_FreeSurface(tab[i].img);
        i--;
    }
}

void        ft_exit(t_enval *env, char *s, int flag)
{
    if (env)
	{
		if (env->sdl.sdl_token)
		{
			free_surface(env->wtex, 5);
            if (env->sdl.rend)
			    SDL_DestroyRenderer(env->sdl.rend);
			if (env->sdl.win)
				SDL_DestroyWindow(env->sdl.win);
			//if (data->sound.token == 1)
			//	free_sound(data);
			//Mix_CloseAudio();
			SDL_Quit();
		}
	}
	if (s)
		ft_putendl_fd(s, 2);
	exit(flag ? EXIT_SUCCESS : EXIT_FAILURE);
}