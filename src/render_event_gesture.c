/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_event_gesture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 04:28:41 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/03 22:32:37 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	event_equip_weapon(t_data *d, int weapon_id)
{
	d->gun_ind = weapon_id;
	d->sprite[weapon_id].on = -1;
	d->sprite[weapon_id].aim_on = 0;
	d->actual_weapon = d->hud.perso_weapon[weapon_id];
}

void	event_change_weapon(t_data *d, const Uint8 *clavier)
{
	if (clavier[SDL_SCANCODE_R])
		reload_weapon(d, d->actual_weapon);
	if (clavier[SDL_SCANCODE_1])
		event_equip_weapon(d, 0);
	if (clavier[SDL_SCANCODE_2])
		event_equip_weapon(d, 1);
	if (clavier[SDL_SCANCODE_3])
		event_equip_weapon(d, 2);
	if (clavier[SDL_SCANCODE_4])
		event_equip_weapon(d, 3);
	if (clavier[SDL_SCANCODE_5])
		event_equip_weapon(d, 4);
	if (clavier[SDL_SCANCODE_6])
		event_equip_weapon(d, 5);
}

void	handle_key_event2(t_data *d, const Uint8 *clavier)
{
	if (clavier[SDL_SCANCODE_I])
		d->z_offset += 0.05;
	if (clavier[SDL_SCANCODE_O])
		d->z_offset -= 0.05;
	if (clavier[SDL_SCANCODE_LALT] && d->jetpack > 0)
	{
		d->z_force += 0.001;
		d->air_time = 0;
	}
	event_change_weapon(d, clavier);
	if (clavier[SDL_SCANCODE_ESCAPE])
		d->run_game = -1;
}

void	handle_key_event(t_data *d)
{
	const Uint8	*clavier;

	clavier = SDL_GetKeyboardState(NULL);
	if (clavier[SDL_SCANCODE_E])
		d->rot += ROT_STEP;
	if (clavier[SDL_SCANCODE_Q])
		d->rot -= ROT_STEP;
	d->rot_calc = calc_sin_cos_rot(d->rot);
	if (clavier[SDL_SCANCODE_D])
		move_with_collide_player(d, &d->player_pos,
		calc_sin_cos_rot(d->rot + M_PI_2), MOVE_STEP * d->speed_modifier);
	if (clavier[SDL_SCANCODE_A])
		move_with_collide_player(d, &d->player_pos,
		calc_sin_cos_rot(d->rot - M_PI_2), MOVE_STEP * d->speed_modifier);
	if (clavier[SDL_SCANCODE_W])
		move_with_collide_player(d, &d->player_pos,
		d->rot_calc, MOVE_STEP * d->speed_modifier);
	if (clavier[SDL_SCANCODE_S])
		move_with_collide_player(d, &d->player_pos,
		calc_sin_cos_rot(d->rot + M_PI), MOVE_STEP * d->speed_modifier);
	handle_key_event2(d, clavier);
}
