/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:43:41 by apons             #+#    #+#             */
/*   Updated: 2020/02/04 20:34:31 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Diverse functions to work with any mlx event that does not require the
** keyboard as well as to unite all mlx hooks under one bigger function.
*/

/*
static int		red_cross(t_enval *env)
{
	ft_freewolf(env, 0);
	exit(0);
	return (0);
}


int				ft_loop_hook(t_enval *env)
{
	movement(env);
	rotation(&env->player, env->keyinf);
	ft_bzero(env->mlx.pxl, WIN_W * WIN_H * sizeof(int));
	ray_draw(env);
	return (0);
}

void			mlx_handle_hooks(t_enval *env)
{
	mlx_hook(env->mlx.w_p, KEYPRESS, KEYPRESSMASK, keypress, env);
	mlx_hook(env->mlx.w_p, DESTROYNOTIFY, KEYRELEASEMASK, red_cross, env);
	mlx_hook(env->mlx.w_p, KEYRELEASE, KEYRELEASEMASK, keyrelease, env);
	mlx_loop_hook(env->mlx.m_p, ft_loop_hook, env);
	mlx_loop(env->mlx.m_p);
}*/
