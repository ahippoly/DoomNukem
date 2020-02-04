/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_damage.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:13:51 by apons             #+#    #+#             */
/*   Updated: 2020/02/03 13:13:51 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gameplay.h"

int		get_damage_dealt(t_npc npc, t_player_character player)
{
	int damage;
	double dmg_mod;

	if (npc.player_allegiance == NPC_HOSTILE)
	{
		dmg_mod = get_modifier(player.effects.att_dmg);
		return (player.arsenal[player.current_w].attack.damage * dmg_mod);		
	}
	return (0);
}