/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:46:18 by apons             #+#    #+#             */
/*   Updated: 2018/12/06 13:51:51 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

char		*ft_strrev(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		ft_rev((str + i), (str + len - i - 1));
		i++;
	}
	return (str);
}
