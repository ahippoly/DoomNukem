/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:58:34 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/20 17:24:51 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (*((unsigned char*)s) != (unsigned char)c && --n > 0)
		s++;
	if (*((unsigned char*)s) == (unsigned char)c)
		return ((unsigned char*)s);
	return (0);
}
