/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:53:29 by apons             #+#    #+#             */
/*   Updated: 2020/02/07 22:41:26 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Second part of raycasting functions.
** Calculations for floor and ceiling
** are done here.
*/

static void		floor_cast(t_enval *env)
{
	if (env->ray.wallside == 0)
	{
		env->ray.floorwall.x = env->ray.mapos.x;
		env->ray.floorwall.y = env->ray.mapos.y + env->ray.wallwhere;
		if (env->ray.dir.x < 0)
			env->ray.floorwall.x += 1.0;
	}
	else
	{
		env->ray.floorwall.x = env->ray.mapos.x + env->ray.wallwhere;
		env->ray.floorwall.y = env->ray.mapos.y;
		if (env->ray.dir.y < 0)
			env->ray.floorwall.y += 1.0;
	}
}

static void		ft_add_pxl(t_enval *env, int j, int i, int t)
{
	if (t == 4 || (t == 5 && env->wtex[5].img->w != env->wtex[4].img->w))
		env->wt.x = (int)(env->ray.currentfloor.x * env->wtex[t].img->w)
			% env->wtex[t].img->w;
	if (t == 4 || (t == 5 && env->wtex[5].img->h != env->wtex[4].img->h))
		env->wt.y = (int)(env->ray.currentfloor.y * env->wtex[t].img->h)
			% env->wtex[t].img->h;
	put_pixel(env->sdl.screen, i, j,
	get_pixel_floor(env, t, env->wt.x, env->wt.y));
}

static void		floor_loop(t_enval *env, int i)
{
	int j;

	j = env->ray.wallbot - 1;
	while (++j < WIN_H)
	{
		env->ray.distcurrent = WIN_H / (2.0 * j - WIN_H);
		env->ray.weight = env->ray.distcurrent / env->ray.distwall;
		env->ray.currentfloor.x = env->ray.weight * env->ray.floorwall.x
			+ (1.0 - env->ray.weight) * env->player.pos.x;
		env->ray.currentfloor.y = env->ray.weight * env->ray.floorwall.y
			+ (1.0 - env->ray.weight) * env->player.pos.y;
		ft_add_pxl(env, j, i, TEXT_FLOOR);
		ft_add_pxl(env, WIN_H - j, i, TEXT_CEILING);
	}
}

static void		floor_calc(t_enval *env, int i)
{
	env->ray.distwall = env->ray.perpwalldist;
	if (env->ray.wallbot < 0)
		env->ray.wallbot = WIN_H;
	floor_loop(env, i);
}

void			fc_draw(t_enval *env, int i)
{
	floor_cast(env);
	floor_calc(env, i);
}
