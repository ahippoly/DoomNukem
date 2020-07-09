/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_init_weapons2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:16:30 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 16:16:42 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int				init_weapon_5(t_hud *hud)
{
	hud->perso_weapon[5]->id = 5;
	hud->perso_weapon[5]->name = WEAPON_NAME_4;
	hud->perso_weapon[5]->ammo_left = 100;
	hud->perso_weapon[5]->capacity = 100;
	hud->perso_weapon[5]->attack_delay = 150;
	hud->perso_weapon[5]->reload_delay = 2700;
	hud->perso_weapon[5]->dammage = 12;
	hud->perso_weapon[5]->range = 10;
	hud->perso_weapon[5]->z_force = 0.003;
	hud->perso_weapon[5]->shoot_repeat = 1;
	return (0);
}
