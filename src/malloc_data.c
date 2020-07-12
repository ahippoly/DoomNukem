/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:51:28 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:44:45 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

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

t_sprite		**malloc_sprite_tab(int size)
{
	t_sprite	**sprite;

	if (!(sprite = (t_sprite **)ft_memalloc(sizeof(t_sprite *) * (size + 1))))
		return (NULL);
	return (sprite);
}
