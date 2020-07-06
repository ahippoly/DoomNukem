/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 22:54:57 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

void	init_img_var(t_img *img, unsigned char *head)
{
	img->pos_size.w = hex2dec(&head[18], 4);
	img->pos_size.h = ft_abs(hex2dec(&head[22], 4));
	img->w = img->pos_size.w;
	img->h = img->pos_size.h;
	img->pixels = NULL;
}

t_img	ft_load_bmp2(char *file, int convert, int bpp)
{
	int				fd;
	unsigned char	head[200];
	size_t			ret;
	int				pix_array_pos;
	t_img			img;

	ft_bzero(&img, sizeof(t_img));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (bmp_error(&img, fd, "cant open file"));
	if (read(fd, head, 0) == -1)
		return (bmp_error(&img, fd, "cant read file, not acces or folder"));
	if ((ret = read(fd, head, BMP_HEADER_READ)) != BMP_HEADER_READ)
		return (bmp_error(&img, fd, "BMP Header too short"));
	init_img_var(&img, head);
	pix_array_pos = hex2dec(&head[10], 4);
	bpp = hex2dec(&head[28], 2);
	if (!(img.pixels = alloc_image(img.w, img.h)))
		return (bmp_error(&img, fd, "Failed to malloc bmp"));
	if ((ret = read(fd, head, pix_array_pos - BMP_HEADER_READ))
		!= (size_t)pix_array_pos - BMP_HEADER_READ)
		return (bmp_error(&img, fd, "BMP file too short"));
	read_file_pixels(img, bpp, fd, convert);
	close(fd);
	return (img);
}
