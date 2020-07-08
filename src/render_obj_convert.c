/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:18:23 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/08 05:22:06 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_obj			convert_wall_to_obj(t_data *d, t_wall *wall)
{
	t_obj	obj;
	t_img	*text;

	ft_bzero(&obj, sizeof(t_obj));
	obj.p1 = wall->p1;
	obj.p2 = wall->p2;
	obj.length = wall->length;
	text = &d->texture[wall->texture_id];
	obj.pixels = text->pixels;
	obj.w = text->w;
	obj.h = text->h;
	obj.z_height = (t_p_size){wall->p1_z_start, wall->p1_z_size};
	obj.z_step = (t_p_size){wall->p2_z_start - wall->p1_z_start,
		wall->p2_z_size - wall->p1_z_size};
	obj.z_text_offset = 0;
	obj.alpha = wall->alpha;
	obj.can_collide = wall->can_collide;
	obj.room_id = wall->room_id_ref;
	obj.rotation = calc_sin_cos_rot(wall->rotation);
	obj.z_ground = -1;
	obj.origin = wall;
	return (obj);
}

static t_obj	convert_mob_to_obj(t_mob *mob)
{
	t_obj	obj;

	obj.pos = mob->pos;
	obj.size = mob->size;
	obj.z_height.pos = mob->z_pos;
	obj.z_height.size = mob->z_size;
	obj.z_step.pos = 0;
	obj.z_step.size = 0;
	obj.z_text_offset = get_float_part(obj.z_height.pos + obj.z_height.size);
	obj.length = 1;
	obj.alpha = 1;
	obj.room_id = TYPE_MOB;
	obj.pixels = mob->sprite.dst;
	obj.w = mob->sprite.dst_w;
	obj.h = mob->sprite.dst_h;
	obj.can_collide = 0;
	obj.z_ground = DEFAULT_Z_GROUND;
	obj.z_force = 0;
	obj.air_time = 0;
	obj.origin = mob;
	return (obj);
}

static t_obj	convert_prop_to_obj(t_props *props)
{
	t_obj	obj;

	obj.pos = props->pos;
	obj.size = props->size / 2;
	obj.z_height.pos = props->z_pos;
	obj.z_height.size = props->size;
	obj.z_step.pos = 0;
	obj.z_step.size = 0;
	obj.z_text_offset = get_float_part(obj.z_height.pos + obj.z_height.size);
	obj.length = 1;
	obj.alpha = 1;
	obj.room_id = TYPE_PROP;
	obj.pixels = props->text->pixels;
	obj.w = props->text->w;
	obj.h = props->text->h;
	obj.can_collide = props->can_collide;
	obj.z_ground = DEFAULT_Z_GROUND;
	obj.z_force = 0;
	obj.air_time = 0;
	obj.origin = props;
	return (obj);
}

void			init_obj_room_ground(t_data *d, t_obj *obj_list, int nb_obj)
{
	int		i;
	t_obj	*curr;

	i = 0;
	while (i < nb_obj)
	{
		curr = &obj_list[i];
		if (curr->room_id < -1)
			curr->z_ground = set_room_ground(d, curr->pos);
		i++;
	}
}

void			init_obj_list(t_data *d)
{
	int	i;
	int	j;

	d->nb_obj = d->map.wall_count + d->nb_props + d->nb_mob;
	i = 0;
	j = 0;
	while (i < d->map.wall_count)
		d->obj_list[j++] = convert_wall_to_obj(d, &d->map.wall_list[i++]);
	i = 0;
	while (i < d->nb_props)
	{
		d->obj_list[j] = convert_prop_to_obj(&d->props[i]);
		d->props[i++].obj_ref = &d->obj_list[j++];
	}
	i = 0;
	while (i < d->nb_mob)
	{
		d->obj_list[j] = convert_mob_to_obj(&d->mobs[i]);
		d->mobs[i++].obj_ref = &d->obj_list[j++];
	}
	init_obj_room_ground(d, d->obj_list, d->nb_obj);
}
