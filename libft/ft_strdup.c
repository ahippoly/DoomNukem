/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:59:51 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/19 16:55:06 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != 0)
		i++;
	if (!(str = (char*)malloc(sizeof(*src) * (i + 1))))
		return (NULL);
	i = 0;
	while (*src != 0)
		str[i++] = *(src++);
	str[i] = 0;
	return (str);
}
