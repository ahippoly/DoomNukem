/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:15:29 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/06 21:17:07 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void 			print_data2screen(t_data *d)
{
    SDL_Rect 	tmp;
	SDL_Texture	*tmp_text;
	int			mini_x;
	int			mini_y;
	int			mini_h;
	int			mini_w;

	mini_x = MINI_MAP_POS_X;
	mini_y = MINI_MAP_POS_Y;
	mini_h = MINI_MAP_SIZE_X;
	mini_w = MINI_MAP_SIZE_Y;
	tmp_text = d->sprite[d->gun_ind].text;
	tmp = set_sdl_rect(mini_x, mini_y, mini_w, mini_h);
	if ((SDL_UpdateTexture(d->screen, NULL, d->p_screen, WIN_SIZE_X * 4)) < 0)
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
