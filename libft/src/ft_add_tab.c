/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:57:00 by ahippoly          #+#    #+#             */
/*   Updated: 2019/02/07 17:49:21 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_add_tab(int *tab, int new, int size)
{
	int *new_tab;
	int i;

	if (!(new_tab = (int*)malloc(sizeof(*tab) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = new;
}
