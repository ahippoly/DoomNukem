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

void	handle_weapon_semiauto(t_enval *env)
{
	int id;
	int state;
	
	id = env->game.pc.equip.current;
	state = env->game.pc.equip.weapon_state;
	if (env->game.pc.equip.delay == (Uint32)0 && (state == WEAPON_STATE_FIRING
		|| state == WEAPON_STATE_CHARGING))
		{
			env->game.pc.equip.delay = SDL_GetTicks();
			if (state == WEAPON_STATE_FIRING)
				ft_putendl("Bang but for real");
		}
	if ((state == WEAPON_STATE_FIRING || state == WEAPON_STATE_CHARGING)
		&& (int)(SDL_GetTicks() - env->game.pc.equip.delay)
		>= env->game.pc.arsenal[id].attack.delay.max * state)
	{
		env->game.pc.equip.delay = 0;
		if (env->game.pc.arsenal[id].attack.type != WEAPON_TYPE_AUTOMATIC)
			env->game.pc.equip.weapon_state--;
	}
}

// void	handle_weapon_automatic(t_enval *env)
// {}

// void	handle_weapon_charged(t_enval *env)
// {}