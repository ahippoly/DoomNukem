/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:52:15 by saneveu           #+#    #+#             */
/*   Updated: 2018/11/14 21:46:59 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int i, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
		((unsigned char *)s)[a++] = (unsigned char)i;
	return (s);
}
