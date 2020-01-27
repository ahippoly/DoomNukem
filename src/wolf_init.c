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

/*
** These functions initialize the program's values and parse the map.
*/

static int		**append_val(char **tab, t_enval *env)
{
	int reader;
	int len;
	int j;

	env->wl = 0;
	while ((reader = get_next_line(env->fd, &env->linebuff)) >= 1)
	{
		env->wl
			== env->map.height ? ft_error("map height incorrect.", env, 0) : 0;
		if (!(tab = ft_strsplit(env->linebuff, ' ')))
			ft_error("map parsing failed.", env, 1);
		free(env->linebuff);
		len = ft_tablen(tab);
		len != env->map.width ? ft_error("a line has bad width.", env, 0) : 0;
		if (!(env->map.walls[env->wl] = (int *)malloc(sizeof(int) * len)))
			ft_error("map wall section malloc failure.", env, 0);
		j = -1;
		while (tab[++j])
			env->map.walls[env->wl][j] = ft_atoi(tab[j]);
		ft_tabfree(tab);
		(j < 3) ? ft_error("incorrect map format.", env, 0) : 0;
		env->wl += 1;
	}
	ft_checkappval(reader, env->wl, env, env->map);
	return (env->map.walls);
}

static void		prep_init(t_enval *env)
{
	env->keyinf.up = 0;
	env->keyinf.down = 0;
	env->keyinf.left = 0;
	env->keyinf.right = 0;
	env->keyinf.sleft = 0;
	env->keyinf.sright = 0;
	env->keyinf.run = 1.0;
	env->map.walls = NULL;
	env->wtex[0] = NULL;
	env->wtex[1] = NULL;
	env->wtex[2] = NULL;
	env->wtex[3] = NULL;
	env->wtex[4] = NULL;
	env->wtex[5] = NULL;
	env->mlx.m_p = NULL;
	env->mlx.w_p = NULL;
	env->mlx.i_p = NULL;
}

void			init_values(char *file, t_enval *env)
{
	char	**tab;

	prep_init(env);
	env->fd = open(file, O_RDONLY);
	if (get_next_line(env->fd, &env->linebuff) == -1)
		ft_error("file reading failed.", env, 0);
	if (!(tab = ft_strsplit(env->linebuff, ' ')))
		ft_error("first line parsing failed.", env, 1);
	free(env->linebuff);
	ft_checkinval(tab, env);
	env->map.width = ft_atoi(tab[0]);
	env->map.height = ft_atoi(tab[1]);
	env->player.pos.x = ft_atoi(tab[3]) - 0.5;
	env->player.pos.y = ft_atoi(tab[2]) - 0.5;
	ft_tabfree(tab);
	if (!(env->map.walls = (int **)malloc(sizeof(int *) * env->map.height)))
		ft_error("map walls malloc failed.", env, 0);
	env->map.walls = append_val(tab, env);
	close(env->fd);
	env->player.dir.x = 1;
	env->player.dir.y = 0;
	env->player.plane.x = 0;
	env->player.plane.y = -FOV;
	env->ray.wallhit = 0;
}

void			init_mlx(t_enval *env)
{
	int width;
	int height;
	int i;

	ft_checkmlx(env);
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
			ft_error("at least one texture is missing or corrupted.", env, 0);
		i++;
	}
}
