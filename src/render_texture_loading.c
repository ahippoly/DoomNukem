/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture_loading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:21:50 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 19:45:02 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

t_img	read_img_surface(char *file, Uint32 pixel_format)
{
	SDL_Surface		*readed_file;
	SDL_Surface		*converted;
	SDL_PixelFormat	*format;
	t_img			img;

	readed_file = SDL_LoadBMP(file);
	if (readed_file == NULL)
		exit_with_msg("failed to load texture bmp file\n");
	format = SDL_AllocFormat(pixel_format);
	converted = SDL_ConvertSurface(readed_file, format, 0);
	SDL_FreeFormat(format);
	SDL_FreeSurface(readed_file);
	img.pixels = alloc_image(converted->w, converted->h);
	ft_memcpy_int(img.pixels, converted->pixels, converted->w * converted->h);
	img.w = converted->w;
	img.h = converted->h;
	SDL_FreeSurface(converted);
	return (img);
}

void	load_bmp_files(t_data *d)
{
	char	*path;
	int		i;

	path = ft_strnew(36);
	i = 0;
	while (i < NB_TEXTURE)
	{
		ft_strcpy(path, "asset/img/textures/TEXT_PATH_");
		ft_strcat(path, ft_itoa(i));
		ft_strcat(path, ".bmp");
		d->texture[i] = ft_load_bmp2(path, BMP_TYPE_BGRA, 0);
		ft_bzero(path, sizeof(char *));
		i++;
	}
	free(path);
}

void	init_rend_img(t_data *d)
{
	d->img[IMG_PLAYER] = ft_load_bmp2(IMG_PATH_0, BMP_TYPE_BGRA, 0);
	d->img[IMG_AFRIT] = ft_load_bmp2(IMG_PATH_1, BMP_TYPE_BGRA, 0);
	d->img[IMG_ORC] = ft_load_bmp2(IMG_PATH_2, BMP_TYPE_BGRA, 0);
	d->img[IMG_KEY] = ft_load_bmp2(IMG_PATH_3, BMP_TYPE_BGRA, 0);
	d->img[IMG_HEAL_PACK] = ft_load_bmp2(IMG_PATH_4, BMP_TYPE_BGRA, 0);
	d->img[IMG_SHIP] = ft_load_bmp2(IMG_PATH_5, BMP_TYPE_BGRA, 0);
	d->img[IMG_JETPACK] = ft_load_bmp2(IMG_PATH_6, BMP_TYPE_BGRA, 0);
}
