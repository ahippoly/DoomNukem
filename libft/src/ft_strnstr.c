/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:13:06 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 17:02:35 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	int		i;
	size_t	j;

	if (*needle == 0)
		return (haystack);
	while (*haystack != 0)
	{
		i = 0;
		j = 0;
		while (*(haystack++) != *needle && *haystack != 0 && len > 0)
			len--;
		haystack--;
		while (needle[j] == haystack[i++] && needle[j] != 0 && j < len)
			j++;
		if (*haystack == 0)
			return (0);
		else if (needle[j] == 0)
			return (haystack);
		haystack++;
	}
	return (0);
}
