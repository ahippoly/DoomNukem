/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 02:21:11 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 17:30:38 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static t_txt_img	process_draw(int i, t_txt_img txt, int size)
{
	t_txt_img		draw_letter;

	draw_letter = set_pos_txt(txt, txt.pos_size.x + (i * SIZE_X + i)
			* size, txt.pos_size.y);
	return (draw_letter);
}

int					read_words(char ***charts,
	char *str, int size, t_txt_img txt)
{
	int				i;
	t_txt_img		draw_letter;

	i = -1;
	while (str[++i] != '\0')
	{
		draw_letter = process_draw(i, txt, size);
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
			return (-1);
	}
	return (0);
}

int					input_text_to_img(char *str, int size, int color,
	t_img to_fill)
{
	char			***charts;
	t_txt_img		txt;

	txt.pixels = to_fill.pixels;
	txt.pos_size = to_fill.pos_size;
	txt.color = color;
	charts = read_char_table(0);
	str = ft_strlower(str);
	if ((read_words(charts, str, size, txt)) < 0)
		return (-1);
	return (0);
}
