/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:16:30 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/14 02:46:54 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

int	render_game(t_data *d)
{
	SDL_SetRelativeMouseMode(SDL_TRUE);
	d->time_last_frame = d->time;
	d->time = SDL_GetTicks();
	d->diff_time = (float)(d->time - d->time_last_frame) / 1000;
	SDL_PumpEvents();
	handle_poll_event(d);
	handle_key_event(d);
	gravity(d);
	create_obj_raybox(d);
	process_mobs_gameplay(d);
	process_gun(d->actual_weapon, d->time, d);
	check_props_collect(d, d->props, &d->hud);
	raycast_thread_init(d);
	print_skybox(d, d->skybox, d->rot_calc.rot, d->p_screen);
	sprite_anim_gun(d);
	update_player_pos_mini_map(d);
	print_player_look_vector(d, d->rot);
	calc_n_disp_framerate(d);
	print_data2screen(d);
	return (0);
}
