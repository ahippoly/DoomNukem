/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:12:09 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 21:55:02 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s1, char (*f)(char))
{
	int		i;
	char	*s2;

	if (!(s1 && f)
		|| !(s2 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = (*f)(s1[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
