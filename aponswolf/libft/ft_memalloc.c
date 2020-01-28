/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:54:02 by apons             #+#    #+#             */
/*   Updated: 2018/12/01 10:47:18 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*black;

	if (!(black = malloc(sizeof(void *) * size)))
		return (NULL);
	ft_bzero(black, size);
	return (black);
}
