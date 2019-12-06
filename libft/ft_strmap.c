/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:32:46 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/24 17:48:46 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!(s && f))
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = 0;
	while (--i >= 0)
		str[i] = f(s[i]);
	return (str);
}
