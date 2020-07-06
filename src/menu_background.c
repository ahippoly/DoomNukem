/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:34:35 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 19:36:00 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
int				init_background(t_data *d)
{
	SDL_Surface	*surface;

	if (!(surface = SDL_LoadBMP(MENU_BG_PATH)))
		exit_game(d, "error : failed to load image");
	if (!(d->menu.menu_bg_t = SDL_CreateTextureFromSurface(d->rend, surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(surface);
	return (0);
}

int				put_menu_bg(t_data *d)
{
	if ((SDL_RenderCopy(d->rend, d->menu.menu_bg_t, NULL, NULL)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}