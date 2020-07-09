/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_img3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:52:41 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 15:57:50 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void		fill_pixels(int x, int y, t_txt_img *txt, t_size size)
{
	int i;
	int j;
	int y_pos;

	j = -1;
	while (++j < size.h)
	{
		i = 0;
		y_pos = (y + j) * txt->pos_size.w;
		while (i < size.w)
			txt->pixels[(x + i++) + y_pos] = txt->color;
	}
}

void		charts2pixels(char **letter, int size,
		t_txt_img txt)
{
	int x;
	int y;
	int size2;

	y = 0;
	size2 = size * 2;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			if (letter[y][x] == 1)
				fill_pixels(x * size + txt.pos_size.x, y * size2
					+ txt.pos_size.y, &txt, (t_size){size, size2});
			x++;
		}
		y++;
	}
}

t_txt_img	set_pos_txt(t_txt_img txt, int x, int y)
{
	txt.pos_size.x = x;
	txt.pos_size.y = y;
	return (txt);
}
