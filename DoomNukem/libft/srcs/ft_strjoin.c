/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 02:28:05 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 21:53:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;

	if (!(s1 && s2) || !(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	dest = ft_strcpy(dest, (char *)s1);
	dest = ft_strcat(dest, (char *)s2);
	return (dest);
}
