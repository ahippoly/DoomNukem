/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:03:00 by saneveu           #+#    #+#             */
/*   Updated: 2020/02/07 21:03:52 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			mouse(t_enval *env, Sint16 xrel, int dir)
{
	double	olddirx;
	double	oldplanex;
	double	angle;

	angle = xrel * M_PI / 180 * -dir;
	olddirx = env->player.dir.x;
	env->player.dir.x = (env->player.dir.x * cos(angle))
		- (env->player.dir.y * sin(angle));
	env->player.dir.y = (olddirx * sin(angle))
		+ (env->player.dir.y * cos(angle));
	oldplanex = env->player.plane.x;
	env->player.plane.x = (oldplanex * cos(angle))
		- (env->player.plane.y * sin(angle));
	env->player.plane.y = (oldplanex * sin(angle))
		+ (env->player.plane.y * cos(angle));
}

void			mouse_motion(t_enval *env)
{
	mouse(env, env->mouse.xrel, 1);
	if (abs(env->mouse.xrel) > WIN_W / 2
	|| env->mouse.x > env->sdl.winx + WIN_W
	|| env->mouse.x < env->sdl.winx
	|| env->mouse.y > env->sdl.winy + WIN_H
	|| env->mouse.y < env->sdl.winy)
		SDL_WarpMouseGlobal(env->sdl.winx + WIN_W / 2,
			env->sdl.winy + WIN_H / 2);
}

void			mouse_events(t_enval *env)
{
	if (env->sdl.key[MOUSE] == 1)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_GetGlobalMouseState(&(env->mouse.x), &(env->mouse.y));
		SDL_GetRelativeMouseState(&(env->mouse.xrel), &(env->mouse.yrel));
		mouse_motion(env);
		SDL_FlushEvent(SDL_MOUSEMOTION);
		env->sdl.key[MOUSE] = 0;
	}
}
