/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:08:16 by apons             #+#    #+#             */
/*   Updated: 2018/12/03 14:50:28 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	char		*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (csrc < cdst)
	{
		while (len--)
			*(cdst + len) = *(csrc + len);
	}
	else
		cdst = ft_memcpy(dst, src, len);
	return (dst);
}
