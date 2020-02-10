/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 00:49:03 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 22:22:04 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	else if (ft_strncmp(&(s1[i]), &(s2[i]), n) == 0)
		return (1);
	else
		return (0);
	return (1);
}
