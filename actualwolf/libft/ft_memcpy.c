/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:57:26 by apons             #+#    #+#             */
/*   Updated: 2018/11/21 09:43:15 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	dst2 = (char*)dst;
	src2 = (char*)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
