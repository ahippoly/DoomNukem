/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:44:00 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/22 16:04:11 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	d;
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	d = (unsigned char)c;
	dst2 = dst;
	src2 = (unsigned char*)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == d)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
