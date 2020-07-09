/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:16 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 11:25:26 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int	render_gameover(t_data *d)
{
	d->player_pos = create_t_point(0.500148 + d->map.player_spawn.x,
		0.500148 + d->map.player_spawn.y);
	d->hud.hp = 100;
	SDL_PumpEvents();
	handle_key_event(d);
	handle_poll_event(d);
	put_bg(d, d->menu.gameover_t);
	render_gameover_button(d);
	catch_over_btn_event(d);
	SDL_RenderPresent(d->rend);
	return (0);
}
