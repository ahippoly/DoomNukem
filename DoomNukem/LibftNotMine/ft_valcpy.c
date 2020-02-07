/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:25:35 by apons             #+#    #+#             */
/*   Updated: 2019/03/28 14:52:40 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_valcpy(int **valdst, int **values, int width, int height)
{
	int x;
	int y;

	if (!(valdst = (int **)malloc(sizeof(int *) * height)))
		return (0);
	y = 0;
	while (y < height)
	{
		if (!(valdst[y] = (int *)malloc(sizeof(int) * width)))
			return (0);
		x = 0;
		while (x < height)
		{
			valdst[y][x] = values[y][x];
			x++;
		}
		y++;
	}
	return (valdst);
}
