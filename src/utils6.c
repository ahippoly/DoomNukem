/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:05:22 by robin             #+#    #+#             */
/*   Updated: 2020/07/06 16:41:17 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		*ft_memcpy_int(unsigned int *dst, const unsigned int *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

float		get_dist(t_point pos1, t_point pos2)
{
	t_point diff;

	diff.x = pos2.x - pos1.x;
	diff.y = pos2.y - pos1.y;
	return (hypot(diff.x, diff.y));
}

t_rot		get_angle(t_point pos1, t_point pos2)
{
	t_point	diff;
	t_rot	rot;

	diff.x = (pos2.x - pos1.x);
	diff.y = (pos2.y - pos1.y);
	if (diff.x > 0)
	{
		rot.rot = atan(diff.y / diff.x);
		rot.cos_rot = cos(rot.rot);
	}
	else
	{
		rot.rot = -atan(diff.y / diff.x);
		rot.cos_rot = -cos(rot.rot);
	}
	rot.sin_rot = sin(rot.rot);
	return (rot);
}
