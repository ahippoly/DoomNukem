/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/06/24 20:07:17 by ahippoly         ###   ########.fr       */
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
		exit_with_msg("Failed to malloc");
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

t_img	verif_bpp(char *head, int fd, int width, int height)
{
	int		bpp;
	char	*str;
	t_img	img;

	str = NULL;
	bpp = hex2dec(&((unsigned char*)head)[2], 2);
	str = read_pixels(fd, str);
	if (bpp == 24)
		str = convert2bgra(str, width, height);
	img.pixels = (unsigned int*)str;
	img.pos_size.w = width;
	img.pos_size.h = height;
	return (img);
}

t_img	ft_load_bmp(char *file)
{
	int		fd;
	char	head[100];
	size_t	ret;
	int		pix_array_pos;
	t_img	img;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit_with_msg("wrong bmp file input");
	if (read(fd, head, 0) == -1)
		exit_with_msg("wrong bmp file input");
	if ((ret = read(fd, head, 26)) != 26)
		exit_with_msg("wrong bmp file header");
	pix_array_pos = hex2dec(&((unsigned char*)head)[10], 4);
	img.pos_size.w = hex2dec(&((unsigned char*)head)[18], 4);
	img.pos_size.h = ft_abs(hex2dec(&((unsigned char*)head)[22], 4));
	if ((ret = read(fd, head, pix_array_pos - 26)) !=
			(size_t)pix_array_pos - 26)
		exit_with_msg("Failed to malloc");
	return (verif_bpp(head, fd, img.pos_size.w, img.pos_size.h));
}
