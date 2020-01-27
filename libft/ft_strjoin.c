/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:45:50 by apons             #+#    #+#             */
/*   Updated: 2018/11/29 15:03:20 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sentence;
	int		almight;
	int		i;

	if (s1 && s2)
	{
		almight = ft_strlen(s1) + ft_strlen(s2);
		if (!(sentence = ft_strnew(almight)))
			return (NULL);
		i = 0;
		while (s1[i])
		{
			sentence[i] = s1[i];
			i++;
		}
		almight = 0;
		while (s2[almight])
		{
			sentence[i + almight] = s2[almight];
			almight++;
		}
		sentence[i + almight] = '\0';
		return (sentence);
	}
	return (NULL);
}
