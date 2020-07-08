/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:47:16 by alebui            #+#    #+#             */
/*   Updated: 2020/07/08 16:45:53 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

//OK
int	render_gameover(t_data *d)
{
	//RESET INFO CAR LA JE SUIS MORTE ET AU MEME ENDROIT DE MA MORT
	SDL_PumpEvents();
	handle_key_event(d);
	handle_poll_event(d);
	put_bg(d, d->menu.gameover_t);
	render_gameover_button(d);
	catch_over_btn_event(d);
	SDL_RenderPresent(d->rend);
	return (0);
}