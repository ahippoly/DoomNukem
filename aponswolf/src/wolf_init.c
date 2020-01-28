/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:58:59 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 16:04:41 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "wolf3d.h"

static int	**append_val(char **tab, t_enval *env)
{
	int reader;
	int len;
	int j;
	int i;

	i = 0;
	while ((reader = get_next_line(env->fd, &env->linebuff)) >= 1)
	{
		tab = ft_strsplit(env->linebuff, ' ');
		free(env->linebuff);
		len = ft_tablen(tab);
		(len != env->map.width ? ft_error("incorrect map format") : 0);
		if (!(env->map.walls[i] = (int *)malloc(sizeof(int) * len)))
			ft_error("malloc fail");
		j = 0;
		while (tab[j])
		{
			env->map.walls[i][j] = ft_atoi(tab[j]);
			j++;
		}
		ft_tabfree(tab);
		if (j < 3)
			ft_error("incorrect map format");
		i += 1;
	}
	ft_checkappval(reader, i, env->map, env->player);
	return (env->map.walls);
}

t_enval		*init_values(char *file, t_enval *env)
{
	char	**tab;

	env->fd = open(file, O_RDONLY);
	if (get_next_line(env->fd, &env->linebuff) == -1)
		ft_error("gnl reading failed.");
	tab = ft_strsplit(env->linebuff, ' ');
	free(env->linebuff);
	env->map.width = ft_atoi(tab[0]);
	env->map.height = ft_atoi(tab[1]);
	env->player.pos.x = ft_atoi(tab[3]) - 0.5;
	env->player.pos.y = ft_atoi(tab[2]) - 0.5;
	ft_tabfree(tab);
	if (!(env->map.walls = (int **)malloc(sizeof(int *) * env->map.height)))
		ft_error("map walls malloc failed.");
	// if (env->player.pos.x < 1.5 || env->player.pos.x > env->map.width - 0.5
	// 		|| env->player.pos.y < 1.5 || env->player.pos.y > env->map.height - 0.5)
	// 	ft_error("player is out of bounds, for sure.");
	env->map.walls = append_val(tab, env);
	env->player.dir.x = 1;
	env->player.dir.y = 0;
	env->player.plane.x = 0;
	env->player.plane.y = -FOV;
	env->ray.wallhit = 0;
	close(env->fd);
	return (env);
}

t_enval		*init_mlx(t_enval *env)
{
	int width;
	int height;
	int i;

	env->mlx.m_p = mlx_init();
	env->mlx.w_p = mlx_new_window(env->mlx.m_p, WIN_W, WIN_H, "Wolf3d");
	env->mlx.i_p = mlx_new_image(env->mlx.m_p, WIN_W, WIN_H);
	env->wtex[0] = mlx_xpm_file_to_image(env->mlx.m_p, WN, &width, &height);
	env->wtex[1] = mlx_xpm_file_to_image(env->mlx.m_p, WS, &width, &height);
	env->wtex[2] = mlx_xpm_file_to_image(env->mlx.m_p, WW, &width, &height);
	env->wtex[3] = mlx_xpm_file_to_image(env->mlx.m_p, WE, &width, &height);
	env->wtex[4] = mlx_xpm_file_to_image(env->mlx.m_p, FL, &width, &height);
	env->wtex[5] = mlx_xpm_file_to_image(env->mlx.m_p, CL, &width, &height);
	i = 0;
	while (i <= 5)
	{
		if (!(env->wtex[i]))
			ft_error("at least one texture is missing.");
		i++;
	}
	env->keyinf.up = 0;
	env->keyinf.down = 0;
	env->keyinf.left = 0;
	env->keyinf.right = 0;
	return (env);
}