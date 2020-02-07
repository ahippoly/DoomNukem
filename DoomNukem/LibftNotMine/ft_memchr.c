/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:27:53 by apons             #+#    #+#             */
/*   Updated: 2018/12/03 14:49:23 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*test;
	void			*dummy;

	i = 0;
	test = (unsigned char *)s;
	dummy = (void *)s;
	while (i < n)
	{
		if (test[i] == (unsigned char)c)
			return (&dummy[i]);
		i++;
	}
	return (NULL);
}
