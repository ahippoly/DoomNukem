/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:53:04 by apons             #+#    #+#             */
/*   Updated: 2019/03/28 14:42:17 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_move_words(char **grid, char const *s, char c)
{
	size_t i;
	size_t w;
	size_t word_i;

	i = 0;
	word_i = 0;
	while (s[i])
	{
		w = 0;
		while (s[i + w] != c && s[i + w] != '\0')
			w++;
		if (w == 0)
			i++;
		else
		{
			if (!(grid[word_i] = ft_strsub(s, i, w)))
				return (NULL);
			i += w;
			word_i++;
		}
	}
	grid[word_i] = 0;
	return (grid);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		word;
	char	**grid;

	if (s)
	{
		word = 0;
		i = 0;
		while (s[i])
		{
			i++;
			if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
				word++;
		}
		if (!(grid = (char **)malloc(sizeof(char*) * (word + 1))))
			return (NULL);
		return (ft_move_words(grid, s, c));
	}
	return (NULL);
}
