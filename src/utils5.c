/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:36:29 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 17:25:54 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		*ft_memmove2(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	if (src == dst)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			cdst[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}

void		del_from_array(void *list, int *size, void *to_remove,
				int obj_size)
{
	int i;

	i = 0;
	while (i < *size)
	{
		if ((list + obj_size * i) == to_remove)
			break ;
		i++;
	}
	(*size)--;
	ft_memmove2(list + obj_size * i, list + obj_size * (i + 1), (*size - i) *
		obj_size);
}
