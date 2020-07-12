/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_map_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahippoly <ahippoly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:03:17 by ahippoly          #+#    #+#             */
/*   Updated: 2020/07/07 23:04:28 by ahippoly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto_global.h"

void	move_map_move_left(t_env *env)
{
	if (env->map_move.x <= -MOVE_SPEED)
		env->map_move.x += MOVE_SPEED;
}

void	move_map_move_right(t_env *env)
{
	env->map_move.x -= MOVE_SPEED;
}

void	move_map_move_up(t_env *env)
{
	if (env->map_move.y <= -MOVE_SPEED)
		env->map_move.y += MOVE_SPEED;
}

void	move_map_move_down(t_env *env)
{
	env->map_move.y -= MOVE_SPEED;
}
