/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:41:05 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/15 19:41:37 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_copy(const char *s1, const char *s2, int len_s1, int len_s2)
{
	int		x;
	int		y;
	char	*tmp;

	if (!(tmp = ft_strnew(len_s1 + len_s2)))
		return ((void *)0);
	x = -1;
	y = -1;
	while (++x < len_s1)
		tmp[x] = s1[x];
	while (++y < len_s2)
		tmp[x++] = s2[y];
	return (tmp);
}

char			*ft_strfjoin(const char *s1, const char *s2, int choose)
{
	int		len_s1;
	int		len_s2;
	char	*ret;

	if (!s1 || !s2)
		return ((void *)0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = ft_copy(s1, s2, len_s1, len_s2);
	choose == 1 ? ft_strdel((char **)&s1) : 0;
	choose == 2 ? ft_strdel((char **)&s2) : 0;
	if (choose == 3)
	{
		ft_strdel((char **)&s1);
		ft_strdel((char **)&s2);
	}
	return (ret);
}
