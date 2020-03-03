/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:58:14 by ahippoly          #+#    #+#             */
/*   Updated: 2020/03/03 21:06:47 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*double_array_size(void *data, int unit_size, size_t array_length)
{
	void	*new_data;
	size_t	array_size;

	array_size = unit_size * array_length;
	if (!(new_data = malloc(array_size * 2)))
		return (NULL);
	ft_memcpy(new_data, data, array_size);
	free(data);
	return (new_data);
}
