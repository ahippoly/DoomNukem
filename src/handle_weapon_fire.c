/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_weapon_fire.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:48:11 by apons             #+#    #+#             */
/*   Updated: 2020/06/08 10:56:41 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** If the weapon is charging and we lift the button off of the mouse,
** cancel the charge and set state to ready.
*/

static void	reset_charged_state(t_enval *env, int id)
{
	env->game.pc.arsenal[id].attack.delay.current = 0;
	env->game.pc.equip.weapon_state = WEAPON_STATE_READY;
	env->sdl.key[LMOUSE] = 0;
}

/*
** Handles the second part of "handle_weapon_fire",
** when the delay is below or equal to 0.
*/

static void	weapon_fire(t_enval *env, int id, int state)
{
	while (env->game.pc.arsenal[id].attack.delay.current <= 0
		&& env->game.pc.arsenal[id].clip.size.current)
	{
		if (state == WEAPON_STATE_FIRING)
		{
			ft_putendl("This here is the part where I should shoot.");
			env->game.pc.arsenal[id].clip.size.current--;
			if (id == 0)
				env->game.pc.fist_side = env->game.pc.fist_side ? 0 : 2;
		}
		env->game.pc.arsenal[id].attack.delay.current +=
		env->game.pc.arsenal[id].attack.delay.max * state;
	}
}

/*
** Universal function to handle the way player shots are fired.
** First check if charging weapons are still charging.
** Then, reduces the delay of the current weapon equipped, although
*/

void		handle_weapon_fire(t_enval *env)
{
	int id;
	int state;

	id = env->game.pc.equip.current;
	state = env->game.pc.equip.weapon_state;
	if (env->sdl.key[LMOUSE] && state == WEAPON_STATE_CHARGING)
		reset_charged_state(env, id);
	if (state == WEAPON_STATE_FIRING || state == WEAPON_STATE_CHARGING)
	{
		if (env->game.pc.arsenal[id].attack.delay.current > 0)
		{
			env->game.pc.arsenal[id].attack.delay.current -=
			SDL_GetTicks() - env->game.pc.equip.delay;
			if ((env->game.pc.arsenal[id].attack.type != WEAPON_TYPE_AUTOMATIC
			|| env->sdl.key[LMOUSE]
			|| !env->game.pc.arsenal[id].clip.size.current)
				&& env->game.pc.arsenal[id].attack.delay.current <= 0)
			{
				env->game.pc.equip.weapon_state--;
				env->sdl.key[LMOUSE] = 0;
			}
		}
		else
			weapon_fire(env, id, state);
	}
}

static void	ammo_handle(t_enval *env, int id)
{
	int old_clip_ammo;

	old_clip_ammo = env->game.pc.arsenal[id].clip.size.current;
	env->game.pc.arsenal[id].clip.size.current +=
	ft_min(env->game.pc.arsenal[id].clip.size.max - old_clip_ammo,
	env->game.pc.arsenal[id].ammo.current);
	env->game.pc.arsenal[id].ammo.current -=
	env->game.pc.arsenal[id].clip.size.current - old_clip_ammo;
	env->game.pc.equip.reload_cd = 0;
	env->game.pc.equip.weapon_state = WEAPON_STATE_READY;
}

void		handle_weapon_reload(t_enval *env)
{
	int id;
	int state;

	state = env->game.pc.equip.weapon_state;
	if (state == WEAPON_STATE_RELOADING)
	{
		id = env->game.pc.equip.current;
		if (env->game.pc.equip.reload_cd)
		{
			env->game.pc.equip.reload_cd -=
			SDL_GetTicks() - env->game.pc.equip.delay;
			if (env->game.pc.equip.reload_cd <= 0)
				ammo_handle(env, id);
		}
		else
			env->game.pc.equip.reload_cd = env->game.pc.arsenal[id].clip.reload;
	}
}
