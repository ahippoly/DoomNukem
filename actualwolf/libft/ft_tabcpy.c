/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:58:07 by apons             #+#    #+#             */
/*   Updated: 2019/05/31 11:01:16 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **dst, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!(dst[i] = ft_strnew(ft_strlen(tab[i]))))
			return (NULL);
		dst[i] = ft_strcpy(dst[i], tab[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
