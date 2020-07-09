/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:30:49 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 16:15:01 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int					init_health_pack(t_data *d, t_hud *hud)
{
	if (!(hud->inv.healthpack_icon_s = SDL_LoadBMP(HEALTHPACK_PATH)))
		exit_game(d, "error : failed to load image");
	if (!(hud->inv.healthpack_icon_t = SDL_CreateTextureFromSurface(d->rend,
		hud->inv.healthpack_icon_s)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(hud->inv.healthpack_icon_s);
	return (0);
}

int					put_healthpack_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if ((SDL_RenderCopy(d->rend, hud->inv.healthpack_icon_t, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}

int					set_healthpack_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Surface		*s_cpy;
	char			*text;

	if (!(text = ft_itoa(nb)))
		exit_game(d, "error : failed to transform int to ascii");
	if (!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
		exit_game(d, "error : failed to render text blended");
	if (!(hud->inv.healthpack_info_s = copy_surface(d, s_cpy, hud)))
		exit_game(d, "error : failed to copy_surface");
	SDL_FreeSurface(s_cpy);
	free(text);
	return (0);
}

int					render_healthpack_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->inv.healthpack_info_t = SDL_CreateTextureFromSurface(d->rend,
		hud->inv.healthpack_info_s)))
		exit_game(d, "error : failed to create texture");
	if ((SDL_RenderCopy(d->rend, hud->inv.healthpack_info_t, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}
