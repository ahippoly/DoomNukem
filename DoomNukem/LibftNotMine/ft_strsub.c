/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:03:25 by apons             #+#    #+#             */
/*   Updated: 2019/03/25 15:02:10 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trunk;
	size_t	i;

	if (s)
	{
		if (!(trunk = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			trunk[i] = s[start + i];
			i++;
		}
		trunk[i] = '\0';
		return (trunk);
	}
	return (NULL);
}
