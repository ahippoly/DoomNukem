/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:39:43 by apons             #+#    #+#             */
/*   Updated: 2018/11/21 09:42:42 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*bud;

	i = 0;
	bud = (char*)b;
	while (i < len)
	{
		bud[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
