/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:36:05 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 14:31:44 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int				render_bg_btn(t_data *d, SDL_Rect pos)
{
	SDL_Rect	calc;

	calc = set_sdl_rect(0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	draw_rectangle(d->p_menu, pos, set_size(WIN_SIZE_X, WIN_SIZE_Y), 0xFFFFFF);
	if ((SDL_UpdateTexture(d->menu_texture, &calc, d->p_menu, WIN_SIZE_X * 4))
			< 0)
		exit_game(d, "error : failed to update texture");
	if ((SDL_RenderCopy(d->rend, d->menu_texture, &pos, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	return (0);
}

int				render_text_btn(t_data *d, SDL_Rect pos, SDL_Texture *texture,
					char *text)
{
	SDL_Color	col;
	SDL_Surface	*s_cpy;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	col.a = 0;
	if (!(s_cpy = TTF_RenderText_Blended(d->font_text, text, col)))
		exit_game(d, "error : failed to render text blended");
	if (!(texture = SDL_CreateTextureFromSurface(d->rend, s_cpy)))
		exit_game(d, "error : failed to create texture");
	TTF_SizeText(d->font_text, text, &pos.w, &pos.h);
	if ((SDL_RenderCopy(d->rend, texture, NULL, &pos)) < 0)
		exit_game(d, "error : failed to render copy");
	SDL_FreeSurface(s_cpy);
	return (0);
}

int				render_btn(t_data *d)
{
	int			btn_y;
	int			text_x;
	int			text_y;

	btn_y = WIN_SIZE_Y / 3;
	text_x = WIN_SIZE_X / 2 + 10;
	text_y = WIN_SIZE_Y / 3 + 13;
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2, btn_y, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y, 0, 0), d->menu.play_t,
		"PLAY");
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2, btn_y + 100, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y + 100, 0, 0),
		d->menu.editor_t, "EDIT MAP");
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2, btn_y + 200, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y + 200, 0, 0), d->menu.quit_t,
		"EXIT");
	return (0);
}
