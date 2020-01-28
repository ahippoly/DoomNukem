/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 08:50:09 by apons             #+#    #+#             */
/*   Updated: 2019/10/24 13:40:32 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**Reminder to check if every conditions are set for this function
*/

void	ft_checkappval(int reader, int i, t_mapinfo map, t_player plr)
{
	int p_x;
	int p_y;

	p_x = (int)plr.pos.x;
	p_y = (int)plr.pos.y;
	if (reader == -1)
		ft_error("file reading failed.");
	if (i != map.height || i < 3)
		ft_error("incorrect map format.");
	//if (p_x <= 1 || p_x >= map.width || p_y <= 1 || p_y >= map.height)
	//	ft_error("player is out of bounds.");
	if (map.walls[p_x][p_y] == 1)
		ft_error("player is in a wall.");
}

void	ft_error(char *err)
{
	ft_putstr("Error : ");
	ft_putendl(err);
	exit(1);
}