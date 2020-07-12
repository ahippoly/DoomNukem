/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_health.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:29:51 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 16:19:06 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int					init_health_icon(t_data *d, t_hud *hud)
{
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(HEALTH_ICON_PATH)))
		exit_game(d, "error : failed to load image");
	if (!(hud->health_texture = SDL_CreateTextureFromSurface(d->rend, surface)))
		exit_game(d, "error : failed to create texture");
	SDL_FreeSurface(surface);
	return (0);
}

int					put_health_icon(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if ((SDL_RenderCopy(d->rend, hud->health_texture, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}

int					set_health_info(t_data *d, t_hud *hud, int nb)
{
	SDL_Surface		*s_cpy;
	char			*text;

	if (nb <= 0)
		nb = 0;
	else if (nb > 100)
		nb = 100;
	if (!(text = ft_itoa(nb)))
		exit_game(d, "error : failed to transform int to ascii");
	if (!(s_cpy = TTF_RenderText_Blended(d->font_nb, text, hud->color)))
		exit_game(d, "error : failed to render text blended");
	if (!(hud->message_health_s = copy_surface(d, s_cpy, hud)))
		exit_game(d, "error : failed to copy surface");
	SDL_FreeSurface(s_cpy);
	free(text);
	return (0);
}

int					render_health_info(t_data *d, t_hud *hud, SDL_Rect pos)
{
	if (!(hud->message_health_t = SDL_CreateTextureFromSurface(d->rend,
		hud->message_health_s)))
		exit_game(d, "error : failed to create texture");
	if ((SDL_RenderCopy(d->rend, hud->message_health_t, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}
