/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:45:43 by apons             #+#    #+#             */
/*   Updated: 2018/12/03 14:45:27 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && *(s1a + i) == *(s2a + i))
		i++;
	return (*(s1a + i) - *(s2a + i));
}
