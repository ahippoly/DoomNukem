/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:42:16 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 15:39:28 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

SDL_Texture	*t_img2sdl_text(SDL_Renderer *rend, t_img src)
{
	SDL_Texture *new;

	new = SDL_CreateTexture(rend, SDL_PIXELFORMAT_ARGB32,
		SDL_TEXTUREACCESS_STREAMING, src.w, src.h);
	SDL_UpdateTexture(new, NULL, src.pixels, src.w * 4);
	return (new);
}

void		swap_char(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		remove_color(unsigned int *pixels, int total_size,
				unsigned int color)
{
	int i;

	i = 0;
	while (i < total_size)
	{
		if (pixels[i] == color)
			pixels[i] = 0;
		i++;
	}
}
