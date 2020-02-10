/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 03:58:28 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 22:07:01 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int		ct(const char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			len++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	if (!s || !(dest = (char **)malloc(sizeof(char *) * (ct(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!(dest[j] = (char *)malloc(sizeof(char) * (len(&s[i], c) + 1))))
				return (0);
			while (s[i] && s[i] != c)
				dest[j][k++] = s[i++];
			dest[j++][k] = '\0';
		}
	}
	dest[j] = NULL;
	return (dest);
}
