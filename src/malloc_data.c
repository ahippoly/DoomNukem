/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:51:28 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 00:19:09 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

/*
FMOD_SOUND		*malloc_fmod_sound(int size)
{
	int			i;
	FMOD_SOUND	*sound;

	if (!(sound = (FMOD_SOUND *)ft_memalloc(sizeof(FMOD_SOUND) * (size + 1))))
		return (NULL);
	return (sound);
}
*/

t_floor			**malloc_floor_tab(int size)
{
	t_floor		**floor;

	if (!(floor = (t_floor **)ft_memalloc(sizeof(t_floor *) * (size + 1))))
		return (NULL);
	return (floor);
}

t_floor			*malloc_floor(int size)
{
	t_floor		*floor;

	if (!(floor = (t_floor *)ft_memalloc(sizeof(t_floor) * (size + 1))))
		return (NULL);
	return (floor);
}

t_props			*malloc_props(int size)
{
	t_props		*prop;

	if (!(prop = (t_props *)ft_memalloc(sizeof(t_props) * (size + 1))))
		return (NULL);
	return (prop);
}

t_mob			*malloc_mob(int size)
{
	t_mob		*mob;

	if (!(mob = (t_mob *)ft_memalloc(sizeof(t_mob) * (size + 1))))
		return (NULL);
	return (mob);
}

t_obj			*malloc_obj(int size)
{
	t_obj		*obj;

	if (!(obj = (t_obj *)ft_memalloc(sizeof(t_obj) * (size + 1))))
		return (NULL);
	return (obj);
}

t_obj			**malloc_obj_tab(int size)
{
	t_obj		**obj;

	if (!(obj = (t_obj **)ft_memalloc(sizeof(t_obj*) * (size + 1))))
		return (NULL);
	return (obj);
}

t_sprite		*malloc_sprite(int size)
{
	t_sprite	*sprite;

	if (!(sprite = (t_sprite *)ft_memalloc(sizeof(t_sprite) * (size + 1))))
		return (NULL);
	return (sprite);
}
