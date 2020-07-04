/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/04 22:28:04 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "proto_global.h"

int		hex2dec(unsigned char *mem, int bytes)
{
	int i;
	int po;
	int hex;

	i = 0;
	po = 0;
	hex = 0;
	while (i < bytes)
	{
		hex += (mem[i] / 16 * ft_pow(16, po + 1))
			+ (mem[i] % 16 * ft_pow(16, po));
		i++;
		po += 2;
	}
	return (hex);
}

char	*read_pixels(int fd, char *str)
{
	size_t	str_length;
	size_t	totalread;
	size_t	ret;
	char	*new_str;
	char	buf[100001];

	str = ft_strdup("");
	totalread = 0;
	str_length = 0;
	while ((ret = read(fd, buf, 100000)))
	{
		buf[ret] = 0;
		totalread += ret;
		new_str = (char*)malloc(totalread);
		ft_memcpy(new_str, str, str_length);
		ft_memcpy(&new_str[str_length], buf, ret);
		free(str);
		str = new_str;
		str_length = totalread;
	}
	return (str);
}

char	*convert2bgra(char *str, int w, int h)
{
	int		end;
	int		i;
	int		j;
	char	*new_str;

	end = w * h * 3;
	if (!(new_str = (char*)malloc(w * h * 4)))
	{
		ft_putendl("Failed to malloc");
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i < end)
	{
		ft_memcpy(&new_str[j], &str[i], 3);
		new_str[j + 3] = (char)255;
		j += 4;
		i += 3;
	}
	free(str);
	return (new_str);
}

t_img		verif_bpp(char *head, int fd, int width, int height)
{
	int		bpp;
	char	*str;
	t_img	img;

	// printf("w,h = %i,%i\n", width, height);
	str = NULL;
	bpp = hex2dec(&((unsigned char*)head)[2], 2);
	str = read_pixels(fd, str);
	if (bpp == 24)
	{
		if (!(str = convert2bgra(str, width, height)))
			str = NULL; // CHECK SI ERREUR
	}
	img.pixels = (unsigned int*)str;
	img.pos_size.w = width;
	img.pos_size.h = height;
	img.w = width;
	img.h = height;
	// printf("bmp size2 w,h = %i,%i\n", img.w, img.h);
	return (img);
}

t_img		ft_load_bmp(char *file)
{
	int		fd;
	char	head[100];
	size_t	ret;
	int		pix_array_pos;
	t_img	img;
	t_img	res; //CHECK ERREUR

	ft_bzero(&res, sizeof(t_img));
	res.w = -42;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if (read(fd, head, 0) == -1)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if ((ret = read(fd, head, 26)) != 26)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	pix_array_pos = hex2dec(&((unsigned char*)head)[10], 4);
	img.pos_size.w = hex2dec(&((unsigned char*)head)[18], 4);
	img.pos_size.h = ft_abs(hex2dec(&((unsigned char*)head)[22], 4));
	if ((ret = read(fd, head, pix_array_pos - 26)) !=
			(size_t)pix_array_pos - 26)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if (!res.w)
		res = verif_bpp(head, fd, img.pos_size.w, img.pos_size.h);
	return (res);
}

void read_file_pixels(t_img text, int bpp, int fd, int convert)
{
	char buffer[BUFF_SIZE];
	int ret;
	int x;
	int y;
	char *pixel;

	x = 0;
	text.w *= 4;
	y = text.w * text.h - text.w;
	if (bpp == 32)
	{
		pixel = (char*)text.pixels;
		while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			while (ret > 0)
			{
				if (x >= text.w)
				{
					y -= text.w;
					x = 0;
				}
				ft_memcpy(&pixel[x + y], buffer + (BUFF_SIZE - ret), 4);
				if (convert == BMP_TYPE_BGRA)
				{
					swap_char(&pixel[x + y], &pixel[x + y + 3]);
					swap_char(&pixel[x + y + 1], &pixel[x + y + 2]);
				}
				else if (convert == BMP_TYPE_ABGR)
					swap_char(&pixel[x + y + 1], &pixel[x + y + 3]);
				x += 4;
				ret -= 4;
			}
		}
	}
	else if (bpp == 24)
	{
		pixel = (char*)text.pixels;
		while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			while (ret > 0)
			{
				if (x >= text.w)
				{
					y -= text.w;
					x = 0;
				}
				pixel[x + y] = 0xFF;
				ft_memcpy(&pixel[x + y + 1], buffer + (BUFF_SIZE - ret), 3);
				swap_char(&pixel[x + y + 1], &pixel[x + y + 3]);
				ret -= 3;
				x += 4;
			}
		}
		printf(" x = %i\n", x);
	}
	else
		exit_with_msg("Error while loading bmp file, wrong bpp\n");
}

t_img	ft_load_bmp2(char *file, int convert)
{
	int				fd;
	unsigned char	head[200];
	size_t			ret;
	int				pix_array_pos;
	t_img			img;
	int				bpp;
	t_img			res;

	ft_bzero(&res, sizeof(t_img));
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if (read(fd, head, 0) == -1)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if ((ret = read(fd, head, BMP_HEADER_READ)) != BMP_HEADER_READ)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	printf("bmp type = %c%c\n", hex2dec(&head[0], 1), hex2dec(&head[1], 1));
	printf("bmp total_size = %i\n", hex2dec(&head[2], 4));
	printf("bmp p_tab begin = %i\n", hex2dec(&head[10], 4));
	printf("bmp header size = %i\n", hex2dec(&head[14], 4));
	printf("bmp w = %i\n", hex2dec(&head[18], 4));
	printf("bmp h = %i\n", hex2dec(&head[22], 4));
	printf("bmp color planes = %i\n", hex2dec(&head[26], 2));
	printf("bmp bpp = %i\n", hex2dec(&head[28], 2));
	pix_array_pos = hex2dec(&((unsigned char*)head)[10], 4);
	img.pos_size.w = hex2dec(&((unsigned char*)head)[18], 4);
	img.pos_size.h = ft_abs(hex2dec(&((unsigned char*)head)[22], 4));
	printf("bmp unsigned char size : %i,%i\n", img.pos_size.w, img.pos_size.h);
	img.w = img.pos_size.w;
	img.h = img.pos_size.h;
	bpp = hex2dec(&head[28], 2);
	if (!(img.pixels = alloc_image(img.w, img.h)))
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if ((ret = read(fd, head, pix_array_pos - BMP_HEADER_READ)) != (size_t)pix_array_pos - BMP_HEADER_READ)
	{
		ft_putendl("wrong bmp file input");
		res.w = -42;
	}
	if (res.w == -42)
		return (res);
	read_file_pixels(img, bpp, fd, convert);
	return (img);
}