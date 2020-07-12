/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:44:23 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 15:44:48 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

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
