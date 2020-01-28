/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:43:41 by apons             #+#    #+#             */
/*   Updated: 2019/10/31 16:04:35 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

static void		up_down(t_enval *env)
{	
	int		judge;
	double	x_cpy;
	double	y_cpy;

	judge = env->keyinf.up + env->keyinf.down;
	x_cpy = env->player.pos.x + (double)env->player.dir.x / 9 * judge;
	y_cpy = env->player.pos.y + (double)env->player.dir.y / 9 * judge;
	if (env->map.walls[(int)(x_cpy + 0.025)][(int)env->player.pos.y] == 0
		&& env->map.walls[(int)(x_cpy - 0.025)][(int)(env->player.pos.y)] == 0)
		env->player.pos.x = x_cpy;
	if (env->map.walls[(int)env->player.pos.x][(int)(y_cpy + 0.025)] == 0
		&& env->map.walls[(int)(env->player.pos.x)][(int)(y_cpy - 0.025)] == 0)
		env->player.pos.y = y_cpy;
}

static void		left_right(t_player *p, t_keys keyinf)
{
	int		judge;
	double	angle;
	double	dir_x_cpy;
	double	pla_x_cpy;

	judge = keyinf.left + keyinf.right;
	dir_x_cpy = p->dir.x;
	pla_x_cpy = p->plane.x;
	angle = 5 * M_PI/180 * judge;
	p->dir.x = (p->dir.x * cos(angle) - p->dir.y * sin(angle));
	p->dir.y = (dir_x_cpy * sin(angle) + p->dir.y * cos(angle));
	p->plane.x = (p->plane.x * cos(angle) - p->plane.y * sin(angle));
	p->plane.y = (pla_x_cpy * sin(angle) + p->plane.y * cos(angle));
}

static int		red_cross(int i)
{
	exit(i);
	return (0);
}

int				ft_loop_hook(t_enval *env)
{
	up_down(env);
	left_right(&env->player, env->keyinf);
	ft_bzero(env->mlx.pxl, WIN_W * WIN_H * sizeof(int));
	ray_draw(env);
	ft_putendl("Test");
	return (0);
}

void			mlx_handle_hooks(t_enval *env)
{
	//  mlx_hook(env->mlx.w_p, KEYPRESS, KEYPRESSMASK, ft_loop_hook_dummy, env);
	
	mlx_hook(env->mlx.w_p, KEYPRESS, KEYPRESSMASK, keypress, env);
	mlx_hook(env->mlx.w_p, DESTROYNOTIFY, KEYRELEASEMASK, red_cross, 0);
	mlx_hook(env->mlx.w_p, KEYRELEASE, KEYRELEASEMASK, keyrelease, env),
	mlx_loop_hook(env->mlx.m_p, ft_loop_hook, env);
	mlx_loop(env->mlx.m_p);
}