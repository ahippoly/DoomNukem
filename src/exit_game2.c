/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:13:19 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 11:13:55 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	free_obj_tab(t_obj **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i]->pixels)
			free(tab[i]->pixels);
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}
