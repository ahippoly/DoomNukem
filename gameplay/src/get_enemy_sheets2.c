/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_sheets2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:24:21 by apons             #+#    #+#             */
/*   Updated: 2020/02/06 15:24:21 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

/*
** Sight range of each and every enemy in the game.
*/

void	get_enemy_sights(double *sights)
{
	sights[ENEMY_GRUNT_MELEE] = 10;
	sights[ENEMY_GRUNT_RANGED_BASIC] = 10;
	sights[ENEMY_GRUNT_RANGED_ADV] = 10;
	sights[ENEMY_GRUNT_RANGED_SUP] = 10;
	sights[ENEMY_SOLDIER_MELEE_ATT] = 10;
	sights[ENEMY_SOLDIER_MELEE_DEF] = 10;
	sights[ENEMY_SOLDIER_MELEE_KAMI] = 10;
	sights[ENEMY_SOLDIER_RANGED_ATT] = 10;
	sights[ENEMY_SOLDIER_RANGED_SUP] = 10;
	sights[ENEMY_ELITE_MELEE_ATT] = 10;
	sights[ENEMY_ELITE_MELEE_SWARMER] = 10;
	sights[ENEMY_ELITE_MELEE_SWARM] = 10;
	sights[ENEMY_ELITE_RANGED_SHORT] = 10;
	sights[ENEMY_ELITE_RANGED_LONG] = 20;
	sights[ENEMY_ELITE_RANGED_SUP] = 10;
	sights[ENEMY_BOSS_FIRST] = 20;
	sights[ENEMY_BOSS_SECOND] = 20;
	sights[ENEMY_BOSS_FINAL] = 20;	
}