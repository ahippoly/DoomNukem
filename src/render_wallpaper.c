/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wallpaper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:31 by alebui            #+#    #+#             */
/*   Updated: 2020/07/08 17:01:20 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK

int				init_backgroundd(t_data *d, SDL_Texture **texture, char *path)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP(path)))
		exit_game(d, "error : failed to load bmp for gameover background");
	if (!((*texture) = SDL_CreateTextureFromSurface(d->rend, surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(surface);
	return (0);
}

int				put_bg(t_data *d, SDL_Texture *texture)
{
	if ((SDL_RenderCopy(d->rend, texture, NULL, NULL)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}
