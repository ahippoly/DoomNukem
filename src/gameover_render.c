/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:16 by alebui            #+#    #+#             */
/*   Updated: 2020/07/09 17:00:46 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int	render_gameover(t_data *d)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
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
