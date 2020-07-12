/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 10:02:17 by alebui            #+#    #+#             */
/*   Updated: 2019/03/04 12:50:08 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strsubfree(char **s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*strsubfree;

	if (!s || !*s || !(strsubfree = ft_strnew(len)))
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
	{
		strsubfree[j] = (*s)[i];
		i++;
		j++;
	}
	ft_strdel(s);
	return (strsubfree);
}
