/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_inv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:30:59 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 19:31:00 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
int					init_key_icon(t_data *d, t_hud *hud)
{
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(KEY_PATH)))
		exit_game(d, "error : failed to load image");
	if (!(hud->inv.key_icon_t = SDL_CreateTextureFromSurface(d->rend, surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(surface);
	return (0);
}

int					put_key_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if ((SDL_RenderCopy(d->rend, hud->inv.key_icon_t, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}

int					set_key_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Surface		*s_cpy;	
	char			*text;

	text = ft_itoa(nb);
	if(!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
		exit_game(d, "error : failed to render text blended");
	if (!(hud->inv.key_info_s = copy_surface(d, s_cpy, hud)))
		exit_game(d, "error : failed to copy_surface");
	SDL_FreeSurface(s_cpy);
	free(text);
	return (0);
}

int					render_key_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->inv.key_info_t = SDL_CreateTextureFromSurface(d->rend, hud->inv.key_info_s)))
		exit_game(d, "error : failed to create texture");
	if ((SDL_RenderCopy(d->rend, hud->inv.key_info_t, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}