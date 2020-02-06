/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_sheets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:04:19 by apons             #+#    #+#             */
/*   Updated: 2020/02/06 13:04:19 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

void	get_enemy_health(int *health)
{
	health[ENEMY_GRUNT_MELEE] = 30;
	health[ENEMY_GRUNT_RANGED_BASIC] = 20;
	health[ENEMY_GRUNT_RANGED_ADV] = 25;
	health[ENEMY_GRUNT_RANGED_SUP] = 25;
	health[ENEMY_SOLDIER_MELEE_ATT] = 45;
	health[ENEMY_SOLDIER_MELEE_DEF] = 80;
	health[ENEMY_SOLDIER_MELEE_KAMI] = 20;
	health[ENEMY_SOLDIER_RANGED_ATT] = 40;
	health[ENEMY_SOLDIER_RANGED_SUP] = 30;
	health[ENEMY_ELITE_MELEE_ATT] = 60;
	health[ENEMY_ELITE_MELEE_SWARMER] = 120;
	health[ENEMY_ELITE_MELEE_SWARM] = 15;
	health[ENEMY_ELITE_RANGED_SHORT] = 50;
	health[ENEMY_ELITE_RANGED_LONG] = 30;
	health[ENEMY_ELITE_RANGED_SUP] = 100;
	health[ENEMY_BOSS_FIRST] = 500;
	health[ENEMY_BOSS_SECOND] = 1000;
	health[ENEMY_BOSS_FINAL] = 1500;
}

void	get_enemy_damage(int *damage)
{
	damage[ENEMY_GRUNT_MELEE] = 10;
	damage[ENEMY_GRUNT_RANGED_BASIC] = 7;
	damage[ENEMY_GRUNT_RANGED_ADV] = 2;
	damage[ENEMY_GRUNT_RANGED_SUP] = 4;
	damage[ENEMY_SOLDIER_MELEE_ATT] = 15;
	damage[ENEMY_SOLDIER_MELEE_DEF] = 5;
	damage[ENEMY_SOLDIER_MELEE_KAMI] = 42;
	damage[ENEMY_SOLDIER_RANGED_ATT] = 10;
	damage[ENEMY_SOLDIER_RANGED_SUP] = 2;
	damage[ENEMY_ELITE_MELEE_ATT] = 20;
	damage[ENEMY_ELITE_MELEE_SWARMER] = 10;
	damage[ENEMY_ELITE_MELEE_SWARM] = 10;
	damage[ENEMY_ELITE_RANGED_SHORT] = 15;
	damage[ENEMY_ELITE_RANGED_LONG] = 20;
	damage[ENEMY_ELITE_RANGED_SUP] = 1;
	damage[ENEMY_BOSS_FIRST] = 10;
	damage[ENEMY_BOSS_SECOND] = 20;
	damage[ENEMY_BOSS_FINAL] = 30;
}

void	get_enemy_range(double *ranges)
{
	ranges[ENEMY_GRUNT_MELEE] = 0.3;
	ranges[ENEMY_GRUNT_RANGED_BASIC] = 6;
	ranges[ENEMY_GRUNT_RANGED_ADV] = 5.5;
	ranges[ENEMY_GRUNT_RANGED_SUP] = 5;
	ranges[ENEMY_SOLDIER_MELEE_ATT] = 0.5;
	ranges[ENEMY_SOLDIER_MELEE_DEF] = 0.4;
	ranges[ENEMY_SOLDIER_MELEE_KAMI] = 0.1;
	ranges[ENEMY_SOLDIER_RANGED_ATT] = 6.5;
	ranges[ENEMY_SOLDIER_RANGED_SUP] = 7;
	ranges[ENEMY_ELITE_MELEE_ATT] = 0.7;
	ranges[ENEMY_ELITE_MELEE_SWARMER] = 1;
	ranges[ENEMY_ELITE_MELEE_SWARM] = 0.5;
	ranges[ENEMY_ELITE_RANGED_SHORT] = 5;
	ranges[ENEMY_ELITE_RANGED_LONG] = 20;
	ranges[ENEMY_ELITE_RANGED_SUP] = 3.5;
	ranges[ENEMY_BOSS_FIRST] = 1;
	ranges[ENEMY_BOSS_SECOND] = 2;
	ranges[ENEMY_BOSS_FINAL] = 2.5;
}

void	get_enemy_speeds(int *speeds)
{
	speeds[ENEMY_GRUNT_MELEE] = 1000;
	speeds[ENEMY_GRUNT_RANGED_BASIC] = 1000;
	speeds[ENEMY_GRUNT_RANGED_ADV] = 250;
	speeds[ENEMY_GRUNT_RANGED_SUP] = 750;
	speeds[ENEMY_SOLDIER_MELEE_ATT] = 1000;
	speeds[ENEMY_SOLDIER_MELEE_DEF] = 1500;
	speeds[ENEMY_SOLDIER_MELEE_KAMI] = 3000;
	speeds[ENEMY_SOLDIER_RANGED_ATT] = 750;
	speeds[ENEMY_SOLDIER_RANGED_SUP] = 1250;
	speeds[ENEMY_ELITE_MELEE_ATT] = 1000;
	speeds[ENEMY_ELITE_MELEE_SWARMER] = 1250;
	speeds[ENEMY_ELITE_MELEE_SWARM] = 750;
	speeds[ENEMY_ELITE_RANGED_SHORT] = 1000;
	speeds[ENEMY_ELITE_RANGED_LONG] = 3000;
	speeds[ENEMY_ELITE_RANGED_SUP] = 150;
	speeds[ENEMY_BOSS_FIRST] = 2000;
	speeds[ENEMY_BOSS_SECOND] = 2000;
	speeds[ENEMY_BOSS_FINAL] = 2000;
}

void	get_enemy_mv_spd(double *mv_spd)
{
	mv_spd[ENEMY_GRUNT_MELEE] = 1.3;
	mv_spd[ENEMY_GRUNT_RANGED_BASIC] = 1.3;
	mv_spd[ENEMY_GRUNT_RANGED_ADV] = 1.3;
	mv_spd[ENEMY_GRUNT_RANGED_SUP] = 1.3;
	mv_spd[ENEMY_SOLDIER_MELEE_ATT] = 1.4;
	mv_spd[ENEMY_SOLDIER_MELEE_DEF] = 1.1;
	mv_spd[ENEMY_SOLDIER_MELEE_KAMI] = 2.5;
	mv_spd[ENEMY_SOLDIER_RANGED_ATT] = 1.4;
	mv_spd[ENEMY_SOLDIER_RANGED_SUP] = 1.4;
	mv_spd[ENEMY_ELITE_MELEE_ATT] = 1.5;
	mv_spd[ENEMY_ELITE_MELEE_SWARMER] = 1.2 ;
	mv_spd[ENEMY_ELITE_MELEE_SWARM] = 2;
	mv_spd[ENEMY_ELITE_RANGED_SHORT] = 1.5;
	mv_spd[ENEMY_ELITE_RANGED_LONG] = 1.5;
	mv_spd[ENEMY_ELITE_RANGED_SUP] = 1.5;
	mv_spd[ENEMY_BOSS_FIRST] = 1.1;
	mv_spd[ENEMY_BOSS_SECOND] = 1.1;
	mv_spd[ENEMY_BOSS_FINAL] = 1.1;
}