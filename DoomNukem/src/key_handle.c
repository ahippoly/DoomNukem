/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:35:08 by apons             #+#    #+#             */
/*   Updated: 2020/02/04 20:19:46 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** These functions handle keyboard events.
** A few condition functions are also here to save file space.
*/

int		keypress(int key, t_enval *env)
{
	if (key == KEY_ESC)
	{
		ft_freewolf(env, 0);
		exit(0);
	}
	if (key == KEY_UP)
		env->keyinf.up = 1;
	if (key == KEY_DOWN)
		env->keyinf.down = -1;
	if (key == KEY_LEFT)
		env->keyinf.left = 1;
	if (key == KEY_RIGHT)
		env->keyinf.right = -1;
	if (key == KEY_Q)
		env->keyinf.sleft = -1;
	if (key == KEY_E)
		env->keyinf.sright = 1;
	if (key == KEY_LSHIFT)
		env->keyinf.run = 1.5;
	return (0);
}

int		keyrelease(int key, t_enval *env)
{
	if (key == KEY_UP)
		env->keyinf.up = 0;
	if (key == KEY_DOWN)
		env->keyinf.down = 0;
	if (key == KEY_LEFT)
		env->keyinf.left = 0;
	if (key == KEY_RIGHT)
		env->keyinf.right = 0;
	if (key == KEY_Q)
		env->keyinf.sleft = 0;
	if (key == KEY_E)
		env->keyinf.sright = 0;
	if (key == KEY_LSHIFT)
		env->keyinf.run = 1;
	return (0);
}
