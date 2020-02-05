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

#include "../includes/gameplay.h"

/*
** The usual melee type of enemy. Weak by itself.
*/

t_npc	get_enemy_grunt(t_pos start_pos)
{
	t_npc grunt;

	grunt.pos = start_pos;
	init_stat(&grunt.health, 30, 30);
	grunt.attack.type = WEAPON_TYPE_MELEE;
	grunt.attack.damage = 7;
	grunt.attack.range = 0.3;
	grunt.attack.speed = 1500;
	grunt.attack.radius.depth = ZERO;
	grunt.attack.radius.width = ZERO;
	grunt.movement_speed = 0.75;
	clean_status_effect(&grunt.effects.dmg_resist);
	clean_status_effect(&grunt.effects.att_dmg);
	clean_status_effect(&grunt.effects.att_spd);
	grunt.player_detection = PLAYER_UNDETECTED;
	grunt.player_allegiance = PLAYER_HOSTILE;
}