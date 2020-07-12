/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:15:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/08 05:27:13 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	print_data2screen(t_data *d)
{
	SDL_Rect	tmp;
	SDL_Texture	*tmp_text;

	tmp_text = d->sprite[d->gun_ind].text;
	tmp = set_sdl_rect(MINI_MAP_POS_X, MINI_MAP_POS_Y,
		MINI_MAP_SIZE_X, MINI_MAP_SIZE_Y);
	if ((SDL_UpdateTexture(d->screen, NULL, d->p_screen, WINSIZEX * 4)) < 0)
		exit_game(d, "error : failed to update texture");
	print_mini_map(d);
	if ((SDL_RenderCopy(d->rend, d->screen, NULL, NULL)) < 0)
		exit_game(d, "error : failed to render copy");
	if ((SDL_RenderCopy(d->rend, tmp_text, &d->src_gun, &d->dst_gun)) < 0)
		exit_game(d, "error : failed to render copy");
	if ((SDL_RenderCopy(d->rend, d->mini_map, NULL, &tmp)) < 0)
		exit_game(d, "error : failed to render copy");
	render_hud(d);
	SDL_RenderPresent(d->rend);
}
