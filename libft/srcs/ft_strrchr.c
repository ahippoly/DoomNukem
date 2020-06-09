/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:26 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/08 18:56:44 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*add;

	i = 0;
	add = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			add = (char *)&(s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (add);
}
