/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:34:42 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/24 17:51:28 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*add_word(char const *s, int i)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = 0;
	while (--i >= 0)
		str[i] = s[i];
	return (str);
}

static int		count_elem(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**tab;

	count = count_elem(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (count + 1))) || !s)
		return (NULL);
	j = 0;
	while (*s && count-- > 0)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if (i == 0)
			return (tab);
		tab[j++] = add_word(s, i);
		while (*s != c && *s)
			s++;
	}
	tab[j] = 0;
	return (tab);
}
