/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_event_poll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 05:06:15 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/09 17:36:39 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	event_gun_mouse(t_data *d, SDL_Event *event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		if (event->button.button == SDL_BUTTON_LEFT)
			shoot_attempt(d, d->actual_weapon);
		else if (event->button.button == SDL_BUTTON_RIGHT)
			aim_gun(d);
	}
	else if (event->type == SDL_MOUSEBUTTONUP)
	{
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			d->shoot_repeat = 0;
			d->sprite[d->gun_ind].anim_end = -1;
			if (d->gun_ind > 2 && d->gun_ind < 6)
				play_sound(d, d->gun_ind + 10);
		}
		else if (event->button.button == SDL_BUTTON_RIGHT)
			d->sprite[d->gun_ind].on = -1;
	}
}

void	inc_fov(t_data *d, float inc)
{
	d->fov_rad += inc * M_PI_2;
	d->fov += inc;
}

void	handle_poll_keydown(t_data *d, SDL_Event *event)
{
	if (event->key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		d->speed_modifier += 1;
	if (event->key.keysym.scancode == SDL_SCANCODE_LCTRL)
	{
		d->speed_modifier -= 0.5;
		d->z_offset -= PLAYER_HEIGHT / 2;
	}
	if (event->key.keysym.scancode == SDL_SCANCODE_N)
		create_mini_map(d, &d->map);
	if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
		d->z_force = JUMP_FORCE;
	if (event->key.keysym.scancode == SDL_SCANCODE_J && d->fov < 1)
		inc_fov(d, 0.05);
	if (event->key.keysym.scancode == SDL_SCANCODE_K && d->fov > 0.20)
		inc_fov(d, -0.05);
}

void	handle_poll_keyup(t_data *d, SDL_Event *event)
{
	if (event->key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		d->speed_modifier -= 1;
	if (event->key.keysym.scancode == SDL_SCANCODE_LCTRL)
	{
		d->speed_modifier += 0.5;
		d->z_offset += PLAYER_HEIGHT / 2;
	}
}

void	handle_poll_event(t_data *d)
{
	SDL_Event	event;

	while (SDL_PollEvent(&d->e))
	{
		event = d->e;
		if (event.type == SDL_WINDOWEVENT
			&& event.window.event == SDL_WINDOWEVENT_CLOSE)
			d->run_game = -1;
		if (event.type == SDL_MOUSEMOTION)
		{
			d->rot += MOUSE_SENS * event.motion.xrel * M_PI_2;
			d->screen_height = HALF_WIN_SIZE_Y + (HALF_WIN_SIZE_Y
			- event.motion.y) * Y_VIEW_RANGE;
		}
		if (event.type == SDL_KEYDOWN)
			handle_poll_keydown(d, &event);
		if (event.type == SDL_KEYUP)
			handle_poll_keyup(d, &event);
		event_gun_mouse(d, &event);
	}
}
