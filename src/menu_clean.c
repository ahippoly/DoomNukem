/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:28:06 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 14:28:06 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

static int	free_texture_menu(t_data *d)
{
	if (!d)
		return (0);
	if (d->menu_texture)
		SDL_DestroyTexture(d->menu_texture);
	if (d->menu.menu_bg_t)
		SDL_DestroyTexture(d->menu.menu_bg_t);
	if (d->menu.btn)
		SDL_DestroyTexture(d->menu.btn);
	if (d->menu.play_t)
		SDL_DestroyTexture(d->menu.play_t);
	if (d->menu.editor_t)
		SDL_DestroyTexture(d->menu.editor_t);
	if (d->menu.quit_t)
		SDL_DestroyTexture(d->menu.quit_t);
	return (0);
}

int			free_gameover(t_data *d)
{
	if (!d)
		return (0);
	free(d->p_gameover);
	if (d->menu.gameover_t)
		SDL_DestroyTexture(d->menu.gameover_t);
	if (d->menu.over_continue_t)
		SDL_DestroyTexture(d->menu.over_continue_t);
	if (d->menu.over_quit_t)
		SDL_DestroyTexture(d->menu.over_quit_t);
	return (0);
}

int			free_menu(t_data *d)
{
	free_texture_menu(d);
	return (0);
}
