/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 22:50:51 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 22:51:50 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Toggles between different fog types.
** Thin -> None -> Thick -> White -> Thin
*/

void		switch_fog(t_enval *env)
{
	env->user.fog++;
	if (env->user.fog == 4)
		env->user.fog = 0;
}

/*
** Allows for weapon swapping. No effect if the weapon is already equipped.
*/

void		change_weapon(t_enval *env)
{
	int id;

	if (env->game.pc.equip.weapon_state == WEAPON_STATE_READY)
	{
		id = env->game.pc.equip.current;
		if (env->event.key.keysym.sym == SDLK_1
			&& !ft_strcmp(env->game.pc.arsenal[0].name, "Fists"))
			env->game.pc.equip.current = 0;
		if (env->event.key.keysym.sym == SDLK_2
			&& !ft_strcmp(env->game.pc.arsenal[1].name, "Pistol"))
			env->game.pc.equip.current = 1;
		if (env->event.key.keysym.sym == SDLK_3
			&& !ft_strcmp(env->game.pc.arsenal[2].name, "Shotgun"))
			env->game.pc.equip.current = 2;
		if (env->event.key.keysym.sym == SDLK_4
			&& !ft_strcmp(env->game.pc.arsenal[3].name, "SMG"))
			env->game.pc.equip.current = 3;
		if (env->event.key.keysym.sym == SDLK_5
			&& !ft_strcmp(env->game.pc.arsenal[4].name, "BFG"))
			env->game.pc.equip.current = 4;
	}
}

/*
** Handles weapon bobbing
*/

void		handle_bobbing(t_enval *env)
{
	static double	i = 0.0;
	static int		sign = 1;

	i = i + 0.2 * sign;
	if (i == 1.0 * sign)
		sign *= -1;
	env->user.bobbing.x = sin(i * M_PI_2) * 10;
	env->user.bobbing.y = cos(i * M_PI_2) * 10;
}

/*
** Handles all events that should be handled when the game is not paused
*/

void		event_unpaused(t_enval *env)
{
	mouseclick_event(env);
	if (env->event.type == SDL_MOUSEMOTION)
		env->sdl.key[MOUSE] = 1;
	if (env->event.key.keysym.sym == SDLK_r)
		env->sdl.key[R] = env->event.type == SDL_KEYDOWN ? -1 : 0;
	if (env->event.type == SDL_KEYDOWN)
	{
		change_weapon(env);
	}
}
