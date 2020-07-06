/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gesture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:32:40 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 19:33:24 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

unsigned int *alloc_image(int width, int height)
{
    unsigned int *image;

    if (!(image = (unsigned int *)malloc(sizeof(unsigned int) * width * height)))
	   return (NULL);
    ft_bzero(image, width * height * sizeof(unsigned int));
    return (image);
}

t_img create_img(unsigned int *pixels, SDL_Rect pos_size)
{
    t_img img;

    img.pixels = pixels;
    img.pos_size = pos_size;
    return (img);
}

SDL_Texture		*bmp_to_texture(char *file, SDL_Renderer *rend)
{
    SDL_Surface *readed_file;
    SDL_Texture *new;

	if ((access(file, R_OK)) < 0)
		return (NULL);
    if (!(readed_file = SDL_LoadBMP(file)))
		return (NULL);
	if (readed_file == NULL)
		return (NULL);
	if (!(new = SDL_CreateTextureFromSurface(rend, readed_file)))
		return (NULL);
    SDL_FreeSurface(readed_file);
    return (new);
}