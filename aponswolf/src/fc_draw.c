/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:53:29 by apons             #+#    #+#             */
/*   Updated: 2020/02/04 21:02:20 by saneveu          ###   ########.fr       */
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
		env->floorwall.x = env->ray.mapos.x;
		env->floorwall.y = env->ray.mapos.y + env->ray.wallwhere;
		if (env->ray.dir.x < 0)
			env->floorwall.x += 1.0;
	}
	else
	{
		env->floorwall.x = env->ray.mapos.x + env->ray.wallwhere;
		env->floorwall.y = env->ray.mapos.y;
		if (env->ray.dir.y < 0)
			env->floorwall.y += 1.0;
	}
}

static void		ft_add_pxl(t_enval *env, int j, int i, int t)
{
	if (t == 4 || (t == 5 && env->wtex[5].img->w != env->wtex[4].img->w))
		env->wt.x = (int)(env->currentfloor.x * env->wtex[t].img->w)
			% env->wtex[t].img->w;
	if (t == 4 || (t == 5 && env->wtex[5].img->h != env->wtex[4].img->h))
		env->wt.y = (int)(env->currentfloor.y * env->wtex[t].img->h)
			% env->wtex[t].img->h;
	/*env->mlx.pxl[WIN_W * j + i] =
		env->wtex[t]->buffer[env->wtex[t]->width * env->wt.y + env->wt.x];*/
	put_pixel(env->sdl.screen, i, j, get_pixel(env, t, i, j));
}

static void		floor_loop(t_enval *env, int i)
{
	int j;

	j = env->ray.wallbot - 1;
	while (++j < WIN_H)
	{
		env->distcurrent = WIN_H / (2.0 * j - WIN_H);
		env->weight = env->distcurrent / env->distwall;
		env->currentfloor.x = env->weight * env->floorwall.x
			+ (1.0 - env->weight) * env->player.pos.x;
		env->currentfloor.y = env->weight * env->floorwall.y
			+ (1.0 - env->weight) * env->player.pos.y;
		ft_add_pxl(env, j, i, TEXT_FLOOR);
		ft_add_pxl(env, WIN_H - j, i, TEXT_CEILING);
	}
}

static void		floor_calc(t_enval *env, int i)
{
	/*
	int bpp;
	int s_line;
	int endian;

	if (!env->wtex[4]->buffer)
		env->wtex[4]->buffer = (int *)mlx_get_data_addr(env->wtex[4]->img,
			&bpp, &s_line, &endian);
	if (!env->wtex[5]->buffer)
		env->wtex[5]->buffer = (int *)mlx_get_data_addr(env->wtex[5]->img,
			&bpp, &s_line, &endian);*/
	env->distwall = env->ray.perpwalldist;
	if (env->ray.wallbot < 0)
		env->ray.wallbot = WIN_H;
	floor_loop(env, i);
}

void			fc_draw(t_enval *env, int i)
{
	floor_cast(env);
	floor_calc(env, i);
}
