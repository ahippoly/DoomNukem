/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:59:51 by ahippoly          #+#    #+#             */
/*   Updated: 2018/12/05 23:13:59 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	if (!src)
	{
		if (!(str = (char*)malloc(sizeof(char) * (1))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (src[i] != 0)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*src != 0)
		str[i++] = *(src++);
	str[i] = 0;
	free(src);
	return (str);
}
