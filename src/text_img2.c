/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_img2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:23:15 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 05:30:20 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

char		***alloc_chart(void)
{
	int		i;
	int		j;
	char	***chart;

	chart = (char***)p_malloc(sizeof(char **) * CHAR_NB);
	j = -1;
	while (++j < CHAR_NB)
	{
		chart[j] = (char**)p_malloc(sizeof(char *) * SIZE_Y);
		i = 0;
		while (i < SIZE_Y)
			chart[j][i++] = (char*)p_malloc(sizeof(char) * SIZE_X);
	}
	return (chart);
}

char		***read_char_table(int is_free)
{
	char		buf[5000];
	int			i;
	static int	nb;
	int			letter_size;
	static char	***charts;

	if (nb == 0)
	{
		charts = alloc_chart();
		if (read(open(CHART_FILE, O_RDONLY), buf, 5000) == -1)
			exit_with_msg("error while reading text_img chart\n");
		i = 0;
		letter_size = SIZE_X * (SIZE_Y + 1) + 1;
		while (nb < CHAR_NB)
		{
			parse_letter(charts[nb], &buf[i]);
			nb++;
			i += letter_size;
		}
	}
	if (is_free == 1)
		free(charts);
	return (charts);
}

void		parse_letter(char **charts, char *letter)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			if (letter[i++] == PIXEL)
				charts[y][x] = 1;
			else
				charts[y][x] = 0;
			x++;
		}
		i++;
		y++;
	}
}

t_txt_img	create_text_img(char *str, int size, int color, SDL_Point pos)
{
	char		***charts;
	t_txt_img	txt;
	int			len;

	charts = read_char_table(0);
	len = ft_strlen(str);
	txt.pos_size.x = 0;
	txt.pos_size.y = 0;
	txt.pos_size.w = (len * SIZE_X + len - 1) * size;
	txt.pos_size.h = SIZE_Y * size * 2;
	txt.color = color;
	if (!(txt.pixels = (unsigned int*)malloc(sizeof(unsigned int) *
					txt.pos_size.w * txt.pos_size.h)))
		exit_with_msg("Failed to malloc\n");
	ft_bzero(txt.pixels, txt.pos_size.w * txt.pos_size.h * sizeof(int));
	str = ft_strlower(ft_strdup(str));
	read_words(charts, str, size, txt);
	free(str);
	txt.pos_size.x = pos.x;
	txt.pos_size.y = pos.y;
	return (txt);
}
