/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_ammo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:48:38 by alebui            #+#    #+#             */
/*   Updated: 2020/07/06 17:23:06 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//OK
#include "proto_global.h"

int					init_ammo_icon(t_data *d, t_hud *hud)
{
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(AMMO_ICON_PATH)))
		exit_game(d, "eror : failed to load hud icon image");
	if (!(hud->ammo_texture = SDL_CreateTextureFromSurface(d->rend, surface)))
		exit_game(d, "error : failed ton convert surface");
	SDL_FreeSurface(surface);
	return (0);
}

int					put_ammo_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if ((SDL_RenderCopy(d->rend, hud->ammo_texture, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}

int					set_ammo_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Surface		*s_cpy;	
	char			*text;
	
	if (nb <= 0)
		nb = 0;
	if (!(text = ft_itoa(nb)))
		exit_game(d, "error : failed to transform int to ascii");
	if(!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
		exit_game(d, "error : failed to render text blender");
	if (!(hud->message_ammo_s = copy_surface(d, s_cpy, hud)))
		exit_game(d, "error : failed to copy_surface");
	SDL_FreeSurface(s_cpy);
	free(text);
	return (0);
}

int					render_ammo_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->message_ammo_t = SDL_CreateTextureFromSurface(d->rend, hud->message_ammo_s)))
		exit_game(d, "error : failed to create texture");
	if ((SDL_RenderCopy(d->rend, hud->message_ammo_t, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}
