/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:26:02 by apons             #+#    #+#             */
/*   Updated: 2020/01/31 10:26:02 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Note : Increasing movement_speed variable actually
** decreases movement speed, unless it is equal to 0.
** In that case, the entity cannot move.
*/

void			init_pc(t_player_character *pc)
{
	init_stat(&pc->health, 100, 100);
	init_stat(&pc->armor, 100, 0);
	pc->movement_speed = 9;
	clean_status_effect(&pc->effects.dmg_resist);
	clean_status_effect(&pc->effects.att_dmg);
	clean_status_effect(&pc->effects.att_spd);
	pc->arsenal[0] = get_weapon_fist();
	pc->arsenal[1] = get_weapon_pistol();
	pc->arsenal[2] = get_weapon_shotgun();
	pc->arsenal[3] = get_weapon_submachinegun();
	pc->arsenal[4] = get_weapon_bfg();
	pc->equip.current = 0;
	pc->equip.weapon_state = WEAPON_STATE_READY;
}