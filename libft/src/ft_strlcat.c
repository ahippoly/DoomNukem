/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:19:58 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/22 16:06:55 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < n)
		len++;
	i = len;
	while (src[len - i] && len + 1 < n)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < n)
		dst[len] = 0;
	return (i + ft_strlen(src));
}
