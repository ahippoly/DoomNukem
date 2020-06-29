/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_props.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:51:48 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/29 00:51:55 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void ref_origin(void *type_list, int nb_type, int type)
{
	t_obj *obj;
	int i;
	int size;
	void *selected;

	i = 0;
	if (type == TYPE_PROP)
	{
		size = sizeof(t_props);
		while (i < nb_type)
		{
			selected = type_list + i++ * size;
			((t_props*)selected)->obj_ref->origin = selected;
		}
	}
	if (type == TYPE_MOB)
	{
		size = sizeof(t_mob);
		while (i < nb_type)
		{
			selected = type_list + i++ * size;
			((t_mob*)selected)->obj_ref->origin = selected;
		}
	}
}

void check_props_collect(t_data *d, t_props *props, t_hud *hud)
{
	int i;
	int nb_props;
	t_props *prop;

	nb_props = d->nb_props;
	i = 0;
	while (i < nb_props)
	{
		prop = &d->props[i];
		if (prop->collectable && get_dist(prop->pos, d->player_pos) < prop->size)
		{
			if (prop->id == KEY_ITEM_ID)
				hud->inv.key += 1;
			if (prop->id == HEAL_PACK_ITEM_ID)
				hud->inv.health_pack += 1;
			//del_from_array(d->obj_list, &d->nb_obj, prop->obj_ref, sizeof(t_obj));
			del_obj(d->obj_list, &d->nb_obj, prop->obj_ref);
			del_from_array(d->props, &d->nb_props, prop, sizeof(t_props));
			ref_origin(props, d->nb_props, TYPE_PROP);
		}
		i++;
	}
}