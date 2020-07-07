/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:21:11 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 05:31:36 by ahippoly         ###   ########.fr       */
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

void		read_words(char ***charts,
		char *str, int size, t_txt_img txt)
{
	int			i;
	t_txt_img	draw_letter;

	i = -1;
	while (str[++i] != '\0')
	{
		draw_letter = set_pos_txt(txt, txt.pos_size.x + (i * SIZE_X + i)
				* size, txt.pos_size.y);
		if (str[i] >= 'a' && str[i] <= 'z')
			charts2pixels(charts[str[i] - 'a'], size, draw_letter);
		else if (str[i] >= '0' && str[i] <= '9')
			charts2pixels(charts[str[i] - '0' + 26], size, draw_letter);
		else if (str[i] == ' ')
			charts2pixels(charts[36], size, draw_letter);
		else if (str[i] == '_')
			charts2pixels(charts[37], size, draw_letter);
		else if (str[i] == '>')
			charts2pixels(charts[38], size, draw_letter);
		else if (str[i] == '<')
			charts2pixels(charts[39], size, draw_letter);
		else if (str[i] == '-')
			charts2pixels(charts[40], size, draw_letter);
		else
			exit_with_msg("error : txt_img not alpha_numeric\n");
	}
}

void		input_text_to_img(char *str, int size, int color, t_img to_fill)
{
	char		***charts;
	t_txt_img	txt;

	txt.pixels = to_fill.pixels;
	txt.pos_size = to_fill.pos_size;
	txt.color = color;
	charts = read_char_table(0);
	str = ft_strlower(str);
	read_words(charts, str, size, txt);
	free(str);
}
