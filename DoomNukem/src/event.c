/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:38:22 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 22:25:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		mouseclick_event(t_enval *env)
{
	if (env->event.type == SDL_MOUSEBUTTONDOWN
	&& env->event.button.button == SDL_BUTTON_LEFT)
	{	
		if (env->game.pc.arsenal[env->game.pc.equip.current].clip.size.current
			&& env->game.pc.equip.weapon_state == WEAPON_STATE_READY)
		{
			if (env->game.pc.arsenal[env->game.pc.equip.current].attack.type == WEAPON_TYPE_CHARGED
				&& env->game.pc.equip.weapon_state != WEAPON_STATE_FIRING)
				env->game.pc.equip.weapon_state = WEAPON_STATE_CHARGING;
			else 
				env->game.pc.equip.weapon_state = WEAPON_STATE_FIRING;
		}
	}
    else if (env->event.type == SDL_MOUSEBUTTONUP && env->event.button.button == SDL_BUTTON_LEFT)
		env->sdl.key[LMOUSE] = env->game.pc.equip.weapon_state != WEAPON_STATE_READY ? 1 : 0;
}

// void			mouseclick_event2(t_enval *env)
// {
// 	ft_putendl("Always going here");
// 	if (env->event.button.button == SDL_BUTTON_LEFT)
// 	{
// 		env->sdl.key[LMOUSE] = env->event.type == SDL_MOUSEBUTTONDOWN ? 1 : 0;
// 		ft_putnbr(env->sdl.key[LMOUSE]);
// 		ft_putendl(" is the state of LMOUSE");
// 	}
// }

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
	int id;

	id = env->game.pc.equip.current;
	if (env->sdl.key[MOUSE])
        mouse_events(env);
    if (env->sdl.key[UP] || env->sdl.key[DOWN] || env->sdl.key[LEFT]
    || env->sdl.key[RIGHT])
        movement(env);
    if (env->sdl.key[Q] || env->sdl.key[E])
        rotation(env, &env->player);
	if (env->sdl.key[R] && env->game.pc.arsenal[id].clip.size.current
		!= env->game.pc.arsenal[id].clip.size.max
		&& env->game.pc.arsenal[id].ammo.current
		&& env->game.pc.equip.weapon_state == WEAPON_STATE_READY)
		env->game.pc.equip.weapon_state = WEAPON_STATE_RELOADING;
	// ft_putendl("Reloading ! or something like that.");
	handle_weapon_reload(env);
	handle_weapon_fire(env);
}

void            event(t_enval *env)
{
	while (SDL_PollEvent(&env->event))
    {
        if ((env->event.key.keysym.sym == SDLK_ESCAPE
		&& env->event.type == SDL_KEYDOWN)
		|| env->event.type == SDL_QUIT)
			ft_exit(env, NULL, 1);
		if (env->event.type == SDL_KEYDOWN)
		{
			if (env->event.key.keysym.sym == SDLK_p)
				env->user.paused *= -1;
			if (env->event.key.keysym.sym == SDLK_l)
        	    	switch_fog(env);
		}
		if (env->user.paused < 0)
		{
			mouseclick_event(env);
        	if (env->event.type == SDL_MOUSEMOTION)
			{
				env->sdl.key[MOUSE] = 1;
				
			}
			if (env->event.key.keysym.sym == SDLK_r)
				env->sdl.key[R] = env->event.type == SDL_KEYDOWN ? -1 : 0;
			if (env->event.type == SDL_KEYDOWN) 
			{
				change_weapon(env);
			}
		}
		move_events(env);	
	}
	if (env->user.paused < 0)
		deal_event(env);
}
