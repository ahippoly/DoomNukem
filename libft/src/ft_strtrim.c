/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:32:20 by ahippoly          #+#    #+#             */
/*   Updated: 2018/11/24 17:50:45 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		j;

	if (!s)
		return (NULL);
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s)
		s++;
	i = 0;
	while (s[i])
		i++;
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ' || !s[i]) && i)
		i--;
	s[0] == 0 ? i : i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	i > 0 ? i-- : i;
	j = -1;
	while (++j <= i)
		str[j] = s[j];
	str[j] = 0;
	return (str);
}
