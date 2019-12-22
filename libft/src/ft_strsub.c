/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:57:59 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/24 17:50:02 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!(s))
		return (NULL);
	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
