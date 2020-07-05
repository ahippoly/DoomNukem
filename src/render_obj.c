/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:14:14 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 23:28:13 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static void	create_raybox(t_obj *obj, t_rot rot_calc)
{
	if (obj->room_id < -1)
	{
		obj->rotation = calc_sin_cos_rot(rot_calc.rot - M_PI_2);
		obj->p1.x = obj->pos.x - obj->size * rot_calc.sin_rot;
		obj->p1.y = obj->pos.y + obj->size * rot_calc.cos_rot;
		obj->p2.x = obj->pos.x + obj->size * rot_calc.sin_rot;
		obj->p2.y = obj->pos.y - obj->size * rot_calc.cos_rot;
	}
}

void	create_obj_raybox(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_obj)
	{
		create_raybox(&d->obj_list[i++], d->rot_calc);
	}
}

// void	correct_origin_ref(int i, int nb_obj, t_obj *obj)
// {
// 	int	size;
// 	int	type;

// 	if (obj->room_id == TYPE_PROP)
// 	{
// 		type = TYPE_PROP;
// 		size = sizeof(t_props);
// 	}
// 	if (obj->room_id == TYPE_MOB)
// 	{
// 		type = TYPE_MOB;
// 		size = sizeof(t_mob);
// 	}
// 	while (i < nb_obj)
// 	{
// 		if (obj->room_id == type)
// 			obj->origin -= size;
// 		i++;
// 	}
// }

void	del_obj(t_obj *obj_list, int *nb_obj, t_obj *obj)
{
	int		i;

	i = 0;
	while (i < *nb_obj)
		if (&obj_list[i++] == obj)
			break ;
	i--;
	(*nb_obj)--;
	while (i < *nb_obj)
	{
		obj = &obj_list[i + 1];
		if (obj->room_id == TYPE_PROP)
			((t_props*)obj->origin)->obj_ref -= 1;
		if (obj->room_id == TYPE_MOB)
			((t_mob*)obj->origin)->obj_ref -= 1;
		obj_list[i] = obj_list[i + 1];
		i++;
	}
}
