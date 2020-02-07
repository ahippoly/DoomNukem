/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:23:14 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 21:59:27 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!find[i])
		return ((char *)src);
	while (i < n && src[i])
	{
		j = 0;
		while (i + j < n && src[i + j] && find[j] && src[i + j] == find[j])
			j++;
		if (!find[j])
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
