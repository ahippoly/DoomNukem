/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:07:08 by apons             #+#    #+#             */
/*   Updated: 2018/12/03 13:44:49 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while (j < size && dst[j])
		j++;
	if (j == size)
		return (size + i);
	if ((i + j) < size)
		ft_memcpy((dst + j), src, (i + 1));
	else
	{
		ft_memcpy((dst + j), src, ((size - j) - 1));
		dst[size - 1] = '\0';
	}
	return (i + j);
}
