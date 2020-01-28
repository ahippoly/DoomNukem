/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:53:29 by apons             #+#    #+#             */
/*   Updated: 2019/11/07 09:53:29 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_enval  *floor_cast(t_enval *env)
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
    return (env);
}

static t_enval  *floor_calc(t_enval *env, int i)
{
    int j;
    int bpp;
    int s_line;
    int endian; 

    if (!env->wtex[4]->buffer)
        env->wtex[4]->buffer = (int *)mlx_get_data_addr(env->wtex[4]->img,
            &bpp, &s_line, &endian);
    if (!env->wtex[5]->buffer)
        env->wtex[5]->buffer = (int *)mlx_get_data_addr(env->wtex[5]->img,
            &bpp, &s_line, &endian);
    env->distwall = env->ray.perpwalldist;
    if (env->ray.wallbot < 0)
        env->ray.wallbot = WIN_H;
    j = env->ray.wallbot;
    while (j < WIN_H)
    {
        env->distcurrent = WIN_H / (2.0 * j - WIN_H);
        env->weight = env->distcurrent / env->distwall;
        env->currentfloor.x = env->weight * env->floorwall.x + (1.0 - env->weight) * env->player.pos.x;
        env->currentfloor.y = env->weight * env->floorwall.y + (1.0 - env->weight) * env->player.pos.y;
        env->wt.x = (int)(env->currentfloor.x * env->wtex[4]->width) % env->wtex[4]->width;
        env->wt.y = (int)(env->currentfloor.y * env->wtex[4]->height) % env->wtex[4]->height;
        env->mlx.pxl[WIN_W * j + i] =
            env->wtex[4]->buffer[env->wtex[4]->width * env->wt.y + env->wt.x];
        env->mlx.pxl[WIN_W * (WIN_H - j) + i] =
            env->wtex[5]->buffer[env->wtex[5]->width * env->wt.y + env->wt.x];
        j++;
    }
    return (env);
}

void            fc_draw(t_enval *env, int i)
{
    env = floor_cast(env);
    env = floor_calc(env, i);
}