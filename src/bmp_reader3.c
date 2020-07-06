/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:29:40 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 19:37:00 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	read_bpp32(t_img *text, int fd, int convert)
{
	char	buffer[BUFF_SIZE];
	char	*pixel;
	int		ret;
	int		x;
	int		y;

	pixel = (char*)text->pixels;
	x = 0;
	y = text->w * text->h - text->w;
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		while (ret > 0)
		{
			if (x >= text->w)
				go_next_line(&x, &y, text->w);
			ft_memcpy(&pixel[x + y], buffer + (BUFF_SIZE - ret), 4);
			convert_bmp_type32(&pixel[x + y], convert);
			x += 4;
			ret -= 4;
		}
	}
}

void	read_bpp24(t_img *text, int fd)
{
	char	buffer[BUFF_SIZE];
	char	*pixel;
	int		ret;
	int		x;
	int		y;

	pixel = (char*)text->pixels;
	x = 0;
	y = text->w * text->h - text->w;
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		while (ret > 0)
		{
			if (x >= text->w)
				go_next_line(&x, &y, text->w);
			pixel[x + y] = 0xFF;
			ft_memcpy(&pixel[x + y + 1], buffer + (BUFF_SIZE - ret), 3);
			swap_char(&pixel[x + y + 1], &pixel[x + y + 3]);
			ret -= 3;
			x += 4;
		}
	}
}

void	read_file_pixels(t_img text, int bpp, int fd, int convert)
{
	text.w *= 4;
	if (bpp == 32)
		read_bpp32(&text, fd, convert);
	else if (bpp == 24)
		read_bpp24(&text, fd);
	else
		exit_with_msg("Error while loading bmp file, wrong bpp\n");
}

t_img	bmp_error(t_img *res, int fd, char *msg)
{
	ft_putstr("wrong bmp file input");
	ft_putstr(msg);
	ft_putchar('\n');
	res->w = -42;
	close(fd);
	return (*res);
}

void	print_bmp_param(unsigned char *head)
{
	printf("bmp type = %c%c\n", hex2dec(&head[0], 1), hex2dec(&head[1], 1));
	printf("bmp total_size = %i\n", hex2dec(&head[2], 4));
	printf("bmp p_tab begin = %i\n", hex2dec(&head[10], 4));
	printf("bmp header size = %i\n", hex2dec(&head[14], 4));
	printf("bmp w = %i\n", hex2dec(&head[18], 4));
	printf("bmp h = %i\n", hex2dec(&head[22], 4));
	printf("bmp color planes = %i\n", hex2dec(&head[26], 2));
	printf("bmp bpp = %i\n", hex2dec(&head[28], 2));
}
