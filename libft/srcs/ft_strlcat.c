/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 20:06:46 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/16 16:00:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t srclen;
	size_t destlen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	while (src[i] && (destlen + i + 1) < size)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (size < destlen)
		return (size + srclen);
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
