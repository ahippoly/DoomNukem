/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_id.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:04:10 by apons             #+#    #+#             */
/*   Updated: 2020/02/06 10:04:10 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_ID_H
# define ENEMY_ID_H

# define ENEMY_GRUNT_MELEE			0
# define ENEMY_GRUNT_RANGED_BASIC	1
# define ENEMY_GRUNT_RANGED_ADV		2
# define ENEMY_GRUNT_RANGED_SUP		3
# define ENEMY_SOLDIER_MELEE_ATT	4
# define ENEMY_SOLDIER_MELEE_DEF	5
# define ENEMY_SOLDIER_MELEE_KAMI	6
# define ENEMY_SOLDIER_RANGED_ATT	7
# define ENEMY_SOLDIER_RANGED_SUP	8
# define ENEMY_ELITE_MELEE_ATT		9
# define ENEMY_ELITE_MELEE_SWARMER	10
# define ENEMY_ELITE_MELEE_SWARM	11
# define ENEMY_ELITE_RANGED_SHORT	12
# define ENEMY_ELITE_RANGED_LONG	13
# define ENEMY_ELITE_RANGED_SUP		14
# define ENEMY_BOSS_FIRST			15
# define ENEMY_BOSS_SECOND			16
# define ENEMY_BOSS_FINAL			17

# define ENEMY_TYPE_COUNT			18

typedef struct	s_stat_sheet
{
	int		health[ENEMY_TYPE_COUNT];
	int		damage[ENEMY_TYPE_COUNT];
	double	ranges[ENEMY_TYPE_COUNT];
	int		delays[ENEMY_TYPE_COUNT];
	double  mv_spd[ENEMY_TYPE_COUNT];
}				t_stat_sheet;

#endif