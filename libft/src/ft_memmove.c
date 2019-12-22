/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:46:46 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 16:52:28 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (src > dst)
	{
		while (i < n)
			((char*)dst)[i++] = *((char*)src++);
		return (dst);
	}
	else if (n == 0)
		return (dst);
	while (n-- > 0)
		((char*)dst)[n] = ((char*)src)[n];
	return (dst);
}
