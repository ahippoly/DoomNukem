/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joindel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:51:31 by apons             #+#    #+#             */
/*   Updated: 2019/03/20 14:30:11 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joindel(char *s1, const char *s2)
{
	size_t		len;
	char		*dst;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s1) || !(s2) || !(dst = ft_strnew(len)))
		return (NULL);
	dst = ft_strcat(dst, s1);
	dst = ft_strcat(dst, s2);
	dst[len] = '\0';
	free(s1);
	return (dst);
}
