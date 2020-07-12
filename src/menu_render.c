/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:35:09 by robin             #+#    #+#             */
/*   Updated: 2020/07/09 17:00:38 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int	render_menu(t_data *d)
{
	SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_PumpEvents();
	handle_key_event(d);
	handle_poll_event(d);
	put_bg(d, d->menu.menu_bg_t);
	render_btn(d);
	catch_btn_event(d);
	SDL_RenderPresent(d->rend);
	return (0);
}
