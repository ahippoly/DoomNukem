/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:38:22 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 21:55:23 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		move_events(t_enval *env)
{
	if (env->event.key.keysym.sym == SDLK_q)
		env->sdl.key[Q] = env->event.type == SDL_KEYDOWN ? -1 : 0;
	else if (env->event.key.keysym.sym == SDLK_e)
		env->sdl.key[E] = env->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (env->event.key.keysym.sym == SDLK_w
		|| env->event.key.keysym.sym == SDLK_UP)
		env->sdl.key[UP] = env->event.type == SDL_KEYDOWN ? 1 : 0;
    else if (env->event.key.keysym.sym == SDLK_a
		|| env->event.key.keysym.sym == SDLK_LEFT)
		env->sdl.key[LEFT] = env->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (env->event.key.keysym.sym == SDLK_s
		|| env->event.key.keysym.sym == SDLK_DOWN)
		env->sdl.key[DOWN] = env->event.type == SDL_KEYDOWN ? -1 : 0;
	else if (env->event.key.keysym.sym == SDLK_d
		|| env->event.key.keysym.sym == SDLK_RIGHT)
		env->sdl.key[RIGHT] = env->event.type == SDL_KEYDOWN ? -1 : 0;
}

static void      deal_event(t_enval *env)
{
    if (env->sdl.key[MOUSE])
        mouse_events(env);
    if (env->sdl.key[UP] != 0 || env->sdl.key[DOWN] != 0 || env->sdl.key[LEFT] != 0
    || env->sdl.key[RIGHT] != 0)
        movement(env);
    if (env->sdl.key[Q] != 0 || env->sdl.key[E] != 0)
        rotation(env, &env->player);
}

void            event(t_enval *env)
{
    while (SDL_PollEvent(&env->event))
    {
        if ((env->event.key.keysym.sym == SDLK_ESCAPE
		&& env->event.type == SDL_KEYDOWN)
		|| env->event.type == SDL_QUIT)
			ft_exit(env, NULL, 1);
        else if (env->event.type == SDL_MOUSEMOTION)
			env->sdl.key[MOUSE] = 1; 
        move_events(env);
    }
    deal_event(env);
}
