/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:01:30 by apons             #+#    #+#             */
/*   Updated: 2019/11/04 13:01:37 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** This function draws the walls the rays hit.
** The second 'if' statement allows reversing
** textures if seen from south or west.
*/

static double	get_where(t_enval *env)
{
	double wallwhere;

	if (env->ray.wallside == 0)
		wallwhere = env->player.pos.y + env->ray.perpwalldist * env->ray.dir.y;
	else
		wallwhere = env->player.pos.x + env->ray.perpwalldist * env->ray.dir.x;
	return (wallwhere - (int)wallwhere);
}

void			wall_draw(t_enval *env, int i, int t)
{
	int j;
	int d;
	int bpp;
	int s_line;
	int endian;

	if (!env->wtex[t]->buffer)
		env->wtex[t]->buffer = (int *)mlx_get_data_addr(env->wtex[t]->img,
			&bpp, &s_line, &endian);
	env->ray.wallwhere = get_where(env);
	env->wt.x = (int)(env->ray.wallwhere * (double)env->wtex[t]->width);
	if ((env->ray.wallside == 0 && env->ray.dir.x > 0)
			|| (env->ray.wallside == 1 && env->ray.dir.y < 0))
		env->wt.x = env->wtex[t]->width - env->wt.x - 1;
	j = env->ray.walltop;
	while (j < env->ray.wallbot)
	{
		d = j * 256 - WIN_H * 128 + env->ray.height * 128;
		env->wt.y = ((d * env->wtex[t]->height) / env->ray.height) / 256;
		env->mlx.pxl[WIN_W * j + i] =
			env->wtex[t]->buffer[env->wtex[t]->width * env->wt.y + env->wt.x];
		j++;
	}
}
