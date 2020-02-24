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
	if (env->event.type == SDL_MOUSEBUTTONDOWN && env->event.button.button == SDL_BUTTON_LEFT)
	{	
		if (env->game.pc.arsenal[env->game.pc.equip.current].attack.type == WEAPON_TYPE_CHARGED
			&& env->game.pc.equip.weapon_state != WEAPON_STATE_FIRING)
			env->game.pc.equip.weapon_state = WEAPON_STATE_CHARGING;
		else 
			env->game.pc.equip.weapon_state = WEAPON_STATE_FIRING;
		
		//ft_putendl("Bang !");
	}
    else if (env->event.type == SDL_MOUSEBUTTONUP && env->event.button.button == SDL_BUTTON_LEFT)
	{
		//env->game.pc.equip.weapon_state = WEAPON_STATE_READY;
		env->game.pc.trigger_held = env->game.pc.equip.weapon_state != WEAPON_STATE_READY ? 1 : 0;
		ft_putendl("Unbang !");
	}
}

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
    handle_weapon_fire2(env);
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
	//env->game.pc.equip.delay = SDL_GetTicks(); //Remove comment for 2nd handle_weapon_fire fc
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
		}
		// if ((env->user.paused) < 0)
		// {	
        if (env->event.type == SDL_MOUSEMOTION)
			env->sdl.key[MOUSE] = 1;
		mouseclick_event(env);
		if (env->event.type == SDL_KEYDOWN) 
		{
			if (env->event.key.keysym.sym == SDLK_l)
            	switch_fog(env);
			change_weapon(env);
		}
        move_events(env);
		// }
		
	}
	// ft_putstr("delay is ");
	// ft_putnbr((int)env->game.pc.arsenal[env->game.pc.equip.current].attack.delay.current);
	// ft_putchar('\n');
	if(env->user.paused < 0)
		deal_event(env);
}
