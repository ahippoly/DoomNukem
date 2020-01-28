/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freewolf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:51:35 by apons             #+#    #+#             */
/*   Updated: 2019/11/18 09:51:38 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** This function frees everything that is necessary to free.
*/

static void	freemap(t_mapinfo *map, int wl)
{
	int i;

	i = -1;
	while (++i < wl)
	{
		if (map->walls[i])
			free(map->walls[i]);
	}
	free(map->walls);
}

static void	freetextures(t_tex **wtex, t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < 6)
	{
		if (wtex[i] && wtex[i]->img)
		{
			mlx_destroy_image(mlx->m_p, wtex[i]->img);
			free(wtex[i]);
		}
	}
}

static void	freemlx(t_mlx *mlx, int i)
{
	mlx->i_p ? mlx_destroy_image(mlx->m_p, mlx->i_p) : 0;
	mlx->w_p ? mlx_destroy_window(mlx->m_p, mlx->w_p) : 0;
	i == 2 ? mlx_del(mlx->m_p) : 0;
}

void		ft_freewolf(t_enval *env, int i)
{
	if (env)
	{
		if (i == 1)
			free(env->linebuff);
		env->map.walls ? freemap(&env->map, env->wl) : 0;
		freetextures(env->wtex, &env->mlx);
		freemlx(&env->mlx, i);
		free(env);
		env = NULL;
	}
}
