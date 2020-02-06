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

#include "../includes/gameplay.h"

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
	reset_buff(pc->effects.dmg_resist);
	reset_buff(pc->effects.att_dmg);
	reset_buff(pc->effects.att_spd);
	pc->arsenal[0] = get_weapon_fist();
}

void			init_game(t_game *game)
{
	
	game->diff_mod = get_diff_mod();
}