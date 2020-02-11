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

/*
** Gives damage dealt by the attacker
*/

int		get_damage_dealt(t_attack attacker, t_buff att_mod)
{
	int		damage;
	double	dmg_mod;
	int		i;

	i = 0;
	dmg_mod = 1.0;
	while (i++ < 2)
		dmg_mod += att_mod.value[0];
	dmg_mod = ft_max(dmg_mod, 0);
	return (attacker.damage * dmg_mod);
}

/*
** Resolves damage actually taken by the defender.
** If armor is involved, damage to health is reduced
** by 80% of the lost armor's value.
** NPCs do not have armor, so make sure to bypass
** the function's parameter by setting it to 0.
*/

void	get_damage_taken(int *health, int *armor, t_buff def_mod, int damage)
{
	double	shield_mod;
	int		i;
	int		old_armor;
	int		armor_lost;

	shield_mod = 1.0;
	while (i++ < 2)
		shield_mod -= def_mod.value[i];
	shield_mod = ft_max(shield_mod, 0);
	if (armor != 0)
	{
		old_armor = *armor;
		*armor = ft_max(armor - damage, 0);
		armor_lost = old_armor - *armor;
		damage -= armor_lost * 0.8;
	}
	*health = ft_max(*health - damage, 0);
}