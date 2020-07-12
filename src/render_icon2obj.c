/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_icon2obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:35:00 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/05 23:13:51 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_props	add_prop_jetpack(t_data *d, SDL_Point pos)
{
	t_props	prop;

	prop.pos.x = (float)pos.x / UNIT;
	prop.pos.y = (float)pos.y / UNIT;
	prop.size = JETPACK_SIZE;
	prop.collectable = JETPACK_COLLECTABLE;
	prop.can_collide = 0;
	prop.id = JETPACK_ITEM_ID;
	prop.text = &d->img[IMG_JETPACK];
	prop.z_pos = 10;
	return (prop);
}

void	identify_icon(t_data *d, t_icon *current)
{
	if (current->id_ref == AFRIT_ICON_ID)
		d->mobs[d->nb_mob++] = add_mob_demon(d, current->pos_i);
	if (current->id_ref == PYRO_ICON_ID)
		d->mobs[d->nb_mob++] = add_mob_pyro(d, current->pos_i);
	if (current->id_ref == KEY_ICON_ID)
		d->props[d->nb_props++] = add_prop_key(d, current->pos_i);
	if (current->id_ref == HEAL_PACK_ICON_ID)
		d->props[d->nb_props++] = add_prop_heal_pack(d, current->pos_i);
	if (current->id_ref == SHIP_ICON_ID)
		d->props[d->nb_props++] = add_prop_ship(d, current->pos_i);
	if (current->id_ref == JETPACK_ICON_ID)
		d->props[d->nb_props++] = add_prop_jetpack(d, current->pos_i);
}

void	load_icons(t_data *d, t_map_data *map)
{
	int		i;

	i = 0;
	d->nb_mob = 0;
	d->nb_props = 0;
	while (i < map->icon_count)
		identify_icon(d, &map->icon_list[i++]);
}
