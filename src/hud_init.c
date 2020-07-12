/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:17:27 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 16:17:54 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int				init_hud_data(t_data *d)
{
	d->hud.current_weap_id = d->gun_ind;
	d->hud.current_perso_id = 1;
	if (d->hud.current_perso_id != PERSO_F ||
		d->hud.current_perso_id != PERSO_M)
		d->hud.current_perso_id = PERSO_F;
	init_weapons(d, &d->hud);
	d->hud.perso_weapon[d->hud.current_weap_id]->ammo_left =
		d->hud.perso_weapon[d->hud.current_weap_id]->capacity;
	init_perso(d, &d->hud);
	init_health_icon(d, &d->hud);
	init_ammo_icon(d, &d->hud);
	init_health_pack(d, &d->hud);
	init_key_icon(d, &d->hud);
	d->hud.hp = 100;
	d->hud.inv.health_pack = 0;
	d->hud.inv.key = 0;
	return (0);
}
