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

static	t_buff	reset_buff(void)
{
	t_buff buff;
	int i;

	i = 0;
	while (i < 4)
	{
		buff.value[i] = 0;
		buff.time[i] = 0;
		i++;
	}
	return (buff);
}

/*
** Note : Increasing movement_speed variable actually
** decreases movement speed, unless it is equal to 0.
** In that case, the entity cannot move.
*/

void			init_pc(t_player_character *pc)
{
	pc->health.max = 100;
	pc->health.current = 100;
	pc->armor.max = 100;
	pc->armor.current = 0;
	pc->movement_speed = 9;
	pc->effects.dmg_resist = reset_buff();
	pc->effects.att_dmg = reset_buff();
	pc->effects.att_spd = reset_buff();
	pc->arsenal[0] = get_fist();
}

void			init_game(t_game *game)
{

}