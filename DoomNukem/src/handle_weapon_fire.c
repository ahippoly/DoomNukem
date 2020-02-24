/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_weapon_fire.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:48:11 by apons             #+#    #+#             */
/*   Updated: 2020/02/19 09:48:11 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** If the weapon is charging and we lift the button off of the mouse,
** cancel the charge and set state to ready.
*/

static void	reset_charged_state(t_enval *env)
{
		env->game.pc.arsenal[env->game.pc.equip.current].attack.delay.current = 0;
		env->game.pc.equip.weapon_state = WEAPON_STATE_READY;
		env->game.pc.trigger_held = 0;
}

static void	reset_charged_state2(t_enval *env,int id)
{
		env->game.pc.arsenal[id].attack.delay.current = 0;
		env->game.pc.equip.weapon_state = WEAPON_STATE_READY;
		env->game.pc.trigger_held = 0;
}

/*
** Universal function to handle the way shots are fired.
*/

void		handle_weapon_fire(t_enval *env)
{
	int id;
	int state;

	id = env->game.pc.equip.current;
	state = env->game.pc.equip.weapon_state;
	if (env->game.pc.trigger_held && state == WEAPON_STATE_CHARGING)
		reset_charged_state(env);
	if (env->game.pc.arsenal[id].attack.delay.current == (Uint32)0 && (state == WEAPON_STATE_FIRING
		|| state == WEAPON_STATE_CHARGING))
	{
		env->game.pc.arsenal[id].attack.delay.current = SDL_GetTicks();
		state == WEAPON_STATE_FIRING ? ft_putendl("Bang for real") : 0;
	}
	if ((state == WEAPON_STATE_FIRING || state == WEAPON_STATE_CHARGING)
		&& (int)(SDL_GetTicks() - env->game.pc.arsenal[id].attack.delay.current)
		>= env->game.pc.arsenal[id].attack.delay.max * state)
	{
		env->game.pc.arsenal[id].attack.delay.current = 0;
		if (env->game.pc.arsenal[id].attack.type != WEAPON_TYPE_AUTOMATIC
			|| env->game.pc.trigger_held)
		{
			env->game.pc.equip.weapon_state--;
			env->game.pc.trigger_held = 0;
		}
	}
}

void		handle_weapon_fire2(t_enval *env)
{
	int id;
	int state;

	id = env->game.pc.equip.current;
	state = env->game.pc.equip.weapon_state;
	if (env->game.pc.trigger_held && state == WEAPON_STATE_CHARGING)
		reset_charged_state2(env, id);
	if (env->game.pc.arsenal[id].attack.delay.current <= 0)
	{
		if (state == WEAPON_STATE_CHARGING || state == WEAPON_STATE_FIRING)
		{
			env->game.pc.arsenal[id].attack.delay.current
			+= env->game.pc.arsenal[id].attack.delay.max;
			ft_putnbr((int)env->game.pc.arsenal[id].attack.delay.current);
			if (state == WEAPON_STATE_FIRING)
				ft_putendl(" Bang, because I'm a weapon !");
		}
	}
	else if (env->game.pc.arsenal[id].attack.delay.current > 0 && state != WEAPON_STATE_READY)
	{	
		env->game.pc.arsenal[id].attack.delay.current -= SDL_GetTicks() - env->game.pc.equip.delay;
		ft_putnbr(env->game.pc.arsenal[id].attack.delay.current);
		ft_putchar('\n');
		if ((env->game.pc.arsenal[id].attack.type != WEAPON_TYPE_AUTOMATIC || env->game.pc.trigger_held)
			&& env->game.pc.arsenal[id].attack.delay.current <= 0)
		{
			env->game.pc.equip.weapon_state--;
			env->game.pc.trigger_held = 0;
		}
	}
}