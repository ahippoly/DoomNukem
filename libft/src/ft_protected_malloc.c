/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protected_malloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:40:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 17:45:05 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*p_malloc(unsigned int size)
{
	void	*data;

	if (!(data = malloc(size)))
	{
		ft_putstr("Failed to malloc");
		return (NULL);
	}
	return (data);
}
