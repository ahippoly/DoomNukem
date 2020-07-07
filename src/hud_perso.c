/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_perso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:31:08 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 19:31:12 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
static int		update_perso(t_data *d, t_hud *hud)
{
	ft_bzero(&hud->perso, sizeof(hud->perso));
	if (hud->current_perso_id == PERSO_F)
	{
		if (!(hud->perso.surface = SDL_LoadBMP(PERSO_PATH_0)))
			exit_game(d, "error : failed to load image");
	}
	else if (hud->current_perso_id == PERSO_M)
	{
		if (!(hud->perso.surface = SDL_LoadBMP(PERSO_PATH_1)))
			exit_game(d, "error : failed to load image");
	}
	else
		exit_game(d, "error : failed to update perso");
	return (0);
}

int				init_perso(t_data *d, t_hud *hud)
{
	update_perso(d, hud);
	if (!(hud->perso.texture = SDL_CreateTextureFromSurface(d->rend, hud->perso.surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->perso.surface);
	hud->perso.hp_max = 100;
	hud->perso.hp = 100;
	return (0);
}

/* Affiche le perso à l'écran */
int				put_perso_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if ((SDL_RenderCopy(d->rend, hud->perso.texture, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}