/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 05:25:25 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/24 20:09:34 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bresenham.h"
#include "proto_global.h"

void	oct_ini(t_oct *oct, SDL_Point pos1, SDL_Point pos2, int pos[2][2])
{
	pos[0][0] = pos1.x;
	pos[0][1] = pos2.x;
	pos[1][0] = pos1.y;
	pos[1][1] = pos2.y;
	oct->inc[0] = pos2.x - pos1.x > 0 ? 1 : -1;
	oct->inc[1] = pos2.y - pos1.y > 0 ? 1 : -1;
	oct->d[0] = (pos2.x - pos1.x) * 2 * oct->inc[0];
	oct->d[1] = (pos2.y - pos1.y) * 2 * oct->inc[1];
	oct->bool = oct->d[0] > oct->d[1] ? 1 : 0;
	oct->boolxy = 1 - oct->bool;
	oct->e = oct->d[oct->boolxy] / 2;
	oct->ecart = (pos[oct->boolxy][1] - pos[oct->boolxy][0])
		* oct->inc[oct->boolxy];
}

void	process_line(t_img img, int pos[2][2], t_oct *oct, int color)
{
	if (pos[0][0] < img.pos_size.w && pos[0][0] > 0 && pos[1][0] > 0
		&& pos[1][0] < img.pos_size.h)
		img.pixels[pos[0][0] + pos[1][0] * img.pos_size.w] = color;
	oct->e -= oct->d[oct->bool];
	while (oct->e <= 0)
	{
		pos[oct->bool][0] += oct->inc[oct->bool];
		oct->e += oct->d[oct->boolxy];
	}
	pos[oct->boolxy][0] += oct->inc[oct->boolxy];
}

void	draw_line(SDL_Point pos1, SDL_Point pos2, t_img img, int color)
{
	t_oct			oct;
	int				pos[2][2];
	int				i;
	int				length;

	if (pos1.x != -42 && pos2.x != -42)
	{
		i = 0;
		oct_ini(&oct, pos1, pos2, pos);
		if (oct.bool == 0)
			length = ft_min(img.pos_size.w * 100,
				ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		else
			length = ft_min(img.pos_size.h * 100,
				ft_abs(pos[oct.boolxy][0] - pos[oct.boolxy][1]));
		while (i < length)
		{
			process_line(img, pos, &oct, color);
			i++;
		}
	}
}
