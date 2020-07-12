/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:25 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 13:36:40 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int		render_gameover_button(t_data *d)
{
	int	btn_y;
	int	text_x;
	int	text_y;

	btn_y = WIN_SIZE_Y / 2;
	text_x = WIN_SIZE_X / 2 - 30;
	text_y = WIN_SIZE_Y / 2 + 10;
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, btn_y, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y, 0, 0),
		d->menu.over_continue_t, "TRY AGAIN");
	render_bg_btn(d, set_sdl_rect(WIN_SIZE_X / 2 - 100, btn_y + 100, 200, 50));
	render_text_btn(d, set_sdl_rect(text_x, text_y + 100, 0, 0),
		d->menu.over_quit_t, "QUIT");
	return (0);
}

int		catch_over_btn_event(t_data *d)
{
	if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100,
		WIN_SIZE_Y / 2, 200, 50)) == 1)
	{
		if (access("./doom-nukem", X_OK))
			exit_game(d, "error : something went wrong with read()");
		else
			d->run_game = GAME;
	}
	else if (is_mouse_on_target(d, set_sdl_rect(WIN_SIZE_X / 2 - 100,
		WIN_SIZE_Y / 2 + 100, 200, 50)) == 1)
		d->run_game = MENU;
	return (0);
}
