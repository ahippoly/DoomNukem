/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:09:16 by apons             #+#    #+#             */
/*   Updated: 2020/02/11 09:09:16 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

/*
** Reload function. cannot be a while, unless we want to freeze the whole program...
*/

void	reload_weapon(t_weapon *weapon, t_equipped *eq, Uint32 delay_start)
{
	Uint32	delay_end;
	int		old_clip_ammo;

	delay_end = SDL_GetTicks();

	if (delay_end - delay_start >= weapon->clip.reload)
	{
		old_clip_ammo = weapon->clip.size.current;
		weapon->clip.size.current += ft_min(weapon->clip.size.max
		- old_clip_ammo, weapon->ammo.current);
		weapon->ammo.current -= weapon->clip.size.current - old_clip_ammo;
		eq->weapon_state = WEAPON_STATE_READY;
	}
	else
		play_wp_anim(weapon, eq, delay_start, delay_end);

}

/*
** Function handling a weapon to shoot
** First, check if the weapon has ammo and shoot when condition is met
** Second, if the clip has no ammo, reload it.
** Last, if both the clip and ammo reserves are empty, display it.
*/

void	handle_weapon(t_weapon *weapon, Uint32 delay, t_game *game)
{
	// if (RIGHT_CLICK)
	// {


		if (weapon->clip.size.current)
			handle_type();
		else if (weapon->ammo.current)
			reload_weapon(weapon, &game->pc.equip, delay);
		else
			ft_putendl("Out of ammo");
	// }	
}
