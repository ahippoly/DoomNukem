/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:46:23 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 15:15:42 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void				free_sprites(t_data *d)
{
	int				i;

	i = 0;
	while (i < MAX_WEAPONS)
	{
		SDL_DestroyTexture(d->sprite[i].text);
		d->sprite[i].text = NULL;
		i++;
	}
}

SDL_Texture			*load_sprite_bmp(char *str, t_data *d)
{
	SDL_Texture		*texture;
	t_img			img;

	texture = NULL;
	img = ft_load_bmp2(str, BMP_TYPE_ARGB, 0);
	texture = SDL_CreateTexture(d->rend, SDL_PIXELFORMAT_ABGR32,
		SDL_TEXTUREACCESS_STREAMING, img.w, img.h);
	SDL_UpdateTexture(texture, NULL, img.pixels, img.w * 4);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	free(img.pixels);
	return (texture);
}
