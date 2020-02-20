/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:11:32 by apons             #+#    #+#             */
/*   Updated: 2020/02/05 13:11:32 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Function allowing to get any type of enemy
*/

t_npc	get_enemy(t_stat_sheet *sheet, int id, t_pos start_pos)
{
	t_npc enemy;

	enemy.pos = start_pos;
	init_stat(&enemy.health, sheet->health[id], sheet->health[id]);
	enemy.attack.type = WEAPON_TYPE_ENEMY;
	enemy.attack.damage = sheet->damage[id];
	enemy.attack.range = sheet->ranges[id];
	init_stat(&enemy.attack.delay, sheet->delays[id], 0);
	enemy.attack.radius.depth = ZERO;
	enemy.attack.radius.width = ZERO;
	enemy.movement_speed = sheet->mv_spd[id];
	clean_status_effect(&enemy.effects.dmg_resist);
	clean_status_effect(&enemy.effects.att_dmg);
	clean_status_effect(&enemy.effects.att_spd);
	enemy.player_detection = PLAYER_UNDETECTED;
	enemy.player_allegiance = PLAYER_HOSTILE;
	return(enemy);
}