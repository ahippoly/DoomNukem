/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:15:26 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 16:51:12 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*((unsigned char*)s1) == *((unsigned char*)s2) && --n > 0)
		s1++ && s2++;
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
