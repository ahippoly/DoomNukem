/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:54:28 by apons             #+#    #+#             */
/*   Updated: 2018/12/03 13:26:57 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	finish;
	size_t			len;

	if (s)
	{
		finish = ft_strlen(s) - 1;
		if (finish + 1 == 0)
			return (ft_strsub(s, 0, 0));
		start = 0;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		if (s[start] == '\0')
			return (ft_strsub(s, 0, 0));
		while (s[finish] == ' ' || s[finish] == '\n' || s[finish] == '\t')
			finish--;
		len = finish - start + 1;
		return (ft_strsub(s, start, len));
	}
	return (NULL);
}
